#pragma once

namespace axl {
namespace math {

template <typename T>
class Vec2
{
	public:
		Vec2(T x = Default.x, T y = Default.y);
		Vec2(const Vec2<T>& vec);
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
		Vec2<T>& set(T value);
		Vec2<T>& set(T x, T y);
		bool isNan() const;
		bool hasNan() const;
		bool hasNoNan() const;
		bool equals(const Vec2<T>& vec, T epsilon = 0.0000001) const;
		bool notEquals(const Vec2<T>& vec, T epsilon = 0.0000001) const;
		bool equals(T x, T y, T epsilon = 0.0000001) const;
		bool notEquals(T x, T y, T epsilon = 0.0000001) const;
	public:
		const static Vec2<T> Zero;
		const static Vec2<T> Identity;
		static Vec2<T> Default;
	public:
		T x, y;
};

} // namespace math
} // namespace axl
#include "Vec2.inl"