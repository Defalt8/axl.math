#include <cmath>
#include <axl.math/float.hpp>
#include <axl.math/mat/Mat3f.hpp>
#include <axl.math/mat/Mat3d.hpp>

namespace axl {
namespace math {

Mat3f::Mat3f(float v) 
{
	values[0] = v;
	values[1] = 0.0f;
	values[2] = 0.0f;
	values[3] = 0.0f;
	values[4] = v;
	values[5] = 0.0f;
	values[6] = 0.0f;
	values[7] = 0.0f;
	values[8] = v;
}

Mat3f::Mat3f(float c0, float c1, float c2, float c3, float c4, float c5, float c6, float c7, float c8)
{
	values[0] = c0;
	values[1] = c1;
	values[2] = c2;
	values[3] = c3;
	values[4] = c4;
	values[5] = c5;
	values[6] = c6;
	values[7] = c7;
	values[8] = c8;
}

Mat3f::Mat3f(const Mat3f& mat)
{
	values[0] = mat.values[0];
	values[1] = mat.values[1];
	values[2] = mat.values[2];
	values[3] = mat.values[3];
	values[4] = mat.values[4];
	values[5] = mat.values[5];
	values[6] = mat.values[6];
	values[7] = mat.values[7];
	values[8] = mat.values[8];
}

Mat3f::Mat3f(const Mat3d& mat)
{
	values[0] = (float)mat.values[0];
	values[1] = (float)mat.values[1];
	values[2] = (float)mat.values[2];
	values[3] = (float)mat.values[3];
	values[4] = (float)mat.values[4];
	values[5] = (float)mat.values[5];
	values[6] = (float)mat.values[6];
	values[7] = (float)mat.values[7];
	values[8] = (float)mat.values[8];
}

float* Mat3f::operator[](int index)
{
	return &values[index * 3];
}
const float* Mat3f::operator[](int index) const
{
	return &values[index * 3];
}

Mat3f Mat3f::operator+(const Mat3f& mat) const
{
	return Mat3f(
		values[0] + mat.values[0],
		values[1] + mat.values[1],
		values[2] + mat.values[2],
		values[3] + mat.values[3],
		values[4] + mat.values[4],
		values[5] + mat.values[5],
		values[6] + mat.values[6],
		values[7] + mat.values[7],
		values[8] + mat.values[8]
	);
}

Mat3f Mat3f::operator-(const Mat3f& mat) const
{
	return Mat3f(
		values[0] - mat.values[0],
		values[1] - mat.values[1],
		values[2] - mat.values[2],
		values[3] - mat.values[3],
		values[4] - mat.values[4],
		values[5] - mat.values[5],
		values[6] - mat.values[6],
		values[7] - mat.values[7],
		values[8] - mat.values[8]
	);
}

Mat3f Mat3f::scMul(const Mat3f& mat) const
{
	return Mat3f(
		values[0] * mat.values[0],
		values[1] * mat.values[1],
		values[2] * mat.values[2],
		values[3] * mat.values[3],
		values[4] * mat.values[4],
		values[5] * mat.values[5],
		values[6] * mat.values[6],
		values[7] * mat.values[7],
		values[8] * mat.values[8]
	);
}

Mat3f Mat3f::scDiv(const Mat3f& mat) const
{
	return Mat3f(
		values[0] / mat.values[0],
		values[1] / mat.values[1],
		values[2] / mat.values[2],
		values[3] / mat.values[3],
		values[4] / mat.values[4],
		values[5] / mat.values[5],
		values[6] / mat.values[6],
		values[7] / mat.values[7],
		values[8] / mat.values[8]
	);
}

Mat3f Mat3f::operator*(const Mat3f& mat) const
{
	return Mat3f(
		values[0] * mat.values[0] + values[3] * mat.values[1] + values[6] * mat.values[2],
		values[1] * mat.values[0] + values[4] * mat.values[1] + values[7] * mat.values[2],
		values[2] * mat.values[0] + values[5] * mat.values[1] + values[8] * mat.values[2],
		values[0] * mat.values[3] + values[3] * mat.values[4] + values[6] * mat.values[5],
		values[1] * mat.values[3] + values[4] * mat.values[4] + values[7] * mat.values[5],
		values[2] * mat.values[3] + values[5] * mat.values[4] + values[8] * mat.values[5],
		values[0] * mat.values[6] + values[3] * mat.values[7] + values[6] * mat.values[8],
		values[1] * mat.values[6] + values[4] * mat.values[7] + values[7] * mat.values[8],
		values[2] * mat.values[6] + values[5] * mat.values[7] + values[8] * mat.values[8]
	);
}

Mat3f Mat3f::operator/(const Mat3f& mat) const
{
	Mat3f imat = mat.inverse();
	if(imat.hasNan())
		return Mat3f::Nan;
	return (*this) * imat;
}

Mat3f Mat3f::operator+(float v) const
{
	return Mat3f(
		values[0] + v, values[1] + v, values[2] + v,
		values[3] + v, values[4] + v, values[5] + v,
		values[6] + v, values[7] + v, values[8] + v
	);
}

Mat3f Mat3f::operator-(float v) const
{
	return Mat3f(
		values[0] - v, values[1] - v, values[2] - v,
		values[3] - v, values[4] - v, values[5] - v,
		values[6] - v, values[7] - v, values[8] - v
	);
}

Mat3f Mat3f::operator*(float v) const
{
	return Mat3f(
		values[0] * v, values[1] * v, values[2] * v,
		values[3] * v, values[4] * v, values[5] * v,
		values[6] * v, values[7] * v, values[8] * v
	);
}

Mat3f Mat3f::operator/(float v) const
{
	return Mat3f(
		values[0] / v, values[1] / v, values[2] / v,
		values[3] / v, values[4] / v, values[5] / v,
		values[6] / v, values[7] / v, values[8] / v
	);
}

Mat3f& Mat3f::operator+=(const Mat3f& mat)
{
	values[0] += mat.values[0];
	values[1] += mat.values[1];
	values[2] += mat.values[2];
	values[3] += mat.values[3];
	values[4] += mat.values[4];
	values[5] += mat.values[5];
	values[6] += mat.values[6];
	values[7] += mat.values[7];
	values[8] += mat.values[8];
	return *this;
}

Mat3f& Mat3f::operator-=(const Mat3f& mat)
{
	values[0] -= mat.values[0];
	values[1] -= mat.values[1];
	values[2] -= mat.values[2];
	values[3] -= mat.values[3];
	values[4] -= mat.values[4];
	values[5] -= mat.values[5];
	values[6] -= mat.values[6];
	values[7] -= mat.values[7];
	values[8] -= mat.values[8];
	return *this;
}

Mat3f& Mat3f::operator*=(const Mat3f& mat)
{
	this->set(
		values[0] * mat.values[0] + values[3] * mat.values[1] + values[6] * mat.values[2],
		values[1] * mat.values[0] + values[4] * mat.values[1] + values[7] * mat.values[2],
		values[2] * mat.values[0] + values[5] * mat.values[1] + values[8] * mat.values[2],
		values[0] * mat.values[3] + values[3] * mat.values[4] + values[6] * mat.values[5],
		values[1] * mat.values[3] + values[4] * mat.values[4] + values[7] * mat.values[5],
		values[2] * mat.values[3] + values[5] * mat.values[4] + values[8] * mat.values[5],
		values[0] * mat.values[6] + values[3] * mat.values[7] + values[6] * mat.values[8],
		values[1] * mat.values[6] + values[4] * mat.values[7] + values[7] * mat.values[8],
		values[2] * mat.values[6] + values[5] * mat.values[7] + values[8] * mat.values[8]
	);
	return *this;
}

Mat3f& Mat3f::operator/=(const Mat3f& mat)
{
	Mat3f imat = mat.inverse();
	if(imat.hasNan())
		return ((*this) = Mat3f::Nan);
	return (*this) *= imat;
}

Mat3f& Mat3f::operator+=(float v)
{
	values[0] += v;
	values[1] += v;
	values[2] += v;
	values[3] += v;
	values[4] += v;
	values[5] += v;
	values[6] += v;
	values[7] += v;
	values[8] += v;
	return *this;
}

Mat3f& Mat3f::operator-=(float v)
{
	values[0] -= v;
	values[1] -= v;
	values[2] -= v;
	values[3] -= v;
	values[4] -= v;
	values[5] -= v;
	values[6] -= v;
	values[7] -= v;
	values[8] -= v;
	return *this;
}

Mat3f& Mat3f::operator*=(float v)
{
	values[0] *= v;
	values[1] *= v;
	values[2] *= v;
	values[3] *= v;
	values[4] *= v;
	values[5] *= v;
	values[6] *= v;
	values[7] *= v;
	values[8] *= v;
	return *this;
}

Mat3f& Mat3f::operator/=(float v)
{
	values[0] /= v;
	values[1] /= v;
	values[2] /= v;
	values[3] /= v;
	values[4] /= v;
	values[5] /= v;
	values[6] /= v;
	values[7] /= v;
	values[8] /= v;
	return *this;
}

Vec3f Mat3f::operator*(const Vec3f& vec) const
{
	return Vec3f(
		(values[0]*vec.x + values[3]*vec.y + values[6]*vec.z),
		(values[1]*vec.x + values[4]*vec.y + values[7]*vec.z),
		(values[2]*vec.x + values[5]*vec.y + values[8]*vec.z)
	);
}

bool Mat3f::operator==(const Mat3f& mat) const
{
	return (
		values[0] == mat.values[0] && values[1] == mat.values[1] && values[2] == mat.values[2] &&
		values[3] == mat.values[3] && values[4] == mat.values[4] && values[5] == mat.values[5] &&
		values[6] == mat.values[6] && values[7] == mat.values[7] && values[8] == mat.values[8]
	);
}

bool Mat3f::operator!=(const Mat3f& mat) const
{
	return (
		values[0] != mat.values[0] || values[1] != mat.values[1] || values[2] != mat.values[2] ||
		values[3] != mat.values[3] || values[4] != mat.values[4] || values[5] != mat.values[5] ||
		values[6] != mat.values[6] || values[7] != mat.values[7] || values[8] != mat.values[8]
	);
}

bool Mat3f::operator==(float v) const
{
	return (
		values[0] == v && values[1] == v && values[2] == v &&
		values[3] == v && values[4] == v && values[5] == v &&
		values[6] == v && values[7] == v && values[8] == v
	);
}

bool Mat3f::operator!=(float v) const
{
	return (
		values[0] != v || values[1] != v || values[2] != v ||
		values[3] != v || values[4] != v || values[5] != v ||
		values[6] != v || values[7] != v || values[8] != v
	);
}

bool Mat3f::isNan() const
{
	return	Float::isNan(values[0]) && Float::isNan(values[1]) && Float::isNan(values[2]) &&
			Float::isNan(values[3]) && Float::isNan(values[4]) && Float::isNan(values[5]) &&
			Float::isNan(values[6]) && Float::isNan(values[7]) && Float::isNan(values[8]);
}

bool Mat3f::isNotNan() const
{
	return	!Float::isNan(values[0]) || !Float::isNan(values[1]) || !Float::isNan(values[2]) ||
			!Float::isNan(values[3]) || !Float::isNan(values[4]) || !Float::isNan(values[5]) ||
			!Float::isNan(values[6]) || !Float::isNan(values[7]) || !Float::isNan(values[8]);
}

bool Mat3f::hasNan() const
{
	return	Float::isNan(values[0]) || Float::isNan(values[1]) || Float::isNan(values[2]) ||
			Float::isNan(values[3]) || Float::isNan(values[4]) || Float::isNan(values[5]) ||
			Float::isNan(values[6]) || Float::isNan(values[7]) || Float::isNan(values[8]);
}

bool Mat3f::hasNoNan() const
{
	return	!Float::isNan(values[0]) && !Float::isNan(values[1]) && !Float::isNan(values[2]) &&
			!Float::isNan(values[3]) && !Float::isNan(values[4]) && !Float::isNan(values[5]) &&
			!Float::isNan(values[6]) && !Float::isNan(values[7]) && !Float::isNan(values[8]);
}

bool Mat3f::equals(const Mat3f& mat, float epsilon) const
{
	return (
		axl::math::Float::equals(values[0], mat.values[0], epsilon) &&
		axl::math::Float::equals(values[1], mat.values[1], epsilon) &&
		axl::math::Float::equals(values[2], mat.values[2], epsilon) &&
		axl::math::Float::equals(values[3], mat.values[3], epsilon) &&
		axl::math::Float::equals(values[4], mat.values[4], epsilon) &&
		axl::math::Float::equals(values[5], mat.values[5], epsilon) &&
		axl::math::Float::equals(values[6], mat.values[6], epsilon) &&
		axl::math::Float::equals(values[7], mat.values[7], epsilon) &&
		axl::math::Float::equals(values[8], mat.values[8], epsilon)
	);
}

bool Mat3f::notEquals(const Mat3f& mat, float epsilon) const
{
	return (
		!axl::math::Float::equals(values[0], mat.values[0], epsilon) ||
		!axl::math::Float::equals(values[1], mat.values[1], epsilon) ||
		!axl::math::Float::equals(values[2], mat.values[2], epsilon) ||
		!axl::math::Float::equals(values[3], mat.values[3], epsilon) ||
		!axl::math::Float::equals(values[4], mat.values[4], epsilon) ||
		!axl::math::Float::equals(values[5], mat.values[5], epsilon) ||
		!axl::math::Float::equals(values[6], mat.values[6], epsilon) ||
		!axl::math::Float::equals(values[7], mat.values[7], epsilon) ||
		!axl::math::Float::equals(values[8], mat.values[8], epsilon)
	);
}

bool Mat3f::equals(float c0, float c1, float c2, float c3, float c4, float c5, float c6, float c7, float c8, float epsilon) const
{
	return (
		axl::math::Float::equals(values[0], c0, epsilon) &&
		axl::math::Float::equals(values[1], c1, epsilon) &&
		axl::math::Float::equals(values[2], c2, epsilon) &&
		axl::math::Float::equals(values[3], c3, epsilon) &&
		axl::math::Float::equals(values[4], c4, epsilon) &&
		axl::math::Float::equals(values[5], c5, epsilon) &&
		axl::math::Float::equals(values[6], c6, epsilon) &&
		axl::math::Float::equals(values[7], c7, epsilon) &&
		axl::math::Float::equals(values[8], c8, epsilon)
	);
}

bool Mat3f::notEquals(float c0, float c1, float c2, float c3, float c4, float c5, float c6, float c7, float c8, float epsilon) const
{
	return (
		!axl::math::Float::equals(values[0], c0, epsilon) ||
		!axl::math::Float::equals(values[1], c1, epsilon) ||
		!axl::math::Float::equals(values[2], c2, epsilon) ||
		!axl::math::Float::equals(values[3], c3, epsilon) ||
		!axl::math::Float::equals(values[4], c4, epsilon) ||
		!axl::math::Float::equals(values[5], c5, epsilon) ||
		!axl::math::Float::equals(values[6], c6, epsilon) ||
		!axl::math::Float::equals(values[7], c7, epsilon) ||
		!axl::math::Float::equals(values[8], c8, epsilon)
	);
}

const float& Mat3f::at(int column_index, int row_index) const
{
	return values[column_index * 3 + row_index];
}

float& Mat3f::at(int column_index, int row_index)
{
	return values[column_index * 3 + row_index];
}


Mat3f& Mat3f::set(float c0, float c1, float c2, float c3, float c4, float c5, float c6, float c7, float c8)
{
	values[0] = c0;
	values[1] = c1;
	values[2] = c2;
	values[3] = c3;
	values[4] = c4;
	values[5] = c5;
	values[6] = c6;
	values[7] = c7;
	values[8] = c8;
	return *this;
}

Mat3f& Mat3f::set(const float pv[9])
{
	if(pv)
	{
		values[0] = pv[0];
		values[1] = pv[1];
		values[2] = pv[2];
		values[3] = pv[3];
		values[4] = pv[4];
		values[5] = pv[5];
		values[6] = pv[6];
		values[7] = pv[7];
		values[8] = pv[8];
	}
	return *this;
}

void Mat3f::setValue(int column_index, int row_index, float v)
{
	values[column_index * 3 + row_index] = v;
}

bool Mat3f::isInvertible() const
{
	const float ae_bd = (values[0] * values[4] - values[1] * values[3]);
	const float ae_bdei_fh_ce_bfeg_dh = (ae_bd * (values[4] * values[8] - values[5] * values[7]) - (values[2] * values[4] - values[1] * values[5]) * (values[4] * values[6] - values[3] * values[7]));
	const float ei_fh = (values[4] * values[8] - values[5] * values[7]);
	return !this->hasNan() && (ae_bd != 0.0f && ei_fh != 0.0f && ae_bdei_fh_ce_bfeg_dh != 0.0f);
}

float Mat3f::determinant() const
{
	return (
		 (values[0]*(values[4]*values[8]-values[7]*values[5]))
		-(values[3]*(values[1]*values[8]-values[7]*values[2]))
		+(values[6]*(values[1]*values[5]-values[4]*values[2]))
	);
}

Mat3f Mat3f::minorDet() const
{
	float r0 = (values[4]*values[8]-values[7]*values[5]);
	float r1 = (values[3]*values[8]-values[6]*values[5]);
	float r2 = (values[3]*values[7]-values[6]*values[4]);
	float r3 = (values[1]*values[8]-values[7]*values[2]);
	float r4 = (values[0]*values[8]-values[6]*values[2]);
	float r5 = (values[0]*values[7]-values[6]*values[1]);
	float r6 = (values[1]*values[5]-values[4]*values[2]);
	float r7 = (values[0]*values[5]-values[3]*values[2]);
	float r8 = (values[0]*values[4]-values[3]*values[1]);
	return Mat3f(r0, r1, r2, r3, r4, r5, r6, r7, r8);
}

Mat3f Mat3f::transpose() const
{
	return Mat3f(
		values[0], values[3], values[6],
		values[1], values[4], values[7],
		values[2], values[5], values[8]
	);
}

Mat3f Mat3f::inverse() const
{
	if(this->hasNan())
		return Mat3f::Nan;
	const float det = this->determinant();
	if (det == 0.0f)
		return Mat3f::Nan;
	float r0 =  (values[4]*values[8]-values[7]*values[5]) / det;
	float r1 = -(values[3]*values[8]-values[6]*values[5]) / det;
	float r2 =  (values[3]*values[7]-values[6]*values[4]) / det;
	float r3 = -(values[1]*values[8]-values[7]*values[2]) / det;
	float r4 =  (values[0]*values[8]-values[6]*values[2]) / det;
	float r5 = -(values[0]*values[7]-values[6]*values[1]) / det;
	float r6 =  (values[1]*values[5]-values[4]*values[2]) / det;
	float r7 = -(values[0]*values[5]-values[3]*values[2]) / det;
	float r8 =  (values[0]*values[4]-values[3]*values[1]) / det;
	return Mat3f(r0, r3, r6, r1, r4, r7, r2, r5, r8);
}

Mat3f Mat3f::filled(float v)
{
	return Mat3f(v, v, v, v, v, v, v, v, v);
}

const Mat3f Mat3f::Identity(1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
const Mat3f Mat3f::Zero(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
const Mat3f Mat3f::Nan(Float::Nan, Float::Nan, Float::Nan, Float::Nan, Float::Nan, Float::Nan, Float::Nan, Float::Nan, Float::Nan);
Mat3f Mat3f::Default(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);

} // namespace axl.math
} // namespace axl