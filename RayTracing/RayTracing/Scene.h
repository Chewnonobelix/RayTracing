#pragma once

#include <QList>
#include "Sphere.h"

class Scene
{
private:
	QList<Sphere> m_geometry;
	QList<Light> m_lights;
	Screen m_screen;

public:
	Scene();
	~Scene();

	void addGeometry(Sphere s);
	void addLight(Light l);
	void addScreen(Screen s);
};

