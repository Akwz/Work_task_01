#ifndef INTERVAL_H
#define INTERVAL_H


class Interval {
private:
	const float m_X_DIFF;
	const float m_Y_DIFF;
public:
	explicit Interval(float x_diff = 0, float y_diff = 0);

	float X() const;
	float Y() const;

};

#endif