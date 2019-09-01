#include "AbstractGeometry.h"



AbstractGeometry::AbstractGeometry()
{
}

AbstractGeometry::AbstractGeometry(const AbstractGeometry& other): m_mat(other.material())
{
}


AbstractGeometry::~AbstractGeometry()
{
}


bool operator == (const AbstractGeometry& s1, const AbstractGeometry& s2)
{
	return true;
}

AbstractGeometry& AbstractGeometry::operator = (const AbstractGeometry& other)
{
	m_mat = other.material();

	return *this;
}

Material AbstractGeometry::material() const
{
	return m_mat;
}

void AbstractGeometry::setMaterial(const Material& m)
{
	m_mat = m;
}
