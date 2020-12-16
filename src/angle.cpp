#include <axl.math/constants.hpp>
#include <axl.math/angle.hpp>
#include <cmath>
namespace axl {
namespace math {
namespace Angle
{
using namespace axl::math::Constants;

double degToRad(double deg)
{
	return deg * D_1_180TH_PI;
}
double radToDeg(double rad)
{
	return rad * D_180_OVER_PI;
}
double normToRad(double norm)
{
	return norm * D_2_PI;
}
double radToNorm(double rad)
{
	return rad / D_2_PI;
}
double normToDeg(double norm)
{
	return norm * 360.0;
}
double degToNorm(double deg)
{
	return deg / 360.0;
}
// float
float degToRad(float deg)
{
	return deg * F_1_180TH_PI;
}
float radToDeg(float rad)
{
	return rad * F_180_OVER_PI;
}
float normToRad(float norm)
{
	return norm * F_2_PI;
}
float radToNorm(float rad)
{
	return rad / F_2_PI;
}
float normToDeg(float norm)
{
	return norm * 360.0f;
}
float degToNorm(float deg)
{
	return deg / 360.0f;
}

} // namespace Angle
} // namespace axl.math
} // namespace axl
