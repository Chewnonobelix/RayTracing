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
