#pragma once
#include "lib.hpp"

namespace axl {
namespace math {
namespace Double {

AXLMATHAPI bool equals(double a, double b, double epsilon = 0.0000001);
AXLMATHAPI bool isNan(double n);
AXLMATHAPI bool isFinite(double n);
AXLMATHAPI bool isInfinite(double n);
AXLMATHAPI bool isPosInfinity(double n);
AXLMATHAPI bool isNegInfinity(double n);

AXLMATHAPI const double Nan;
AXLMATHAPI const double PosInf;
AXLMATHAPI const double NegInf;

} // namespace axl.math.Double
} // namespace axl.math
} // namespace axl