#include "Material.h"



Material::Material()
{
}

Material::Material(const Material& other): m_original(other.original()), m_diffus(other.diffuse()),
m_specularity(other.specularity()), m_shininess(other.shininess())
{
}


Material::~Material()
{
}

Material& Material::operator =(const Material& m)
{
	m_original = m.original();
	m_diffus = m.diffuse();
	m_specularity = m.specularity();
	m_shininess = m.shininess();

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

double Material::specularity() const
{
	return m_diffus;
}

void Material::setSpecularity(double s)
{
	m_specularity = s;
}

int Material::shininess() const
{
	return m_shininess;
}

void Material::setShininess(int s)
{
	m_shininess = s;
}


QColor Material::diffusing(QVector<double> norm, QVector<double> inLight, QColor inColor) const
{
	double dot = norm[0]*inLight[0] + norm[1]*inLight[1]+norm[2]*inLight[2];

	dot *= diffuse();

	
	inColor.setRed(abs(inColor.red() * dot));
	inColor.setGreen(abs(inColor.green() * dot));
	inColor.setBlue(abs(inColor.blue() * dot));

	return inColor;
}

QColor Material::specularing(QVector<double> eye, QVector<double> normal, QVector<double> light, QColor inColor) const
{
	QVector<double> h;
	h << (eye[0] + light[0]) / 2;
	h << (eye[1] + light[1]) / 2;
	h << (eye[2] + light[2]) / 2;

	double dot = h[0] * normal[0] + h[1] * normal[1] + h[2] * normal[2];
	double intensity = 1;

	for (int i = 0; i < shininess(); i++)
		intensity *= dot;

	intensity *= specularity();

	inColor.setRed(inColor.red() * intensity);
	inColor.setGreen(inColor.green() * intensity);
	inColor.setBlue(inColor.blue() * intensity);

	return inColor;
}
