#pragma once

class Point
{
private:
	double m_x;
	double m_y;
	double m_z;

public:
	Point(double x = 0, double y = 0, double z = 0);
	Point(const Point& t);
	virtual ~Point();

	double x() const;
	void setX(double x);
	double y() const;
	void setY(double y);
	double z() const;
	void setZ(double z);


	friend bool operator ==(const Point& t1, const Point& t2);
	friend bool operator < (const Point& t1, const Point& t2);
	Point& operator =(const Point& other);
};
