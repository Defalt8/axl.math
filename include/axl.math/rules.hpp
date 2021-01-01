#pragma once
#include "lib.hpp"

namespace axl {
namespace math {
namespace Rules {

typedef enum class _Axis
{
	// left hand side rule
	AXIS_LHS,
	// right hand side rule
	AXIS_RHS
} Axis;

AXLMATHAPI Axis DefaultAxisRule;

} // namespace axl.math.Rules
} // namespace axl.math
} // namespace axl