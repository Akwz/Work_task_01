#ifndef LINE_H
#define LINE_H

#include <list>

#include "figure.h"
#include "point.h"
#include "range.h"

class Line : public Figure {
public:
	explicit Line(const Point &begin, const Point &end);
	explicit Line(const Point &p = Point());
	explicit Line(const std::list<Point> &line_points);
	Line(const Line &ln);

	Line& operator=(const Line &ln);

	void setStartPoint(const Point &p);
	void setEndPoint(const Point &p);

	Range xRange() const;
	Range yRange() const;
};

#endif 