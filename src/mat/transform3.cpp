#include <cmath>
#include <axl.math/lib.hpp>
#include <axl.math/mat/Mat3f.hpp>
#include <axl.math/mat/Mat3d.hpp>
#include <axl.math/mat/transform3.hpp>

namespace axl {
namespace math {
namespace Transform3 {

Mat3f scale(const axl::math::Vec2f& scale)
{
	return Mat3f(
		scale.x, 0, 0,
		0, scale.y, 0,
		0, 0, 1
	);
}
Mat3f translate(const axl::math::Vec2f& translate)
{
	return Mat3f(
		1, 0, 0,
		0, 1, 0,
		translate.x, translate.y, 1
	);
}
Mat3f rotate(float theta, Rules::Axis axis_rule)
{
	switch(axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: break;
		case Rules::Axis::AXIS_LHS: theta = -theta; break;
	}
	return Mat3f(
		std::cos(theta), std::sin(theta), 0,
		-std::sin(theta), std::cos(theta), 0,
		0, 0, 1
	);
}
Mat3f scaleTranslate(const axl::math::Vec2f& scale, const axl::math::Vec2f& translate)
{
	return Mat3f(
		scale.x, 0, 0,
		0, scale.y, 0,
		translate.x, translate.y, 1
	);
}
Mat3f translateScale(const axl::math::Vec2f& translate, const axl::math::Vec2f& scale)
{
	return Mat3f(
		scale.x, 0, 0,
		0, scale.y, 0,
		scale.x * translate.x, scale.y * translate.y, 1
	);
}
Mat3f scaleRotate(const axl::math::Vec2f& scale, float theta, Rules::Axis axis_rule)
{
	switch (axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: break;
		case Rules::Axis::AXIS_LHS: theta = -theta; break;
	}
	const float c = std::cos(theta);
	const float s = std::sin(theta);
	return Mat3f(
		scale.x * c, scale.x * s, 0,
		-scale.y * s, scale.y * c, 0,
		0, 0, 1
	);
}
Mat3f rotateScale(float theta, const axl::math::Vec2f& scale, Rules::Axis axis_rule)
{
	switch (axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: break;
		case Rules::Axis::AXIS_LHS: theta = -theta; break;
	}
	const float c = std::cos(theta);
	const float s = std::sin(theta);
	return Mat3f(
		scale.x * c, scale.y * s, 0,
		-scale.x * s, scale.y * c, 0,
		0, 0, 1
	);
}
Mat3f translateRotate(const axl::math::Vec2f& translation, float theta, Rules::Axis axis_rule)
{
	switch (axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: break;
		case Rules::Axis::AXIS_LHS: theta = -theta; break;
	}
	const float c = std::cos(theta);
	const float s = std::sin(theta);
	return Mat3f(
		c, s, 0,
		-s, c, 0,
		translation.x * c - translation.y * s, translation.x * s + translation.y * c, 1
	);
}
Mat3f rotateTranslate(float theta, const axl::math::Vec2f& translation, Rules::Axis axis_rule)
{
	switch (axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: break;
		case Rules::Axis::AXIS_LHS: theta = -theta; break;
	}
	const float c = std::cos(theta);
	const float s = std::sin(theta);
	return Mat3f(
		c, s, 0,
		-s, c, 0,
		translation.x, translation.y, 1
	);
}
Mat3f scaleTranslateRotate(const axl::math::Vec2f& scale, const axl::math::Vec2f& translation, float theta, Rules::Axis axis_rule)
{
	switch (axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: break;
		case Rules::Axis::AXIS_LHS: theta = -theta; break;
	}
	const float c = std::cos(theta);
	const float s = std::sin(theta);
	return Mat3f(
		scale.x * c, scale.x * s, 0,
		-scale.y * s, scale.y * c, 0,
		translation.x * c - translation.y * s, translation.x * s + translation.y * c, 1
	);
}
Mat3f scaleRotateTranslate(const axl::math::Vec2f& scale, float theta, const axl::math::Vec2f& translation, Rules::Axis axis_rule)
{
	switch (axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: break;
		case Rules::Axis::AXIS_LHS: theta = -theta; break;
	}
	const float c = std::cos(theta);
	const float s = std::sin(theta);
	return Mat3f(
		scale.x * c, scale.x * s, 0,
		-scale.y * s, scale.y * c, 0,
		translation.x, translation.y, 1
	);
}
Mat3f translateScaleRotate(const axl::math::Vec2f& translation, const axl::math::Vec2f& scale, float theta, Rules::Axis axis_rule)
{
	switch (axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: break;
		case Rules::Axis::AXIS_LHS: theta = -theta; break;
	}
	const float c = std::cos(theta);
	const float s = std::sin(theta);
	return Mat3f(
		scale.x * c, scale.x * s, 0,
		-scale.y * s, scale.y * c, 0,
		scale.x * translation.x * c - scale.y * translation.y * s, scale.x * translation.x * s + scale.y * translation.y * c, 1
	);
}
Mat3f translateRotateScale(const axl::math::Vec2f& translation, float theta, const axl::math::Vec2f& scale, Rules::Axis axis_rule)
{
	switch (axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: break;
		case Rules::Axis::AXIS_LHS: theta = -theta; break;
	}
	const float c = std::cos(theta);
	const float s = std::sin(theta);
	return Mat3f(
		scale.x * c, scale.y * s, 0,
		-scale.x * s, scale.y * c, 0,
		scale.x * (translation.x * c - translation.y * s), scale.y * (translation.x * s + translation.y * c), 1
	);
}
Mat3f rotateScaleTranslate(float theta, const axl::math::Vec2f& scale, const axl::math::Vec2f& translation, Rules::Axis axis_rule)
{
	switch (axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: break;
		case Rules::Axis::AXIS_LHS: theta = -theta; break;
	}
	const float c = std::cos(theta);
	const float s = std::sin(theta);
	return Mat3f(
		scale.x * c, scale.x * s, 0,
		-scale.y * s, scale.y * c, 0,
		scale.x * translation.x * c - scale.y * translation.y * s, scale.x * translation.x * s + scale.y * translation.y * c, 1
	);
}
Mat3f rotateTranslateScale(float theta, const axl::math::Vec2f& translation, const axl::math::Vec2f& scale, Rules::Axis axis_rule)
{
	switch (axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: break;
		case Rules::Axis::AXIS_LHS: theta = -theta; break;
	}
	const float c = std::cos(theta);
	const float s = std::sin(theta);
	return Mat3f(
		scale.x * c, scale.y * s, 0,
		-scale.x * s, scale.y * c, 0,
		scale.x * translation.x, scale.y * translation.y, 1
	);
}


Mat3d scale(const axl::math::Vec2d& scale)
{
	return Mat3d(
		scale.x, 0, 0,
		0, scale.y, 0,
		0, 0, 1
	);
}
Mat3d translate(const axl::math::Vec2d& translate)
{
	return Mat3d(
		1, 0, 0,
		0, 1, 0,
		translate.x, translate.y, 1
	);
}
Mat3d rotate(double theta, Rules::Axis axis_rule)
{
	switch (axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: break;
		case Rules::Axis::AXIS_LHS: theta = -theta; break;
	}
	return Mat3d(
		std::cos(theta), std::sin(theta), 0,
		-std::sin(theta), std::cos(theta), 0,
		0, 0, 1
	);
}
Mat3d scaleTranslate(const axl::math::Vec2d& scale, const axl::math::Vec2d& translate)
{
	return Mat3d(
		scale.x, 0, 0,
		0, scale.y, 0,
		translate.x, translate.y, 1
	);
}
Mat3d translateScale(const axl::math::Vec2d& translate, const axl::math::Vec2d& scale)
{
	return Mat3d(
		scale.x, 0, 0,
		0, scale.y, 0,
		scale.x * translate.x, scale.y * translate.y, 1
	);
}
Mat3d scaleRotate(const axl::math::Vec2d& scale, double theta, Rules::Axis axis_rule)
{
	switch (axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: break;
		case Rules::Axis::AXIS_LHS: theta = -theta; break;
	}
	const double c = std::cos(theta);
	const double s = std::sin(theta);
	return Mat3d(
		scale.x * c, scale.x * s, 0,
		-scale.y * s, scale.y * c, 0,
		0, 0, 1
	);
}
Mat3d rotateScale(double theta, const axl::math::Vec2d& scale, Rules::Axis axis_rule)
{
	switch (axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: break;
		case Rules::Axis::AXIS_LHS: theta = -theta; break;
	}
	const double c = std::cos(theta);
	const double s = std::sin(theta);
	return Mat3d(
		scale.x * c, scale.y * s, 0,
		-scale.x * s, scale.y * c, 0,
		0, 0, 1
	);
}
Mat3d translateRotate(const axl::math::Vec2d& translation, double theta, Rules::Axis axis_rule)
{
	switch (axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: break;
		case Rules::Axis::AXIS_LHS: theta = -theta; break;
	}
	const double c = std::cos(theta);
	const double s = std::sin(theta);
	return Mat3d(
		c, s, 0,
		-s, c, 0,
		translation.x * c - translation.y * s, translation.x * s + translation.y * c, 1
	);
}
Mat3d rotateTranslate(double theta, const axl::math::Vec2d& translation, Rules::Axis axis_rule)
{
	switch (axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: break;
		case Rules::Axis::AXIS_LHS: theta = -theta; break;
	}
	const double c = std::cos(theta);
	const double s = std::sin(theta);
	return Mat3d(
		c, s, 0,
		-s, c, 0,
		translation.x, translation.y, 1
	);
}
Mat3d scaleTranslateRotate(const axl::math::Vec2d& scale, const axl::math::Vec2d& translation, double theta, Rules::Axis axis_rule)
{
	switch (axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: break;
		case Rules::Axis::AXIS_LHS: theta = -theta; break;
	}
	const double c = std::cos(theta);
	const double s = std::sin(theta);
	return Mat3d(
		scale.x * c, scale.x * s, 0,
		-scale.y * s, scale.y * c, 0,
		translation.x * c - translation.y * s, translation.x * s + translation.y * c, 1
	);
}
Mat3d scaleRotateTranslate(const axl::math::Vec2d& scale, double theta, const axl::math::Vec2d& translation, Rules::Axis axis_rule)
{
	switch (axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: break;
		case Rules::Axis::AXIS_LHS: theta = -theta; break;
	}
	const double c = std::cos(theta);
	const double s = std::sin(theta);
	return Mat3d(
		scale.x * c, scale.x * s, 0,
		-scale.y * s, scale.y * c, 0,
		translation.x, translation.y, 1
	);
}
Mat3d translateScaleRotate(const axl::math::Vec2d& translation, const axl::math::Vec2d& scale, double theta, Rules::Axis axis_rule)
{
	switch (axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: break;
		case Rules::Axis::AXIS_LHS: theta = -theta; break;
	}
	const double c = std::cos(theta);
	const double s = std::sin(theta);
	return Mat3d(
		scale.x * c, scale.x * s, 0,
		-scale.y * s, scale.y * c, 0,
		scale.x * translation.x * c - scale.y * translation.y * s, scale.x * translation.x * s + scale.y * translation.y * c, 1
	);
}
Mat3d translateRotateScale(const axl::math::Vec2d& translation, double theta, const axl::math::Vec2d& scale, Rules::Axis axis_rule)
{
	switch (axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: break;
		case Rules::Axis::AXIS_LHS: theta = -theta; break;
	}
	const double c = std::cos(theta);
	const double s = std::sin(theta);
	return Mat3d(
		scale.x * c, scale.y * s, 0,
		-scale.x * s, scale.y * c, 0,
		scale.x * (translation.x * c - translation.y * s), scale.y * (translation.x * s + translation.y * c), 1
	);
}
Mat3d rotateScaleTranslate(double theta, const axl::math::Vec2d& scale, const axl::math::Vec2d& translation, Rules::Axis axis_rule)
{
	switch (axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: break;
		case Rules::Axis::AXIS_LHS: theta = -theta; break;
	}
	const double c = std::cos(theta);
	const double s = std::sin(theta);
	return Mat3d(
		scale.x * c, scale.x * s, 0,
		-scale.y * s, scale.y * c, 0,
		scale.x * translation.x * c - scale.y * translation.y * s, scale.x * translation.x * s + scale.y * translation.y * c, 1
	);
}
Mat3d rotateTranslateScale(double theta, const axl::math::Vec2d& translation, const axl::math::Vec2d& scale, Rules::Axis axis_rule)
{
	switch (axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: break;
		case Rules::Axis::AXIS_LHS: theta = -theta; break;
	}
	const double c = std::cos(theta);
	const double s = std::sin(theta);
	return Mat3d(
		scale.x * c, scale.y * s, 0,
		-scale.x * s, scale.y * c, 0,
		scale.x * translation.x, scale.y * translation.y, 1
	);
}

} // namespace axl.math.Transform3
} // namespace axl.math
} // namespace axl
