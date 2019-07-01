#include "line.h"

Line::Line(const Point &begin, const Point &end)
	: Figure(std::list<Point>{begin, end})
{

}

Line::Line(const std::list<Point> &line_points)
	: Figure(line_points)
{
	
}

Line::Line(const Point &p)
	: Line(p, p)
{

}

Line::Line(const Line &ln)
	: Line(ln.getStartPoint(), ln.getEndPoint())
{

}

/*..........................................*/

Line& Line::operator=(const Line &ln) {
	this->setStartPoint(ln.getStartPoint());
	this->setEndPoint(ln.getEndPoint());
	return (*this);
}

/*..........................................*/

void Line::setStartPoint(const Point &p) {
	points.pop_front();
	points.push_front(p);
}

void Line::setEndPoint(const Point &p) {
	points.pop_back();
	points.push_back(p);
}

Range Line::xRange() const {
	return Range(getStartPoint().getX(), getEndPoint().getX());
}

Range Line::yRange() const {
	return Range(getStartPoint().getY(), getEndPoint().getY());
}