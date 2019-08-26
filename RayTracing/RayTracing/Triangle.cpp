#include "Triangle.h"

Triangle::Triangle()
{
}

Triangle::Triangle(const Triangle& other): m_p1(other.p1()), m_p2(other.p2()), m_p3(other.p3())
{
}

Triangle::~Triangle()
{
}


bool operator ==(const Triangle& t1, const Triangle& t2)
{
	return t1.p1() == t2.p1() && t1.p2() == t2.p2() && t1.p3() == t2.p3();
}

Triangle& Triangle::operator =(const Triangle& other)
{
	m_p1 = other.p1();
	m_p2 = other.p2();
	m_p3 = other.p3();

	return *this;
}

Point Triangle::p1() const
{
	return m_p1;
}

void Triangle::setP1(Point p1)
{
	m_p1 = p1;
}

Point Triangle::p2() const
{
	return m_p2;
}

void Triangle::setP2(Point p2)
{
	m_p2 = p2;
}

Point Triangle::p3() const
{
	return m_p3;
}

void Triangle::setP3(Point p3)
{
	m_p3 = p3;
}

bool Triangle::intersect(Line l) const
{
	return false;
}
