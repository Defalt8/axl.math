#pragma once
#include "../lib.hpp"
#include "../rules.hpp"
#include "../orders.hpp"
#include "../vec/vec3f.hpp"
#include "../vec/vec4f.hpp"
#include "../mat/Mat4f.hpp"

namespace axl {
namespace math {

class AXLMATHCXXAPI Transform4f
{
	public:
		Transform4f(const Vec3f& scale = Vec3f(1.0f,1.0f,1.0f),
			const Vec3f& position = Vec3f(0.0f,0.0f,0.0f),
			const Vec3f& rotation = Vec3f(0.0f,0.0f,0.0f),
			Orders::Transform transform_order = Orders::Transform::STR,
			Orders::Rotation rotation_order = Orders::Rotation::XYZ,
			Rules::Axis axis_rule = Rules::DefaultAxisRule);
		void setScale(const Vec3f& scale, bool update_matrix = true);
		void setPosition(const Vec3f& position, bool update_matrix = true);
		void setRotation(const Vec3f& rotation, bool update_matrix = true);
		void setRotation(const Vec3f& rotation, Orders::Rotation rotation_order,
			Rules::Axis axis_rule = Rules::DefaultAxisRule,
			bool update_matrix = true);
		void setTransformOrder(Orders::Transform transform_order = Orders::Transform::STR, bool update_matrix = true);
		void setRotationOrder(Orders::Rotation rotation_order = Orders::Rotation::XYZ, bool update_matrix = true);
		void setAxisRule(Rules::Axis axis_rule = Rules::DefaultAxisRule, bool update_matrix = true);
		bool isUpdated() const;
		const Mat4f& getMatrix() const;
		const Vec3f& getScale() const;
		const Vec3f& getPosition() const;
		const Vec3f& getRotation() const;
		Orders::Transform getTransformOrder() const;
		Orders::Rotation getRotationOrder() const;
		Rules::Axis getAxisRule() const;
		void updateMatrix();
		Vec3f transform(const Vec3f& vec) const;
		Vec4f transform(const Vec4f& vec) const;
	private:
		bool m_is_updated;
		Mat4f m_matrix;
		Vec3f m_scale;
		Vec3f m_position;
		Vec3f m_rotation;
		Orders::Transform m_transform_order;
		Orders::Rotation m_rotation_order;
		Rules::Axis m_axis_rule;
};

} // axl.math
} // axl
