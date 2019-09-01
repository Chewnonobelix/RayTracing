#include "Plan.h"

Plan::Plan()
{}

Plan::Plan(const Plan& other) : m_corner(other.corners()), m_material(other.material())
{}

Plan::~Plan()
{}

Plan& Plan::operator =(const Plan& other)
{
	m_corner = other.corners();
	m_material = other.material();

	return *this;
}

bool operator == (const Plan& p1, const Plan& p2)
{
	return p1.corners() == p2.corners();
}

QVector<Point> Plan::corners() const
{
	return m_corner;
}

void Plan::setCorners(QVector<Point> c)
{
	m_corner = c;
}

Material Plan::material() const
{
	return m_material;
}

void Plan::setMaterial(Material m)
{
	m_material = m;
}

