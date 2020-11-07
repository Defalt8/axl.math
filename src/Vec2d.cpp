#include <cmath>
#include <axl.math/constants.hpp>
#include <axl.math/double.hpp>
#include <axl.math/Vec2d.hpp>

namespace axl {
namespace math {

Vec2d::Vec2d(double x, double y) :
	x(x), y(y)
{}
Vec2d::Vec2d(const Vec2d& vec) :
	x(vec.x), y(vec.y)
{}

Vec2d Vec2d::operator+() const
{
	return Vec2d(x, y);
}
Vec2d Vec2d::operator-() const
{
	return Vec2d(-x, -y);
}
Vec2d Vec2d::operator+(const Vec2d& vec) const 
{
	return Vec2d(x + vec.x, y + vec.y);
}
Vec2d Vec2d::operator-(const Vec2d& vec) const 
{
	return Vec2d(x - vec.x, y - vec.y);
}
Vec2d Vec2d::operator*(const Vec2d& vec) const 
{
	return Vec2d(x * vec.x, y * vec.y);
}
Vec2d Vec2d::operator/(const Vec2d& vec) const 
{
	return Vec2d(x / vec.x, y / vec.y);
}
Vec2d Vec2d::operator+(double v) const 
{
	return Vec2d(x + v, y + v);
}
Vec2d Vec2d::operator-(double v) const 
{
	return Vec2d(x - v, y - v);
}
Vec2d Vec2d::operator*(double v) const 
{
	return Vec2d(x * v, y * v);
}
Vec2d Vec2d::operator/(double v) const 
{
	return Vec2d(x / v, y / v);
}
Vec2d& Vec2d::operator+=(const Vec2d& vec) 
{
	x = (x + vec.x); y = (y + vec.y); return *this;
}
Vec2d& Vec2d::operator-=(const Vec2d& vec) 
{
	x = (x - vec.x); y = (y - vec.y); return *this;
}
Vec2d& Vec2d::operator*=(const Vec2d& vec) 
{
	x = (x * vec.x); y = (y * vec.y); return *this;
}
Vec2d& Vec2d::operator/=(const Vec2d& vec) 
{
	x = (x / vec.x); y = (y / vec.y); return *this;
}
Vec2d& Vec2d::operator+=(double v) 
{
	x = x + v; y = y + v; return *this;
}
Vec2d& Vec2d::operator-=(double v) 
{
	x = x - v; y = y - v; return *this;
}
Vec2d& Vec2d::operator*=(double v) 
{
	x = x * v; y = y * v; return *this;
}
Vec2d& Vec2d::operator/=(double v) 
{
	x = x / v; y = y / v; return *this;
}
bool Vec2d::operator==(const Vec2d& vec) const 
{
	return (x == vec.x && y == vec.y);
}
bool Vec2d::operator!=(const Vec2d& vec) const 
{
	return (x != vec.x || y != vec.y);
}
bool Vec2d::operator==(const double& v) const 
{
	return (x == v && y == v);
}
bool Vec2d::operator!=(const double& v) const 
{
	return (x != v || y != v);
}

Vec2d& Vec2d::set(double value)
{
	this->x = (value);
	this->y = (value);
	return *this;
}
Vec2d& Vec2d::set(double _x, double _y)
{
	this->x = (_x);
	this->y = (_y);
	return *this;
}
bool Vec2d::isNan() const
{
	return Double::isNan(x) && Double::isNan(y);
}
bool Vec2d::hasNan() const
{
	return Double::isNan(x) || Double::isNan(y);
}
bool Vec2d::hasNoNan() const
{
	return !Double::isNan(x) && !Double::isNan(y);
}
bool Vec2d::equals(const Vec2d& vec, double epsilon) const 
{
	return (Double::equals(x, vec.x, epsilon) && Double::equals(y, vec.y, epsilon));
}
bool Vec2d::notEquals(const Vec2d& vec, double epsilon) const 
{
	return (!Double::equals(x, vec.x, epsilon) || !Double::equals(y, vec.y, epsilon));
}
bool Vec2d::equals(double _x, double _y, double epsilon) const 
{
	return (Double::equals(x, _x, epsilon) && Double::equals(y, _y, epsilon));
}
bool Vec2d::notEquals(double _x, double _y, double epsilon) const 
{
	return (!Double::equals(x, _x, epsilon) || !Double::equals(y, _y, epsilon));
}

double Vec2d::magn() const
{
	return (std::sqrt(x*x + y*y));
}
Vec2d Vec2d::norm() const
{
	const register double magnitude = std::sqrt(x*x + y*y);
	return Vec2d(x / magnitude, y / magnitude);
}
Vec2d& Vec2d::normalize()
{
	const register double magnitude = std::sqrt(x*x + y*y);
	x = (x / magnitude);
	y = (y / magnitude);
	return *this;
}
double Vec2d::dot(const Vec2d& vec) const
{
	return (x * vec.x + y * vec.y);
}
double Vec2d::cross(const Vec2d& vec) const
{
	return (x * vec.y - y * vec.x);
}
double Vec2d::angle(AxisRule axis_rule) const
{
	switch(axis_rule)
	{
		default:
		case RHS: return std::atan2(y, x);
		case LHS: return std::atan2(x, y);
	}
}
double Vec2d::angle(const Vec2d& ref_vec, AxisRule axis_rule) const
{
	switch(axis_rule)
	{
		default:
		case RHS: return (std::atan2(y, x) - std::atan2(ref_vec.y, ref_vec.x));
		case LHS: return (std::atan2(x, y) - std::atan2(ref_vec.x, ref_vec.y));
	}
}
double Vec2d::fullAngle(AxisRule axis_rule) const
{
	using namespace axl::math::Constants;
	switch(axis_rule)
	{
		default:
		case RHS:
			return std::fmod((_2_PI + std::atan2(y, x)), _2_PI);
		case LHS:
			return std::fmod((_2_PI + std::atan2(x, y)), _2_PI);
	}
}
double Vec2d::fullAngle(const Vec2d& ref_vec, AxisRule axis_rule) const
{
	using namespace axl::math::Constants;
	switch(axis_rule)
	{
		default:
		case RHS: return std::fmod((_2_PI + std::atan2(y, x) - std::atan2(ref_vec.y, ref_vec.x)), _2_PI);
		case LHS: return std::fmod((_2_PI + std::atan2(x, y) - std::atan2(ref_vec.x, ref_vec.y)), _2_PI);
	}
}

Vec2d& Vec2d::scale(double scale_all)
{
	x = (scale_all * x);
	y = (scale_all * y);
	return *this;
}
Vec2d& Vec2d::scale(double scale_x, double scale_y)
{
	x = (scale_x * x);
	y = (scale_y * y);
	return *this;
}
Vec2d Vec2d::scaled(double scale_all) const
{
	return Vec2d(scale_all * x, scale_all * y);
}
Vec2d Vec2d::scaled(double scale_x, double scale_y) const
{
	return Vec2d(scale_x * x, scale_y * y);
}
Vec2d& Vec2d::translate(double delta_x, double delta_y)
{
	x = (x + delta_x);
	y = (y + delta_y);
	return *this;
}
Vec2d& Vec2d::translate(const Vec2d& delta)
{
	x = (x + delta.x);
	y = (y + delta.y);
	return *this;
}
Vec2d Vec2d::translated(double delta_x, double delta_y) const
{
	return Vec2d(x + delta_x, y + delta_y);
}
Vec2d Vec2d::translated(const Vec2d& delta) const
{
	return Vec2d(x + delta.x, y + delta.y);
}

Vec2d& Vec2d::rotate(double theta_z, AxisRule axis_rule)
{
	
	switch (axis_rule)
	{
		default:
		case RHS:
			{
				const register double _x = (x * std::cos(theta_z) - y * std::sin(theta_z));
				const register double _y = (x * std::sin(theta_z) + y * std::cos(theta_z));
				this->x = _x;
				this->y = _y;
			}
			return *this;
		case LHS:
			{
				theta_z = -theta_z;
				const register double _x = (x * std::cos(theta_z) - y * std::sin(theta_z));
				const register double _y = (x * std::sin(theta_z) + y * std::cos(theta_z));
				this->x = _x;
				this->y = _y;
			}
			return *this;
	}
	
}
Vec2d Vec2d::rotated(double theta_z, AxisRule axis_rule) const
{
	switch (axis_rule)
	{
		default:
		case RHS: return Vec2d((x * std::cos(theta_z) - y * std::sin(theta_z)), (x * std::sin(theta_z) + y * std::cos(theta_z)));
		case LHS:
			theta_z = -theta_z;
			return Vec2d((x * std::cos(theta_z) - y * std::sin(theta_z)), (x * std::sin(theta_z) + y * std::cos(theta_z)));
	}
}

const Vec2d Vec2d::Zero(0.0, 0.0);
const Vec2d Vec2d::Identity(1.0, 1.0);
Vec2d Vec2d::Default(0.0, 0.0);
Vec2d::AxisRule Vec2d::DefaultAxisRule = Vec2d::RHS;

} // namespace math
} // namespace axl
