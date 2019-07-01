#ifndef FIGURE_H
#define FIGURE_H

#include <list>

#include "point.h"

class Figure {
protected:
	std::list<Point> points;

	Figure(const std::list<Point> &val = std::list<Point>{Point()});
	Figure(const Figure &f);

public:
	size_t pointsCount() const;
	float length() const;
	Point getStartPoint() const;
	Point getEndPoint() const;

	std::list<Point> getPoints() const;
};

#endif