#include <cmath>
#include <axl.math/double.hpp>
#include <axl.math/Mat3d.hpp>
#include <axl.math/Mat3f.hpp>

namespace axl {
namespace math {

Mat3d::Mat3d(double v) 
{
	values[0] = v;
	values[1] = 0.0;
	values[2] = 0.0;
	values[3] = 0.0;
	values[4] = v;
	values[5] = 0.0;
	values[6] = 0.0;
	values[7] = 0.0;
	values[8] = v;
}

Mat3d::Mat3d(double c0, double c1, double c2, double c3, double c4, double c5, double c6, double c7, double c8)
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

Mat3d::Mat3d(const Mat3d& mat)
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

Mat3d::Mat3d(const Mat3f& mat)
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

double* Mat3d::operator[](int index)
{
	return &values[index * 3];
}
const double* Mat3d::operator[](int index) const
{
	return &values[index * 3];
}

Mat3d Mat3d::operator+(const Mat3d& mat) const
{
	return Mat3d(
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

Mat3d Mat3d::operator-(const Mat3d& mat) const
{
	return Mat3d(
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

Mat3d Mat3d::scMul(const Mat3d& mat) const
{
	return Mat3d(
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

Mat3d Mat3d::scDiv(const Mat3d& mat) const
{
	return Mat3d(
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

Mat3d Mat3d::operator*(const Mat3d& mat) const
{
	return Mat3d(
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

Mat3d Mat3d::operator/(const Mat3d& mat) const
{
	Mat3d imat = mat.inverse();
	if(imat.hasNan())
		return Mat3d::Nan;
	return (*this) * imat;
}

Mat3d Mat3d::operator+(double v) const
{
	return Mat3d(
		values[0] + v, values[1] + v, values[2] + v,
		values[3] + v, values[4] + v, values[5] + v,
		values[6] + v, values[7] + v, values[8] + v
	);
}

Mat3d Mat3d::operator-(double v) const
{
	return Mat3d(
		values[0] - v, values[1] - v, values[2] - v,
		values[3] - v, values[4] - v, values[5] - v,
		values[6] - v, values[7] - v, values[8] - v
	);
}

Mat3d Mat3d::operator*(double v) const
{
	return Mat3d(
		values[0] * v, values[1] * v, values[2] * v,
		values[3] * v, values[4] * v, values[5] * v,
		values[6] * v, values[7] * v, values[8] * v
	);
}

Mat3d Mat3d::operator/(double v) const
{
	return Mat3d(
		values[0] / v, values[1] / v, values[2] / v,
		values[3] / v, values[4] / v, values[5] / v,
		values[6] / v, values[7] / v, values[8] / v
	);
}

Mat3d& Mat3d::operator+=(const Mat3d& mat)
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

Mat3d& Mat3d::operator-=(const Mat3d& mat)
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

Mat3d& Mat3d::operator*=(const Mat3d& mat)
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

Mat3d& Mat3d::operator/=(const Mat3d& mat)
{
	Mat3d imat = mat.inverse();
	if(imat.hasNan())
		return ((*this) = Mat3d::Nan);
	return (*this) *= imat;
}

Mat3d& Mat3d::operator+=(double v)
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

Mat3d& Mat3d::operator-=(double v)
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

Mat3d& Mat3d::operator*=(double v)
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

Mat3d& Mat3d::operator/=(double v)
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

Vec3f Mat3d::operator*(const Vec3f& vec) const
{
	return Vec3f(
		(float)(values[0]*vec.x + values[3]*vec.y + values[6]*vec.z),
		(float)(values[1]*vec.x + values[4]*vec.y + values[7]*vec.z),
		(float)(values[2]*vec.x + values[5]*vec.y + values[8]*vec.z)
	);
}

bool Mat3d::operator==(const Mat3d& mat) const
{
	return (
		values[0] == mat.values[0] && values[1] == mat.values[1] && values[2] == mat.values[2] &&
		values[3] == mat.values[3] && values[4] == mat.values[4] && values[5] == mat.values[5] &&
		values[6] == mat.values[6] && values[7] == mat.values[7] && values[8] == mat.values[8]
	);
}

bool Mat3d::operator!=(const Mat3d& mat) const
{
	return (
		values[0] != mat.values[0] || values[1] != mat.values[1] || values[2] != mat.values[2] ||
		values[3] != mat.values[3] || values[4] != mat.values[4] || values[5] != mat.values[5] ||
		values[6] != mat.values[6] || values[7] != mat.values[7] || values[8] != mat.values[8]
	);
}

bool Mat3d::operator==(double v) const
{
	return (
		values[0] == v && values[1] == v && values[2] == v &&
		values[3] == v && values[4] == v && values[5] == v &&
		values[6] == v && values[7] == v && values[8] == v
	);
}

bool Mat3d::operator!=(double v) const
{
	return (
		values[0] != v || values[1] != v || values[2] != v ||
		values[3] != v || values[4] != v || values[5] != v ||
		values[6] != v || values[7] != v || values[8] != v
	);
}

bool Mat3d::isNan() const
{
	return	std::isnan(values[0]) && std::isnan(values[1]) && std::isnan(values[2]) &&
			std::isnan(values[3]) && std::isnan(values[4]) && std::isnan(values[5]) &&
			std::isnan(values[6]) && std::isnan(values[7]) && std::isnan(values[8]);
}

bool Mat3d::isNotNan() const
{
	return	!std::isnan(values[0]) || !std::isnan(values[1]) || !std::isnan(values[2]) ||
			!std::isnan(values[3]) || !std::isnan(values[4]) || !std::isnan(values[5]) ||
			!std::isnan(values[6]) || !std::isnan(values[7]) || !std::isnan(values[8]);
}

bool Mat3d::hasNan() const
{
	return	std::isnan(values[0]) || std::isnan(values[1]) || std::isnan(values[2]) ||
			std::isnan(values[3]) || std::isnan(values[4]) || std::isnan(values[5]) ||
			std::isnan(values[6]) || std::isnan(values[7]) || std::isnan(values[8]);
}

bool Mat3d::hasNoNan() const
{
	return	!std::isnan(values[0]) && !std::isnan(values[1]) && !std::isnan(values[2]) &&
			!std::isnan(values[3]) && !std::isnan(values[4]) && !std::isnan(values[5]) &&
			!std::isnan(values[6]) && !std::isnan(values[7]) && !std::isnan(values[8]);
}

bool Mat3d::equals(const Mat3d& mat, double epsilon) const
{
	return (
		axl::math::Double::equals(values[0], mat.values[0], epsilon) &&
		axl::math::Double::equals(values[1], mat.values[1], epsilon) &&
		axl::math::Double::equals(values[2], mat.values[2], epsilon) &&
		axl::math::Double::equals(values[3], mat.values[3], epsilon) &&
		axl::math::Double::equals(values[4], mat.values[4], epsilon) &&
		axl::math::Double::equals(values[5], mat.values[5], epsilon) &&
		axl::math::Double::equals(values[6], mat.values[6], epsilon) &&
		axl::math::Double::equals(values[7], mat.values[7], epsilon) &&
		axl::math::Double::equals(values[8], mat.values[8], epsilon)
	);
}

bool Mat3d::notEquals(const Mat3d& mat, double epsilon) const
{
	return (
		!axl::math::Double::equals(values[0], mat.values[0], epsilon) ||
		!axl::math::Double::equals(values[1], mat.values[1], epsilon) ||
		!axl::math::Double::equals(values[2], mat.values[2], epsilon) ||
		!axl::math::Double::equals(values[3], mat.values[3], epsilon) ||
		!axl::math::Double::equals(values[4], mat.values[4], epsilon) ||
		!axl::math::Double::equals(values[5], mat.values[5], epsilon) ||
		!axl::math::Double::equals(values[6], mat.values[6], epsilon) ||
		!axl::math::Double::equals(values[7], mat.values[7], epsilon) ||
		!axl::math::Double::equals(values[8], mat.values[8], epsilon)
	);
}

bool Mat3d::equals(double c0, double c1, double c2, double c3, double c4, double c5, double c6, double c7, double c8, double epsilon) const
{
	return (
		axl::math::Double::equals(values[0], c0, epsilon) &&
		axl::math::Double::equals(values[1], c1, epsilon) &&
		axl::math::Double::equals(values[2], c2, epsilon) &&
		axl::math::Double::equals(values[3], c3, epsilon) &&
		axl::math::Double::equals(values[4], c4, epsilon) &&
		axl::math::Double::equals(values[5], c5, epsilon) &&
		axl::math::Double::equals(values[6], c6, epsilon) &&
		axl::math::Double::equals(values[7], c7, epsilon) &&
		axl::math::Double::equals(values[8], c8, epsilon)
	);
}

bool Mat3d::notEquals(double c0, double c1, double c2, double c3, double c4, double c5, double c6, double c7, double c8, double epsilon) const
{
	return (
		!axl::math::Double::equals(values[0], c0, epsilon) ||
		!axl::math::Double::equals(values[1], c1, epsilon) ||
		!axl::math::Double::equals(values[2], c2, epsilon) ||
		!axl::math::Double::equals(values[3], c3, epsilon) ||
		!axl::math::Double::equals(values[4], c4, epsilon) ||
		!axl::math::Double::equals(values[5], c5, epsilon) ||
		!axl::math::Double::equals(values[6], c6, epsilon) ||
		!axl::math::Double::equals(values[7], c7, epsilon) ||
		!axl::math::Double::equals(values[8], c8, epsilon)
	);
}

const double& Mat3d::at(int column_index, int row_index) const
{
	return values[column_index * 3 + row_index];
}

double& Mat3d::at(int column_index, int row_index)
{
	return values[column_index * 3 + row_index];
}


Mat3d& Mat3d::set(double c0, double c1, double c2, double c3, double c4, double c5, double c6, double c7, double c8)
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

Mat3d& Mat3d::set(const double pv[9])
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

void Mat3d::setValue(int column_index, int row_index, double v)
{
	values[column_index * 3 + row_index] = v;
}

bool Mat3d::isInvertible() const
{
	const double ae_bd = (values[0] * values[4] - values[1] * values[3]);
	const double ae_bdei_fh_ce_bfeg_dh = (ae_bd * (values[4] * values[8] - values[5] * values[7]) - (values[2] * values[4] - values[1] * values[5]) * (values[4] * values[6] - values[3] * values[7]));
	const double ei_fh = (values[4] * values[8] - values[5] * values[7]);
	return !this->hasNan() && (ae_bd != 0.0 && ei_fh != 0.0 && ae_bdei_fh_ce_bfeg_dh != 0.0);
}

double Mat3d::determinant() const
{
	return (
		 (values[0]*(values[4]*values[8]-values[7]*values[5]))
		-(values[3]*(values[1]*values[8]-values[7]*values[2]))
		+(values[6]*(values[1]*values[5]-values[4]*values[2]))
	);
}

Mat3d Mat3d::minorDet() const
{
	double r0 = (values[4]*values[8]-values[7]*values[5]);
	double r1 = (values[3]*values[8]-values[6]*values[5]);
	double r2 = (values[3]*values[7]-values[6]*values[4]);
	double r3 = (values[1]*values[8]-values[7]*values[2]);
	double r4 = (values[0]*values[8]-values[6]*values[2]);
	double r5 = (values[0]*values[7]-values[6]*values[1]);
	double r6 = (values[1]*values[5]-values[4]*values[2]);
	double r7 = (values[0]*values[5]-values[3]*values[2]);
	double r8 = (values[0]*values[4]-values[3]*values[1]);
	return Mat3d(r0, r1, r2, r3, r4, r5, r6, r7, r8);
}

Mat3d Mat3d::transpose() const
{
	return Mat3d(
		values[0], values[3], values[6],
		values[1], values[4], values[7],
		values[2], values[5], values[8]
	);
}

Mat3d Mat3d::inverse() const
{
	const double det = this->determinant();
	if (det == 0.0 || this->hasNan())
		return Mat3d::Nan;
	double r0 =  (values[4]*values[8]-values[7]*values[5]) / det;
	double r1 = -(values[3]*values[8]-values[6]*values[5]) / det;
	double r2 =  (values[3]*values[7]-values[6]*values[4]) / det;
	double r3 = -(values[1]*values[8]-values[7]*values[2]) / det;
	double r4 =  (values[0]*values[8]-values[6]*values[2]) / det;
	double r5 = -(values[0]*values[7]-values[6]*values[1]) / det;
	double r6 =  (values[1]*values[5]-values[4]*values[2]) / det;
	double r7 = -(values[0]*values[5]-values[3]*values[2]) / det;
	double r8 =  (values[0]*values[4]-values[3]*values[1]) / det;
	return Mat3d(r0, r3, r6, r1, r4, r7, r2, r5, r8);
}

Mat3d Mat3d::filled(double v)
{
	return Mat3d(v, v, v, v, v, v, v, v, v);
}

const Mat3d Mat3d::Identity(1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);
const Mat3d Mat3d::Zero(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
const Mat3d Mat3d::Nan(Double::Nan, Double::Nan, Double::Nan, Double::Nan, Double::Nan, Double::Nan, Double::Nan, Double::Nan, Double::Nan);
Mat3d Mat3d::Default(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);

} // namespace axl.math
} // namespace axl