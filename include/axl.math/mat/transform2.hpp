#pragma once
#include "../lib.hpp"
#include "Mat2f.hpp"
#include "Mat2d.hpp"

namespace axl {
namespace math {
namespace Transform2 {

AXLMATHAPI Mat2f transform(float scale, float translate);
AXLMATHAPI Mat2f scale(float scale);
AXLMATHAPI Mat2f translate(float translate);

AXLMATHAPI Mat2d transform(double scale, double translate);
AXLMATHAPI Mat2d scale(double scale);
AXLMATHAPI Mat2d translate(double translate);

} // namespace axl.math.Transform2
} // namespace axl.math
} // namespace axl
