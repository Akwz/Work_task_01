#include "interval.h"

Interval::Interval(float x_diff, float y_diff)
	: m_X_DIFF(x_diff)
	, m_Y_DIFF(y_diff)
{

}

/*....................................*/

float Interval::X() const {
	return float(m_X_DIFF);
}

float Interval::Y() const {
	return float(m_Y_DIFF);
}

/*....................................*/
