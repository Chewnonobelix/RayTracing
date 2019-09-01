#pragma once

#include <QVector>
#include "Point.h"
#include "Material.h"

class Plan
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
};

