#include "Point.h"

Point::Point(double x, double y, double z): m_x(x), m_y(y), m_z(z)
{
}

Point::Point(const Point& t) : m_x(t.x()), m_y(t.y()), m_z(t.z())
{

}

Point::~Point()
{
}


double Point::x() const
{
	return m_x;
}

void Point::setX(double x)
{
	m_x = x;
}

double Point::y() const
{
	return m_y;
}

void Point::setY(double y)
{
	m_y = y;
}

double Point::z() const
{
	return m_z;
}

void Point::setZ(double z)
{
	m_z = z;
}


bool operator ==(const Point& t1, const Point& t2)
{
	return t1.x() == t2.x() && t1.y() == t2.y() && t1.z() == t2.z();
}

bool operator < (const Point& t1, const Point& t2)
{
	return t1.x() < t2.x() || t1.y() < t2.y() || t1.z() < t2.z();
}

Point& Point::operator =(const Point& other)
{
	m_x = other.x();
	m_y = other.y();
	m_z = other.z();

	return *this;
}
