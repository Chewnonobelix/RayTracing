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


bool Plan::intersect(const Line& l, Point& nearest) const
{
	bool ret = false;

	double a, b, c, d;

	a = corners()[0].y() * (corners()[1].z() - corners()[2].z()) +
		corners()[1].y() * (corners()[2].z() - corners()[0].z()) +
		corners()[2].y() * (corners()[0].z() - corners()[1].z());

	b = corners()[0].z() * (corners()[1].x() - corners()[2].x()) +
		corners()[1].z() * (corners()[2].x() - corners()[0].x()) +
		corners()[2].z() * (corners()[0].x() - corners()[1].x());

	c = corners()[0].x() * (corners()[1].y() - corners()[2].y()) +
		corners()[1].x() * (corners()[2].y() - corners()[0].y()) +
		corners()[2].x() * (corners()[0].y() - corners()[1].y());

	d = -corners()[0].x() * (corners()[1].y()*corners()[2].z() - corners()[2].y()*corners()[1].z()) -
		corners()[1].x() * (corners()[2].y()*corners()[0].z() - corners()[0].y()*corners()[2].z()) -
		corners()[2].x() * (corners()[0].y()*corners()[1].z() - corners()[1].y()*corners()[0].z());

	double t = 0;

	t = -(a*l.origin().x() + b * l.origin().y() + c * l.origin().z() + d);

	if ((a*l.vector()[0] + b * l.vector()[1] + c * l.vector()[2]) == 0)
		return false;

	t /= (a*l.vector()[0] + b * l.vector()[1] + c * l.vector()[2]);

	nearest.setX(l.origin().x() - l.vector()[0] * t);
	nearest.setY(l.origin().y() - l.vector()[1] * t);
	nearest.setZ(l.origin().z() - l.vector()[2] * t);

	qDebug() << "Intersect plan"<<nearest.x()<<nearest.y()<<nearest.z();
	return true;
}

double Plan::distanceTo(const Point& p) const
{

	return 0;
}

QVector<double> Plan::normalToPoint(const Point& p) const
{
	QVector<double> ret, v1, v2;
	
	v1 << corners()[1].x() - corners()[0].x() << corners()[1].y() - corners()[0].y() << corners()[1].z() - corners()[0].z();
	v2 << corners()[2].x() - corners()[0].x() << corners()[2].y() - corners()[0].y() << corners()[2].z() - corners()[0].z();

	ret << v1[1] * v2[2] - v1[2] * v2[1] << v1[0] * v2[2] - v1[2] * v2[0] << v1[0] * v2[1] - v1[1] * v2[0];

	return ret;
}

