#pragma once

#include "Line.h"
#include "Point.h"

class Triangle
{
private:
	Point m_p1;
	Point m_p2;
	Point m_p3;

public:
	Triangle();
	Triangle(const Triangle& other);
	virtual ~Triangle();

	friend bool operator ==(const Triangle& t1, const Triangle& t2);
	Triangle& operator =(const Triangle& other);

	Point p1() const;
	void setP1(Point p1);
	Point p2() const;
	void setP2(Point p2);
	Point p3() const;
	void setP3(Point p3);

	bool intersect(Line l) const;
};

