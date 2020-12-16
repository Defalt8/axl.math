#pragma once
#include "../lib.hpp"
#include "Mat2f.hpp"
#include "Mat2d.hpp"

namespace axl {
namespace math {
namespace Transform2 {

Mat2f AXLMATHAPI transform(float scale, float translate);
Mat2f AXLMATHAPI scale(float scale);
Mat2f AXLMATHAPI translate(float translate);

Mat2d AXLMATHAPI transform(double scale, double translate);
Mat2d AXLMATHAPI scale(double scale);
Mat2d AXLMATHAPI translate(double translate);

} // namespace axl.math.Transform2
} // namespace axl.math
} // namespace axl
