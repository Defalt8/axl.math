#pragma once
#include "rules.hpp"

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
		T magn() const;
		Vec2<T> norm() const;
		Vec2<T>& normalize();
		T dot(const Vec2<T>& vec) const;
		T cross(const Vec2<T>& vec) const;
		T angle(Rules::Axis axis_rule = DefaultAxisRule) const;
		T angle(const Vec2<T>& ref_vec, Rules::Axis axis_rule = DefaultAxisRule) const;
		T fullAngle(Rules::Axis axis_rule = DefaultAxisRule) const;
		T fullAngle(const Vec2<T>& ref_vec, Rules::Axis axis_rule = DefaultAxisRule) const;
	public:
		Vec2<T>& scale(T scale_all);
		Vec2<T>& scale(T scale_x, T scale_y);
		Vec2<T> scaled(T scale_all) const;
		Vec2<T> scaled(T scale_x, T scale_y) const;
		Vec2<T>& translate(T delta_x, T delta_y);
		Vec2<T>& translate(const Vec2<T>& delta);
		Vec2<T> translated(T delta_x, T delta_y) const;
		Vec2<T> translated(const Vec2<T>& delta) const;
		Vec2<T>& rotate(T theta_z, Rules::Axis axis_rule = DefaultAxisRule);
		Vec2<T> rotated(T theta_z, Rules::Axis axis_rule = DefaultAxisRule) const;
	public:
		const static Vec2<T> Zero;
		const static Vec2<T> Identity;
		static Vec2<T> Default;
		static Rules::Axis DefaultAxisRule;
	public:
		T x, y;
};

} // namespace math
} // namespace axl
#include "Vec2.inl"