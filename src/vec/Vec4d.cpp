#include <cmath>
#include <axl.math/double.hpp>
#include <axl.math/vec/Vec4d.hpp>

namespace axl {
namespace math {

Vec4d::Vec4d(double _x, double _y, double _z, double _w) :
	x(_x), y(_y), z(_z), w(_w)
{}

Vec4d::Vec4d(const Vec4d& vec) :
	x(vec.x), y(vec.y), z(vec.z), w(vec.w)
{}

Vec4d::Vec4d(const Vec2d& vec, double _z, double _w) :
	x(vec.x), y(vec.y), z(_z), w(_w)
{}

Vec4d::Vec4d(const Vec3d& vec, double _w) :
	x(vec.x), y(vec.y), z(vec.z), w(_w)
{}

Vec4d Vec4d::operator+() const
{
	return Vec4d(x, y, z, w);
}

Vec4d Vec4d::operator-() const
{
	return Vec4d(-x, -y, -z, -w);
}

Vec4d Vec4d::operator+(const Vec4d& vec) const 
{
	return Vec4d(x + vec.x, y + vec.y, z + vec.z, w + vec.w);
}

Vec4d Vec4d::operator-(const Vec4d& vec) const 
{
	return Vec4d(x - vec.x, y - vec.y, z - vec.z, w - vec.w);
}

Vec4d Vec4d::operator*(const Vec4d& vec) const 
{
	return Vec4d(x * vec.x, y * vec.y, z * vec.z, w * vec.w);
}

Vec4d Vec4d::operator/(const Vec4d& vec) const 
{
	return Vec4d(x / vec.x, y / vec.y, z / vec.z, w / vec.w);
}

Vec4d Vec4d::operator+(double v) const 
{
	return Vec4d(x + v, y + v, z + v, w + v);
}

Vec4d Vec4d::operator-(double v) const 
{
	return Vec4d(x - v, y - v, z - v, w - v);
}

Vec4d Vec4d::operator*(double v) const 
{
	return Vec4d(x * v, y * v, z * v, w * v);
}

Vec4d Vec4d::operator/(double v) const 
{
	return Vec4d(x / v, y / v, z / v, w / v);
}

Vec4d& Vec4d::operator+=(const Vec4d& vec) 
{
	x = (x + vec.x); y = (y + vec.y); z = (z + vec.z); w = (w + vec.w); return *this;
}

Vec4d& Vec4d::operator-=(const Vec4d& vec) 
{
	x = (x - vec.x); y = (y - vec.y); z = (z - vec.z); w = (w - vec.w); return *this;
}

Vec4d& Vec4d::operator*=(const Vec4d& vec) 
{
	x = (x * vec.x); y = (y * vec.y); z = (z * vec.z); w = (w * vec.w); return *this;
}

Vec4d& Vec4d::operator/=(const Vec4d& vec) 
{
	x = (x / vec.x); y = (y / vec.y); z = (z / vec.z); w = (w / vec.w); return *this;
}

Vec4d& Vec4d::operator+=(double v) 
{
	x = (x + v); y = (y + v); z = (z + v); w = (w + v); return *this;
}

Vec4d& Vec4d::operator-=(double v) 
{
	x = (x - v); y = (y - v); z = (z - v); w = (w - v); return *this;
}

Vec4d& Vec4d::operator*=(double v) 
{
	x = (x * v); y = (y * v); z = (z * v); w = (w * v); return *this;
}

Vec4d& Vec4d::operator/=(double v) 
{
	x = (x / v); y = (y / v); z = (z / v); w = (w / v); return *this;
}

bool Vec4d::operator==(const Vec4d& vec) const 
{
	return (x == vec.x && y == vec.y && z == vec.z && w == vec.w);
}

bool Vec4d::operator!=(const Vec4d& vec) const 
{
	return (x != vec.x || y != vec.y || z != vec.z || w != vec.w);
}

bool Vec4d::operator==(const double& v) const 
{
	return (x == v && y == v && z == v && w == v);
}

bool Vec4d::operator!=(const double& v) const 
{
	return (x != v || y != v || z != v || w != v);
}

bool Vec4d::isNan() const
{
	return Double::isNan(x) && Double::isNan(y) && Double::isNan(z) && Double::isNan(w);
}

bool Vec4d::hasNan() const
{
	return Double::isNan(x) || Double::isNan(y) || Double::isNan(z) || Double::isNan(w);
}

bool Vec4d::hasNoNan() const
{
	return !Double::isNan(x) && !Double::isNan(y) && !Double::isNan(z) && !Double::isNan(w);
}

bool Vec4d::equals(const Vec4d& vec, double epsilon) const
{
	return (Double::equals(x, vec.x, epsilon) && Double::equals(y, vec.y, epsilon) && Double::equals(z, vec.z, epsilon)&& Double::equals(w, vec.w, epsilon));
}

bool Vec4d::notEquals(const Vec4d& vec, double epsilon) const
{
	return (!Double::equals(x, vec.x, epsilon) || !Double::equals(y, vec.y, epsilon) || !Double::equals(z, vec.z, epsilon)|| !Double::equals(w, vec.w, epsilon));
}

bool Vec4d::equals(double _x, double _y, double _z, double _w, double epsilon) const
{
	return (Double::equals(x, _x, epsilon) && Double::equals(y, _y, epsilon) && Double::equals(z, _z, epsilon)&& Double::equals(w, _w, epsilon));
}

bool Vec4d::notEquals(double _x, double _y, double _z, double _w, double epsilon) const
{
	return (!Double::equals(x, _x, epsilon) || !Double::equals(y, _y, epsilon) || !Double::equals(z, _z, epsilon)|| !Double::equals(w, _w, epsilon));
}

Vec4d& Vec4d::set(double value) 
{
	this->x = (value); this->y = (value); this->z = (value); this->w = (value); return *this;
}

Vec4d& Vec4d::set(double _x, double _y) 
{
	this->x = (_x); this->y = (_y); return *this;
}

Vec4d& Vec4d::set(double _x, double _y, double _z) 
{
	this->x = (_x); this->y = (_y); this->z = (_z); return *this;
}

Vec4d& Vec4d::set(double _x, double _y, double _z, double _w) 
{
	this->x = (_x); this->y = (_y); this->z = (_z); this->w = (_w); return *this;
}

double Vec4d::magn() const
{
	return (std::sqrt(x * x + y * y + z * z + w * w));
}

Vec4d Vec4d::norm() const
{
	const register double magnitude = std::sqrt(x * x + y * y + z * z + w * w);
	return Vec4d(x / magnitude, y / magnitude, z / magnitude, w / magnitude);
}

Vec4d& Vec4d::normalize()
{
	const register double magnitude = std::sqrt(x * x + y * y + z * z + w * w);
	x = (x / magnitude);
	y = (y / magnitude);
	z = (z / magnitude);
	w = (w / magnitude);
	return *this;
}

double Vec4d::dot(const Vec4d& vec) const
{
	return (x * vec.x + y * vec.y + z * vec.z + w * vec.w);
}

Vec4d& Vec4d::scale(double scale_all)
{
	x = (scale_all * x);
	y = (scale_all * y);
	z = (scale_all * z);
	w = (scale_all * w);
	return *this;
}

Vec4d& Vec4d::scale(double scale_x, double scale_y, double scale_z, double scale_w)
{
	x = (scale_x * x);
	y = (scale_y * y);
	z = (scale_z * z);
	w = (scale_w * w);
	return *this;
}

Vec4d Vec4d::scaled(double scale_all) const
{
	return Vec4d(scale_all * x, scale_all * y, scale_all * z, scale_all * w);
}

Vec4d Vec4d::scaled(double scale_x, double scale_y, double scale_z, double scale_w) const
{
	return Vec4d(scale_x * x, scale_y * y, scale_z * z, scale_w * w);
}

Vec4d& Vec4d::translate(double delta_x, double delta_y, double delta_z, double delta_w)
{
	x = (x + delta_x);
	y = (y + delta_y);
	z = (z + delta_z);
	w = (w + delta_w);
	return *this;
}

Vec4d& Vec4d::translate(const Vec4d& delta)
{
	x = (x + delta.x);
	y = (y + delta.y);
	z = (z + delta.z);
	w = (w + delta.w);
	return *this;
}

Vec4d Vec4d::translated(double delta_x, double delta_y, double delta_z, double delta_w) const
{
	return Vec4d(x + delta_x, y + delta_y, z + delta_z, w + delta_w);
}

Vec4d Vec4d::translated(const Vec4d& delta) const
{
	return Vec4d(x + delta.x, y + delta.y, z + delta.z, w + delta.w);
}

Vec4d operator+(double v, const Vec4d& vec)
{
	return Vec4d(v + vec.x, v + vec.y, v + vec.z, v + vec.w);
}

Vec4d operator-(double v, const Vec4d& vec)
{
	return Vec4d(v - vec.x, v - vec.y, v - vec.z, v - vec.w);
}

Vec4d operator*(double v, const Vec4d& vec)
{
	return Vec4d(v * vec.x, v * vec.y, v * vec.z, v * vec.w);
}

Vec4d operator/(double v, const Vec4d& vec)
{
	return Vec4d(v / vec.x, v / vec.y, v / vec.z, v / vec.w);
}

Vec4d Vec4d::filled(double v) { return Vec4d(v, v, v, v); }
const Vec4d Vec4d::Zero(0.0, 0.0, 0.0, 0.0);
const Vec4d Vec4d::Identity(1.0, 1.0, 1.0, 1.0);
Vec4d Vec4d::Default(0.0, 0.0, 0.0, 0.0);
Rules::Axis Vec4d::DefaultAxisRule = Rules::Axis::AXIS_RHS;

} // namespace axl.math
} // namespace axl
