#pragma once
#include "../lib.hpp"
#include "../rules.hpp"
#include "Mat3f.hpp"
#include "Mat3d.hpp"

namespace axl {
namespace math {
namespace Transform3 {

AXLMATHAPI Mat3f scale(const axl::math::Vec2f& scale);
AXLMATHAPI Mat3f translate(const axl::math::Vec2f& translate);
AXLMATHAPI Mat3f rotate(float theta, Rules::Axis axis_rule = Rules::DefaultAxisRule);
AXLMATHAPI Mat3f scaleTranslate(const axl::math::Vec2f& scale, const axl::math::Vec2f& translate);
AXLMATHAPI Mat3f translateScale(const axl::math::Vec2f& translate, const axl::math::Vec2f& scale);
AXLMATHAPI Mat3f scaleRotate(const axl::math::Vec2f& scale, float theta, Rules::Axis axis_rule = Rules::DefaultAxisRule);
AXLMATHAPI Mat3f rotateScale(float theta, const axl::math::Vec2f& scale, Rules::Axis axis_rule = Rules::DefaultAxisRule);
AXLMATHAPI Mat3f translateRotate(const axl::math::Vec2f& translation, float theta, Rules::Axis axis_rule = Rules::DefaultAxisRule);
AXLMATHAPI Mat3f rotateTranslate(float theta, const axl::math::Vec2f& translation, Rules::Axis axis_rule = Rules::DefaultAxisRule);
AXLMATHAPI Mat3f scaleTranslateRotate(const axl::math::Vec2f& scale, const axl::math::Vec2f& translation, float theta, Rules::Axis axis_rule = Rules::DefaultAxisRule);
AXLMATHAPI Mat3f scaleRotateTranslate(const axl::math::Vec2f& scale, float theta, const axl::math::Vec2f& translation, Rules::Axis axis_rule = Rules::DefaultAxisRule);
AXLMATHAPI Mat3f translateScaleRotate(const axl::math::Vec2f& translation, const axl::math::Vec2f& scale, float theta, Rules::Axis axis_rule = Rules::DefaultAxisRule);
AXLMATHAPI Mat3f translateRotateScale(const axl::math::Vec2f& translation, float theta, const axl::math::Vec2f& scale, Rules::Axis axis_rule = Rules::DefaultAxisRule);
AXLMATHAPI Mat3f rotateScaleTranslate(float theta, const axl::math::Vec2f& scale, const axl::math::Vec2f& translation, Rules::Axis axis_rule = Rules::DefaultAxisRule);
AXLMATHAPI Mat3f rotateTranslateScale(float theta, const axl::math::Vec2f& translation, const axl::math::Vec2f& scale, Rules::Axis axis_rule = Rules::DefaultAxisRule);


AXLMATHAPI Mat3d scale(const axl::math::Vec2d& scale);
AXLMATHAPI Mat3d translate(const axl::math::Vec2d& translate);
AXLMATHAPI Mat3d rotate(double theta, Rules::Axis axis_rule = Rules::DefaultAxisRule);
AXLMATHAPI Mat3d scaleTranslate(const axl::math::Vec2d& scale, const axl::math::Vec2d& translate);
AXLMATHAPI Mat3d translateScale(const axl::math::Vec2d& translate, const axl::math::Vec2d& scale);
AXLMATHAPI Mat3d scaleRotate(const axl::math::Vec2d& scale, double theta, Rules::Axis axis_rule = Rules::DefaultAxisRule);
AXLMATHAPI Mat3d rotateScale(double theta, const axl::math::Vec2d& scale, Rules::Axis axis_rule = Rules::DefaultAxisRule);
AXLMATHAPI Mat3d translateRotate(const axl::math::Vec2d& translation, double theta, Rules::Axis axis_rule = Rules::DefaultAxisRule);
AXLMATHAPI Mat3d rotateTranslate(double theta, const axl::math::Vec2d& translation, Rules::Axis axis_rule = Rules::DefaultAxisRule);
AXLMATHAPI Mat3d scaleTranslateRotate(const axl::math::Vec2d& scale, const axl::math::Vec2d& translation, double theta, Rules::Axis axis_rule = Rules::DefaultAxisRule);
AXLMATHAPI Mat3d scaleRotateTranslate(const axl::math::Vec2d& scale, double theta, const axl::math::Vec2d& translation, Rules::Axis axis_rule = Rules::DefaultAxisRule);
AXLMATHAPI Mat3d translateScaleRotate(const axl::math::Vec2d& translation, const axl::math::Vec2d& scale, double theta, Rules::Axis axis_rule = Rules::DefaultAxisRule);
AXLMATHAPI Mat3d translateRotateScale(const axl::math::Vec2d& translation, double theta, const axl::math::Vec2d& scale, Rules::Axis axis_rule = Rules::DefaultAxisRule);
AXLMATHAPI Mat3d rotateScaleTranslate(double theta, const axl::math::Vec2d& scale, const axl::math::Vec2d& translation, Rules::Axis axis_rule = Rules::DefaultAxisRule);
AXLMATHAPI Mat3d rotateTranslateScale(double theta, const axl::math::Vec2d& translation, const axl::math::Vec2d& scale, Rules::Axis axis_rule = Rules::DefaultAxisRule);

} // namespace axl.math.Transform3
} // namespace axl.math
} // namespace axl
