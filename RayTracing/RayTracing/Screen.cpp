#include "Screen.h"


Screen::Screen()
{
	m_u << 0 << 0 << 0;
	m_v << 0 << 0 << 0;
	m_orthogonal << 0 << 0 << 0;
}

Screen::Screen(const Screen& other): m_u(other.u()), m_v(other.v()), m_orthogonal(other.orthogonal()),
m_width(other.width()), m_height(other.height()), m_position(other.position()), m_dir(other.dir())
{
	calculateOrthogonal();
}

Screen::~Screen()
{}

QVector<int> Screen::u() const
{
	return m_u;
}

void Screen::setU(QVector<int> u)
{
	m_u = u;
	calculateOrthogonal();
}

QVector<int> Screen::v() const
{
	return m_v;
}

void Screen::setV(QVector<int> v)
{
	m_v = v;
	calculateOrthogonal();
}

int Screen::width() const
{
	return m_width;
}

void Screen::setWidth(int w)
{
	m_width = w;
}

int Screen::height() const
{
	return m_height;
}

void Screen::setHeight(int h)
{
	m_height = h;
}

Point Screen::position() const
{
	return m_position;
}

void Screen::setPosition(Point p)
{
	m_position = p;
}

bool Screen::dir() const
{
	return m_dir;
}

void Screen::setDir(bool dir)
{
	m_dir = dir;
}

bool operator == (const Screen& s1, const Screen& s2)
{
	return false;
}

Screen& Screen::operator=(const Screen& other)
{
	m_u = other.u();
	m_v = other.v();
	m_position = other.position();
	m_width = other.width();
	m_height = other.height();
	m_dir = other.dir();

	calculateOrthogonal();
	return *this;
}

QVector<int> Screen::orthogonal() const
{
	return m_orthogonal;
}

void Screen::calculateOrthogonal()
{
	m_orthogonal[0] = m_u[1]*m_v[2] - m_u[2]*m_v[1];
	m_orthogonal[1] = m_u[0] * m_v[2] - m_u[2] * m_v[0];
	m_orthogonal[2] = m_u[0] * m_v[1] - m_u[1] * m_v[0];
}
