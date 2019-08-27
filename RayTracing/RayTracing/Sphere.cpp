#include "Sphere.h"

Sphere::Sphere()
{}

Sphere::Sphere(const Sphere& other): m_center(other.center()), m_radius(other.radius())
{}

Sphere::~Sphere()
{}

bool operator == (const Sphere& s1, const Sphere& s2)
{
	return s1.center() == s2.center() && s1.radius() == s2.radius();
}

Sphere& Sphere::operator = (const Sphere& other)
{
	m_center = other.center();
	m_radius = other.radius();

	return *this;
}

Point Sphere::center() const
{
	return m_center;
}

void Sphere::setCenter(Point c)
{
	m_center = c;
}

double Sphere::radius() const
{
	return m_radius;
}

void Sphere::setRadius(double r)
{
	m_radius = r;
}

bool Sphere::intersect(const Line& l) const
{
	double a = 0, b = 0, c = 0;

	for (int i = 0; i < 3; i++)
		a += l.vector()[i] * l.vector()[i];

	Point t;
	t.setX(l.origin().x() - center().x());
	t.setY(l.origin().y() - center().y());
	t.setZ(l.origin().z() - center().z());

	b = 2 * (l.vector()[0] * t.x() + l.vector()[1] * t.y() + l.vector()[2] * t.z());

	double t2 = t.x()*t.x() + t.y()*t.y() + t.z()*t.z();
	c = t2 - radius()*radius();

	double delta = b*b - 4 * a*c;

	return delta >= 0;
}

bool operator < (const Sphere& s1, const Sphere& s2)
{
	double d1, d2;
	Point c1, c2;
	c1 = s1.center(); c2 = s2.center();

	d1 = sqrt(c1.x()*c1.x() + c1.y()*c1.y() + c1.z()*c1.z());
	d2 = sqrt(c2.x()*c2.x() + c2.y()*c2.y() + c2.z()*c2.z());

	return (d1 - s1.radius()) < (d2 - s2.radius());
}