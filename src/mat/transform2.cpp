#include <cmath>
#include <axl.math/lib.hpp>
#include <axl.math/mat/Mat2f.hpp>
#include <axl.math/mat/Mat2d.hpp>
#include <axl.math/mat/transform2.hpp>

namespace axl {
namespace math {
namespace Transform2 {

Mat2f transform(float scale, float translate)
{
	return Mat2f(
		scale, 0,
		translate, 1
	);
}
Mat2f scale(float scale)
{
	return Mat2f(
		scale, 0,
		0, 1
	);
}
Mat2f translate(float translate)
{
	return Mat2f(
		1, 0,
		translate, 1
	);
}

Mat2d transform(double scale, double translate)
{
	return Mat2d(
		scale, 0,
		translate, 1
	);
}
Mat2d scale(double scale)
{
	return Mat2d(
		scale, 0,
		0, 1
	);
}
Mat2d translate(double translate)
{
	return Mat2d(
		1, 0,
		translate, 1
	);
}


} // namespace axl.math.Transform2
} // namespace axl.math
} // namespace axl
