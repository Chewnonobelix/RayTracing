#include "Sphere.h"

Sphere::Sphere()
{}

Sphere::Sphere(const Sphere& other): AbstractGeometry(other), 
m_center(other.center()), m_radius(other.radius())
{}

Sphere::~Sphere()
{}

bool operator == (const Sphere& s1, const Sphere& s2)
{
	return s1.center() == s2.center() && s1.radius() == s2.radius();
}

Sphere& Sphere::operator = (const Sphere& other)
{
	AbstractGeometry& t = *this;
	t = other;

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

bool Sphere::intersect(const Line& l, Point& nearest) const
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

	double x1, x2;
	if (delta >= 0)
	{
		x1 = (-b + sqrt(delta)) / (2 * a);
		x2 = (-b - sqrt(delta)) / (2 * a);

		Point p1, p2;
		p1.setX(l.vector()[0] * x1 + l.origin().x());
		p1.setY(l.vector()[1] * x1 + l.origin().y());
		p1.setZ(l.vector()[2] * x1 + l.origin().z());

		p2.setX(l.vector()[0] * x2 + l.origin().x());
		p2.setY(l.vector()[1] * x2 + l.origin().y());
		p2.setZ(l.vector()[2] * x2 + l.origin().z());

		double d1, d2;
		d1 = sqrt((l.origin().x() * p1.x())*(l.origin().x() * p1.x())+
			(l.origin().y() * p1.y())*(l.origin().y() * p1.y())+
			(l.origin().z() * p1.z())*(l.origin().z() * p1.z()));

		d2 = sqrt((l.origin().x() * p2.x())*(l.origin().x() * p2.x()) +
			(l.origin().y() * p2.y())*(l.origin().y() * p2.y()) +
			(l.origin().z() * p2.z())*(l.origin().z() * p2.z()));
	
	
		nearest = d1 < d2 ? p1 : p2;

	}

	return delta >= 0;
}

bool operator < (const Sphere& s1, const Sphere& s2)
{
	double d1, d2;

	d1 = s1.distanceTo(Point(0,0,0));
	d2 = s2.distanceTo(Point(0, 0, 0));

	return (d1 - s1.radius()) < (d2 - s2.radius());
}

double Sphere::distanceTo(const Point& p) const
{
	Point c = center();
	double ret = 0;
	ret += (c.x() - p.x())*(c.x() - p.x());
	ret += (c.y() - p.y())*(c.y() - p.y());
	ret += (c.z() - p.z())*(c.z() - p.z());
	return  sqrt(ret) - radius();
}

QVector<double> Sphere::normalToPoint(const Point& p) const
{
	QVector<double> ret;
	ret << (p.x() - center().x()) << (p.y() - center().y()) << (p.z() - center().z());
	return ret;
}
