#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <cmath>
#include <list>

#include "line.h"
#include "area.h"
#include "calc_method.h"
#include "ratio.h"
#include "range.h"

namespace Algorithms {

struct Params {
	Ratio A;
	Ratio B;
	Ratio C;
};

struct DirectionVector {
	float X;
	float Y;
};

/* ......................... METHOD №1 ..........................*/
class throughGeneralEquation : public CalculationMethod {
private:

public:
	throughGeneralEquation();
	virtual ~throughGeneralEquation(){}
private:
	virtual bool calculate() override;
	Params getLineEquationParams(const Line &_line) const;
	Params getLineEquationParams(const DirectionVector &_vec, const Point &_p) const;
	DirectionVector getDirVec(const Params &_params) const;
	bool rangesIntersects(const Range &r1, const Range &r2) const;
	float getMax(const std::list<float> &_floats) const;
	float getMin(const std::list<float> &_floats) const;
};
/*...............................................................*/







} // Algorithms


#endif