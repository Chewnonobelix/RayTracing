#include "Material.h"



Material::Material()
{
}

Material::Material(const Material& other): m_original(other.original())
{
}


Material::~Material()
{
}

Material& Material::operator =(const Material& m)
{
	m_original = m.original();

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
