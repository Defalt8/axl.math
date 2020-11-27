#pragma once
#include "lib.hpp"
#include "Vec3f.hpp"
#include "Vec3d.hpp"

namespace axl {
namespace math {

class Mat3f;

class AXLMATHCXXAPI Mat3d
{
	public:
		Mat3d(double diag_v);
		Mat3d(double c0, double c1, double c2, double c3, double c4, double c5, double c6, double c7, double c8);
		Mat3d(const Mat3d& mat = Default);
		Mat3d(const Mat3f& mat);
	public:
		double* operator[](int index);
		const double* operator[](int index) const;
		Mat3d operator+(const Mat3d& mat) const;
		Mat3d operator-(const Mat3d& mat) const;
		Mat3d scMul(const Mat3d& mat) const;
		Mat3d scDiv(const Mat3d& mat) const;
		Mat3d operator*(const Mat3d& mat) const;
		Mat3d operator/(const Mat3d& mat) const;
		Mat3d operator+(double v) const;
		Mat3d operator-(double v) const;
		Mat3d operator*(double v) const;
		Mat3d operator/(double v) const;
		Mat3d& operator+=(const Mat3d& mat);
		Mat3d& operator-=(const Mat3d& mat);
		Mat3d& operator*=(const Mat3d& mat);
		Mat3d& operator/=(const Mat3d& mat);
		Mat3d& operator+=(double v);
		Mat3d& operator-=(double v);
		Mat3d& operator*=(double v);
		Mat3d& operator/=(double v);
		Vec3f operator*(const Vec3f& vec) const;
		Vec3d operator*(const Vec3d& vec) const;
		bool operator==(const Mat3d& mat) const;
		bool operator!=(const Mat3d& mat) const;
		bool operator==(double v) const;
		bool operator!=(double v) const;
	public:
		bool isNan() const;
		bool isNotNan() const;
		bool hasNan() const;
		bool hasNoNan() const;
		bool equals(const Mat3d& mat, double epsilon = 0.000001) const;
		bool notEquals(const Mat3d& mat, double epsilon = 0.000001) const;
		bool equals(double c0, double c1, double c2, double c3, double c4, double c5, double c6, double c7, double c8, double epsilon = 0.000001) const;
		bool notEquals(double c0, double c1, double c2, double c3, double c4, double c5, double c6, double c7, double c8, double epsilon = 0.000001) const;
	public:
		const double& at(int column_index, int row_index) const;
		double& at(int column_index, int row_index);
		Mat3d& set(double c0, double c1, double c2, double c3, double c4, double c5, double c6, double c7, double c8);
		Mat3d& set(const double pv[9]);
		void setValue(int column_index, int row_index, double v);
		bool isInvertible() const;
		double determinant() const;
		Mat3d minorDet() const;
		Mat3d transpose() const;
		Mat3d inverse() const;
	public:
		static Mat3d filled(double v);
		const static Mat3d Identity;
		const static Mat3d Zero;
		const static Mat3d Nan;
		static Mat3d Default;
	public:
		double values[9];
};

} // namespace axl.math
} // namespace axl
