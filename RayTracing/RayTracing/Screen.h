#pragma once

#include <QVector>
#include "Point.h"

class Screen
{
private:
	QVector<int> m_u;
	QVector<int> m_v;
	int m_width;
	int m_height;
	Point m_position;
	bool m_dir;

public:
	Screen();
	Screen(const Screen& other);
	virtual ~Screen();

	QVector<int> u() const;
	void setU(QVector<int> u);
	QVector<int> v() const;
	void setV(QVector<int> v);
	int width() const;
	void setWidth(int w);
	int height() const;
	void setHeight(int h);
	Point position() const;
	void setPosition(Point p);
	bool dir() const;
	void setDir(bool dir);

	friend bool operator == (const Screen& s1, const Screen& s2);
	Screen& operator=(const Screen& other);

};

