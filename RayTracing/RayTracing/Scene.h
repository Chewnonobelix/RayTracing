#pragma once

#include <QList>
#include "Sphere.h"

class Scene
{
private:
	QList<Sphere> m_geometry;

public:
	Scene();
	~Scene();

	void addGeometry(Sphere s);
};

