#pragma once
#include "../lib.hpp"
#include "../vec/Vec4f.hpp"
#include "../vec/Vec4d.hpp"

namespace axl {
namespace math {

class Mat4d;

class AXLMATHCXXAPI Mat4f
{
	public:
		Mat4f(float diag_v);
		Mat4f(float c0, float c1, float c2, float c3, float c4, float c5, float c6, float c7, float c8, float c9, float c10, float c11, float c12, float c13, float c14, float c15);
		Mat4f(const Mat4f& mat = Default);
		Mat4f(const Mat4d& mat);
	public:
		float* operator[](int index);
		const float* operator[](int index) const;
		Mat4f operator+(const Mat4f& mat) const;
		Mat4f operator-(const Mat4f& mat) const;
		Mat4f scMul(const Mat4f& mat) const;
		Mat4f scDiv(const Mat4f& mat) const;
		Mat4f operator*(const Mat4f& mat) const;
		Mat4f operator+(float v) const;
		Mat4f operator-(float v) const;
		Mat4f operator*(float v) const;
		Mat4f operator/(float v) const;
		Mat4f& operator+=(const Mat4f& mat);
		Mat4f& operator-=(const Mat4f& mat);
		Mat4f& operator*=(const Mat4f& mat);
		Mat4f& operator+=(float v);
		Mat4f& operator-=(float v);
		Mat4f& operator*=(float v);
		Mat4f& operator/=(float v);
		Vec4d operator*(const Vec4d& vec) const;
		Vec4f operator*(const Vec4f& vec) const;
		bool operator==(const Mat4f& mat) const;
		bool operator!=(const Mat4f& mat) const;
		bool operator==(float v) const;
		bool operator!=(float v) const;
	public:
		bool isNan() const;
		bool isNotNan() const;
		bool hasNan() const;
		bool hasNoNan() const;
		bool equals(const Mat4f& mat, float epsilon = 0.001f) const;
		bool notEquals(const Mat4f& mat, float epsilon = 0.001f) const;
		bool equals(float c0, float c1, float c2, float c3, float c4, float c5, float c6, float c7, float c8, float c9, float c10, float c11, float c12, float c13, float c14, float c15, float epsilon = 0.001f) const;
		bool notEquals(float c0, float c1, float c2, float c3, float c4, float c5, float c6, float c7, float c8, float c9, float c10, float c11, float c12, float c13, float c14, float c15, float epsilon = 0.001f) const;
	public:
		const float& at(int column_index, int row_index) const;
		float& at(int column_index, int row_index);
		Mat4f& set(float c0, float c1, float c2, float c3, float c4, float c5, float c6, float c7, float c8, float c9, float c10, float c11, float c12, float c13, float c14, float c15);
		Mat4f& set(const float pv[16]);
		void setValue(int column_index, int row_index, float v);
		Mat4f transpose() const;
	public:
		static Mat4f filled(float v);
		const static Mat4f Identity;
		const static Mat4f Zero;
		const static Mat4f Nan;
		static Mat4f Default;
	public:
		float values[16];
};

} // namespace axl.math
} // namespace axl
