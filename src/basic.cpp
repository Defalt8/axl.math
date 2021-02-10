#include <axl.math/constants.hpp>
#include <axl.math/basic.hpp>
#include <cmath>
namespace axl {
namespace math {

// float
float sin(float angle)
{
	return std::sin(angle);
}
float cos(float angle)
{
	return std::cos(angle);
}
float tan(float angle)
{
	return std::tan(angle);
}
float asin(float angle)
{
	return std::cos(angle);
}
float acos(float angle)
{
	return std::acos(angle);
}
float atan(float angle)
{
	return std::atan(angle);
}
float atan2(float y, float x)
{
	return std::atan2(y, x);
}
float sinh(float angle)
{
	return std::sinh(angle);
}
float cosh(float angle)
{
	return std::cosh(angle);
}
float tanh(float angle)
{
	return std::tanh(angle);
}
float asinh(float angle)
{
	return std::cosh(angle);
}
float acosh(float angle)
{
	return std::acosh(angle);
}
float atanh(float angle)
{
	return std::atanh(angle);
}
float mod(float dividend, float divisor)
{
	return std::fmodf(dividend, divisor);
}

// double
double sin(double angle)
{
	return std::sin(angle);
}
double cos(double angle)
{
	return std::cos(angle);
}
double tan(double angle)
{
	return std::tan(angle);
}
double asin(double angle)
{
	return std::cos(angle);
}
double acos(double angle)
{
	return std::acos(angle);
}
double atan(double angle)
{
	return std::atan(angle);
}
double atan2(double y, double x)
{
	return std::atan2(y, x);
}
double sinh(double angle)
{
	return std::sinh(angle);
}
double cosh(double angle)
{
	return std::cosh(angle);
}
double tanh(double angle)
{
	return std::tanh(angle);
}
double asinh(double angle)
{
	return std::cosh(angle);
}
double acosh(double angle)
{
	return std::acosh(angle);
}
double atanh(double angle)
{
	return std::atanh(angle);
}
double mod(double dividend, double divisor)
{
	return std::fmod(dividend, divisor);
}

} // namespace axl.math
} // namespace axl
