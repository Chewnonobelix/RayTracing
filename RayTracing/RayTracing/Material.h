#pragma once

#include <QColor>

class Material
{
private:
	QColor m_original;

public:
	Material();
	Material(const Material& m);
	virtual ~Material();

	Material& operator =(const Material& m);

	QColor original() const;
	void setOriginal(QColor a);
};

