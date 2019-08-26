#include "Line.h"



Line::Line()
{
}

Line::Line(const Line& other): m_begin(other.begin()), m_end(other.end())
{
}

Line::~Line()
{
}


Point Line::begin() const
{
	return m_begin;
}

void Line::setBegin(Point b)
{
	m_begin = b;
}

Point Line::end() const
{
	return m_end;
}

void Line::setEnd(Point e)
{
	m_end = e;
}

double Line::length() const
{
	double ret = (m_begin.x() - m_end.x())*(m_begin.x() - m_end.x()) + (m_begin.y() - m_end.y())*(m_begin.y() - m_end.y()) + (m_begin.z() - m_end.z())*(m_begin.z() - m_end.z());
	return sqrt(ret);
}

bool operator == (const Line& l1, const Line& l2)
{
	return l1.begin() == l2.begin() && l1.end() == l2.end();
}

Line& Line::operator =(const Line& other)
{
	m_begin = other.begin();
	m_end = other.end();

	return *this;
}
