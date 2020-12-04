#include <cmath>
#include <axl.math/float.hpp>
#include <axl.math/vec/Vec4d.hpp>
#include <axl.math/vec/Vec4f.hpp>
#include <axl.math/mat/Mat4f.hpp>

namespace axl {
namespace math {

Mat4f::Mat4f(float diag_v)
{
	values[0] = diag_v; values[1] = 0.0f; values[2] = 0.0f; values[3] = 0.0f;
	values[4] = 0.0f; values[5] = diag_v; values[6] = 0.0f; values[7] = 0.0f;
	values[8] = 0.0f; values[9] = 0.0f; values[10] = diag_v; values[11] = 0.0f;
	values[12] = 0.0f; values[13] = 0.0f; values[14] = 0.0f; values[15] = diag_v;
}
Mat4f::Mat4f(float c0, float c1, float c2, float c3, float c4, float c5, float c6, float c7, float c8, float c9, float c10, float c11, float c12, float c13, float c14, float c15)
{
	values[0] = c0; values[1] = c1; values[2] = c2; values[3] = c3;
	values[4] = c4; values[5] = c5; values[6] = c6; values[7] = c7;
	values[8] = c8; values[9] = c9; values[10] = c10; values[11] = c11;
	values[12] = c12; values[13] = c13; values[14] = c14; values[15] = c15;
}
Mat4f::Mat4f(const Mat4f& mat)
{
	values[0] = mat.values[0]; values[1] = mat.values[1]; values[2] = mat.values[2]; values[3] = mat.values[3];
	values[4] = mat.values[4]; values[5] = mat.values[5]; values[6] = mat.values[6]; values[7] = mat.values[7];
	values[8] = mat.values[8]; values[9] = mat.values[9]; values[10] = mat.values[10]; values[11] = mat.values[11];
	values[12] = mat.values[12]; values[13] = mat.values[13]; values[14] = mat.values[14]; values[15] = mat.values[15];
}
// Mat4f(const Mat3d& mat);

float* Mat4f::operator[](int index)
{
	return &values[index * 4];
}
const float* Mat4f::operator[](int index) const
{
	return &values[index * 4];
}
Mat4f Mat4f::operator+(const Mat4f& mat) const
{
	return Mat4f(
		values[0] + mat.values[0], values[1] + mat.values[1], values[2] + mat.values[2], values[3] + mat.values[3],
		values[4] + mat.values[4], values[5] + mat.values[5], values[6] + mat.values[6], values[7] + mat.values[7],
		values[8] + mat.values[8], values[9] + mat.values[9], values[10] + mat.values[10], values[11] + mat.values[11],
		values[12] + mat.values[12], values[13] + mat.values[13], values[14] + mat.values[14], values[15] + mat.values[15]
	);
}
Mat4f Mat4f::operator-(const Mat4f& mat) const
{
	return Mat4f(
		values[0] - mat.values[0], values[1] - mat.values[1], values[2] - mat.values[2], values[3] - mat.values[3],
		values[4] - mat.values[4], values[5] - mat.values[5], values[6] - mat.values[6], values[7] - mat.values[7],
		values[8] - mat.values[8], values[9] - mat.values[9], values[10] - mat.values[10], values[11] - mat.values[11],
		values[12] - mat.values[12], values[13] - mat.values[13], values[14] - mat.values[14], values[15] - mat.values[15]
	);
}
Mat4f Mat4f::scMul(const Mat4f& mat) const
{
	return Mat4f(
		values[0] * mat.values[0], values[1] * mat.values[1], values[2] * mat.values[2], values[3] * mat.values[3],
		values[4] * mat.values[4], values[5] * mat.values[5], values[6] * mat.values[6], values[7] * mat.values[7],
		values[8] * mat.values[8], values[9] * mat.values[9], values[10] * mat.values[10], values[11] * mat.values[11],
		values[12] * mat.values[12], values[13] * mat.values[13], values[14] * mat.values[14], values[15] * mat.values[15]
	);
}
Mat4f Mat4f::scDiv(const Mat4f& mat) const
{
	return Mat4f(
		values[0] / mat.values[0], values[1] / mat.values[1], values[2] / mat.values[2], values[3] / mat.values[3],
		values[4] / mat.values[4], values[5] / mat.values[5], values[6] / mat.values[6], values[7] / mat.values[7],
		values[8] / mat.values[8], values[9] / mat.values[9], values[10] / mat.values[10], values[11] / mat.values[11],
		values[12] / mat.values[12], values[13] / mat.values[13], values[14] / mat.values[14], values[15] / mat.values[15]
	);
}
Mat4f Mat4f::operator*(const Mat4f& mat) const
{
	return Mat4f(
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
Mat4f Mat4f::operator+(float v) const
{
	return Mat4f(
		values[0] + v, values[1] + v, values[2] + v, values[3] + v,
		values[4] + v, values[5] + v, values[6] + v, values[7] + v,
		values[8] + v, values[9] + v, values[10] + v, values[11] + v,
		values[12] + v, values[13] + v, values[14] + v, values[15] + v
	);
}
Mat4f Mat4f::operator-(float v) const
{
	return Mat4f(
		values[0] - v, values[1] - v, values[2] - v, values[3] - v,
		values[4] - v, values[5] - v, values[6] - v, values[7] - v,
		values[8] - v, values[9] - v, values[10] - v, values[11] - v,
		values[12] - v, values[13] - v, values[14] - v, values[15] - v
	);
}
Mat4f Mat4f::operator*(float v) const
{
	return Mat4f(
		values[0] * v, values[1] * v, values[2] * v, values[3] * v,
		values[4] * v, values[5] * v, values[6] * v, values[7] * v,
		values[8] * v, values[9] * v, values[10] * v, values[11] * v,
		values[12] * v, values[13] * v, values[14] * v, values[15] * v
	);
}
Mat4f Mat4f::operator/(float v) const
{
	return Mat4f(
		values[0] / v, values[1] / v, values[2] / v, values[3] / v,
		values[4] / v, values[5] / v, values[6] / v, values[7] / v,
		values[8] / v, values[9] / v, values[10] / v, values[11] / v,
		values[12] / v, values[13] / v, values[14] / v, values[15] / v
	);
}
Mat4f& Mat4f::operator+=(const Mat4f& mat)
{
	values[0] += mat.values[0]; values[1] += mat.values[1]; values[2] += mat.values[2]; values[3] += mat.values[3];
	values[4] += mat.values[4]; values[5] += mat.values[5]; values[6] += mat.values[6]; values[7] += mat.values[7];
	values[8] += mat.values[8]; values[9] += mat.values[9]; values[10] += mat.values[10]; values[11] += mat.values[11];
	values[12] += mat.values[12]; values[13] += mat.values[13]; values[14] += mat.values[14]; values[15] += mat.values[15];
	return *this;
}
Mat4f& Mat4f::operator-=(const Mat4f& mat)
{
	values[0] -= mat.values[0]; values[1] -= mat.values[1]; values[2] -= mat.values[2]; values[3] -= mat.values[3];
	values[4] -= mat.values[4]; values[5] -= mat.values[5]; values[6] -= mat.values[6]; values[7] -= mat.values[7];
	values[8] -= mat.values[8]; values[9] -= mat.values[9]; values[10] -= mat.values[10]; values[11] -= mat.values[11];
	values[12] -= mat.values[12]; values[13] -= mat.values[13]; values[14] -= mat.values[14]; values[15] -= mat.values[15];
	return *this;
}
Mat4f& Mat4f::operator*=(const Mat4f& mat)
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
Mat4f& Mat4f::operator+=(float v)
{
	values[0] += v; values[1] += v; values[2] += v; values[3] += v;
	values[4] += v; values[5] += v; values[6] += v; values[7] += v;
	values[8] += v; values[9] += v; values[10] += v; values[11] += v;
	values[12] += v; values[13] += v; values[14] += v; values[15] += v;
	return *this;
}
Mat4f& Mat4f::operator-=(float v)
{
	values[0] -= v; values[1] -= v; values[2] -= v; values[3] -= v;
	values[4] -= v; values[5] -= v; values[6] -= v; values[7] -= v;
	values[8] -= v; values[9] -= v; values[10] -= v; values[11] -= v;
	values[12] -= v; values[13] -= v; values[14] -= v; values[15] -= v;
	return *this;
}
Mat4f& Mat4f::operator*=(float v)
{
	values[0] *= v; values[1] *= v; values[2] *= v; values[3] *= v;
	values[4] *= v; values[5] *= v; values[6] *= v; values[7] *= v;
	values[8] *= v; values[9] *= v; values[10] *= v; values[11] *= v;
	values[12] *= v; values[13] *= v; values[14] *= v; values[15] *= v;
	return *this;
}
Mat4f& Mat4f::operator/=(float v)
{
	values[0] /= v; values[1] /= v; values[2] /= v; values[3] /= v;
	values[4] /= v; values[5] /= v; values[6] /= v; values[7] /= v;
	values[8] /= v; values[9] /= v; values[10] /= v; values[11] /= v;
	values[12] /= v; values[13] /= v; values[14] /= v; values[15] /= v;
	return *this;
}
Vec4d Mat4f::operator*(const Vec4d& vec) const
{
	return Vec4d(
		(double)(values[0] * vec.x + values[4] * vec.y + values[8] * vec.z + values[12] * vec.w),
		(double)(values[1] * vec.x + values[5] * vec.y + values[9] * vec.z + values[13] * vec.w),
		(double)(values[2] * vec.x + values[6] * vec.y + values[10] * vec.z + values[14] * vec.w),
		(double)(values[3] * vec.x + values[7] * vec.y + values[11] * vec.z + values[15] * vec.w)
	);
}
Vec4f Mat4f::operator*(const Vec4f& vec) const
{
	return Vec4f(
		values[0] * vec.x + values[4] * vec.y + values[8] * vec.z + values[12] * vec.w,
		values[1] * vec.x + values[5] * vec.y + values[9] * vec.z + values[13] * vec.w,
		values[2] * vec.x + values[6] * vec.y + values[10] * vec.z + values[14] * vec.w,
		values[3] * vec.x + values[7] * vec.y + values[11] * vec.z + values[15] * vec.w
	);
}
bool Mat4f::operator==(const Mat4f& mat) const
{
	return values[0] == mat.values[0] && values[1] == mat.values[1] && values[2] == mat.values[2] && values[3] == mat.values[3] &&
		values[4] == mat.values[4] && values[5] == mat.values[5] && values[6] == mat.values[6] && values[7] == mat.values[7] &&
		values[8] == mat.values[8] && values[9] == mat.values[9] && values[10] == mat.values[10] && values[11] == mat.values[11] &&
		values[12] == mat.values[12] && values[13] == mat.values[13] && values[14] == mat.values[14] && values[15] == mat.values[15];
}
bool Mat4f::operator!=(const Mat4f& mat) const
{
	return values[0] != mat.values[0] || values[1] != mat.values[1] || values[2] != mat.values[2] || values[3] != mat.values[3] ||
		values[4] != mat.values[4] || values[5] != mat.values[5] || values[6] != mat.values[6] || values[7] != mat.values[7] ||
		values[8] != mat.values[8] || values[9] != mat.values[9] || values[10] != mat.values[10] || values[11] != mat.values[11] ||
		values[12] != mat.values[12] || values[13] != mat.values[13] || values[14] != mat.values[14] || values[15] != mat.values[15];
}
bool Mat4f::operator==(float v) const
{
	return values[0] == v && values[1] == v && values[2] == v && values[3] == v &&
		values[4] == v && values[5] == v && values[6] == v && values[7] == v &&
		values[8] == v && values[9] == v && values[10] == v && values[11] == v &&
		values[12] == v && values[13] == v && values[14] == v && values[15] == v;
}
bool Mat4f::operator!=(float v) const
{
	return values[0] != v || values[1] != v || values[2] != v || values[3] != v ||
		values[4] != v || values[5] != v || values[6] != v || values[7] != v ||
		values[8] != v || values[9] != v || values[10] != v || values[11] != v ||
		values[12] != v || values[13] != v || values[14] != v || values[15] != v;
}

bool Mat4f::isNan() const
{
	return Float::isNan(values[0]) && Float::isNan(values[1]) && Float::isNan(values[2]) && Float::isNan(values[3]) &&
		Float::isNan(values[4]) && Float::isNan(values[5]) && Float::isNan(values[6]) && Float::isNan(values[7]) &&
		Float::isNan(values[8]) && Float::isNan(values[9]) && Float::isNan(values[10]) && Float::isNan(values[11]) &&
		Float::isNan(values[12]) && Float::isNan(values[13]) && Float::isNan(values[14]) && Float::isNan(values[15]);
}
bool Mat4f::isNotNan() const
{
	return !Float::isNan(values[0]) || !Float::isNan(values[1]) || !Float::isNan(values[2]) || !Float::isNan(values[3]) ||
		!Float::isNan(values[4]) || !Float::isNan(values[5]) || !Float::isNan(values[6]) || !Float::isNan(values[7]) ||
		!Float::isNan(values[8]) || !Float::isNan(values[9]) || !Float::isNan(values[10]) || !Float::isNan(values[11]) ||
		!Float::isNan(values[12]) || !Float::isNan(values[13]) || !Float::isNan(values[14]) || !Float::isNan(values[15]);
}
bool Mat4f::hasNan() const
{
	return Float::isNan(values[0]) || Float::isNan(values[1]) || Float::isNan(values[2]) || Float::isNan(values[3]) ||
		Float::isNan(values[4]) || Float::isNan(values[5]) || Float::isNan(values[6]) || Float::isNan(values[7]) ||
		Float::isNan(values[8]) || Float::isNan(values[9]) || Float::isNan(values[10]) || Float::isNan(values[11]) ||
		Float::isNan(values[12]) || Float::isNan(values[13]) || Float::isNan(values[14]) || Float::isNan(values[15]);
}
bool Mat4f::hasNoNan() const
{
	return !Float::isNan(values[0]) && !Float::isNan(values[1]) && !Float::isNan(values[2]) && !Float::isNan(values[3]) &&
		!Float::isNan(values[4]) && !Float::isNan(values[5]) && !Float::isNan(values[6]) && !Float::isNan(values[7]) &&
		!Float::isNan(values[8]) && !Float::isNan(values[9]) && !Float::isNan(values[10]) && !Float::isNan(values[11]) &&
		!Float::isNan(values[12]) && !Float::isNan(values[13]) && !Float::isNan(values[14]) && !Float::isNan(values[15]);
}
bool Mat4f::equals(const Mat4f& mat, float epsilon) const
{
	return Float::equals(values[0], mat.values[0], epsilon) && Float::equals(values[1], mat.values[1], epsilon) && Float::equals(values[2], mat.values[2], epsilon) && Float::equals(values[3], mat.values[3], epsilon) &&
		Float::equals(values[4], mat.values[4], epsilon) && Float::equals(values[5], mat.values[5], epsilon) && Float::equals(values[6], mat.values[6], epsilon) && Float::equals(values[7], mat.values[7], epsilon) &&
		Float::equals(values[8], mat.values[8], epsilon) && Float::equals(values[9], mat.values[9], epsilon) && Float::equals(values[10], mat.values[10], epsilon) && Float::equals(values[11], mat.values[11], epsilon) &&
		Float::equals(values[12], mat.values[12], epsilon) && Float::equals(values[13], mat.values[13], epsilon) && Float::equals(values[14], mat.values[14], epsilon) && Float::equals(values[15], mat.values[15], epsilon);
}
bool Mat4f::notEquals(const Mat4f& mat, float epsilon) const
{
	return !Float::equals(values[0], mat.values[0], epsilon) || !Float::equals(values[1], mat.values[1], epsilon) || !Float::equals(values[2], mat.values[2], epsilon) || !Float::equals(values[3], mat.values[3], epsilon) ||
		!Float::equals(values[4], mat.values[4], epsilon) || !Float::equals(values[5], mat.values[5], epsilon) || !Float::equals(values[6], mat.values[6], epsilon) || !Float::equals(values[7], mat.values[7], epsilon) ||
		!Float::equals(values[8], mat.values[8], epsilon) || !Float::equals(values[9], mat.values[9], epsilon) || !Float::equals(values[10], mat.values[10], epsilon) || !Float::equals(values[11], mat.values[11], epsilon) ||
		!Float::equals(values[12], mat.values[12], epsilon) || !Float::equals(values[13], mat.values[13], epsilon) || !Float::equals(values[14], mat.values[14], epsilon) || !Float::equals(values[15], mat.values[15], epsilon);
}
bool Mat4f::equals(float c0, float c1, float c2, float c3, float c4, float c5, float c6, float c7, float c8, float c9, float c10, float c11, float c12, float c13, float c14, float c15, float epsilon) const
{
	return Float::equals(values[0], c0, epsilon) && Float::equals(values[1], c1, epsilon) && Float::equals(values[2], c2, epsilon) && Float::equals(values[3], c3, epsilon) &&
		Float::equals(values[4], c4, epsilon) && Float::equals(values[5], c5, epsilon) && Float::equals(values[6], c6, epsilon) && Float::equals(values[7], c7, epsilon) &&
		Float::equals(values[8], c8, epsilon) && Float::equals(values[9], c9, epsilon) && Float::equals(values[10], c10, epsilon) && Float::equals(values[11], c11, epsilon) &&
		Float::equals(values[12], c12, epsilon) && Float::equals(values[13], c13, epsilon) && Float::equals(values[14], c14, epsilon) && Float::equals(values[15], c15, epsilon);
}
bool Mat4f::notEquals(float c0, float c1, float c2, float c3, float c4, float c5, float c6, float c7, float c8, float c9, float c10, float c11, float c12, float c13, float c14, float c15, float epsilon) const
{
	return !Float::equals(values[0], c0, epsilon) || !Float::equals(values[1], c1, epsilon) || !Float::equals(values[2], c2, epsilon) || !Float::equals(values[3], c3, epsilon) ||
		!Float::equals(values[4], c4, epsilon) || !Float::equals(values[5], c5, epsilon) || !Float::equals(values[6], c6, epsilon) || !Float::equals(values[7], c7, epsilon) ||
		!Float::equals(values[8], c8, epsilon) || !Float::equals(values[9], c9, epsilon) || !Float::equals(values[10], c10, epsilon) || !Float::equals(values[11], c11, epsilon) ||
		!Float::equals(values[12], c12, epsilon) || !Float::equals(values[13], c13, epsilon) || !Float::equals(values[14], c14, epsilon) || !Float::equals(values[15], c15, epsilon);
}

const float& Mat4f::at(int column_index, int row_index) const
{
	return values[column_index * 4 + row_index];
}
float& Mat4f::at(int column_index, int row_index)
{
	return values[column_index * 4 + row_index];
}
Mat4f& Mat4f::set(float c0, float c1, float c2, float c3, float c4, float c5, float c6, float c7, float c8, float c9, float c10, float c11, float c12, float c13, float c14, float c15)
{
	values[0] = c0; values[1] = c1; values[2] = c2; values[3] = c3;
	values[4] = c4; values[5] = c5; values[6] = c6; values[7] = c7;
	values[8] = c8; values[9] = c9; values[10] = c10; values[11] = c11;
	values[12] = c12; values[13] = c13; values[14] = c14; values[15] = c15;
	return *this;
}
Mat4f& Mat4f::set(const float pv[16])
{
	values[0] = pv[0]; values[1] = pv[1]; values[2] = pv[2]; values[3] = pv[3];
	values[4] = pv[4]; values[5] = pv[5]; values[6] = pv[6]; values[7] = pv[7];
	values[8] = pv[8]; values[9] = pv[9]; values[10] = pv[10]; values[11] = pv[11];
	values[12] = pv[12]; values[13] = pv[13]; values[14] = pv[14]; values[15] = pv[15];
	return *this;
}
void Mat4f::setValue(int column_index, int row_index, float v)
{
	values[column_index * 4 + row_index] = v;
}
Mat4f Mat4f::transpose() const
{
	return Mat4f(
		values[0], values[4], values[8], values[12],
		values[1], values[5], values[9], values[13],
		values[2], values[6], values[10], values[14],
		values[3], values[7], values[11], values[15]
	);
}

Mat4f Mat4f::filled(float v)
{
	return Mat4f(
		v, v, v, v,
		v, v, v, v,
		v, v, v, v,
		v, v, v, v
	);
}
const Mat4f Mat4f::Identity(
	1.0f, 0.0f, 0.0f, 0.0f, 
	0.0f, 1.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 1.0f
);
const Mat4f Mat4f::Zero(
	0.0f, 0.0f, 0.0f, 0.0f, 
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f
);
const Mat4f Mat4f::Nan(
	Float::Nan, Float::Nan, Float::Nan, Float::Nan, 
	Float::Nan, Float::Nan, Float::Nan, Float::Nan,
	Float::Nan, Float::Nan, Float::Nan, Float::Nan,
	Float::Nan, Float::Nan, Float::Nan, Float::Nan
);
Mat4f Mat4f::Default(
	0.0f, 0.0f, 0.0f, 0.0f, 
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f
);

} // namespace axl.math
} // namespace axl
