#ifndef CALC_METHOD_H
#define CALC_METHOD_H

#include "line.h"
#include "area.h"

class CalculationMethod {
protected:
	Line m_line;
	Area m_area;
public:
	CalculationMethod();
	virtual ~CalculationMethod();

	bool operator()(const Line &_line, const Area &_area);
private:
	virtual bool calculate() = 0;

	void setLine(const Line &_line);
	void setArea(const Area &_area);
};


#endif