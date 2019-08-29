#pragma once

#include <QColor>

class Material
{
private:
	QColor m_original;
	double m_diffus;
	double m_specularity;
	int m_shininess;

public:
	Material();
	Material(const Material& m);
	virtual ~Material();

	Material& operator =(const Material& m);

	QColor original() const;
	void setOriginal(QColor a);
	double diffuse() const;
	void setDiffuse(double d);
	double specularity() const;
	void setSpecularity(double s);
	int shininess() const;
	void setShininess(int s);

	QColor diffusing(QVector<int> norm, QVector<int> inLight, QColor inColor) const;
	QColor specularing(QVector<int> eye, QVector<int> normal, QVector<int> light, QColor inColor)
};

