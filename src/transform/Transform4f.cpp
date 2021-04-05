#include <axl.math/lib.hpp>
#include <axl.math/mat/Transform4.hpp>
#include <axl.math/transform/Transform4f.hpp>

namespace axl {
namespace math {

Transform4f::Transform4f(const Vec3f& scale, const Vec3f& position, const Vec3f& rotation, Orders::Transform transform_order, Orders::Rotation rotation_order, Rules::Axis axis_rule) :
	m_is_updated(false),
	m_scale(scale),
	m_position(position),
	m_rotation(rotation),
	m_transform_order(transform_order),
	m_rotation_order(rotation_order),
	m_axis_rule(axis_rule)
{
	this->updateMatrix();
}
void Transform4f::setScale(const Vec3f& scale, bool update_matrix)
{
	this->m_is_updated = false;
	this->m_scale = scale;
	if(update_matrix)
		this->updateMatrix();
}
void Transform4f::setPosition(const Vec3f& position, bool update_matrix)
{
	this->m_is_updated = false;
	this->m_position = position;
	if(update_matrix)
		this->updateMatrix();
}
void Transform4f::setRotation(const Vec3f& rotation, bool update_matrix)
{
	this->m_is_updated = false;
	this->m_rotation = rotation;
	if(update_matrix)
		this->updateMatrix();
}
void Transform4f::setRotation(const Vec3f& rotation, Orders::Rotation rotation_order, Rules::Axis axis_rule, bool update_matrix)
{
	this->m_is_updated = false;
	this->m_rotation = rotation;
	this->m_rotation_order = rotation_order;
	this->m_axis_rule = axis_rule;
	if(update_matrix)
		this->updateMatrix();
}
void Transform4f::setTransformOrder(Orders::Transform transform_order, bool update_matrix)
{
	this->m_is_updated = false;
	this->m_transform_order = transform_order;
	if(update_matrix)
		this->updateMatrix();
}
void Transform4f::setRotationOrder(Orders::Rotation rotation_order, bool update_matrix)
{
	this->m_is_updated = false;
	this->m_rotation_order = rotation_order;
	if(update_matrix)
		this->updateMatrix();
}
void Transform4f::setAxisRule(Rules::Axis axis_rule, bool update_matrix)
{
	this->m_is_updated = false;
	this->m_axis_rule = axis_rule;
	if(update_matrix)
		this->updateMatrix();
}
bool Transform4f::isUpdated() const
{
	return this->m_is_updated;
}
const Mat4f& Transform4f::getMatrix() const
{
	return this->m_matrix;
}
const Vec3f& Transform4f::getScale() const
{
	return this->m_scale;
}
const Vec3f& Transform4f::getPosition() const
{
	return this->m_position;
}
const Vec3f& Transform4f::getRotation() const
{
	return this->m_rotation;
}
Orders::Transform Transform4f::getTransformOrder() const
{
	return this->m_transform_order;
}
Orders::Rotation Transform4f::getRotationOrder() const
{
	return this->m_rotation_order;
}
Rules::Axis Transform4f::getAxisRule() const
{
	return this->m_axis_rule;
}
void Transform4f::updateMatrix()
{
	if(this->m_is_updated) return;
	this->m_is_updated = true;
	switch(this->m_transform_order)
	{
		default:
		case Orders::Transform::STR:
			switch(this->m_rotation_order)
			{
				default:
				case Orders::Rotation::XYZ:
					this->m_matrix = Transform4::rotateZYX(this->m_rotation, this->m_axis_rule) * Transform4::scaleTranslate(this->m_scale, this->m_position);
					return;
				case Orders::Rotation::XZY:
					this->m_matrix = Transform4::rotateYZX(this->m_rotation, this->m_axis_rule) * Transform4::scaleTranslate(this->m_scale, this->m_position);
					return;
				case Orders::Rotation::YXZ:
					this->m_matrix = Transform4::rotateZXY(this->m_rotation, this->m_axis_rule) * Transform4::scaleTranslate(this->m_scale, this->m_position);
					return;
				case Orders::Rotation::YZX:
					this->m_matrix = Transform4::rotateXZY(this->m_rotation, this->m_axis_rule) * Transform4::scaleTranslate(this->m_scale, this->m_position);
					return;
				case Orders::Rotation::ZXY:
					this->m_matrix = Transform4::rotateYXZ(this->m_rotation, this->m_axis_rule) * Transform4::scaleTranslate(this->m_scale, this->m_position);
					return;
				case Orders::Rotation::ZYX:
					this->m_matrix = Transform4::rotateXYZ(this->m_rotation, this->m_axis_rule) * Transform4::scaleTranslate(this->m_scale, this->m_position);
					return;
			}
			return;
		case Orders::Transform::SRT:
			switch(this->m_rotation_order)
			{
				default:
				case Orders::Rotation::XYZ:
					this->m_matrix = Transform4::translate(this->m_position) * Transform4::rotateZYX(this->m_rotation, this->m_axis_rule) * Transform4::scale(this->m_scale);
					return;
				case Orders::Rotation::XZY:
					this->m_matrix = Transform4::translate(this->m_position) * Transform4::rotateYZX(this->m_rotation, this->m_axis_rule) * Transform4::scale(this->m_scale);
					return;
				case Orders::Rotation::YXZ:
					this->m_matrix = Transform4::translate(this->m_position) * Transform4::rotateZXY(this->m_rotation, this->m_axis_rule) * Transform4::scale(this->m_scale);
					return;
				case Orders::Rotation::YZX:
					this->m_matrix = Transform4::translate(this->m_position) * Transform4::rotateXZY(this->m_rotation, this->m_axis_rule) * Transform4::scale(this->m_scale);
					return;
				case Orders::Rotation::ZXY:
					this->m_matrix = Transform4::translate(this->m_position) * Transform4::rotateYXZ(this->m_rotation, this->m_axis_rule) * Transform4::scale(this->m_scale);
					return;
				case Orders::Rotation::ZYX:
					this->m_matrix = Transform4::translate(this->m_position) * Transform4::rotateXYZ(this->m_rotation, this->m_axis_rule) * Transform4::scale(this->m_scale);
					return;
			}
			return;
		case Orders::Transform::TSR:
			switch(this->m_rotation_order)
			{
				default:
				case Orders::Rotation::XYZ:
					this->m_matrix = Transform4::rotateZYX(this->m_rotation, this->m_axis_rule) * Transform4::translateScale(this->m_position, this->m_scale);
					return;
				case Orders::Rotation::XZY:
					this->m_matrix = Transform4::rotateYZX(this->m_rotation, this->m_axis_rule) * Transform4::translateScale(this->m_position, this->m_scale);
					return;
				case Orders::Rotation::YXZ:
					this->m_matrix = Transform4::rotateZXY(this->m_rotation, this->m_axis_rule) * Transform4::translateScale(this->m_position, this->m_scale);
					return;
				case Orders::Rotation::YZX:
					this->m_matrix = Transform4::rotateXZY(this->m_rotation, this->m_axis_rule) * Transform4::translateScale(this->m_position, this->m_scale);
					return;
				case Orders::Rotation::ZXY:
					this->m_matrix = Transform4::rotateYXZ(this->m_rotation, this->m_axis_rule) * Transform4::translateScale(this->m_position, this->m_scale);
					return;
				case Orders::Rotation::ZYX:
					this->m_matrix = Transform4::rotateXYZ(this->m_rotation, this->m_axis_rule) * Transform4::translateScale(this->m_position, this->m_scale);
					return;
			}
			return;
		case Orders::Transform::TRS:
			switch(this->m_rotation_order)
			{
				default:
				case Orders::Rotation::XYZ:
					this->m_matrix = Transform4::scale(this->m_scale) * Transform4::rotateZYX(this->m_rotation, this->m_axis_rule) * Transform4::translate(this->m_position);
					return;
				case Orders::Rotation::XZY:
					this->m_matrix = Transform4::scale(this->m_scale) * Transform4::rotateYZX(this->m_rotation, this->m_axis_rule) * Transform4::translate(this->m_position);
					return;
				case Orders::Rotation::YXZ:
					this->m_matrix = Transform4::scale(this->m_scale) * Transform4::rotateZXY(this->m_rotation, this->m_axis_rule) * Transform4::translate(this->m_position);
					return;
				case Orders::Rotation::YZX:
					this->m_matrix = Transform4::scale(this->m_scale) * Transform4::rotateXZY(this->m_rotation, this->m_axis_rule) * Transform4::translate(this->m_position);
					return;
				case Orders::Rotation::ZXY:
					this->m_matrix = Transform4::scale(this->m_scale) * Transform4::rotateYXZ(this->m_rotation, this->m_axis_rule) * Transform4::translate(this->m_position);
					return;
				case Orders::Rotation::ZYX:
					this->m_matrix = Transform4::scale(this->m_scale) * Transform4::rotateXYZ(this->m_rotation, this->m_axis_rule) * Transform4::translate(this->m_position);
					return;
			}
			return;
		case Orders::Transform::RST:
			switch(this->m_rotation_order)
			{
				default:
				case Orders::Rotation::XYZ:
					this->m_matrix = Transform4::scaleTranslate(this->m_scale, this->m_position) * Transform4::rotateZYX(this->m_rotation, this->m_axis_rule);
					return;
				case Orders::Rotation::XZY:
					this->m_matrix = Transform4::scaleTranslate(this->m_scale, this->m_position) * Transform4::rotateYZX(this->m_rotation, this->m_axis_rule);
					return;
				case Orders::Rotation::YXZ:
					this->m_matrix = Transform4::scaleTranslate(this->m_scale, this->m_position) * Transform4::rotateZXY(this->m_rotation, this->m_axis_rule);
					return;
				case Orders::Rotation::YZX:
					this->m_matrix = Transform4::scaleTranslate(this->m_scale, this->m_position) * Transform4::rotateXZY(this->m_rotation, this->m_axis_rule);
					return;
				case Orders::Rotation::ZXY:
					this->m_matrix = Transform4::scaleTranslate(this->m_scale, this->m_position) * Transform4::rotateYXZ(this->m_rotation, this->m_axis_rule);
					return;
				case Orders::Rotation::ZYX:
					this->m_matrix = Transform4::scaleTranslate(this->m_scale, this->m_position) * Transform4::rotateXYZ(this->m_rotation, this->m_axis_rule);
					return;
			}
			return;
		case Orders::Transform::RTS:
			switch(this->m_rotation_order)
			{
				default:
				case Orders::Rotation::XYZ:
					this->m_matrix = Transform4::translateScale(this->m_position, this->m_scale) * Transform4::rotateZYX(this->m_rotation, this->m_axis_rule);
					return;
				case Orders::Rotation::XZY:
					this->m_matrix = Transform4::translateScale(this->m_position, this->m_scale) * Transform4::rotateYZX(this->m_rotation, this->m_axis_rule);
					return;
				case Orders::Rotation::YXZ:
					this->m_matrix = Transform4::translateScale(this->m_position, this->m_scale) * Transform4::rotateZXY(this->m_rotation, this->m_axis_rule);
					return;
				case Orders::Rotation::YZX:
					this->m_matrix = Transform4::translateScale(this->m_position, this->m_scale) * Transform4::rotateXZY(this->m_rotation, this->m_axis_rule);
					return;
				case Orders::Rotation::ZXY:
					this->m_matrix = Transform4::translateScale(this->m_position, this->m_scale) * Transform4::rotateYXZ(this->m_rotation, this->m_axis_rule);
					return;
				case Orders::Rotation::ZYX:
					this->m_matrix = Transform4::translateScale(this->m_position, this->m_scale) * Transform4::rotateXYZ(this->m_rotation, this->m_axis_rule);
					return;
			}
			return;
	}
}
Vec3f Transform4f::transform(const Vec3f& vec) const
{
	Vec4f rvec = this->m_matrix * Vec4f(vec.x, vec.y, vec.z, 1.0f);
	return Vec3f(rvec.x, rvec.y, rvec.z);
}
Vec4f Transform4f::transform(const Vec4f& vec) const
{
	return this->m_matrix * vec;
}

} // axl.math
} // axl

