#pragma once

#include <qdebug.h>
#include "Point.h"
#include "Line.h"
#include "Material.h"
#include "AbstractGeometry.h"

#define pi 3.14159265

class Sphere: public AbstractGeometry
{
private:
	Point m_center;
	double m_radius;

public:
	Sphere();
	Sphere(const Sphere& other);
	~Sphere();

	friend bool operator == (const Sphere& s1, const Sphere& s2);
	friend bool operator < (const Sphere& s1, const Sphere& s2);
	Sphere& operator = (const Sphere& other);

	Point center() const;
	void setCenter(Point c);
	double radius() const;
	void setRadius(double r);

	bool intersect(const Line& l, Point& nearest) const;
	double distanceTo(const Point& p) const;
	QVector<double> normalToPoint(const Point& p) const;
};

