#pragma once
#include "../lib.hpp"

namespace axl {
namespace math {

class AXLMATHCXXAPI Rectanglef
{
	public:
		Rectanglef(float x1 = 0.0f, float y1 = 0.0f, float x2 = 0.0f, float y2 = 0.0f);
		Rectanglef(const Rectanglef& rectangle);
		void set(float x1, float y1, float x2, float y2);
		bool isOverlapping(const Rectanglef& rectangle) const;
	public:
		float x1, y1, x2, y2;
};

} // axl.math
} // axl
