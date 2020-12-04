#include <cmath>
#include <axl.math/double.hpp>
#include <axl.math/vec/Vec4d.hpp>
#include <axl.math/vec/Vec4f.hpp>
#include <axl.math/mat/Mat4f.hpp>
#include <axl.math/mat/Mat4d.hpp>

namespace axl {
namespace math {

Mat4d::Mat4d(double diag_v)
{
	values[0] = diag_v; values[1] = 0.0; values[2] = 0.0; values[3] = 0.0;
	values[4] = 0.0; values[5] = diag_v; values[6] = 0.0; values[7] = 0.0;
	values[8] = 0.0; values[9] = 0.0; values[10] = diag_v; values[11] = 0.0;
	values[12] = 0.0; values[13] = 0.0; values[14] = 0.0; values[15] = diag_v;
}
Mat4d::Mat4d(double c0, double c1, double c2, double c3, double c4, double c5, double c6, double c7, double c8, double c9, double c10, double c11, double c12, double c13, double c14, double c15)
{
	values[0] = c0; values[1] = c1; values[2] = c2; values[3] = c3;
	values[4] = c4; values[5] = c5; values[6] = c6; values[7] = c7;
	values[8] = c8; values[9] = c9; values[10] = c10; values[11] = c11;
	values[12] = c12; values[13] = c13; values[14] = c14; values[15] = c15;
}
Mat4d::Mat4d(const Mat4d& mat)
{
	values[0] = mat.values[0]; values[1] = mat.values[1]; values[2] = mat.values[2]; values[3] = mat.values[3];
	values[4] = mat.values[4]; values[5] = mat.values[5]; values[6] = mat.values[6]; values[7] = mat.values[7];
	values[8] = mat.values[8]; values[9] = mat.values[9]; values[10] = mat.values[10]; values[11] = mat.values[11];
	values[12] = mat.values[12]; values[13] = mat.values[13]; values[14] = mat.values[14]; values[15] = mat.values[15];
}
Mat4d::Mat4d(const Mat4f& mat)
{
	values[0] = (double)mat.values[0]; values[1] = (double)mat.values[1]; values[2] = (double)mat.values[2]; values[3] = (double)mat.values[3];
	values[4] = (double)mat.values[4]; values[5] = (double)mat.values[5]; values[6] = (double)mat.values[6]; values[7] = (double)mat.values[7];
	values[8] = (double)mat.values[8]; values[9] = (double)mat.values[9]; values[10] = (double)mat.values[10]; values[11] = (double)mat.values[11];
	values[12] = (double)mat.values[12]; values[13] = (double)mat.values[13]; values[14] = (double)mat.values[14]; values[15] = (double)mat.values[15];
}

double* Mat4d::operator[](int index)
{
	return &values[index * 4];
}
const double* Mat4d::operator[](int index) const
{
	return &values[index * 4];
}
Mat4d Mat4d::operator+(const Mat4d& mat) const
{
	return Mat4d(
		values[0] + mat.values[0], values[1] + mat.values[1], values[2] + mat.values[2], values[3] + mat.values[3],
		values[4] + mat.values[4], values[5] + mat.values[5], values[6] + mat.values[6], values[7] + mat.values[7],
		values[8] + mat.values[8], values[9] + mat.values[9], values[10] + mat.values[10], values[11] + mat.values[11],
		values[12] + mat.values[12], values[13] + mat.values[13], values[14] + mat.values[14], values[15] + mat.values[15]
	);
}
Mat4d Mat4d::operator-(const Mat4d& mat) const
{
	return Mat4d(
		values[0] - mat.values[0], values[1] - mat.values[1], values[2] - mat.values[2], values[3] - mat.values[3],
		values[4] - mat.values[4], values[5] - mat.values[5], values[6] - mat.values[6], values[7] - mat.values[7],
		values[8] - mat.values[8], values[9] - mat.values[9], values[10] - mat.values[10], values[11] - mat.values[11],
		values[12] - mat.values[12], values[13] - mat.values[13], values[14] - mat.values[14], values[15] - mat.values[15]
	);
}
Mat4d Mat4d::scMul(const Mat4d& mat) const
{
	return Mat4d(
		values[0] * mat.values[0], values[1] * mat.values[1], values[2] * mat.values[2], values[3] * mat.values[3],
		values[4] * mat.values[4], values[5] * mat.values[5], values[6] * mat.values[6], values[7] * mat.values[7],
		values[8] * mat.values[8], values[9] * mat.values[9], values[10] * mat.values[10], values[11] * mat.values[11],
		values[12] * mat.values[12], values[13] * mat.values[13], values[14] * mat.values[14], values[15] * mat.values[15]
	);
}
Mat4d Mat4d::scDiv(const Mat4d& mat) const
{
	return Mat4d(
		values[0] / mat.values[0], values[1] / mat.values[1], values[2] / mat.values[2], values[3] / mat.values[3],
		values[4] / mat.values[4], values[5] / mat.values[5], values[6] / mat.values[6], values[7] / mat.values[7],
		values[8] / mat.values[8], values[9] / mat.values[9], values[10] / mat.values[10], values[11] / mat.values[11],
		values[12] / mat.values[12], values[13] / mat.values[13], values[14] / mat.values[14], values[15] / mat.values[15]
	);
}
Mat4d Mat4d::operator*(const Mat4d& mat) const
{
	return Mat4d(
		values[0] * mat.values[0] + values[4] * mat.values[1] + values[8] * mat.values[2] + values[12] * mat.values[3],
		values[1] * mat.values[0] + values[5] * mat.values[1] + values[9] * mat.values[2] + values[13] * mat.values[3],
		values[2] * mat.values[0] + values[6] * mat.values[1] + values[10] * mat.values[2] + values[14] * mat.values[3],
		values[3] * mat.values[0] + values[7] * mat.values[1] + values[11] * mat.values[2] + values[15] * mat.values[3],
		values[0] * mat.values[4] + values[4] * mat.values[5] + values[8] * mat.values[6] + values[12] * mat.values[7],
		values[1] * mat.values[4] + values[5] * mat.values[5] + values[9] * mat.values[6] + values[13] * mat.values[7],
		values[2] * mat.values[4] + values[6] * mat.values[5] + values[10] * mat.values[6] + values[14] * mat.values[7],
		values[3] * mat.values[4] + values[7] * mat.values[5] + values[11] * mat.values[6] + values[15] * mat.values[7],
		values[0] * mat.values[8] + values[4] * mat.values[9] + values[8] * mat.values[10] + values[12] * mat.values[11],
		values[1] * mat.values[8] + values[5] * mat.values[9] + values[9] * mat.values[10] + values[13] * mat.values[11],
		values[2] * mat.values[8] + values[6] * mat.values[9] + values[10] * mat.values[10] + values[14] * mat.values[11],
		values[3] * mat.values[8] + values[7] * mat.values[9] + values[11] * mat.values[10] + values[15] * mat.values[11],
		values[0] * mat.values[12] + values[4] * mat.values[13] + values[8] * mat.values[14] + values[12] * mat.values[15],
		values[1] * mat.values[12] + values[5] * mat.values[13] + values[9] * mat.values[14] + values[13] * mat.values[15],
		values[2] * mat.values[12] + values[6] * mat.values[13] + values[10] * mat.values[14] + values[14] * mat.values[15],
		values[3] * mat.values[12] + values[7] * mat.values[13] + values[11] * mat.values[14] + values[15] * mat.values[15]
	);
}
Mat4d Mat4d::operator+(double v) const
{
	return Mat4d(
		values[0] + v, values[1] + v, values[2] + v, values[3] + v,
		values[4] + v, values[5] + v, values[6] + v, values[7] + v,
		values[8] + v, values[9] + v, values[10] + v, values[11] + v,
		values[12] + v, values[13] + v, values[14] + v, values[15] + v
	);
}
Mat4d Mat4d::operator-(double v) const
{
	return Mat4d(
		values[0] - v, values[1] - v, values[2] - v, values[3] - v,
		values[4] - v, values[5] - v, values[6] - v, values[7] - v,
		values[8] - v, values[9] - v, values[10] - v, values[11] - v,
		values[12] - v, values[13] - v, values[14] - v, values[15] - v
	);
}
Mat4d Mat4d::operator*(double v) const
{
	return Mat4d(
		values[0] * v, values[1] * v, values[2] * v, values[3] * v,
		values[4] * v, values[5] * v, values[6] * v, values[7] * v,
		values[8] * v, values[9] * v, values[10] * v, values[11] * v,
		values[12] * v, values[13] * v, values[14] * v, values[15] * v
	);
}
Mat4d Mat4d::operator/(double v) const
{
	return Mat4d(
		values[0] / v, values[1] / v, values[2] / v, values[3] / v,
		values[4] / v, values[5] / v, values[6] / v, values[7] / v,
		values[8] / v, values[9] / v, values[10] / v, values[11] / v,
		values[12] / v, values[13] / v, values[14] / v, values[15] / v
	);
}
Mat4d& Mat4d::operator+=(const Mat4d& mat)
{
	values[0] += mat.values[0]; values[1] += mat.values[1]; values[2] += mat.values[2]; values[3] += mat.values[3];
	values[4] += mat.values[4]; values[5] += mat.values[5]; values[6] += mat.values[6]; values[7] += mat.values[7];
	values[8] += mat.values[8]; values[9] += mat.values[9]; values[10] += mat.values[10]; values[11] += mat.values[11];
	values[12] += mat.values[12]; values[13] += mat.values[13]; values[14] += mat.values[14]; values[15] += mat.values[15];
	return *this;
}
Mat4d& Mat4d::operator-=(const Mat4d& mat)
{
	values[0] -= mat.values[0]; values[1] -= mat.values[1]; values[2] -= mat.values[2]; values[3] -= mat.values[3];
	values[4] -= mat.values[4]; values[5] -= mat.values[5]; values[6] -= mat.values[6]; values[7] -= mat.values[7];
	values[8] -= mat.values[8]; values[9] -= mat.values[9]; values[10] -= mat.values[10]; values[11] -= mat.values[11];
	values[12] -= mat.values[12]; values[13] -= mat.values[13]; values[14] -= mat.values[14]; values[15] -= mat.values[15];
	return *this;
}
Mat4d& Mat4d::operator*=(const Mat4d& mat)
{
	this->set(
		values[0] * mat.values[0] + values[4] * mat.values[1] + values[8] * mat.values[2] + values[12] * mat.values[3],
		values[1] * mat.values[0] + values[5] * mat.values[1] + values[9] * mat.values[2] + values[13] * mat.values[3],
		values[2] * mat.values[0] + values[6] * mat.values[1] + values[10] * mat.values[2] + values[14] * mat.values[3],
		values[3] * mat.values[0] + values[7] * mat.values[1] + values[11] * mat.values[2] + values[15] * mat.values[3],
		values[0] * mat.values[4] + values[4] * mat.values[5] + values[8] * mat.values[6] + values[12] * mat.values[7],
		values[1] * mat.values[4] + values[5] * mat.values[5] + values[9] * mat.values[6] + values[13] * mat.values[7],
		values[2] * mat.values[4] + values[6] * mat.values[5] + values[10] * mat.values[6] + values[14] * mat.values[7],
		values[3] * mat.values[4] + values[7] * mat.values[5] + values[11] * mat.values[6] + values[15] * mat.values[7],
		values[0] * mat.values[8] + values[4] * mat.values[9] + values[8] * mat.values[10] + values[12] * mat.values[11],
		values[1] * mat.values[8] + values[5] * mat.values[9] + values[9] * mat.values[10] + values[13] * mat.values[11],
		values[2] * mat.values[8] + values[6] * mat.values[9] + values[10] * mat.values[10] + values[14] * mat.values[11],
		values[3] * mat.values[8] + values[7] * mat.values[9] + values[11] * mat.values[10] + values[15] * mat.values[11],
		values[0] * mat.values[12] + values[4] * mat.values[13] + values[8] * mat.values[14] + values[12] * mat.values[15],
		values[1] * mat.values[12] + values[5] * mat.values[13] + values[9] * mat.values[14] + values[13] * mat.values[15],
		values[2] * mat.values[12] + values[6] * mat.values[13] + values[10] * mat.values[14] + values[14] * mat.values[15],
		values[3] * mat.values[12] + values[7] * mat.values[13] + values[11] * mat.values[14] + values[15] * mat.values[15]
	);
	return *this;
}
Mat4d& Mat4d::operator+=(double v)
{
	values[0] += v; values[1] += v; values[2] += v; values[3] += v;
	values[4] += v; values[5] += v; values[6] += v; values[7] += v;
	values[8] += v; values[9] += v; values[10] += v; values[11] += v;
	values[12] += v; values[13] += v; values[14] += v; values[15] += v;
	return *this;
}
Mat4d& Mat4d::operator-=(double v)
{
	values[0] -= v; values[1] -= v; values[2] -= v; values[3] -= v;
	values[4] -= v; values[5] -= v; values[6] -= v; values[7] -= v;
	values[8] -= v; values[9] -= v; values[10] -= v; values[11] -= v;
	values[12] -= v; values[13] -= v; values[14] -= v; values[15] -= v;
	return *this;
}
Mat4d& Mat4d::operator*=(double v)
{
	values[0] *= v; values[1] *= v; values[2] *= v; values[3] *= v;
	values[4] *= v; values[5] *= v; values[6] *= v; values[7] *= v;
	values[8] *= v; values[9] *= v; values[10] *= v; values[11] *= v;
	values[12] *= v; values[13] *= v; values[14] *= v; values[15] *= v;
	return *this;
}
Mat4d& Mat4d::operator/=(double v)
{
	values[0] /= v; values[1] /= v; values[2] /= v; values[3] /= v;
	values[4] /= v; values[5] /= v; values[6] /= v; values[7] /= v;
	values[8] /= v; values[9] /= v; values[10] /= v; values[11] /= v;
	values[12] /= v; values[13] /= v; values[14] /= v; values[15] /= v;
	return *this;
}
Vec4d Mat4d::operator*(const Vec4d& vec) const
{
	return Vec4d(
		(double)(values[0] * vec.x + values[4] * vec.y + values[8] * vec.z + values[12] * vec.w),
		(double)(values[1] * vec.x + values[5] * vec.y + values[9] * vec.z + values[13] * vec.w),
		(double)(values[2] * vec.x + values[6] * vec.y + values[10] * vec.z + values[14] * vec.w),
		(double)(values[3] * vec.x + values[7] * vec.y + values[11] * vec.z + values[15] * vec.w)
	);
}
Vec4f Mat4d::operator*(const Vec4f& vec) const
{
	return Vec4f(
		values[0] * vec.x + values[4] * vec.y + values[8] * vec.z + values[12] * vec.w,
		values[1] * vec.x + values[5] * vec.y + values[9] * vec.z + values[13] * vec.w,
		values[2] * vec.x + values[6] * vec.y + values[10] * vec.z + values[14] * vec.w,
		values[3] * vec.x + values[7] * vec.y + values[11] * vec.z + values[15] * vec.w
	);
}
bool Mat4d::operator==(const Mat4d& mat) const
{
	return values[0] == mat.values[0] && values[1] == mat.values[1] && values[2] == mat.values[2] && values[3] == mat.values[3] &&
		values[4] == mat.values[4] && values[5] == mat.values[5] && values[6] == mat.values[6] && values[7] == mat.values[7] &&
		values[8] == mat.values[8] && values[9] == mat.values[9] && values[10] == mat.values[10] && values[11] == mat.values[11] &&
		values[12] == mat.values[12] && values[13] == mat.values[13] && values[14] == mat.values[14] && values[15] == mat.values[15];
}
bool Mat4d::operator!=(const Mat4d& mat) const
{
	return values[0] != mat.values[0] || values[1] != mat.values[1] || values[2] != mat.values[2] || values[3] != mat.values[3] ||
		values[4] != mat.values[4] || values[5] != mat.values[5] || values[6] != mat.values[6] || values[7] != mat.values[7] ||
		values[8] != mat.values[8] || values[9] != mat.values[9] || values[10] != mat.values[10] || values[11] != mat.values[11] ||
		values[12] != mat.values[12] || values[13] != mat.values[13] || values[14] != mat.values[14] || values[15] != mat.values[15];
}
bool Mat4d::operator==(double v) const
{
	return values[0] == v && values[1] == v && values[2] == v && values[3] == v &&
		values[4] == v && values[5] == v && values[6] == v && values[7] == v &&
		values[8] == v && values[9] == v && values[10] == v && values[11] == v &&
		values[12] == v && values[13] == v && values[14] == v && values[15] == v;
}
bool Mat4d::operator!=(double v) const
{
	return values[0] != v || values[1] != v || values[2] != v || values[3] != v ||
		values[4] != v || values[5] != v || values[6] != v || values[7] != v ||
		values[8] != v || values[9] != v || values[10] != v || values[11] != v ||
		values[12] != v || values[13] != v || values[14] != v || values[15] != v;
}

bool Mat4d::isNan() const
{
	return Double::isNan(values[0]) && Double::isNan(values[1]) && Double::isNan(values[2]) && Double::isNan(values[3]) &&
		Double::isNan(values[4]) && Double::isNan(values[5]) && Double::isNan(values[6]) && Double::isNan(values[7]) &&
		Double::isNan(values[8]) && Double::isNan(values[9]) && Double::isNan(values[10]) && Double::isNan(values[11]) &&
		Double::isNan(values[12]) && Double::isNan(values[13]) && Double::isNan(values[14]) && Double::isNan(values[15]);
}
bool Mat4d::isNotNan() const
{
	return !Double::isNan(values[0]) || !Double::isNan(values[1]) || !Double::isNan(values[2]) || !Double::isNan(values[3]) ||
		!Double::isNan(values[4]) || !Double::isNan(values[5]) || !Double::isNan(values[6]) || !Double::isNan(values[7]) ||
		!Double::isNan(values[8]) || !Double::isNan(values[9]) || !Double::isNan(values[10]) || !Double::isNan(values[11]) ||
		!Double::isNan(values[12]) || !Double::isNan(values[13]) || !Double::isNan(values[14]) || !Double::isNan(values[15]);
}
bool Mat4d::hasNan() const
{
	return Double::isNan(values[0]) || Double::isNan(values[1]) || Double::isNan(values[2]) || Double::isNan(values[3]) ||
		Double::isNan(values[4]) || Double::isNan(values[5]) || Double::isNan(values[6]) || Double::isNan(values[7]) ||
		Double::isNan(values[8]) || Double::isNan(values[9]) || Double::isNan(values[10]) || Double::isNan(values[11]) ||
		Double::isNan(values[12]) || Double::isNan(values[13]) || Double::isNan(values[14]) || Double::isNan(values[15]);
}
bool Mat4d::hasNoNan() const
{
	return !Double::isNan(values[0]) && !Double::isNan(values[1]) && !Double::isNan(values[2]) && !Double::isNan(values[3]) &&
		!Double::isNan(values[4]) && !Double::isNan(values[5]) && !Double::isNan(values[6]) && !Double::isNan(values[7]) &&
		!Double::isNan(values[8]) && !Double::isNan(values[9]) && !Double::isNan(values[10]) && !Double::isNan(values[11]) &&
		!Double::isNan(values[12]) && !Double::isNan(values[13]) && !Double::isNan(values[14]) && !Double::isNan(values[15]);
}
bool Mat4d::equals(const Mat4d& mat, double epsilon) const
{
	return Double::equals(values[0], mat.values[0], epsilon) && Double::equals(values[1], mat.values[1], epsilon) && Double::equals(values[2], mat.values[2], epsilon) && Double::equals(values[3], mat.values[3], epsilon) &&
		Double::equals(values[4], mat.values[4], epsilon) && Double::equals(values[5], mat.values[5], epsilon) && Double::equals(values[6], mat.values[6], epsilon) && Double::equals(values[7], mat.values[7], epsilon) &&
		Double::equals(values[8], mat.values[8], epsilon) && Double::equals(values[9], mat.values[9], epsilon) && Double::equals(values[10], mat.values[10], epsilon) && Double::equals(values[11], mat.values[11], epsilon) &&
		Double::equals(values[12], mat.values[12], epsilon) && Double::equals(values[13], mat.values[13], epsilon) && Double::equals(values[14], mat.values[14], epsilon) && Double::equals(values[15], mat.values[15], epsilon);
}
bool Mat4d::notEquals(const Mat4d& mat, double epsilon) const
{
	return !Double::equals(values[0], mat.values[0], epsilon) || !Double::equals(values[1], mat.values[1], epsilon) || !Double::equals(values[2], mat.values[2], epsilon) || !Double::equals(values[3], mat.values[3], epsilon) ||
		!Double::equals(values[4], mat.values[4], epsilon) || !Double::equals(values[5], mat.values[5], epsilon) || !Double::equals(values[6], mat.values[6], epsilon) || !Double::equals(values[7], mat.values[7], epsilon) ||
		!Double::equals(values[8], mat.values[8], epsilon) || !Double::equals(values[9], mat.values[9], epsilon) || !Double::equals(values[10], mat.values[10], epsilon) || !Double::equals(values[11], mat.values[11], epsilon) ||
		!Double::equals(values[12], mat.values[12], epsilon) || !Double::equals(values[13], mat.values[13], epsilon) || !Double::equals(values[14], mat.values[14], epsilon) || !Double::equals(values[15], mat.values[15], epsilon);
}
bool Mat4d::equals(double c0, double c1, double c2, double c3, double c4, double c5, double c6, double c7, double c8, double c9, double c10, double c11, double c12, double c13, double c14, double c15, double epsilon) const
{
	return Double::equals(values[0], c0, epsilon) && Double::equals(values[1], c1, epsilon) && Double::equals(values[2], c2, epsilon) && Double::equals(values[3], c3, epsilon) &&
		Double::equals(values[4], c4, epsilon) && Double::equals(values[5], c5, epsilon) && Double::equals(values[6], c6, epsilon) && Double::equals(values[7], c7, epsilon) &&
		Double::equals(values[8], c8, epsilon) && Double::equals(values[9], c9, epsilon) && Double::equals(values[10], c10, epsilon) && Double::equals(values[11], c11, epsilon) &&
		Double::equals(values[12], c12, epsilon) && Double::equals(values[13], c13, epsilon) && Double::equals(values[14], c14, epsilon) && Double::equals(values[15], c15, epsilon);
}
bool Mat4d::notEquals(double c0, double c1, double c2, double c3, double c4, double c5, double c6, double c7, double c8, double c9, double c10, double c11, double c12, double c13, double c14, double c15, double epsilon) const
{
	return !Double::equals(values[0], c0, epsilon) || !Double::equals(values[1], c1, epsilon) || !Double::equals(values[2], c2, epsilon) || !Double::equals(values[3], c3, epsilon) ||
		!Double::equals(values[4], c4, epsilon) || !Double::equals(values[5], c5, epsilon) || !Double::equals(values[6], c6, epsilon) || !Double::equals(values[7], c7, epsilon) ||
		!Double::equals(values[8], c8, epsilon) || !Double::equals(values[9], c9, epsilon) || !Double::equals(values[10], c10, epsilon) || !Double::equals(values[11], c11, epsilon) ||
		!Double::equals(values[12], c12, epsilon) || !Double::equals(values[13], c13, epsilon) || !Double::equals(values[14], c14, epsilon) || !Double::equals(values[15], c15, epsilon);
}

const double& Mat4d::at(int column_index, int row_index) const
{
	return values[column_index * 4 + row_index];
}
double& Mat4d::at(int column_index, int row_index)
{
	return values[column_index * 4 + row_index];
}
Mat4d& Mat4d::set(double c0, double c1, double c2, double c3, double c4, double c5, double c6, double c7, double c8, double c9, double c10, double c11, double c12, double c13, double c14, double c15)
{
	values[0] = c0; values[1] = c1; values[2] = c2; values[3] = c3;
	values[4] = c4; values[5] = c5; values[6] = c6; values[7] = c7;
	values[8] = c8; values[9] = c9; values[10] = c10; values[11] = c11;
	values[12] = c12; values[13] = c13; values[14] = c14; values[15] = c15;
	return *this;
}
Mat4d& Mat4d::set(const double pv[16])
{
	values[0] = pv[0]; values[1] = pv[1]; values[2] = pv[2]; values[3] = pv[3];
	values[4] = pv[4]; values[5] = pv[5]; values[6] = pv[6]; values[7] = pv[7];
	values[8] = pv[8]; values[9] = pv[9]; values[10] = pv[10]; values[11] = pv[11];
	values[12] = pv[12]; values[13] = pv[13]; values[14] = pv[14]; values[15] = pv[15];
	return *this;
}
void Mat4d::setValue(int column_index, int row_index, double v)
{
	values[column_index * 4 + row_index] = v;
}
Mat4d Mat4d::transpose() const
{
	return Mat4d(
		values[0], values[4], values[8], values[12],
		values[1], values[5], values[9], values[13],
		values[2], values[6], values[10], values[14],
		values[3], values[7], values[11], values[15]
	);
}

Mat4d Mat4d::filled(double v)
{
	return Mat4d(
		v, v, v, v,
		v, v, v, v,
		v, v, v, v,
		v, v, v, v
	);
}
const Mat4d Mat4d::Identity(
	1.0, 0.0, 0.0, 0.0, 
	0.0, 1.0, 0.0, 0.0,
	0.0, 0.0, 1.0, 0.0,
	0.0, 0.0, 0.0, 1.0
);
const Mat4d Mat4d::Zero(
	0.0, 0.0, 0.0, 0.0, 
	0.0, 0.0, 0.0, 0.0,
	0.0, 0.0, 0.0, 0.0,
	0.0, 0.0, 0.0, 0.0
);
const Mat4d Mat4d::Nan(
	Double::Nan, Double::Nan, Double::Nan, Double::Nan, 
	Double::Nan, Double::Nan, Double::Nan, Double::Nan,
	Double::Nan, Double::Nan, Double::Nan, Double::Nan,
	Double::Nan, Double::Nan, Double::Nan, Double::Nan
);
Mat4d Mat4d::Default(
	0.0, 0.0, 0.0, 0.0, 
	0.0, 0.0, 0.0, 0.0,
	0.0, 0.0, 0.0, 0.0,
	0.0, 0.0, 0.0, 0.0
);

} // namespace axl.math
} // namespace axl
