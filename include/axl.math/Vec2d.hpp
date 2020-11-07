#pragma once
#include "rules.hpp"

namespace axl {
namespace math {

class Vec2d
{
	public:
		Vec2d(double x = Default.x, double y = Default.y);
		Vec2d(const Vec2d& vec);
	public:
		Vec2d operator+() const;
		Vec2d operator-() const;
		Vec2d operator+(const Vec2d& vec) const;
		Vec2d operator-(const Vec2d& vec) const;
		Vec2d operator*(const Vec2d& vec) const;
		Vec2d operator/(const Vec2d& vec) const;
		Vec2d operator+(double v) const;
		Vec2d operator-(double v) const;
		Vec2d operator*(double v) const;
		Vec2d operator/(double v) const;
		Vec2d& operator+=(const Vec2d& vec);
		Vec2d& operator-=(const Vec2d& vec);
		Vec2d& operator*=(const Vec2d& vec);
		Vec2d& operator/=(const Vec2d& vec);
		Vec2d& operator+=(double v);
		Vec2d& operator-=(double v);
		Vec2d& operator*=(double v);
		Vec2d& operator/=(double v);
		bool operator==(const Vec2d& vec) const;
		bool operator!=(const Vec2d& vec) const;
		bool operator==(const double& v) const;
		bool operator!=(const double& v) const;
	public:
		Vec2d& set(double value);
		Vec2d& set(double x, double y);
		bool isNan() const;
		bool hasNan() const;
		bool hasNoNan() const;
		bool equals(const Vec2d& vec, double epsilon = 0.0000001) const;
		bool notEquals(const Vec2d& vec, double epsilon = 0.0000001) const;
		bool equals(double x, double y, double epsilon = 0.0000001) const;
		bool notEquals(double x, double y, double epsilon = 0.0000001) const;
	public:
		double magn() const;
		Vec2d norm() const;
		Vec2d& normalize();
		double dot(const Vec2d& vec) const;
		double cross(const Vec2d& vec) const;
		double angle(Rules::Axis axis_rule = DefaultAxisRule) const;
		double angle(const Vec2d& ref_vec, Rules::Axis axis_rule = DefaultAxisRule) const;
		double fullAngle(Rules::Axis axis_rule = DefaultAxisRule) const;
		double fullAngle(const Vec2d& ref_vec, Rules::Axis axis_rule = DefaultAxisRule) const;
	public:
		Vec2d& scale(double scale_all);
		Vec2d& scale(double scale_x, double scale_y);
		Vec2d scaled(double scale_all) const;
		Vec2d scaled(double scale_x, double scale_y) const;
		Vec2d& translate(double delta_x, double delta_y);
		Vec2d& translate(const Vec2d& delta);
		Vec2d translated(double delta_x, double delta_y) const;
		Vec2d translated(const Vec2d& delta) const;
		Vec2d& rotate(double theta_z, Rules::Axis axis_rule = DefaultAxisRule);
		Vec2d rotated(double theta_z, Rules::Axis axis_rule = DefaultAxisRule) const;
	public:
		const static Vec2d Zero;
		const static Vec2d Identity;
		static Vec2d Default;
		static Rules::Axis DefaultAxisRule;
	public:
		double x, y;
};

} // namespace math
} // namespace axl