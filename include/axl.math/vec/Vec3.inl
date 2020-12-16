#include <cmath>
#include "Vec3.hpp"

namespace axl {
namespace math {

template <typename T>
inline Vec3<T>::Vec3(T _x, T _y, T _z) :
	x(_x), y(_y), z(_z)
{}
template <typename T>
template <typename U>
inline Vec3<T>::Vec3(U _x, U _y, U _z) :
	x((T)_x), y((T)_y), z((T)_z)
{}
template <typename T>
template <typename U>
inline Vec3<T>::Vec3(const Vec3<U>& vec) :
	x((T)vec.x), y((T)vec.y), z((T)vec.z)
{}
template <typename T>
template <typename U>
inline Vec3<T>::Vec3(const Vec2<U>& vec, T _z) :
	x((T)vec.x), y((T)vec.y), z(_z)
{}

template <typename T>
inline Vec3<T> Vec3<T>::operator+() const
{
	return Vec3<T>(x, y, z);
}
template <typename T>
inline Vec3<T> Vec3<T>::operator-() const
{
	return Vec3<T>(-x, -y, -z);
}
template <typename T>
inline Vec3<T> Vec3<T>::operator+(const Vec3<T>& vec) const 
{
	return Vec3<T>(x + vec.x, y + vec.y, z + vec.z);
}
template <typename T>
inline Vec3<T> Vec3<T>::operator-(const Vec3<T>& vec) const 
{
	return Vec3<T>(x - vec.x, y - vec.y, z - vec.z);
}
template <typename T>
inline Vec3<T> Vec3<T>::operator*(const Vec3<T>& vec) const 
{
	return Vec3<T>(x * vec.x, y * vec.y, z * vec.z);
}
template <typename T>
inline Vec3<T> Vec3<T>::operator/(const Vec3<T>& vec) const 
{
	return Vec3<T>(x / vec.x, y / vec.y, z / vec.z);
}
template <typename T>
inline Vec3<T> Vec3<T>::operator+(T v) const 
{
	return Vec3<T>(x + v, y + v, z + v);
}
template <typename T>
inline Vec3<T> Vec3<T>::operator-(T v) const 
{
	return Vec3<T>(x - v, y - v, z - v);
}
template <typename T>
inline Vec3<T> Vec3<T>::operator*(T v) const 
{
	return Vec3<T>(x * v, y * v, z * v);
}
template <typename T>
inline Vec3<T> Vec3<T>::operator/(T v) const 
{
	return Vec3<T>(x / v, y / v, z / v);
}
template <typename T>
inline Vec3<T>& Vec3<T>::operator+=(const Vec3<T>& vec) 
{
	x = (x + vec.x); y = (y + vec.y); z = (z + vec.z); return *this;
}
template <typename T>
inline Vec3<T>& Vec3<T>::operator-=(const Vec3<T>& vec) 
{
	x = (x - vec.x); y = (y - vec.y); z = (z - vec.z); return *this;
}
template <typename T>
inline Vec3<T>& Vec3<T>::operator*=(const Vec3<T>& vec) 
{
	x = (x * vec.x); y = (y * vec.y); z = (z * vec.z); return *this;
}
template <typename T>
inline Vec3<T>& Vec3<T>::operator/=(const Vec3<T>& vec) 
{
	x = (x / vec.x); y = (y / vec.y); z = (z / vec.z); return *this;
}
template <typename T>
inline Vec3<T>& Vec3<T>::operator+=(T v) 
{
	x = (x + v); y = (y + v); z = (z + v); return *this;
}
template <typename T>
inline Vec3<T>& Vec3<T>::operator-=(T v) 
{
	x = (x - v); y = (y - v); z = (z - v); return *this;
}
template <typename T>
inline Vec3<T>& Vec3<T>::operator*=(T v) 
{
	x = (x * v); y = (y * v); z = (z * v); return *this;
}
template <typename T>
inline Vec3<T>& Vec3<T>::operator/=(T v) 
{
	x = (x / v); y = (y / v); z = (z / v); return *this;
}
template <typename T>
inline bool Vec3<T>::operator==(const Vec3<T>& vec) const 
{
	return (x == vec.x && y == vec.y && z == vec.z);
}
template <typename T>
inline bool Vec3<T>::operator!=(const Vec3<T>& vec) const 
{
	return (x != vec.x || y != vec.y || z != vec.z);
}
template <typename T>
inline bool Vec3<T>::operator==(const T& v) const 
{
	return (x == v && y == v && z == v);
}
template <typename T>
inline bool Vec3<T>::operator!=(const T& v) const 
{
	return (x != v || y != v || z != v);
}

template <typename T>
template <typename U>
inline bool Vec3<T>::equals(const Vec3<U>& vec) const
{
	return (x == vec.x && y == vec.y && z == vec.z);
}
template <typename T>
template <typename U>
inline bool Vec3<T>::notEquals(const Vec3<U>& vec) const
{
	return (x != vec.x || y != vec.y || z != vec.z);
}
template <typename T>
template <typename U>
inline bool Vec3<T>::equals(U _x, U _y, U _z) const
{
	return (x == _x && y == _y && z == _z);
}
template <typename T>
template <typename U>
inline bool Vec3<T>::notEquals(U _x, U _y, U _z) const
{
	return (x != _x || y != _y || z != _z);
}

template <typename T>
inline Vec3<T>& Vec3<T>::set(T value) 
{
	this->x = (value); this->y = (value); this->z = (value); return *this;
}
template <typename T>
inline Vec3<T>& Vec3<T>::set(T _x, T _y) 
{
	this->x = (_x); this->y = (_y); return *this;
}
template <typename T>
inline Vec3<T>& Vec3<T>::set(T _x, T _y, T _z) 
{
	this->x = (_x); this->y = (_y); this->z = (_z); return *this;
}

template <typename T>
inline Vec3<T> operator+(T v, const Vec3<T>& vec)
{
	return Vec3<T>(v + vec.x, v + vec.y, v + vec.z);
}

template <typename T>
inline Vec3<T> operator-(T v, const Vec3<T>& vec)
{
	return Vec3<T>(v - vec.x, v - vec.y, v - vec.z);
}

template <typename T>
inline Vec3<T> operator*(T v, const Vec3<T>& vec)
{
	return Vec3<T>(v * vec.x, v * vec.y, v * vec.z);
}

template <typename T>
inline Vec3<T> operator/(T v, const Vec3<T>& vec)
{
	return Vec3<T>(v / vec.x, v / vec.y, v / vec.z);
}

template <typename T>
Vec3<T> Vec3<T>::filled(T v) { return Vec3<T>(v, v, v); }
template <typename T>
const Vec3<T> Vec3<T>::Zero((T)0, (T)0, (T)0);
template <typename T>
const Vec3<T> Vec3<T>::Identity((T)1, (T)1, (T)1);
template <typename T>
Vec3<T> Vec3<T>::Default((T)0, (T)0, (T)0);

} // namespace axl.math
} // namespace axl
