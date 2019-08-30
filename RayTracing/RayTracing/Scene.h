#pragma once

#include <QImage>
#include <qdebug.h>
#include <QList>
#include "Sphere.h"
#include "Light.h"
#include "Screen.h"

#define rebound 0

class Scene
{
private:
	QList<Sphere> m_geometry;
	QList<Light> m_lights;
	Screen m_screen;
	QImage m_output;

	void sort(QList<Sphere>& list, Point origin);
public:
	Scene();
	~Scene();

	void addGeometry(Sphere s);
	void addLight(Light l);
	void addScreen(Screen s);

	QList<Sphere> spheres() const;
	QList<Light> lights() const;
	Screen screen() const;

	void rayTracing();

	void save(QString filename);
};

