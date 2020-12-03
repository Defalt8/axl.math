#pragma once
#include "../lib.hpp"
#include "../vec/Vec2d.hpp"
#include "../vec/Vec2f.hpp"

namespace axl {
namespace math {

class Mat2f;

// Column-major 2x2 matrix
class AXLMATHCXXAPI Mat2d
{
	public:
		Mat2d(double diag_v);
		Mat2d(double c0, double c1, double c2, double c3);
		Mat2d(const Mat2d& mat = Default);
		Mat2d(const Mat2f& mat);
	public:
		double* operator[](int index);
		const double* operator[](int index) const;
		Mat2d operator+(const Mat2d& mat) const;
		Mat2d operator-(const Mat2d& mat) const;
		Mat2d scMul(const Mat2d& mat) const;
		Mat2d scDiv(const Mat2d& mat) const;
		Mat2d operator*(const Mat2d& mat) const;
		Mat2d operator/(const Mat2d& mat) const;
		Mat2d operator+(double v) const;
		Mat2d operator-(double v) const;
		Mat2d operator*(double v) const;
		Mat2d operator/(double v) const;
		Mat2d& operator+=(const Mat2d& mat);
		Mat2d& operator-=(const Mat2d& mat);
		Mat2d& operator*=(const Mat2d& mat);
		Mat2d& operator/=(const Mat2d& mat);
		Mat2d& operator+=(double v);
		Mat2d& operator-=(double v);
		Mat2d& operator*=(double v);
		Mat2d& operator/=(double v);
		Vec2d operator*(const Vec2d& vec) const;
		Vec2f operator*(const Vec2f& vec) const;
		bool operator==(const Mat2d& mat) const;
		bool operator!=(const Mat2d& mat) const;
		bool operator==(double v) const;
		bool operator!=(double v) const;
	public:
		bool isNan() const;
		bool isNotNan() const;
		bool hasNan() const;
		bool hasNoNan() const;
		bool equals(const Mat2d& mat, double epsilon = 0.000001) const;
		bool notEquals(const Mat2d& mat, double epsilon = 0.000001) const;
		bool equals(double c0, double c1, double c2, double c3, double epsilon = 0.000001) const;
		bool notEquals(double c0, double c1, double c2, double c3, double epsilon = 0.000001) const;
	public:
		const double& at(int column_index, int row_index) const;
		double& at(int column_index, int row_index);
		Mat2d& set(double c0, double c1, double c2, double c3);
		Mat2d& set(const double pv[4]);
		void setValue(int column_index, int row_index, double v);
		bool isInvertible() const;
		double determinant() const;
		Mat2d transpose() const;
		Mat2d inverse() const;
	public:
		static Mat2d filled(double v);
		const static Mat2d Identity;
		const static Mat2d Zero;
		const static Mat2d Nan;
		static Mat2d Default;
	public:
		double values[4];
};

} // namespace axl.math
} // namespace axl
