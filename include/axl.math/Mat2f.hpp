#pragma once
#include "lib.hpp"
#include "Vec2f.hpp"

namespace axl {
namespace math {

class AXLMATHCXXAPI Mat2f
{
	public:
		Mat2f(float diag_v = 1.0f);
		Mat2f(float c0, float c1, float c2, float c3);
		Mat2f(const Mat2f& mat);
	public:
		float* operator[](int index);
		const float* operator[](int index) const;
		Mat2f operator+(const Mat2f& mat) const;
		Mat2f operator-(const Mat2f& mat) const;
		Mat2f scMul(const Mat2f& mat) const;
		Mat2f scDiv(const Mat2f& mat) const;
		Mat2f operator*(const Mat2f& mat) const;
		Mat2f operator/(const Mat2f& mat) const;
		Mat2f operator+(float v) const;
		Mat2f operator-(float v) const;
		Mat2f operator*(float v) const;
		Mat2f operator/(float v) const;
		Mat2f& operator+=(const Mat2f& mat);
		Mat2f& operator-=(const Mat2f& mat);
		Mat2f& operator*=(const Mat2f& mat);
		Mat2f& operator/=(const Mat2f& mat);
		Mat2f& operator+=(float v);
		Mat2f& operator-=(float v);
		Mat2f& operator*=(float v);
		Mat2f& operator/=(float v);
		Vec2f operator*(const Vec2f& vec) const;
		bool operator==(const Mat2f& mat) const;
		bool operator!=(const Mat2f& mat) const;
		bool operator==(float v) const;
		bool operator!=(float v) const;
	public:
		bool isNan() const;
		bool hasNan() const;
		bool equals(const Mat2f& mat, float epsilon = 0.001f) const;
		bool notEquals(const Mat2f& mat, float epsilon = 0.001f) const;
		bool equals(float c0, float c1, float c2, float c3, float epsilon = 0.001f) const;
		bool notEquals(float c0, float c1, float c2, float c3, float epsilon = 0.001f) const;
	public:
		const float& at(int column_index, int row_index) const;
		float& at(int column_index, int row_index);
		Mat2f& set(float c0, float c1, float c2, float c3);
		Mat2f& set(const float pv[4]);
		void setValue(int column_index, int row_index, float v);
		bool isInvertible() const;
		Mat2f inverse() const;
	public:
		static Mat2f filled(float v);
		const static Mat2f Identity;
		const static Mat2f Zero;
		const static Mat2f Nan;
	public:
		float values[4];
};

} // namespace axl.math
} // namespace axl
