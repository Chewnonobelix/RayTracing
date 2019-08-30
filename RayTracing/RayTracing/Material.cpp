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
	auto nLight = normalize(inLight);
	auto nNormal = normalize(norm);

	double dot = nNormal[0]* nLight[0] + nNormal[1]* nLight[1]+ nNormal[2]* nLight[2];

	dot *= diffuse();

	
	inColor.setRed(abs(inColor.red() * dot) < 255 ? abs(inColor.red() * dot) : 255);
	inColor.setGreen(abs(inColor.green() * dot) < 255 ? abs(inColor.green() * dot) : 255);
	inColor.setBlue(abs(inColor.blue() * dot) < 255 ? abs(inColor.blue() * dot) : 255);

	return inColor;
}

QColor Material::specularing(QVector<double> eye, QVector<double> normal, QVector<double> light, QColor inColor) const
{
	auto nEye = normalize(eye);
	auto nLight = normalize(light);
	auto nNormal = normalize(normal);

	QVector<double> h;
	h << (nEye[0] + nLight[0]) / 2;
	h << (nEye[1] + nLight[1]) / 2;
	h << (nEye[2] + nLight[2]) / 2;

	auto nH = normalize(h);

	double dot = nH[0] * nNormal[0] + nH[1] * nNormal[1] + nH[2] * nNormal[2];
	double intensity = 1;

	for (int i = 0; i < shininess(); i++)
		intensity *= dot;

	intensity *= specularity();

	inColor.setRed(inColor.red() * intensity < 255 ? inColor.red() * intensity : 255);
	inColor.setGreen(inColor.green() * intensity < 255 ? inColor.green() * intensity : 255);
	inColor.setBlue(inColor.blue() * intensity < 255 ? inColor.blue() * intensity : 255);

	return inColor;
}

QColor Material::combinateLight(QVector<double> eye, QVector<double> normal, QVector<double> light, QColor inColor) const
{
	QColor diff, spec;
	diff = diffusing(normal, light, inColor);
	spec = specularing(eye, normal, light, inColor);

	QColor ret;
	ret.setRed(diff.red() + spec.red() < 255 ? diff.red() + spec.red() : 255);
	ret.setBlue(diff.blue() + spec.blue() < 255 ? diff.blue() + spec.blue() : 255);
	ret.setGreen(diff.green() + spec.green() < 255 ? diff.green() + spec.green() : 255);

	return ret;
}

QVector<double> Material::normalize(QVector<double> v) const
{
	QVector<double> ret;
	double norm;
	norm = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);

	ret << v[0] / norm << v[1] / norm << v[2] / norm;

	return ret;
}