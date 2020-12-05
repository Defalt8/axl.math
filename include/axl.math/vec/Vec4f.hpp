#pragma once
#include "../lib.hpp"
#include "../Rules.hpp"
#include "Vec2f.hpp"
#include "Vec3f.hpp"

namespace axl {
namespace math {

class AXLMATHCXXAPI Vec4f
{
	public:
		Vec4f(float x = Default.x, float y = Default.y, float z = Default.z, float w = Default.w);
		Vec4f(const Vec4f& vec);
		Vec4f(const Vec2f& vec, float z = Default.z, float w = Default.w);
		Vec4f(const Vec3f& vec, float w = Default.w);
	public:
		Vec4f operator+() const;
		Vec4f operator-() const;
		Vec4f operator+(const Vec4f& vec) const;
		Vec4f operator-(const Vec4f& vec) const;
		Vec4f operator*(const Vec4f& vec) const;
		Vec4f operator/(const Vec4f& vec) const;
		Vec4f operator+(float v) const;
		Vec4f operator-(float v) const;
		Vec4f operator*(float v) const;
		Vec4f operator/(float v) const;
		Vec4f& operator+=(const Vec4f& vec);
		Vec4f& operator-=(const Vec4f& vec);
		Vec4f& operator*=(const Vec4f& vec);
		Vec4f& operator/=(const Vec4f& vec);
		Vec4f& operator+=(float v);
		Vec4f& operator-=(float v);
		Vec4f& operator*=(float v);
		Vec4f& operator/=(float v);
		bool operator==(const Vec4f& vec) const;
		bool operator!=(const Vec4f& vec) const;
		bool operator==(const float& v) const;
		bool operator!=(const float& v) const;
	public:
		bool isNan() const;
		bool hasNan() const;
		bool hasNoNan() const;
		bool equals(const Vec4f& vec, float epsilon = 0.001f) const;
		bool notEquals(const Vec4f& vec, float epsilon = 0.001f) const;
		bool equals(float x, float y, float z, float w, float epsilon = 0.001f) const;
		bool notEquals(float x, float y, float z, float w, float epsilon = 0.001f) const;
	public:
		Vec4f& set(float value);
		Vec4f& set(float x, float y);
		Vec4f& set(float x, float y, float z);
		Vec4f& set(float x, float y, float z, float w);
	public:
		float magn() const;
		Vec4f norm() const;
		Vec4f& normalize();
		float dot(const Vec4f& vec) const;
	public:
		Vec4f& scale(float scale_all);
		Vec4f& scale(float scale_x, float scale_y, float scale_z, float scale_w);
		Vec4f scaled(float scale_all) const;
		Vec4f scaled(float scale_x, float scale_y, float scale_z, float scale_w) const;
		Vec4f& translate(float delta_x, float delta_y, float delta_z, float delta_w);
		Vec4f& translate(const Vec4f& delta);
		Vec4f translated(float delta_x, float delta_y, float delta_z, float delta_w) const;
		Vec4f translated(const Vec4f& delta) const;
	public:
		static Vec4f filled(float v);
		const static Vec4f Zero;
		const static Vec4f Identity;
		static Vec4f Default;
		static Rules::Axis DefaultAxisRule;
	public:
		float x, y, z, w;
};

Vec4f operator+(float v, const Vec4f& vec);
Vec4f operator-(float v, const Vec4f& vec);
Vec4f operator*(float v, const Vec4f& vec);
Vec4f operator/(float v, const Vec4f& vec);

} // namespace axl.math
} // namespace axl