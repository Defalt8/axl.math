#pragma once
#include "lib.hpp"
#include "rules.hpp"

namespace axl {
namespace math {

class AXLMATHCXXAPI Vec2f
{
	public:
		Vec2f(float x = Default.x, float y = Default.y);
		Vec2f(const Vec2f& vec);
	public:
		Vec2f operator+() const;
		Vec2f operator-() const;
		Vec2f operator+(const Vec2f& vec) const;
		Vec2f operator-(const Vec2f& vec) const;
		Vec2f operator*(const Vec2f& vec) const;
		Vec2f operator/(const Vec2f& vec) const;
		Vec2f operator+(float v) const;
		Vec2f operator-(float v) const;
		Vec2f operator*(float v) const;
		Vec2f operator/(float v) const;
		Vec2f& operator+=(const Vec2f& vec);
		Vec2f& operator-=(const Vec2f& vec);
		Vec2f& operator*=(const Vec2f& vec);
		Vec2f& operator/=(const Vec2f& vec);
		Vec2f& operator+=(float v);
		Vec2f& operator-=(float v);
		Vec2f& operator*=(float v);
		Vec2f& operator/=(float v);
		bool operator==(const Vec2f& vec) const;
		bool operator!=(const Vec2f& vec) const;
		bool operator==(const float& v) const;
		bool operator!=(const float& v) const;
	public:
		Vec2f& set(float value);
		Vec2f& set(float x, float y);
		bool isNan() const;
		bool hasNan() const;
		bool hasNoNan() const;
		bool equals(const Vec2f& vec, float epsilon = 0.001f) const;
		bool notEquals(const Vec2f& vec, float epsilon = 0.001f) const;
		bool equals(float x, float y, float epsilon = 0.001f) const;
		bool notEquals(float x, float y, float epsilon = 0.001f) const;
	public:
		float magn() const;
		Vec2f norm() const;
		Vec2f& normalize();
		float dot(const Vec2f& vec) const;
		float cross(const Vec2f& vec) const;
		float angle(Rules::Axis axis_rule = DefaultAxisRule) const;
		float angle(const Vec2f& ref_vec, Rules::Axis axis_rule = DefaultAxisRule) const;
		float fullAngle(Rules::Axis axis_rule = DefaultAxisRule) const;
		float fullAngle(const Vec2f& ref_vec, Rules::Axis axis_rule = DefaultAxisRule) const;
	public:
		Vec2f& scale(float scale_all);
		Vec2f& scale(float scale_x, float scale_y);
		Vec2f scaled(float scale_all) const;
		Vec2f scaled(float scale_x, float scale_y) const;
		Vec2f& translate(float delta_x, float delta_y);
		Vec2f& translate(const Vec2f& delta);
		Vec2f translated(float delta_x, float delta_y) const;
		Vec2f translated(const Vec2f& delta) const;
		Vec2f& rotate(float theta_z, Rules::Axis axis_rule = DefaultAxisRule);
		Vec2f rotated(float theta_z, Rules::Axis axis_rule = DefaultAxisRule) const;
	public:
		const static Vec2f Zero;
		const static Vec2f Identity;
		static Vec2f Default;
		static Rules::Axis DefaultAxisRule;
	public:
		float x, y;
};

} // namespace math
} // namespace axl