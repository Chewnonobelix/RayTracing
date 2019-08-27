#pragma once

class Light
{
private:
	int m_red;
	int m_green;
	int m_blue;
	double m_power;

public:
	Light();
	Light(const Light& other);
	~Light();

	int red() const;
	void setRed(int r);
	int blue() const;
	void setBlue(int b);
	int green() const;
	void setGreen(int g);
	double power() const;
	void setPower(double p);

	Light& operator =(const Light&);
	friend bool operator == (const Light& l1, const Light& l2);
};

