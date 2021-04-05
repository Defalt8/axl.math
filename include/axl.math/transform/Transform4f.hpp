#pragma once
#include "../lib.hpp"
#include "../rules.hpp"
#include "../orders.hpp"
#include "../vec/vec3f.hpp"
#include "../mat/Mat4f.hpp"

namespace axl {
namespace math {

class AXLMATHCXXAPI Transform4f
{
	public:
		Transform4f(const axl::math::Vec3f& scale = axl::math::Vec3f(1.0f,1.0f,1.0f),
			const axl::math::Vec3f& position = axl::math::Vec3f(0.0f,0.0f,0.0f),
			const axl::math::Vec3f& rotation = axl::math::Vec3f(0.0f,0.0f,0.0f),
			Orders::Transform transform_order = Orders::Transform::STR,
			Orders::Rotation rotation_order = Orders::Rotation::XYZ,
			axl::math::Rules::Axis axis_rule = axl::math::Rules::DefaultAxisRule);
		void setScale(const axl::math::Vec3f& scale, bool update_matrix = true);
		void setPosition(const axl::math::Vec3f& position, bool update_matrix = true);
		void setRotation(const axl::math::Vec3f& rotation, bool update_matrix = true);
		void setRotation(const axl::math::Vec3f& rotation,
			Orders::Rotation rotation_order = Orders::Rotation::XYZ,
			axl::math::Rules::Axis axis_rule = axl::math::Rules::DefaultAxisRule,
			bool update_matrix = true);
		void setTransformOrder(Orders::Transform transform_order = Orders::Transform::STR, bool update_matrix = true);
		void setRotationOrder(Orders::Rotation rotation_order = Orders::Rotation::XYZ, bool update_matrix = true);
		void setAxisRule(axl::math::Rules::Axis axis_rule = axl::math::Rules::DefaultAxisRule, bool update_matrix = true);
		bool isUpdated() const;
		const axl::math::Mat4f& getMatrix() const;
		const axl::math::Vec3f& getScale() const;
		const axl::math::Vec3f& getPosition() const;
		const axl::math::Vec3f& getRotation() const;
		Orders::Transform getTransformOrder() const;
		Orders::Rotation getRotationOrder() const;
		axl::math::Rules::Axis getAxisRule() const;
		void updateMatrix();
	private:
		bool m_is_updated;
		axl::math::Mat4f m_matrix;
		axl::math::Vec3f m_scale;
		axl::math::Vec3f m_position;
		axl::math::Vec3f m_rotation;
		Orders::Transform m_transform_order;
		Orders::Rotation m_rotation_order;
		axl::math::Rules::Axis m_axis_rule;
};

} // axl.math
} // axl
