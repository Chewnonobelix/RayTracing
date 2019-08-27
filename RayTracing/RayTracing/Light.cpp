#include "Light.h"

Light::Light()
{}

Light::Light(const Light& other): m_red(other.red()), m_green(other.green()), m_blue(other.blue()), m_power(other.power())
{}

Light::~Light()
{}

int Light::red() const
{
	return m_red;
}

void Light::setRed(int r)
{
	m_red = r;
}

int Light::blue() const
{
	return m_blue;
}

void Light::setBlue(int b)
{
	m_blue = b;
}

int Light::green() const
{
	return m_green;
}

void Light::setGreen(int g)
{
	m_green = g;
}

double Light::power() const
{
	return m_power;
}

void Light::setPower(double p)
{
	m_power = p;
}

Light& Light::operator =(const Light& other)
{
	m_red = other.red();
	m_green = other.green();
	m_blue = other.blue();
	m_power = other.power();

	return *this;
}

bool operator == (const Light& l1, const Light& l2)
{
	return l1.red() == l2.red() &&
		l1.green() == l2.green() &&
		l1.blue() == l2.blue() &&
		l1.power() == l2.power();
}
