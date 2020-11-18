#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include "Assert.hpp"
#include "lib.hpp"
#include <axl.math/constants.hpp>
#include <axl.math/angle.hpp>
#include <axl.math/double.hpp>
#include <axl.math/Vec3d.hpp>

float _zero = 0.0;
const static float _nan = _zero / _zero;

int main(int argc, char *argv[])
{
	bool verbose = argc > 1 && (0 == strcmp(argv[1], "-v") || 0 == strcmp(argv[1], "--verbose"));
	using namespace axl;
	using namespace axl::math;
	using namespace axl::math::Constants;
	using namespace axl::math::Angle;
	printf("axl.math - version %hu.%hu.%hu  %s %s\n", lib::VERSION.major, lib::VERSION.minor, lib::VERSION.patch, cstrLibType(lib::LIBRARY_TYPE), cstrBuildType(lib::BUILD_TYPE));
	puts("----------------------------------------");
	const double sq2 = std::sqrt(2.0);
	{ // static values
		Assertv(Double::equals(0.0, Vec3d::Zero.x), verbose);
		Assertv(Double::equals(0.0, Vec3d::Zero.y), verbose);
		Assertv(Double::equals(0.0, Vec3d::Zero.z), verbose);
		Assertv(Double::equals(1.0, Vec3d::Identity.x), verbose);
		Assertv(Double::equals(1.0, Vec3d::Identity.y), verbose);
		Assertv(Double::equals(1.0, Vec3d::Identity.z), verbose);
		Assertv(Vec3d::Default.equals(0.0, 0.0, 0.0), verbose);
	}
	{ // constructors
		{ // default constructor
			{
				Assertv(Vec3d::Default.equals(Vec3d::Zero), verbose);
				Vec3d vec;
				Assertv(Double::equals(Vec3d::Default.x, vec.x), verbose);
				Assertv(Double::equals(Vec3d::Default.y, vec.y), verbose);
				Assertv(Double::equals(Vec3d::Default.z, vec.z), verbose);
			}
			{
				Vec3d::Default = Vec3d::Identity;
				Assertv(Vec3d::Default.equals(Vec3d::Identity), verbose);
				Vec3d vec;
				Assertv(vec.equals(Vec3d::Identity), verbose);
				Assertv(Double::equals(Vec3d::Default.x, vec.x), verbose);
				Assertv(Double::equals(Vec3d::Default.y, vec.y), verbose);
				Assertv(Double::equals(Vec3d::Default.z, vec.z), verbose);
				Vec3d::Default = Vec3d::Zero;
				Assertv(Vec3d::Default.equals(Vec3d::Zero), verbose);
			}
		}
		{ // values constructor
			Vec3d vec(3.1415, 0.6721234, 456.3422);
			Assertv(Double::equals(3.1415, vec.x), verbose);
			Assertv(Double::equals(0.6721234, vec.y), verbose);
			Assertv(Double::equals(456.3422, vec.z), verbose);
		}
		{ // copy constructor
			{
				Vec3d vec(3.1415, 0.6721234, 456.3422);
				Assertv(Double::equals(3.1415, vec.x), verbose);
				Assertv(Double::equals(0.6721234, vec.y), verbose);
				Assertv(Double::equals(456.3422, vec.z), verbose);
				Vec3d vec1(vec);
				Assertv(Double::equals(3.1415, vec1.x), verbose);
				Assertv(Double::equals(0.6721234, vec1.y), verbose);
				Assertv(Double::equals(456.3422, vec1.z), verbose);
				Vec3d vec2 = vec;
				Assertv(Double::equals(3.1415, vec2.x), verbose);
				Assertv(Double::equals(0.6721234, vec2.y), verbose);
				Assertv(Double::equals(456.3422, vec2.z), verbose);
			}
			{
				const Vec2d vec2(1.23, 3.45);
				Assertv(vec2.equals(1.23, 3.45), verbose);
				{
					const Vec3d vec3(vec2);
					Assertv(vec3.equals(1.23, 3.45, 0.0), verbose);
				}
				{
					const Vec3d vec3(vec2, 6.9);
					Assertv(vec3.equals(1.23, 3.45, 6.9), verbose);
				}
			}
		}
	}
	{ // unary operators
		const Vec3d vec(3.4, 5.6, 1.2345);
		const Vec3d pvec = +vec;
		const Vec3d nvec = -vec;
		Assertv(pvec.equals(pvec), verbose);
		Assertv(nvec.equals(-pvec.x, -pvec.y, -pvec.z, 0.001), verbose);
		Assertv(vec.equals(-nvec), verbose);
	}
	{ // Nan
		{
			const Vec3d vec(_nan, _nan, _nan);
			Assertv(vec.isNan(), verbose);
			Assertv(vec.hasNan(), verbose);
			Assertv(!vec.hasNoNan(), verbose);
		}
		{
			const Vec3d vec(0.6, _nan, _nan);
			Assertv(!vec.isNan(), verbose);
			Assertv(vec.hasNan(), verbose);
			Assertv(!vec.hasNoNan(), verbose);
		}
		{
			const Vec3d vec(0.6, _nan, 5.5);
			Assertv(!vec.isNan(), verbose);
			Assertv(vec.hasNan(), verbose);
			Assertv(!vec.hasNoNan(), verbose);
		}
		{
			const Vec3d vec(0.5, 1.0, 6.4);
			Assertv(!vec.isNan(), verbose);
			Assertv(!vec.hasNan(), verbose);
			Assertv(vec.hasNoNan(), verbose);
		}
	}
	{ // equality operators
		Assertv(Vec3d::Zero == 0.0, verbose);
		Assertv(Vec3d::Identity == 1.0, verbose);
		Assertv(Vec3d::Zero == Vec3d::Zero, verbose);
		Assertv(Vec3d::Identity == Vec3d::Identity, verbose);
		Assertv(!(Vec3d::Zero != 0.0), verbose);
		Assertv(!(Vec3d::Identity != 1.0), verbose);
		Assertv(!(Vec3d::Zero != Vec3d::Zero), verbose);
		Assertv(!(Vec3d::Identity != Vec3d::Identity), verbose);
		Vec3d vec(3.45, 4.5, 324.23), vec2(1.2345, 0.987654, 324.23);
		Assertv(vec.equals(3.45, 4.5, 324.23), verbose);
		Assertv(vec.equals(vec), verbose);
		Assertv(!vec.equals(vec2), verbose);
		Assertv(!vec.notEquals(3.45, 4.5, 324.23), verbose);
		Assertv(!vec.notEquals(vec), verbose);
		Assertv(vec.notEquals(vec2), verbose);
	}
	{ // arthimetic operators
		{ // addition
			const double lval_x = 12.344, lval_y = 131.04, lval_z = 0.3445453;
			const double rval_x = 4.5664, rval_y = 12314.43005, rval_z = 344.56;
			const Vec3d lvec(lval_x, lval_y, lval_z), rvec(rval_x, rval_y, rval_z);
			Vec3d vec = lvec + rvec;
			Assertv(vec.equals(lval_x + rval_x, lval_y + rval_y, lval_z + rval_z), verbose);
			
			vec = lvec + rval_y;
			Assertv(vec.equals(lval_x + rval_y, lval_y + rval_y, lval_z + rval_y), verbose);

			vec = lvec;
			Assertv(vec.equals(lval_x, lval_y, lval_z), verbose);
			vec += rvec;
			Assertv(vec.equals(lval_x + rval_x, lval_y + rval_y, lval_z + rval_z), verbose);

			vec = lvec;
			Assertv(vec.equals(lval_x, lval_y, lval_z), verbose);
			vec += rval_x;
			Assertv(vec.equals(lval_x + rval_x, lval_y + rval_x, lval_z + rval_x), verbose);
		}
		{ // subtraction
			const double lval_x = 12.344, lval_y = 131.04, lval_z = 0.3445453;
			const double rval_x = 4.5664, rval_y = 12314.43005, rval_z = 344.56;
			const Vec3d lvec(lval_x, lval_y, lval_z), rvec(rval_x, rval_y, rval_z);
			Vec3d vec = lvec - rvec;
			Assertv(vec.equals(lval_x - rval_x, lval_y - rval_y, lval_z - rval_z), verbose);
			
			vec = lvec - rval_y;
			Assertv(vec.equals(lval_x - rval_y, lval_y - rval_y, lval_z - rval_y), verbose);

			vec = lvec;
			Assertv(vec.equals(lval_x, lval_y, lval_z), verbose);
			vec -= rvec;
			Assertv(vec.equals(lval_x - rval_x, lval_y - rval_y, lval_z - rval_z), verbose);

			vec = lvec;
			Assertv(vec.equals(lval_x, lval_y, lval_z), verbose);
			vec -= rval_x;
			Assertv(vec.equals(lval_x - rval_x, lval_y - rval_x, lval_z - rval_x), verbose);
		}
		{ // multiplication
			const double lval_x = 12.344, lval_y = 131.04, lval_z = 0.3445453;
			const double rval_x = 4.5664, rval_y = 12314.43005, rval_z = 344.56;
			const Vec3d lvec(lval_x, lval_y, lval_z), rvec(rval_x, rval_y, rval_z);
			Vec3d vec = lvec * rvec;
			Assertv(vec.equals(lval_x * rval_x, lval_y * rval_y, lval_z * rval_z), verbose);
			
			vec = lvec * rval_y;
			Assertv(vec.equals(lval_x * rval_y, lval_y * rval_y, lval_z * rval_y), verbose);

			vec = lvec;
			Assertv(vec.equals(lval_x, lval_y, lval_z), verbose);
			vec *= rvec;
			Assertv(vec.equals(lval_x * rval_x, lval_y * rval_y, lval_z * rval_z), verbose);

			vec = lvec;
			Assertv(vec.equals(lval_x, lval_y, lval_z), verbose);
			vec *= rval_x;
			Assertv(vec.equals(lval_x * rval_x, lval_y * rval_x, lval_z * rval_x), verbose);
		}
		{ // division
			const double lval_x = 12.344, lval_y = 131.04, lval_z = 0.3445453;
			const double rval_x = 4.5664, rval_y = 12314.43005, rval_z = 344.56;
			const Vec3d lvec(lval_x, lval_y, lval_z), rvec(rval_x, rval_y, rval_z);
			Vec3d vec = lvec / rvec;
			Assertv(vec.equals(lval_x / rval_x, lval_y / rval_y, lval_z / rval_z), verbose);
			
			vec = lvec / rval_y;
			Assertv(vec.equals(lval_x / rval_y, lval_y / rval_y, lval_z / rval_y), verbose);

			vec = lvec;
			Assertv(vec.equals(lval_x, lval_y, lval_z), verbose);
			vec /= rvec;
			Assertv(vec.equals(lval_x / rval_x, lval_y / rval_y, lval_z / rval_z), verbose);

			vec = lvec;
			Assertv(vec.equals(lval_x, lval_y, lval_z), verbose);
			vec /= rval_x;
			Assertv(vec.equals(lval_x / rval_x, lval_y / rval_x, lval_z / rval_x), verbose);
		}
	}
	{ // vector operations
		{ // magnitude
			const double x = 2.0, y = 3.0, z = -4.6;
			const Vec3d vec(x, y, z);
			const double magn = vec.magn();
			Assertv(Double::equals(magn, std::sqrt(x * x + y * y + z * z)), verbose);
			Assertv(Double::equals(magn, std::sqrt(std::pow(x, 2.0) + std::pow(y, 2.0) + std::pow(z, 2.0))), verbose);
		}
		{ // normal
			{
				const double x = 2.0, y = 3.0, z = -3.5;
				const Vec3d vec(x, y, z);
				const double magn1 = std::sqrt(x * x + y * y + z * z);
				const double magn2 = std::sqrt(std::pow(x, 2.0) + std::pow(y, 2.0) + std::pow(z, 2.0));
				const Vec3d norm_vec = vec.norm();
				const Vec3d norm_vec1 = vec / magn1;
				const Vec3d norm_vec2 = vec / magn2;
				Assertv(Double::equals(1.0, norm_vec.magn()), verbose);
				Assertv(Double::equals(1.0, norm_vec1.magn()), verbose);
				Assertv(Double::equals(1.0, norm_vec2.magn()), verbose);
				Assertv(Double::equals(1.0, std::sqrt(norm_vec1.x * norm_vec1.x + norm_vec1.y * norm_vec1.y + norm_vec1.z * norm_vec1.z)), verbose);
				Assertv(Double::equals(1.0, std::sqrt(std::pow(norm_vec2.x, 2.0) + std::pow(norm_vec2.y, 2.0) + std::pow(norm_vec2.z, 2.0))), verbose);
			}
			{
				const double x = 2.0, y = 3.0, z = -4.5;
				const Vec3d vec(x, y, z);
				Vec3d nvec(x, y, z);
				nvec.normalize();
				const double magn1 = std::sqrt(x * x + y * y + z * z);
				const Vec3d norm_vec = vec / magn1;
				Assertv(nvec.equals(norm_vec), verbose);
				Assertv(Double::equals(1.0, nvec.magn()), verbose);
				Assertv(Double::equals(1.0, norm_vec.magn()), verbose);
				Assertv(vec.equals(nvec * vec.magn()), verbose);
			}
		}
		{ // dot product
			const double lx = 2.0, ly = 3.0, lz = -3.5;
			const double rx = 4.0, ry = -6.0, rz = -9.5;
			const Vec3d lvec(lx, ly, lz);
			const Vec3d rvec(rx, ry, rz);
			const double dotplr = lvec.dot(rvec);
			const double dotprl = rvec.dot(lvec);
			Assertv(Double::equals(dotplr, (lx * rx + ly * ry + lz * rz)), verbose);
			Assertv(Double::equals(dotprl, (lx * rx + ly * ry + lz * rz)), verbose);
		}
		{ // cross product
			const double lx = 2.0, ly = 3.0, lz = -3.5;
			const double rx = 4.0, ry = -6.0, rz = -9.5;
			const Vec3d lvec(lx, ly, lz);
			const Vec3d rvec(rx, ry, rz);
			const Vec3d crossplr = lvec.cross(rvec);
			const Vec3d crossprl = rvec.cross(lvec);
			Assertv(crossplr.equals((ly * rz - lz * ry), -(lx * rz - lz * rx), (lx * ry - ly * rx)), verbose);
			Assertv(crossprl.equals((ry * lz - rz * ly), -(rx * lz - rz * lx), (rx * ly - ry * lx)), verbose);

		}
		{ // euler angle
			Vec3d::DefaultAxisRule = Rules::AXIS_RHS;
			Assertve(Vec3d::DefaultAxisRule == Rules::AXIS_RHS, verbose);
			{ // RHS
				Assertv(Vec3d(0, 0, 0).euler().equals(0.0, 0.0, 0.0), verbose);
				Assertv(Vec3d(5, 0, 0).euler().equals(0.0, degToRad(90.0), 0.0), verbose);
				Assertv(Vec3d(0, 5, 0).euler().equals(0.0, 0.0, degToRad(90.0)), verbose);
				Assertv(Vec3d(0, 0, 5).euler().equals(degToRad(90.0), 0.0, 0.0), verbose);
				Assertv(Vec3d(5, 5, 0).euler().equals(0.0, degToRad(90.0), degToRad(45.0)), verbose);
				Assertv(Vec3d(5, 0, 5).euler().equals(degToRad(90.0), degToRad(45.0), 0.0), verbose);
				Assertv(Vec3d(0, 5, 5).euler().equals(degToRad(45.0), 0.0, degToRad(90.0)), verbose);
				Assertv(Vec3d(5, 5, 5).euler().equals(degToRad(45.0), degToRad(45.0), degToRad(45.0)), verbose);
				Assertv((Vec3d(-5, 0, 0)).euler().equals(0.0, degToRad(-90.0), degToRad(180.0)), verbose);
				Assertv((Vec3d(0, -5, 0)).euler().equals(degToRad(180.0), 0.0, degToRad(-90.0)), verbose);
				Assertv((Vec3d(0, 0, -5)).euler().equals(degToRad(-90.0), degToRad(180.0), 0.0), verbose);
				///
				const Vec3d ref_vec(10, 10, 10);
				Assertv(Vec3d(0, 0, 0).euler(ref_vec).equals(degToRad(-45.0), degToRad(-45.0), degToRad(-45.0)), verbose);
				Assertv(Vec3d(5, 0, 0).euler(ref_vec).equals(degToRad(-45.0), degToRad(45.0), degToRad(-45.0)), verbose);
				Assertv(Vec3d(0, 5, 0).euler(ref_vec).equals(degToRad(-45.0), degToRad(-45.0), degToRad(45.0)), verbose);
				Assertv(Vec3d(0, 0, 5).euler(ref_vec).equals(degToRad(45.0), degToRad(-45.0), degToRad(-45.0)), verbose);
				Assertv(Vec3d(5, 5, 0).euler(ref_vec).equals(degToRad(-45.0), degToRad(45.0), degToRad(0.0)), verbose);
				Assertv(Vec3d(5, 0, 5).euler(ref_vec).equals(degToRad(45.0), degToRad(0.0), degToRad(-45.0)), verbose);
				Assertv(Vec3d(0, 5, 5).euler(ref_vec).equals(degToRad(0.0), degToRad(-45.0), degToRad(45.0)), verbose);
				Assertv(Vec3d(5, 5, 5).euler(ref_vec).equals(degToRad(0.0), degToRad(0.0), degToRad(0.0)), verbose);
				Assertv((Vec3d(-5, 0, 0)).euler(ref_vec).equals(degToRad(-45.0), degToRad(-135.0), degToRad(135.0)), verbose);
				Assertv((Vec3d(0, -5, 0)).euler(ref_vec).equals(degToRad(135.0), degToRad(-45.0), degToRad(-135.0)), verbose);
				Assertv((Vec3d(0, 0, -5)).euler(ref_vec).equals(degToRad(-135.0), degToRad(135.0), degToRad(-45.0)), verbose);
			}
			Vec3d::DefaultAxisRule = Rules::AXIS_LHS;
			Assertve(Vec3d::DefaultAxisRule == Rules::AXIS_LHS, verbose);
			{ // LHS
				Assertv(Vec3d(0, 0, 0).euler().equals(0.0, 0.0, 0.0), verbose);
				Assertv(Vec3d(5, 0, 0).euler().equals(0.0, 0.0, degToRad(90.0)), verbose);
				Assertv(Vec3d(0, 5, 0).euler().equals(degToRad(90.0), 0.0, 0.0), verbose);
				Assertv(Vec3d(0, 0, 5).euler().equals(0.0, degToRad(90.0), 0.0), verbose);
				Assertv(Vec3d(5, 5, 0).euler().equals(degToRad(90.0), 0.0, degToRad(45.0)), verbose);
				Assertv(Vec3d(5, 0, 5).euler().equals(0.0, degToRad(45.0), degToRad(90.0)), verbose);
				Assertv(Vec3d(0, 5, 5).euler().equals(degToRad(45.0), degToRad(90.0), 0.0), verbose);
				Assertv(Vec3d(5, 5, 5).euler().equals(degToRad(45.0), degToRad(45.0), degToRad(45.0)), verbose);
				Assertv((Vec3d(-5, 0, 0)).euler().equals(0.0, degToRad(180.0), degToRad(-90.0)), verbose);
				Assertv((Vec3d(0, -5, 0)).euler().equals(degToRad(-90.0), 0.0, degToRad(180.0)), verbose);
				Assertv((Vec3d(0, 0, -5)).euler().equals(degToRad(180.0), degToRad(-90.0), 0.0), verbose);
				///
				const Vec3d ref_vec(10, 10, 10);
				Assertv(ref_vec.euler().equals(degToRad(45.0), degToRad(45.0), degToRad(45.0)), verbose);
				Assertv(Vec3d(0, 0, 0).euler(ref_vec).equals(degToRad(-45.0), degToRad(-45.0), degToRad(-45.0)), verbose);
				Assertv(Vec3d(5, 0, 0).euler(ref_vec).equals(degToRad(-45.0), degToRad(-45.0), degToRad(45.0)), verbose);
				Assertv(Vec3d(0, 5, 0).euler(ref_vec).equals(degToRad(45.0), degToRad(-45.0), degToRad(-45.0)), verbose);
				Assertv(Vec3d(0, 0, 5).euler(ref_vec).equals(degToRad(-45.0), degToRad(45.0), degToRad(-45.0)), verbose);
				Assertv(Vec3d(5, 5, 0).euler(ref_vec).equals(degToRad(45.0), degToRad(-45.0), degToRad(0.0)), verbose);
				Assertv(Vec3d(5, 0, 5).euler(ref_vec).equals(degToRad(-45.0), degToRad(0.0), degToRad(45.0)), verbose);
				Assertv(Vec3d(0, 5, 5).euler(ref_vec).equals(degToRad(0.0), degToRad(45.0), degToRad(-45.0)), verbose);
				Assertv(Vec3d(5, 5, 5).euler(ref_vec).equals(degToRad(0.0), degToRad(0.0), degToRad(0.0)), verbose);
				Assertv((Vec3d(-5, 0, 0)).euler(ref_vec).equals(degToRad(-45.0), degToRad(135.0), degToRad(-135.0)), verbose);
				Assertv((Vec3d(0, -5, 0)).euler(ref_vec).equals(degToRad(-135.0), degToRad(-45.0), degToRad(135.0)), verbose);
				Assertv((Vec3d(0, 0, -5)).euler(ref_vec).equals(degToRad(135.0), degToRad(-135.0), degToRad(-45.0)), verbose);
			}
		}
	}
	{ // transforms
		{ // scale
			const double scale = 4.5, scale_x = 1.56, scale_y = 0.75, scale_z = -90.0;
			{
				Vec3d vec(5.67, 98.999, 66.9);
				Assertv(vec.equals(5.67, 98.999, 66.9), verbose);
				vec.scale(1.0);
				Assertv(vec.equals(5.67, 98.999, 66.9), verbose);
			}
			{
				Vec3d vec(5.5, 0.0, 0.5);
				Assertv(vec.equals(5.5, 0.0, 0.5), verbose);
				vec.scale(0.0, 2.0, 0.5);
				Assertv(vec.equals(0.0, 0.0, 0.25), verbose);
			}
			{
				Vec3d vec(5.67, 98.999, 66.9);
				Assertv(vec.equals(5.67, 98.999, 66.9), verbose);
				vec.scale(scale);
				Assertv(vec.equals(5.67 * scale, 98.999 * scale, 66.9 * scale), verbose);
			}
			{
				Vec3d vec(5.67, 98.999, 66.9);
				Assertv(vec.equals(5.67, 98.999, 66.9), verbose);
				vec.scale(scale_x, scale_y, scale_z);
				Assertv(vec.equals(5.67 * scale_x, 98.999 * scale_y, 66.9 * scale_z), verbose);
			}
		}
		{ // scaled
			const double scale = 4.5, scale_x = 1.56, scale_y = 0.75, scale_z = -90.0;
			{
				const Vec3d vec(5.67, 98.999, 66.9);
				Assertv(vec.equals(5.67, 98.999, 66.9), verbose);
				Assertv(vec.scaled(1.0).equals(5.67, 98.999, 66.9), verbose);
			}
			{
				const Vec3d vec(5.5, 0.0, 0.5);
				Assertv(vec.equals(5.5, 0.0, 0.5), verbose);
				Assertv(vec.scaled(0.0, 2.0, 0.5).equals(0.0, 0.0, 0.25), verbose);
			}
			{
				const Vec3d vec(5.67, 98.999, 66.9);
				Assertv(vec.equals(5.67, 98.999, 66.9), verbose);
				Assertv(vec.scaled(scale).equals(5.67 * scale, 98.999 * scale, 66.9 * scale), verbose);
			}
			{
				const Vec3d vec(5.67, 98.999, 66.9);
				Assertv(vec.equals(5.67, 98.999, 66.9), verbose);
				Assertv(vec.scaled(scale_x, scale_y, scale_z).equals(5.67 * scale_x, 98.999 * scale_y, 66.9 * scale_z), verbose);
			}
		}
		{ // translate
			{ // Vec3d
				const Vec3d delta(4.5, -900.3434, -44.66);
				Vec3d vec(5.67, 98.999, -120.04);
				Assertv(vec.equals(5.67, 98.999, -120.04), verbose);
				vec.translate(delta);
				Assertv(vec.equals(5.67 + delta.x, 98.999 + delta.y, -120.04 + delta.z), verbose);
			}
			{ // values
				const double delta_x = 4.5, delta_y = -900.3434, delta_z = -44.66;
				Vec3d vec(5.67, 98.999, -120.04);
				Assertv(vec.equals(5.67, 98.999, -120.04), verbose);
				vec.translate(delta_x, delta_y, delta_z);
				Assertv(vec.equals(5.67 + delta_x, 98.999 + delta_y, -120.04 + delta_z), verbose);
			}
		}
		{ // translated
			{ // Vec3d
				const Vec3d delta(4.5, -900.3434, -44.66);
				const Vec3d vec(5.67, 98.999, -120.04);
				Assertv(vec.equals(5.67, 98.999, -120.04), verbose);
				Vec3d tvec = vec.translated(delta);
				Assertv(tvec.equals(vec.x + delta.x, vec.y + delta.y, vec.z + delta.z), verbose);
			}
			{ // values
				const double delta_x = 4.5, delta_y = -900.3434, delta_z = -44.66;
				const Vec3d vec(5.67, 98.999, -120.04);
				Assertv(vec.equals(5.67, 98.999, -120.04), verbose);
				Vec3d tvec = vec.translated(delta_x, delta_y, delta_z);
				Assertv(tvec.equals(vec.x + delta_x, vec.y + delta_y, vec.z + delta_z), verbose);
			}
		}
		{ // rotate
			{ // RHS
				Vec3d::DefaultAxisRule = Rules::AXIS_RHS;
				Assertve(Vec3d::DefaultAxisRule == Rules::AXIS_RHS, verbose);
				Assertv(Vec3d(5, 5, 5).rotate(degToRad(0.0), degToRad(0.0), degToRad(0.0)).equals(5, 5, 5), verbose);
				Assertv(Vec3d(5, 0, 0).rotate(degToRad(90.0), degToRad(0.0), degToRad(0.0)).equals(5, 0, 0), verbose);
				Assertv(Vec3d(5, 0, 0).rotate(degToRad(0.0), degToRad(90.0), degToRad(0.0)).equals(0, 0, -5), verbose);
				Assertv(Vec3d(5, 0, 0).rotate(degToRad(0.0), degToRad(0.0), degToRad(90.0)).equals(0, 5, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotate(degToRad(90.0), degToRad(0.0), degToRad(0.0)).equals(0, 0, 5), verbose);
				Assertv(Vec3d(0, 5, 0).rotate(degToRad(0.0), degToRad(90.0), degToRad(0.0)).equals(0, 5, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotate(degToRad(0.0), degToRad(0.0), degToRad(90.0)).equals(-5, 0, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotate(degToRad(90.0), degToRad(0.0), degToRad(0.0)).equals(0, -5, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotate(degToRad(0.0), degToRad(90.0), degToRad(0.0)).equals(5, 0, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotate(degToRad(0.0), degToRad(0.0), degToRad(90.0)).equals(0, 0, 5), verbose);
				Assertv(Vec3d(5, 0, 0).rotate(degToRad(-90.0), degToRad(0.0), degToRad(0.0)).equals(5, 0, 0), verbose);
				Assertv(Vec3d(5, 0, 0).rotate(degToRad(0.0), degToRad(-90.0), degToRad(0.0)).equals(0, 0, 5), verbose);
				Assertv(Vec3d(5, 0, 0).rotate(degToRad(0.0), degToRad(0.0), degToRad(-90.0)).equals(0, -5, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotate(degToRad(-90.0), degToRad(0.0), degToRad(0.0)).equals(0, 0, -5), verbose);
				Assertv(Vec3d(0, 5, 0).rotate(degToRad(0.0), degToRad(-90.0), degToRad(0.0)).equals(0, 5, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotate(degToRad(0.0), degToRad(0.0), degToRad(-90.0)).equals(5, 0, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotate(degToRad(-90.0), degToRad(0.0), degToRad(0.0)).equals(0, 5, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotate(degToRad(0.0), degToRad(-90.0), degToRad(0.0)).equals(-5, 0, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotate(degToRad(0.0), degToRad(0.0), degToRad(-90.0)).equals(0, 0, 5), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotate(degToRad(45.0), degToRad(0.0), degToRad(0.0)).equals(sq2, 1, 1), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotate(degToRad(-45.0), degToRad(0.0), degToRad(0.0)).equals(sq2, 1, -1), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotate(degToRad(0.0), degToRad(45.0), degToRad(0.0)).equals(1, sq2, -1), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotate(degToRad(0.0), degToRad(-45.0), degToRad(0.0)).equals(1, sq2, 1), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotate(degToRad(0.0), degToRad(0.0), degToRad(45.0)).equals(0, 2, 0), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotate(degToRad(0.0), degToRad(0.0), degToRad(-45.0)).equals(2, 0, 0), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotate(degToRad(45.0), degToRad(0.0), degToRad(0.0)).equals(sq2, -1, 1), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotate(degToRad(-45.0), degToRad(0.0), degToRad(0.0)).equals(sq2, 1, 1), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotate(degToRad(0.0), degToRad(45.0), degToRad(0.0)).equals(2, 0, 0), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotate(degToRad(0.0), degToRad(-45.0), degToRad(0.0)).equals(0, 0, 2), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotate(degToRad(0.0), degToRad(0.0), degToRad(45.0)).equals(1, 1, sq2), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotate(degToRad(0.0), degToRad(0.0), degToRad(-45.0)).equals(1, -1, sq2), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotate(degToRad(45.0), degToRad(0.0), degToRad(0.0)).equals(0, 0, 2), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotate(degToRad(-45.0), degToRad(0.0), degToRad(0.0)).equals(0, 2, 0), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotate(degToRad(0.0), degToRad(45.0), degToRad(0.0)).equals(1, sq2, 1), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotate(degToRad(0.0), degToRad(-45.0), degToRad(0.0)).equals(-1, sq2, 1), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotate(degToRad(0.0), degToRad(0.0), degToRad(45.0)).equals(-1, 1, sq2), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotate(degToRad(0.0), degToRad(0.0), degToRad(-45.0)).equals(1, 1, sq2), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotate(degToRad(45.0), degToRad(0.0), degToRad(0.0)).equals(sq2, 0, 2), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotate(degToRad(-45.0), degToRad(0.0), degToRad(0.0)).equals(sq2, 2, 0), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotate(degToRad(0.0), degToRad(45.0), degToRad(0.0)).equals(2, sq2, 0), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotate(degToRad(0.0), degToRad(-45.0), degToRad(0.0)).equals(0, sq2, 2), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotate(degToRad(0.0), degToRad(0.0), degToRad(45.0)).equals(0, 2, sq2), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotate(degToRad(0.0), degToRad(0.0), degToRad(-45.0)).equals(2, 0, sq2), verbose);
			}
			{ // LHS
				Vec3d::DefaultAxisRule = Rules::AXIS_LHS;
				Assertve(Vec3d::DefaultAxisRule == Rules::AXIS_LHS, verbose);
				Assertv(Vec3d(5, 5, 5).rotate(degToRad(0.0), degToRad(0.0), degToRad(0.0)).equals(5, 5, 5), verbose);
				Assertv(Vec3d(5, 0, 0).rotate(degToRad(90.0), degToRad(0.0), degToRad(0.0)).equals(5, 0, 0), verbose);
				Assertv(Vec3d(5, 0, 0).rotate(degToRad(0.0), degToRad(90.0), degToRad(0.0)).equals(0, 0, 5), verbose);
				Assertv(Vec3d(5, 0, 0).rotate(degToRad(0.0), degToRad(0.0), degToRad(90.0)).equals(0, -5, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotate(degToRad(90.0), degToRad(0.0), degToRad(0.0)).equals(0, 0, -5), verbose);
				Assertv(Vec3d(0, 5, 0).rotate(degToRad(0.0), degToRad(90.0), degToRad(0.0)).equals(0, 5, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotate(degToRad(0.0), degToRad(0.0), degToRad(90.0)).equals(5, 0, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotate(degToRad(90.0), degToRad(0.0), degToRad(0.0)).equals(0, 5, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotate(degToRad(0.0), degToRad(90.0), degToRad(0.0)).equals(-5, 0, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotate(degToRad(0.0), degToRad(0.0), degToRad(90.0)).equals(0, 0, 5), verbose);
				Assertv(Vec3d(5, 0, 0).rotate(degToRad(-90.0), degToRad(0.0), degToRad(0.0)).equals(5, 0, 0), verbose);
				Assertv(Vec3d(5, 0, 0).rotate(degToRad(0.0), degToRad(-90.0), degToRad(0.0)).equals(0, 0, -5), verbose);
				Assertv(Vec3d(5, 0, 0).rotate(degToRad(0.0), degToRad(0.0), degToRad(-90.0)).equals(0, 5, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotate(degToRad(-90.0), degToRad(0.0), degToRad(0.0)).equals(0, 0, 5), verbose);
				Assertv(Vec3d(0, 5, 0).rotate(degToRad(0.0), degToRad(-90.0), degToRad(0.0)).equals(0, 5, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotate(degToRad(0.0), degToRad(0.0), degToRad(-90.0)).equals(-5, 0, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotate(degToRad(-90.0), degToRad(0.0), degToRad(0.0)).equals(0, -5, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotate(degToRad(0.0), degToRad(-90.0), degToRad(0.0)).equals(5, 0, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotate(degToRad(0.0), degToRad(0.0), degToRad(-90.0)).equals(0, 0, 5), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotate(degToRad(45.0), degToRad(0.0), degToRad(0.0)).equals(sq2, 1, -1), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotate(degToRad(-45.0), degToRad(0.0), degToRad(0.0)).equals(sq2, 1, 1), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotate(degToRad(0.0), degToRad(45.0), degToRad(0.0)).equals(1, sq2, 1), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotate(degToRad(0.0), degToRad(-45.0), degToRad(0.0)).equals(1, sq2, -1), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotate(degToRad(0.0), degToRad(0.0), degToRad(45.0)).equals(2, 0, 0), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotate(degToRad(0.0), degToRad(0.0), degToRad(-45.0)).equals(0, 2, 0), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotate(degToRad(45.0), degToRad(0.0), degToRad(0.0)).equals(sq2, 1, 1), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotate(degToRad(-45.0), degToRad(0.0), degToRad(0.0)).equals(sq2, -1, 1), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotate(degToRad(0.0), degToRad(45.0), degToRad(0.0)).equals(0, 0, 2), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotate(degToRad(0.0), degToRad(-45.0), degToRad(0.0)).equals(2, 0, 0), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotate(degToRad(0.0), degToRad(0.0), degToRad(45.0)).equals(1, -1, sq2), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotate(degToRad(0.0), degToRad(0.0), degToRad(-45.0)).equals(1, 1, sq2), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotate(degToRad(45.0), degToRad(0.0), degToRad(0.0)).equals(0, 2, 0), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotate(degToRad(-45.0), degToRad(0.0), degToRad(0.0)).equals(0, 0, 2), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotate(degToRad(0.0), degToRad(45.0), degToRad(0.0)).equals(-1, sq2, 1), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotate(degToRad(0.0), degToRad(-45.0), degToRad(0.0)).equals(1, sq2, 1), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotate(degToRad(0.0), degToRad(0.0), degToRad(45.0)).equals(1, 1, sq2), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotate(degToRad(0.0), degToRad(0.0), degToRad(-45.0)).equals(-1, 1, sq2), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotate(degToRad(45.0), degToRad(0.0), degToRad(0.0)).equals(sq2, 2, 0), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotate(degToRad(-45.0), degToRad(0.0), degToRad(0.0)).equals(sq2, 0, 2), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotate(degToRad(0.0), degToRad(45.0), degToRad(0.0)).equals(0, sq2, 2), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotate(degToRad(0.0), degToRad(-45.0), degToRad(0.0)).equals(2, sq2, 0), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotate(degToRad(0.0), degToRad(0.0), degToRad(45.0)).equals(2, 0, sq2), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotate(degToRad(0.0), degToRad(0.0), degToRad(-45.0)).equals(0, 2, sq2), verbose);
			}
		}
		{ // rotate - angle_vec
			{ // RHS
				Vec3d::DefaultAxisRule = Rules::AXIS_RHS;
				Assertve(Vec3d::DefaultAxisRule == Rules::AXIS_RHS, verbose);
				Assertv(Vec3d(5, 5, 5).rotate(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(0.0))).equals(5, 5, 5), verbose);
				Assertv(Vec3d(5, 0, 0).rotate(Vec3d(degToRad(90.0), degToRad(0.0), degToRad(0.0))).equals(5, 0, 0), verbose);
				Assertv(Vec3d(5, 0, 0).rotate(Vec3d(degToRad(0.0), degToRad(90.0), degToRad(0.0))).equals(0, 0, -5), verbose);
				Assertv(Vec3d(5, 0, 0).rotate(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(90.0))).equals(0, 5, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotate(Vec3d(degToRad(90.0), degToRad(0.0), degToRad(0.0))).equals(0, 0, 5), verbose);
				Assertv(Vec3d(0, 5, 0).rotate(Vec3d(degToRad(0.0), degToRad(90.0), degToRad(0.0))).equals(0, 5, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotate(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(90.0))).equals(-5, 0, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotate(Vec3d(degToRad(90.0), degToRad(0.0), degToRad(0.0))).equals(0, -5, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotate(Vec3d(degToRad(0.0), degToRad(90.0), degToRad(0.0))).equals(5, 0, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotate(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(90.0))).equals(0, 0, 5), verbose);
				Assertv(Vec3d(5, 0, 0).rotate(Vec3d(degToRad(-90.0), degToRad(0.0), degToRad(0.0))).equals(5, 0, 0), verbose);
				Assertv(Vec3d(5, 0, 0).rotate(Vec3d(degToRad(0.0), degToRad(-90.0), degToRad(0.0))).equals(0, 0, 5), verbose);
				Assertv(Vec3d(5, 0, 0).rotate(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(-90.0))).equals(0, -5, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotate(Vec3d(degToRad(-90.0), degToRad(0.0), degToRad(0.0))).equals(0, 0, -5), verbose);
				Assertv(Vec3d(0, 5, 0).rotate(Vec3d(degToRad(0.0), degToRad(-90.0), degToRad(0.0))).equals(0, 5, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotate(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(-90.0))).equals(5, 0, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotate(Vec3d(degToRad(-90.0), degToRad(0.0), degToRad(0.0))).equals(0, 5, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotate(Vec3d(degToRad(0.0), degToRad(-90.0), degToRad(0.0))).equals(-5, 0, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotate(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(-90.0))).equals(0, 0, 5), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotate(Vec3d(degToRad(45.0), degToRad(0.0), degToRad(0.0))).equals(sq2, 1, 1), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotate(Vec3d(degToRad(-45.0), degToRad(0.0), degToRad(0.0))).equals(sq2, 1, -1), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotate(Vec3d(degToRad(0.0), degToRad(45.0), degToRad(0.0))).equals(1, sq2, -1), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotate(Vec3d(degToRad(0.0), degToRad(-45.0), degToRad(0.0))).equals(1, sq2, 1), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotate(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(45.0))).equals(0, 2, 0), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotate(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(-45.0))).equals(2, 0, 0), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotate(Vec3d(degToRad(45.0), degToRad(0.0), degToRad(0.0))).equals(sq2, -1, 1), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotate(Vec3d(degToRad(-45.0), degToRad(0.0), degToRad(0.0))).equals(sq2, 1, 1), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotate(Vec3d(degToRad(0.0), degToRad(45.0), degToRad(0.0))).equals(2, 0, 0), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotate(Vec3d(degToRad(0.0), degToRad(-45.0), degToRad(0.0))).equals(0, 0, 2), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotate(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(45.0))).equals(1, 1, sq2), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotate(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(-45.0))).equals(1, -1, sq2), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotate(Vec3d(degToRad(45.0), degToRad(0.0), degToRad(0.0))).equals(0, 0, 2), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotate(Vec3d(degToRad(-45.0), degToRad(0.0), degToRad(0.0))).equals(0, 2, 0), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotate(Vec3d(degToRad(0.0), degToRad(45.0), degToRad(0.0))).equals(1, sq2, 1), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotate(Vec3d(degToRad(0.0), degToRad(-45.0), degToRad(0.0))).equals(-1, sq2, 1), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotate(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(45.0))).equals(-1, 1, sq2), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotate(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(-45.0))).equals(1, 1, sq2), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotate(Vec3d(degToRad(45.0), degToRad(0.0), degToRad(0.0))).equals(sq2, 0, 2), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotate(Vec3d(degToRad(-45.0), degToRad(0.0), degToRad(0.0))).equals(sq2, 2, 0), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotate(Vec3d(degToRad(0.0), degToRad(45.0), degToRad(0.0))).equals(2, sq2, 0), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotate(Vec3d(degToRad(0.0), degToRad(-45.0), degToRad(0.0))).equals(0, sq2, 2), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotate(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(45.0))).equals(0, 2, sq2), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotate(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(-45.0))).equals(2, 0, sq2), verbose);
			}
			{ // LHS
				Vec3d::DefaultAxisRule = Rules::AXIS_LHS;
				Assertve(Vec3d::DefaultAxisRule == Rules::AXIS_LHS, verbose);
				Assertv(Vec3d(5, 5, 5).rotate(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(0.0))).equals(5, 5, 5), verbose);
				Assertv(Vec3d(5, 0, 0).rotate(Vec3d(degToRad(90.0), degToRad(0.0), degToRad(0.0))).equals(5, 0, 0), verbose);
				Assertv(Vec3d(5, 0, 0).rotate(Vec3d(degToRad(0.0), degToRad(90.0), degToRad(0.0))).equals(0, 0, 5), verbose);
				Assertv(Vec3d(5, 0, 0).rotate(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(90.0))).equals(0, -5, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotate(Vec3d(degToRad(90.0), degToRad(0.0), degToRad(0.0))).equals(0, 0, -5), verbose);
				Assertv(Vec3d(0, 5, 0).rotate(Vec3d(degToRad(0.0), degToRad(90.0), degToRad(0.0))).equals(0, 5, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotate(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(90.0))).equals(5, 0, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotate(Vec3d(degToRad(90.0), degToRad(0.0), degToRad(0.0))).equals(0, 5, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotate(Vec3d(degToRad(0.0), degToRad(90.0), degToRad(0.0))).equals(-5, 0, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotate(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(90.0))).equals(0, 0, 5), verbose);
				Assertv(Vec3d(5, 0, 0).rotate(Vec3d(degToRad(-90.0), degToRad(0.0), degToRad(0.0))).equals(5, 0, 0), verbose);
				Assertv(Vec3d(5, 0, 0).rotate(Vec3d(degToRad(0.0), degToRad(-90.0), degToRad(0.0))).equals(0, 0, -5), verbose);
				Assertv(Vec3d(5, 0, 0).rotate(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(-90.0))).equals(0, 5, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotate(Vec3d(degToRad(-90.0), degToRad(0.0), degToRad(0.0))).equals(0, 0, 5), verbose);
				Assertv(Vec3d(0, 5, 0).rotate(Vec3d(degToRad(0.0), degToRad(-90.0), degToRad(0.0))).equals(0, 5, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotate(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(-90.0))).equals(-5, 0, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotate(Vec3d(degToRad(-90.0), degToRad(0.0), degToRad(0.0))).equals(0, -5, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotate(Vec3d(degToRad(0.0), degToRad(-90.0), degToRad(0.0))).equals(5, 0, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotate(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(-90.0))).equals(0, 0, 5), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotate(Vec3d(degToRad(45.0), degToRad(0.0), degToRad(0.0))).equals(sq2, 1, -1), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotate(Vec3d(degToRad(-45.0), degToRad(0.0), degToRad(0.0))).equals(sq2, 1, 1), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotate(Vec3d(degToRad(0.0), degToRad(45.0), degToRad(0.0))).equals(1, sq2, 1), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotate(Vec3d(degToRad(0.0), degToRad(-45.0), degToRad(0.0))).equals(1, sq2, -1), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotate(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(45.0))).equals(2, 0, 0), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotate(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(-45.0))).equals(0, 2, 0), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotate(Vec3d(degToRad(45.0), degToRad(0.0), degToRad(0.0))).equals(sq2, 1, 1), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotate(Vec3d(degToRad(-45.0), degToRad(0.0), degToRad(0.0))).equals(sq2, -1, 1), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotate(Vec3d(degToRad(0.0), degToRad(45.0), degToRad(0.0))).equals(0, 0, 2), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotate(Vec3d(degToRad(0.0), degToRad(-45.0), degToRad(0.0))).equals(2, 0, 0), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotate(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(45.0))).equals(1, -1, sq2), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotate(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(-45.0))).equals(1, 1, sq2), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotate(Vec3d(degToRad(45.0), degToRad(0.0), degToRad(0.0))).equals(0, 2, 0), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotate(Vec3d(degToRad(-45.0), degToRad(0.0), degToRad(0.0))).equals(0, 0, 2), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotate(Vec3d(degToRad(0.0), degToRad(45.0), degToRad(0.0))).equals(-1, sq2, 1), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotate(Vec3d(degToRad(0.0), degToRad(-45.0), degToRad(0.0))).equals(1, sq2, 1), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotate(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(45.0))).equals(1, 1, sq2), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotate(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(-45.0))).equals(-1, 1, sq2), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotate(Vec3d(degToRad(45.0), degToRad(0.0), degToRad(0.0))).equals(sq2, 2, 0), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotate(Vec3d(degToRad(-45.0), degToRad(0.0), degToRad(0.0))).equals(sq2, 0, 2), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotate(Vec3d(degToRad(0.0), degToRad(45.0), degToRad(0.0))).equals(0, sq2, 2), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotate(Vec3d(degToRad(0.0), degToRad(-45.0), degToRad(0.0))).equals(2, sq2, 0), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotate(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(45.0))).equals(2, 0, sq2), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotate(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(-45.0))).equals(0, 2, sq2), verbose);
			}
		}
		{ // rotateX
			{ // RHS
				Vec3d::DefaultAxisRule = Rules::AXIS_RHS;
				Assertve(Vec3d::DefaultAxisRule == Rules::AXIS_RHS, verbose);
				Assertv(Vec3d(5, 5, 5).rotateX(degToRad(0.0)).equals(5, 5, 5), verbose);
				Assertv(Vec3d(5, 0, 0).rotateX(degToRad(90.0)).equals(5, 0, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotateX(degToRad(90.0)).equals(0, 0, 5), verbose);
				Assertv(Vec3d(0, 0, 5).rotateX(degToRad(90.0)).equals(0, -5, 0), verbose);
				Assertv(Vec3d(5, 0, 0).rotateX(degToRad(-90.0)).equals(5, 0, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotateX(degToRad(-90.0)).equals(0, 0, -5), verbose);
				Assertv(Vec3d(0, 0, 5).rotateX(degToRad(-90.0)).equals(0, 5, 0), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotateX(degToRad(45.0)).equals(sq2, 1, 1), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotateX(degToRad(-45.0)).equals(sq2, 1, -1), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotateX(degToRad(45.0)).equals(sq2, -1, 1), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotateX(degToRad(-45.0)).equals(sq2, 1, 1), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotateX(degToRad(45.0)).equals(0, 0, 2), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotateX(degToRad(-45.0)).equals(0, 2, 0), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotateX(degToRad(45.0)).equals(sq2, 0, 2), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotateX(degToRad(-45.0)).equals(sq2, 2, 0), verbose);
			}
			{ // LHS
				Vec3d::DefaultAxisRule = Rules::AXIS_LHS;
				Assertve(Vec3d::DefaultAxisRule == Rules::AXIS_LHS, verbose);
				Assertv(Vec3d(5, 5, 5).rotateX(degToRad(0.0)).equals(5, 5, 5), verbose);
				Assertv(Vec3d(5, 0, 0).rotateX(degToRad(90.0)).equals(5, 0, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotateX(degToRad(90.0)).equals(0, 0, -5), verbose);
				Assertv(Vec3d(0, 0, 5).rotateX(degToRad(90.0)).equals(0, 5, 0), verbose);
				Assertv(Vec3d(5, 0, 0).rotateX(degToRad(-90.0)).equals(5, 0, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotateX(degToRad(-90.0)).equals(0, 0, 5), verbose);
				Assertv(Vec3d(0, 0, 5).rotateX(degToRad(-90.0)).equals(0, -5, 0), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotateX(degToRad(45.0)).equals(sq2, 1, -1), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotateX(degToRad(-45.0)).equals(sq2, 1, 1), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotateX(degToRad(45.0)).equals(sq2, 1, 1), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotateX(degToRad(-45.0)).equals(sq2, -1, 1), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotateX(degToRad(45.0)).equals(0, 2, 0), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotateX(degToRad(-45.0)).equals(0, 0, 2), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotateX(degToRad(45.0)).equals(sq2, 2, 0), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotateX(degToRad(-45.0)).equals(sq2, 0, 2), verbose);
			}
		}
		{ // rotateY
			{ // RHS
				Vec3d::DefaultAxisRule = Rules::AXIS_RHS;
				Assertve(Vec3d::DefaultAxisRule == Rules::AXIS_RHS, verbose);
				Assertv(Vec3d(5, 5, 5).rotateY(degToRad(0.0)).equals(5, 5, 5), verbose);
				Assertv(Vec3d(5, 0, 0).rotateY(degToRad(90.0)).equals(0, 0, -5), verbose);
				Assertv(Vec3d(0, 5, 0).rotateY(degToRad(90.0)).equals(0, 5, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotateY(degToRad(90.0)).equals(5, 0, 0), verbose);
				Assertv(Vec3d(5, 0, 0).rotateY(degToRad(-90.0)).equals(0, 0, 5), verbose);
				Assertv(Vec3d(0, 5, 0).rotateY(degToRad(-90.0)).equals(0, 5, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotateY(degToRad(-90.0)).equals(-5, 0, 0), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotateY(degToRad(45.0)).equals(1, sq2, -1), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotateY(degToRad(-45.0)).equals(1, sq2, 1), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotateY(degToRad(45.0)).equals(2, 0, 0), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotateY(degToRad(-45.0)).equals(0, 0, 2), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotateY(degToRad(45.0)).equals(1, sq2, 1), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotateY(degToRad(-45.0)).equals(-1, sq2, 1), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotateY(degToRad(45.0)).equals(2, sq2, 0), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotateY(degToRad(-45.0)).equals(0, sq2, 2), verbose);
			}
			{ // LHS
				Vec3d::DefaultAxisRule = Rules::AXIS_LHS;
				Assertve(Vec3d::DefaultAxisRule == Rules::AXIS_LHS, verbose);
				Assertv(Vec3d(5, 5, 5).rotateY(degToRad(0.0)).equals(5, 5, 5), verbose);
				Assertv(Vec3d(5, 0, 0).rotateY(degToRad(90.0)).equals(0, 0, 5), verbose);
				Assertv(Vec3d(0, 5, 0).rotateY(degToRad(90.0)).equals(0, 5, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotateY(degToRad(90.0)).equals(-5, 0, 0), verbose);
				Assertv(Vec3d(5, 0, 0).rotateY(degToRad(-90.0)).equals(0, 0, -5), verbose);
				Assertv(Vec3d(0, 5, 0).rotateY(degToRad(-90.0)).equals(0, 5, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotateY(degToRad(-90.0)).equals(5, 0, 0), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotateY(degToRad(45.0)).equals(1, sq2, 1), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotateY(degToRad(-45.0)).equals(1, sq2, -1), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotateY(degToRad(45.0)).equals(0, 0, 2), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotateY(degToRad(-45.0)).equals(2, 0, 0), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotateY(degToRad(45.0)).equals(-1, sq2, 1), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotateY(degToRad(-45.0)).equals(1, sq2, 1), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotateY(degToRad(45.0)).equals(0, sq2, 2), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotateY(degToRad(-45.0)).equals(2, sq2, 0), verbose);
			}
		}
		{ // rotateZ
			{ // RHS
				Vec3d::DefaultAxisRule = Rules::AXIS_RHS;
				Assertve(Vec3d::DefaultAxisRule == Rules::AXIS_RHS, verbose);
				Assertv(Vec3d(5, 5, 5).rotateZ(degToRad(0.0)).equals(5, 5, 5), verbose);
				Assertv(Vec3d(5, 0, 0).rotateZ(degToRad(90.0)).equals(0, 5, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotateZ(degToRad(90.0)).equals(-5, 0, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotateZ(degToRad(90.0)).equals(0, 0, 5), verbose);
				Assertv(Vec3d(5, 0, 0).rotateZ(degToRad(-90.0)).equals(0, -5, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotateZ(degToRad(-90.0)).equals(5, 0, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotateZ(degToRad(-90.0)).equals(0, 0, 5), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotateZ(degToRad(45.0)).equals(0, 2, 0), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotateZ(degToRad(-45.0)).equals(2, 0, 0), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotateZ(degToRad(45.0)).equals(1, 1, sq2), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotateZ(degToRad(-45.0)).equals(1, -1, sq2), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotateZ(degToRad(45.0)).equals(-1, 1, sq2), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotateZ(degToRad(-45.0)).equals(1, 1, sq2), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotateZ(degToRad(45.0)).equals(0, 2, sq2), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotateZ(degToRad(-45.0)).equals(2, 0, sq2), verbose);
			}
			{ // LHS
				Vec3d::DefaultAxisRule = Rules::AXIS_LHS;
				Assertve(Vec3d::DefaultAxisRule == Rules::AXIS_LHS, verbose);
				Assertv(Vec3d(5, 5, 5).rotateZ(degToRad(0.0)).equals(5, 5, 5), verbose);
				Assertv(Vec3d(5, 0, 0).rotateZ(degToRad(90.0)).equals(0, -5, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotateZ(degToRad(90.0)).equals(5, 0, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotateZ(degToRad(90.0)).equals(0, 0, 5), verbose);
				Assertv(Vec3d(5, 0, 0).rotateZ(degToRad(-90.0)).equals(0, 5, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotateZ(degToRad(-90.0)).equals(-5, 0, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotateZ(degToRad(-90.0)).equals(0, 0, 5), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotateZ(degToRad(45.0)).equals(2, 0, 0), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotateZ(degToRad(-45.0)).equals(0, 2, 0), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotateZ(degToRad(45.0)).equals(1, -1, sq2), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotateZ(degToRad(-45.0)).equals(1, 1, sq2), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotateZ(degToRad(45.0)).equals(1, 1, sq2), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotateZ(degToRad(-45.0)).equals(-1, 1, sq2), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotateZ(degToRad(45.0)).equals(2, 0, sq2), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotateZ(degToRad(-45.0)).equals(0, 2, sq2), verbose);
			}
		}
		{ // rotated
			{ // RHS
				Vec3d::DefaultAxisRule = Rules::AXIS_RHS;
				Assertve(Vec3d::DefaultAxisRule == Rules::AXIS_RHS, verbose);
				Assertv(Vec3d(5, 5, 5).rotated(degToRad(0.0), degToRad(0.0), degToRad(0.0)).equals(5, 5, 5), verbose);
				Assertv(Vec3d(5, 0, 0).rotated(degToRad(90.0), degToRad(0.0), degToRad(0.0)).equals(5, 0, 0), verbose);
				Assertv(Vec3d(5, 0, 0).rotated(degToRad(0.0), degToRad(90.0), degToRad(0.0)).equals(0, 0, -5), verbose);
				Assertv(Vec3d(5, 0, 0).rotated(degToRad(0.0), degToRad(0.0), degToRad(90.0)).equals(0, 5, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotated(degToRad(90.0), degToRad(0.0), degToRad(0.0)).equals(0, 0, 5), verbose);
				Assertv(Vec3d(0, 5, 0).rotated(degToRad(0.0), degToRad(90.0), degToRad(0.0)).equals(0, 5, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotated(degToRad(0.0), degToRad(0.0), degToRad(90.0)).equals(-5, 0, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotated(degToRad(90.0), degToRad(0.0), degToRad(0.0)).equals(0, -5, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotated(degToRad(0.0), degToRad(90.0), degToRad(0.0)).equals(5, 0, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotated(degToRad(0.0), degToRad(0.0), degToRad(90.0)).equals(0, 0, 5), verbose);
				Assertv(Vec3d(5, 0, 0).rotated(degToRad(-90.0), degToRad(0.0), degToRad(0.0)).equals(5, 0, 0), verbose);
				Assertv(Vec3d(5, 0, 0).rotated(degToRad(0.0), degToRad(-90.0), degToRad(0.0)).equals(0, 0, 5), verbose);
				Assertv(Vec3d(5, 0, 0).rotated(degToRad(0.0), degToRad(0.0), degToRad(-90.0)).equals(0, -5, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotated(degToRad(-90.0), degToRad(0.0), degToRad(0.0)).equals(0, 0, -5), verbose);
				Assertv(Vec3d(0, 5, 0).rotated(degToRad(0.0), degToRad(-90.0), degToRad(0.0)).equals(0, 5, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotated(degToRad(0.0), degToRad(0.0), degToRad(-90.0)).equals(5, 0, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotated(degToRad(-90.0), degToRad(0.0), degToRad(0.0)).equals(0, 5, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotated(degToRad(0.0), degToRad(-90.0), degToRad(0.0)).equals(-5, 0, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotated(degToRad(0.0), degToRad(0.0), degToRad(-90.0)).equals(0, 0, 5), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotated(degToRad(45.0), degToRad(0.0), degToRad(0.0)).equals(sq2, 1, 1), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotated(degToRad(-45.0), degToRad(0.0), degToRad(0.0)).equals(sq2, 1, -1), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotated(degToRad(0.0), degToRad(45.0), degToRad(0.0)).equals(1, sq2, -1), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotated(degToRad(0.0), degToRad(-45.0), degToRad(0.0)).equals(1, sq2, 1), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotated(degToRad(0.0), degToRad(0.0), degToRad(45.0)).equals(0, 2, 0), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotated(degToRad(0.0), degToRad(0.0), degToRad(-45.0)).equals(2, 0, 0), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotated(degToRad(45.0), degToRad(0.0), degToRad(0.0)).equals(sq2, -1, 1), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotated(degToRad(-45.0), degToRad(0.0), degToRad(0.0)).equals(sq2, 1, 1), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotated(degToRad(0.0), degToRad(45.0), degToRad(0.0)).equals(2, 0, 0), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotated(degToRad(0.0), degToRad(-45.0), degToRad(0.0)).equals(0, 0, 2), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotated(degToRad(0.0), degToRad(0.0), degToRad(45.0)).equals(1, 1, sq2), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotated(degToRad(0.0), degToRad(0.0), degToRad(-45.0)).equals(1, -1, sq2), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotated(degToRad(45.0), degToRad(0.0), degToRad(0.0)).equals(0, 0, 2), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotated(degToRad(-45.0), degToRad(0.0), degToRad(0.0)).equals(0, 2, 0), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotated(degToRad(0.0), degToRad(45.0), degToRad(0.0)).equals(1, sq2, 1), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotated(degToRad(0.0), degToRad(-45.0), degToRad(0.0)).equals(-1, sq2, 1), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotated(degToRad(0.0), degToRad(0.0), degToRad(45.0)).equals(-1, 1, sq2), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotated(degToRad(0.0), degToRad(0.0), degToRad(-45.0)).equals(1, 1, sq2), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotated(degToRad(45.0), degToRad(0.0), degToRad(0.0)).equals(sq2, 0, 2), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotated(degToRad(-45.0), degToRad(0.0), degToRad(0.0)).equals(sq2, 2, 0), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotated(degToRad(0.0), degToRad(45.0), degToRad(0.0)).equals(2, sq2, 0), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotated(degToRad(0.0), degToRad(-45.0), degToRad(0.0)).equals(0, sq2, 2), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotated(degToRad(0.0), degToRad(0.0), degToRad(45.0)).equals(0, 2, sq2), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotated(degToRad(0.0), degToRad(0.0), degToRad(-45.0)).equals(2, 0, sq2), verbose);
			}
			{ // LHS
				Vec3d::DefaultAxisRule = Rules::AXIS_LHS;
				Assertve(Vec3d::DefaultAxisRule == Rules::AXIS_LHS, verbose);
				Assertv(Vec3d(5, 5, 5).rotated(degToRad(0.0), degToRad(0.0), degToRad(0.0)).equals(5, 5, 5), verbose);
				Assertv(Vec3d(5, 0, 0).rotated(degToRad(90.0), degToRad(0.0), degToRad(0.0)).equals(5, 0, 0), verbose);
				Assertv(Vec3d(5, 0, 0).rotated(degToRad(0.0), degToRad(90.0), degToRad(0.0)).equals(0, 0, 5), verbose);
				Assertv(Vec3d(5, 0, 0).rotated(degToRad(0.0), degToRad(0.0), degToRad(90.0)).equals(0, -5, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotated(degToRad(90.0), degToRad(0.0), degToRad(0.0)).equals(0, 0, -5), verbose);
				Assertv(Vec3d(0, 5, 0).rotated(degToRad(0.0), degToRad(90.0), degToRad(0.0)).equals(0, 5, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotated(degToRad(0.0), degToRad(0.0), degToRad(90.0)).equals(5, 0, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotated(degToRad(90.0), degToRad(0.0), degToRad(0.0)).equals(0, 5, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotated(degToRad(0.0), degToRad(90.0), degToRad(0.0)).equals(-5, 0, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotated(degToRad(0.0), degToRad(0.0), degToRad(90.0)).equals(0, 0, 5), verbose);
				Assertv(Vec3d(5, 0, 0).rotated(degToRad(-90.0), degToRad(0.0), degToRad(0.0)).equals(5, 0, 0), verbose);
				Assertv(Vec3d(5, 0, 0).rotated(degToRad(0.0), degToRad(-90.0), degToRad(0.0)).equals(0, 0, -5), verbose);
				Assertv(Vec3d(5, 0, 0).rotated(degToRad(0.0), degToRad(0.0), degToRad(-90.0)).equals(0, 5, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotated(degToRad(-90.0), degToRad(0.0), degToRad(0.0)).equals(0, 0, 5), verbose);
				Assertv(Vec3d(0, 5, 0).rotated(degToRad(0.0), degToRad(-90.0), degToRad(0.0)).equals(0, 5, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotated(degToRad(0.0), degToRad(0.0), degToRad(-90.0)).equals(-5, 0, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotated(degToRad(-90.0), degToRad(0.0), degToRad(0.0)).equals(0, -5, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotated(degToRad(0.0), degToRad(-90.0), degToRad(0.0)).equals(5, 0, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotated(degToRad(0.0), degToRad(0.0), degToRad(-90.0)).equals(0, 0, 5), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotated(degToRad(45.0), degToRad(0.0), degToRad(0.0)).equals(sq2, 1, -1), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotated(degToRad(-45.0), degToRad(0.0), degToRad(0.0)).equals(sq2, 1, 1), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotated(degToRad(0.0), degToRad(45.0), degToRad(0.0)).equals(1, sq2, 1), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotated(degToRad(0.0), degToRad(-45.0), degToRad(0.0)).equals(1, sq2, -1), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotated(degToRad(0.0), degToRad(0.0), degToRad(45.0)).equals(2, 0, 0), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotated(degToRad(0.0), degToRad(0.0), degToRad(-45.0)).equals(0, 2, 0), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotated(degToRad(45.0), degToRad(0.0), degToRad(0.0)).equals(sq2, 1, 1), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotated(degToRad(-45.0), degToRad(0.0), degToRad(0.0)).equals(sq2, -1, 1), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotated(degToRad(0.0), degToRad(45.0), degToRad(0.0)).equals(0, 0, 2), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotated(degToRad(0.0), degToRad(-45.0), degToRad(0.0)).equals(2, 0, 0), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotated(degToRad(0.0), degToRad(0.0), degToRad(45.0)).equals(1, -1, sq2), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotated(degToRad(0.0), degToRad(0.0), degToRad(-45.0)).equals(1, 1, sq2), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotated(degToRad(45.0), degToRad(0.0), degToRad(0.0)).equals(0, 2, 0), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotated(degToRad(-45.0), degToRad(0.0), degToRad(0.0)).equals(0, 0, 2), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotated(degToRad(0.0), degToRad(45.0), degToRad(0.0)).equals(-1, sq2, 1), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotated(degToRad(0.0), degToRad(-45.0), degToRad(0.0)).equals(1, sq2, 1), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotated(degToRad(0.0), degToRad(0.0), degToRad(45.0)).equals(1, 1, sq2), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotated(degToRad(0.0), degToRad(0.0), degToRad(-45.0)).equals(-1, 1, sq2), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotated(degToRad(45.0), degToRad(0.0), degToRad(0.0)).equals(sq2, 2, 0), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotated(degToRad(-45.0), degToRad(0.0), degToRad(0.0)).equals(sq2, 0, 2), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotated(degToRad(0.0), degToRad(45.0), degToRad(0.0)).equals(0, sq2, 2), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotated(degToRad(0.0), degToRad(-45.0), degToRad(0.0)).equals(2, sq2, 0), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotated(degToRad(0.0), degToRad(0.0), degToRad(45.0)).equals(2, 0, sq2), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotated(degToRad(0.0), degToRad(0.0), degToRad(-45.0)).equals(0, 2, sq2), verbose);
			}
		}
		{ // rotated - angle_vec
			{ // RHS
				Vec3d::DefaultAxisRule = Rules::AXIS_RHS;
				Assertve(Vec3d::DefaultAxisRule == Rules::AXIS_RHS, verbose);
				Assertv(Vec3d(5, 5, 5).rotated(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(0.0))).equals(5, 5, 5), verbose);
				Assertv(Vec3d(5, 0, 0).rotated(Vec3d(degToRad(90.0), degToRad(0.0), degToRad(0.0))).equals(5, 0, 0), verbose);
				Assertv(Vec3d(5, 0, 0).rotated(Vec3d(degToRad(0.0), degToRad(90.0), degToRad(0.0))).equals(0, 0, -5), verbose);
				Assertv(Vec3d(5, 0, 0).rotated(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(90.0))).equals(0, 5, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotated(Vec3d(degToRad(90.0), degToRad(0.0), degToRad(0.0))).equals(0, 0, 5), verbose);
				Assertv(Vec3d(0, 5, 0).rotated(Vec3d(degToRad(0.0), degToRad(90.0), degToRad(0.0))).equals(0, 5, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotated(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(90.0))).equals(-5, 0, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotated(Vec3d(degToRad(90.0), degToRad(0.0), degToRad(0.0))).equals(0, -5, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotated(Vec3d(degToRad(0.0), degToRad(90.0), degToRad(0.0))).equals(5, 0, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotated(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(90.0))).equals(0, 0, 5), verbose);
				Assertv(Vec3d(5, 0, 0).rotated(Vec3d(degToRad(-90.0), degToRad(0.0), degToRad(0.0))).equals(5, 0, 0), verbose);
				Assertv(Vec3d(5, 0, 0).rotated(Vec3d(degToRad(0.0), degToRad(-90.0), degToRad(0.0))).equals(0, 0, 5), verbose);
				Assertv(Vec3d(5, 0, 0).rotated(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(-90.0))).equals(0, -5, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotated(Vec3d(degToRad(-90.0), degToRad(0.0), degToRad(0.0))).equals(0, 0, -5), verbose);
				Assertv(Vec3d(0, 5, 0).rotated(Vec3d(degToRad(0.0), degToRad(-90.0), degToRad(0.0))).equals(0, 5, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotated(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(-90.0))).equals(5, 0, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotated(Vec3d(degToRad(-90.0), degToRad(0.0), degToRad(0.0))).equals(0, 5, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotated(Vec3d(degToRad(0.0), degToRad(-90.0), degToRad(0.0))).equals(-5, 0, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotated(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(-90.0))).equals(0, 0, 5), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotated(Vec3d(degToRad(45.0), degToRad(0.0), degToRad(0.0))).equals(sq2, 1, 1), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotated(Vec3d(degToRad(-45.0), degToRad(0.0), degToRad(0.0))).equals(sq2, 1, -1), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotated(Vec3d(degToRad(0.0), degToRad(45.0), degToRad(0.0))).equals(1, sq2, -1), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotated(Vec3d(degToRad(0.0), degToRad(-45.0), degToRad(0.0))).equals(1, sq2, 1), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotated(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(45.0))).equals(0, 2, 0), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotated(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(-45.0))).equals(2, 0, 0), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotated(Vec3d(degToRad(45.0), degToRad(0.0), degToRad(0.0))).equals(sq2, -1, 1), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotated(Vec3d(degToRad(-45.0), degToRad(0.0), degToRad(0.0))).equals(sq2, 1, 1), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotated(Vec3d(degToRad(0.0), degToRad(45.0), degToRad(0.0))).equals(2, 0, 0), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotated(Vec3d(degToRad(0.0), degToRad(-45.0), degToRad(0.0))).equals(0, 0, 2), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotated(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(45.0))).equals(1, 1, sq2), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotated(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(-45.0))).equals(1, -1, sq2), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotated(Vec3d(degToRad(45.0), degToRad(0.0), degToRad(0.0))).equals(0, 0, 2), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotated(Vec3d(degToRad(-45.0), degToRad(0.0), degToRad(0.0))).equals(0, 2, 0), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotated(Vec3d(degToRad(0.0), degToRad(45.0), degToRad(0.0))).equals(1, sq2, 1), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotated(Vec3d(degToRad(0.0), degToRad(-45.0), degToRad(0.0))).equals(-1, sq2, 1), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotated(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(45.0))).equals(-1, 1, sq2), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotated(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(-45.0))).equals(1, 1, sq2), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotated(Vec3d(degToRad(45.0), degToRad(0.0), degToRad(0.0))).equals(sq2, 0, 2), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotated(Vec3d(degToRad(-45.0), degToRad(0.0), degToRad(0.0))).equals(sq2, 2, 0), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotated(Vec3d(degToRad(0.0), degToRad(45.0), degToRad(0.0))).equals(2, sq2, 0), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotated(Vec3d(degToRad(0.0), degToRad(-45.0), degToRad(0.0))).equals(0, sq2, 2), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotated(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(45.0))).equals(0, 2, sq2), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotated(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(-45.0))).equals(2, 0, sq2), verbose);
			}
			{ // LHS
				Vec3d::DefaultAxisRule = Rules::AXIS_LHS;
				Assertve(Vec3d::DefaultAxisRule == Rules::AXIS_LHS, verbose);
				Assertv(Vec3d(5, 5, 5).rotated(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(0.0))).equals(5, 5, 5), verbose);
				Assertv(Vec3d(5, 0, 0).rotated(Vec3d(degToRad(90.0), degToRad(0.0), degToRad(0.0))).equals(5, 0, 0), verbose);
				Assertv(Vec3d(5, 0, 0).rotated(Vec3d(degToRad(0.0), degToRad(90.0), degToRad(0.0))).equals(0, 0, 5), verbose);
				Assertv(Vec3d(5, 0, 0).rotated(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(90.0))).equals(0, -5, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotated(Vec3d(degToRad(90.0), degToRad(0.0), degToRad(0.0))).equals(0, 0, -5), verbose);
				Assertv(Vec3d(0, 5, 0).rotated(Vec3d(degToRad(0.0), degToRad(90.0), degToRad(0.0))).equals(0, 5, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotated(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(90.0))).equals(5, 0, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotated(Vec3d(degToRad(90.0), degToRad(0.0), degToRad(0.0))).equals(0, 5, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotated(Vec3d(degToRad(0.0), degToRad(90.0), degToRad(0.0))).equals(-5, 0, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotated(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(90.0))).equals(0, 0, 5), verbose);
				Assertv(Vec3d(5, 0, 0).rotated(Vec3d(degToRad(-90.0), degToRad(0.0), degToRad(0.0))).equals(5, 0, 0), verbose);
				Assertv(Vec3d(5, 0, 0).rotated(Vec3d(degToRad(0.0), degToRad(-90.0), degToRad(0.0))).equals(0, 0, -5), verbose);
				Assertv(Vec3d(5, 0, 0).rotated(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(-90.0))).equals(0, 5, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotated(Vec3d(degToRad(-90.0), degToRad(0.0), degToRad(0.0))).equals(0, 0, 5), verbose);
				Assertv(Vec3d(0, 5, 0).rotated(Vec3d(degToRad(0.0), degToRad(-90.0), degToRad(0.0))).equals(0, 5, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotated(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(-90.0))).equals(-5, 0, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotated(Vec3d(degToRad(-90.0), degToRad(0.0), degToRad(0.0))).equals(0, -5, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotated(Vec3d(degToRad(0.0), degToRad(-90.0), degToRad(0.0))).equals(5, 0, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotated(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(-90.0))).equals(0, 0, 5), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotated(Vec3d(degToRad(45.0), degToRad(0.0), degToRad(0.0))).equals(sq2, 1, -1), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotated(Vec3d(degToRad(-45.0), degToRad(0.0), degToRad(0.0))).equals(sq2, 1, 1), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotated(Vec3d(degToRad(0.0), degToRad(45.0), degToRad(0.0))).equals(1, sq2, 1), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotated(Vec3d(degToRad(0.0), degToRad(-45.0), degToRad(0.0))).equals(1, sq2, -1), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotated(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(45.0))).equals(2, 0, 0), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotated(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(-45.0))).equals(0, 2, 0), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotated(Vec3d(degToRad(45.0), degToRad(0.0), degToRad(0.0))).equals(sq2, 1, 1), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotated(Vec3d(degToRad(-45.0), degToRad(0.0), degToRad(0.0))).equals(sq2, -1, 1), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotated(Vec3d(degToRad(0.0), degToRad(45.0), degToRad(0.0))).equals(0, 0, 2), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotated(Vec3d(degToRad(0.0), degToRad(-45.0), degToRad(0.0))).equals(2, 0, 0), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotated(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(45.0))).equals(1, -1, sq2), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotated(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(-45.0))).equals(1, 1, sq2), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotated(Vec3d(degToRad(45.0), degToRad(0.0), degToRad(0.0))).equals(0, 2, 0), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotated(Vec3d(degToRad(-45.0), degToRad(0.0), degToRad(0.0))).equals(0, 0, 2), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotated(Vec3d(degToRad(0.0), degToRad(45.0), degToRad(0.0))).equals(-1, sq2, 1), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotated(Vec3d(degToRad(0.0), degToRad(-45.0), degToRad(0.0))).equals(1, sq2, 1), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotated(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(45.0))).equals(1, 1, sq2), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotated(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(-45.0))).equals(-1, 1, sq2), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotated(Vec3d(degToRad(45.0), degToRad(0.0), degToRad(0.0))).equals(sq2, 2, 0), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotated(Vec3d(degToRad(-45.0), degToRad(0.0), degToRad(0.0))).equals(sq2, 0, 2), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotated(Vec3d(degToRad(0.0), degToRad(45.0), degToRad(0.0))).equals(0, sq2, 2), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotated(Vec3d(degToRad(0.0), degToRad(-45.0), degToRad(0.0))).equals(2, sq2, 0), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotated(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(45.0))).equals(2, 0, sq2), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotated(Vec3d(degToRad(0.0), degToRad(0.0), degToRad(-45.0))).equals(0, 2, sq2), verbose);
			}
		}
		{ // rotatedX
			{ // RHS
				Vec3d::DefaultAxisRule = Rules::AXIS_RHS;
				Assertve(Vec3d::DefaultAxisRule == Rules::AXIS_RHS, verbose);
				Assertv(Vec3d(5, 5, 5).rotatedX(degToRad(0.0)).equals(5, 5, 5), verbose);
				Assertv(Vec3d(5, 0, 0).rotatedX(degToRad(90.0)).equals(5, 0, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotatedX(degToRad(90.0)).equals(0, 0, 5), verbose);
				Assertv(Vec3d(0, 0, 5).rotatedX(degToRad(90.0)).equals(0, -5, 0), verbose);
				Assertv(Vec3d(5, 0, 0).rotatedX(degToRad(-90.0)).equals(5, 0, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotatedX(degToRad(-90.0)).equals(0, 0, -5), verbose);
				Assertv(Vec3d(0, 0, 5).rotatedX(degToRad(-90.0)).equals(0, 5, 0), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotatedX(degToRad(45.0)).equals(sq2, 1, 1), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotatedX(degToRad(-45.0)).equals(sq2, 1, -1), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotatedX(degToRad(45.0)).equals(sq2, -1, 1), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotatedX(degToRad(-45.0)).equals(sq2, 1, 1), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotatedX(degToRad(45.0)).equals(0, 0, 2), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotatedX(degToRad(-45.0)).equals(0, 2, 0), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotatedX(degToRad(45.0)).equals(sq2, 0, 2), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotatedX(degToRad(-45.0)).equals(sq2, 2, 0), verbose);
			}
			{ // LHS
				Vec3d::DefaultAxisRule = Rules::AXIS_LHS;
				Assertve(Vec3d::DefaultAxisRule == Rules::AXIS_LHS, verbose);
				Assertv(Vec3d(5, 5, 5).rotatedX(degToRad(0.0)).equals(5, 5, 5), verbose);
				Assertv(Vec3d(5, 0, 0).rotatedX(degToRad(90.0)).equals(5, 0, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotatedX(degToRad(90.0)).equals(0, 0, -5), verbose);
				Assertv(Vec3d(0, 0, 5).rotatedX(degToRad(90.0)).equals(0, 5, 0), verbose);
				Assertv(Vec3d(5, 0, 0).rotatedX(degToRad(-90.0)).equals(5, 0, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotatedX(degToRad(-90.0)).equals(0, 0, 5), verbose);
				Assertv(Vec3d(0, 0, 5).rotatedX(degToRad(-90.0)).equals(0, -5, 0), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotatedX(degToRad(45.0)).equals(sq2, 1, -1), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotatedX(degToRad(-45.0)).equals(sq2, 1, 1), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotatedX(degToRad(45.0)).equals(sq2, 1, 1), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotatedX(degToRad(-45.0)).equals(sq2, -1, 1), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotatedX(degToRad(45.0)).equals(0, 2, 0), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotatedX(degToRad(-45.0)).equals(0, 0, 2), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotatedX(degToRad(45.0)).equals(sq2, 2, 0), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotatedX(degToRad(-45.0)).equals(sq2, 0, 2), verbose);
			}
		}
		{ // rotatedY
			{ // RHS
				Vec3d::DefaultAxisRule = Rules::AXIS_RHS;
				Assertve(Vec3d::DefaultAxisRule == Rules::AXIS_RHS, verbose);
				Assertv(Vec3d(5, 5, 5).rotatedY(degToRad(0.0)).equals(5, 5, 5), verbose);
				Assertv(Vec3d(5, 0, 0).rotatedY(degToRad(90.0)).equals(0, 0, -5), verbose);
				Assertv(Vec3d(0, 5, 0).rotatedY(degToRad(90.0)).equals(0, 5, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotatedY(degToRad(90.0)).equals(5, 0, 0), verbose);
				Assertv(Vec3d(5, 0, 0).rotatedY(degToRad(-90.0)).equals(0, 0, 5), verbose);
				Assertv(Vec3d(0, 5, 0).rotatedY(degToRad(-90.0)).equals(0, 5, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotatedY(degToRad(-90.0)).equals(-5, 0, 0), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotatedY(degToRad(45.0)).equals(1, sq2, -1), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotatedY(degToRad(-45.0)).equals(1, sq2, 1), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotatedY(degToRad(45.0)).equals(2, 0, 0), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotatedY(degToRad(-45.0)).equals(0, 0, 2), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotatedY(degToRad(45.0)).equals(1, sq2, 1), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotatedY(degToRad(-45.0)).equals(-1, sq2, 1), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotatedY(degToRad(45.0)).equals(2, sq2, 0), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotatedY(degToRad(-45.0)).equals(0, sq2, 2), verbose);
			}
			{ // LHS
				Vec3d::DefaultAxisRule = Rules::AXIS_LHS;
				Assertve(Vec3d::DefaultAxisRule == Rules::AXIS_LHS, verbose);
				Assertv(Vec3d(5, 5, 5).rotatedY(degToRad(0.0)).equals(5, 5, 5), verbose);
				Assertv(Vec3d(5, 0, 0).rotatedY(degToRad(90.0)).equals(0, 0, 5), verbose);
				Assertv(Vec3d(0, 5, 0).rotatedY(degToRad(90.0)).equals(0, 5, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotatedY(degToRad(90.0)).equals(-5, 0, 0), verbose);
				Assertv(Vec3d(5, 0, 0).rotatedY(degToRad(-90.0)).equals(0, 0, -5), verbose);
				Assertv(Vec3d(0, 5, 0).rotatedY(degToRad(-90.0)).equals(0, 5, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotatedY(degToRad(-90.0)).equals(5, 0, 0), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotatedY(degToRad(45.0)).equals(1, sq2, 1), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotatedY(degToRad(-45.0)).equals(1, sq2, -1), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotatedY(degToRad(45.0)).equals(0, 0, 2), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotatedY(degToRad(-45.0)).equals(2, 0, 0), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotatedY(degToRad(45.0)).equals(-1, sq2, 1), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotatedY(degToRad(-45.0)).equals(1, sq2, 1), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotatedY(degToRad(45.0)).equals(0, sq2, 2), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotatedY(degToRad(-45.0)).equals(2, sq2, 0), verbose);
			}
		}
		{ // rotatedZ
			{ // RHS
				Vec3d::DefaultAxisRule = Rules::AXIS_RHS;
				Assertve(Vec3d::DefaultAxisRule == Rules::AXIS_RHS, verbose);
				Assertv(Vec3d(5, 5, 5).rotatedZ(degToRad(0.0)).equals(5, 5, 5), verbose);
				Assertv(Vec3d(5, 0, 0).rotatedZ(degToRad(90.0)).equals(0, 5, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotatedZ(degToRad(90.0)).equals(-5, 0, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotatedZ(degToRad(90.0)).equals(0, 0, 5), verbose);
				Assertv(Vec3d(5, 0, 0).rotatedZ(degToRad(-90.0)).equals(0, -5, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotatedZ(degToRad(-90.0)).equals(5, 0, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotatedZ(degToRad(-90.0)).equals(0, 0, 5), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotatedZ(degToRad(45.0)).equals(0, 2, 0), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotatedZ(degToRad(-45.0)).equals(2, 0, 0), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotatedZ(degToRad(45.0)).equals(1, 1, sq2), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotatedZ(degToRad(-45.0)).equals(1, -1, sq2), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotatedZ(degToRad(45.0)).equals(-1, 1, sq2), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotatedZ(degToRad(-45.0)).equals(1, 1, sq2), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotatedZ(degToRad(45.0)).equals(0, 2, sq2), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotatedZ(degToRad(-45.0)).equals(2, 0, sq2), verbose);
			}
			{ // LHS
				Vec3d::DefaultAxisRule = Rules::AXIS_LHS;
				Assertve(Vec3d::DefaultAxisRule == Rules::AXIS_LHS, verbose);
				Assertv(Vec3d(5, 5, 5).rotatedZ(degToRad(0.0)).equals(5, 5, 5), verbose);
				Assertv(Vec3d(5, 0, 0).rotatedZ(degToRad(90.0)).equals(0, -5, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotatedZ(degToRad(90.0)).equals(5, 0, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotatedZ(degToRad(90.0)).equals(0, 0, 5), verbose);
				Assertv(Vec3d(5, 0, 0).rotatedZ(degToRad(-90.0)).equals(0, 5, 0), verbose);
				Assertv(Vec3d(0, 5, 0).rotatedZ(degToRad(-90.0)).equals(-5, 0, 0), verbose);
				Assertv(Vec3d(0, 0, 5).rotatedZ(degToRad(-90.0)).equals(0, 0, 5), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotatedZ(degToRad(45.0)).equals(2, 0, 0), verbose);
				Assertv(Vec3d(sq2, sq2, 0).rotatedZ(degToRad(-45.0)).equals(0, 2, 0), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotatedZ(degToRad(45.0)).equals(1, -1, sq2), verbose);
				Assertv(Vec3d(sq2, 0, sq2).rotatedZ(degToRad(-45.0)).equals(1, 1, sq2), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotatedZ(degToRad(45.0)).equals(1, 1, sq2), verbose);
				Assertv(Vec3d(0, sq2, sq2).rotatedZ(degToRad(-45.0)).equals(-1, 1, sq2), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotatedZ(degToRad(45.0)).equals(2, 0, sq2), verbose);
				Assertv(Vec3d(sq2, sq2, sq2).rotatedZ(degToRad(-45.0)).equals(0, 2, sq2), verbose);
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