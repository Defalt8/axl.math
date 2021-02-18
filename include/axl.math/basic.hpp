#pragma once
#include "lib.hpp"

namespace axl {
namespace math {

AXLMATHAPI float sin(float angle);
AXLMATHAPI float cos(float angle);
AXLMATHAPI float tan(float angle);
AXLMATHAPI float asin(float angle);
AXLMATHAPI float acos(float angle);
AXLMATHAPI float atan(float angle);
AXLMATHAPI float atan2(float y, float x);
AXLMATHAPI float sinh(float angle);
AXLMATHAPI float cosh(float angle);
AXLMATHAPI float tanh(float angle);
AXLMATHAPI float asinh(float angle);
AXLMATHAPI float acosh(float angle);
AXLMATHAPI float atanh(float angle);
AXLMATHAPI float mod(float dividend, float divisor);
AXLMATHAPI float sqrt(float value);
AXLMATHAPI float log(float value);
AXLMATHAPI float log2(float value);
AXLMATHAPI float log10(float value);
AXLMATHAPI float pow(float base, float power);

AXLMATHAPI double sin(double angle);
AXLMATHAPI double cos(double angle);
AXLMATHAPI double tan(double angle);
AXLMATHAPI double asin(double angle);
AXLMATHAPI double acos(double angle);
AXLMATHAPI double atan(double angle);
AXLMATHAPI double atan2(double y, double x);
AXLMATHAPI double sinh(double angle);
AXLMATHAPI double cosh(double angle);
AXLMATHAPI double tanh(double angle);
AXLMATHAPI double asinh(double angle);
AXLMATHAPI double acosh(double angle);
AXLMATHAPI double atanh(double angle);
AXLMATHAPI double mod(double dividend, double divisor);
AXLMATHAPI double sqrt(double value);
AXLMATHAPI double log(double value);
AXLMATHAPI double log2(double value);
AXLMATHAPI double log10(double value);
AXLMATHAPI double pow(double base, double power);

} // namespace axl.math
} // namespace axl