#pragma once
#include "../lib.hpp"

namespace axl {
namespace math {

class AXLMATHCXXAPI Rectangled
{
	public:
		Rectangled(double x1 = 0.0, double y1 = 0.0, double x2 = 0.0, double y2 = 0.0);
		Rectangled(const Rectangled& rectangle);
		void set(double x1, double y1, double x2, double y2);
		bool isOverlapping(const Rectangled& rectangle) const;
	public:
		double x1, y1, x2, y2;
};

} // axl.math
} // axl
