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
const Vec2<T> Vec2<T>::Zero((T)0, (T)0);
template <typename T>
const Vec2<T> Vec2<T>::Identity((T)1, (T)1);
template <typename T>
Vec2<T> Vec2<T>::Default((T)0, (T)0);

} // namespace math
} // namespace axl
