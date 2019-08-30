#pragma once

#include <QColor>
#include <cmath>
class Material
{
private:
	QColor m_original;
	double m_diffus;
	double m_specularity;
	int m_shininess;

	QVector<double> normalize(QVector<double> v) const;
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

	QColor diffusing(QVector<double> norm, QVector<double> inLight, QColor inColor) const;
	QColor specularing(QVector<double> eye, QVector<double> normal, QVector<double> light, QColor inColor) const;
	QColor combinateLight(QVector<double> eye, QVector<double> normal, QVector<double> light, QColor inColor) const;
};

