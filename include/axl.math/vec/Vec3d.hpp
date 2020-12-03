#pragma once
#include "../lib.hpp"
#include "../rules.hpp"
#include "Vec2d.hpp"

namespace axl {
namespace math {

class AXLMATHCXXAPI Vec3d
{
	public:
		Vec3d(double x = Default.x, double y = Default.y, double z = Default.z);
		Vec3d(const Vec3d& vec);
		Vec3d(const Vec2d& vec, double z = Default.z);
	public:
		Vec3d operator+() const;
		Vec3d operator-() const;
		Vec3d operator+(const Vec3d& vec) const;
		Vec3d operator-(const Vec3d& vec) const;
		Vec3d operator*(const Vec3d& vec) const;
		Vec3d operator/(const Vec3d& vec) const;
		Vec3d operator+(double v) const;
		Vec3d operator-(double v) const;
		Vec3d operator*(double v) const;
		Vec3d operator/(double v) const;
		Vec3d& operator+=(const Vec3d& vec);
		Vec3d& operator-=(const Vec3d& vec);
		Vec3d& operator*=(const Vec3d& vec);
		Vec3d& operator/=(const Vec3d& vec);
		Vec3d& operator+=(double v);
		Vec3d& operator-=(double v);
		Vec3d& operator*=(double v);
		Vec3d& operator/=(double v);
		bool operator==(const Vec3d& vec) const;
		bool operator!=(const Vec3d& vec) const;
		bool operator==(const double& v) const;
		bool operator!=(const double& v) const;
	public:
		Vec3d& set(double value);
		Vec3d& set(double x, double y);
		Vec3d& set(double x, double y, double z);
		bool isNan() const;
		bool hasNan() const;
		bool hasNoNan() const;
		bool equals(const Vec3d& vec, double epsilon = 0.0000001) const;
		bool notEquals(const Vec3d& vec, double epsilon = 0.0000001) const;
		bool equals(double x, double y, double z, double epsilon = 0.0000001) const;
		bool notEquals(double x, double y, double z, double epsilon = 0.0000001) const;
	public:
		double magn() const;
		Vec3d norm() const;
		Vec3d& normalize();
		double dot(const Vec3d& vec) const;
		Vec3d cross(const Vec3d& vec, Rules::Axis axis_rule = DefaultAxisRule) const;
		Vec3d euler(Rules::Axis axis_rule = DefaultAxisRule) const;
		Vec3d euler(const Vec3d& ref_vec, Rules::Axis axis_rule = DefaultAxisRule) const;
	public:
		Vec3d& scale(double scale_all);
		Vec3d& scale(double scale_x, double scale_y, double scale_z);
		Vec3d scaled(double scale_all) const;
		Vec3d scaled(double scale_x, double scale_y, double scale_z) const;
		Vec3d& translate(double delta_x, double delta_y, double delta_z);
		Vec3d& translate(const Vec3d& delta);
		Vec3d translated(double delta_x, double delta_y, double delta_z) const;
		Vec3d translated(const Vec3d& delta) const;
		Vec3d& rotate(double angle_x, double angle_y, double angle_z, Rules::Axis axis_rule = DefaultAxisRule);
		Vec3d& rotate(const Vec3d& angle_vec, Rules::Axis axis_rule = DefaultAxisRule);
		Vec3d& rotateX(double angle_x, Rules::Axis axis_rule = DefaultAxisRule);
		Vec3d& rotateY(double angle_y, Rules::Axis axis_rule = DefaultAxisRule);
		Vec3d& rotateZ(double angle_z, Rules::Axis axis_rule = DefaultAxisRule);
		Vec3d rotated(double angle_x, double angle_y, double angle_z, Rules::Axis axis_rule = DefaultAxisRule) const;
		Vec3d rotated(const Vec3d& angle_vec, Rules::Axis axis_rule = DefaultAxisRule) const;
		Vec3d rotatedX(double angle_x, Rules::Axis axis_rule = DefaultAxisRule);
		Vec3d rotatedY(double angle_y, Rules::Axis axis_rule = DefaultAxisRule);
		Vec3d rotatedZ(double angle_z, Rules::Axis axis_rule = DefaultAxisRule);
	public:
		const static Vec3d Zero;
		const static Vec3d Identity;
		static Vec3d Default;
		static Rules::Axis DefaultAxisRule;
	public:
		double x, y, z;
};

Vec3d AXLMATHAPI operator+(double v, const Vec3d& vec);
Vec3d AXLMATHAPI operator-(double v, const Vec3d& vec);
Vec3d AXLMATHAPI operator*(double v, const Vec3d& vec);
Vec3d AXLMATHAPI operator/(double v, const Vec3d& vec);

} // namespace axl.math
} // namespace axl