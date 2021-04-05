#include <axl.math/lib.hpp>
#include <axl.math/mat/Transform4.hpp>
#include <axl.math/transform/Transform4d.hpp>

namespace axl {
namespace math {

Transform4d::Transform4d(const Vec3d& scale, const Vec3d& position, const Vec3d& rotation, Orders::Transform transform_order, Orders::Rotation rotation_order, Rules::Axis axis_rule) :
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
void Transform4d::setScale(const Vec3d& scale, bool update_matrix)
{
	this->m_is_updated = false;
	this->m_scale = scale;
	if(update_matrix)
		this->updateMatrix();
}
void Transform4d::setPosition(const Vec3d& position, bool update_matrix)
{
	this->m_is_updated = false;
	this->m_position = position;
	if(update_matrix)
		this->updateMatrix();
}
void Transform4d::setRotation(const Vec3d& rotation, bool update_matrix)
{
	this->m_is_updated = false;
	this->m_rotation = rotation;
	if(update_matrix)
		this->updateMatrix();
}
void Transform4d::setRotation(const Vec3d& rotation, Orders::Rotation rotation_order, Rules::Axis axis_rule, bool update_matrix)
{
	this->m_is_updated = false;
	this->m_rotation = rotation;
	this->m_rotation_order = rotation_order;
	this->m_axis_rule = axis_rule;
	if(update_matrix)
		this->updateMatrix();
}
void Transform4d::setTransformOrder(Orders::Transform transform_order, bool update_matrix)
{
	this->m_is_updated = false;
	this->m_transform_order = transform_order;
	if(update_matrix)
		this->updateMatrix();
}
void Transform4d::setRotationOrder(Orders::Rotation rotation_order, bool update_matrix)
{
	this->m_is_updated = false;
	this->m_rotation_order = rotation_order;
	if(update_matrix)
		this->updateMatrix();
}
void Transform4d::setAxisRule(Rules::Axis axis_rule, bool update_matrix)
{
	this->m_is_updated = false;
	this->m_axis_rule = axis_rule;
	if(update_matrix)
		this->updateMatrix();
}
bool Transform4d::isUpdated() const
{
	return this->m_is_updated;
}
const Mat4d& Transform4d::getMatrix() const
{
	return this->m_matrix;
}
const Vec3d& Transform4d::getScale() const
{
	return this->m_scale;
}
const Vec3d& Transform4d::getPosition() const
{
	return this->m_position;
}
const Vec3d& Transform4d::getRotation() const
{
	return this->m_rotation;
}
Orders::Transform Transform4d::getTransformOrder() const
{
	return this->m_transform_order;
}
Orders::Rotation Transform4d::getRotationOrder() const
{
	return this->m_rotation_order;
}
Rules::Axis Transform4d::getAxisRule() const
{
	return this->m_axis_rule;
}
void Transform4d::updateMatrix()
{
	if(this->m_is_updated) return;
	this->m_is_updated = true;
	Mat4d r_matrix(Mat4d::Identity);
	switch(this->m_rotation_order)
	{
		default:
		case Orders::Rotation::XYZ: r_matrix = Transform4::rotateZYX(this->m_rotation, this->m_axis_rule); break;
		case Orders::Rotation::XZY: r_matrix = Transform4::rotateYZX(this->m_rotation, this->m_axis_rule); break;
		case Orders::Rotation::YXZ: r_matrix = Transform4::rotateZXY(this->m_rotation, this->m_axis_rule); break;
		case Orders::Rotation::YZX: r_matrix = Transform4::rotateXZY(this->m_rotation, this->m_axis_rule); break;
		case Orders::Rotation::ZXY: r_matrix = Transform4::rotateYXZ(this->m_rotation, this->m_axis_rule); break;
		case Orders::Rotation::ZYX: r_matrix = Transform4::rotateXYZ(this->m_rotation, this->m_axis_rule); break;
		case Orders::Rotation::XY: r_matrix = Transform4::rotateYX(this->m_rotation, this->m_axis_rule); break;
		case Orders::Rotation::XZ: r_matrix = Transform4::rotateZX(this->m_rotation, this->m_axis_rule); break;
		case Orders::Rotation::YX: r_matrix = Transform4::rotateXY(this->m_rotation, this->m_axis_rule); break;
		case Orders::Rotation::YZ: r_matrix = Transform4::rotateZY(this->m_rotation, this->m_axis_rule); break;
		case Orders::Rotation::ZX: r_matrix = Transform4::rotateXZ(this->m_rotation, this->m_axis_rule); break;
		case Orders::Rotation::ZY: r_matrix = Transform4::rotateYZ(this->m_rotation, this->m_axis_rule); break;
		case Orders::Rotation::X: r_matrix = Transform4::rotateX(this->m_rotation.x, this->m_axis_rule); break;
		case Orders::Rotation::Y: r_matrix = Transform4::rotateY(this->m_rotation.y, this->m_axis_rule); break;
		case Orders::Rotation::Z: r_matrix = Transform4::rotateZ(this->m_rotation.z, this->m_axis_rule); break;
		case Orders::Rotation::NONE: break;
	}
	if(this->m_rotation_order == Orders::Rotation::NONE)
	{
		switch(this->m_transform_order)
		{
			default:
			case Orders::Transform::STR:
			case Orders::Transform::SRT:
			case Orders::Transform::RST:
				this->m_matrix = Transform4::scaleTranslate(this->m_scale, this->m_position);
				return;
			case Orders::Transform::TSR:
			case Orders::Transform::TRS:
			case Orders::Transform::RTS:
				this->m_matrix = Transform4::translateScale(this->m_position, this->m_scale);
				return;
		}
	}
	else
	{
		switch(this->m_transform_order)
		{
			default:
			case Orders::Transform::STR: this->m_matrix = r_matrix * Transform4::scaleTranslate(this->m_scale, this->m_position); return;
			case Orders::Transform::SRT: this->m_matrix = Transform4::translate(this->m_position) * r_matrix * Transform4::scale(this->m_scale); return;
			case Orders::Transform::TSR: this->m_matrix = r_matrix * Transform4::translateScale(this->m_position, this->m_scale); return;
			case Orders::Transform::TRS: this->m_matrix = Transform4::scale(this->m_scale) * r_matrix * Transform4::translate(this->m_position); return;
			case Orders::Transform::RST: this->m_matrix = Transform4::scaleTranslate(this->m_scale, this->m_position) * r_matrix; return;
			case Orders::Transform::RTS: this->m_matrix = Transform4::translateScale(this->m_position, this->m_scale) * r_matrix; return;
		}
	}
}
Vec3d Transform4d::transform(const Vec3d& vec) const
{
	Vec4d rvec = this->m_matrix * Vec4d(vec.x, vec.y, vec.z, 1.0f);
	return Vec3d(rvec.x, rvec.y, rvec.z);
}
Vec4d Transform4d::transform(const Vec4d& vec) const
{
	return this->m_matrix * vec;
}

} // axl.math
} // axl

