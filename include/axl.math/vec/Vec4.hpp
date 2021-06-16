#pragma once
#include "Vec2.hpp"
#include "Vec3.hpp"
#include "Vec4.hpp"

namespace axl {
namespace math {

template <typename T>
class Vec4
{
	public:
		enum Vec3Order { XYZ, XZY, YXZ, YZX, ZXY, ZYX };
	public:
		Vec4(T x = Default.x, T y = Default.y, T z = Default.z, T w = Default.w);
		template <typename U>
		Vec4(U x, U y, U z, U w);
		template <typename U>
		Vec4(const Vec4<U>& vec);
		template <typename U>
		Vec4(const Vec2<U>& vec, T z = Default.z, T w = Default.w);
		template <typename U>
		Vec4(const Vec3<U>& vec, T w = Default.w);
	public:
		Vec4<T> operator+() const;
		Vec4<T> operator-() const;
		Vec4<T> operator+(const Vec4<T>& vec) const;
		Vec4<T> operator-(const Vec4<T>& vec) const;
		Vec4<T> operator*(const Vec4<T>& vec) const;
		Vec4<T> operator/(const Vec4<T>& vec) const;
		Vec4<T> operator+(T v) const;
		Vec4<T> operator-(T v) const;
		Vec4<T> operator*(T v) const;
		Vec4<T> operator/(T v) const;
		Vec4<T>& operator+=(const Vec4<T>& vec);
		Vec4<T>& operator-=(const Vec4<T>& vec);
		Vec4<T>& operator*=(const Vec4<T>& vec);
		Vec4<T>& operator/=(const Vec4<T>& vec);
		Vec4<T>& operator+=(T v);
		Vec4<T>& operator-=(T v);
		Vec4<T>& operator*=(T v);
		Vec4<T>& operator/=(T v);
		bool operator==(const Vec4<T>& vec) const;
		bool operator!=(const Vec4<T>& vec) const;
		bool operator==(const T& v) const;
		bool operator!=(const T& v) const;
	public:
		template <typename U>
		bool equals(const Vec4<U>& vec) const;
		template <typename U>
		bool notEquals(const Vec4<U>& vec) const;
		template <typename U>
		bool equals(U x, U y, U z, U w) const;
		template <typename U>
		bool notEquals(U x, U y, U z, U w) const;
	public:
		Vec4<T>& set(T value);
		Vec4<T>& set(T x, T y);
		Vec4<T>& set(T x, T y, T z);
		Vec4<T>& set(T x, T y, T z, T w);
	public:
		template <typename U = T>
		Vec3<U> toVec3(Vec3Order order = XYZ) const;
	public:
		static Vec4<T> filled(T v);
		const static Vec4<T> Zero;
		const static Vec4<T> Identity;
		static Vec4<T> Default;
	public:
		T x, y, z, w;
};

} // namespace axl.math
} // namespace axl
#include "Vec4.inl"