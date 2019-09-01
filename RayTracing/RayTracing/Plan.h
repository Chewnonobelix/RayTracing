#pragma once

#include <QVector>
#include <QDebug>
#include "Point.h"
#include "Material.h"
#include "AbstractGeometry.h"

class Plan: public AbstractGeometry
{
private:
	QVector<Point> m_corner;
	Material m_material;

public:
	Plan();
	Plan(const Plan& other);
	virtual ~Plan();

	Plan& operator =(const Plan& other);
	friend bool operator == (const Plan& p1, const Plan& p2);

	QVector<Point> corners() const;
	void setCorners(QVector<Point> c);
	Material material() const;
	void setMaterial(Material m);

	bool intersect(const Line& l, Point& nearest) const;
	double distanceTo(const Point& p) const;
	QVector<double> normalToPoint(const Point& p) const;

};

