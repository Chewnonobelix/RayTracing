#pragma once

#include <qdebug.h>
#include "Point.h"
#include "Line.h"
#include "Material.h"

#define pi 3.14159265

class Sphere
{
private:
	Point m_center;
	double m_radius;
	Material m_mat;

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

	Material material() const;
	void setMaterial(const Material& m);
};

