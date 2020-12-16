#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include "../Assert.hpp"
#include "../lib.hpp"
#include <axl.math/double.hpp>
#include <axl.math/vec/Vec4d.hpp>

int main(int argc, char *argv[])
{
	bool verbose = argc > 1 && (0 == strcmp(argv[1], "-v") || 0 == strcmp(argv[1], "--verbose"));
	using namespace axl;
	using namespace axl::math;
	printf("axl.math - version %hu.%hu.%hu  %s %s\n", lib::VERSION.major, lib::VERSION.minor, lib::VERSION.patch, libType(lib::LIBRARY_TYPE), buildType(lib::BUILD_TYPE));
	puts("----------------------------------------");
	{ // static values
		Assertv(Double::equals(0.0, Vec4d::Zero.x, 0.000001), verbose);
		Assertv(Double::equals(0.0, Vec4d::Zero.y, 0.000001), verbose);
		Assertv(Double::equals(0.0, Vec4d::Zero.z, 0.000001), verbose);
		Assertv(Double::equals(1.0, Vec4d::Identity.x, 0.000001), verbose);
		Assertv(Double::equals(1.0, Vec4d::Identity.y, 0.000001), verbose);
		Assertv(Double::equals(1.0, Vec4d::Identity.z, 0.000001), verbose);
		Assertv(Vec4d::filled(69.96).equals(69.96, 69.96, 69.96, 69.96), verbose);
		Assertv(Vec4d::Default.equals(0.0, 0.0, 0.0, 0.0), verbose);
	}
	{ // constructors
		{ // default constructor
			{
				Assertv(Vec4d::Default.equals(Vec4d::Zero), verbose);
				Vec4d vec;
				Assertv((Vec4d::Default.x == vec.x), verbose);
				Assertv((Vec4d::Default.y == vec.y), verbose);
				Assertv((Vec4d::Default.z == vec.z), verbose);
				Assertv((Vec4d::Default.w == vec.w), verbose);
			}
			{
				Vec4d::Default = Vec4d::Identity;
				Assertv(Vec4d::Default.equals(Vec4d::Identity), verbose);
				Vec4d vec;
				Assertv(vec.equals(Vec4d::Identity), verbose);
				Assertv((Vec4d::Default.x == vec.x), verbose);
				Assertv((Vec4d::Default.y == vec.y), verbose);
				Assertv((Vec4d::Default.z == vec.z), verbose);
				Assertv((Vec4d::Default.w == vec.w), verbose);
				Vec4d::Default = Vec4d::Zero;
				Assertv(Vec4d::Default.equals(Vec4d::Zero), verbose);
			}
		}
		{ // values constructor
			Vec4d vec(3, 0, 456, 45);
			Assertv(Double::equals(3, vec.x, 0.000001), verbose);
			Assertv(Double::equals(0, vec.y, 0.000001), verbose);
			Assertv(Double::equals(456, vec.z, 0.000001), verbose);
			Assertv(Double::equals(45, vec.w, 0.000001), verbose);
		}
		{ // copy constructor
			{
				Vec4d vec(3, 0, 456, 45);
				Assertv(Double::equals(3, vec.x, 0.000001), verbose);
				Assertv(Double::equals(0, vec.y, 0.000001), verbose);
				Assertv(Double::equals(456, vec.z, 0.000001), verbose);
				Assertv(Double::equals(45, vec.w, 0.000001), verbose);
				Vec4d vec1(vec);
				Assertv(Double::equals(3, vec1.x, 0.000001), verbose);
				Assertv(Double::equals(0, vec1.y, 0.000001), verbose);
				Assertv(Double::equals(456, vec1.z, 0.000001), verbose);
				Assertv(Double::equals(45, vec1.w, 0.000001), verbose);
				Vec4d vec2 = vec;
				Assertv(Double::equals(3, vec2.x, 0.000001), verbose);
				Assertv(Double::equals(0, vec2.y, 0.000001), verbose);
				Assertv(Double::equals(456, vec2.z, 0.000001), verbose);
				Assertv(Double::equals(45, vec2.w, 0.000001), verbose);
			}
			{
				const Vec2d vec2(1, 3);
				Assertv(vec2.equals(1, 3), verbose);
				{
					const Vec4d vec4(vec2);
					Assertv(vec4.equals(1, 3, 0, 0), verbose);
				}
				{
					const Vec4d vec4(vec2, 6, 7);
					Assertv(vec4.equals(1, 3, 6, 7), verbose);
				}
			}
			{
				const Vec3d vec3(1, 3, 5);
				Assertv(vec3.equals(1, 3, 5), verbose);
				{
					const Vec4d vec4(vec3);
					Assertv(vec4.equals(1, 3, 5, 0), verbose);
				}
				{
					const Vec4d vec4(vec3, 7);
					Assertv(vec4.equals(1, 3, 5, 7), verbose);
				}
			}
		}
	}
	{ // array mode referencing
		const Vec4d vec(1,2,3,4);
		Assertv(vec.equals(1,2,3,4), verbose);
		Assertv(&(&vec.x)[0] == &vec.x, verbose);
		Assertv(&(&vec.x)[1] == &vec.y, verbose);
		Assertv(&(&vec.x)[2] == &vec.z, verbose);
		Assertv(&(&vec.x)[3] == &vec.w, verbose);
		Assertv(vec.equals((&vec.x)[0],(&vec.x)[1],(&vec.x)[2],(&vec.x)[3]), verbose);
	}
	{ // unary operators
		const Vec4d vec(3, 5, 1, 45);
		const Vec4d pvec = +vec;
		const Vec4d nvec = -vec;
		Assertv(pvec.equals(pvec), verbose);
		Assertv(nvec.equals(-pvec.x, -pvec.y, -pvec.z, -pvec.w), verbose);
		Assertv(vec.equals(-nvec), verbose);
	}
	{ // Nan
		{
			const Vec4d vec(Double::Nan, Double::Nan, Double::Nan, Double::Nan);
			Assertv(vec.isNan(), verbose);
			Assertv(vec.hasNan(), verbose);
			Assertv(!vec.hasNoNan(), verbose);
		}
		{
			const Vec4d vec(0.6, Double::Nan, Double::Nan, Double::Nan);
			Assertv(!vec.isNan(), verbose);
			Assertv(vec.hasNan(), verbose);
			Assertv(!vec.hasNoNan(), verbose);
		}
		{
			const Vec4d vec(0.6, Double::Nan, 5.5, Double::Nan);
			Assertv(!vec.isNan(), verbose);
			Assertv(vec.hasNan(), verbose);
			Assertv(!vec.hasNoNan(), verbose);
		}
		{
			const Vec4d vec(0.5, 1.0, 6.4, 5.5);
			Assertv(!vec.isNan(), verbose);
			Assertv(!vec.hasNan(), verbose);
			Assertv(vec.hasNoNan(), verbose);
		}
	}
	{ // equality operators
		Assertv(Vec4d::Zero == 0.0, verbose);
		Assertv(Vec4d::Identity == 1.0, verbose);
		Assertv(Vec4d::Zero == Vec4d::Zero, verbose);
		Assertv(Vec4d::Identity == Vec4d::Identity, verbose);
		Assertv(!(Vec4d::Zero != 0.0), verbose);
		Assertv(!(Vec4d::Identity != 1.0), verbose);
		Assertv(!(Vec4d::Zero != Vec4d::Zero), verbose);
		Assertv(!(Vec4d::Identity != Vec4d::Identity), verbose);
		Vec4d vec(3, 4, 324, 45), vec2(1, 0, 324, 45);
		Assertv(vec.equals(3, 4, 324, 45), verbose);
		Assertv(vec.equals(vec), verbose);
		Assertv(!vec.equals(vec2), verbose);
		Assertv(!vec.notEquals(3, 4, 324, 45), verbose);
		Assertv(!vec.notEquals(vec), verbose);
		Assertv(vec.notEquals(vec2), verbose);
	}
	{ // arthimetic operators
		{ // addition
			const double lval_x = 12, lval_y = 131, lval_z = 0, lval_w = 32;
			const double rval_x = 4, rval_y = 12314, rval_z = 344, rval_w = 89;
			const Vec4d lvec(lval_x, lval_y, lval_z, lval_w), rvec(rval_x, rval_y, rval_z, rval_w);
			Vec4d vec = lvec + rvec;
			Assertv(vec.equals(lval_x + rval_x, lval_y + rval_y, lval_z + rval_z, lval_w + rval_w), verbose);
			
			vec = lvec + rval_y;
			Assertv(vec.equals(lval_x + rval_y, lval_y + rval_y, lval_z + rval_y, lval_w + rval_y), verbose);
			vec = lval_x + rvec;
			Assertv(vec.equals(lval_x + rval_x, lval_x + rval_y, lval_x + rval_z, lval_x + rval_w), verbose);

			vec = lvec;
			Assertv(vec.equals(lval_x, lval_y, lval_z, lval_w), verbose);
			vec += rvec;
			Assertv(vec.equals(lval_x + rval_x, lval_y + rval_y, lval_z + rval_z, lval_w + rval_w), verbose);

			vec = lvec;
			Assertv(vec.equals(lval_x, lval_y, lval_z, lval_w), verbose);
			vec += rval_x;
			Assertv(vec.equals(lval_x + rval_x, lval_y + rval_x, lval_z + rval_x, lval_w + rval_x), verbose);
		}
		{ // subtraction
			const double lval_x = 12, lval_y = 131, lval_z = 0, lval_w = 32;
			const double rval_x = 4, rval_y = 12314, rval_z = 344, rval_w = 89;
			const Vec4d lvec(lval_x, lval_y, lval_z, lval_w), rvec(rval_x, rval_y, rval_z, rval_w);
			Vec4d vec = lvec - rvec;
			Assertv(vec.equals(lval_x - rval_x, lval_y - rval_y, lval_z - rval_z, lval_w - rval_w), verbose);
			
			vec = lvec - rval_y;
			Assertv(vec.equals(lval_x - rval_y, lval_y - rval_y, lval_z - rval_y, lval_w - rval_y), verbose);
			vec = lval_x - rvec;
			Assertv(vec.equals(lval_x - rval_x, lval_x - rval_y, lval_x - rval_z, lval_x - rval_w), verbose);

			vec = lvec;
			Assertv(vec.equals(lval_x, lval_y, lval_z, lval_w), verbose);
			vec -= rvec;
			Assertv(vec.equals(lval_x - rval_x, lval_y - rval_y, lval_z - rval_z, lval_w - rval_w), verbose);

			vec = lvec;
			Assertv(vec.equals(lval_x, lval_y, lval_z, lval_w), verbose);
			vec -= rval_x;
			Assertv(vec.equals(lval_x - rval_x, lval_y - rval_x, lval_z - rval_x, lval_w - rval_x), verbose);
		}
		{ // multiplication
			const double lval_x = 12, lval_y = 131, lval_z = 0, lval_w = 32;
			const double rval_x = 4, rval_y = 12314, rval_z = 344, rval_w = 89;
			const Vec4d lvec(lval_x, lval_y, lval_z, lval_w), rvec(rval_x, rval_y, rval_z, rval_w);
			Vec4d vec = lvec * rvec;
			Assertv(vec.equals(lval_x * rval_x, lval_y * rval_y, lval_z * rval_z, lval_w * rval_w), verbose);
			
			vec = lvec * rval_y;
			Assertv(vec.equals(lval_x * rval_y, lval_y * rval_y, lval_z * rval_y, lval_w * rval_y), verbose);
			vec = lval_x * rvec;
			Assertv(vec.equals(lval_x * rval_x, lval_x * rval_y, lval_x * rval_z, lval_x * rval_w), verbose);

			vec = lvec;
			Assertv(vec.equals(lval_x, lval_y, lval_z, lval_w), verbose);
			vec *= rvec;
			Assertv(vec.equals(lval_x * rval_x, lval_y * rval_y, lval_z * rval_z, lval_w * rval_w), verbose);

			vec = lvec;
			Assertv(vec.equals(lval_x, lval_y, lval_z, lval_w), verbose);
			vec *= rval_x;
			Assertv(vec.equals(lval_x * rval_x, lval_y * rval_x, lval_z * rval_x, lval_w * rval_x), verbose);
		}
		{ // division
			const double lval_x = 12, lval_y = 131, lval_z = 0, lval_w = 32;
			const double rval_x = 4, rval_y = 12314, rval_z = 344, rval_w = 89;
			const Vec4d lvec(lval_x, lval_y, lval_z, lval_w), rvec(rval_x, rval_y, rval_z, rval_w);
			Vec4d vec = lvec / rvec;
			Assertv(vec.equals(lval_x / rval_x, lval_y / rval_y, lval_z / rval_z, lval_w / rval_w), verbose);
			
			vec = lvec / rval_y;
			Assertv(vec.equals(lval_x / rval_y, lval_y / rval_y, lval_z / rval_y, lval_w / rval_y), verbose);
			vec = lval_x / rvec;
			Assertv(vec.equals(lval_x / rval_x, lval_x / rval_y, lval_x / rval_z, lval_x / rval_w), verbose);

			vec = lvec;
			Assertv(vec.equals(lval_x, lval_y, lval_z, lval_w), verbose);
			vec /= rvec;
			Assertv(vec.equals(lval_x / rval_x, lval_y / rval_y, lval_z / rval_z, lval_w / rval_w), verbose);

			vec = lvec;
			Assertv(vec.equals(lval_x, lval_y, lval_z, lval_w), verbose);
			vec /= rval_x;
			Assertv(vec.equals(lval_x / rval_x, lval_y / rval_x, lval_z / rval_x, lval_w / rval_x), verbose);
		}
	}
	{ // vector operation tests
		{ // magnitude
			const double x = 2.0, y = 3.0, z = -4.6, w = 3.14;
			const Vec4d vec(x, y, z, w);
			const double magn = vec.magn();
			Assertv(Double::equals(magn, std::sqrt(x * x + y * y + z * z+ w * w), 0.000001), verbose);
			Assertv(Double::equals(magn, std::sqrt(std::pow(x, 2.0) + std::pow(y, 2.0) + std::pow(z, 2.0) + std::pow(w, 2.0)), 0.000001), verbose);
		}
		{ // normal
			{
				const double x = 2.0, y = 3.0, z = -3.5, w = 4.31;
				const Vec4d vec(x, y, z, w);
				const double magn1 = std::sqrt(x * x + y * y + z * z + w * w);
				const double magn2 = std::sqrt(std::pow(x, 2.0) + std::pow(y, 2.0) + std::pow(z, 2.0) + std::pow(w, 2.0));
				const Vec4d norm_vec = vec.norm();
				const Vec4d norm_vec1 = vec / magn1;
				const Vec4d norm_vec2 = vec / magn2;
				Assertv(Double::equals(1.0, norm_vec.magn(), 0.000001), verbose);
				Assertv(Double::equals(1.0, norm_vec1.magn(), 0.000001), verbose);
				Assertv(Double::equals(1.0, norm_vec2.magn(), 0.000001), verbose);
				Assertv(Double::equals(1.0, std::sqrt(norm_vec1.x * norm_vec1.x + norm_vec1.y * norm_vec1.y + norm_vec1.z * norm_vec1.z + norm_vec1.w * norm_vec1.w), 0.000001), verbose);
				Assertv(Double::equals(1.0, std::sqrt(std::pow(norm_vec2.x, 2.0) + std::pow(norm_vec2.y, 2.0) + std::pow(norm_vec2.z, 2.0) + std::pow(norm_vec2.w, 2.0)), 0.000001), verbose);
			}
			{
				const double x = 2.0, y = 3.0, z = -4.5, w = 4.12;
				const Vec4d vec(x, y, z, w);
				Vec4d nvec(x, y, z, w);
				nvec.normalize();
				const double magn1 = std::sqrt(x * x + y * y + z * z + w * w);
				const Vec4d norm_vec = vec / magn1;
				Assertv(nvec.equals(norm_vec, 0.000001), verbose);
				Assertv(Double::equals(1.0, nvec.magn(), 0.000001), verbose);
				Assertv(Double::equals(1.0, norm_vec.magn(), 0.000001), verbose);
				Assertv(vec.equals(nvec * vec.magn(), 0.000001), verbose);
			}
		}
		{ // dot product
			const double lx = 2.0, ly = 3.0, lz = -3.5, lw = 0.555;
			const double rx = 4.0, ry = -6.0, rz = -9.5, rw = 3.14;
			const Vec4d lvec(lx, ly, lz, lw);
			const Vec4d rvec(rx, ry, rz, rw);
			const double dotplr = lvec.dot(rvec);
			const double dotprl = rvec.dot(lvec);
			Assertv(Double::equals(dotplr, (lx * rx + ly * ry + lz * rz+ lw * rw), 0.000001), verbose);
			Assertv(Double::equals(dotprl, (lx * rx + ly * ry + lz * rz+ lw * rw), 0.000001), verbose);
		}
	}
	{ // transforms
		{ // scale
			const double scale = 4.5, scale_x = 1.56, scale_y = 0.75, scale_z = -90.0, scale_w = 9.3;
			{
				Vec4d vec(5.67, 98.999, 66.9, 45.0);
				Assertv(vec.equals(5.67, 98.999, 66.9, 45.0, 0.000001), verbose);
				vec.scale(1.0);
				Assertv(vec.equals(5.67, 98.999, 66.9, 45.0, 0.000001), verbose);
			}
			{
				Vec4d vec(5.5, 0.0, 0.5, 45.0);
				Assertv(vec.equals(5.5, 0.0, 0.5, 45.0, 0.000001), verbose);
				vec.scale(0.0, 2.0, 0.5, 2.0);
				Assertv(vec.equals(0.0, 0.0, 0.25, 90.0, 0.000001), verbose);
			}
			{
				Vec4d vec(5.67, 98.999, 66.9, 45.0);
				Assertv(vec.equals(5.67, 98.999, 66.9, 45.0, 0.000001), verbose);
				vec.scale(scale);
				Assertv(vec.equals(5.67 * scale, 98.999 * scale, 66.9 * scale, 45.0 * scale, 0.000001), verbose);
			}
			{
				Vec4d vec(5.67, 98.999, 66.9, 45.0);
				Assertv(vec.equals(5.67, 98.999, 66.9, 45.0, 0.000001), verbose);
				vec.scale(scale_x, scale_y, scale_z, scale_w);
				Assertv(vec.equals(5.67 * scale_x, 98.999 * scale_y, 66.9 * scale_z, 45.0 * scale_w, 0.000001), verbose);
			}
		}
		{ // scaled
			const double scale = 4.5, scale_x = 1.56, scale_y = 0.75, scale_z = -90.0, scale_w = 9.5;
			{
				const Vec4d vec(5.67, 98.999, 66.9, 45.0);
				Assertv(vec.equals(5.67, 98.999, 66.9, 45.0, 0.000001), verbose);
				Assertv(vec.scaled(1.0).equals(5.67, 98.999, 66.9, 45.0, 0.000001), verbose);
			}
			{
				const Vec4d vec(5.5, 0.0, 0.5, 45.0);
				Assertv(vec.equals(5.5, 0.0, 0.5, 45.0, 0.000001), verbose);
				Assertv(vec.scaled(0.0, 2.0, 0.5, 2.0).equals(0.0, 0.0, 0.25, 90.0, 0.000001), verbose);
			}
			{
				const Vec4d vec(5.67, 98.999, 66.9, 45.0);
				Assertv(vec.equals(5.67, 98.999, 66.9, 45.0, 0.000001), verbose);
				Assertv(vec.scaled(scale).equals(5.67 * scale, 98.999 * scale, 66.9 * scale, 45.0 * scale, 0.000001), verbose);
			}
			{
				const Vec4d vec(5.67, 98.999, 66.9, 45.0);
				Assertv(vec.equals(5.67, 98.999, 66.9, 45.0, 0.000001), verbose);
				Assertv(vec.scaled(scale_x, scale_y, scale_z, scale_w).equals(5.67 * scale_x, 98.999 * scale_y, 66.9 * scale_z, 45.0 * scale_w, 0.000001), verbose);
			}
		}
		{ // translate
			{ // Vec4d
				const Vec4d delta(4.5, -900.3434, -44.66, 45.0);
				Vec4d vec(5.67, 98.999, -120.04, 5.0);
				Assertv(vec.equals(5.67, 98.999, -120.04, 5.0, 0.000001), verbose);
				vec.translate(delta);
				Assertv(vec.equals(5.67 + delta.x, 98.999 + delta.y, -120.04 + delta.z, 5.0 + delta.w, 0.000001), verbose);
			}
			{ // values
				const double delta_x = 4.5, delta_y = -900.3434, delta_z = -44.66, delta_w = 35.0;
				Vec4d vec(5.67, 98.999, -120.04, -35.0);
				Assertv(vec.equals(5.67, 98.999, -120.04, -35.0), verbose);
				vec.translate(delta_x, delta_y, delta_z, delta_w);
				Assertv(vec.equals(5.67 + delta_x, 98.999 + delta_y, -120.04 + delta_z, -35.0 + delta_w, 0.000001), verbose);
			}
		}
		{ // translated
			{ // Vec4d
				const Vec4d delta(4.5, -900.3434, -44.66, -35.0);
				const Vec4d vec(5.67, 98.999, -120.04, 5.0);
				Assertv(vec.equals(5.67, 98.999, -120.04, 5.0, 0.000001), verbose);
				Vec4d tvec = vec.translated(delta);
				Assertv(tvec.equals(vec.x + delta.x, vec.y + delta.y, vec.z + delta.z, vec.w + delta.w, 0.000001), verbose);
			}
			{ // values
				const double delta_x = 4.5, delta_y = -900.3434, delta_z = -44.66, delta_w = 5.0;
				const Vec4d vec(5.67, 98.999, -120.04, -35.0);
				Assertv(vec.equals(5.67, 98.999, -120.04, -35.0), verbose);
				Vec4d tvec = vec.translated(delta_x, delta_y, delta_z, delta_w);
				Assertv(tvec.equals(vec.x + delta_x, vec.y + delta_y, vec.z + delta_z, -35.0 + delta_w, 0.000001), verbose);
			}
		}
	}
	if(Assert::_num_failed_tests <= 0)
		printf("ALL GOOD!\n");
	else
	{
		puts("----------------------------------------");
		printf("# %d Failed!\n", Assert::_num_failed_tests);
	}
	return Assert::_num_failed_tests;
}