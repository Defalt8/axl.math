#pragma once
#include "../lib.hpp"
#include "../rules.hpp"
#include "Mat4f.hpp"
#include "Mat4d.hpp"

namespace axl {
namespace math {
namespace Transform4 {
	
Mat4f AXLMATHAPI scale(const axl::math::Vec3f& scale);
Mat4f AXLMATHAPI translate(const axl::math::Vec3f& translate);
// Scale then translate
Mat4f AXLMATHAPI scaleTranslate(const axl::math::Vec3f& scale, const axl::math::Vec3f& translate);
// Translate then scale
Mat4f AXLMATHAPI translateScale(const axl::math::Vec3f& translate, const axl::math::Vec3f& scale);
Mat4f AXLMATHAPI rotateX(float rotation_x, Rules::Axis axis_rule = Rules::DefaultAxisRule);
Mat4f AXLMATHAPI rotateY(float rotation_y, Rules::Axis axis_rule = Rules::DefaultAxisRule);
Mat4f AXLMATHAPI rotateZ(float rotation_z, Rules::Axis axis_rule = Rules::DefaultAxisRule);
Mat4f AXLMATHAPI rotateXY(const axl::math::Vec3f& rotation, Rules::Axis axis_rule = Rules::DefaultAxisRule);
Mat4f AXLMATHAPI rotateXZ(const axl::math::Vec3f& rotation, Rules::Axis axis_rule = Rules::DefaultAxisRule);
Mat4f AXLMATHAPI rotateYX(const axl::math::Vec3f& rotation, Rules::Axis axis_rule = Rules::DefaultAxisRule);
Mat4f AXLMATHAPI rotateYZ(const axl::math::Vec3f& rotation, Rules::Axis axis_rule = Rules::DefaultAxisRule);
Mat4f AXLMATHAPI rotateZX(const axl::math::Vec3f& rotation, Rules::Axis axis_rule = Rules::DefaultAxisRule);
Mat4f AXLMATHAPI rotateZY(const axl::math::Vec3f& rotation, Rules::Axis axis_rule = Rules::DefaultAxisRule);
Mat4f AXLMATHAPI rotateXYZ(const axl::math::Vec3f& rotation, Rules::Axis axis_rule = Rules::DefaultAxisRule);
Mat4f AXLMATHAPI rotateXZY(const axl::math::Vec3f& rotation, Rules::Axis axis_rule = Rules::DefaultAxisRule);
Mat4f AXLMATHAPI rotateYXZ(const axl::math::Vec3f& rotation, Rules::Axis axis_rule = Rules::DefaultAxisRule);
Mat4f AXLMATHAPI rotateYZX(const axl::math::Vec3f& rotation, Rules::Axis axis_rule = Rules::DefaultAxisRule);
Mat4f AXLMATHAPI rotateZXY(const axl::math::Vec3f& rotation, Rules::Axis axis_rule = Rules::DefaultAxisRule);
Mat4f AXLMATHAPI rotateZYX(const axl::math::Vec3f& rotation, Rules::Axis axis_rule = Rules::DefaultAxisRule);


Mat4d AXLMATHAPI scale(const axl::math::Vec3d& scale);
Mat4d AXLMATHAPI translate(const axl::math::Vec3d& translate);
// Scale then translate
Mat4d AXLMATHAPI scaleTranslate(const axl::math::Vec3d& scale, const axl::math::Vec3d& translate);
// Translate then scale
Mat4d AXLMATHAPI translateScale(const axl::math::Vec3d& translate, const axl::math::Vec3d& scale);
Mat4d AXLMATHAPI rotateX(double rotation_x, Rules::Axis axis_rule = Rules::DefaultAxisRule);
Mat4d AXLMATHAPI rotateY(double rotation_y, Rules::Axis axis_rule = Rules::DefaultAxisRule);
Mat4d AXLMATHAPI rotateZ(double rotation_z, Rules::Axis axis_rule = Rules::DefaultAxisRule);
Mat4d AXLMATHAPI rotateXY(const axl::math::Vec3d& rotation, Rules::Axis axis_rule = Rules::DefaultAxisRule);
Mat4d AXLMATHAPI rotateXZ(const axl::math::Vec3d& rotation, Rules::Axis axis_rule = Rules::DefaultAxisRule);
Mat4d AXLMATHAPI rotateYX(const axl::math::Vec3d& rotation, Rules::Axis axis_rule = Rules::DefaultAxisRule);
Mat4d AXLMATHAPI rotateYZ(const axl::math::Vec3d& rotation, Rules::Axis axis_rule = Rules::DefaultAxisRule);
Mat4d AXLMATHAPI rotateZX(const axl::math::Vec3d& rotation, Rules::Axis axis_rule = Rules::DefaultAxisRule);
Mat4d AXLMATHAPI rotateZY(const axl::math::Vec3d& rotation, Rules::Axis axis_rule = Rules::DefaultAxisRule);
Mat4d AXLMATHAPI rotateXYZ(const axl::math::Vec3d& rotation, Rules::Axis axis_rule = Rules::DefaultAxisRule);
Mat4d AXLMATHAPI rotateXZY(const axl::math::Vec3d& rotation, Rules::Axis axis_rule = Rules::DefaultAxisRule);
Mat4d AXLMATHAPI rotateYXZ(const axl::math::Vec3d& rotation, Rules::Axis axis_rule = Rules::DefaultAxisRule);
Mat4d AXLMATHAPI rotateYZX(const axl::math::Vec3d& rotation, Rules::Axis axis_rule = Rules::DefaultAxisRule);
Mat4d AXLMATHAPI rotateZXY(const axl::math::Vec3d& rotation, Rules::Axis axis_rule = Rules::DefaultAxisRule);
Mat4d AXLMATHAPI rotateZYX(const axl::math::Vec3d& rotation, Rules::Axis axis_rule = Rules::DefaultAxisRule);

} // namespace axl.math.Transform4
} // namespace axl.math
} // namespace axl
