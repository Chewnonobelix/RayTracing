#pragma once

#include <QColor>

class Material
{
private:
	QColor m_original;
	double m_diffus;

public:
	Material();
	Material(const Material& m);
	virtual ~Material();

	Material& operator =(const Material& m);

	QColor original() const;
	void setOriginal(QColor a);
	double diffuse() const;
	void setDiffuse(double d);

	QColor diffusing(QVector<int> norm, QVector<int> inLight, QColor inColor) const;
};

