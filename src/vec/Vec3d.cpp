#include <cmath>
#include <axl.math/rules.hpp>
#include <axl.math/double.hpp>
#include <axl.math/vec/Vec3d.hpp>
#include <axl.math/vec/Vec2d.hpp>

namespace axl {
namespace math {

Vec3d::Vec3d(double _x, double _y, double _z) :
	x(_x), y(_y), z(_z)
{}
Vec3d::Vec3d(const Vec3d& vec) :
	x(vec.x), y(vec.y), z(vec.z)
{}
Vec3d::Vec3d(const Vec2d& vec, double _z) :
	x(vec.x), y(vec.y), z(_z)
{}

Vec3d Vec3d::operator+() const
{
	return Vec3d(x, y, z);
}
Vec3d Vec3d::operator-() const
{
	return Vec3d(-x, -y, -z);
}
Vec3d Vec3d::operator+(const Vec3d& vec) const 
{
	return Vec3d(x + vec.x, y + vec.y, z + vec.z);
}
Vec3d Vec3d::operator-(const Vec3d& vec) const 
{
	return Vec3d(x - vec.x, y - vec.y, z - vec.z);
}
Vec3d Vec3d::operator*(const Vec3d& vec) const 
{
	return Vec3d(x * vec.x, y * vec.y, z * vec.z);
}
Vec3d Vec3d::operator/(const Vec3d& vec) const 
{
	return Vec3d(x / vec.x, y / vec.y, z / vec.z);
}
Vec3d Vec3d::operator+(double v) const 
{
	return Vec3d(x + v, y + v, z + v);
}
Vec3d Vec3d::operator-(double v) const 
{
	return Vec3d(x - v, y - v, z - v);
}
Vec3d Vec3d::operator*(double v) const 
{
	return Vec3d(x * v, y * v, z * v);
}
Vec3d Vec3d::operator/(double v) const 
{
	return Vec3d(x / v, y / v, z / v);
}
Vec3d& Vec3d::operator+=(const Vec3d& vec) 
{
	x = (x + vec.x); y = (y + vec.y); z = (z + vec.z); return *this;
}
Vec3d& Vec3d::operator-=(const Vec3d& vec) 
{
	x = (x - vec.x); y = (y - vec.y); z = (z - vec.z); return *this;
}
Vec3d& Vec3d::operator*=(const Vec3d& vec) 
{
	x = (x * vec.x); y = (y * vec.y); z = (z * vec.z); return *this;
}
Vec3d& Vec3d::operator/=(const Vec3d& vec) 
{
	x = (x / vec.x); y = (y / vec.y); z = (z / vec.z); return *this;
}
Vec3d& Vec3d::operator+=(double v) 
{
	x = (x + v); y = (y + v); z = (z + v); return *this;
}
Vec3d& Vec3d::operator-=(double v) 
{
	x = (x - v); y = (y - v); z = (z - v); return *this;
}
Vec3d& Vec3d::operator*=(double v) 
{
	x = (x * v); y = (y * v); z = (z * v); return *this;
}
Vec3d& Vec3d::operator/=(double v) 
{
	x = (x / v); y = (y / v); z = (z / v); return *this;
}
bool Vec3d::operator==(const Vec3d& vec) const 
{
	return (x == vec.x && y == vec.y && z == vec.z);
}
bool Vec3d::operator!=(const Vec3d& vec) const 
{
	return (x != vec.x || y != vec.y || z != vec.z);
}
bool Vec3d::operator==(const double& v) const 
{
	return (x == v && y == v && z == v);
}
bool Vec3d::operator!=(const double& v) const 
{
	return (x != v || y != v || z != v);
}

Vec3d& Vec3d::set(double value) 
{
	this->x = (value); this->y = (value); this->z = (value); return *this;
}
Vec3d& Vec3d::set(double _x, double _y) 
{
	this->x = (_x); this->y = (_y); return *this;
}
Vec3d& Vec3d::set(double _x, double _y, double _z) 
{
	this->x = (_x); this->y = (_y); this->z = (_z); return *this;
}
bool Vec3d::isNan() const
{
	return Double::isNan(x) && Double::isNan(y) && Double::isNan(z);
}
bool Vec3d::hasNan() const
{
	return Double::isNan(x) || Double::isNan(y) || Double::isNan(z);
}
bool Vec3d::hasNoNan() const
{
	return !Double::isNan(x) && !Double::isNan(y) && !Double::isNan(z);
}
bool Vec3d::equals(const Vec3d& vec, double epsilon) const 
{
	return (Double::equals(x, vec.x, epsilon) && Double::equals(y, vec.y, epsilon) && Double::equals(z, vec.z, epsilon));
}
bool Vec3d::notEquals(const Vec3d& vec, double epsilon) const 
{
	return (!Double::equals(x, vec.x, epsilon) || !Double::equals(y, vec.y, epsilon) || !Double::equals(z, vec.z, epsilon));
}
bool Vec3d::equals(double _x, double _y, double _z, double epsilon) const 
{
	return (Double::equals(x, _x, epsilon) && Double::equals(y, _y, epsilon) && Double::equals(z, _z, epsilon));
}
bool Vec3d::notEquals(double _x, double _y, double _z, double epsilon) const 
{
	return (!Double::equals(x, _x, epsilon) || !Double::equals(y, _y, epsilon) || !Double::equals(z, _z, epsilon));
}

double Vec3d::magn() const
{
	return (std::sqrt(x * x + y * y + z * z));
}
Vec3d Vec3d::norm() const
{
	const register double magnitude = std::sqrt(x * x + y * y + z * z);
	return Vec3d(x / magnitude, y / magnitude, z / magnitude);
}
Vec3d& Vec3d::normalize()
{
	const register double magnitude = std::sqrt(x * x + y * y + z * z);
	x = (x / magnitude);
	y = (y / magnitude);
	z = (z / magnitude);
	return *this;
}
double Vec3d::dot(const Vec3d& vec) const
{
	return (x * vec.x + y * vec.y + z * vec.z);
}
Vec3d Vec3d::cross(const Vec3d& vec, Rules::Axis axis_rule) const
{
	switch (axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: return Vec3d((y * vec.z - z * vec.y), (z * vec.x - x * vec.z), (x * vec.y - y * vec.x));
		case Rules::Axis::AXIS_LHS: return Vec3d((z * vec.y - y * vec.z), (x * vec.z - z * vec.x), (y * vec.x - x * vec.y));
	}
}
Vec3d Vec3d::euler(Rules::Axis axis_rule) const
{
	switch (axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: return Vec3d(std::atan2(z, y), std::atan2(x, z), std::atan2(y, x));
		case Rules::Axis::AXIS_LHS: return Vec3d(std::atan2(y, z), std::atan2(z, x), std::atan2(x, y));
	}
}
Vec3d Vec3d::euler(const Vec3d& ref_vec, Rules::Axis axis_rule) const
{
	switch (axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: return Vec3d(std::atan2(z, y) - std::atan2(ref_vec.z, ref_vec.y), std::atan2(x, z) - std::atan2(ref_vec.x, ref_vec.z), std::atan2(y, x) - std::atan2(ref_vec.y, ref_vec.x));
		case Rules::Axis::AXIS_LHS: return Vec3d(std::atan2(y, z) - std::atan2(ref_vec.y, ref_vec.z), std::atan2(z, x) - std::atan2(ref_vec.z, ref_vec.x), std::atan2(x, y) - std::atan2(ref_vec.x, ref_vec.y));
	}
}

Vec3d& Vec3d::scale(double scale_all)
{
	x = (scale_all * x);
	y = (scale_all * y);
	z = (scale_all * z);
	return *this;
}
Vec3d& Vec3d::scale(double scale_x, double scale_y, double scale_z)
{
	x = (scale_x * x);
	y = (scale_y * y);
	z = (scale_z * z);
	return *this;
}
Vec3d Vec3d::scaled(double scale_all) const
{
	return Vec3d(scale_all * x, scale_all * y, scale_all * z);
}
Vec3d Vec3d::scaled(double scale_x, double scale_y, double scale_z) const
{
	return Vec3d(scale_x * x, scale_y * y, scale_z * z);
}
Vec3d& Vec3d::translate(double delta_x, double delta_y, double delta_z)
{
	x = (x + delta_x);
	y = (y + delta_y);
	z = (z + delta_z);
	return *this;
}
Vec3d& Vec3d::translate(const Vec3d& delta)
{
	x = (x + delta.x);
	y = (y + delta.y);
	z = (z + delta.z);
	return *this;
}
Vec3d Vec3d::translated(double delta_x, double delta_y, double delta_z) const
{
	return Vec3d(x + delta_x, y + delta_y, z + delta_z);
}
Vec3d Vec3d::translated(const Vec3d& delta) const
{
	return Vec3d(x + delta.x, y + delta.y, z + delta.z);
}
Vec3d& Vec3d::rotate(double angle_x, double angle_y, double angle_z, Rules::Axis axis_rule)
{
	double _x, _y, _z;
	switch(axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS:
			_x = (std::cos(angle_y) * std::cos(angle_z) * x - std::sin(angle_z) * y + std::sin(angle_y) * z);
			_y = (std::sin(angle_z) * x + std::cos(angle_x) * std::cos(angle_z) * y - std::sin(angle_x) * z);
			_z = (-std::sin(angle_y) * x + std::sin(angle_x) * y + std::cos(angle_x) * std::cos(angle_y) * z);
			break;
		case Rules::Axis::AXIS_LHS:
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
Vec3d& Vec3d::rotate(const Vec3d& angle_vec, Rules::Axis axis_rule)
{
	double _x, _y, _z;
	switch(axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS:
			_x = (std::cos(angle_vec.y) * std::cos(angle_vec.z) * x - std::sin(angle_vec.z) * y + std::sin(angle_vec.y) * z);
			_y = (std::sin(angle_vec.z) * x + std::cos(angle_vec.x) * std::cos(angle_vec.z) * y - std::sin(angle_vec.x) * z);
			_z = (-std::sin(angle_vec.y) * x + std::sin(angle_vec.x) * y + std::cos(angle_vec.x) * std::cos(angle_vec.y) * z);
			break;
		case Rules::Axis::AXIS_LHS:
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
Vec3d& Vec3d::rotateX(double angle_x, Rules::Axis axis_rule)
{
	double _y, _z;
	switch(axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS:
			_y = (std::cos(angle_x) * y - std::sin(angle_x) * z);
			_z = (std::sin(angle_x) * y + std::cos(angle_x) * z);
			break;
		case Rules::Axis::AXIS_LHS:
			_y = (std::cos(angle_x) * y + std::sin(angle_x) * z);
			_z = (-std::sin(angle_x) * y + std::cos(angle_x) * z);
			break;
	}
	y = _y;
	z = _z;
	return *this;
}
Vec3d& Vec3d::rotateY(double angle_y, Rules::Axis axis_rule)
{
	double _x, _z;
	switch(axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS:
			_x = (std::cos(angle_y) * x + std::sin(angle_y) * z);
			_z = (-std::sin(angle_y) * x + std::cos(angle_y) * z);
			break;
		case Rules::Axis::AXIS_LHS:
			_x = (std::cos(angle_y) * x - std::sin(angle_y) * z);
			_z = (std::sin(angle_y) * x + std::cos(angle_y) * z);
			break;
	}
	x = _x;
	z = _z;
	return *this;
}
Vec3d& Vec3d::rotateZ(double angle_z, Rules::Axis axis_rule)
{
	double _x, _y;
	switch(axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS:
			_x = (std::cos(angle_z) * x - std::sin(angle_z) * y);
			_y = (std::sin(angle_z) * x + std::cos(angle_z) * y);
			break;
		case Rules::Axis::AXIS_LHS:
			_x = (std::cos(angle_z) * x + std::sin(angle_z) * y);
			_y = (-std::sin(angle_z) * x + std::cos(angle_z) * y);
			break;
	}
	x = _x;
	y = _y;
	return *this;
}
Vec3d Vec3d::rotated(double angle_x, double angle_y, double angle_z, Rules::Axis axis_rule) const
{
	switch(axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS:
			return Vec3d(
				(std::cos(angle_y) * std::cos(angle_z) * x - std::sin(angle_z) * y + std::sin(angle_y) * z),
				(std::sin(angle_z) * x + std::cos(angle_x) * std::cos(angle_z) * y - std::sin(angle_x) * z),
				(-std::sin(angle_y) * x + std::sin(angle_x) * y + std::cos(angle_x) * std::cos(angle_y) * z)
				);
		case Rules::Axis::AXIS_LHS:
			return Vec3d(
				(std::cos(angle_y) * std::cos(angle_z) * x + std::sin(angle_z) * y - std::sin(angle_y) * z),
				(-std::sin(angle_z) * x + std::cos(angle_x) * std::cos(angle_z) * y + std::sin(angle_x) * z),
				(std::sin(angle_y) * x - std::sin(angle_x) * y + std::cos(angle_x) * std::cos(angle_y) * z)
			);
	}
}
Vec3d Vec3d::rotated(const Vec3d& angle_vec, Rules::Axis axis_rule) const
{
	switch(axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS:
			return Vec3d(
				(std::cos(angle_vec.y) * std::cos(angle_vec.z) * x - std::sin(angle_vec.z) * y + std::sin(angle_vec.y) * z),
				(std::sin(angle_vec.z) * x + std::cos(angle_vec.x) * std::cos(angle_vec.z) * y - std::sin(angle_vec.x) * z),
				(-std::sin(angle_vec.y) * x + std::sin(angle_vec.x) * y + std::cos(angle_vec.x) * std::cos(angle_vec.y) * z)
				);
		case Rules::Axis::AXIS_LHS:
			return Vec3d(
				(std::cos(angle_vec.y) * std::cos(angle_vec.z) * x + std::sin(angle_vec.z) * y - std::sin(angle_vec.y) * z),
				(-std::sin(angle_vec.z) * x + std::cos(angle_vec.x) * std::cos(angle_vec.z) * y + std::sin(angle_vec.x) * z),
				(std::sin(angle_vec.y) * x - std::sin(angle_vec.x) * y + std::cos(angle_vec.x) * std::cos(angle_vec.y) * z)
			);
	}
}

Vec3d Vec3d::rotatedX(double angle_x, Rules::Axis axis_rule)
{
	switch(axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS:
			return Vec3d(x, (std::cos(angle_x) * y - std::sin(angle_x) * z), (std::sin(angle_x) * y + std::cos(angle_x) * z));
		case Rules::Axis::AXIS_LHS:
			return Vec3d(x, (std::cos(angle_x) * y + std::sin(angle_x) * z), (-std::sin(angle_x) * y + std::cos(angle_x) * z));
	}
}
Vec3d Vec3d::rotatedY(double angle_y, Rules::Axis axis_rule)
{
	switch(axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS:
			return Vec3d((std::cos(angle_y) * x + std::sin(angle_y) * z), y, (-std::sin(angle_y) * x + std::cos(angle_y) * z));
		case Rules::Axis::AXIS_LHS:
			return Vec3d((std::cos(angle_y) * x - std::sin(angle_y) * z), y, (std::sin(angle_y) * x + std::cos(angle_y) * z));
	}
}
Vec3d Vec3d::rotatedZ(double angle_z, Rules::Axis axis_rule)
{
	switch(axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS:
			return Vec3d((std::cos(angle_z) * x - std::sin(angle_z) * y), (std::sin(angle_z) * x + std::cos(angle_z) * y), z);
		case Rules::Axis::AXIS_LHS:
			return Vec3d((std::cos(angle_z) * x + std::sin(angle_z) * y), (-std::sin(angle_z) * x + std::cos(angle_z) * y), z);
	}
}

Vec3d operator+(double v, const Vec3d& vec)
{
	return Vec3d(v + vec.x, v + vec.y, v + vec.z);
}

Vec3d operator-(double v, const Vec3d& vec)
{
	return Vec3d(v - vec.x, v - vec.y, v - vec.z);
}

Vec3d operator*(double v, const Vec3d& vec)
{
	return Vec3d(v * vec.x, v * vec.y, v * vec.z);
}

Vec3d operator/(double v, const Vec3d& vec)
{
	return Vec3d(v / vec.x, v / vec.y, v / vec.z);
}

Vec3d Vec3d::filled(double v) { return Vec3d(v, v, v); }
const Vec3d Vec3d::Zero(0.0, 0.0, 0.0);
const Vec3d Vec3d::Identity(1.0, 1.0, 1.0);
Vec3d Vec3d::Default(0.0, 0.0, 0.0);
Rules::Axis Vec3d::DefaultAxisRule = Rules::Axis::AXIS_RHS;

} // namespace axl.math
} // namespace axl
