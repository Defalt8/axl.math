#pragma once
namespace axl {
namespace math {
namespace Float {

extern bool equals(float a, float b, float epsilon = 0.0001f);
extern bool isNan(float n);
extern bool isFinite(float n);
extern bool isInfinite(float n);
extern bool isPosInfinity(float n);
extern bool isNegInfinity(float n);

} // namespace axl.math.Float
} // namespace axl.math
} // namespace axl