#ifndef AREA_H
#define AREA_H

#include <list>

#include "figure.h"
#include "point.h"
#include "range.h"

class Area : public Figure {
private:

public:
	explicit Area(const Point &p1, const Point &p2, const Point &p3, const Point &p4);
	explicit Area(const Point &p1 = Point());
	explicit Area(const std::list<Point> &pts);
	Area(const Area &val);

	Area& operator=(const Area &val);

	Point p1() const;
	Point p2() const;
	Point p3() const;
	Point p4() const;

	float minX() const;
	float maxX() const;
	float minY() const;
	float maxY() const;

	Range xRange() const;
	Range yRange() const;

private:
	Point operator[](const int& idx) const;
};

#endif