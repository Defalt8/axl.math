#pragma once
#include "../lib.hpp"
#include "../rules.hpp"
#include "Vec2f.hpp"

namespace axl {
namespace math {

class AXLMATHCXXAPI Vec3f
{
	public:
		Vec3f(float x = Default.x, float y = Default.y, float z = Default.z);
		Vec3f(const Vec3f& vec);
		Vec3f(const Vec2f& vec, float z = Default.z);
	public:
		Vec3f operator+() const;
		Vec3f operator-() const;
		Vec3f operator+(const Vec3f& vec) const;
		Vec3f operator-(const Vec3f& vec) const;
		Vec3f operator*(const Vec3f& vec) const;
		Vec3f operator/(const Vec3f& vec) const;
		Vec3f operator+(float v) const;
		Vec3f operator-(float v) const;
		Vec3f operator*(float v) const;
		Vec3f operator/(float v) const;
		Vec3f& operator+=(const Vec3f& vec);
		Vec3f& operator-=(const Vec3f& vec);
		Vec3f& operator*=(const Vec3f& vec);
		Vec3f& operator/=(const Vec3f& vec);
		Vec3f& operator+=(float v);
		Vec3f& operator-=(float v);
		Vec3f& operator*=(float v);
		Vec3f& operator/=(float v);
		bool operator==(const Vec3f& vec) const;
		bool operator!=(const Vec3f& vec) const;
		bool operator==(const float& v) const;
		bool operator!=(const float& v) const;
	public:
		Vec3f& set(float value);
		Vec3f& set(float x, float y);
		Vec3f& set(float x, float y, float z);
		bool isNan() const;
		bool hasNan() const;
		bool hasNoNan() const;
		bool equals(const Vec3f& vec, float epsilon = 0.001f) const;
		bool notEquals(const Vec3f& vec, float epsilon = 0.001f) const;
		bool equals(float x, float y, float z, float epsilon = 0.001f) const;
		bool notEquals(float x, float y, float z, float epsilon = 0.001f) const;
	public:
		float magn() const;
		Vec3f norm() const;
		Vec3f& normalize();
		float dot(const Vec3f& vec) const;
		Vec3f cross(const Vec3f& vec, Rules::Axis axis_rule = DefaultAxisRule) const;
		Vec3f euler(Rules::Axis axis_rule = DefaultAxisRule) const;
		Vec3f euler(const Vec3f& ref_vec, Rules::Axis axis_rule = DefaultAxisRule) const;
	public:
		Vec3f& scale(float scale_all);
		Vec3f& scale(float scale_x, float scale_y, float scale_z);
		Vec3f scaled(float scale_all) const;
		Vec3f scaled(float scale_x, float scale_y, float scale_z) const;
		Vec3f& translate(float delta_x, float delta_y, float delta_z);
		Vec3f& translate(const Vec3f& delta);
		Vec3f translated(float delta_x, float delta_y, float delta_z) const;
		Vec3f translated(const Vec3f& delta) const;
		Vec3f& rotate(float angle_x, float angle_y, float angle_z, Rules::Axis axis_rule = DefaultAxisRule);
		Vec3f& rotate(const Vec3f& angle_vec, Rules::Axis axis_rule = DefaultAxisRule);
		Vec3f& rotateX(float angle_x, Rules::Axis axis_rule = DefaultAxisRule);
		Vec3f& rotateY(float angle_y, Rules::Axis axis_rule = DefaultAxisRule);
		Vec3f& rotateZ(float angle_z, Rules::Axis axis_rule = DefaultAxisRule);
		Vec3f rotated(float angle_x, float angle_y, float angle_z, Rules::Axis axis_rule = DefaultAxisRule) const;
		Vec3f rotated(const Vec3f& angle_vec, Rules::Axis axis_rule = DefaultAxisRule) const;
		Vec3f rotatedX(float angle_x, Rules::Axis axis_rule = DefaultAxisRule);
		Vec3f rotatedY(float angle_y, Rules::Axis axis_rule = DefaultAxisRule);
		Vec3f rotatedZ(float angle_z, Rules::Axis axis_rule = DefaultAxisRule);
	public:
		static Vec3f filled(float v);
		const static Vec3f Zero;
		const static Vec3f Identity;
		static Vec3f Default;
		static Rules::Axis DefaultAxisRule;
	public:
		float x, y, z;
};

Vec3f AXLMATHAPI operator+(float v, const Vec3f& vec);
Vec3f AXLMATHAPI operator-(float v, const Vec3f& vec);
Vec3f AXLMATHAPI operator*(float v, const Vec3f& vec);
Vec3f AXLMATHAPI operator/(float v, const Vec3f& vec);

} // namespace axl.math
} // namespace axl