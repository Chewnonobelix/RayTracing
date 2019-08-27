#pragma once

#include <cmath>
#include <QVector>
#include "Point.h"

class Line
{
private:
	QVector<double> m_vector;
	Point m_origin;

public:
	Line();
	Line(const Line& other);
	virtual ~Line();

	QVector<double> vector() const;
	void setVector(QVector<double> v);
	void setVector(double u, double v, double w);

	Point origin() const;
	void setOrigin(Point o);

	friend bool operator == (const Line& l1, const Line& l2);
	Line& operator =(const Line& other);
};

