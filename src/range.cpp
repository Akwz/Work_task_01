#include "range.h"

Range::Range(const float &from, const float &to)
	: m_from(from)
	, m_to(to)
{

}

Range::Range(const float &val)
	: Range(val, val)
{
	
}

/*....................................................*/

float Range::from() const {
	return m_from;
}

float Range::to() const {
	return m_to;
}