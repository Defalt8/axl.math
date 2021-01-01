	#include <cmath>
#include <axl.math/lib.hpp>
#include <axl.math/mat/Mat4f.hpp>
#include <axl.math/mat/Mat4d.hpp>
#include <axl.math/mat/transform4.hpp>

namespace axl {
namespace math {
namespace Transform4 {

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
Mat4f rotateX(float rotation_x, Rules::Axis axis_rule)
{
	switch (axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: break;
		case Rules::Axis::AXIS_LHS: rotation_x = -rotation_x; break;
	}
	return axl::math::Mat4f(
		1, 0, 0, 0,
		0, std::cos(rotation_x), std::sin(rotation_x), 0,
		0, -std::sin(rotation_x), std::cos(rotation_x), 0,
		0, 0, 0, 1
	);
}
Mat4f rotateY(float rotation_y, Rules::Axis axis_rule)
{
	switch (axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: break;
		case Rules::Axis::AXIS_LHS: rotation_y = -rotation_y; break;
	}
	return axl::math::Mat4f(
		std::cos(rotation_y), 0, -std::sin(rotation_y), 0,
		0, 1, 0, 0,
		std::sin(rotation_y), 0, std::cos(rotation_y), 0,
		0, 0, 0, 1
	);
}
Mat4f rotateZ(float rotation_z, Rules::Axis axis_rule)
{
	switch (axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: break;
		case Rules::Axis::AXIS_LHS: rotation_z = -rotation_z; break;
	}
	return axl::math::Mat4f(
		std::cos(rotation_z), std::sin(rotation_z), 0, 0,
		-std::sin(rotation_z), std::cos(rotation_z), 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	);
}
Mat4f rotateXY(const axl::math::Vec3f& rotation, Rules::Axis axis_rule)
{
	float alpha, beta;
	switch(axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: alpha = rotation.x; beta = rotation.y; break;
		case Rules::Axis::AXIS_LHS: alpha = -rotation.x; beta = -rotation.y; break;
	}
	return Mat4f(
		std::cos(beta), std::sin(alpha) * std::sin(beta), -std::cos(alpha) * std::sin(beta), 0,
		0, std::cos(alpha), std::sin(alpha), 0,
		std::sin(beta), -std::sin(alpha) * std::cos(beta), std::cos(alpha) * std::cos(beta), 0,
		0, 0, 0, 1
	);
}
Mat4f rotateXZ(const axl::math::Vec3f& rotation, Rules::Axis axis_rule)
{
	float alpha, gamma;
	switch(axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: alpha = rotation.x; gamma = rotation.z; break;
		case Rules::Axis::AXIS_LHS: alpha = -rotation.x; gamma = -rotation.z; break;
	}
	return Mat4f(
		std::cos(gamma), std::cos(alpha) * std::sin(gamma), std::sin(alpha) * std::sin(gamma), 0,
		-std::sin(gamma), std::cos(alpha) * std::cos(gamma), std::sin(alpha) * std::cos(gamma), 0,
		0, -std::sin(alpha), std::cos(alpha), 0,
		0, 0, 0, 1
	);
}
Mat4f rotateYX(const axl::math::Vec3f& rotation, Rules::Axis axis_rule)
{
	float alpha, beta;
	switch(axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: alpha = rotation.x; beta = rotation.y; break;
		case Rules::Axis::AXIS_LHS: alpha = -rotation.x; beta = -rotation.y; break;
	}
	return Mat4f(
		std::cos(beta), 0, -std::sin(beta), 0,
		std::sin(beta) * std::sin(alpha), std::cos(alpha), std::cos(beta) * std::sin(alpha), 0,
		std::sin(beta) * std::cos(alpha), -std::sin(alpha), std::cos(beta) * std::cos(alpha), 0,
		0, 0, 0, 1
	);
}
Mat4f rotateYZ(const axl::math::Vec3f& rotation, Rules::Axis axis_rule)
{
	float beta, gamma;
	switch (axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: beta = rotation.y; gamma = rotation.z; break;
		case Rules::Axis::AXIS_LHS: beta = -rotation.y; gamma = -rotation.z; break;
	}
	return Mat4f(
		std::cos(beta) * std::cos(gamma), std::sin(gamma), -std::sin(beta) * std::cos(gamma), 0,
		-std::cos(beta) * std::sin(gamma), std::cos(gamma), std::sin(beta) * std::sin(gamma), 0,
		std::sin(beta), 0, std::cos(beta), 0,
		0, 0, 0, 1
	);
}
Mat4f rotateZX(const axl::math::Vec3f& rotation, Rules::Axis axis_rule)
{
	float alpha, gamma;
	switch (axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: alpha = rotation.x; gamma = rotation.z; break;
		case Rules::Axis::AXIS_LHS: alpha = -rotation.x; gamma = -rotation.z; break;
	}
	return Mat4f(
		std::cos(gamma), std::sin(gamma), 0, 0,
		-std::sin(gamma) * std::cos(alpha), std::cos(gamma) * std::cos(alpha), std::sin(alpha), 0,
		std::sin(gamma) * std::sin(alpha), -std::cos(gamma) * std::sin(alpha), std::cos(alpha), 0,
		0, 0, 0, 1
	);
}
Mat4f rotateZY(const axl::math::Vec3f& rotation, Rules::Axis axis_rule)
{
	float beta, gamma;
	switch(axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: beta = rotation.y; gamma = rotation.z; break;
		case Rules::Axis::AXIS_LHS: beta = -rotation.y; gamma = -rotation.z; break;
	}
	return Mat4f(
		std::cos(gamma) * std::cos(beta), std::sin(gamma) * std::cos(beta), -std::sin(beta), 0,
		-std::sin(gamma), std::cos(gamma), 0, 0,
		std::cos(gamma) * std::sin(beta), std::sin(gamma) * std::sin(beta), std::cos(beta), 0,
		0, 0, 0, 1
	);
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
Mat4d rotateX(double rotation_x, Rules::Axis axis_rule)
{
	switch (axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: break;
		case Rules::Axis::AXIS_LHS: rotation_x = -rotation_x; break;
	}
	return axl::math::Mat4d(
		1, 0, 0, 0,
		0, std::cos(rotation_x), std::sin(rotation_x), 0,
		0, -std::sin(rotation_x), std::cos(rotation_x), 0,
		0, 0, 0, 1
	);
}
Mat4d rotateY(double rotation_y, Rules::Axis axis_rule)
{
	switch (axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: break;
		case Rules::Axis::AXIS_LHS: rotation_y = -rotation_y; break;
	}
	return axl::math::Mat4d(
		std::cos(rotation_y), 0, -std::sin(rotation_y), 0,
		0, 1, 0, 0,
		std::sin(rotation_y), 0, std::cos(rotation_y), 0,
		0, 0, 0, 1
	);
}
Mat4d rotateZ(double rotation_z, Rules::Axis axis_rule)
{
	switch (axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: break;
		case Rules::Axis::AXIS_LHS: rotation_z = -rotation_z; break;
	}
	return axl::math::Mat4d(
		std::cos(rotation_z), std::sin(rotation_z), 0, 0,
		-std::sin(rotation_z), std::cos(rotation_z), 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	);
}
Mat4d rotateXY(const axl::math::Vec3d& rotation, Rules::Axis axis_rule)
{
	double alpha, beta;
	switch (axis_rule)
	{
		case Rules::Axis::AXIS_RHS: alpha = rotation.x; beta = rotation.y; break;
		case Rules::Axis::AXIS_LHS: alpha = -rotation.x; beta = -rotation.y; break;
	}
	return Mat4d(
		std::cos(beta), std::sin(alpha) * std::sin(beta), -std::cos(alpha) * std::sin(beta), 0,
		0, std::cos(alpha), std::sin(alpha), 0,
		std::sin(beta), -std::sin(alpha) * std::cos(beta), std::cos(alpha) * std::cos(beta), 0,
		0, 0, 0, 1
	);
}
Mat4d rotateXZ(const axl::math::Vec3d& rotation, Rules::Axis axis_rule)
{
	double alpha, gamma;
	switch (axis_rule)
	{
		case Rules::Axis::AXIS_RHS: alpha = rotation.x; gamma = rotation.z; break;
		case Rules::Axis::AXIS_LHS: alpha = -rotation.x; gamma = -rotation.z; break;
	}
	return Mat4d(
		std::cos(gamma), std::cos(alpha) * std::sin(gamma), std::sin(alpha) * std::sin(gamma), 0,
		-std::sin(gamma), std::cos(alpha) * std::cos(gamma), std::sin(alpha) * std::cos(gamma), 0,
		0, -std::sin(alpha), std::cos(alpha), 0,
		0, 0, 0, 1
	);
}
Mat4d rotateYX(const axl::math::Vec3d& rotation, Rules::Axis axis_rule)
{
	double alpha, beta;
	switch (axis_rule)
	{
		case Rules::Axis::AXIS_RHS: alpha = rotation.x; beta = rotation.y; break;
		case Rules::Axis::AXIS_LHS: alpha = -rotation.x; beta = -rotation.y; break;
	}
	return Mat4d(
		std::cos(beta), 0, -std::sin(beta), 0,
		std::sin(beta) * std::sin(alpha), std::cos(alpha), std::cos(beta) * std::sin(alpha), 0,
		std::sin(beta) * std::cos(alpha), -std::sin(alpha), std::cos(beta) * std::cos(alpha), 0,
		0, 0, 0, 1
	);
}
Mat4d rotateYZ(const axl::math::Vec3d& rotation, Rules::Axis axis_rule)
{
	double beta, gamma;
	switch (axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: beta = rotation.y; gamma = rotation.z; break;
		case Rules::Axis::AXIS_LHS: beta = -rotation.y; gamma = -rotation.z; break;
	}
	return Mat4d(
		std::cos(beta) * std::cos(gamma), std::sin(gamma), -std::sin(beta) * std::cos(gamma), 0,
		-std::cos(beta) * std::sin(gamma), std::cos(gamma), std::sin(beta) * std::sin(gamma), 0,
		std::sin(beta), 0, std::cos(beta), 0,
		0, 0, 0, 1
	);
}
Mat4d rotateZX(const axl::math::Vec3d& rotation, Rules::Axis axis_rule)
{
	double alpha, gamma;
	switch (axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: alpha = rotation.x; gamma = rotation.z; break;
		case Rules::Axis::AXIS_LHS: alpha = -rotation.x; gamma = -rotation.z; break;
	}
	return Mat4d(
		std::cos(gamma), std::sin(gamma), 0, 0,
		-std::sin(gamma) * std::cos(alpha), std::cos(gamma) * std::cos(alpha), std::sin(alpha), 0,
		std::sin(gamma) * std::sin(alpha), -std::cos(gamma) * std::sin(alpha), std::cos(alpha), 0,
		0, 0, 0, 1
	);
}
Mat4d rotateZY(const axl::math::Vec3d& rotation, Rules::Axis axis_rule)
{
	double beta, gamma;
	switch (axis_rule)
	{
		default:
		case Rules::Axis::AXIS_RHS: beta = rotation.y; gamma = rotation.z; break;
		case Rules::Axis::AXIS_LHS: beta = -rotation.y; gamma = -rotation.z; break;
	}
	return Mat4d(
		std::cos(gamma) * std::cos(beta), std::sin(gamma) * std::cos(beta), -std::sin(beta), 0,
		-std::sin(gamma), std::cos(gamma), 0, 0,
		std::cos(gamma) * std::sin(beta), std::sin(gamma) * std::sin(beta), std::cos(beta), 0,
		0, 0, 0, 1
	);
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

} // namespace axl.math.Transform4
} // namespace axl.math
} // namespace axl
