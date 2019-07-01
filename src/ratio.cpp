#include "ratio.h"

Ratio::Ratio(const float &num, const float &den)
	: m_num(num)
	, m_den(den)
{

}

Ratio::Ratio(const float &num)
	: Ratio(num, 1.f)
{

}

Ratio::Ratio(const Ratio &r)
	: Ratio(r.numerator(), r.denominator())
{

}

/*.............................................................*/

float Ratio::numerator() const {
	return m_num;
}

float Ratio::denominator() const {
	return m_den;
}

void Ratio::setNumerator(const float &val) {
	m_num = val;
}

void Ratio::setDenominator(const float &val) {
	m_den = val;
}

void Ratio::simplify() {
	if(numerator() == 0.f || denominator() == 0.f)
		return;

	float n_mult = numerator() < 0.f ? -1.f : 1.f;
	float d_mult = denominator() < 0.f ? -1.f : 1.f;
	std::list<float> num_mult = factorize(numerator());
	std::list<float> den_mult = factorize(denominator());

	std::vector<float> nod_parts;
	for(auto i = num_mult.begin(); i != num_mult.end(); ++i) {
		for(auto j = den_mult.begin(); j != den_mult.end(); ++j) {
			if((*i) == (*j)) {
				nod_parts.push_back(*j);
				den_mult.erase(j);
				break;
			}
		}
	}

	if(!nod_parts.empty()) {
		float nod = 1.f;
		for(float val : nod_parts) {
			nod *= val;
		}
		setNumerator(numerator() / nod);
		setDenominator(denominator() / nod);
	}

	if(n_mult < 0.f && d_mult < 0.f) {
		setNumerator(n_mult * numerator());
		setDenominator(d_mult * denominator());
	}
}

std::list<float> Ratio::factorize(const float &val) {
	std::list<float> result;
	float value = std::abs(val);
	for(float t = 2.f; t <= value; ++t) {
		if(isPrime(t)) {
			if(fmod(value, t) == 0.f) {
				result.push_back(t);
				value = value / t;
				t = 2.f;
			}
		}
	}
	return result;
}

bool Ratio::isPrime(const float &val) {
	bool result = true;
	for(float i = 2.f; i*i <= val; ++i) {
		if(fmod(val, i) == 0.f){
			result = false;
			break;
		}
	}
	return result;
}

/*..............................................................*/

Ratio& Ratio::operator=(const Ratio &r) {
	this->m_num = r.numerator();
	this->m_den = r.denominator();
	return (*this);
}

Ratio Ratio::operator+(const Ratio &r) {
	float num = this->m_num * r.denominator() + r.numerator() * this->denominator();
	float den = this->m_den * r.denominator();
	Ratio result(num, den);
	result.simplify();
	return result;
}

Ratio Ratio::operator-(const Ratio &r) {
	float num = this->m_num * r.denominator() - r.numerator() * this->denominator();
	float den = this->m_den * r.denominator();
	Ratio result(num, den);
	result.simplify();
	return result;
}

Ratio Ratio::operator*(const Ratio &r) {
	float num = this->m_num * r.numerator();
	float den = this->m_den * r.denominator();
	Ratio result(num, den);
	result.simplify();
	return result;
}

Ratio Ratio::operator/(const Ratio &r) {
	float num = this->m_num * r.denominator();
	float den = this->m_den * r.numerator();
	Ratio result(num, den);
	result.simplify();
	return result;
}

Ratio::operator float() const {
	return numerator() / denominator();
}