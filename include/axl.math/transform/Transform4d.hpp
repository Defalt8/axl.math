#pragma once
#include "../lib.hpp"
#include "../rules.hpp"
#include "../orders.hpp"
#include "../vec/vec3f.hpp"
#include "../vec/vec4f.hpp"
#include "../mat/Mat4d.hpp"

namespace axl {
namespace math {

class AXLMATHCXXAPI Transform4d
{
	public:
		Transform4d(const Vec3d& scale = Vec3d(1.0f,1.0f,1.0f),
			const Vec3d& position = Vec3d(0.0f,0.0f,0.0f),
			const Vec3d& rotation = Vec3d(0.0f,0.0f,0.0f),
			Orders::Transform transform_order = Orders::Transform::STR,
			Orders::Rotation rotation_order = Orders::Rotation::XYZ,
			Rules::Axis axis_rule = Rules::DefaultAxisRule);
		void setScale(const Vec3d& scale, bool update_matrix = true);
		void setPosition(const Vec3d& position, bool update_matrix = true);
		void setRotation(const Vec3d& rotation, bool update_matrix = true);
		void setRotation(const Vec3d& rotation, Orders::Rotation rotation_order,
			Rules::Axis axis_rule = Rules::DefaultAxisRule,
			bool update_matrix = true);
		void setTransformOrder(Orders::Transform transform_order = Orders::Transform::STR, bool update_matrix = true);
		void setRotationOrder(Orders::Rotation rotation_order = Orders::Rotation::XYZ, bool update_matrix = true);
		void setAxisRule(Rules::Axis axis_rule = Rules::DefaultAxisRule, bool update_matrix = true);
		bool isUpdated() const;
		const Mat4d& getMatrix() const;
		const Vec3d& getScale() const;
		const Vec3d& getPosition() const;
		const Vec3d& getRotation() const;
		Orders::Transform getTransformOrder() const;
		Orders::Rotation getRotationOrder() const;
		Rules::Axis getAxisRule() const;
		void updateMatrix();
		Vec3d transform(const Vec3d& vec) const;
		Vec4d transform(const Vec4d& vec) const;
	private:
		bool m_is_updated;
		Mat4d m_matrix;
		Vec3d m_scale;
		Vec3d m_position;
		Vec3d m_rotation;
		Orders::Transform m_transform_order;
		Orders::Rotation m_rotation_order;
		Rules::Axis m_axis_rule;
};

} // axl.math
} // axl
