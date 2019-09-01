#pragma once

#include <QImage>
#include <qdebug.h>
#include <QList>
#include <QSharedPointer>
#include "Sphere.h"
#include "Light.h"
#include "Screen.h"

#define rebound 1

typedef QSharedPointer<AbstractGeometry> GeometryPointer;

class Scene
{
private:
	QList<GeometryPointer> m_geometry;
	QList<Light> m_lights;
	Screen m_screen;
	QImage m_output;
	QColor m_ambient;

	void sort(QList<GeometryPointer>& list, Point origin);
	QColor recursiveRay(GeometryPointer s, Point init , Point touch, int r);

public:
	Scene();
	~Scene();

	void addGeometry(GeometryPointer s);
	void addLight(Light l);
	void addScreen(Screen s);

	QList<GeometryPointer> spheres() const;
	QList<Light> lights() const;
	Screen screen() const;

	void rayTracing();

	void save(QString filename);
};

