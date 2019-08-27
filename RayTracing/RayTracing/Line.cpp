#include "Line.h"



Line::Line()
{
	m_vector << 0 << 0 << 0;
}

Line::Line(const Line& other): m_vector(other.vector()), m_origin(other.origin())
{
}

Line::~Line()
{
}


QVector<double> Line::vector() const
{
	return m_vector;
}

void Line::setVector(QVector<double> v)
{
	m_vector = v;
}

Point Line::origin() const
{
	return m_origin;
}

void Line::setOrigin(Point o)
{
	m_origin = o;
}

void Line::setVector(double u, double v, double w)
{
	m_vector[0] = u;
	m_vector[1] = v;
	m_vector[2] = w;
}

bool operator == (const Line& l1, const Line& l2)
{
	return l1.vector() == l2.vector() && l1.origin == l2.origin();
}

Line& Line::operator =(const Line& other)
{
	m_vector = other.vector();
	m_origin = other.origin();

	return *this;
}
