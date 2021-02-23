#pragma once
#include "../lib.hpp"

namespace axl {
namespace math {

class AXLMATHCXXAPI Rectanglei
{
	public:
		Rectanglei(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0);
		Rectanglei(const Rectanglei& rectangle);
		void set(int x1, int y1, int x2, int y2);
		bool isOverlapping(const Rectanglei& rectangle) const;
	public:
		int x1, y1, x2, y2;
};

} // axl.math
} // axl
