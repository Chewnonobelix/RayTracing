#pragma once

#include <cmath>
#include "Point.h"

class Line
{
private:
	Point m_begin;
	Point m_end;

public:
	Line();
	Line(const Line& other);
	virtual ~Line();

	Point begin() const;
	void setBegin(Point b);
	Point end() const;
	void setEnd(Point e);

	double length() const;
	friend bool operator == (const Line& l1, const Line& l2);
	Line& operator =(const Line& other);
};

