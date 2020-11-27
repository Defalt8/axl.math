#pragma once
#include "lib.hpp"

namespace axl {
namespace math {
namespace Float {

AXLMATHAPI bool equals(float a, float b, float epsilon = 0.0001f);
AXLMATHAPI bool isNan(float n);
AXLMATHAPI bool isFinite(float n);
AXLMATHAPI bool isInfinite(float n);
AXLMATHAPI bool isPosInfinity(float n);
AXLMATHAPI bool isNegInfinity(float n);

AXLMATHAPI const float Nan;
AXLMATHAPI const float PosInf;
AXLMATHAPI const float NegInf;

} // namespace axl.math.Float
} // namespace axl.math
} // namespace axl