#include "figure.h"

Figure::Figure(const std::list<Point> &val)
	: points(val)
{
	if(points.size() == 0) {
		points.push_back(Point());
	}
}

Figure::Figure(const Figure& f)
	: Figure(f.getPoints())
{
	
}

/*...............................................*/

size_t Figure::pointsCount() const {
	return points.size();
}

float Figure::length() const {
	float result = 0.f;

	for(auto itr = points.begin() ,prev_itr = points.begin(); itr != points.end(); prev_itr = itr++) {
		Interval diff = (*itr).getInterval(*prev_itr);
		result += static_cast<float>(
			sqrt(
				pow((double)diff.X(), 2) + pow((double)diff.Y(), 2)
			));
	}

	return result;
}

Point Figure::getStartPoint() const {
	Point result = points.front();
	return result;
}

Point Figure::getEndPoint() const {
	Point result = points.back();
	return result;
}

std::list<Point> Figure::getPoints() const {
	return points;
}