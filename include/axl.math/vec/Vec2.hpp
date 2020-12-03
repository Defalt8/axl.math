#pragma once

namespace axl {
namespace math {

template <typename T>
class Vec2
{
	public:
		Vec2(T x = Default.x, T y = Default.y);
		template <typename U>
		Vec2(U x, U y);
		template <typename U>
		Vec2(const Vec2<U>& vec);
	public:
		Vec2<T> operator+() const;
		Vec2<T> operator-() const;
		Vec2<T> operator+(const Vec2<T>& vec) const;
		Vec2<T> operator-(const Vec2<T>& vec) const;
		Vec2<T> operator*(const Vec2<T>& vec) const;
		Vec2<T> operator/(const Vec2<T>& vec) const;
		Vec2<T> operator+(T v) const;
		Vec2<T> operator-(T v) const;
		Vec2<T> operator*(T v) const;
		Vec2<T> operator/(T v) const;
		Vec2<T>& operator+=(const Vec2<T>& vec);
		Vec2<T>& operator-=(const Vec2<T>& vec);
		Vec2<T>& operator*=(const Vec2<T>& vec);
		Vec2<T>& operator/=(const Vec2<T>& vec);
		Vec2<T>& operator+=(T v);
		Vec2<T>& operator-=(T v);
		Vec2<T>& operator*=(T v);
		Vec2<T>& operator/=(T v);
		bool operator==(const Vec2<T>& vec) const;
		bool operator!=(const Vec2<T>& vec) const;
		bool operator==(const T& v) const;
		bool operator!=(const T& v) const;
	public:
		template <typename U>
		bool equals(const Vec2<U>& vec) const;
		template <typename U>
		bool notEquals(const Vec2<U>& vec) const;
		template <typename U>
		bool equals(U x, U y) const;
		template <typename U>
		bool notEquals(U x, U y) const;
	public:
		Vec2<T>& set(T value);
		Vec2<T>& set(T x, T y);
	public:
		const static Vec2<T> Zero;
		const static Vec2<T> Identity;
		static Vec2<T> Default;
	public:
		T x, y;
};

} // namespace axl.math
} // namespace axl
#include "Vec2.inl"