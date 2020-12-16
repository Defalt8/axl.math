#pragma once
#include "../lib.hpp"
#include "../rules.hpp"
#include "Mat3f.hpp"
#include "Mat3d.hpp"

namespace axl {
namespace math {
namespace Transform3 {

Mat3f AXLMATHAPI transform(const axl::math::Vec2f& scale, float rotate, const axl::math::Vec2f& translate, Rules::Axis axis_rule = Rules::AXIS_RHS);
Mat3f AXLMATHAPI scale(const axl::math::Vec2f& scale);
Mat3f AXLMATHAPI translate(const axl::math::Vec2f& translate);
Mat3f AXLMATHAPI rotate(float rotate, Rules::Axis axis_rule = Rules::AXIS_RHS);
Mat3f AXLMATHAPI scaleTranslate(const axl::math::Vec2f& scale, const axl::math::Vec2f& translate);
Mat3f AXLMATHAPI scaleRotate(const axl::math::Vec2f& scale, float rotate, Rules::Axis axis_rule = Rules::AXIS_RHS);
Mat3f AXLMATHAPI rotateTranslate(float rotate, const axl::math::Vec2f& translate, Rules::Axis axis_rule = Rules::AXIS_RHS);

Mat3d AXLMATHAPI transform(const axl::math::Vec2d& scale, double rotate, const axl::math::Vec2d& translate, Rules::Axis axis_rule = Rules::AXIS_RHS);
Mat3d AXLMATHAPI scale(const axl::math::Vec2d& scale);
Mat3d AXLMATHAPI translate(const axl::math::Vec2d& translate);
Mat3d AXLMATHAPI rotate(double rotate, Rules::Axis axis_rule = Rules::AXIS_RHS);
Mat3d AXLMATHAPI scaleTranslate(const axl::math::Vec2d& scale, const axl::math::Vec2d& translate);
Mat3d AXLMATHAPI scaleRotate(const axl::math::Vec2d& scale, double rotate, Rules::Axis axis_rule = Rules::AXIS_RHS);
Mat3d AXLMATHAPI rotateTranslate(double rotate, const axl::math::Vec2d& translate, Rules::Axis axis_rule = Rules::AXIS_RHS);

} // namespace axl.math.Transform3
} // namespace axl.math
} // namespace axl
