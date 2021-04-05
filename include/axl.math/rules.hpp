#pragma once
#include "lib.hpp"

namespace axl {
namespace math {
namespace Rules {

enum class Axis
{
	LHS,	// left hand side rule
	RHS		// right hand side rule
};

AXLMATHAPI Axis DefaultAxisRule;

} // namespace axl.math.Rules
} // namespace axl.math
} // namespace axl