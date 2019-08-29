#include "Material.h"



Material::Material()
{
}

Material::Material(const Material& other): m_original(other.original()), m_diffus(other.diffuse())
{
}


Material::~Material()
{
}

Material& Material::operator =(const Material& m)
{
	m_original = m.original();
	m_diffus = m.diffuse();

	return *this;
}

QColor Material::original() const
{
	return m_original;
}

void Material::setOriginal(QColor a)
{
	m_original = a;
}

double Material::diffuse() const
{
	return m_diffus;
}

void Material::setDiffuse(double d)
{
	m_diffus = d;
}

QColor Material::diffusing(QVector<int> norm, QVector<int> inLight, QColor inColor) const
{
	double dot = norm[0]*inLight[0] + norm[1]*inLight[1]+norm[2]*inLight[2];

	dot *= diffuse();

	inColor.setRed(inColor.red() * dot);
	inColor.setGreen(inColor.green() * dot);
	inColor.setBlue(inColor.blue() * dot);

	return inColor;
}