#ifndef RATIO_H
#define RATIO_H

#include <list>
#include <vector>
#include <cmath>

class Ratio {
private:
	float m_num;
	float m_den;
public:
	explicit Ratio(const float &num, const float &den);
	explicit Ratio(const float &num = 1.f);
	Ratio(const Ratio &r);


	float numerator() const;
	float denominator() const;

	void setNumerator(const float &val);
	void setDenominator(const float &val);

	Ratio& operator=(const Ratio &r);

	Ratio operator+(const Ratio &r);
	Ratio operator-(const Ratio &r);
	Ratio operator*(const Ratio &r);
	Ratio operator/(const Ratio &r);

	operator float() const;
private:
	void simplify();
	std::list<float> factorize(const float &val);
	bool isPrime(const float &val);
};

#endif