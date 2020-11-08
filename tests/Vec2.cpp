#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include "Assert.hpp"
#include <axl.math/lib.hpp>
#include <axl.math/constants.hpp>
#include <axl.math/double.hpp>
#include <axl.math/angle.hpp>
#include <axl.math/Vec2.hpp>

int main(int argc, char *argv[])
{
	bool verbose = argc > 1 && (0 == strcmp(argv[1], "-v") || 0 == strcmp(argv[1], "--verbose"));
	using namespace axl;
	using namespace axl::math;
	using namespace axl::math::Constants;
	printf("library version: %u %u %u\n", lib::version.major, lib::version.minor, lib::version.patch);
	{ // static values
		Assertv(Double::equals(0.0, Vec2<double>::Zero.x), verbose);
		Assertv(Double::equals(0.0, Vec2<double>::Zero.y), verbose);
		Assertv(Double::equals(1.0, Vec2<double>::Identity.x), verbose);
		Assertv(Double::equals(1.0, Vec2<double>::Identity.y), verbose);
		Assertv(Vec2<double>::Default.equals(0.0, 0.0), verbose);
	}
	{ // constructors
		{ // default constructor
			{
				Assertv(Vec2<double>::Default.equals(Vec2<double>::Zero), verbose);
				Vec2<double> vec;
				Assertv(Double::equals(Vec2<double>::Default.x, vec.x), verbose);
				Assertv(Double::equals(Vec2<double>::Default.y, vec.y), verbose);
			}
			{
				Vec2<double>::Default = Vec2<double>::Identity;
				Assertv(Vec2<double>::Default.equals(Vec2<double>::Identity), verbose);
				Vec2<double> vec;
				Assertv(vec.equals(Vec2<double>::Identity), verbose);
				Assertv(Double::equals(Vec2<double>::Default.x, vec.x), verbose);
				Assertv(Double::equals(Vec2<double>::Default.y, vec.y), verbose);
				Vec2<double>::Default = Vec2<double>::Zero;
				Assertv(Vec2<double>::Default.equals(Vec2<double>::Zero), verbose);
			}
		}
		{ // values constructor
			Vec2<double> vec(3.1415, 0.6721234);
			Assertv(Double::equals(3.1415, vec.x), verbose);
			Assertv(Double::equals(0.6721234, vec.y), verbose);
		}
		{ // copy constructor
			Vec2<double> vec(3.1415, 0.6721234);
			Assertv(Double::equals(3.1415, vec.x), verbose);
			Assertv(Double::equals(0.6721234, vec.y), verbose);
			Vec2<double> vec1(vec);
			Assertv(Double::equals(3.1415, vec1.x), verbose);
			Assertv(Double::equals(0.6721234, vec1.y), verbose);
			Vec2<double> vec2 = vec;
			Assertv(Double::equals(3.1415, vec2.x), verbose);
			Assertv(Double::equals(0.6721234, vec2.y), verbose);
		}
	}
	{ // unary operators
		const Vec2<double> vec(3.4, 5.6);
		const Vec2<double> pvec = +vec;
		const Vec2<double> nvec = -vec;
		Assertv(pvec.equals(pvec), verbose);
		Assertv(nvec.equals(-pvec.x, -pvec.y, 0.001), verbose);
		Assertv(vec.equals(-nvec), verbose);
	}
	{ // Nan
		{
			const Vec2<double> vec(0.0/0.0, 0.0/0.0);
			Assertv(vec.isNan(), verbose);
			Assertv(vec.hasNan(), verbose);
			Assertv(!vec.hasNoNan(), verbose);
		}
		{
			const Vec2<double> vec(0.6, 0.0/0.0);
			Assertv(!vec.isNan(), verbose);
			Assertv(vec.hasNan(), verbose);
			Assertv(!vec.hasNoNan(), verbose);
		}
		{
			const Vec2<double> vec(0.5, 1.0);
			Assertv(!vec.isNan(), verbose);
			Assertv(!vec.hasNan(), verbose);
			Assertv(vec.hasNoNan(), verbose);
		}
	}
	{ // equality operators
		Assertv(Vec2<double>::Zero == 0.0, verbose);
		Assertv(Vec2<double>::Identity == 1.0, verbose);
		Assertv(Vec2<double>::Zero == Vec2<double>::Zero, verbose);
		Assertv(Vec2<double>::Identity == Vec2<double>::Identity, verbose);
		Assertv(!(Vec2<double>::Zero != 0.0), verbose);
		Assertv(!(Vec2<double>::Identity != 1.0), verbose);
		Assertv(!(Vec2<double>::Zero != Vec2<double>::Zero), verbose);
		Assertv(!(Vec2<double>::Identity != Vec2<double>::Identity), verbose);
		Vec2<double> vec(3.45, 4.5), vec2(1.2345, 0.987654);
		Assertv(vec.equals(3.45, 4.5), verbose);
		Assertv(vec.equals(vec), verbose);
		Assertv(!vec.equals(vec2), verbose);
		Assertv(!vec.notEquals(3.45, 4.5), verbose);
		Assertv(!vec.notEquals(vec), verbose);
		Assertv(vec.notEquals(vec2), verbose);
	}
	{ // arthimetic operators
		{ // addition
			const double lval_x = 12.344, lval_y = 131.04, rval_x = 4.5664, rval_y = 12314.43005;
			const Vec2<double> lvec(lval_x, lval_y), rvec(rval_x, rval_y);
			Vec2<double> vec = lvec + rvec;
			Assertv(vec.equals(lval_x + rval_x, lval_y + rval_y), verbose);
			
			vec = lvec + rval_y;
			Assertv(vec.equals(lval_x + rval_y, lval_y + rval_y), verbose);

			vec = lvec;
			Assertv(vec.equals(lval_x, lval_y), verbose);
			vec += rvec;
			Assertv(vec.equals(lval_x + rval_x, lval_y + rval_y), verbose);

			vec = lvec;
			Assertv(vec.equals(lval_x, lval_y), verbose);
			vec += rval_x;
			Assertv(vec.equals(lval_x + rval_x, lval_y + rval_x), verbose);
		}
		{ // subtraction
			const double lval_x = 12.344, lval_y = 131.04, rval_x = 4.5664, rval_y = 12314.43005;
			const Vec2<double> lvec(lval_x, lval_y), rvec(rval_x, rval_y);
			Vec2<double> vec = lvec - rvec;
			Assertv(vec.equals(lval_x - rval_x, lval_y - rval_y), verbose);
			
			vec = lvec - rval_y;
			Assertv(vec.equals(lval_x - rval_y, lval_y - rval_y), verbose);

			vec = lvec;
			Assertv(vec.equals(lval_x, lval_y), verbose);
			vec -= rvec;
			Assertv(vec.equals(lval_x - rval_x, lval_y - rval_y), verbose);

			vec = lvec;
			Assertv(vec.equals(lval_x, lval_y), verbose);
			vec -= rval_x;
			Assertv(vec.equals(lval_x - rval_x, lval_y - rval_x), verbose);
		}
		{ // multiplication
			const double lval_x = 12.344, lval_y = 131.04, rval_x = 4.5664, rval_y = 12314.43005;
			const Vec2<double> lvec(lval_x, lval_y), rvec(rval_x, rval_y);
			Vec2<double> vec = lvec * rvec;
			Assertv(vec.equals(lval_x * rval_x, lval_y * rval_y), verbose);
			
			vec = lvec * rval_y;
			Assertv(vec.equals(lval_x * rval_y, lval_y * rval_y), verbose);

			vec = lvec;
			Assertv(vec.equals(lval_x, lval_y), verbose);
			vec *= rvec;
			Assertv(vec.equals(lval_x * rval_x, lval_y * rval_y), verbose);

			vec = lvec;
			Assertv(vec.equals(lval_x, lval_y), verbose);
			vec *= rval_x;
			Assertv(vec.equals(lval_x * rval_x, lval_y * rval_x), verbose);
		}
		{ // division
			const double lval_x = 12.344, lval_y = 131.04, rval_x = 4.5664, rval_y = 12314.43005;
			const Vec2<double> lvec(lval_x, lval_y), rvec(rval_x, rval_y);
			Vec2<double> vec = lvec / rvec;
			Assertv(vec.equals(lval_x / rval_x, lval_y / rval_y), verbose);
			
			vec = lvec / rval_y;
			Assertv(vec.equals(lval_x / rval_y, lval_y / rval_y), verbose);

			vec = lvec;
			Assertv(vec.equals(lval_x, lval_y), verbose);
			vec /= rvec;
			Assertv(vec.equals(lval_x / rval_x, lval_y / rval_y), verbose);

			vec = lvec;
			Assertv(vec.equals(lval_x, lval_y), verbose);
			vec /= rval_x;
			Assertv(vec.equals(lval_x / rval_x, lval_y / rval_x), verbose);
		}
	}
	{ // vector operations
		{ // magnitude
			const double x = 2.0, y = 3.0;
			const Vec2<double> vec(x, y);
			const double magn = vec.magn();
			Assertv(Double::equals(magn, std::sqrt(x * x + y * y)), verbose);
			Assertv(Double::equals(magn, std::sqrt(std::pow(x, 2.0) + std::pow(y, 2.0))), verbose);
		}
		{ // normal
			{
				const double x = 2.0, y = 3.0;
				const Vec2<double> vec(x, y);
				const double magn1 = std::sqrt(x * x + y * y);
				const double magn2 = std::sqrt(std::pow(x, 2.0) + std::pow(y, 2.0));
				const Vec2<double> norm_vec = vec.norm();
				const Vec2<double> norm_vec1 = vec / magn1;
				const Vec2<double> norm_vec2 = vec / magn2;
				Assertv(Double::equals(1.0, norm_vec.magn()), verbose);
				Assertv(Double::equals(1.0, norm_vec1.magn()), verbose);
				Assertv(Double::equals(1.0, norm_vec2.magn()), verbose);
				Assertv(Double::equals(1.0, std::sqrt(norm_vec.x * norm_vec.x + norm_vec.y * norm_vec.y)), verbose);
				Assertv(Double::equals(1.0, std::sqrt(norm_vec1.x * norm_vec1.x + norm_vec1.y * norm_vec1.y)), verbose);
				Assertv(Double::equals(1.0, std::sqrt(std::pow(norm_vec2.x, 2.0) + std::pow(norm_vec2.y, 2.0))), verbose);
			}
			{
				const double x = 2.0, y = 3.0;
				const Vec2<double> vec(x, y);
				Vec2<double> nvec(x, y);
				nvec.normalize();
				const double magn1 = std::sqrt(x * x + y * y);
				const Vec2<double> norm_vec = vec / magn1;
				Assertv(nvec.equals(norm_vec), verbose);
				Assertv(Double::equals(1.0, nvec.magn()), verbose);
				Assertv(Double::equals(1.0, norm_vec.magn()), verbose);
				Assertv(vec.equals(nvec * vec.magn()), verbose);
			}
		}
		{ // dot product
			const double lx = 2.0, ly = 3.0;
			const double rx = 4.0, ry = 6.0;
			const Vec2<double> lvec(lx, ly);
			const Vec2<double> rvec(rx, ry);
			const double dotplr = lvec.dot(rvec);
			const double dotprl = rvec.dot(lvec);
			Assertv(Double::equals(dotplr, (lx * rx + ly * ry)), verbose);
			Assertv(Double::equals(dotprl, (lx * rx + ly * ry)), verbose);
		}
		{ // cross product
			const double lx = 2.0, ly = 3.0;
			const double rx = 4.0, ry = 6.0;
			const Vec2<double> lvec(lx, ly);
			const Vec2<double> rvec(rx, ry);
			const double crossplr = lvec.cross(rvec);
			const double crossprl = rvec.cross(lvec);
			Assertv(Double::equals(crossplr, (lx * ry - ly * rx)), verbose);
			Assertv(Double::equals(crossprl, (rx * ly - ry * lx)), verbose);
		}
		{ // angle
			Assertve(Vec2<double>::DefaultAxisRule == Rules::RHS, verbose);
			{ // Rules::RHS
				Assertv(Double::equals(Vec2<double>(-0.0, 0.0).angle(), Angle::degToRad(180.0)), verbose);
				Assertv(Double::equals(Vec2<double>(0.0, -0.0).angle(), Angle::degToRad(-0.0)), verbose);
				Assertv(Double::equals(Vec2<double>(-0.0, -0.0).angle(), Angle::degToRad(-180.0)), verbose);
				Assertv(Double::equals(Vec2<double>(0.0, 0.0).angle(), Angle::degToRad(0.0)), verbose);
				Assertv(Double::equals(Vec2<double>(1.0, 0.0).angle(), Angle::degToRad(0.0)), verbose);
				Assertv(Double::equals(Vec2<double>(0.0, 1.0).angle(), Angle::degToRad(90.0)), verbose);
				Assertv(Double::equals(Vec2<double>(-1.0, 0.0).angle(), Angle::degToRad(180.0)), verbose);
				Assertv(Double::equals(Vec2<double>(0.0, -1.0).angle(), -Angle::degToRad(90.0)), verbose);
				Assertv(Double::equals(Vec2<double>(1.0, 1.0).angle(), Angle::degToRad(45.0)), verbose);
				Assertv(Double::equals(Vec2<double>(-1.0, 1.0).angle(), Angle::degToRad(135.0)), verbose);
				Assertv(Double::equals(Vec2<double>(-1.0, -1.0).angle(), -Angle::degToRad(135.0)), verbose);
				Assertv(Double::equals(Vec2<double>(1.0, -1.0).angle(), -Angle::degToRad(45.0)), verbose);
				// full angle
				Assertv(Double::equals(Vec2<double>(-0.0, 0.0).fullAngle(), Angle::degToRad(180.0)), verbose);
				Assertv(Double::equals(Vec2<double>(0.0, -0.0).fullAngle(), Angle::degToRad(0.0)), verbose);
				Assertv(Double::equals(Vec2<double>(-0.0, -0.0).fullAngle(), Angle::degToRad(180.0)), verbose);
				Assertv(Double::equals(Vec2<double>(0.0, 0.0).fullAngle(), Angle::degToRad(0.0)), verbose);
				Assertv(Double::equals(Vec2<double>(1.0, 0.0).fullAngle(), Angle::degToRad(0.0)), verbose);
				Assertv(Double::equals(Vec2<double>(0.0, 1.0).fullAngle(), Angle::degToRad(90.0)), verbose);
				Assertv(Double::equals(Vec2<double>(-1.0, 0.0).fullAngle(), Angle::degToRad(180.0)), verbose);
				Assertv(Double::equals(Vec2<double>(0.0, -1.0).fullAngle(), Angle::degToRad(270.0)), verbose);
				Assertv(Double::equals(Vec2<double>(1.0, 1.0).fullAngle(), Angle::degToRad(45.0)), verbose);
				Assertv(Double::equals(Vec2<double>(-1.0, 1.0).fullAngle(), Angle::degToRad(135.0)), verbose);
				Assertv(Double::equals(Vec2<double>(-1.0, -1.0).fullAngle(), Angle::degToRad(225.0)), verbose);
				Assertv(Double::equals(Vec2<double>(1.0, -1.0).fullAngle(), Angle::degToRad(315.0)), verbose);
			}
			{ // Rules::LHS
				Vec2<double>::DefaultAxisRule = Rules::LHS;
				Assertve(Vec2<double>::DefaultAxisRule == Rules::LHS, verbose);
				Assertv(Double::equals(Vec2<double>(-0.0, 0.0).angle(), Angle::degToRad(-0.0)), verbose);
				Assertv(Double::equals(Vec2<double>(0.0, -0.0).angle(), Angle::degToRad(180.0)), verbose);
				Assertv(Double::equals(Vec2<double>(-0.0, -0.0).angle(), Angle::degToRad(-180.0)), verbose);
				Assertv(Double::equals(Vec2<double>(0.0, 0.0).angle(), Angle::degToRad(0.0)), verbose);
				Assertv(Double::equals(Vec2<double>(1.0, 0.0).angle(), Angle::degToRad(90.0)), verbose);
				Assertv(Double::equals(Vec2<double>(0.0, 1.0).angle(), Angle::degToRad(0.0)), verbose);
				Assertv(Double::equals(Vec2<double>(-1.0, 0.0).angle(), Angle::degToRad(-90.0)), verbose);
				Assertv(Double::equals(Vec2<double>(0.0, -1.0).angle(), Angle::degToRad(180.0)), verbose);
				Assertv(Double::equals(Vec2<double>(1.0, 1.0).angle(), Angle::degToRad(45.0)), verbose);
				Assertv(Double::equals(Vec2<double>(-1.0, 1.0).angle(), Angle::degToRad(-45.0)), verbose);
				Assertv(Double::equals(Vec2<double>(-1.0, -1.0).angle(), Angle::degToRad(-135.0)), verbose);
				Assertv(Double::equals(Vec2<double>(1.0, -1.0).angle(), Angle::degToRad(135.0)), verbose);
				// full angle
				Assertv(Double::equals(Vec2<double>(-0.0, 0.0).fullAngle(), Angle::degToRad(0.0)), verbose);
				Assertv(Double::equals(Vec2<double>(0.0, -0.0).fullAngle(), Angle::degToRad(180.0)), verbose);
				Assertv(Double::equals(Vec2<double>(-0.0, -0.0).fullAngle(), Angle::degToRad(180.0)), verbose);
				Assertv(Double::equals(Vec2<double>(0.0, 0.0).fullAngle(), Angle::degToRad(0.0)), verbose);
				Assertv(Double::equals(Vec2<double>(1.0, 0.0).fullAngle(), Angle::degToRad(90.0)), verbose);
				Assertv(Double::equals(Vec2<double>(0.0, 1.0).fullAngle(), Angle::degToRad(0.0)), verbose);
				Assertv(Double::equals(Vec2<double>(-1.0, 0.0).fullAngle(), Angle::degToRad(270.0)), verbose);
				Assertv(Double::equals(Vec2<double>(0.0, -1.0).fullAngle(), Angle::degToRad(180.0)), verbose);
				Assertv(Double::equals(Vec2<double>(1.0, 1.0).fullAngle(), Angle::degToRad(45.0)), verbose);
				Assertv(Double::equals(Vec2<double>(-1.0, 1.0).fullAngle(), Angle::degToRad(315.0)), verbose);
				Assertv(Double::equals(Vec2<double>(-1.0, -1.0).fullAngle(), Angle::degToRad(225.0)), verbose);
				Assertv(Double::equals(Vec2<double>(1.0, -1.0).fullAngle(), Angle::degToRad(135.0)), verbose);
			}
			{ // Rules::RHS
				Vec2<double>::DefaultAxisRule = Rules::RHS;
				Assertve(Vec2<double>::DefaultAxisRule == Rules::RHS, verbose);
				const double lx = 3.0, ly = -1.0;
				const double rx = 2.0, ry = 6.0;
				const Vec2<double> lvec(lx, ly);
				const Vec2<double> rvec(rx, ry);
				const double anglelr = std::atan2(lvec.y, lvec.x) - std::atan2(rvec.y, rvec.x);
				const double anglerl = std::atan2(rvec.y, rvec.x) - std::atan2(lvec.y, lvec.x);
				Assertv(Double::equals(lvec.angle(rvec), anglelr), verbose);
				Assertv(Double::equals(rvec.angle(lvec), anglerl), verbose);
				Assertv(Double::equals(lvec.angle(lvec), 0.0), verbose);
				Assertv(Double::equals(lvec.angle(-lvec), Angle::degToRad(-180.0)), verbose);
				Assertv(Double::equals(rvec.angle(-rvec), Angle::degToRad(180.0)), verbose);
				Assertv(Double::equals(lvec.fullAngle(-lvec), Angle::degToRad(180.0)), verbose);
				Assertv(Double::equals(rvec.fullAngle(-rvec), Angle::degToRad(180.0)), verbose);
			}
			{ // Rules::LHS
				Vec2<double>::DefaultAxisRule = Rules::LHS;
				Assertve(Vec2<double>::DefaultAxisRule == Rules::LHS, verbose);
				const double lx = 3.0, ly = -1.0;
				const double rx = 2.0, ry = 6.0;
				const Vec2<double> lvec(lx, ly);
				const Vec2<double> rvec(rx, ry);
				const double anglelr = std::atan2(lvec.x, lvec.y) - std::atan2(rvec.x, rvec.y);
				const double anglerl = std::atan2(rvec.x, rvec.y) - std::atan2(lvec.x, lvec.y);
				Assertv(Double::equals(lvec.angle(rvec), anglelr), verbose);
				Assertv(Double::equals(rvec.angle(lvec), anglerl), verbose);
				Assertv(Double::equals(lvec.angle(lvec), 0.0), verbose);
				Assertv(Double::equals(lvec.angle(-lvec), Angle::degToRad(180.0)), verbose);
				Assertv(Double::equals(rvec.angle(-rvec), Angle::degToRad(180.0)), verbose);
				Assertv(Double::equals(lvec.fullAngle(-lvec), Angle::degToRad(180.0)), verbose);
				Assertv(Double::equals(rvec.fullAngle(-rvec), Angle::degToRad(180.0)), verbose);
			}
		}
	}
	{ // transforms
		{ // scale
			const double scale = 4.5, scale_x = 1.56, scale_y = 0.75;
			{
				Vec2<double> vec(5.67, 98.999);
				Assertv(vec.equals(5.67, 98.999), verbose);
				vec.scale(1.0);
				Assertv(vec.equals(5.67, 98.999), verbose);
			}
			{
				Vec2<double> vec(5.5, 0.0);
				Assertv(vec.equals(5.5, 0.0), verbose);
				vec.scale(0.0, 2.0);
				Assertv(vec.equals(0.0, 0.0), verbose);
			}
			{
				Vec2<double> vec(5.67, 98.999);
				Assertv(vec.equals(5.67, 98.999), verbose);
				vec.scale(scale);
				Assertv(vec.equals(5.67 * scale, 98.999 * scale), verbose);
			}
			{
				Vec2<double> vec(5.67, 98.999);
				Assertv(vec.equals(5.67, 98.999), verbose);
				vec.scale(scale_x, scale_y);
				Assertv(vec.equals(5.67 * scale_x, 98.999 * scale_y), verbose);
			}
		}
		{ // scaled
			const double scale = 4.5, scale_x = 1.56, scale_y = 0.75;
			{
				const Vec2<double> vec(5.67, 98.999);
				Assertv(vec.equals(5.67, 98.999), verbose);
				Assertv(vec.scaled(1.0).equals(5.67, 98.999), verbose);
			}
			{
				const Vec2<double> vec(5.5, 0.0);
				Assertv(vec.equals(5.5, 0.0), verbose);
				Assertv(vec.scaled(0.0, 2.0).equals(0.0, 0.0), verbose);
			}
			{
				const Vec2<double> vec(5.67, 98.999);
				Assertv(vec.equals(5.67, 98.999), verbose);
				Assertv(vec.scaled(scale).equals(5.67 * scale, 98.999 * scale), verbose);
			}
			{
				const Vec2<double> vec(5.67, 98.999);
				Assertv(vec.equals(5.67, 98.999), verbose);
				Assertv(vec.scaled(scale_x, scale_y).equals(5.67 * scale_x, 98.999 * scale_y), verbose);
			}
		}
		{ // translate
			{ // Vec2<double>
				const Vec2<double> delta(4.5, -900.3434);
				Vec2<double> vec(5.67, 98.999);
				Assertv(vec.equals(5.67, 98.999), verbose);
				vec.translate(delta);
				Assertv(vec.equals(5.67 + delta.x, 98.999 + delta.y), verbose);
			}
			{ // values
				const double delta_x = 4.5, delta_y = -900.3434;
				Vec2<double> vec(5.67, 98.999);
				Assertv(vec.equals(5.67, 98.999), verbose);
				vec.translate(delta_x, delta_y);
				Assertv(vec.equals(5.67 + delta_x, 98.999 + delta_y), verbose);
			}
		}
		{ // translated
			{ // Vec2<double>
				const Vec2<double> delta(4.5, -900.3434);
				const Vec2<double> vec(5.67, 98.999);
				Assertv(vec.equals(5.67, 98.999), verbose);
				Vec2<double> tvec = vec.translated(delta);
				Assertv(tvec.equals(vec.x + delta.x, vec.y + delta.y), verbose);
			}
			{ // values
				const double delta_x = 4.5, delta_y = -900.3434;
				const Vec2<double> vec(5.67, 98.999);
				Assertv(vec.equals(5.67, 98.999), verbose);
				Vec2<double> tvec = vec.translated(delta_x, delta_y);
				Assertv(tvec.equals(vec.x + delta_x, vec.y + delta_y), verbose);
			}
		}
		{ // rotate
			{ // Rules::RHS
				Vec2<double>::DefaultAxisRule = Rules::RHS;
				Assertve(Vec2<double>::DefaultAxisRule == Rules::RHS, verbose);
				Assertv(Vec2<double>(5, 0).rotate(Angle::degToRad(90.0)).equals(0, 5), verbose);
				Assertv(Vec2<double>(0, 5).rotate(Angle::degToRad(90.0)).equals(-5, 0), verbose);
				Assertv(Vec2<double>(-5, 0).rotate(Angle::degToRad(90.0)).equals(0, -5), verbose);
				Assertv(Vec2<double>(0, -5).rotate(Angle::degToRad(90.0)).equals(5, 0), verbose);
				Assertv(Vec2<double>(5, 3).rotate(Angle::degToRad(90.0)).equals(-3, 5), verbose);
				Assertv(Vec2<double>(5, 3).rotate(Angle::degToRad(180.0)).equals(-5, -3), verbose);
				Assertv(Vec2<double>(5, 3).rotate(Angle::degToRad(270.0)).equals(3, -5), verbose);
				Assertv(Vec2<double>(5, 3).rotate(Angle::degToRad(360.0)).equals(5, 3), verbose);
			}
			{ // Rules::LHS
				Vec2<double>::DefaultAxisRule = Rules::LHS;
				Assertve(Vec2<double>::DefaultAxisRule == Rules::LHS, verbose);
				Assertv(Vec2<double>(5, 0).rotate(Angle::degToRad(90.0)).equals(0, -5), verbose);
				Assertv(Vec2<double>(0, 5).rotate(Angle::degToRad(90.0)).equals(5, 0), verbose);
				Assertv(Vec2<double>(-5, 0).rotate(Angle::degToRad(90.0)).equals(0, 5), verbose);
				Assertv(Vec2<double>(0, -5).rotate(Angle::degToRad(90.0)).equals(-5, 0), verbose);
				Assertv(Vec2<double>(5, 3).rotate(Angle::degToRad(90.0)).equals(3, -5), verbose);
				Assertv(Vec2<double>(5, 3).rotate(Angle::degToRad(180.0)).equals(-5, -3), verbose);
				Assertv(Vec2<double>(5, 3).rotate(Angle::degToRad(270.0)).equals(-3, 5), verbose);
				Assertv(Vec2<double>(5, 3).rotate(Angle::degToRad(360.0)).equals(5, 3), verbose);
			}
		}
		{ // rotated
			{ // Rules::RHS
				Vec2<double>::DefaultAxisRule = Rules::RHS;
				Assertve(Vec2<double>::DefaultAxisRule == Rules::RHS, verbose);
				Assertv(Vec2<double>(5, 0).rotated(Angle::degToRad(90.0)).equals(0, 5), verbose);
				Assertv(Vec2<double>(0, 5).rotated(Angle::degToRad(90.0)).equals(-5, 0), verbose);
				Assertv(Vec2<double>(-5, 0).rotated(Angle::degToRad(90.0)).equals(0, -5), verbose);
				Assertv(Vec2<double>(0, -5).rotated(Angle::degToRad(90.0)).equals(5, 0), verbose);
				Assertv(Vec2<double>(5, 3).rotated(Angle::degToRad(90.0)).equals(-3, 5), verbose);
				Assertv(Vec2<double>(5, 3).rotated(Angle::degToRad(180.0)).equals(-5, -3), verbose);
				Assertv(Vec2<double>(5, 3).rotated(Angle::degToRad(270.0)).equals(3, -5), verbose);
				Assertv(Vec2<double>(5, 3).rotated(Angle::degToRad(360.0)).equals(5, 3), verbose);
			}
		}
	}
	if(verbose) {
		puts("----------------------------------------");
		if(Assert::_num_failed_tests <= 0) printf("# All Good!\n", Assert::_num_failed_tests);
		else printf("# %d Failed!\n", Assert::_num_failed_tests);
	}
	return Assert::_num_failed_tests;
}