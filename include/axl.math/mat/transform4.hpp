#pragma once
#include "../lib.hpp"
#include "../rules.hpp"
#include "Mat4f.hpp"
#include "Mat4d.hpp"

namespace axl {
namespace math {
namespace Transform4 {

Mat4f AXLMATHAPI transform(const axl::math::Vec3f& scale, const axl::math::Vec3f& rotate, const axl::math::Vec3f& translate, Rules::Axis axis_rule = Rules::AXIS_RHS);
Mat4f AXLMATHAPI scale(const axl::math::Vec3f& scale);
Mat4f AXLMATHAPI translate(const axl::math::Vec3f& translate);
Mat4f AXLMATHAPI rotate(const axl::math::Vec3f& rotate, Rules::Axis axis_rule = Rules::AXIS_RHS);
Mat4f AXLMATHAPI scaleTranslate(const axl::math::Vec3f& scale, const axl::math::Vec3f& translate);
Mat4f AXLMATHAPI scaleRotate(const axl::math::Vec3f& scale, const axl::math::Vec3f& rotate, Rules::Axis axis_rule = Rules::AXIS_RHS);
Mat4f AXLMATHAPI rotateTranslate(const axl::math::Vec3f& rotate, const axl::math::Vec3f& translate, Rules::Axis axis_rule = Rules::AXIS_RHS);
Mat4f AXLMATHAPI rotateX(float rotate_x, Rules::Axis axis_rule = Rules::AXIS_RHS);
Mat4f AXLMATHAPI rotateY(float rotate_y, Rules::Axis axis_rule = Rules::AXIS_RHS);
Mat4f AXLMATHAPI rotateZ(float rotate_z, Rules::Axis axis_rule = Rules::AXIS_RHS);
Mat4f AXLMATHAPI scaleRotateX(const axl::math::Vec3f& scale, float rotate_x, Rules::Axis axis_rule = Rules::AXIS_RHS);
Mat4f AXLMATHAPI scaleRotateY(const axl::math::Vec3f& scale, float rotate_y, Rules::Axis axis_rule = Rules::AXIS_RHS);
Mat4f AXLMATHAPI scaleRotateZ(const axl::math::Vec3f& scale, float rotate_z, Rules::Axis axis_rule = Rules::AXIS_RHS);
Mat4f AXLMATHAPI rotateXTranslate(float rotate_x, const axl::math::Vec3f& translate, Rules::Axis axis_rule = Rules::AXIS_RHS);
Mat4f AXLMATHAPI rotateYTranslate(float rotate_y, const axl::math::Vec3f& translate, Rules::Axis axis_rule = Rules::AXIS_RHS);
Mat4f AXLMATHAPI rotateZTranslate(float rotate_z, const axl::math::Vec3f& translate, Rules::Axis axis_rule = Rules::AXIS_RHS);

Mat4d AXLMATHAPI transform(const axl::math::Vec3d& scale, const axl::math::Vec3d& rotate, const axl::math::Vec3d& translate, Rules::Axis axis_rule = Rules::AXIS_RHS);
Mat4d AXLMATHAPI scale(const axl::math::Vec3d& scale);
Mat4d AXLMATHAPI translate(const axl::math::Vec3d& translate);
Mat4d AXLMATHAPI rotate(const axl::math::Vec3d& rotate, Rules::Axis axis_rule = Rules::AXIS_RHS);
Mat4d AXLMATHAPI scaleTranslate(const axl::math::Vec3d& scale, const axl::math::Vec3d& translate);
Mat4d AXLMATHAPI scaleRotate(const axl::math::Vec3d& scale, const axl::math::Vec3d& rotate, Rules::Axis axis_rule = Rules::AXIS_RHS);
Mat4d AXLMATHAPI rotateTranslate(const axl::math::Vec3d& rotate, const axl::math::Vec3d& translate, Rules::Axis axis_rule = Rules::AXIS_RHS);
Mat4d AXLMATHAPI rotateX(double rotate_x, Rules::Axis axis_rule = Rules::AXIS_RHS);
Mat4d AXLMATHAPI rotateY(double rotate_y, Rules::Axis axis_rule = Rules::AXIS_RHS);
Mat4d AXLMATHAPI rotateZ(double rotate_z, Rules::Axis axis_rule = Rules::AXIS_RHS);
Mat4d AXLMATHAPI scaleRotateX(const axl::math::Vec3d& scale, double rotate_x, Rules::Axis axis_rule = Rules::AXIS_RHS);
Mat4d AXLMATHAPI scaleRotateY(const axl::math::Vec3d& scale, double rotate_y, Rules::Axis axis_rule = Rules::AXIS_RHS);
Mat4d AXLMATHAPI scaleRotateZ(const axl::math::Vec3d& scale, double rotate_z, Rules::Axis axis_rule = Rules::AXIS_RHS);
Mat4d AXLMATHAPI rotateXTranslate(double rotate_x, const axl::math::Vec3d& translate, Rules::Axis axis_rule = Rules::AXIS_RHS);
Mat4d AXLMATHAPI rotateYTranslate(double rotate_y, const axl::math::Vec3d& translate, Rules::Axis axis_rule = Rules::AXIS_RHS);
Mat4d AXLMATHAPI rotateZTranslate(double rotate_z, const axl::math::Vec3d& translate, Rules::Axis axis_rule = Rules::AXIS_RHS);

} // namespace axl.math.Transform4
} // namespace axl.math
} // namespace axl
