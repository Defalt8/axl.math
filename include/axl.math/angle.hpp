#pragma once
#include "lib.hpp"

namespace axl {
namespace math {
namespace Angle {

AXLMATHAPI double degToRad(double deg);
AXLMATHAPI double radToDeg(double rad);
AXLMATHAPI double normToRad(double norm);
AXLMATHAPI double radToNorm(double rad);
AXLMATHAPI double normToDeg(double norm);
AXLMATHAPI double degToNorm(double deg);

AXLMATHAPI float degToRad(float deg);
AXLMATHAPI float radToDeg(float rad);
AXLMATHAPI float normToRad(float norm);
AXLMATHAPI float radToNorm(float rad);
AXLMATHAPI float normToDeg(float norm);
AXLMATHAPI float degToNorm(float deg);

} // namespace axl.math.Angle
} // namespace axl.math
} // namespace axl