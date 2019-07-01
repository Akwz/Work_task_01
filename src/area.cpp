#include "area.h"

Area::Area(const Point &p1, const Point &p2, const Point &p3, const Point &p4)
	: Figure(std::list<Point>{p1,p2,p3,p4})
{

}

Area::Area(const Point &p1)
	: Area(p1,p1,p1,p1)
{

}

Area::Area(const std::list<Point> &pts)
	: Figure(pts)
{

}

Area::Area(const Area &val)
	: Area(val.getPoints())
{

}


/*..............................................*/

Point Area::p1() const {
	return (*this)[0];
}

Point Area::p2() const {
	return (*this)[1];
}

Point Area::p3() const {
	return (*this)[2];
}

Point Area::p4() const {
	return (*this)[3];
}

float Area::minX() const {
	float result = points.begin()->getX();
	for(Point p : points) {
		if(p.getX() < result) {
			result = p.getX();
		}
	}
	return result;
}

float Area::maxX() const {
	float result = points.begin()->getX();
	for(Point p : points) {
		if(p.getX() > result) {
			result = p.getX();
		}
	}
	return result;
}

float Area::minY() const {
	float result = points.begin()->getY();
	for(Point p : points) {
		if(p.getY() < result) {
			result = p.getY();
		}
	}
	return result;
}

float Area::maxY() const {
	float result = points.begin()->getY();
	for(Point p : points) {
		if(p.getY() > result) {
			result = p.getY();
		}
	}
	return result;
}

Range Area::xRange() const {
	return Range(minX(), maxX());
}

Range Area::yRange() const {
	return Range(minY(), maxY());
}

/*................................................*/

Point Area::operator[](const int &idx) const {
	Point res = Point();
	int curr_pos = 0;
	for(auto i = points.begin(); i != points.end(); i++) {
		if(curr_pos++ == idx) {
			res = *i;
		}
	}
	return res;
}

Area& Area::operator=(const Area &val) {
	this->points = val.getPoints();
	return (*this);
}