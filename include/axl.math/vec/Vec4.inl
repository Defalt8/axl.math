#include <cmath>
#include "Vec4.hpp"

namespace axl {
namespace math {

template <typename T>
inline Vec4<T>::Vec4(T _x, T _y, T _z, T _w) :
	x(_x), y(_y), z(_z), w(_w)
{}
template <typename T>
template <typename U>
inline Vec4<T>::Vec4(U _x, U _y, U _z, U _w) :
	x((T)_x), y((T)_y), z((T)_z), w((T)_w)
{}
template <typename T>
template <typename U>
inline Vec4<T>::Vec4(const Vec4<U>& vec) :
	x((T)vec.x), y((T)vec.y), z((T)vec.z), w((T)vec.w)
{}
template <typename T>
template <typename U>
inline Vec4<T>::Vec4(const Vec2<U>& vec, T _z, T _w) :
	x((T)vec.x), y((T)vec.y), z(_z), w(_w)
{}
template <typename T>
template <typename U>
inline Vec4<T>::Vec4(const Vec3<U>& vec, T _w) :
	x((T)vec.x), y((T)vec.y), z((T)vec.z), w(_w)
{}

template <typename T>
inline Vec4<T> Vec4<T>::operator+() const
{
	return Vec4<T>(x, y, z, w);
}
template <typename T>
inline Vec4<T> Vec4<T>::operator-() const
{
	return Vec4<T>(-x, -y, -z, -w);
}
template <typename T>
inline Vec4<T> Vec4<T>::operator+(const Vec4<T>& vec) const 
{
	return Vec4<T>(x + vec.x, y + vec.y, z + vec.z, w + vec.w);
}
template <typename T>
inline Vec4<T> Vec4<T>::operator-(const Vec4<T>& vec) const 
{
	return Vec4<T>(x - vec.x, y - vec.y, z - vec.z, w - vec.w);
}
template <typename T>
inline Vec4<T> Vec4<T>::operator*(const Vec4<T>& vec) const 
{
	return Vec4<T>(x * vec.x, y * vec.y, z * vec.z, w * vec.w);
}
template <typename T>
inline Vec4<T> Vec4<T>::operator/(const Vec4<T>& vec) const 
{
	return Vec4<T>(x / vec.x, y / vec.y, z / vec.z, w / vec.w);
}
template <typename T>
inline Vec4<T> Vec4<T>::operator+(T v) const 
{
	return Vec4<T>(x + v, y + v, z + v, w + v);
}
template <typename T>
inline Vec4<T> Vec4<T>::operator-(T v) const 
{
	return Vec4<T>(x - v, y - v, z - v, w - v);
}
template <typename T>
inline Vec4<T> Vec4<T>::operator*(T v) const 
{
	return Vec4<T>(x * v, y * v, z * v, w * v);
}
template <typename T>
inline Vec4<T> Vec4<T>::operator/(T v) const 
{
	return Vec4<T>(x / v, y / v, z / v, w / v);
}
template <typename T>
inline Vec4<T>& Vec4<T>::operator+=(const Vec4<T>& vec) 
{
	x = (x + vec.x); y = (y + vec.y); z = (z + vec.z); w = (w + vec.w); return *this;
}
template <typename T>
inline Vec4<T>& Vec4<T>::operator-=(const Vec4<T>& vec) 
{
	x = (x - vec.x); y = (y - vec.y); z = (z - vec.z); w = (w - vec.w); return *this;
}
template <typename T>
inline Vec4<T>& Vec4<T>::operator*=(const Vec4<T>& vec) 
{
	x = (x * vec.x); y = (y * vec.y); z = (z * vec.z); w = (w * vec.w); return *this;
}
template <typename T>
inline Vec4<T>& Vec4<T>::operator/=(const Vec4<T>& vec) 
{
	x = (x / vec.x); y = (y / vec.y); z = (z / vec.z); w = (w / vec.w); return *this;
}
template <typename T>
inline Vec4<T>& Vec4<T>::operator+=(T v) 
{
	x = (x + v); y = (y + v); z = (z + v); w = (w + v); return *this;
}
template <typename T>
inline Vec4<T>& Vec4<T>::operator-=(T v) 
{
	x = (x - v); y = (y - v); z = (z - v); w = (w - v); return *this;
}
template <typename T>
inline Vec4<T>& Vec4<T>::operator*=(T v) 
{
	x = (x * v); y = (y * v); z = (z * v); w = (w * v); return *this;
}
template <typename T>
inline Vec4<T>& Vec4<T>::operator/=(T v) 
{
	x = (x / v); y = (y / v); z = (z / v); w = (w / v); return *this;
}
template <typename T>
inline bool Vec4<T>::operator==(const Vec4<T>& vec) const 
{
	return (x == vec.x && y == vec.y && z == vec.z && w == vec.w);
}
template <typename T>
inline bool Vec4<T>::operator!=(const Vec4<T>& vec) const 
{
	return (x != vec.x || y != vec.y || z != vec.z || w != vec.w);
}
template <typename T>
inline bool Vec4<T>::operator==(const T& v) const 
{
	return (x == v && y == v && z == v && w == v);
}
template <typename T>
inline bool Vec4<T>::operator!=(const T& v) const 
{
	return (x != v || y != v || z != v || w != v);
}

template <typename T>
template <typename U>
inline bool Vec4<T>::equals(const Vec4<U>& vec) const
{
	return (x == vec.x && y == vec.y && z == vec.z && w == vec.w);
}
template <typename T>
template <typename U>
inline bool Vec4<T>::notEquals(const Vec4<U>& vec) const
{
	return (x != vec.x || y != vec.y || z != vec.z || w != vec.w);
}
template <typename T>
template <typename U>
inline bool Vec4<T>::equals(U _x, U _y, U _z, U _w) const
{
	return (x == _x && y == _y && z == _z && w == _w);
}
template <typename T>
template <typename U>
inline bool Vec4<T>::notEquals(U _x, U _y, U _z, U _w) const
{
	return (x != _x || y != _y || z != _z || w != _w);
}

template <typename T>
inline Vec4<T>& Vec4<T>::set(T value) 
{
	this->x = (value); this->y = (value); this->z = (value); this->w = (value); return *this;
}
template <typename T>
inline Vec4<T>& Vec4<T>::set(T _x, T _y) 
{
	this->x = (_x); this->y = (_y); return *this;
}
template <typename T>
inline Vec4<T>& Vec4<T>::set(T _x, T _y, T _z) 
{
	this->x = (_x); this->y = (_y); this->z = (_z); return *this;
}
template <typename T>
inline Vec4<T>& Vec4<T>::set(T _x, T _y, T _z, T _w) 
{
	this->x = (_x); this->y = (_y); this->z = (_z); this->w = (_w); return *this;
}
template <typename T>
template <typename U>
Vec3<U> Vec4<T>::toVec3(Vec4<T>::Vec3Order order) const
{
	switch(order)
	{
		default:
		case XYZ: return Vec3<U>(x, y, z);
		case XZY: return Vec3<U>(x, z, y);
		case YXZ: return Vec3<U>(y, x, z);
		case YZX: return Vec3<U>(y, z, x);
		case ZXY: return Vec3<U>(z, x, y);
		case ZYX: return Vec3<U>(z, y, x);
	}
}

template <typename T>
inline Vec4<T> operator+(T v, const Vec4<T>& vec)
{
	return Vec4<T>(v + vec.x, v + vec.y, v + vec.z, v + vec.w);
}

template <typename T>
inline Vec4<T> operator-(T v, const Vec4<T>& vec)
{
	return Vec4<T>(v - vec.x, v - vec.y, v - vec.z, v - vec.w);
}

template <typename T>
inline Vec4<T> operator*(T v, const Vec4<T>& vec)
{
	return Vec4<T>(v * vec.x, v * vec.y, v * vec.z, v * vec.w);
}

template <typename T>
inline Vec4<T> operator/(T v, const Vec4<T>& vec)
{
	return Vec4<T>(v / vec.x, v / vec.y, v / vec.z, v / vec.w);
}


template <typename T>
Vec4<T> Vec4<T>::filled(T v) { return Vec4<T>(v, v, v, v); }
template <typename T>
const Vec4<T> Vec4<T>::Zero((T)0, (T)0, (T)0, (T)0);
template <typename T>
const Vec4<T> Vec4<T>::Identity((T)1, (T)1, (T)1, (T)1);
template <typename T>
Vec4<T> Vec4<T>::Default((T)0, (T)0, (T)0, (T)0);

} // namespace axl.math
} // namespace axl
