#include <cmath>
#include <axl.math/float.hpp>
#include <axl.math/mat/Mat2f.hpp>
#include <axl.math/mat/Mat2d.hpp>

namespace axl {
namespace math {

Mat2f::Mat2f(float v) 
{
	values[0] = v;
	values[1] = 0.0f;
	values[2] = 0.0f;
	values[3] = v;
}

Mat2f::Mat2f(float c0, float c1, float c2, float c3)
{
	values[0] = c0;
	values[1] = c1;
	values[2] = c2;
	values[3] = c3;
}

Mat2f::Mat2f(const Mat2f& mat)
{
	values[0] = mat.values[0];
	values[1] = mat.values[1];
	values[2] = mat.values[2];
	values[3] = mat.values[3];
}

Mat2f::Mat2f(const Mat2d& mat)
{
	values[0] = (float)mat.values[0];
	values[1] = (float)mat.values[1];
	values[2] = (float)mat.values[2];
	values[3] = (float)mat.values[3];
}

float* Mat2f::operator[](int index)
{
	return &values[index * 2];
}
const float* Mat2f::operator[](int index) const
{
	return &values[index * 2];
}

Mat2f Mat2f::operator+(const Mat2f& mat) const
{
	return Mat2f(
		values[0] + mat.values[0],
		values[1] + mat.values[1],
		values[2] + mat.values[2],
		values[3] + mat.values[3]
	);
}

Mat2f Mat2f::operator-(const Mat2f& mat) const
{
	return Mat2f(
		values[0] - mat.values[0],
		values[1] - mat.values[1],
		values[2] - mat.values[2],
		values[3] - mat.values[3]
	);
}

Mat2f Mat2f::scMul(const Mat2f& mat) const
{
	return Mat2f(
		values[0] * mat.values[0],
		values[1] * mat.values[1],
		values[2] * mat.values[2],
		values[3] * mat.values[3]
	);
}

Mat2f Mat2f::scDiv(const Mat2f& mat) const
{
	return Mat2f(
		values[0] / mat.values[0],
		values[1] / mat.values[1],
		values[2] / mat.values[2],
		values[3] / mat.values[3]
	);
}

Mat2f Mat2f::operator*(const Mat2f& mat) const
{
	return Mat2f(
		values[0] * mat.values[0] + values[2] * mat.values[1],
		values[1] * mat.values[0] + values[3] * mat.values[1], 
		values[0] * mat.values[2] + values[2] * mat.values[3],
		values[1] * mat.values[2] + values[3] * mat.values[3]
	);
}

Mat2f Mat2f::operator/(const Mat2f& mat) const
{
	Mat2f imat = mat.inverse();
	if(imat.hasNan())
		return Mat2f::Nan;
	return Mat2f(
		values[0] * imat.values[0] + values[2] * imat.values[1],
		values[1] * imat.values[0] + values[3] * imat.values[1], 
		values[0] * imat.values[2] + values[2] * imat.values[3],
		values[1] * imat.values[2] + values[3] * imat.values[3]
	);
}

Mat2f Mat2f::operator+(float v) const
{
	return Mat2f(values[0] + v, values[1] + v, values[2] + v, values[3] + v);
}

Mat2f Mat2f::operator-(float v) const
{
	return Mat2f(values[0] - v, values[1] - v, values[2] - v, values[3] - v);
}

Mat2f Mat2f::operator*(float v) const
{
	return Mat2f(values[0] * v, values[1] * v, values[2] * v, values[3] * v);
}

Mat2f Mat2f::operator/(float v) const
{
	return Mat2f(values[0] / v, values[1] / v, values[2] / v, values[3] / v);
}

Mat2f& Mat2f::operator+=(const Mat2f& mat)
{
	values[0] += mat.values[0];
	values[1] += mat.values[1];
	values[2] += mat.values[2];
	values[3] += mat.values[3];
	return *this;
}

Mat2f& Mat2f::operator-=(const Mat2f& mat)
{
	values[0] -= mat.values[0];
	values[1] -= mat.values[1];
	values[2] -= mat.values[2];
	values[3] -= mat.values[3];
	return *this;
}

Mat2f& Mat2f::operator*=(const Mat2f& mat)
{
	this->set(
		values[0] * mat.values[0] + values[2] * mat.values[1],
		values[1] * mat.values[0] + values[3] * mat.values[1],
		values[0] * mat.values[2] + values[2] * mat.values[3],
		values[1] * mat.values[2] + values[3] * mat.values[3]
	);
	return *this;
}

Mat2f& Mat2f::operator/=(const Mat2f& mat)
{
	Mat2f imat = mat.inverse();
	this->set(
		values[0] * imat.values[0] + values[2] * imat.values[1],
		values[1] * imat.values[0] + values[3] * imat.values[1], 
		values[0] * imat.values[2] + values[2] * imat.values[3],
		values[1] * imat.values[2] + values[3] * imat.values[3]
	);
	return *this;
}

Mat2f& Mat2f::operator+=(float v)
{
	values[0] += v;
	values[1] += v;
	values[2] += v;
	values[3] += v;
	return *this;
}

Mat2f& Mat2f::operator-=(float v)
{
	values[0] -= v;
	values[1] -= v;
	values[2] -= v;
	values[3] -= v;
	return *this;
}

Mat2f& Mat2f::operator*=(float v)
{
	values[0] *= v;
	values[1] *= v;
	values[2] *= v;
	values[3] *= v;
	return *this;
}

Mat2f& Mat2f::operator/=(float v)
{
	values[0] /= v;
	values[1] /= v;
	values[2] /= v;
	values[3] /= v;
	return *this;
}

Vec2f Mat2f::operator*(const Vec2f& vec) const
{
	return Vec2f((values[0]*vec.x + values[2]*vec.y), (values[1]*vec.x + values[3]*vec.y));
}

Vec2d Mat2f::operator*(const Vec2d& vec) const
{
	return Vec2d((values[0]*vec.x + values[2]*vec.y), (values[1]*vec.x + values[3]*vec.y));
}

bool Mat2f::operator==(const Mat2f& mat) const
{
	return (values[0] == mat.values[0] && values[1] == mat.values[1] && values[2] == mat.values[2] && values[3] == mat.values[3]);
}

bool Mat2f::operator!=(const Mat2f& mat) const
{
	return (values[0] != mat.values[0] || values[1] != mat.values[1] || values[2] != mat.values[2] || values[3] != mat.values[3]);
}

bool Mat2f::operator==(float v) const
{
	return (values[0] == v && values[1] == v && values[2] == v && values[3] == v);
}

bool Mat2f::operator!=(float v) const
{
	return (values[0] != v || values[1] != v || values[2] != v || values[3] != v);
}

bool Mat2f::isNan() const
{
	return Float::isNan(values[0]) && Float::isNan(values[1]) && Float::isNan(values[2]) && Float::isNan(values[3]);
}

bool Mat2f::hasNan() const
{
	return Float::isNan(values[0]) || Float::isNan(values[1]) || Float::isNan(values[2]) || Float::isNan(values[3]);
}

bool Mat2f::equals(const Mat2f& mat, float epsilon) const
{
	return (
		axl::math::Float::equals(values[0], mat.values[0], epsilon) &&
		axl::math::Float::equals(values[1], mat.values[1], epsilon) &&
		axl::math::Float::equals(values[2], mat.values[2], epsilon) &&
		axl::math::Float::equals(values[3], mat.values[3], epsilon)
	);
}

bool Mat2f::notEquals(const Mat2f& mat, float epsilon) const
{
	return (
		!axl::math::Float::equals(values[0], mat.values[0], epsilon) ||
		!axl::math::Float::equals(values[1], mat.values[1], epsilon) ||
		!axl::math::Float::equals(values[2], mat.values[2], epsilon) ||
		!axl::math::Float::equals(values[3], mat.values[3], epsilon)
	);
}

bool Mat2f::equals(float c0, float c1, float c2, float c3, float epsilon) const
{
	return (
		axl::math::Float::equals(values[0], c0, epsilon) &&
		axl::math::Float::equals(values[1], c1, epsilon) &&
		axl::math::Float::equals(values[2], c2, epsilon) &&
		axl::math::Float::equals(values[3], c3, epsilon)
	);
}

bool Mat2f::notEquals(float c0, float c1, float c2, float c3, float epsilon) const
{
	return (
		!axl::math::Float::equals(values[0], c0, epsilon) ||
		!axl::math::Float::equals(values[1], c1, epsilon) ||
		!axl::math::Float::equals(values[2], c2, epsilon) ||
		!axl::math::Float::equals(values[3], c3, epsilon)
	);
}

const float& Mat2f::at(int column_index, int row_index) const
{
	return values[column_index * 2 + row_index];
}

float& Mat2f::at(int column_index, int row_index)
{
	return values[column_index * 2 + row_index];
}


Mat2f& Mat2f::set(float c0, float c1, float c2, float c3)
{
	values[0] = c0;
	values[1] = c1;
	values[2] = c2;
	values[3] = c3;
	return *this;
}

Mat2f& Mat2f::set(const float pv[4])
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

void Mat2f::setValue(int column_index, int row_index, float v)
{
	values[column_index * 2 + row_index] = v;
}

bool Mat2f::isInvertible() const
{
	return !this->hasNan() && (values[0] * values[3] - values[1] * values[2]) != 0.0f;
}

float Mat2f::determinant() const
{
	return (values[0] * values[3] - values[2] * values[1]);
}

Mat2f Mat2f::transpose() const
{
	return Mat2f(values[0], values[2], values[1], values[3]);
}

Mat2f Mat2f::inverse() const
{
	float ad_bc = (values[0] * values[3] - values[1] * values[2]);
	if(ad_bc == 0.0f) return Mat2f::filled(Float::Nan);
	return Mat2f( values[3]/ad_bc, -values[1]/ad_bc, -values[2]/ad_bc, values[0]/ad_bc );
}

Mat2f Mat2f::filled(float v)
{
	return Mat2f(v, v, v, v);
}

const Mat2f Mat2f::Identity(1.0f, 0.0f, 0.0f, 1.0f);
const Mat2f Mat2f::Zero(0.0f, 0.0f, 0.0f, 0.0f);
const Mat2f Mat2f::Nan(Float::Nan, Float::Nan, Float::Nan, Float::Nan);
Mat2f Mat2f::Default(0.0f, 0.0f, 0.0f, 0.0f);

} // namespace axl.math
} // namespace axl