#include "Vec2.hpp"
#include <cmath>
#include <axl.math/constants.hpp>
#include <axl.math/Double.hpp>
#include <axl.math/Vec2.hpp>

namespace axl {
namespace math {

template <typename T>
inline Vec2<T>::Vec2(T x, T y) :
	x(x), y(y)
{}
template <typename T>
inline Vec2<T>::Vec2(const Vec2<T>& vec) :
	x(vec.x), y(vec.y)
{}

template <typename T>
inline Vec2<T> Vec2<T>::operator+() const
{
	return Vec2<T>(x, y);
}
template <typename T>
inline Vec2<T> Vec2<T>::operator-() const
{
	return Vec2<T>(-x, -y);
}
template <typename T>
inline Vec2<T> Vec2<T>::operator+(const Vec2<T>& vec) const 
{
	return Vec2<T>(x + vec.x, y + vec.y);
}
template <typename T>
inline Vec2<T> Vec2<T>::operator-(const Vec2<T>& vec) const 
{
	return Vec2<T>(x - vec.x, y - vec.y);
}
template <typename T>
inline Vec2<T> Vec2<T>::operator*(const Vec2<T>& vec) const 
{
	return Vec2<T>(x * vec.x, y * vec.y);
}
template <typename T>
inline Vec2<T> Vec2<T>::operator/(const Vec2<T>& vec) const 
{
	return Vec2<T>(x / vec.x, y / vec.y);
}
template <typename T>
inline Vec2<T> Vec2<T>::operator+(T v) const 
{
	return Vec2<T>(x + v, y + v);
}
template <typename T>
inline Vec2<T> Vec2<T>::operator-(T v) const 
{
	return Vec2<T>(x - v, y - v);
}
template <typename T>
inline Vec2<T> Vec2<T>::operator*(T v) const 
{
	return Vec2<T>(x * v, y * v);
}
template <typename T>
inline Vec2<T> Vec2<T>::operator/(T v) const 
{
	return Vec2<T>(x / v, y / v);
}
template <typename T>
inline Vec2<T>& Vec2<T>::operator+=(const Vec2<T>& vec) 
{
	x = (x + vec.x); y = (y + vec.y); return *this;
}
template <typename T>
inline Vec2<T>& Vec2<T>::operator-=(const Vec2<T>& vec) 
{
	x = (x - vec.x); y = (y - vec.y); return *this;
}
template <typename T>
inline Vec2<T>& Vec2<T>::operator*=(const Vec2<T>& vec) 
{
	x = (x * vec.x); y = (y * vec.y); return *this;
}
template <typename T>
inline Vec2<T>& Vec2<T>::operator/=(const Vec2<T>& vec) 
{
	x = (x / vec.x); y = (y / vec.y); return *this;
}
template <typename T>
inline Vec2<T>& Vec2<T>::operator+=(T v) 
{
	x = x + v; y = y + v; return *this;
}
template <typename T>
inline Vec2<T>& Vec2<T>::operator-=(T v) 
{
	x = x - v; y = y - v; return *this;
}
template <typename T>
inline Vec2<T>& Vec2<T>::operator*=(T v) 
{
	x = x * v; y = y * v; return *this;
}
template <typename T>
inline Vec2<T>& Vec2<T>::operator/=(T v) 
{
	x = x / v; y = y / v; return *this;
}
template <typename T>
inline bool Vec2<T>::operator==(const Vec2<T>& vec) const 
{
	return (x == vec.x && y == vec.y);
}
template <typename T>
inline bool Vec2<T>::operator!=(const Vec2<T>& vec) const 
{
	return (x != vec.x || y != vec.y);
}
template <typename T>
inline bool Vec2<T>::operator==(const T& v) const 
{
	return (x == v && y == v);
}
template <typename T>
inline bool Vec2<T>::operator!=(const T& v) const 
{
	return (x != v || y != v);
}

template <typename T>
inline Vec2<T>& Vec2<T>::set(T value)
{
	this->x = (value);
	this->y = (value);
	return *this;
}
template <typename T>
inline Vec2<T>& Vec2<T>::set(T _x, T _y)
{
	this->x = (_x);
	this->y = (_y);
	return *this;
}
template <typename T>
inline bool Vec2<T>::isNan() const
{
	return Double::isNan(x) && Double::isNan(y);
}
template <typename T>
inline bool Vec2<T>::hasNan() const
{
	return Double::isNan(x) || Double::isNan(y);
}
template <typename T>
inline bool Vec2<T>::hasNoNan() const
{
	return !Double::isNan(x) && !Double::isNan(y);
}
template <typename T>
inline bool Vec2<T>::equals(const Vec2<T>& vec, T epsilon) const 
{
	return (Double::equals(x, vec.x, epsilon) && Double::equals(y, vec.y, epsilon));
}
template <typename T>
inline bool Vec2<T>::notEquals(const Vec2<T>& vec, T epsilon) const 
{
	return (!Double::equals(x, vec.x, epsilon) || !Double::equals(y, vec.y, epsilon));
}
template <typename T>
inline bool Vec2<T>::equals(T _x, T _y, T epsilon) const 
{
	return (Double::equals(x, _x, epsilon) && Double::equals(y, _y, epsilon));
}
template <typename T>
inline bool Vec2<T>::notEquals(T _x, T _y, T epsilon) const 
{
	return (!Double::equals(x, _x, epsilon) || !Double::equals(y, _y, epsilon));
}

template <typename T>
inline T Vec2<T>::magn() const
{
	return (std::sqrt(x*x + y*y));
}
template <typename T>
inline Vec2<T> Vec2<T>::norm() const
{
	const register T magnitude = std::sqrt(x*x + y*y);
	return Vec2<T>(x / magnitude, y / magnitude);
}
template <typename T>
inline Vec2<T>& Vec2<T>::normalize()
{
	const register T magnitude = std::sqrt(x*x + y*y);
	x = (x / magnitude);
	y = (y / magnitude);
	return *this;
}
template <typename T>
inline T Vec2<T>::dot(const Vec2<T>& vec) const
{
	return (x * vec.x + y * vec.y);
}
template <typename T>
inline T Vec2<T>::cross(const Vec2<T>& vec) const
{
	return (x * vec.y - y * vec.x);
}
template <typename T>
inline T Vec2<T>::angle(Rules::Axis axis_rule) const
{
	switch(axis_rule)
	{
		default:
		case Rules::RHS: return std::atan2(y, x);
		case Rules::LHS: return std::atan2(x, y);
	}
}
template <typename T>
inline T Vec2<T>::angle(const Vec2<T>& ref_vec, Rules::Axis axis_rule) const
{
	switch(axis_rule)
	{
		default:
		case Rules::RHS: return (std::atan2(y, x) - std::atan2(ref_vec.y, ref_vec.x));
		case Rules::LHS: return (std::atan2(x, y) - std::atan2(ref_vec.x, ref_vec.y));
	}
}
template <typename T>
inline T Vec2<T>::fullAngle(Rules::Axis axis_rule) const
{
	using namespace axl::math::Constants;
	switch(axis_rule)
	{
		default:
		case Rules::RHS:
			return std::fmod((_2_PI + std::atan2(y, x)), _2_PI);
		case Rules::LHS:
			return std::fmod((_2_PI + std::atan2(x, y)), _2_PI);
	}
}
template <typename T>
inline T Vec2<T>::fullAngle(const Vec2<T>& ref_vec, Rules::Axis axis_rule) const
{
	using namespace axl::math::Constants;
	switch(axis_rule)
	{
		default:
		case Rules::RHS: return std::fmod((_2_PI + std::atan2(y, x) - std::atan2(ref_vec.y, ref_vec.x)), _2_PI);
		case Rules::LHS: return std::fmod((_2_PI + std::atan2(x, y) - std::atan2(ref_vec.x, ref_vec.y)), _2_PI);
	}
}

template <typename T>
inline Vec2<T>& Vec2<T>::scale(T scale_all)
{
	x = (scale_all * x);
	y = (scale_all * y);
	return *this;
}
template <typename T>
inline Vec2<T>& Vec2<T>::scale(T scale_x, T scale_y)
{
	x = (scale_x * x);
	y = (scale_y * y);
	return *this;
}
template <typename T>
inline Vec2<T> Vec2<T>::scaled(T scale_all) const
{
	return Vec2<T>(scale_all * x, scale_all * y);
}
template <typename T>
inline Vec2<T> Vec2<T>::scaled(T scale_x, T scale_y) const
{
	return Vec2<T>(scale_x * x, scale_y * y);
}
template <typename T>
inline Vec2<T>& Vec2<T>::translate(T delta_x, T delta_y)
{
	x = (x + delta_x);
	y = (y + delta_y);
	return *this;
}
template <typename T>
inline Vec2<T>& Vec2<T>::translate(const Vec2<T>& delta)
{
	x = (x + delta.x);
	y = (y + delta.y);
	return *this;
}
template <typename T>
inline Vec2<T> Vec2<T>::translated(T delta_x, T delta_y) const
{
	return Vec2<T>(x + delta_x, y + delta_y);
}
template <typename T>
inline Vec2<T> Vec2<T>::translated(const Vec2<T>& delta) const
{
	return Vec2<T>(x + delta.x, y + delta.y);
}

template <typename T>
inline Vec2<T>& Vec2<T>::rotate(T theta_z, Rules::Axis axis_rule)
{
	
	switch (axis_rule)
	{
		default:
		case Rules::RHS:
			{
				const register T _x = (x * std::cos(theta_z) - y * std::sin(theta_z));
				const register T _y = (x * std::sin(theta_z) + y * std::cos(theta_z));
				this->x = _x;
				this->y = _y;
			}
			return *this;
		case Rules::LHS:
			{
				theta_z = -theta_z;
				const register T _x = (x * std::cos(theta_z) - y * std::sin(theta_z));
				const register T _y = (x * std::sin(theta_z) + y * std::cos(theta_z));
				this->x = _x;
				this->y = _y;
			}
			return *this;
	}
	
}
template <typename T>
inline Vec2<T> Vec2<T>::rotated(T theta_z, Rules::Axis axis_rule) const
{
	switch (axis_rule)
	{
		default:
		case Rules::RHS: return Vec2<T>((x * std::cos(theta_z) - y * std::sin(theta_z)), (x * std::sin(theta_z) + y * std::cos(theta_z)));
		case Rules::LHS:
			theta_z = -theta_z;
			return Vec2<T>((x * std::cos(theta_z) - y * std::sin(theta_z)), (x * std::sin(theta_z) + y * std::cos(theta_z)));
	}
}

template <typename T>
const Vec2<T> Vec2<T>::Zero(0.0, 0.0);
template <typename T>
const Vec2<T> Vec2<T>::Identity(1.0, 1.0);
template <typename T>
Vec2<T> Vec2<T>::Default(0.0, 0.0);
template <typename T>
Rules::Axis Vec2<T>::DefaultAxisRule = Rules::RHS;

} // namespace math
} // namespace axl
