#include <cmath>
#include <axl.math/lib.hpp>
#include <axl.math/mat/Mat3f.hpp>
#include <axl.math/mat/Mat3d.hpp>
#include <axl.math/mat/transform3.hpp>

namespace axl {
namespace math {
namespace Transform3 {

Mat3f transform(const axl::math::Vec2f& scale, float rotate, const axl::math::Vec2f& translate, Rules::Axis axis_rule)
{
	switch(axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: return axl::math::Mat3f(
			(scale.x * std::cos(rotate)), 0, 0,
			0, (scale.y * std::sin(rotate)), 0,
			translate.x, translate.y, 1
		);
		case Rules::Axis::AXIS_LHS: return axl::math::Mat3f(
			(scale.x * std::cos(rotate)), 0, 0,
			0, (scale.y * -std::sin(rotate)), 0,
			translate.x, translate.y, 1
		);
	}
}
Mat3f scale(const axl::math::Vec2f& scale)
{
	return axl::math::Mat3f(
		scale.x, 0, 0,
		0, scale.y, 0,
		0, 0, 1
	);
}
Mat3f translate(const axl::math::Vec2f& translate)
{
	return axl::math::Mat3f(
		1, 0, 0,
		0, 1, 0,
		translate.x, translate.y, 1
	);
}
Mat3f rotate(float rotate, Rules::Axis axis_rule)
{
	switch(axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: return axl::math::Mat3f(
			(std::cos(rotate)), 0, 0,
			0, (std::sin(rotate)), 0,
			0, 0, 1
		);
		case Rules::Axis::AXIS_LHS: return axl::math::Mat3f(
			(std::cos(rotate)), 0, 0,
			0, (-std::sin(rotate)), 0,
			0, 0, 1
		);
	}
}
Mat3f scaleTranslate(const axl::math::Vec2f& scale, const axl::math::Vec2f& translate)
{
	return axl::math::Mat3f(
		scale.x, 0, 0,
		0, scale.y, 0,
		translate.x, translate.y, 1
	);
}
Mat3f scaleRotate(const axl::math::Vec2f& scale, float rotate, Rules::Axis axis_rule)
{
	switch(axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: return axl::math::Mat3f(
			(scale.x * std::cos(rotate)), 0, 0,
			0, (scale.y * std::sin(rotate)), 0,
			0, 0, 1
		);
		case Rules::Axis::AXIS_LHS: return axl::math::Mat3f(
			(scale.x * std::cos(rotate)), 0, 0,
			0, (scale.y * -std::sin(rotate)), 0,
			0, 0, 1
		);
	}
}
Mat3f rotateTranslate(float rotate, const axl::math::Vec2f& translate, Rules::Axis axis_rule)
{
	switch(axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: return axl::math::Mat3f(
			(std::cos(rotate)), 0, 0,
			0, (std::sin(rotate)), 0,
			translate.x, translate.y, 1
		);
		case Rules::Axis::AXIS_LHS: return axl::math::Mat3f(
			(std::cos(rotate)), 0, 0,
			0, (-std::sin(rotate)), 0,
			translate.x, translate.y, 1
		);
	}
}

Mat3d transform(const axl::math::Vec2d& scale, double rotate, const axl::math::Vec2d& translate, Rules::Axis axis_rule)
{
	switch(axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: return axl::math::Mat3d(
			(scale.x * std::cos(rotate)), 0, 0,
			0, (scale.y * std::sin(rotate)), 0,
			translate.x, translate.y, 1
		);
		case Rules::Axis::AXIS_LHS: return axl::math::Mat3d(
			(scale.x * std::cos(rotate)), 0, 0,
			0, (scale.y * -std::sin(rotate)), 0,
			translate.x, translate.y, 1
		);
	}
}
Mat3d scale(const axl::math::Vec2d& scale)
{
	return axl::math::Mat3d(
		scale.x, 0, 0,
		0, scale.y, 0,
		0, 0, 1
	);
}
Mat3d translate(const axl::math::Vec2d& translate)
{
	return axl::math::Mat3d(
		1, 0, 0,
		0, 1, 0,
		translate.x, translate.y, 1
	);
}
Mat3d rotate(double rotate, Rules::Axis axis_rule)
{
	switch(axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: return axl::math::Mat3d(
			(std::cos(rotate)), 0, 0,
			0, (std::sin(rotate)), 0,
			0, 0, 1
		);
		case Rules::Axis::AXIS_LHS: return axl::math::Mat3d(
			(std::cos(rotate)), 0, 0,
			0, (-std::sin(rotate)), 0,
			0, 0, 1
		);
	}
}
Mat3d scaleTranslate(const axl::math::Vec2d& scale, const axl::math::Vec2d& translate)
{
	return axl::math::Mat3d(
		scale.x, 0, 0,
		0, scale.y, 0,
		translate.x, translate.y, 1
	);
}
Mat3d scaleRotate(const axl::math::Vec2d& scale, double rotate, Rules::Axis axis_rule)
{
	switch(axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: return axl::math::Mat3d(
			(scale.x * std::cos(rotate)), 0, 0,
			0, (scale.y * std::sin(rotate)), 0,
			0, 0, 1
		);
		case Rules::Axis::AXIS_LHS: return axl::math::Mat3d(
			(scale.x * std::cos(rotate)), 0, 0,
			0, (scale.y * -std::sin(rotate)), 0,
			0, 0, 1
		);
	}
}
Mat3d rotateTranslate(double rotate, const axl::math::Vec2d& translate, Rules::Axis axis_rule)
{
	switch(axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: return axl::math::Mat3d(
			(std::cos(rotate)), 0, 0,
			0, (std::sin(rotate)), 0,
			translate.x, translate.y, 1
		);
		case Rules::Axis::AXIS_LHS: return axl::math::Mat3d(
			(std::cos(rotate)), 0, 0,
			0, (-std::sin(rotate)), 0,
			translate.x, translate.y, 1
		);
	}
}

} // namespace axl.math.Transform3
} // namespace axl.math
} // namespace axl
