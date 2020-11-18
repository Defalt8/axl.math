#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include "Assert.hpp"
#include "lib.hpp"
#include <axl.math/constants.hpp>
#include <axl.math/float.hpp>
#include <axl.math/angle.hpp>
#include <axl.math/Vec2f.hpp>

int main(int argc, char *argv[])
{
	bool verbose = argc > 1 && (0 == strcmp(argv[1], "-v") || 0 == strcmp(argv[1], "--verbose"));
	using namespace axl;
	using namespace axl::math;
	using namespace axl::math::Constants;
	printf("axl.math - version %hu.%hu.%hu  %s %s\n", lib::VERSION.major, lib::VERSION.minor, lib::VERSION.patch, cstrLibType(lib::LIBRARY_TYPE), cstrBuildType(lib::BUILD_TYPE));
	puts("----------------------------------------");
	{ // static values
		Assertv(Float::equals(0.0f, Vec2f::Zero.x), verbose);
		Assertv(Float::equals(0.0f, Vec2f::Zero.y), verbose);
		Assertv(Float::equals(1.0f, Vec2f::Identity.x), verbose);
		Assertv(Float::equals(1.0f, Vec2f::Identity.y), verbose);
		Assertv(Vec2f::Default.equals(0.0f, 0.0f, 0.0001f), verbose);
	}
	{ // constructors
		{ // default constructor
			{
				Assertv(Vec2f::Default.equals(Vec2f::Zero), verbose);
				Vec2f vec;
				Assertv(Float::equals(Vec2f::Default.x, vec.x), verbose);
				Assertv(Float::equals(Vec2f::Default.y, vec.y), verbose);
			}
			{
				Vec2f::Default = Vec2f::Identity;
				Assertv(Vec2f::Default.equals(Vec2f::Identity), verbose);
				Vec2f vec;
				Assertv(vec.equals(Vec2f::Identity), verbose);
				Assertv(Float::equals(Vec2f::Default.x, vec.x), verbose);
				Assertv(Float::equals(Vec2f::Default.y, vec.y), verbose);
				Vec2f::Default = Vec2f::Zero;
				Assertv(Vec2f::Default.equals(Vec2f::Zero), verbose);
			}
		}
		{ // values constructor
			Vec2f vec(3.1415f, 0.6721234f);
			Assertv(Float::equals(3.1415f, vec.x), verbose);
			Assertv(Float::equals(0.6721234f, vec.y), verbose);
		}
		{ // copy constructor
			Vec2f vec(3.1415f, 0.6721234f);
			Assertv(Float::equals(3.1415f, vec.x), verbose);
			Assertv(Float::equals(0.6721234f, vec.y), verbose);
			Vec2f vec1(vec);
			Assertv(Float::equals(3.1415f, vec1.x), verbose);
			Assertv(Float::equals(0.6721234f, vec1.y), verbose);
			Vec2f vec2 = vec;
			Assertv(Float::equals(3.1415f, vec2.x), verbose);
			Assertv(Float::equals(0.6721234f, vec2.y), verbose);
		}
	}
	{ // unary operators
		const Vec2f vec(3.4f, 5.6f);
		const Vec2f pvec = +vec;
		const Vec2f nvec = -vec;
		Assertv(pvec.equals(pvec), verbose);
		Assertv(nvec.equals(-pvec.x, -pvec.y, 0.001f), verbose);
		Assertv(vec.equals(-nvec, 0.0001f), verbose);
	}
	{ // Nan
		{
			const Vec2f vec(0.0f/0.0f, 0.0f/0.0f);
			Assertv(vec.isNan(), verbose);
			Assertv(vec.hasNan(), verbose);
			Assertv(!vec.hasNoNan(), verbose);
		}
		{
			const Vec2f vec(0.6f, 0.0f/0.0f);
			Assertv(!vec.isNan(), verbose);
			Assertv(vec.hasNan(), verbose);
			Assertv(!vec.hasNoNan(), verbose);
		}
		{
			const Vec2f vec(0.5f, 1.0f);
			Assertv(!vec.isNan(), verbose);
			Assertv(!vec.hasNan(), verbose);
			Assertv(vec.hasNoNan(), verbose);
		}
	}
	{ // equality operators
		Assertv(Vec2f::Zero == 0.0f, verbose);
		Assertv(Vec2f::Identity == 1.0f, verbose);
		Assertv(Vec2f::Zero == Vec2f::Zero, verbose);
		Assertv(Vec2f::Identity == Vec2f::Identity, verbose);
		Assertv(!(Vec2f::Zero != 0.0f), verbose);
		Assertv(!(Vec2f::Identity != 1.0f), verbose);
		Assertv(!(Vec2f::Zero != Vec2f::Zero), verbose);
		Assertv(!(Vec2f::Identity != Vec2f::Identity), verbose);
		Vec2f vec(3.45f, 4.5f), vec2(1.2345f, 0.987654f);
		Assertv(vec.equals(3.45f, 4.5f), verbose);
		Assertv(vec.equals(vec), verbose);
		Assertv(!vec.equals(vec2), verbose);
		Assertv(!vec.notEquals(3.45f, 4.5f), verbose);
		Assertv(!vec.notEquals(vec), verbose);
		Assertv(vec.notEquals(vec2), verbose);
	}
	{ // arthimetic operators
		{ // addition
			const float lval_x = 12.344f, lval_y = 131.04f, rval_x = 4.5664f, rval_y = 12314.43005f;
			const Vec2f lvec(lval_x, lval_y), rvec(rval_x, rval_y);
			Vec2f vec = lvec + rvec;
			Assertv(vec.equals(lval_x + rval_x, lval_y + rval_y, 0.0001f), verbose);
			
			vec = lvec + rval_y;
			Assertv(vec.equals(lval_x + rval_y, lval_y + rval_y, 0.0001f), verbose);

			vec = lvec;
			Assertv(vec.equals(lval_x, lval_y, 0.0001f), verbose);
			vec += rvec;
			Assertv(vec.equals(lval_x + rval_x, lval_y + rval_y, 0.0001f), verbose);

			vec = lvec;
			Assertv(vec.equals(lval_x, lval_y, 0.0001f), verbose);
			vec += rval_x;
			Assertv(vec.equals(lval_x + rval_x, lval_y + rval_x, 0.0001f), verbose);
		}
		{ // subtraction
			const float lval_x = 12.344f, lval_y = 131.04f, rval_x = 4.5664f, rval_y = 12314.43005f;
			const Vec2f lvec(lval_x, lval_y), rvec(rval_x, rval_y);
			Vec2f vec = lvec - rvec;
			Assertv(vec.equals(lval_x - rval_x, lval_y - rval_y, 0.0001f), verbose);
			
			vec = lvec - rval_y;
			Assertv(vec.equals(lval_x - rval_y, lval_y - rval_y, 0.0001f), verbose);

			vec = lvec;
			Assertv(vec.equals(lval_x, lval_y, 0.0001f), verbose);
			vec -= rvec;
			Assertv(vec.equals(lval_x - rval_x, lval_y - rval_y, 0.0001f), verbose);

			vec = lvec;
			Assertv(vec.equals(lval_x, lval_y, 0.0001f), verbose);
			vec -= rval_x;
			Assertv(vec.equals(lval_x - rval_x, lval_y - rval_x, 0.0001f), verbose);
		}
		{ // multiplication
			const float lval_x = 12.344f, lval_y = 131.04f, rval_x = 4.5664f, rval_y = 12314.43005f;
			const Vec2f lvec(lval_x, lval_y), rvec(rval_x, rval_y);
			Vec2f vec = lvec * rvec;
			Assertv(vec.equals(lval_x * rval_x, lval_y * rval_y, 0.0001f), verbose);
			
			vec = lvec * rval_y;
			Assertv(vec.equals(lval_x * rval_y, lval_y * rval_y, 0.0001f), verbose);

			vec = lvec;
			Assertv(vec.equals(lval_x, lval_y, 0.0001f), verbose);
			vec *= rvec;
			Assertv(vec.equals(lval_x * rval_x, lval_y * rval_y, 0.0001f), verbose);

			vec = lvec;
			Assertv(vec.equals(lval_x, lval_y, 0.0001f), verbose);
			vec *= rval_x;
			Assertv(vec.equals(lval_x * rval_x, lval_y * rval_x, 0.0001f), verbose);
		}
		{ // division
			const float lval_x = 12.344f, lval_y = 131.04f, rval_x = 4.5664f, rval_y = 12314.43005f;
			const Vec2f lvec(lval_x, lval_y), rvec(rval_x, rval_y);
			Vec2f vec = lvec / rvec;
			Assertv(vec.equals(lval_x / rval_x, lval_y / rval_y, 0.0001f), verbose);
			
			vec = lvec / rval_y;
			Assertv(vec.equals(lval_x / rval_y, lval_y / rval_y, 0.0001f), verbose);

			vec = lvec;
			Assertv(vec.equals(lval_x, lval_y, 0.0001f), verbose);
			vec /= rvec;
			Assertv(vec.equals(lval_x / rval_x, lval_y / rval_y, 0.0001f), verbose);

			vec = lvec;
			Assertv(vec.equals(lval_x, lval_y, 0.0001f), verbose);
			vec /= rval_x;
			Assertv(vec.equals(lval_x / rval_x, lval_y / rval_x, 0.0001f), verbose);
		}
	}
	{ // vector operations
		{ // magnitude
			const float x = 2.0f, y = 3.0f;
			const Vec2f vec(x, y);
			const float magn = vec.magn();
			Assertv(Float::equals(magn, std::sqrt(x * x + y * y), 0.0001f), verbose);
			Assertv(Float::equals(magn, std::sqrt(std::pow(x, 2.0f) + std::pow(y, 2.0f)), 0.0001f), verbose);
		}
		{ // normal
			{
				const float x = 2.0f, y = 3.0f;
				const Vec2f vec(x, y);
				const float magn1 = std::sqrt(x * x + y * y);
				const float magn2 = std::sqrt(std::pow(x, 2.0f) + std::pow(y, 2.0f));
				const Vec2f norm_vec = vec.norm();
				const Vec2f norm_vec1 = vec / magn1;
				const Vec2f norm_vec2 = vec / magn2;
				Assertv(Float::equals(1.0f, norm_vec.magn(), 0.0001f), verbose);
				Assertv(Float::equals(1.0f, norm_vec1.magn(), 0.0001f), verbose);
				Assertv(Float::equals(1.0f, norm_vec2.magn(), 0.0001f), verbose);
				Assertv(Float::equals(1.0f, std::sqrt(norm_vec.x * norm_vec.x + norm_vec.y * norm_vec.y), 0.0001f), verbose);
				Assertv(Float::equals(1.0f, std::sqrt(norm_vec1.x * norm_vec1.x + norm_vec1.y * norm_vec1.y), 0.0001f), verbose);
				Assertv(Float::equals(1.0f, std::sqrt(std::pow(norm_vec2.x, 2.0f) + std::pow(norm_vec2.y, 2.0f)), 0.0001f), verbose);
			}
			{
				const float x = 2.0f, y = 3.0f;
				const Vec2f vec(x, y);
				Vec2f nvec(x, y);
				nvec.normalize();
				const float magn1 = std::sqrt(x * x + y * y);
				const Vec2f norm_vec = vec / magn1;
				Assertv(nvec.equals(norm_vec, 0.0001f), verbose);
				Assertv(Float::equals(1.0f, nvec.magn(), 0.0001f), verbose);
				Assertv(Float::equals(1.0f, norm_vec.magn(), 0.0001f), verbose);
				Assertv(vec.equals(nvec * vec.magn(), 0.0001f), verbose);
			}
		}
		{ // dot product
			const float lx = 2.0f, ly = 3.0f;
			const float rx = 4.0f, ry = 6.0f;
			const Vec2f lvec(lx, ly);
			const Vec2f rvec(rx, ry);
			const float dotplr = lvec.dot(rvec);
			const float dotprl = rvec.dot(lvec);
			Assertv(Float::equals(dotplr, (lx * rx + ly * ry), 0.0001f), verbose);
			Assertv(Float::equals(dotprl, (lx * rx + ly * ry), 0.0001f), verbose);
		}
		{ // cross product
			const float lx = 2.0f, ly = 3.0f;
			const float rx = 4.0f, ry = 6.0f;
			const Vec2f lvec(lx, ly);
			const Vec2f rvec(rx, ry);
			const float crossplr = lvec.cross(rvec);
			const float crossprl = rvec.cross(lvec);
			Assertv(Float::equals(crossplr, (lx * ry - ly * rx), 0.0001f), verbose);
			Assertv(Float::equals(crossprl, (rx * ly - ry * lx), 0.0001f), verbose);
		}
		{ // angle
			Assertve(Vec2f::DefaultAxisRule == Rules::AXIS_RHS, verbose);
			{ // Rules::AXIS_RHS
				Assertv(Float::equals(Vec2f(-0.0f, 0.0f).angle(), Angle::degToRad(180.0f), 0.0001f), verbose);
				Assertv(Float::equals(Vec2f(0.0f, -0.0f).angle(), Angle::degToRad(-0.0f), 0.0001f), verbose);
				Assertv(Float::equals(Vec2f(-0.0f, -0.0f).angle(), Angle::degToRad(-180.0f), 0.0001f), verbose);
				Assertv(Float::equals(Vec2f(0.0f, 0.0f).angle(), Angle::degToRad(0.0f), 0.0001f), verbose);
				Assertv(Float::equals(Vec2f(1.0f, 0.0f).angle(), Angle::degToRad(0.0f), 0.0001f), verbose);
				Assertv(Float::equals(Vec2f(0.0f, 1.0f).angle(), Angle::degToRad(90.0f), 0.0001f), verbose);
				Assertv(Float::equals(Vec2f(-1.0f, 0.0f).angle(), Angle::degToRad(180.0f), 0.0001f), verbose);
				Assertv(Float::equals(Vec2f(0.0f, -1.0f).angle(), -Angle::degToRad(90.0f), 0.0001f), verbose);
				Assertv(Float::equals(Vec2f(1.0f, 1.0f).angle(), Angle::degToRad(45.0f), 0.0001f), verbose);
				Assertv(Float::equals(Vec2f(-1.0f, 1.0f).angle(), Angle::degToRad(135.0f), 0.0001f), verbose);
				Assertv(Float::equals(Vec2f(-1.0f, -1.0f).angle(), -Angle::degToRad(135.0f), 0.0001f), verbose);
				Assertv(Float::equals(Vec2f(1.0f, -1.0f).angle(), -Angle::degToRad(45.0f), 0.0001f), verbose);
				// full angle
				Assertv(Float::equals(Vec2f(-0.0f, 0.0f).fullAngle(), Angle::degToRad(180.0f), 0.0001f), verbose);
				Assertv(Float::equals(Vec2f(0.0f, -0.0f).fullAngle(), Angle::degToRad(0.0f), 0.0001f), verbose);
				Assertv(Float::equals(Vec2f(-0.0f, -0.0f).fullAngle(), Angle::degToRad(180.0f), 0.0001f), verbose);
				Assertv(Float::equals(Vec2f(0.0f, 0.0f).fullAngle(), Angle::degToRad(0.0f), 0.0001f), verbose);
				Assertv(Float::equals(Vec2f(1.0f, 0.0f).fullAngle(), Angle::degToRad(0.0f), 0.0001f), verbose);
				Assertv(Float::equals(Vec2f(0.0f, 1.0f).fullAngle(), Angle::degToRad(90.0f), 0.0001f), verbose);
				Assertv(Float::equals(Vec2f(-1.0f, 0.0f).fullAngle(), Angle::degToRad(180.0f), 0.0001f), verbose);
				Assertv(Float::equals(Vec2f(0.0f, -1.0f).fullAngle(), Angle::degToRad(270.0f), 0.0001f), verbose);
				Assertv(Float::equals(Vec2f(1.0f, 1.0f).fullAngle(), Angle::degToRad(45.0f), 0.0001f), verbose);
				Assertv(Float::equals(Vec2f(-1.0f, 1.0f).fullAngle(), Angle::degToRad(135.0f), 0.0001f), verbose);
				Assertv(Float::equals(Vec2f(-1.0f, -1.0f).fullAngle(), Angle::degToRad(225.0f), 0.0001f), verbose);
				Assertv(Float::equals(Vec2f(1.0f, -1.0f).fullAngle(), Angle::degToRad(315.0f), 0.0001f), verbose);
			}
			{ // Rules::AXIS_LHS
				Vec2f::DefaultAxisRule = Rules::AXIS_LHS;
				Assertve(Vec2f::DefaultAxisRule == Rules::AXIS_LHS, verbose);
				Assertv(Float::equals(Vec2f(-0.0f, 0.0f).angle(), Angle::degToRad(-0.0f), 0.0001f), verbose);
				Assertv(Float::equals(Vec2f(0.0f, -0.0f).angle(), Angle::degToRad(180.0f), 0.0001f), verbose);
				Assertv(Float::equals(Vec2f(-0.0f, -0.0f).angle(), Angle::degToRad(-180.0f), 0.0001f), verbose);
				Assertv(Float::equals(Vec2f(0.0f, 0.0f).angle(), Angle::degToRad(0.0f), 0.0001f), verbose);
				Assertv(Float::equals(Vec2f(1.0f, 0.0f).angle(), Angle::degToRad(90.0f), 0.0001f), verbose);
				Assertv(Float::equals(Vec2f(0.0f, 1.0f).angle(), Angle::degToRad(0.0f), 0.0001f), verbose);
				Assertv(Float::equals(Vec2f(-1.0f, 0.0f).angle(), Angle::degToRad(-90.0f), 0.0001f), verbose);
				Assertv(Float::equals(Vec2f(0.0f, -1.0f).angle(), Angle::degToRad(180.0f), 0.0001f), verbose);
				Assertv(Float::equals(Vec2f(1.0f, 1.0f).angle(), Angle::degToRad(45.0f), 0.0001f), verbose);
				Assertv(Float::equals(Vec2f(-1.0f, 1.0f).angle(), Angle::degToRad(-45.0f), 0.0001f), verbose);
				Assertv(Float::equals(Vec2f(-1.0f, -1.0f).angle(), Angle::degToRad(-135.0f), 0.0001f), verbose);
				Assertv(Float::equals(Vec2f(1.0f, -1.0f).angle(), Angle::degToRad(135.0f), 0.0001f), verbose);
				// full angle
				Assertv(Float::equals(Vec2f(-0.0f, 0.0f).fullAngle(), Angle::degToRad(0.0f), 0.0001f), verbose);
				Assertv(Float::equals(Vec2f(0.0f, -0.0f).fullAngle(), Angle::degToRad(180.0f), 0.0001f), verbose);
				Assertv(Float::equals(Vec2f(-0.0f, -0.0f).fullAngle(), Angle::degToRad(180.0f), 0.0001f), verbose);
				Assertv(Float::equals(Vec2f(0.0f, 0.0f).fullAngle(), Angle::degToRad(0.0f), 0.0001f), verbose);
				Assertv(Float::equals(Vec2f(1.0f, 0.0f).fullAngle(), Angle::degToRad(90.0f), 0.0001f), verbose);
				Assertv(Float::equals(Vec2f(0.0f, 1.0f).fullAngle(), Angle::degToRad(0.0f), 0.0001f), verbose);
				Assertv(Float::equals(Vec2f(-1.0f, 0.0f).fullAngle(), Angle::degToRad(270.0f), 0.0001f), verbose);
				Assertv(Float::equals(Vec2f(0.0f, -1.0f).fullAngle(), Angle::degToRad(180.0f), 0.0001f), verbose);
				Assertv(Float::equals(Vec2f(1.0f, 1.0f).fullAngle(), Angle::degToRad(45.0f), 0.0001f), verbose);
				Assertv(Float::equals(Vec2f(-1.0f, 1.0f).fullAngle(), Angle::degToRad(315.0f), 0.0001f), verbose);
				Assertv(Float::equals(Vec2f(-1.0f, -1.0f).fullAngle(), Angle::degToRad(225.0f), 0.0001f), verbose);
				Assertv(Float::equals(Vec2f(1.0f, -1.0f).fullAngle(), Angle::degToRad(135.0f), 0.0001f), verbose);
			}
			{ // Rules::AXIS_RHS
				Vec2f::DefaultAxisRule = Rules::AXIS_RHS;
				Assertve(Vec2f::DefaultAxisRule == Rules::AXIS_RHS, verbose);
				const float lx = 3.0f, ly = -1.0f;
				const float rx = 2.0f, ry = 6.0f;
				const Vec2f lvec(lx, ly);
				const Vec2f rvec(rx, ry);
				const float anglelr = std::atan2(lvec.y, lvec.x) - std::atan2(rvec.y, rvec.x);
				const float anglerl = std::atan2(rvec.y, rvec.x) - std::atan2(lvec.y, lvec.x);
				Assertv(Float::equals(lvec.angle(rvec), anglelr, 0.0001f), verbose);
				Assertv(Float::equals(rvec.angle(lvec), anglerl, 0.0001f), verbose);
				Assertv(Float::equals(lvec.angle(lvec), 0.0f, 0.0001f), verbose);
				Assertv(Float::equals(lvec.angle(-lvec), Angle::degToRad(-180.0f), 0.0001f), verbose);
				Assertv(Float::equals(rvec.angle(-rvec), Angle::degToRad(180.0f), 0.0001f), verbose);
				Assertv(Float::equals(lvec.fullAngle(-lvec), Angle::degToRad(180.0f), 0.0001f), verbose);
				Assertv(Float::equals(rvec.fullAngle(-rvec), Angle::degToRad(180.0f), 0.0001f), verbose);
			}
			{ // Rules::AXIS_LHS
				Vec2f::DefaultAxisRule = Rules::AXIS_LHS;
				Assertve(Vec2f::DefaultAxisRule == Rules::AXIS_LHS, verbose);
				const float lx = 3.0f, ly = -1.0f;
				const float rx = 2.0f, ry = 6.0f;
				const Vec2f lvec(lx, ly);
				const Vec2f rvec(rx, ry);
				const float anglelr = std::atan2(lvec.x, lvec.y) - std::atan2(rvec.x, rvec.y);
				const float anglerl = std::atan2(rvec.x, rvec.y) - std::atan2(lvec.x, lvec.y);
				Assertv(Float::equals(lvec.angle(rvec), anglelr, 0.0001f), verbose);
				Assertv(Float::equals(rvec.angle(lvec), anglerl, 0.0001f), verbose);
				Assertv(Float::equals(lvec.angle(lvec), 0.0f, 0.0001f), verbose);
				Assertv(Float::equals(lvec.angle(-lvec), Angle::degToRad(180.0f), 0.0001f), verbose);
				Assertv(Float::equals(rvec.angle(-rvec), Angle::degToRad(180.0f), 0.0001f), verbose);
				Assertv(Float::equals(lvec.fullAngle(-lvec), Angle::degToRad(180.0f), 0.0001f), verbose);
				Assertv(Float::equals(rvec.fullAngle(-rvec), Angle::degToRad(180.0f), 0.0001f), verbose);
			}
		}
	}
	{ // transforms
		{ // scale
			const float scale = 4.5f, scale_x = 1.56f, scale_y = 0.75f;
			{
				Vec2f vec(5.67f, 98.999f);
				Assertv(vec.equals(5.67f, 98.999f, 0.0001f), verbose);
				vec.scale(1.0f);
				Assertv(vec.equals(5.67f, 98.999f, 0.0001f), verbose);
			}
			{
				Vec2f vec(5.5f, 0.0f);
				Assertv(vec.equals(5.5f, 0.0f, 0.0001f), verbose);
				vec.scale(0.0f, 2.0f);
				Assertv(vec.equals(0.0f, 0.0f, 0.0001f), verbose);
			}
			{
				Vec2f vec(5.67f, 98.999f);
				Assertv(vec.equals(5.67f, 98.999f, 0.0001f), verbose);
				vec.scale(scale);
				Assertv(vec.equals(5.67f * scale, 98.999f * scale, 0.0001f), verbose);
			}
			{
				Vec2f vec(5.67f, 98.999f);
				Assertv(vec.equals(5.67f, 98.999f, 0.0001f), verbose);
				vec.scale(scale_x, scale_y);
				Assertv(vec.equals(5.67f * scale_x, 98.999f * scale_y, 0.0001f), verbose);
			}
		}
		{ // scaled
			const float scale = 4.5f, scale_x = 1.56f, scale_y = 0.75f;
			{
				const Vec2f vec(5.67f, 98.999f);
				Assertv(vec.equals(5.67f, 98.999f, 0.0001f), verbose);
				Assertv(vec.scaled(1.0f).equals(5.67f, 98.999f, 0.0001f), verbose);
			}
			{
				const Vec2f vec(5.5f, 0.0f);
				Assertv(vec.equals(5.5f, 0.0f, 0.0001f), verbose);
				Assertv(vec.scaled(0.0f, 2.0f).equals(0.0f, 0.0f, 0.0001f), verbose);
			}
			{
				const Vec2f vec(5.67f, 98.999f);
				Assertv(vec.equals(5.67f, 98.999f, 0.0001f), verbose);
				Assertv(vec.scaled(scale).equals(5.67f * scale, 98.999f * scale, 0.0001f), verbose);
			}
			{
				const Vec2f vec(5.67f, 98.999f);
				Assertv(vec.equals(5.67f, 98.999f, 0.0001f), verbose);
				Assertv(vec.scaled(scale_x, scale_y).equals(5.67f * scale_x, 98.999f * scale_y, 0.0001f), verbose);
			}
		}
		{ // translate
			{ // Vec2f
				const Vec2f delta(4.5f, -900.3434f);
				Vec2f vec(5.67f, 98.999f);
				Assertv(vec.equals(5.67f, 98.999f, 0.0001f), verbose);
				vec.translate(delta);
				Assertv(vec.equals(5.67f + delta.x, 98.999f + delta.y, 0.0001f), verbose);
			}
			{ // values
				const float delta_x = 4.5f, delta_y = -900.3434f;
				Vec2f vec(5.67f, 98.999f);
				Assertv(vec.equals(5.67f, 98.999f), verbose);
				vec.translate(delta_x, delta_y);
				Assertv(vec.equals(5.67f + delta_x, 98.999f + delta_y, 0.0001f), verbose);
			}
		}
		{ // translated
			{ // Vec2f
				const Vec2f delta(4.5f, -900.3434f);
				const Vec2f vec(5.67f, 98.999f);
				Assertv(vec.equals(5.67f, 98.999f, 0.0001f), verbose);
				Vec2f tvec = vec.translated(delta);
				Assertv(tvec.equals(vec.x + delta.x, vec.y + delta.y, 0.0001f), verbose);
			}
			{ // values
				const float delta_x = 4.5f, delta_y = -900.3434f;
				const Vec2f vec(5.67f, 98.999f);
				Assertv(vec.equals(5.67f, 98.999f), verbose);
				Vec2f tvec = vec.translated(delta_x, delta_y);
				Assertv(tvec.equals(vec.x + delta_x, vec.y + delta_y, 0.0001f), verbose);
			}
		}
		{ // rotate
			{ // Rules::AXIS_RHS
				Vec2f::DefaultAxisRule = Rules::AXIS_RHS;
				Assertve(Vec2f::DefaultAxisRule == Rules::AXIS_RHS, verbose);
				Assertv(Vec2f(5, 0).rotate(Angle::degToRad(90.0f)).equals(0, 5, 0.0001f), verbose);
				Assertv(Vec2f(0, 5).rotate(Angle::degToRad(90.0f)).equals(-5, 0, 0.0001f), verbose);
				Assertv(Vec2f(-5, 0).rotate(Angle::degToRad(90.0f)).equals(0, -5, 0.0001f), verbose);
				Assertv(Vec2f(0, -5).rotate(Angle::degToRad(90.0f)).equals(5, 0, 0.0001f), verbose);
				Assertv(Vec2f(5, 3).rotate(Angle::degToRad(90.0f)).equals(-3, 5, 0.0001f), verbose);
				Assertv(Vec2f(5, 3).rotate(Angle::degToRad(180.0f)).equals(-5, -3, 0.0001f), verbose);
				Assertv(Vec2f(5, 3).rotate(Angle::degToRad(270.0f)).equals(3, -5, 0.0001f), verbose);
				Assertv(Vec2f(5, 3).rotate(Angle::degToRad(360.0f)).equals(5, 3, 0.0001f), verbose);
			}
			{ // Rules::AXIS_LHS
				Vec2f::DefaultAxisRule = Rules::AXIS_LHS;
				Assertve(Vec2f::DefaultAxisRule == Rules::AXIS_LHS, verbose);
				Assertv(Vec2f(5, 0).rotate(Angle::degToRad(90.0f)).equals(0, -5, 0.0001f), verbose);
				Assertv(Vec2f(0, 5).rotate(Angle::degToRad(90.0f)).equals(5, 0, 0.0001f), verbose);
				Assertv(Vec2f(-5, 0).rotate(Angle::degToRad(90.0f)).equals(0, 5, 0.0001f), verbose);
				Assertv(Vec2f(0, -5).rotate(Angle::degToRad(90.0f)).equals(-5, 0, 0.0001f), verbose);
				Assertv(Vec2f(5, 3).rotate(Angle::degToRad(90.0f)).equals(3, -5, 0.0001f), verbose);
				Assertv(Vec2f(5, 3).rotate(Angle::degToRad(180.0f)).equals(-5, -3, 0.0001f), verbose);
				Assertv(Vec2f(5, 3).rotate(Angle::degToRad(270.0f)).equals(-3, 5, 0.0001f), verbose);
				Assertv(Vec2f(5, 3).rotate(Angle::degToRad(360.0f)).equals(5, 3, 0.0001f), verbose);
			}
		}
		{ // rotated
			{ // Rules::AXIS_RHS
				Vec2f::DefaultAxisRule = Rules::AXIS_RHS;
				Assertve(Vec2f::DefaultAxisRule == Rules::AXIS_RHS, verbose);
				Assertv(Vec2f(5, 0).rotated(Angle::degToRad(90.0f)).equals(0, 5, 0.0001f), verbose);
				Assertv(Vec2f(0, 5).rotated(Angle::degToRad(90.0f)).equals(-5, 0, 0.0001f), verbose);
				Assertv(Vec2f(-5, 0).rotated(Angle::degToRad(90.0f)).equals(0, -5, 0.0001f), verbose);
				Assertv(Vec2f(0, -5).rotated(Angle::degToRad(90.0f)).equals(5, 0, 0.0001f), verbose);
				Assertv(Vec2f(5, 3).rotated(Angle::degToRad(90.0f)).equals(-3, 5, 0.0001f), verbose);
				Assertv(Vec2f(5, 3).rotated(Angle::degToRad(180.0f)).equals(-5, -3, 0.0001f), verbose);
				Assertv(Vec2f(5, 3).rotated(Angle::degToRad(270.0f)).equals(3, -5, 0.0001f), verbose);
				Assertv(Vec2f(5, 3).rotated(Angle::degToRad(360.0f)).equals(5, 3, 0.0001f), verbose);
			}
		}
	}

	if(Assert::_num_failed_tests <= 0)
		printf("# All Good!\n", Assert::_num_failed_tests);
	else
	{
		puts("----------------------------------------");
		printf("# %d Failed!\n", Assert::_num_failed_tests);
	}
	return Assert::_num_failed_tests;
}