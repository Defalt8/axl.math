#include <cmath>
#include <axl.math/rules.hpp>
#include <axl.math/float.hpp>
#include <axl.math/Vec3f.hpp>
#include <axl.math/Vec2f.hpp>

namespace axl {
namespace math {

Vec3f::Vec3f(float _x, float _y, float _z) :
	x(_x), y(_y), z(_z)
{}
Vec3f::Vec3f(const Vec3f& vec) :
	x(vec.x), y(vec.y), z(vec.z)
{}
Vec3f::Vec3f(const Vec2f& vec, float _z) :
	x(vec.x), y(vec.y), z(_z)
{}

Vec3f Vec3f::operator+() const
{
	return Vec3f(x, y, z);
}
Vec3f Vec3f::operator-() const
{
	return Vec3f(-x, -y, -z);
}
Vec3f Vec3f::operator+(const Vec3f& vec) const 
{
	return Vec3f(x + vec.x, y + vec.y, z + vec.z);
}
Vec3f Vec3f::operator-(const Vec3f& vec) const 
{
	return Vec3f(x - vec.x, y - vec.y, z - vec.z);
}
Vec3f Vec3f::operator*(const Vec3f& vec) const 
{
	return Vec3f(x * vec.x, y * vec.y, z * vec.z);
}
Vec3f Vec3f::operator/(const Vec3f& vec) const 
{
	return Vec3f(x / vec.x, y / vec.y, z / vec.z);
}
Vec3f Vec3f::operator+(float v) const 
{
	return Vec3f(x + v, y + v, z + v);
}
Vec3f Vec3f::operator-(float v) const 
{
	return Vec3f(x - v, y - v, z - v);
}
Vec3f Vec3f::operator*(float v) const 
{
	return Vec3f(x * v, y * v, z * v);
}
Vec3f Vec3f::operator/(float v) const 
{
	return Vec3f(x / v, y / v, z / v);
}
Vec3f& Vec3f::operator+=(const Vec3f& vec) 
{
	x = (x + vec.x); y = (y + vec.y); z = (z + vec.z); return *this;
}
Vec3f& Vec3f::operator-=(const Vec3f& vec) 
{
	x = (x - vec.x); y = (y - vec.y); z = (z - vec.z); return *this;
}
Vec3f& Vec3f::operator*=(const Vec3f& vec) 
{
	x = (x * vec.x); y = (y * vec.y); z = (z * vec.z); return *this;
}
Vec3f& Vec3f::operator/=(const Vec3f& vec) 
{
	x = (x / vec.x); y = (y / vec.y); z = (z / vec.z); return *this;
}
Vec3f& Vec3f::operator+=(float v) 
{
	x = (x + v); y = (y + v); z = (z + v); return *this;
}
Vec3f& Vec3f::operator-=(float v) 
{
	x = (x - v); y = (y - v); z = (z - v); return *this;
}
Vec3f& Vec3f::operator*=(float v) 
{
	x = (x * v); y = (y * v); z = (z * v); return *this;
}
Vec3f& Vec3f::operator/=(float v) 
{
	x = (x / v); y = (y / v); z = (z / v); return *this;
}
bool Vec3f::operator==(const Vec3f& vec) const 
{
	return (x == vec.x && y == vec.y && z == vec.z);
}
bool Vec3f::operator!=(const Vec3f& vec) const 
{
	return (x != vec.x || y != vec.y || z != vec.z);
}
bool Vec3f::operator==(const float& v) const 
{
	return (x == v && y == v && z == v);
}
bool Vec3f::operator!=(const float& v) const 
{
	return (x != v || y != v || z != v);
}

Vec3f& Vec3f::set(float value) 
{
	this->x = (value); this->y = (value); this->z = (value); return *this;
}
Vec3f& Vec3f::set(float _x, float _y) 
{
	this->x = (_x); this->y = (_y); return *this;
}
Vec3f& Vec3f::set(float _x, float _y, float _z) 
{
	this->x = (_x); this->y = (_y); this->z = (_z); return *this;
}
bool Vec3f::isNan() const
{
	return Float::isNan(x) && Float::isNan(y) && Float::isNan(z);
}
bool Vec3f::hasNan() const
{
	return Float::isNan(x) || Float::isNan(y) || Float::isNan(z);
}
bool Vec3f::hasNoNan() const
{
	return !Float::isNan(x) && !Float::isNan(y) && !Float::isNan(z);
}
bool Vec3f::equals(const Vec3f& vec, float epsilon) const 
{
	return (Float::equals(x, vec.x, epsilon) && Float::equals(y, vec.y, epsilon) && Float::equals(z, vec.z, epsilon));
}
bool Vec3f::notEquals(const Vec3f& vec, float epsilon) const 
{
	return (!Float::equals(x, vec.x, epsilon) || !Float::equals(y, vec.y, epsilon) || !Float::equals(z, vec.z, epsilon));
}
bool Vec3f::equals(float _x, float _y, float _z, float epsilon) const 
{
	return (Float::equals(x, _x, epsilon) && Float::equals(y, _y, epsilon) && Float::equals(z, _z, epsilon));
}
bool Vec3f::notEquals(float _x, float _y, float _z, float epsilon) const 
{
	return (!Float::equals(x, _x, epsilon) || !Float::equals(y, _y, epsilon) || !Float::equals(z, _z, epsilon));
}

float Vec3f::magn() const
{
	return (std::sqrt(x * x + y * y + z * z));
}
Vec3f Vec3f::norm() const
{
	const register float magnitude = std::sqrt(x * x + y * y + z * z);
	return Vec3f(x / magnitude, y / magnitude, z / magnitude);
}
Vec3f& Vec3f::normalize()
{
	const register float magnitude = std::sqrt(x * x + y * y + z * z);
	x = (x / magnitude);
	y = (y / magnitude);
	z = (z / magnitude);
	return *this;
}
float Vec3f::dot(const Vec3f& vec) const
{
	return (x * vec.x + y * vec.y + z * vec.z);
}
Vec3f Vec3f::cross(const Vec3f& vec, Rules::Axis axis_rule) const
{
	switch (axis_rule)
	{
		default:
		case Rules::AXIS_RHS: return Vec3f((y * vec.z - z * vec.y), (z * vec.x - x * vec.z), (x * vec.y - y * vec.x));
		case Rules::AXIS_LHS: return Vec3f((z * vec.y - y * vec.z), (x * vec.z - z * vec.x), (y * vec.x - x * vec.y));
	}
}
Vec3f Vec3f::euler(Rules::Axis axis_rule) const
{
	switch (axis_rule)
	{
		default:
		case Rules::AXIS_RHS: return Vec3f(std::atan2(z, y), std::atan2(x, z), std::atan2(y, x));
		case Rules::AXIS_LHS: return Vec3f(std::atan2(y, z), std::atan2(z, x), std::atan2(x, y));
	}
}
Vec3f Vec3f::euler(const Vec3f& ref_vec, Rules::Axis axis_rule) const
{
	switch (axis_rule)
	{
		default:
		case Rules::AXIS_RHS: return Vec3f(std::atan2(z, y) - std::atan2(ref_vec.z, ref_vec.y), std::atan2(x, z) - std::atan2(ref_vec.x, ref_vec.z), std::atan2(y, x) - std::atan2(ref_vec.y, ref_vec.x));
		case Rules::AXIS_LHS: return Vec3f(std::atan2(y, z) - std::atan2(ref_vec.y, ref_vec.z), std::atan2(z, x) - std::atan2(ref_vec.z, ref_vec.x), std::atan2(x, y) - std::atan2(ref_vec.x, ref_vec.y));
	}
}

Vec3f& Vec3f::scale(float scale_all)
{
	x = (scale_all * x);
	y = (scale_all * y);
	z = (scale_all * z);
	return *this;
}
Vec3f& Vec3f::scale(float scale_x, float scale_y, float scale_z)
{
	x = (scale_x * x);
	y = (scale_y * y);
	z = (scale_z * z);
	return *this;
}
Vec3f Vec3f::scaled(float scale_all) const
{
	return Vec3f(scale_all * x, scale_all * y, scale_all * z);
}
Vec3f Vec3f::scaled(float scale_x, float scale_y, float scale_z) const
{
	return Vec3f(scale_x * x, scale_y * y, scale_z * z);
}
Vec3f& Vec3f::translate(float delta_x, float delta_y, float delta_z)
{
	x = (x + delta_x);
	y = (y + delta_y);
	z = (z + delta_z);
	return *this;
}
Vec3f& Vec3f::translate(const Vec3f& delta)
{
	x = (x + delta.x);
	y = (y + delta.y);
	z = (z + delta.z);
	return *this;
}
Vec3f Vec3f::translated(float delta_x, float delta_y, float delta_z) const
{
	return Vec3f(x + delta_x, y + delta_y, z + delta_z);
}
Vec3f Vec3f::translated(const Vec3f& delta) const
{
	return Vec3f(x + delta.x, y + delta.y, z + delta.z);
}
Vec3f& Vec3f::rotate(float angle_x, float angle_y, float angle_z, Rules::Axis axis_rule)
{
	float _x, _y, _z;
	switch(axis_rule)
	{
		default:
		case Rules::AXIS_RHS:
			_x = (std::cos(angle_y) * std::cos(angle_z) * x - std::sin(angle_z) * y + std::sin(angle_y) * z);
			_y = (std::sin(angle_z) * x + std::cos(angle_x) * std::cos(angle_z) * y - std::sin(angle_x) * z);
			_z = (-std::sin(angle_y) * x + std::sin(angle_x) * y + std::cos(angle_x) * std::cos(angle_y) * z);
			break;
		case Rules::AXIS_LHS:
			_x = (std::cos(angle_y) * std::cos(angle_z) * x + std::sin(angle_z) * y - std::sin(angle_y) * z);
			_y = (-std::sin(angle_z) * x + std::cos(angle_x) * std::cos(angle_z) * y + std::sin(angle_x) * z);
			_z = (std::sin(angle_y) * x - std::sin(angle_x) * y + std::cos(angle_x) * std::cos(angle_y) * z);
			break;
	}
	x = _x;
	y = _y;
	z = _z;
	return *this;
}
Vec3f& Vec3f::rotate(const Vec3f& angle_vec, Rules::Axis axis_rule)
{
	float _x, _y, _z;
	switch(axis_rule)
	{
		default:
		case Rules::AXIS_RHS:
			_x = (std::cos(angle_vec.y) * std::cos(angle_vec.z) * x - std::sin(angle_vec.z) * y + std::sin(angle_vec.y) * z);
			_y = (std::sin(angle_vec.z) * x + std::cos(angle_vec.x) * std::cos(angle_vec.z) * y - std::sin(angle_vec.x) * z);
			_z = (-std::sin(angle_vec.y) * x + std::sin(angle_vec.x) * y + std::cos(angle_vec.x) * std::cos(angle_vec.y) * z);
			break;
		case Rules::AXIS_LHS:
			_x = (std::cos(angle_vec.y) * std::cos(angle_vec.z) * x + std::sin(angle_vec.z) * y - std::sin(angle_vec.y) * z);
			_y = (-std::sin(angle_vec.z) * x + std::cos(angle_vec.x) * std::cos(angle_vec.z) * y + std::sin(angle_vec.x) * z);
			_z = (std::sin(angle_vec.y) * x - std::sin(angle_vec.x) * y + std::cos(angle_vec.x) * std::cos(angle_vec.y) * z);
			break;
	}
	x = _x;
	y = _y;
	z = _z;
	return *this;
}
Vec3f& Vec3f::rotateX(float angle_x, Rules::Axis axis_rule)
{
	float _y, _z;
	switch(axis_rule)
	{
		default:
		case Rules::AXIS_RHS:
			_y = (std::cos(angle_x) * y - std::sin(angle_x) * z);
			_z = (std::sin(angle_x) * y + std::cos(angle_x) * z);
			break;
		case Rules::AXIS_LHS:
			_y = (std::cos(angle_x) * y + std::sin(angle_x) * z);
			_z = (-std::sin(angle_x) * y + std::cos(angle_x) * z);
			break;
	}
	y = _y;
	z = _z;
	return *this;
}
Vec3f& Vec3f::rotateY(float angle_y, Rules::Axis axis_rule)
{
	float _x, _z;
	switch(axis_rule)
	{
		default:
		case Rules::AXIS_RHS:
			_x = (std::cos(angle_y) * x + std::sin(angle_y) * z);
			_z = (-std::sin(angle_y) * x + std::cos(angle_y) * z);
			break;
		case Rules::AXIS_LHS:
			_x = (std::cos(angle_y) * x - std::sin(angle_y) * z);
			_z = (std::sin(angle_y) * x + std::cos(angle_y) * z);
			break;
	}
	x = _x;
	z = _z;
	return *this;
}
Vec3f& Vec3f::rotateZ(float angle_z, Rules::Axis axis_rule)
{
	float _x, _y;
	switch(axis_rule)
	{
		default:
		case Rules::AXIS_RHS:
			_x = (std::cos(angle_z) * x - std::sin(angle_z) * y);
			_y = (std::sin(angle_z) * x + std::cos(angle_z) * y);
			break;
		case Rules::AXIS_LHS:
			_x = (std::cos(angle_z) * x + std::sin(angle_z) * y);
			_y = (-std::sin(angle_z) * x + std::cos(angle_z) * y);
			break;
	}
	x = _x;
	y = _y;
	return *this;
}
Vec3f Vec3f::rotated(float angle_x, float angle_y, float angle_z, Rules::Axis axis_rule) const
{
	switch(axis_rule)
	{
		default:
		case Rules::AXIS_RHS:
			return Vec3f(
				(std::cos(angle_y) * std::cos(angle_z) * x - std::sin(angle_z) * y + std::sin(angle_y) * z),
				(std::sin(angle_z) * x + std::cos(angle_x) * std::cos(angle_z) * y - std::sin(angle_x) * z),
				(-std::sin(angle_y) * x + std::sin(angle_x) * y + std::cos(angle_x) * std::cos(angle_y) * z)
				);
		case Rules::AXIS_LHS:
			return Vec3f(
				(std::cos(angle_y) * std::cos(angle_z) * x + std::sin(angle_z) * y - std::sin(angle_y) * z),
				(-std::sin(angle_z) * x + std::cos(angle_x) * std::cos(angle_z) * y + std::sin(angle_x) * z),
				(std::sin(angle_y) * x - std::sin(angle_x) * y + std::cos(angle_x) * std::cos(angle_y) * z)
			);
	}
}
Vec3f Vec3f::rotated(const Vec3f& angle_vec, Rules::Axis axis_rule) const
{
	switch(axis_rule)
	{
		default:
		case Rules::AXIS_RHS:
			return Vec3f(
				(std::cos(angle_vec.y) * std::cos(angle_vec.z) * x - std::sin(angle_vec.z) * y + std::sin(angle_vec.y) * z),
				(std::sin(angle_vec.z) * x + std::cos(angle_vec.x) * std::cos(angle_vec.z) * y - std::sin(angle_vec.x) * z),
				(-std::sin(angle_vec.y) * x + std::sin(angle_vec.x) * y + std::cos(angle_vec.x) * std::cos(angle_vec.y) * z)
				);
		case Rules::AXIS_LHS:
			return Vec3f(
				(std::cos(angle_vec.y) * std::cos(angle_vec.z) * x + std::sin(angle_vec.z) * y - std::sin(angle_vec.y) * z),
				(-std::sin(angle_vec.z) * x + std::cos(angle_vec.x) * std::cos(angle_vec.z) * y + std::sin(angle_vec.x) * z),
				(std::sin(angle_vec.y) * x - std::sin(angle_vec.x) * y + std::cos(angle_vec.x) * std::cos(angle_vec.y) * z)
			);
	}
}

Vec3f Vec3f::rotatedX(float angle_x, Rules::Axis axis_rule)
{
	switch(axis_rule)
	{
		default:
		case Rules::AXIS_RHS:
			return Vec3f(x, (std::cos(angle_x) * y - std::sin(angle_x) * z), (std::sin(angle_x) * y + std::cos(angle_x) * z));
		case Rules::AXIS_LHS:
			return Vec3f(x, (std::cos(angle_x) * y + std::sin(angle_x) * z), (-std::sin(angle_x) * y + std::cos(angle_x) * z));
	}
}
Vec3f Vec3f::rotatedY(float angle_y, Rules::Axis axis_rule)
{
	switch(axis_rule)
	{
		default:
		case Rules::AXIS_RHS:
			return Vec3f((std::cos(angle_y) * x + std::sin(angle_y) * z), y, (-std::sin(angle_y) * x + std::cos(angle_y) * z));
		case Rules::AXIS_LHS:
			return Vec3f((std::cos(angle_y) * x - std::sin(angle_y) * z), y, (std::sin(angle_y) * x + std::cos(angle_y) * z));
	}
}
Vec3f Vec3f::rotatedZ(float angle_z, Rules::Axis axis_rule)
{
	switch(axis_rule)
	{
		default:
		case Rules::AXIS_RHS:
			return Vec3f((std::cos(angle_z) * x - std::sin(angle_z) * y), (std::sin(angle_z) * x + std::cos(angle_z) * y), z);
		case Rules::AXIS_LHS:
			return Vec3f((std::cos(angle_z) * x + std::sin(angle_z) * y), (-std::sin(angle_z) * x + std::cos(angle_z) * y), z);
	}
}
const Vec3f Vec3f::Zero(0.0f, 0.0f, 0.0f);
const Vec3f Vec3f::Identity(1.0f, 1.0f, 1.0f);
Vec3f Vec3f::Default(0.0f, 0.0f, 0.0f);
Rules::Axis Vec3f::DefaultAxisRule = Rules::AXIS_RHS;

} // namespace math
} // namespace axl
