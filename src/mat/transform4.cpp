#include <cmath>
#include <axl.math/lib.hpp>
#include <axl.math/mat/Mat4f.hpp>
#include <axl.math/mat/Mat4d.hpp>
#include <axl.math/mat/transform4.hpp>

namespace axl {
namespace math {
namespace Transform4 {

Mat4f transform(const axl::math::Vec3f& scale, const axl::math::Vec3f& rotate, const axl::math::Vec3f& translate, Rules::Axis axis_rule)
{
	switch(axis_rule)
	{
		default:
		case Rules::AXIS_RHS: return axl::math::Mat4f(
			(scale.x * std::cos(rotate.y) * std::cos(rotate.z)), (scale.x * std::sin(rotate.z)), (scale.x * -std::sin(rotate.y)), 0,
			(scale.y * -std::sin(rotate.z)), (scale.y * std::cos(rotate.x) * std::cos(rotate.z)), (scale.y * std::sin(rotate.x)), 0,
			(scale.z * std::sin(rotate.y)), (scale.z * -std::sin(rotate.x)), (scale.z * std::cos(rotate.x) * std::cos(rotate.y)), 0,
			translate.x, translate.y, translate.z, 1
		);
		case Rules::AXIS_LHS: return axl::math::Mat4f(
			(scale.x * std::cos(rotate.y) * std::cos(rotate.z)), (scale.x * -std::sin(rotate.z)), (scale.x * std::sin(rotate.y)), 0,
			(scale.y * std::sin(rotate.z)), (scale.y * std::cos(rotate.x) * std::cos(rotate.z)), (scale.y * -std::sin(rotate.x)), 0,
			(scale.z * -std::sin(rotate.y)), (scale.z * std::sin(rotate.x)), (scale.z * std::cos(rotate.x) * std::cos(rotate.y)), 0,
			translate.x, translate.y, translate.z, 1
		);
	}
}
Mat4f scale(const axl::math::Vec3f& scale)
{
	return axl::math::Mat4f(
		scale.x, 0, 0, 0,
		0, scale.y, 0, 0,
		0, 0, scale.z, 0,
		0, 0, 0, 1
	);
}
Mat4f translate(const axl::math::Vec3f& translate)
{
	return axl::math::Mat4f(
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		translate.x, translate.y, translate.z, 1
	);
}
Mat4f rotate(const axl::math::Vec3f& rotate, Rules::Axis axis_rule)
{
	switch(axis_rule)
	{
		default:
		case Rules::AXIS_RHS: return axl::math::Mat4f(
			(std::cos(rotate.y) * std::cos(rotate.z)), (std::sin(rotate.z)), (-std::sin(rotate.y)), 0,
			(-std::sin(rotate.z)), (std::cos(rotate.x) * std::cos(rotate.z)), (std::sin(rotate.x)), 0,
			(std::sin(rotate.y)), (-std::sin(rotate.x)), (std::cos(rotate.x) * std::cos(rotate.y)), 0,
			0, 0, 0, 1
		);
		case Rules::AXIS_LHS: return axl::math::Mat4f(
			(std::cos(rotate.y) * std::cos(rotate.z)), (-std::sin(rotate.z)), (std::sin(rotate.y)), 0,
			(std::sin(rotate.z)), (std::cos(rotate.x) * std::cos(rotate.z)), (-std::sin(rotate.x)), 0,
			(-std::sin(rotate.y)), (std::sin(rotate.x)), (std::cos(rotate.x) * std::cos(rotate.y)), 0,
			0, 0, 0, 1
		);
	}
}
Mat4f scaleTranslate(const axl::math::Vec3f& scale, const axl::math::Vec3f& translate)
{
	return axl::math::Mat4f(
		scale.x, 0, 0, 0,
		0, scale.y, 0, 0,
		0, 0, scale.z, 0,
		translate.x, translate.y, translate.z, 1
	);
}
Mat4f scaleRotate(const axl::math::Vec3f& scale, const axl::math::Vec3f& rotate, Rules::Axis axis_rule)
{
	switch(axis_rule)
	{
		default:
		case Rules::AXIS_RHS: return axl::math::Mat4f(
			(scale.x * std::cos(rotate.y) * std::cos(rotate.z)), (scale.x * std::sin(rotate.z)), (scale.x * -std::sin(rotate.y)), 0,
			(scale.y * -std::sin(rotate.z)), (scale.y * std::cos(rotate.x) * std::cos(rotate.z)), (scale.y * std::sin(rotate.x)), 0,
			(scale.z * std::sin(rotate.y)), (scale.z * -std::sin(rotate.x)), (scale.z * std::cos(rotate.x) * std::cos(rotate.y)), 0,
			0, 0, 0, 1
		);
		case Rules::AXIS_LHS: return axl::math::Mat4f(
			(scale.x * std::cos(rotate.y) * std::cos(rotate.z)), (scale.x * -std::sin(rotate.z)), (scale.x * std::sin(rotate.y)), 0,
			(scale.y * std::sin(rotate.z)), (scale.y * std::cos(rotate.x) * std::cos(rotate.z)), (scale.y * -std::sin(rotate.x)), 0,
			(scale.z * -std::sin(rotate.y)), (scale.z * std::sin(rotate.x)), (scale.z * std::cos(rotate.x) * std::cos(rotate.y)), 0,
			0, 0, 0, 1
		);
	}
}
Mat4f rotateTranslate(const axl::math::Vec3f& rotate, const axl::math::Vec3f& translate, Rules::Axis axis_rule)
{
	switch(axis_rule)
	{
		default:
		case Rules::AXIS_RHS: return axl::math::Mat4f(
			(std::cos(rotate.y) * std::cos(rotate.z)), (std::sin(rotate.z)), (-std::sin(rotate.y)), 0,
			(-std::sin(rotate.z)), (std::cos(rotate.x) * std::cos(rotate.z)), (std::sin(rotate.x)), 0,
			(std::sin(rotate.y)), (-std::sin(rotate.x)), (std::cos(rotate.x) * std::cos(rotate.y)), 0,
			translate.x, translate.y, translate.z, 1
		);
		case Rules::AXIS_LHS: return axl::math::Mat4f(
			(std::cos(rotate.y) * std::cos(rotate.z)), (-std::sin(rotate.z)), (std::sin(rotate.y)), 0,
			(std::sin(rotate.z)), (std::cos(rotate.x) * std::cos(rotate.z)), (-std::sin(rotate.x)), 0,
			(-std::sin(rotate.y)), (std::sin(rotate.x)), (std::cos(rotate.x) * std::cos(rotate.y)), 0,
			translate.x, translate.y, translate.z, 1
		);
	}
}
Mat4f rotateX(float rotate_x, Rules::Axis axis_rule)
{
	switch(axis_rule)
	{
		default:
		case Rules::AXIS_RHS: return axl::math::Mat4f(
			1, 0, 0, 0,
			0, (std::cos(rotate_x)), (std::sin(rotate_x)), 0,
			0, (-std::sin(rotate_x)), (std::cos(rotate_x)), 0,
			0, 0, 0, 1
		);
		case Rules::AXIS_LHS: return axl::math::Mat4f(
			1, 0, 0, 0,
			0, (std::cos(rotate_x)), (-std::sin(rotate_x)), 0,
			0, (std::sin(rotate_x)), (std::cos(rotate_x)), 0,
			0, 0, 0, 1
		);
	}
}
Mat4f rotateY(float rotate_y, Rules::Axis axis_rule)
{
	switch(axis_rule)
	{
		default:
		case Rules::AXIS_RHS: return axl::math::Mat4f(
			(std::cos(rotate_y)), 0, (-std::sin(rotate_y)), 0,
			0, 1, 0, 0,
			(std::sin(rotate_y)), 0, (std::cos(rotate_y)), 0,
			0, 0, 0, 1
		);
		case Rules::AXIS_LHS: return axl::math::Mat4f(
			(std::cos(rotate_y)), 0, (std::sin(rotate_y)), 0,
			0, 1, 0, 0,
			(-std::sin(rotate_y)), 0, (std::cos(rotate_y)), 0,
			0, 0, 0, 1
		);
	}
}
Mat4f rotateZ(float rotate_z, Rules::Axis axis_rule)
{
	switch(axis_rule)
	{
		default:
		case Rules::AXIS_RHS: return axl::math::Mat4f(
			(std::cos(rotate_z)), (std::sin(rotate_z)), 0, 0,
			(-std::sin(rotate_z)), (std::cos(rotate_z)), 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		);
		case Rules::AXIS_LHS: return axl::math::Mat4f(
			(std::cos(rotate_z)), (-std::sin(rotate_z)), 0, 0,
			(std::sin(rotate_z)), (std::cos(rotate_z)), 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		);
	}
}

Mat4f scaleRotateX(const axl::math::Vec3f& scale, float rotate_x, Rules::Axis axis_rule)
{
	switch(axis_rule)
	{
		default:
		case Rules::AXIS_RHS: return axl::math::Mat4f(
			scale.x, 0, 0, 0,
			0, (scale.y * std::cos(rotate_x)), (scale.z * std::sin(rotate_x)), 0,
			0, (scale.y * -std::sin(rotate_x)), (scale.z * std::cos(rotate_x)), 0,
			0, 0, 0, 1
		);
		case Rules::AXIS_LHS: return axl::math::Mat4f(
			scale.x, 0, 0, 0,
			0, (scale.y * std::cos(rotate_x)), (scale.z * -std::sin(rotate_x)), 0,
			0, (scale.y * std::sin(rotate_x)), (scale.z * std::cos(rotate_x)), 0,
			0, 0, 0, 1
		);
	}
}
Mat4f scaleRotateY(const axl::math::Vec3f& scale, float rotate_y, Rules::Axis axis_rule)
{
	switch(axis_rule)
	{
		default:
		case Rules::AXIS_RHS: return axl::math::Mat4f(
			(scale.x * std::cos(rotate_y)), 0, (scale.z * -std::sin(rotate_y)), 0,
			0, scale.y, 0, 0,
			(scale.x * std::sin(rotate_y)), 0, (scale.z * std::cos(rotate_y)), 0,
			0, 0, 0, 1
		);
		case Rules::AXIS_LHS: return axl::math::Mat4f(
			(scale.x * std::cos(rotate_y)), 0, (scale.z * std::sin(rotate_y)), 0,
			0, scale.y, 0, 0,
			(scale.x * -std::sin(rotate_y)), 0, (scale.z * std::cos(rotate_y)), 0,
			0, 0, 0, 1
		);
	}
}
Mat4f scaleRotateZ(const axl::math::Vec3f& scale, float rotate_z, Rules::Axis axis_rule)
{
	switch(axis_rule)
	{
		default:
		case Rules::AXIS_RHS: return axl::math::Mat4f(
			(scale.x * std::cos(rotate_z)), (scale.y * std::sin(rotate_z)), 0, 0,
			(scale.x * -std::sin(rotate_z)), (scale.y * std::cos(rotate_z)), 0, 0,
			0, 0, scale.z, 0,
			0, 0, 0, 1
		);
		case Rules::AXIS_LHS: return axl::math::Mat4f(
			(scale.x * std::cos(rotate_z)), (scale.y * -std::sin(rotate_z)), 0, 0,
			(scale.x * std::sin(rotate_z)), (scale.y * std::cos(rotate_z)), 0, 0,
			0, 0, scale.z, 0,
			0, 0, 0, 1
		);
	}
}
Mat4f rotateXTranslate(float rotate_x, const axl::math::Vec3f& translate, Rules::Axis axis_rule)
{
	switch(axis_rule)
	{
		default:
		case Rules::AXIS_RHS: return axl::math::Mat4f(
			1, 0, 0, 0,
			0, (std::cos(rotate_x)), (std::sin(rotate_x)), 0,
			0, (-std::sin(rotate_x)), (std::cos(rotate_x)), 0,
			translate.x, translate.y, translate.z, 1
		);
		case Rules::AXIS_LHS: return axl::math::Mat4f(
			1, 0, 0, 0,
			0, (std::cos(rotate_x)), (-std::sin(rotate_x)), 0,
			0, (std::sin(rotate_x)), (std::cos(rotate_x)), 0,
			translate.x, translate.y, translate.z, 1
		);
	}
}
Mat4f rotateYTranslate(float rotate_y, const axl::math::Vec3f& translate, Rules::Axis axis_rule)
{
	switch(axis_rule)
	{
		default:
		case Rules::AXIS_RHS: return axl::math::Mat4f(
			(std::cos(rotate_y)), 0, (-std::sin(rotate_y)), 0,
			0, 1, 0, 0,
			(std::sin(rotate_y)), 0, (std::cos(rotate_y)), 0,
			translate.x, translate.y, translate.z, 1
		);
		case Rules::AXIS_LHS: return axl::math::Mat4f(
			(std::cos(rotate_y)), 0, (std::sin(rotate_y)), 0,
			0, 1, 0, 0,
			(-std::sin(rotate_y)), 0, (std::cos(rotate_y)), 0,
			translate.x, translate.y, translate.z, 1
		);
	}
}
Mat4f rotateZTranslate(float rotate_z, const axl::math::Vec3f& translate, Rules::Axis axis_rule)
{
	switch(axis_rule)
	{
		default:
		case Rules::AXIS_RHS: return axl::math::Mat4f(
			(std::cos(rotate_z)), (std::sin(rotate_z)), 0, 0,
			(-std::sin(rotate_z)), (std::cos(rotate_z)), 0, 0,
			0, 0, 1, 0,
			translate.x, translate.y, translate.z, 1
		);
		case Rules::AXIS_LHS: return axl::math::Mat4f(
			(std::cos(rotate_z)), (-std::sin(rotate_z)), 0, 0,
			(std::sin(rotate_z)), (std::cos(rotate_z)), 0, 0,
			0, 0, 1, 0,
			translate.x, translate.y, translate.z, 1
		);
	}
}


Mat4d transform(const axl::math::Vec3d& scale, const axl::math::Vec3d& rotate, const axl::math::Vec3d& translate, Rules::Axis axis_rule)
{
	switch(axis_rule)
	{
		default:
		case Rules::AXIS_RHS: return axl::math::Mat4d(
			(scale.x * std::cos(rotate.y) * std::cos(rotate.z)), (scale.x * std::sin(rotate.z)), (scale.x * -std::sin(rotate.y)), 0,
			(scale.y * -std::sin(rotate.z)), (scale.y * std::cos(rotate.x) * std::cos(rotate.z)), (scale.y * std::sin(rotate.x)), 0,
			(scale.z * std::sin(rotate.y)), (scale.z * -std::sin(rotate.x)), (scale.z * std::cos(rotate.x) * std::cos(rotate.y)), 0,
			translate.x, translate.y, translate.z, 1
		);
		case Rules::AXIS_LHS: return axl::math::Mat4d(
			(scale.x * std::cos(rotate.y) * std::cos(rotate.z)), (scale.x * -std::sin(rotate.z)), (scale.x * std::sin(rotate.y)), 0,
			(scale.y * std::sin(rotate.z)), (scale.y * std::cos(rotate.x) * std::cos(rotate.z)), (scale.y * -std::sin(rotate.x)), 0,
			(scale.z * -std::sin(rotate.y)), (scale.z * std::sin(rotate.x)), (scale.z * std::cos(rotate.x) * std::cos(rotate.y)), 0,
			translate.x, translate.y, translate.z, 1
		);
	}
}
Mat4d scale(const axl::math::Vec3d& scale)
{
	return axl::math::Mat4d(
		scale.x, 0, 0, 0,
		0, scale.y, 0, 0,
		0, 0, scale.z, 0,
		0, 0, 0, 1
	);
}
Mat4d translate(const axl::math::Vec3d& translate)
{
	return axl::math::Mat4d(
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		translate.x, translate.y, translate.z, 1
	);
}
Mat4d rotate(const axl::math::Vec3d& rotate, Rules::Axis axis_rule)
{
	switch(axis_rule)
	{
		default:
		case Rules::AXIS_RHS: return axl::math::Mat4d(
			(std::cos(rotate.y) * std::cos(rotate.z)), (std::sin(rotate.z)), (-std::sin(rotate.y)), 0,
			(-std::sin(rotate.z)), (std::cos(rotate.x) * std::cos(rotate.z)), (std::sin(rotate.x)), 0,
			(std::sin(rotate.y)), (-std::sin(rotate.x)), (std::cos(rotate.x) * std::cos(rotate.y)), 0,
			0, 0, 0, 1
		);
		case Rules::AXIS_LHS: return axl::math::Mat4d(
			(std::cos(rotate.y) * std::cos(rotate.z)), (-std::sin(rotate.z)), (std::sin(rotate.y)), 0,
			(std::sin(rotate.z)), (std::cos(rotate.x) * std::cos(rotate.z)), (-std::sin(rotate.x)), 0,
			(-std::sin(rotate.y)), (std::sin(rotate.x)), (std::cos(rotate.x) * std::cos(rotate.y)), 0,
			0, 0, 0, 1
		);
	}
}
Mat4d scaleTranslate(const axl::math::Vec3d& scale, const axl::math::Vec3d& translate)
{
	return axl::math::Mat4d(
		scale.x, 0, 0, 0,
		0, scale.y, 0, 0,
		0, 0, scale.z, 0,
		translate.x, translate.y, translate.z, 1
	);
}
Mat4d scaleRotate(const axl::math::Vec3d& scale, const axl::math::Vec3d& rotate, Rules::Axis axis_rule)
{
	switch(axis_rule)
	{
		default:
		case Rules::AXIS_RHS: return axl::math::Mat4d(
			(scale.x * std::cos(rotate.y) * std::cos(rotate.z)), (scale.x * std::sin(rotate.z)), (scale.x * -std::sin(rotate.y)), 0,
			(scale.y * -std::sin(rotate.z)), (scale.y * std::cos(rotate.x) * std::cos(rotate.z)), (scale.y * std::sin(rotate.x)), 0,
			(scale.z * std::sin(rotate.y)), (scale.z * -std::sin(rotate.x)), (scale.z * std::cos(rotate.x) * std::cos(rotate.y)), 0,
			0, 0, 0, 1
		);
		case Rules::AXIS_LHS: return axl::math::Mat4d(
			(scale.x * std::cos(rotate.y) * std::cos(rotate.z)), (scale.x * -std::sin(rotate.z)), (scale.x * std::sin(rotate.y)), 0,
			(scale.y * std::sin(rotate.z)), (scale.y * std::cos(rotate.x) * std::cos(rotate.z)), (scale.y * -std::sin(rotate.x)), 0,
			(scale.z * -std::sin(rotate.y)), (scale.z * std::sin(rotate.x)), (scale.z * std::cos(rotate.x) * std::cos(rotate.y)), 0,
			0, 0, 0, 1
		);
	}
}
Mat4d rotateTranslate(const axl::math::Vec3d& rotate, const axl::math::Vec3d& translate, Rules::Axis axis_rule)
{
	switch(axis_rule)
	{
		default:
		case Rules::AXIS_RHS: return axl::math::Mat4d(
			(std::cos(rotate.y) * std::cos(rotate.z)), (std::sin(rotate.z)), (-std::sin(rotate.y)), 0,
			(-std::sin(rotate.z)), (std::cos(rotate.x) * std::cos(rotate.z)), (std::sin(rotate.x)), 0,
			(std::sin(rotate.y)), (-std::sin(rotate.x)), (std::cos(rotate.x) * std::cos(rotate.y)), 0,
			translate.x, translate.y, translate.z, 1
		);
		case Rules::AXIS_LHS: return axl::math::Mat4d(
			(std::cos(rotate.y) * std::cos(rotate.z)), (-std::sin(rotate.z)), (std::sin(rotate.y)), 0,
			(std::sin(rotate.z)), (std::cos(rotate.x) * std::cos(rotate.z)), (-std::sin(rotate.x)), 0,
			(-std::sin(rotate.y)), (std::sin(rotate.x)), (std::cos(rotate.x) * std::cos(rotate.y)), 0,
			translate.x, translate.y, translate.z, 1
		);
	}
}
Mat4d rotateX(double rotate_x, Rules::Axis axis_rule)
{
	switch(axis_rule)
	{
		default:
		case Rules::AXIS_RHS: return axl::math::Mat4d(
			1, 0, 0, 0,
			0, (std::cos(rotate_x)), (std::sin(rotate_x)), 0,
			0, (-std::sin(rotate_x)), (std::cos(rotate_x)), 0,
			0, 0, 0, 1
		);
		case Rules::AXIS_LHS: return axl::math::Mat4d(
			1, 0, 0, 0,
			0, (std::cos(rotate_x)), (-std::sin(rotate_x)), 0,
			0, (std::sin(rotate_x)), (std::cos(rotate_x)), 0,
			0, 0, 0, 1
		);
	}
}
Mat4d rotateY(double rotate_y, Rules::Axis axis_rule)
{
	switch(axis_rule)
	{
		default:
		case Rules::AXIS_RHS: return axl::math::Mat4d(
			(std::cos(rotate_y)), 0, (-std::sin(rotate_y)), 0,
			0, 1, 0, 0,
			(std::sin(rotate_y)), 0, (std::cos(rotate_y)), 0,
			0, 0, 0, 1
		);
		case Rules::AXIS_LHS: return axl::math::Mat4d(
			(std::cos(rotate_y)), 0, (std::sin(rotate_y)), 0,
			0, 1, 0, 0,
			(-std::sin(rotate_y)), 0, (std::cos(rotate_y)), 0,
			0, 0, 0, 1
		);
	}
}
Mat4d rotateZ(double rotate_z, Rules::Axis axis_rule)
{
	switch(axis_rule)
	{
		default:
		case Rules::AXIS_RHS: return axl::math::Mat4d(
			(std::cos(rotate_z)), (std::sin(rotate_z)), 0, 0,
			(-std::sin(rotate_z)), (std::cos(rotate_z)), 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		);
		case Rules::AXIS_LHS: return axl::math::Mat4d(
			(std::cos(rotate_z)), (-std::sin(rotate_z)), 0, 0,
			(std::sin(rotate_z)), (std::cos(rotate_z)), 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		);
	}
}

Mat4d scaleRotateX(const axl::math::Vec3d& scale, double rotate_x, Rules::Axis axis_rule)
{
	switch(axis_rule)
	{
		default:
		case Rules::AXIS_RHS: return axl::math::Mat4d(
			scale.x, 0, 0, 0,
			0, (scale.y * std::cos(rotate_x)), (scale.z * std::sin(rotate_x)), 0,
			0, (scale.y * -std::sin(rotate_x)), (scale.z * std::cos(rotate_x)), 0,
			0, 0, 0, 1
		);
		case Rules::AXIS_LHS: return axl::math::Mat4d(
			scale.x, 0, 0, 0,
			0, (scale.y * std::cos(rotate_x)), (scale.z * -std::sin(rotate_x)), 0,
			0, (scale.y * std::sin(rotate_x)), (scale.z * std::cos(rotate_x)), 0,
			0, 0, 0, 1
		);
	}
}
Mat4d scaleRotateY(const axl::math::Vec3d& scale, double rotate_y, Rules::Axis axis_rule)
{
	switch(axis_rule)
	{
		default:
		case Rules::AXIS_RHS: return axl::math::Mat4d(
			(scale.x * std::cos(rotate_y)), 0, (scale.z * -std::sin(rotate_y)), 0,
			0, scale.y, 0, 0,
			(scale.x * std::sin(rotate_y)), 0, (scale.z * std::cos(rotate_y)), 0,
			0, 0, 0, 1
		);
		case Rules::AXIS_LHS: return axl::math::Mat4d(
			(scale.x * std::cos(rotate_y)), 0, (scale.z * std::sin(rotate_y)), 0,
			0, scale.y, 0, 0,
			(scale.x * -std::sin(rotate_y)), 0, (scale.z * std::cos(rotate_y)), 0,
			0, 0, 0, 1
		);
	}
}
Mat4d scaleRotateZ(const axl::math::Vec3d& scale, double rotate_z, Rules::Axis axis_rule)
{
	switch(axis_rule)
	{
		default:
		case Rules::AXIS_RHS: return axl::math::Mat4d(
			(scale.x * std::cos(rotate_z)), (scale.y * std::sin(rotate_z)), 0, 0,
			(scale.x * -std::sin(rotate_z)), (scale.y * std::cos(rotate_z)), 0, 0,
			0, 0, scale.z, 0,
			0, 0, 0, 1
		);
		case Rules::AXIS_LHS: return axl::math::Mat4d(
			(scale.x * std::cos(rotate_z)), (scale.y * -std::sin(rotate_z)), 0, 0,
			(scale.x * std::sin(rotate_z)), (scale.y * std::cos(rotate_z)), 0, 0,
			0, 0, scale.z, 0,
			0, 0, 0, 1
		);
	}
}
Mat4d rotateXTranslate(double rotate_x, const axl::math::Vec3d& translate, Rules::Axis axis_rule)
{
	switch(axis_rule)
	{
		default:
		case Rules::AXIS_RHS: return axl::math::Mat4d(
			1, 0, 0, 0,
			0, (std::cos(rotate_x)), (std::sin(rotate_x)), 0,
			0, (-std::sin(rotate_x)), (std::cos(rotate_x)), 0,
			translate.x, translate.y, translate.z, 1
		);
		case Rules::AXIS_LHS: return axl::math::Mat4d(
			1, 0, 0, 0,
			0, (std::cos(rotate_x)), (-std::sin(rotate_x)), 0,
			0, (std::sin(rotate_x)), (std::cos(rotate_x)), 0,
			translate.x, translate.y, translate.z, 1
		);
	}
}
Mat4d rotateYTranslate(double rotate_y, const axl::math::Vec3d& translate, Rules::Axis axis_rule)
{
	switch(axis_rule)
	{
		default:
		case Rules::AXIS_RHS: return axl::math::Mat4d(
			(std::cos(rotate_y)), 0, (-std::sin(rotate_y)), 0,
			0, 1, 0, 0,
			(std::sin(rotate_y)), 0, (std::cos(rotate_y)), 0,
			translate.x, translate.y, translate.z, 1
		);
		case Rules::AXIS_LHS: return axl::math::Mat4d(
			(std::cos(rotate_y)), 0, (std::sin(rotate_y)), 0,
			0, 1, 0, 0,
			(-std::sin(rotate_y)), 0, (std::cos(rotate_y)), 0,
			translate.x, translate.y, translate.z, 1
		);
	}
}
Mat4d rotateZTranslate(double rotate_z, const axl::math::Vec3d& translate, Rules::Axis axis_rule)
{
	switch(axis_rule)
	{
		default:
		case Rules::AXIS_RHS: return axl::math::Mat4d(
			(std::cos(rotate_z)), (std::sin(rotate_z)), 0, 0,
			(-std::sin(rotate_z)), (std::cos(rotate_z)), 0, 0,
			0, 0, 1, 0,
			translate.x, translate.y, translate.z, 1
		);
		case Rules::AXIS_LHS: return axl::math::Mat4d(
			(std::cos(rotate_z)), (-std::sin(rotate_z)), 0, 0,
			(std::sin(rotate_z)), (std::cos(rotate_z)), 0, 0,
			0, 0, 1, 0,
			translate.x, translate.y, translate.z, 1
		);
	}
}

} // namespace axl.math.Transform4
} // namespace axl.math
} // namespace axl
