#include <cmath>
#include <axl.math/double.hpp>
#include <axl.math/Mat2d.hpp>
#include <axl.math/Mat2f.hpp>

namespace axl {
namespace math {

Mat2d::Mat2d(double v) 
{
	values[0] = v;
	values[1] = 0.0;
	values[2] = 0.0;
	values[3] = v;
}

Mat2d::Mat2d(double c0, double c1, double c2, double c3)
{
	values[0] = c0;
	values[1] = c1;
	values[2] = c2;
	values[3] = c3;
}

Mat2d::Mat2d(const Mat2d& mat)
{
	values[0] = mat.values[0];
	values[1] = mat.values[1];
	values[2] = mat.values[2];
	values[3] = mat.values[3];
}

Mat2d::Mat2d(const Mat2f& mat)
{
	values[0] = mat.values[0];
	values[1] = mat.values[1];
	values[2] = mat.values[2];
	values[3] = mat.values[3];
}

double* Mat2d::operator[](int index)
{
	return &values[index * 2];
}
const double* Mat2d::operator[](int index) const
{
	return &values[index * 2];
}

Mat2d Mat2d::operator+(const Mat2d& mat) const
{
	return Mat2d(
		values[0] + mat.values[0],
		values[1] + mat.values[1],
		values[2] + mat.values[2],
		values[3] + mat.values[3]
	);
}

Mat2d Mat2d::operator-(const Mat2d& mat) const
{
	return Mat2d(
		values[0] - mat.values[0],
		values[1] - mat.values[1],
		values[2] - mat.values[2],
		values[3] - mat.values[3]
	);
}

Mat2d Mat2d::scMul(const Mat2d& mat) const
{
	return Mat2d(
		values[0] * mat.values[0],
		values[1] * mat.values[1],
		values[2] * mat.values[2],
		values[3] * mat.values[3]
	);
}

Mat2d Mat2d::scDiv(const Mat2d& mat) const
{
	return Mat2d(
		values[0] / mat.values[0],
		values[1] / mat.values[1],
		values[2] / mat.values[2],
		values[3] / mat.values[3]
	);
}

Mat2d Mat2d::operator*(const Mat2d& mat) const
{
	return Mat2d(
		values[0] * mat.values[0] + values[2] * mat.values[1],
		values[1] * mat.values[0] + values[3] * mat.values[1], 
		values[0] * mat.values[2] + values[2] * mat.values[3],
		values[1] * mat.values[2] + values[3] * mat.values[3]
	);
}

Mat2d Mat2d::operator/(const Mat2d& mat) const
{
	Mat2d imat = mat.inverse();
	if(imat.hasNan())
		return Mat2d::Nan;
	return Mat2d(
		values[0] * imat.values[0] + values[2] * imat.values[1],
		values[1] * imat.values[0] + values[3] * imat.values[1], 
		values[0] * imat.values[2] + values[2] * imat.values[3],
		values[1] * imat.values[2] + values[3] * imat.values[3]
	);
}

Mat2d Mat2d::operator+(double v) const
{
	return Mat2d(values[0] + v, values[1] + v, values[2] + v, values[3] + v);
}

Mat2d Mat2d::operator-(double v) const
{
	return Mat2d(values[0] - v, values[1] - v, values[2] - v, values[3] - v);
}

Mat2d Mat2d::operator*(double v) const
{
	return Mat2d(values[0] * v, values[1] * v, values[2] * v, values[3] * v);
}

Mat2d Mat2d::operator/(double v) const
{
	return Mat2d(values[0] / v, values[1] / v, values[2] / v, values[3] / v);
}

Mat2d& Mat2d::operator+=(const Mat2d& mat)
{
	values[0] += mat.values[0];
	values[1] += mat.values[1];
	values[2] += mat.values[2];
	values[3] += mat.values[3];
	return *this;
}

Mat2d& Mat2d::operator-=(const Mat2d& mat)
{
	values[0] -= mat.values[0];
	values[1] -= mat.values[1];
	values[2] -= mat.values[2];
	values[3] -= mat.values[3];
	return *this;
}

Mat2d& Mat2d::operator*=(const Mat2d& mat)
{
	this->set(
		values[0] * mat.values[0] + values[2] * mat.values[1],
		values[1] * mat.values[0] + values[3] * mat.values[1],
		values[0] * mat.values[2] + values[2] * mat.values[3],
		values[1] * mat.values[2] + values[3] * mat.values[3]
	);
	return *this;
}

Mat2d& Mat2d::operator/=(const Mat2d& mat)
{
	Mat2d imat = mat.inverse();
	this->set(
		values[0] * imat.values[0] + values[2] * imat.values[1],
		values[1] * imat.values[0] + values[3] * imat.values[1], 
		values[0] * imat.values[2] + values[2] * imat.values[3],
		values[1] * imat.values[2] + values[3] * imat.values[3]
	);
	return *this;
}

Mat2d& Mat2d::operator+=(double v)
{
	values[0] += v;
	values[1] += v;
	values[2] += v;
	values[3] += v;
	return *this;
}

Mat2d& Mat2d::operator-=(double v)
{
	values[0] -= v;
	values[1] -= v;
	values[2] -= v;
	values[3] -= v;
	return *this;
}

Mat2d& Mat2d::operator*=(double v)
{
	values[0] *= v;
	values[1] *= v;
	values[2] *= v;
	values[3] *= v;
	return *this;
}

Mat2d& Mat2d::operator/=(double v)
{
	values[0] /= v;
	values[1] /= v;
	values[2] /= v;
	values[3] /= v;
	return *this;
}

Vec2d Mat2d::operator*(const Vec2d& vec) const
{
	return Vec2d((values[0]*vec.x + values[2]*vec.y), (values[1]*vec.x + values[3]*vec.y));
}

Vec2f Mat2d::operator*(const Vec2f& vec) const
{
	return Vec2f((float)(values[0]*vec.x + values[2]*vec.y), (float)(values[1]*vec.x + values[3]*vec.y));
}

bool Mat2d::operator==(const Mat2d& mat) const
{
	return (values[0] == mat.values[0] && values[1] == mat.values[1] && values[2] == mat.values[2] && values[3] == mat.values[3]);
}

bool Mat2d::operator!=(const Mat2d& mat) const
{
	return (values[0] != mat.values[0] || values[1] != mat.values[1] || values[2] != mat.values[2] || values[3] != mat.values[3]);
}

bool Mat2d::operator==(double v) const
{
	return (values[0] == v && values[1] == v && values[2] == v && values[3] == v);
}

bool Mat2d::operator!=(double v) const
{
	return (values[0] != v || values[1] != v || values[2] != v || values[3] != v);
}

bool Mat2d::isNan() const
{
	return std::isnan(values[0]) && std::isnan(values[1]) && std::isnan(values[2]) && std::isnan(values[3]);
}

bool Mat2d::hasNan() const
{
	return std::isnan(values[0]) || std::isnan(values[1]) || std::isnan(values[2]) || std::isnan(values[3]);
}

bool Mat2d::equals(const Mat2d& mat, double epsilon) const
{
	return (
		axl::math::Double::equals(values[0], mat.values[0], epsilon) &&
		axl::math::Double::equals(values[1], mat.values[1], epsilon) &&
		axl::math::Double::equals(values[2], mat.values[2], epsilon) &&
		axl::math::Double::equals(values[3], mat.values[3], epsilon)
	);
}

bool Mat2d::notEquals(const Mat2d& mat, double epsilon) const
{
	return (
		!axl::math::Double::equals(values[0], mat.values[0], epsilon) ||
		!axl::math::Double::equals(values[1], mat.values[1], epsilon) ||
		!axl::math::Double::equals(values[2], mat.values[2], epsilon) ||
		!axl::math::Double::equals(values[3], mat.values[3], epsilon)
	);
}

bool Mat2d::equals(double c0, double c1, double c2, double c3, double epsilon) const
{
	return (
		axl::math::Double::equals(values[0], c0, epsilon) &&
		axl::math::Double::equals(values[1], c1, epsilon) &&
		axl::math::Double::equals(values[2], c2, epsilon) &&
		axl::math::Double::equals(values[3], c3, epsilon)
	);
}

bool Mat2d::notEquals(double c0, double c1, double c2, double c3, double epsilon) const
{
	return (
		!axl::math::Double::equals(values[0], c0, epsilon) ||
		!axl::math::Double::equals(values[1], c1, epsilon) ||
		!axl::math::Double::equals(values[2], c2, epsilon) ||
		!axl::math::Double::equals(values[3], c3, epsilon)
	);
}

const double& Mat2d::at(int column_index, int row_index) const
{
	return values[column_index * 2 + row_index];
}

double& Mat2d::at(int column_index, int row_index)
{
	return values[column_index * 2 + row_index];
}


Mat2d& Mat2d::set(double c0, double c1, double c2, double c3)
{
	values[0] = c0;
	values[1] = c1;
	values[2] = c2;
	values[3] = c3;
	return *this;
}

Mat2d& Mat2d::set(const double pv[4])
{
	if(pv)
	{
		values[0] = pv[0];
		values[1] = pv[1];
		values[2] = pv[2];
		values[3] = pv[3];
	}
	return *this;
}

void Mat2d::setValue(int column_index, int row_index, double v)
{
	values[column_index * 2 + row_index] = v;
}

bool Mat2d::isInvertible() const
{
	return !this->hasNan() && (values[0] * values[3] - values[1] * values[2]) != 0.0;
}

double Mat2d::determinant() const
{
	return (values[0] * values[3] - values[2] * values[1]);
}

Mat2d Mat2d::transpose() const
{
	return Mat2d(values[0], values[2], values[1], values[3]);
}

Mat2d Mat2d::inverse() const
{
	double ad_bc = (values[0] * values[3] - values[1] * values[2]);
	if(ad_bc == 0.0) return Mat2d::filled(Double::Nan);
	return Mat2d( values[3]/ad_bc, -values[1]/ad_bc, -values[2]/ad_bc, values[0]/ad_bc );
}

Mat2d Mat2d::filled(double v)
{
	return Mat2d(v, v, v, v);
}

const Mat2d Mat2d::Identity(1.0, 0.0, 0.0, 1.0);
const Mat2d Mat2d::Zero(0.0, 0.0, 0.0, 0.0);
const Mat2d Mat2d::Nan(Double::Nan, Double::Nan, Double::Nan, Double::Nan);
Mat2d Mat2d::Default(0.0, 0.0, 0.0, 0.0);

} // namespace axl.math
} // namespace axl