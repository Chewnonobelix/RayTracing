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

public:
	Screen();
	virtual ~Screen();
};

