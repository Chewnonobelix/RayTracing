#include "Material.h"



Material::Material()
{
}

Material::Material(const Material& other): m_ambient(other.ambient())
{
}


Material::~Material()
{
}

Material& Material::operator =(const Material& m)
{
	m_ambient = m.ambient();

	return *this;
}

QColor Material::ambient() const
{
	return m_ambient;
}

void Material::setAmbient(QColor a)
{
	m_ambient = a;
}
