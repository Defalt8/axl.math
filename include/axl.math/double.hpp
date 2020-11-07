#pragma once
namespace axl {
namespace math {
namespace Double {

extern bool equals(double a, double b, double epsilon = 0.0000001);
extern bool isNan(double n);
extern bool isFinite(double n);
extern bool isInfinite(double n);
extern bool isPosInfinity(double n);
extern bool isNegInfinity(double n);

} // namespace axl.math.Double
} // namespace axl.math
} // namespace axl