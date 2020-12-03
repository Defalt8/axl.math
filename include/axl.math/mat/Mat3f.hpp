#pragma once
#include "../lib.hpp"
#include "../vec/Vec3f.hpp"
#include "../vec/Vec3d.hpp"

namespace axl {
namespace math {

class Mat3d;

class AXLMATHCXXAPI Mat3f
{
	public:
		Mat3f(float diag_v);
		Mat3f(float c0, float c1, float c2, float c3, float c4, float c5, float c6, float c7, float c8);
		Mat3f(const Mat3f& mat = Default);
		Mat3f(const Mat3d& mat);
	public:
		float* operator[](int index);
		const float* operator[](int index) const;
		Mat3f operator+(const Mat3f& mat) const;
		Mat3f operator-(const Mat3f& mat) const;
		Mat3f scMul(const Mat3f& mat) const;
		Mat3f scDiv(const Mat3f& mat) const;
		Mat3f operator*(const Mat3f& mat) const;
		Mat3f operator/(const Mat3f& mat) const;
		Mat3f operator+(float v) const;
		Mat3f operator-(float v) const;
		Mat3f operator*(float v) const;
		Mat3f operator/(float v) const;
		Mat3f& operator+=(const Mat3f& mat);
		Mat3f& operator-=(const Mat3f& mat);
		Mat3f& operator*=(const Mat3f& mat);
		Mat3f& operator/=(const Mat3f& mat);
		Mat3f& operator+=(float v);
		Mat3f& operator-=(float v);
		Mat3f& operator*=(float v);
		Mat3f& operator/=(float v);
		Vec3f operator*(const Vec3f& vec) const;
		bool operator==(const Mat3f& mat) const;
		bool operator!=(const Mat3f& mat) const;
		bool operator==(float v) const;
		bool operator!=(float v) const;
	public:
		bool isNan() const;
		bool isNotNan() const;
		bool hasNan() const;
		bool hasNoNan() const;
		bool equals(const Mat3f& mat, float epsilon = 0.001f) const;
		bool notEquals(const Mat3f& mat, float epsilon = 0.001f) const;
		bool equals(float c0, float c1, float c2, float c3, float c4, float c5, float c6, float c7, float c8, float epsilon = 0.001f) const;
		bool notEquals(float c0, float c1, float c2, float c3, float c4, float c5, float c6, float c7, float c8, float epsilon = 0.001f) const;
	public:
		const float& at(int column_index, int row_index) const;
		float& at(int column_index, int row_index);
		Mat3f& set(float c0, float c1, float c2, float c3, float c4, float c5, float c6, float c7, float c8);
		Mat3f& set(const float pv[9]);
		void setValue(int column_index, int row_index, float v);
		bool isInvertible() const;
		float determinant() const;
		Mat3f minorDet() const;
		Mat3f transpose() const;
		Mat3f inverse() const;
	public:
		static Mat3f filled(float v);
		const static Mat3f Identity;
		const static Mat3f Zero;
		const static Mat3f Nan;
		static Mat3f Default;
	public:
		float values[9];
};

} // namespace axl.math
} // namespace axl
