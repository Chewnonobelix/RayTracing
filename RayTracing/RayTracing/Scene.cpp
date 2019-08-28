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

void Scene::rayTracing()
{
	m_output = m_output.scaled(m_screen.width(), m_screen.height());

	QList<Sphere> ordered = spheres();
	Point origin = screen().position();

	auto sort = [](QList<Sphere>& list, Point origin) {
		for (int i = 0; i < list.size(); i++)
			for (int j = i + 1 j < list.size(); j++)
				if (list[j].distanceTo(origin) < list[i].distanceTo(origin))
					list.swapItemAt(i, j);
	};

	sort(ordered, origin);

	for (int i = 1; i <= m_screen.width(); i++)
	{
		for (int j = 1; j <= m_screen.height(); j++)
		{
			Line ray;
			ray.setVector(m_screen.orthogonal());
			Point p = m_screen.position();
			p.setX((p.x() * m_screen.u()[0] + p.y() * m_screen.u()[1] + p.z() * m_screen.u()[2])*i);
			p.setY((p.x() * m_screen.v()[0] + p.y() * m_screen.v()[1] + p.z() * m_screen.v()[2])*j);
			p.setZ(p.x() * m_screen.orthogonal()[0] + p.y() * m_screen.orthogonal()[1] + p.z() * m_screen.orthogonal()[2]);
			ray.setOrigin(p);

			sort(ordered, p);
			Sphere nearest = m_geometry.first();
			bool hit = false;

			for (auto it = ordered.begin(); !hit && it != ordered.end(); it++)
			{
				if (hit = s.intersect(ray))
				{
					nearest = *it;
				}
			}
		}
	}
}