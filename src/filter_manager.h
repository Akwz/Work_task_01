#ifndef FILTER_MANAGER_H
#define FILTER_MANAGER_H

#include <list>

#include "area.h"
#include "line.h"
#include "calc_method.h"
#include "algorithms.h"

class FilterManager {
private:

	Area m_area;
	std::list<Line> m_lines;

	// calculation method
	CalculationMethod *isCrosses;
	// calculation method

public:
	FilterManager(CalculationMethod *method = (new Algorithms::throughGeneralEquation()));
	~FilterManager();

	void setArea(const Area &a);
	void setLines(const std::list<Line> &lines);
	std::list<Line> filter() const;
};

#endif