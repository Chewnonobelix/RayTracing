#include "Line.h"



Line::Line()
{
	m_vector << 0 << 0 << 0;
}

Line::Line(const Line& other): m_vector(other.vector()){
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

void Line::setVector(double u, double v, double w)
{
	m_vector[0] = u;
	m_vector[1] = v;
	m_vector[2] = w;
}

bool operator == (const Line& l1, const Line& l2)
{
	return l1.vector() == l2.vector();
}

Line& Line::operator =(const Line& other)
{
	m_vector = other.vector();
	
	return *this;
}
