#include <cmath>
#include <axl.math/float.hpp>
#include <axl.math/Vec4f.hpp>

namespace axl {
namespace math {

Vec4f::Vec4f(float _x, float _y, float _z, float _w) :
	x(_x), y(_y), z(_z), w(_w)
{}

Vec4f::Vec4f(const Vec4f& vec) :
	x(vec.x), y(vec.y), z(vec.z), w(vec.w)
{}

Vec4f::Vec4f(const Vec2f& vec, float _z, float _w) :
	x(vec.x), y(vec.y), z(_z), w(_w)
{}

Vec4f::Vec4f(const Vec3f& vec, float _w) :
	x(vec.x), y(vec.y), z(vec.z), w(_w)
{}

Vec4f Vec4f::operator+() const
{
	return Vec4f(x, y, z, w);
}

Vec4f Vec4f::operator-() const
{
	return Vec4f(-x, -y, -z, -w);
}

Vec4f Vec4f::operator+(const Vec4f& vec) const 
{
	return Vec4f(x + vec.x, y + vec.y, z + vec.z, w + vec.w);
}

Vec4f Vec4f::operator-(const Vec4f& vec) const 
{
	return Vec4f(x - vec.x, y - vec.y, z - vec.z, w - vec.w);
}

Vec4f Vec4f::operator*(const Vec4f& vec) const 
{
	return Vec4f(x * vec.x, y * vec.y, z * vec.z, w * vec.w);
}

Vec4f Vec4f::operator/(const Vec4f& vec) const 
{
	return Vec4f(x / vec.x, y / vec.y, z / vec.z, w / vec.w);
}

Vec4f Vec4f::operator+(float v) const 
{
	return Vec4f(x + v, y + v, z + v, w + v);
}

Vec4f Vec4f::operator-(float v) const 
{
	return Vec4f(x - v, y - v, z - v, w - v);
}

Vec4f Vec4f::operator*(float v) const 
{
	return Vec4f(x * v, y * v, z * v, w * v);
}

Vec4f Vec4f::operator/(float v) const 
{
	return Vec4f(x / v, y / v, z / v, w / v);
}

Vec4f& Vec4f::operator+=(const Vec4f& vec) 
{
	x = (x + vec.x); y = (y + vec.y); z = (z + vec.z); w = (w + vec.w); return *this;
}

Vec4f& Vec4f::operator-=(const Vec4f& vec) 
{
	x = (x - vec.x); y = (y - vec.y); z = (z - vec.z); w = (w - vec.w); return *this;
}

Vec4f& Vec4f::operator*=(const Vec4f& vec) 
{
	x = (x * vec.x); y = (y * vec.y); z = (z * vec.z); w = (w * vec.w); return *this;
}

Vec4f& Vec4f::operator/=(const Vec4f& vec) 
{
	x = (x / vec.x); y = (y / vec.y); z = (z / vec.z); w = (w / vec.w); return *this;
}

Vec4f& Vec4f::operator+=(float v) 
{
	x = (x + v); y = (y + v); z = (z + v); w = (w + v); return *this;
}

Vec4f& Vec4f::operator-=(float v) 
{
	x = (x - v); y = (y - v); z = (z - v); w = (w - v); return *this;
}

Vec4f& Vec4f::operator*=(float v) 
{
	x = (x * v); y = (y * v); z = (z * v); w = (w * v); return *this;
}

Vec4f& Vec4f::operator/=(float v) 
{
	x = (x / v); y = (y / v); z = (z / v); w = (w / v); return *this;
}

bool Vec4f::operator==(const Vec4f& vec) const 
{
	return (x == vec.x && y == vec.y && z == vec.z && w == vec.w);
}

bool Vec4f::operator!=(const Vec4f& vec) const 
{
	return (x != vec.x || y != vec.y || z != vec.z || w != vec.w);
}

bool Vec4f::operator==(const float& v) const 
{
	return (x == v && y == v && z == v && w == v);
}

bool Vec4f::operator!=(const float& v) const 
{
	return (x != v || y != v || z != v || w != v);
}

bool Vec4f::isNan() const
{
	return Float::isNan(x) && Float::isNan(y) && Float::isNan(z) && Float::isNan(w);
}

bool Vec4f::hasNan() const
{
	return Float::isNan(x) || Float::isNan(y) || Float::isNan(z) || Float::isNan(w);
}

bool Vec4f::hasNoNan() const
{
	return !Float::isNan(x) && !Float::isNan(y) && !Float::isNan(z) && !Float::isNan(w);
}

bool Vec4f::equals(const Vec4f& vec, float epsilon) const
{
	return (Float::equals(x, vec.x, epsilon) && Float::equals(y, vec.y, epsilon) && Float::equals(z, vec.z, epsilon)&& Float::equals(w, vec.w, epsilon));
}

bool Vec4f::notEquals(const Vec4f& vec, float epsilon) const
{
	return (!Float::equals(x, vec.x, epsilon) || !Float::equals(y, vec.y, epsilon) || !Float::equals(z, vec.z, epsilon)|| !Float::equals(w, vec.w, epsilon));
}

bool Vec4f::equals(float _x, float _y, float _z, float _w, float epsilon) const
{
	return (Float::equals(x, _x, epsilon) && Float::equals(y, _y, epsilon) && Float::equals(z, _z, epsilon)&& Float::equals(w, _w, epsilon));
}

bool Vec4f::notEquals(float _x, float _y, float _z, float _w, float epsilon) const
{
	return (!Float::equals(x, _x, epsilon) || !Float::equals(y, _y, epsilon) || !Float::equals(z, _z, epsilon)|| !Float::equals(w, _w, epsilon));
}

Vec4f& Vec4f::set(float value) 
{
	this->x = (value); this->y = (value); this->z = (value); this->w = (value); return *this;
}

Vec4f& Vec4f::set(float _x, float _y) 
{
	this->x = (_x); this->y = (_y); return *this;
}

Vec4f& Vec4f::set(float _x, float _y, float _z) 
{
	this->x = (_x); this->y = (_y); this->z = (_z); return *this;
}

Vec4f& Vec4f::set(float _x, float _y, float _z, float _w) 
{
	this->x = (_x); this->y = (_y); this->z = (_z); this->w = (_w); return *this;
}

float Vec4f::magn() const
{
	return (std::sqrt(x * x + y * y + z * z + w * w));
}

Vec4f Vec4f::norm() const
{
	const register float magnitude = std::sqrt(x * x + y * y + z * z + w * w);
	return Vec4f(x / magnitude, y / magnitude, z / magnitude, w / magnitude);
}

Vec4f& Vec4f::normalize()
{
	const register float magnitude = std::sqrt(x * x + y * y + z * z + w * w);
	x = (x / magnitude);
	y = (y / magnitude);
	z = (z / magnitude);
	w = (w / magnitude);
	return *this;
}

float Vec4f::dot(const Vec4f& vec) const
{
	return (x * vec.x + y * vec.y + z * vec.z + w * vec.w);
}

Vec4f& Vec4f::scale(float scale_all)
{
	x = (scale_all * x);
	y = (scale_all * y);
	z = (scale_all * z);
	w = (scale_all * w);
	return *this;
}

Vec4f& Vec4f::scale(float scale_x, float scale_y, float scale_z, float scale_w)
{
	x = (scale_x * x);
	y = (scale_y * y);
	z = (scale_z * z);
	w = (scale_w * w);
	return *this;
}

Vec4f Vec4f::scaled(float scale_all) const
{
	return Vec4f(scale_all * x, scale_all * y, scale_all * z, scale_all * w);
}

Vec4f Vec4f::scaled(float scale_x, float scale_y, float scale_z, float scale_w) const
{
	return Vec4f(scale_x * x, scale_y * y, scale_z * z, scale_w * w);
}

Vec4f& Vec4f::translate(float delta_x, float delta_y, float delta_z, float delta_w)
{
	x = (x + delta_x);
	y = (y + delta_y);
	z = (z + delta_z);
	w = (w + delta_w);
	return *this;
}

Vec4f& Vec4f::translate(const Vec4f& delta)
{
	x = (x + delta.x);
	y = (y + delta.y);
	z = (z + delta.z);
	w = (w + delta.w);
	return *this;
}

Vec4f Vec4f::translated(float delta_x, float delta_y, float delta_z, float delta_w) const
{
	return Vec4f(x + delta_x, y + delta_y, z + delta_z, w + delta_w);
}

Vec4f Vec4f::translated(const Vec4f& delta) const
{
	return Vec4f(x + delta.x, y + delta.y, z + delta.z, w + delta.w);
}

Vec4f operator+(float v, const Vec4f& vec)
{
	return Vec4f(v + vec.x, v + vec.y, v + vec.z, v + vec.w);
}

Vec4f operator-(float v, const Vec4f& vec)
{
	return Vec4f(v - vec.x, v - vec.y, v - vec.z, v - vec.w);
}

Vec4f operator*(float v, const Vec4f& vec)
{
	return Vec4f(v * vec.x, v * vec.y, v * vec.z, v * vec.w);
}

Vec4f operator/(float v, const Vec4f& vec)
{
	return Vec4f(v / vec.x, v / vec.y, v / vec.z, v / vec.w);
}


const Vec4f Vec4f::Zero(0.0f, 0.0f, 0.0f, 0.0f);
const Vec4f Vec4f::Identity(1.0f, 1.0f, 1.0f, 1.0f);
Vec4f Vec4f::Default(0.0f, 0.0f, 0.0f, 0.0f);
Rules::Axis Vec4f::DefaultAxisRule = Rules::AXIS_RHS;

} // namespace axl.math
} // namespace axl
