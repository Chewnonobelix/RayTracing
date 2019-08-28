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

			Sphere nearest = m_geometry.first();
			for (auto s : m_geometry)
			{
				if (s.intersect(ray))
				{
					if (s.distanceTo(p) < nearest.distanceTo(p))
					{
						nearest = s;
					}
				}
			}
			ray.setOrigin(p);
		}
	}
}