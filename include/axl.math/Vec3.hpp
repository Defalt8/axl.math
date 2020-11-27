#pragma once
#include "Vec2.hpp"

namespace axl {
namespace math {

template <typename T>
class Vec3
{
	public:
		Vec3(T x = Default.x, T y = Default.y, T z = Default.z);
		template <typename U>
		Vec3(U x, U y, U z);
		template <typename U>
		Vec3(const Vec3<U>& vec);
		template <typename U>
		Vec3(const Vec2<U>& vec, T z = Default.z);
	public:
		Vec3<T> operator+() const;
		Vec3<T> operator-() const;
		Vec3<T> operator+(const Vec3<T>& vec) const;
		Vec3<T> operator-(const Vec3<T>& vec) const;
		Vec3<T> operator*(const Vec3<T>& vec) const;
		Vec3<T> operator/(const Vec3<T>& vec) const;
		Vec3<T> operator+(T v) const;
		Vec3<T> operator-(T v) const;
		Vec3<T> operator*(T v) const;
		Vec3<T> operator/(T v) const;
		Vec3<T>& operator+=(const Vec3<T>& vec);
		Vec3<T>& operator-=(const Vec3<T>& vec);
		Vec3<T>& operator*=(const Vec3<T>& vec);
		Vec3<T>& operator/=(const Vec3<T>& vec);
		Vec3<T>& operator+=(T v);
		Vec3<T>& operator-=(T v);
		Vec3<T>& operator*=(T v);
		Vec3<T>& operator/=(T v);
		bool operator==(const Vec3<T>& vec) const;
		bool operator!=(const Vec3<T>& vec) const;
		bool operator==(const T& v) const;
		bool operator!=(const T& v) const;
	public:
		template <typename U>
		bool equals(const Vec3<U>& vec) const;
		template <typename U>
		bool notEquals(const Vec3<U>& vec) const;
		template <typename U>
		bool equals(U x, U y, U z) const;
		template <typename U>
		bool notEquals(U x, U y, U z) const;
	public:
		Vec3<T>& set(T value);
		Vec3<T>& set(T x, T y);
		Vec3<T>& set(T x, T y, T z);
	public:
		const static Vec3<T> Zero;
		const static Vec3<T> Identity;
		static Vec3<T> Default;
	public:
		T x, y, z;
};

} // namespace axl.math
} // namespace axl
#include "Vec3.inl"