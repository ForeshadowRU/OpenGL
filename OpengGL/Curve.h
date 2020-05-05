#pragma once
#include <functional>
#include "Interval.h"
class Curve
{
private:
	std::function<float(float)> function;
	Interval interval;
public:
	Curve(const std::function<float(float)>& func,const  Interval &interval)
	{
		this->interval = interval;
		this->function = func;
	}

	float operator()(float x) const{
		return function(x);
	}

	void setInterval(Interval interval)
	{
		this->interval = interval;
	}
	Interval getInterval() const
	{
		return interval;
	}
};

