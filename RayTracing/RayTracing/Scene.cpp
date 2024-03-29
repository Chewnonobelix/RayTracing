#include "Scene.h"



Scene::Scene()
{
}


Scene::~Scene()
{
}

void Scene::addGeometry(GeometryPointer s)
{
	m_geometry << s;
}

void Scene::addLight(Light l)
{
	m_lights << l;
}

void Scene::addScreen(Screen s)
{
	m_screen = s;
}

QList<GeometryPointer> Scene::spheres() const
{
	return m_geometry;
}

QList<Light> Scene::lights() const
{
	return m_lights;
}

Screen Scene::screen() const
{
	return m_screen;
}

void Scene::sort(QList<GeometryPointer>& list, Point origin)
{
	for (int i = 0; i < list.size(); i++)
		for (int j = i + 1; j < list.size(); j++)
			if (list[j]->distanceTo(origin) < list[i]->distanceTo(origin))
				list.swapItemsAt(i, j);
}

void Scene::rayTracing()
{
	m_output = QImage(m_screen.width(), m_screen.height(), QImage::Format_RGB32);

	QList<GeometryPointer> ordered = spheres();
	Point origin = screen().position();
	m_output.fill(Qt::black);

	sort(ordered, origin);


	for (int i = 0; i < m_screen.width(); i++)
	{
		for (int j = 0; j < m_screen.height(); j++)
		{
			Line ray;
			ray.setVector(m_screen.orthogonal()[0], m_screen.orthogonal()[1], m_screen.orthogonal()[2]);
			Point p = m_screen.position();
			p.setX(p.x() + i * m_screen.u()[0] + j * m_screen.v()[0]);
			p.setY(p.y() + i * m_screen.u()[1] + j * m_screen.v()[1]);
			p.setZ(p.z() + m_screen.u()[2] + m_screen.v()[2]);
			ray.setOrigin(p);

			sort(ordered, p);
			GeometryPointer nearest = !m_geometry.isEmpty() ? m_geometry.first() : GeometryPointer();
			bool hit = false;

			Point nearestPoint;

			for (auto it = ordered.begin(); !hit && it != ordered.end(); it++)
			{
				if (hit = (*it)->intersect(ray, nearestPoint))
				{
					QVector<double> vec;
					vec << nearestPoint.x() - p.x() << nearestPoint.y() - p.y() << nearestPoint.z() - p.z();
					double orthNorm, vecNorm;

					orthNorm = sqrt(ray.vector()[0]* ray.vector()[0]+ ray.vector()[1]* ray.vector()[1]+ ray.vector()[2]* ray.vector()[2]);
					vecNorm = sqrt(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]);
					double dot = (ray.vector()[0] * vec[0] + ray.vector()[1] * vec[1] + ray.vector()[2] * vec[2]) / (orthNorm*vecNorm);
					double theta = acos(dot);
					
					hit = (m_screen.dir() && theta != 0) || (!m_screen.dir() && theta == 0);

					if(hit)
						nearest = *it;
				}
			}

			if (hit)
			{
				QColor c = recursiveRay(nearest, p, nearestPoint, rebound);
				m_output.setPixelColor(p.x(), p.y(), c);
			}
			
		}

	}
}

QColor Scene::recursiveRay(GeometryPointer s, Point init, Point end, int r)
{
	if (r == 0)
		return m_ambient;

	QList<GeometryPointer> ordered = spheres();
	
	sort(ordered, end);
	QColor ret;
	ret.setRed(s->material().original().red());
	ret.setGreen(s->material().original().green());
	ret.setBlue(s->material().original().blue());

	QVector<double> normalPoint = s->normalToPoint(end);

	QVector<double> out;
	out << init.x() - end.x() << init.y() - end.y() << init.z() - end.z();

	auto getNorm = [](QVector<double> vec) {
		return sqrt(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]);
	};

	for (auto it : lights())
	{
		Line ray;
		ray.setOrigin(end);

		QVector<double> vec;
		vec << it.position().x() - end.x() << it.position().y() - end.y() << it.position().z() - end.z();
		double norm = getNorm(vec);;
		vec[0] /= norm; vec[1] /= norm; vec[2] /= norm;

		ray.setVector(vec);

		double theta = 0;
		theta = normalPoint[0] * vec[0] + normalPoint[1] * vec[1] + normalPoint[2] * vec[2];
		theta /= (getNorm(normalPoint) * getNorm(vec));
		double angle = acos(theta);

		if (angle > pi/4)
			continue;

		bool otherHit = false;
		Point pt;
		GeometryPointer nearest = !spheres().isEmpty() ? spheres().first() : GeometryPointer();

		for (auto it2 : spheres())
		{
			otherHit = !it2->intersect(ray, pt);
			otherHit &= (it2->distanceTo(pt) < it2->distanceTo(it.position()));

			if (it2->distanceTo(end) < nearest->distanceTo(end))
				nearest = it2;
		}
		if (otherHit)
		{
			QColor nColor = recursiveRay(nearest, end, pt, r - 1);
			auto normal = nearest->normalToPoint(end);
			QColor combinated = s->material().combinateLight(out, normal, ray.vector(), QColor(it.red(), it.green(), it.blue()));

			ret.setRed((nColor.red() + combinated.red())/2 < 255 ? (nColor.red() + combinated.red())/2 : 255);
			ret.setBlue((nColor.blue() + combinated.blue())/2 < 255 ? (nColor.blue() + combinated.blue())/2 : 255);
			ret.setBlue((nColor.green() + combinated.green())/2 < 255 ? (nColor.green() + combinated.green())/2 : 255);
			ret.setAlpha(std::min(nColor.alpha(), combinated.alpha()));
		}
		else
		{
			QVector<double> normal = s->normalToPoint(end);

			QColor nColor = s->material().combinateLight(out, normal, ray.vector(), QColor(it.red(), it.green(), it.blue()));

			int r, nr, g, ng, b, nb;
			r = ret.red(); g = ret.green(); b = ret.blue();
			nr = nColor.red(); ng = nColor.green(); nb = nColor.blue();

			nr += r; nb += b; ng += g;
			nr /= 2; nb /= 2; ng /= 2;

			ret.setRed(nr < 255 ? nr : 255);
			ret.setGreen(ng < 255 ? ng : 255);
			ret.setBlue(nb < 255 ? nb : 255);
			ret.setAlpha(std::min(ret.alpha(), nColor.alpha()));

		}
	}	


	return ret;
}


void Scene::save(QString filename)
{
	qDebug() << m_output.save(filename);
}