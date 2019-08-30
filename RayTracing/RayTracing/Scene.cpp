#include "Scene.h"



Scene::Scene()
{
}


Scene::~Scene()
{
}

void Scene::addGeometry(Sphere s)
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

QList<Sphere> Scene::spheres() const
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

void Scene::sort(QList<Sphere>& list, Point origin) 
{
	for (int i = 0; i < list.size(); i++)
		for (int j = i + 1; j < list.size(); j++)
			if (list[j].distanceTo(origin) < list[i].distanceTo(origin))
				list.swapItemsAt(i, j);
}

void Scene::rayTracing()
{
	m_output = QImage(m_screen.width(), m_screen.height(), QImage::Format_RGB32);

	QList<Sphere> ordered = spheres();
	Point origin = screen().position();


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
			Sphere nearest = !m_geometry.isEmpty() ? m_geometry.first() : Sphere();
			bool hit = false;

			for (auto it = ordered.begin(); !hit && it != ordered.end(); it++)
			{
				if (hit = it->intersect(ray))
				{
					nearest = *it;
				}
			}

			if (hit)
				m_output.setPixelColor(p.x(), p.y(), nearest.material().original());
			else
				m_output.setPixelColor(p.x(), p.y(), Qt::black);
		}

	}
}

void Scene::save(QString filename)
{
	qDebug() << m_output.save(filename);
}