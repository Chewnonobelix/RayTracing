#pragma once

#include "Point.h"
#include "Line.h"
#include "Material.h"


class AbstractGeometry
{
private:
	Material m_mat;

public:
	AbstractGeometry();
	AbstractGeometry(const AbstractGeometry& other);
	virtual ~AbstractGeometry();


	AbstractGeometry& operator =(const AbstractGeometry& other);
	friend bool operator ==(const AbstractGeometry& ag1, const AbstractGeometry& ag2);

	Material material() const;
	void setMaterial(const Material& m);

	virtual bool intersect(const Line& l, Point& nearest) const = 0;
	virtual double distanceTo(const Point& p) const = 0;
	virtual QVector<double> normalToPoint(const Point& p) const = 0;
};

