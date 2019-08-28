#pragma once

#include <QColor>

class Material
{
private:
	QColor m_ambient;

public:
	Material();
	Material(const Material& m);
	virtual ~Material();

	Material& operator =(const Material& m);

	QColor ambient() const;
	void setAmbient(QColor a);
};

