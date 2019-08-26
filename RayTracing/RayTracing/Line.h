#pragma once

#include <cmath>
#include <QVector>
#include "Point.h"

class Line
{
private:
	QVector<double> m_vector;

public:
	Line();
	Line(const Line& other);
	virtual ~Line();

	QVector<double> vector() const;
	void setVector(QVector<double> v);
	void setVector(double u, double v, double w);

	friend bool operator == (const Line& l1, const Line& l2);
	Line& operator =(const Line& other);
};

