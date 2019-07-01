#ifndef RANGE_H
#define RANGE_H

class Range {
private:
	float m_from;
	float m_to;
public:
	Range(const float &from, const float &to);
	Range(const float &val);

	float from() const;
	float to() const;
};


#endif