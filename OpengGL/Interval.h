#pragma once
#include <functional>
class Interval
{
	float start = 0.0;
	float end = 1.0;
	
public:

	Interval() = default;

	Interval(const float start, const float end)
	{
		if(start > end)
		{
			this->end = start;
			this->start = end;
			return;
		}
		this->start = start;
		this->end = end;
	};

	void forEach(const std::function<void(float)>& func, const float step) const
	{
		for(auto i = start; i < end; i += step )
		{
			func(i);
		}
	}
	

	
};

