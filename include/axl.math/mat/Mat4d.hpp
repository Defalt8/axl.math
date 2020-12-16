#pragma once
#include "../lib.hpp"
#include "../vec/Vec4f.hpp"
#include "../vec/Vec4d.hpp"

namespace axl {
namespace math {

class Mat4f;

class AXLMATHCXXAPI Mat4d
{
	public:
		Mat4d(double diag_v);
		Mat4d(double c0, double c1, double c2, double c3, double c4, double c5, double c6, double c7, double c8, double c9, double c10, double c11, double c12, double c13, double c14, double c15);
		Mat4d(const Mat4d& mat = Default);
		Mat4d(const Mat4f& mat);
	public:
		double* operator[](int index);
		const double* operator[](int index) const;
		Mat4d operator+(const Mat4d& mat) const;
		Mat4d operator-(const Mat4d& mat) const;
		Mat4d scMul(const Mat4d& mat) const;
		Mat4d scDiv(const Mat4d& mat) const;
		Mat4d operator*(const Mat4d& mat) const;
		Mat4d operator+(double v) const;
		Mat4d operator-(double v) const;
		Mat4d operator*(double v) const;
		Mat4d operator/(double v) const;
		Mat4d& operator+=(const Mat4d& mat);
		Mat4d& operator-=(const Mat4d& mat);
		Mat4d& operator*=(const Mat4d& mat);
		Mat4d& operator+=(double v);
		Mat4d& operator-=(double v);
		Mat4d& operator*=(double v);
		Mat4d& operator/=(double v);
		Vec4d operator*(const Vec4d& vec) const;
		Vec4f operator*(const Vec4f& vec) const;
		bool operator==(const Mat4d& mat) const;
		bool operator!=(const Mat4d& mat) const;
		bool operator==(double v) const;
		bool operator!=(double v) const;
	public:
		bool isNan() const;
		bool isNotNan() const;
		bool hasNan() const;
		bool hasNoNan() const;
		bool equals(const Mat4d& mat, double epsilon = 0.000001) const;
		bool notEquals(const Mat4d& mat, double epsilon = 0.000001) const;
		bool equals(double c0, double c1, double c2, double c3, double c4, double c5, double c6, double c7, double c8, double c9, double c10, double c11, double c12, double c13, double c14, double c15, double epsilon = 0.000001) const;
		bool notEquals(double c0, double c1, double c2, double c3, double c4, double c5, double c6, double c7, double c8, double c9, double c10, double c11, double c12, double c13, double c14, double c15, double epsilon = 0.000001) const;
	public:
		const double& at(int column_index, int row_index) const;
		double& at(int column_index, int row_index);
		Mat4d& set(double c0, double c1, double c2, double c3, double c4, double c5, double c6, double c7, double c8, double c9, double c10, double c11, double c12, double c13, double c14, double c15);
		Mat4d& set(const double pv[16]);
		void setValue(int column_index, int row_index, double v);
		Mat4d transpose() const;
	public:
		static Mat4d filled(double v);
		const static Mat4d Identity;
		const static Mat4d Zero;
		const static Mat4d Nan;
		static Mat4d Default;
	public:
		double values[16];
};

} // namespace axl.math
} // namespace axl
