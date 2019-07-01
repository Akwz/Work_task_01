#include "algorithms.h"

namespace Algorithms {

/*......................... throughGeneralEquation .........................*/
throughGeneralEquation::throughGeneralEquation()
	: CalculationMethod()
{

}

bool throughGeneralEquation::calculate() {
	bool result = false;

	// process calculation HERE!
	Params line_eq_params; // составляющие уравнения прямой line
	Params p1_eq_params; // стоставляющие ур-ия прямой в точке p1 исследумой области
	Params p2_eq_params; // стоставляющие ур-ия прямой в точке p2 исследумой области
	Params p3_eq_params; // стоставляющие ур-ия прямой в точке p3 исследумой области
	Params p4_eq_params; // стоставляющие ур-ия прямой в точке p4 исследумой области

	if(!rangesIntersects(m_line.xRange(), m_area.xRange()) || !rangesIntersects(m_line.yRange(), m_area.yRange())) {
		return result;
	}

	// находим все составляющии уравнений общего вида
	line_eq_params = getLineEquationParams(m_line);
	p1_eq_params = getLineEquationParams(getDirVec(line_eq_params), m_area.p1());
	p2_eq_params = getLineEquationParams(getDirVec(line_eq_params), m_area.p2());
	p3_eq_params = getLineEquationParams(getDirVec(line_eq_params), m_area.p3());
	p4_eq_params = getLineEquationParams(getDirVec(line_eq_params), m_area.p4());

	if(static_cast<float>(line_eq_params.A) == 0.f && static_cast<float>(line_eq_params.B) == 0.f) {
		result = true;
	} else if(static_cast<float>(line_eq_params.A) == 0.f) {
		result = true;
	} else if(static_cast<float>(line_eq_params.B) == 0.f) {
		result = true;
	} else {
		std::list<float> C_s{
			p1_eq_params.C,
			p2_eq_params.C,
			p3_eq_params.C,
			p4_eq_params.C};

		Range area_C_range = Range(getMin(C_s), getMax(C_s));
		Range line_C_range(line_eq_params.C);
		result = rangesIntersects(area_C_range, line_C_range);
	}

	return result;
}

bool throughGeneralEquation::rangesIntersects(const Range &r1, const Range &r2) const {
	bool result = false;

	float r1max = std::max(r1.from(), r1.to());
	float r1min = std::min(r1.from(), r1.to());
	float r2max = std::max(r2.from(), r2.to());
	float r2min = std::min(r2.from(), r2.to());
	
	if(r1max >= r2max && r1min <= r2max)
		result = true;
	else if(r1max <= r2max && r1max >= r2min)
		result = true;

	return result;
}

DirectionVector throughGeneralEquation::getDirVec(const Params &_params) const {
	DirectionVector result;

	result.X = static_cast<float>(_params.B) * -1.f;
	result.Y = static_cast<float>(_params.A);

	return result;
}

Params throughGeneralEquation::getLineEquationParams(const DirectionVector &_vec, const Point &_p) const {
	Params result;

	float C1 = _vec.Y * _p.getX() * -1.f;
	float C2 = _vec.X * _p.getY() * -1.f;

	result.A = Ratio(_vec.Y);
	result.B = Ratio(_vec.X * -1.f);
	result.C = Ratio(C1 - C2);

	return result;
}

Params throughGeneralEquation::getLineEquationParams(const Line &_line) const {
	Params result;

	float x1 = _line.getStartPoint().getX();
	float x2 = _line.getEndPoint().getX();
	float y1 = _line.getStartPoint().getY();
	float y2 = _line.getEndPoint().getY();

	result.A = Ratio(
		y1 - y2,
		1.f);
	result.B = Ratio(
		x2 - x1,
		1.f);
	result.C = Ratio(
		x1 * y2 - x2 * y1,
		1.f);

	return result;
}

float throughGeneralEquation::getMax(const std::list<float> &_floats) const {
	float result = _floats.front();
	for(float val : _floats) {
		if(val > result) {
			result = val;
		}
	}
	return result;
}

float throughGeneralEquation::getMin(const std::list<float> &_floats) const {
	float result = _floats.front();
	for(float val : _floats) {
		if(val < result) {
			result = val;
		}
	}
	return result;
}
/*..........................................................................*/






} // Algorithms