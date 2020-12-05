#pragma once
#include "../lib.hpp"
#include "../Rules.hpp"
#include "Vec2d.hpp"
#include "Vec3d.hpp"

namespace axl {
namespace math {

class AXLMATHCXXAPI Vec4d
{
	public:
		Vec4d(double x = Default.x, double y = Default.y, double z = Default.z, double w = Default.w);
		Vec4d(const Vec4d& vec);
		Vec4d(const Vec2d& vec, double z = Default.z, double w = Default.w);
		Vec4d(const Vec3d& vec, double w = Default.w);
	public:
		Vec4d operator+() const;
		Vec4d operator-() const;
		Vec4d operator+(const Vec4d& vec) const;
		Vec4d operator-(const Vec4d& vec) const;
		Vec4d operator*(const Vec4d& vec) const;
		Vec4d operator/(const Vec4d& vec) const;
		Vec4d operator+(double v) const;
		Vec4d operator-(double v) const;
		Vec4d operator*(double v) const;
		Vec4d operator/(double v) const;
		Vec4d& operator+=(const Vec4d& vec);
		Vec4d& operator-=(const Vec4d& vec);
		Vec4d& operator*=(const Vec4d& vec);
		Vec4d& operator/=(const Vec4d& vec);
		Vec4d& operator+=(double v);
		Vec4d& operator-=(double v);
		Vec4d& operator*=(double v);
		Vec4d& operator/=(double v);
		bool operator==(const Vec4d& vec) const;
		bool operator!=(const Vec4d& vec) const;
		bool operator==(const double& v) const;
		bool operator!=(const double& v) const;
	public:
		bool isNan() const;
		bool hasNan() const;
		bool hasNoNan() const;
		bool equals(const Vec4d& vec, double epsilon = 0.000001) const;
		bool notEquals(const Vec4d& vec, double epsilon = 0.000001) const;
		bool equals(double x, double y, double z, double w, double epsilon = 0.000001) const;
		bool notEquals(double x, double y, double z, double w, double epsilon = 0.000001) const;
	public:
		Vec4d& set(double value);
		Vec4d& set(double x, double y);
		Vec4d& set(double x, double y, double z);
		Vec4d& set(double x, double y, double z, double w);
	public:
		double magn() const;
		Vec4d norm() const;
		Vec4d& normalize();
		double dot(const Vec4d& vec) const;
	public:
		Vec4d& scale(double scale_all);
		Vec4d& scale(double scale_x, double scale_y, double scale_z, double scale_w);
		Vec4d scaled(double scale_all) const;
		Vec4d scaled(double scale_x, double scale_y, double scale_z, double scale_w) const;
		Vec4d& translate(double delta_x, double delta_y, double delta_z, double delta_w);
		Vec4d& translate(const Vec4d& delta);
		Vec4d translated(double delta_x, double delta_y, double delta_z, double delta_w) const;
		Vec4d translated(const Vec4d& delta) const;
	public:
		static Vec4d filled(double v);
		const static Vec4d Zero;
		const static Vec4d Identity;
		static Vec4d Default;
		static Rules::Axis DefaultAxisRule;
	public:
		double x, y, z, w;
};

Vec4d operator+(double v, const Vec4d& vec);
Vec4d operator-(double v, const Vec4d& vec);
Vec4d operator*(double v, const Vec4d& vec);
Vec4d operator/(double v, const Vec4d& vec);

} // namespace axl.math
} // namespace axl