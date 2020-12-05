#include <cmath>
#include "Vec2.hpp"

namespace axl {
namespace math {

template <typename T>
inline Vec2<T>::Vec2(T _x, T _y) :
	x(_x), y(_y)
{}
template <typename T>
template <typename U>
inline Vec2<T>::Vec2(U _x, U _y) :
	x((T)_x), y((T)_y)
{}
template <typename T>
template <typename U>
inline Vec2<T>::Vec2(const Vec2<U>& vec) :
	x((T)vec.x), y((T)vec.y)
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
template <typename U>
inline bool Vec2<T>::equals(const Vec2<U>& vec) const
{
	return (x == vec.x && y == vec.y);
}
template <typename T>
template <typename U>
inline bool Vec2<T>::notEquals(const Vec2<U>& vec) const
{
	return (x != vec.x || y != vec.y);
}
template <typename T>
template <typename U>
inline bool Vec2<T>::equals(U _x, U _y) const
{
	return (x == _x && y == _y);
}
template <typename T>
template <typename U>
inline bool Vec2<T>::notEquals(U _x, U _y) const
{
	return (x != _x || y != _y);
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
inline Vec2<T> operator+(T v, const Vec2<T>& vec)
{
	return Vec2<T>(v + vec.x,v + vec.y);
}

template <typename T>
inline Vec2<T> operator-(T v, const Vec2<T>& vec)
{
	return Vec2<T>(v - vec.x,v - vec.y);
}

template <typename T>
inline Vec2<T> operator*(T v, const Vec2<T>& vec)
{
	return Vec2<T>(v * vec.x,v * vec.y);
}

template <typename T>
inline Vec2<T> operator/(T v, const Vec2<T>& vec)
{
	return Vec2<T>(v / vec.x,v / vec.y);
}


template <typename T>
Vec2<T> Vec2<T>::filled(T v) { return Vec2<T>(v, v); }
template <typename T>
const Vec2<T> Vec2<T>::Zero((T)0, (T)0);
template <typename T>
const Vec2<T> Vec2<T>::Identity((T)1, (T)1);
template <typename T>
Vec2<T> Vec2<T>::Default((T)0, (T)0);

} // namespace axl.math
} // namespace axl
