#pragma once

#include "Point.h"
#include "Line.h"

class Sphere
{
private:
	Point m_center;
	double m_radius;

public:
	Sphere();
	Sphere(const Sphere& other);
	~Sphere();

	friend bool operator == (const Sphere& s1, const Sphere& s2);
	Sphere& operator = (const Sphere& other);

	Point center() const;
	void setCenter(Point c);
	double radius() const;
	void setRadius(double r);

	bool intersect(const Line& l) const;
};

