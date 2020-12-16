#include <cmath>
#include <axl.math/lib.hpp>
#include <axl.math/util.hpp>

namespace axl {
namespace math {
namespace Util {

float clamp(float value, float min, float max)
{
	return (value <= min ? min : (value >= max ? max : value));
}

double clamp(double value, double min, double max)
{
	return (value <= min ? min : (value >= max ? max : value));
}

float map(float value, float from_min, float from_max, float to_min, float to_max)
{
	return ((value - from_min) * ((to_max - to_min) / (from_max - from_min)) + to_min);
}

double map(double value, double from_min, double from_max, double to_min, double to_max)
{
	return ((value - from_min) * ((to_max - to_min) / (from_max - from_min)) + to_min);
}

float round(float value)
{
	return std::round(value);
}

double round(double value)
{
	return std::round(value);
}

float floor(float value)
{
	return std::floor(value);
}

double floor(double value)
{
	return std::floor(value);
}

float ceil(float value)
{
	return std::ceil(value);
}

double ceil(double value)
{
	return std::ceil(value);
}


} // namespace axl.math.Util
} // namespace axl.math
} // namespace axl