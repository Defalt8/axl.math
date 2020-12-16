#pragma once
#include "lib.hpp"

namespace axl {
namespace math {
namespace Util {

AXLMATHAPI float clamp(float value, float min, float max);
AXLMATHAPI double clamp(double value, double min, double max);
AXLMATHAPI float map(float value, float from_min, float from_max, float to_min, float to_max);
AXLMATHAPI double map(double value, double from_min, double from_max, double to_min, double to_max);
AXLMATHAPI float round(float value);
AXLMATHAPI double round(double value);
AXLMATHAPI float floor(float value);
AXLMATHAPI double floor(double value);
AXLMATHAPI float ceil(float value);
AXLMATHAPI double ceil(double value);

} // namespace axl.math.Util
} // namespace axl.math
} // namespace axl