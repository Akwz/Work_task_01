#ifndef POINT_H
#define POINT_H

#include <cmath>

#include "interval.h"


namespace coordinate {
	enum name {
		X,
		Y
	};
}

class Point {
private:
	float m_X;
	float m_Y; 
public:
	explicit Point(float val = 0.f);
	explicit Point(float x, float y);
	Point(const Point& p);

	Point& operator=(const Point &p);
	float operator[](coordinate::name val) const;

	float getX() const;
	float getY() const;
	Interval getInterval(const Point &p) const;

};

#endif