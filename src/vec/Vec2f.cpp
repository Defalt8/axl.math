#include <cmath>
#include <axl.math/constants.hpp>
#include <axl.math/float.hpp>
#include <axl.math/vec/Vec2f.hpp>

namespace axl {
namespace math {

Vec2f::Vec2f(float x, float y) :
	x(x), y(y)
{}
Vec2f::Vec2f(const Vec2f& vec) :
	x(vec.x), y(vec.y)
{}

Vec2f Vec2f::operator+() const
{
	return Vec2f(x, y);
}
Vec2f Vec2f::operator-() const
{
	return Vec2f(-x, -y);
}
Vec2f Vec2f::operator+(const Vec2f& vec) const 
{
	return Vec2f(x + vec.x, y + vec.y);
}
Vec2f Vec2f::operator-(const Vec2f& vec) const 
{
	return Vec2f(x - vec.x, y - vec.y);
}
Vec2f Vec2f::operator*(const Vec2f& vec) const 
{
	return Vec2f(x * vec.x, y * vec.y);
}
Vec2f Vec2f::operator/(const Vec2f& vec) const 
{
	return Vec2f(x / vec.x, y / vec.y);
}
Vec2f Vec2f::operator+(float v) const 
{
	return Vec2f(x + v, y + v);
}
Vec2f Vec2f::operator-(float v) const 
{
	return Vec2f(x - v, y - v);
}
Vec2f Vec2f::operator*(float v) const 
{
	return Vec2f(x * v, y * v);
}
Vec2f Vec2f::operator/(float v) const 
{
	return Vec2f(x / v, y / v);
}
Vec2f& Vec2f::operator+=(const Vec2f& vec) 
{
	x = (x + vec.x); y = (y + vec.y); return *this;
}
Vec2f& Vec2f::operator-=(const Vec2f& vec) 
{
	x = (x - vec.x); y = (y - vec.y); return *this;
}
Vec2f& Vec2f::operator*=(const Vec2f& vec) 
{
	x = (x * vec.x); y = (y * vec.y); return *this;
}
Vec2f& Vec2f::operator/=(const Vec2f& vec) 
{
	x = (x / vec.x); y = (y / vec.y); return *this;
}
Vec2f& Vec2f::operator+=(float v) 
{
	x = x + v; y = y + v; return *this;
}
Vec2f& Vec2f::operator-=(float v) 
{
	x = x - v; y = y - v; return *this;
}
Vec2f& Vec2f::operator*=(float v) 
{
	x = x * v; y = y * v; return *this;
}
Vec2f& Vec2f::operator/=(float v) 
{
	x = x / v; y = y / v; return *this;
}
bool Vec2f::operator==(const Vec2f& vec) const 
{
	return (x == vec.x && y == vec.y);
}
bool Vec2f::operator!=(const Vec2f& vec) const 
{
	return (x != vec.x || y != vec.y);
}
bool Vec2f::operator==(const float& v) const 
{
	return (x == v && y == v);
}
bool Vec2f::operator!=(const float& v) const 
{
	return (x != v || y != v);
}

Vec2f& Vec2f::set(float value)
{
	this->x = (value);
	this->y = (value);
	return *this;
}
Vec2f& Vec2f::set(float _x, float _y)
{
	this->x = (_x);
	this->y = (_y);
	return *this;
}
bool Vec2f::isNan() const
{
	return Float::isNan(x) && Float::isNan(y);
}
bool Vec2f::hasNan() const
{
	return Float::isNan(x) || Float::isNan(y);
}
bool Vec2f::hasNoNan() const
{
	return !Float::isNan(x) && !Float::isNan(y);
}
bool Vec2f::equals(const Vec2f& vec, float epsilon) const 
{
	return (Float::equals(x, vec.x, epsilon) && Float::equals(y, vec.y, epsilon));
}
bool Vec2f::notEquals(const Vec2f& vec, float epsilon) const 
{
	return (!Float::equals(x, vec.x, epsilon) || !Float::equals(y, vec.y, epsilon));
}
bool Vec2f::equals(float _x, float _y, float epsilon) const 
{
	return (Float::equals(x, _x, epsilon) && Float::equals(y, _y, epsilon));
}
bool Vec2f::notEquals(float _x, float _y, float epsilon) const 
{
	return (!Float::equals(x, _x, epsilon) || !Float::equals(y, _y, epsilon));
}

float Vec2f::magn() const
{
	return (std::sqrt(x*x + y*y));
}
Vec2f Vec2f::norm() const
{
	const register float magnitude = std::sqrt(x*x + y*y);
	return Vec2f(x / magnitude, y / magnitude);
}
Vec2f& Vec2f::normalize()
{
	const register float magnitude = std::sqrt(x*x + y*y);
	x = (x / magnitude);
	y = (y / magnitude);
	return *this;
}
float Vec2f::dot(const Vec2f& vec) const
{
	return (x * vec.x + y * vec.y);
}
float Vec2f::cross(const Vec2f& vec) const
{
	return (x * vec.y - y * vec.x);
}
float Vec2f::angle(Rules::Axis axis_rule) const
{
	switch(axis_rule)
	{
		default:
		case Rules::AXIS_RHS: return std::atan2(y, x);
		case Rules::AXIS_LHS: return std::atan2(x, y);
	}
}
float Vec2f::angle(const Vec2f& ref_vec, Rules::Axis axis_rule) const
{
	switch(axis_rule)
	{
		default:
		case Rules::AXIS_RHS: return (std::atan2(y, x) - std::atan2(ref_vec.y, ref_vec.x));
		case Rules::AXIS_LHS: return (std::atan2(x, y) - std::atan2(ref_vec.x, ref_vec.y));
	}
}
float Vec2f::fullAngle(Rules::Axis axis_rule) const
{
	using namespace axl::math::Constants;
	switch(axis_rule)
	{
		default:
		case Rules::AXIS_RHS:
			return std::fmod((F_2_PI + std::atan2(y, x)), F_2_PI);
		case Rules::AXIS_LHS:
			return std::fmod((F_2_PI + std::atan2(x, y)), F_2_PI);
	}
}
float Vec2f::fullAngle(const Vec2f& ref_vec, Rules::Axis axis_rule) const
{
	using namespace axl::math::Constants;
	switch(axis_rule)
	{
		default:
		case Rules::AXIS_RHS: return std::fmod((F_2_PI + std::atan2(y, x) - std::atan2(ref_vec.y, ref_vec.x)), F_2_PI);
		case Rules::AXIS_LHS: return std::fmod((F_2_PI + std::atan2(x, y) - std::atan2(ref_vec.x, ref_vec.y)), F_2_PI);
	}
}

Vec2f& Vec2f::scale(float scale_all)
{
	x = (scale_all * x);
	y = (scale_all * y);
	return *this;
}
Vec2f& Vec2f::scale(float scale_x, float scale_y)
{
	x = (scale_x * x);
	y = (scale_y * y);
	return *this;
}
Vec2f Vec2f::scaled(float scale_all) const
{
	return Vec2f(scale_all * x, scale_all * y);
}
Vec2f Vec2f::scaled(float scale_x, float scale_y) const
{
	return Vec2f(scale_x * x, scale_y * y);
}
Vec2f& Vec2f::translate(float delta_x, float delta_y)
{
	x = (x + delta_x);
	y = (y + delta_y);
	return *this;
}
Vec2f& Vec2f::translate(const Vec2f& delta)
{
	x = (x + delta.x);
	y = (y + delta.y);
	return *this;
}
Vec2f Vec2f::translated(float delta_x, float delta_y) const
{
	return Vec2f(x + delta_x, y + delta_y);
}
Vec2f Vec2f::translated(const Vec2f& delta) const
{
	return Vec2f(x + delta.x, y + delta.y);
}

Vec2f& Vec2f::rotate(float theta_z, Rules::Axis axis_rule)
{
	
	switch (axis_rule)
	{
		default:
		case Rules::AXIS_RHS:
			{
				const register float _x = (x * std::cos(theta_z) - y * std::sin(theta_z));
				const register float _y = (x * std::sin(theta_z) + y * std::cos(theta_z));
				this->x = _x;
				this->y = _y;
			}
			return *this;
		case Rules::AXIS_LHS:
			{
				const register float _x = (x * std::cos(theta_z) + y * std::sin(theta_z));
				const register float _y = (y * std::cos(theta_z) - x * std::sin(theta_z));
				this->x = _x;
				this->y = _y;
			}
			return *this;
	}
	
}
Vec2f Vec2f::rotated(float theta_z, Rules::Axis axis_rule) const
{
	switch (axis_rule)
	{
		default:
		case Rules::AXIS_RHS: return Vec2f((x * std::cos(theta_z) - y * std::sin(theta_z)), (x * std::sin(theta_z) + y * std::cos(theta_z)));
		case Rules::AXIS_LHS:
			theta_z = -theta_z;
			return Vec2f((x * std::cos(theta_z) + y * std::sin(theta_z)), (y * std::cos(theta_z) - x * std::sin(theta_z)));
	}
}

Vec2f operator+(float v, const Vec2f& vec)
{
	return Vec2f(v + vec.x, v + vec.y);
}

Vec2f operator-(float v, const Vec2f& vec)
{
	return Vec2f(v - vec.x, v - vec.y);
}

Vec2f operator*(float v, const Vec2f& vec)
{
	return Vec2f(v * vec.x, v * vec.y);
}

Vec2f operator/(float v, const Vec2f& vec)
{
	return Vec2f(v / vec.x, v / vec.y);
}

Vec2f Vec2f::filled(float v) { return Vec2f(v, v); }
const Vec2f Vec2f::Zero(0.0f, 0.0f);
const Vec2f Vec2f::Identity(1.0f, 1.0f);
Vec2f Vec2f::Default(0.0f, 0.0f);
Rules::Axis Vec2f::DefaultAxisRule = Rules::AXIS_RHS;

} // namespace axl.math
} // namespace axl
