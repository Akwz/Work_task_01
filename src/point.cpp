#include "point.h"

Point::Point(float val)
	: Point(val, val)
{

}

Point::Point(float x, float y)
	: m_X(x)
	, m_Y(y)
{

}

Point::Point(const Point &p)
	: Point(p.m_X, p.m_Y)
{

}

/*.................................................*/

float Point::getX() const {
	return m_X;
}

float Point::getY() const {
	return m_Y;
}

Interval Point::getInterval(const Point& p) const {
	return Interval(abs(this->m_X - p.m_X), abs(this->m_Y - p.m_Y));
}

/*..................................................*/

float Point::operator[](coordinate::name val) const {
	return (val == coordinate::X) ? m_X : m_Y ;
}

Point& Point::operator=(const Point& p) {
	this->m_X = p.m_X;
	this->m_Y = p.m_Y;
	return (*this);
}
