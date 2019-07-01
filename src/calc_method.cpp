#include "calc_method.h"

CalculationMethod::CalculationMethod()
{

}

CalculationMethod::~CalculationMethod()
{

}

/*....................................*/

bool CalculationMethod::operator()(const Line &_line, const Area &_area) {
	setLine(_line);
	setArea(_area);
	return calculate();
}

void CalculationMethod::setLine(const Line &_line) {
	m_line = _line;
}

void CalculationMethod::setArea(const Area &_area) {
	m_area = _area;
}