#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include "../Assert.hpp"
#include "../lib.hpp"
#include <axl.math/float.hpp>
#include <axl.math/vec/Vec4f.hpp>

int main(int argc, char *argv[])
{
	bool verbose = argc > 1 && (0 == strcmp(argv[1], "-v") || 0 == strcmp(argv[1], "--verbose"));
	using namespace axl;
	using namespace axl::math;
	printf("axl.math - version %hu.%hu.%hu  %s %s\n", lib::VERSION.major, lib::VERSION.minor, lib::VERSION.patch, libType(lib::LIBRARY_TYPE), buildType(lib::BUILD_TYPE));
	puts("----------------------------------------");
	{ // static values
		Assertv(Float::equals(0.0f, Vec4f::Zero.x, 0.0001f), verbose);
		Assertv(Float::equals(0.0f, Vec4f::Zero.y, 0.0001f), verbose);
		Assertv(Float::equals(0.0f, Vec4f::Zero.z, 0.0001f), verbose);
		Assertv(Float::equals(1.0f, Vec4f::Identity.x, 0.0001f), verbose);
		Assertv(Float::equals(1.0f, Vec4f::Identity.y, 0.0001f), verbose);
		Assertv(Float::equals(1.0f, Vec4f::Identity.z, 0.0001f), verbose);
		Assertv(Vec4f::filled(69.96f).equals(69.96f, 69.96f, 69.96f, 69.96f), verbose);
		Assertv(Vec4f::Default.equals(0.0f, 0.0f, 0.0f, 0.0f), verbose);
	}
	{ // constructors
		{ // default constructor
			{
				Assertv(Vec4f::Default.equals(Vec4f::Zero), verbose);
				Vec4f vec;
				Assertv((Vec4f::Default.x == vec.x), verbose);
				Assertv((Vec4f::Default.y == vec.y), verbose);
				Assertv((Vec4f::Default.z == vec.z), verbose);
				Assertv((Vec4f::Default.w == vec.w), verbose);
			}
			{
				Vec4f::Default = Vec4f::Identity;
				Assertv(Vec4f::Default.equals(Vec4f::Identity), verbose);
				Vec4f vec;
				Assertv(vec.equals(Vec4f::Identity), verbose);
				Assertv((Vec4f::Default.x == vec.x), verbose);
				Assertv((Vec4f::Default.y == vec.y), verbose);
				Assertv((Vec4f::Default.z == vec.z), verbose);
				Assertv((Vec4f::Default.w == vec.w), verbose);
				Vec4f::Default = Vec4f::Zero;
				Assertv(Vec4f::Default.equals(Vec4f::Zero), verbose);
			}
		}
		{ // values constructor
			Vec4f vec(3, 0, 456, 45);
			Assertv(Float::equals(3, vec.x, 0.0001f), verbose);
			Assertv(Float::equals(0, vec.y, 0.0001f), verbose);
			Assertv(Float::equals(456, vec.z, 0.0001f), verbose);
			Assertv(Float::equals(45, vec.w, 0.0001f), verbose);
		}
		{ // copy constructor
			{
				Vec4f vec(3, 0, 456, 45);
				Assertv(Float::equals(3, vec.x, 0.0001f), verbose);
				Assertv(Float::equals(0, vec.y, 0.0001f), verbose);
				Assertv(Float::equals(456, vec.z, 0.0001f), verbose);
				Assertv(Float::equals(45, vec.w, 0.0001f), verbose);
				Vec4f vec1(vec);
				Assertv(Float::equals(3, vec1.x, 0.0001f), verbose);
				Assertv(Float::equals(0, vec1.y, 0.0001f), verbose);
				Assertv(Float::equals(456, vec1.z, 0.0001f), verbose);
				Assertv(Float::equals(45, vec1.w, 0.0001f), verbose);
				Vec4f vec2 = vec;
				Assertv(Float::equals(3, vec2.x, 0.0001f), verbose);
				Assertv(Float::equals(0, vec2.y, 0.0001f), verbose);
				Assertv(Float::equals(456, vec2.z, 0.0001f), verbose);
				Assertv(Float::equals(45, vec2.w, 0.0001f), verbose);
			}
			{
				const Vec2f vec2(1, 3);
				Assertv(vec2.equals(1, 3), verbose);
				{
					const Vec4f vec4(vec2);
					Assertv(vec4.equals(1, 3, 0, 0), verbose);
				}
				{
					const Vec4f vec4(vec2, 6, 7);
					Assertv(vec4.equals(1, 3, 6, 7), verbose);
				}
			}
			{
				const Vec3f vec3(1, 3, 5);
				Assertv(vec3.equals(1, 3, 5), verbose);
				{
					const Vec4f vec4(vec3);
					Assertv(vec4.equals(1, 3, 5, 0), verbose);
				}
				{
					const Vec4f vec4(vec3, 7);
					Assertv(vec4.equals(1, 3, 5, 7), verbose);
				}
			}
		}
	}
	{ // array mode referencing
		const Vec4f vec(1,2,3,4);
		Assertv(vec.equals(1,2,3,4), verbose);
		Assertv(&(&vec.x)[0] == &vec.x, verbose);
		Assertv(&(&vec.x)[1] == &vec.y, verbose);
		Assertv(&(&vec.x)[2] == &vec.z, verbose);
		Assertv(&(&vec.x)[3] == &vec.w, verbose);
		Assertv(vec.equals((&vec.x)[0],(&vec.x)[1],(&vec.x)[2],(&vec.x)[3]), verbose);
	}
	{ // unary operators
		const Vec4f vec(3, 5, 1, 45);
		const Vec4f pvec = +vec;
		const Vec4f nvec = -vec;
		Assertv(pvec.equals(pvec), verbose);
		Assertv(nvec.equals(-pvec.x, -pvec.y, -pvec.z, -pvec.w), verbose);
		Assertv(vec.equals(-nvec), verbose);
	}
	{ // Nan
		{
			const Vec4f vec(Float::Nan, Float::Nan, Float::Nan, Float::Nan);
			Assertv(vec.isNan(), verbose);
			Assertv(vec.hasNan(), verbose);
			Assertv(!vec.hasNoNan(), verbose);
		}
		{
			const Vec4f vec(0.6f, Float::Nan, Float::Nan, Float::Nan);
			Assertv(!vec.isNan(), verbose);
			Assertv(vec.hasNan(), verbose);
			Assertv(!vec.hasNoNan(), verbose);
		}
		{
			const Vec4f vec(0.6f, Float::Nan, 5.5f, Float::Nan);
			Assertv(!vec.isNan(), verbose);
			Assertv(vec.hasNan(), verbose);
			Assertv(!vec.hasNoNan(), verbose);
		}
		{
			const Vec4f vec(0.5f, 1.0f, 6.4f, 5.5f);
			Assertv(!vec.isNan(), verbose);
			Assertv(!vec.hasNan(), verbose);
			Assertv(vec.hasNoNan(), verbose);
		}
	}
	{ // equality operators
		Assertv(Vec4f::Zero == 0.0f, verbose);
		Assertv(Vec4f::Identity == 1.0f, verbose);
		Assertv(Vec4f::Zero == Vec4f::Zero, verbose);
		Assertv(Vec4f::Identity == Vec4f::Identity, verbose);
		Assertv(!(Vec4f::Zero != 0.0f), verbose);
		Assertv(!(Vec4f::Identity != 1.0f), verbose);
		Assertv(!(Vec4f::Zero != Vec4f::Zero), verbose);
		Assertv(!(Vec4f::Identity != Vec4f::Identity), verbose);
		Vec4f vec(3, 4, 324, 45), vec2(1, 0, 324, 45);
		Assertv(vec.equals(3, 4, 324, 45), verbose);
		Assertv(vec.equals(vec), verbose);
		Assertv(!vec.equals(vec2), verbose);
		Assertv(!vec.notEquals(3, 4, 324, 45), verbose);
		Assertv(!vec.notEquals(vec), verbose);
		Assertv(vec.notEquals(vec2), verbose);
	}
	{ // arthimetic operators
		{ // addition
			const float lval_x = 12, lval_y = 131, lval_z = 0, lval_w = 32;
			const float rval_x = 4, rval_y = 12314, rval_z = 344, rval_w = 89;
			const Vec4f lvec(lval_x, lval_y, lval_z, lval_w), rvec(rval_x, rval_y, rval_z, rval_w);
			Vec4f vec = lvec + rvec;
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
			const float lval_x = 12, lval_y = 131, lval_z = 0, lval_w = 32;
			const float rval_x = 4, rval_y = 12314, rval_z = 344, rval_w = 89;
			const Vec4f lvec(lval_x, lval_y, lval_z, lval_w), rvec(rval_x, rval_y, rval_z, rval_w);
			Vec4f vec = lvec - rvec;
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
			const float lval_x = 12, lval_y = 131, lval_z = 0, lval_w = 32;
			const float rval_x = 4, rval_y = 12314, rval_z = 344, rval_w = 89;
			const Vec4f lvec(lval_x, lval_y, lval_z, lval_w), rvec(rval_x, rval_y, rval_z, rval_w);
			Vec4f vec = lvec * rvec;
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
			const float lval_x = 12, lval_y = 131, lval_z = 0, lval_w = 32;
			const float rval_x = 4, rval_y = 12314, rval_z = 344, rval_w = 89;
			const Vec4f lvec(lval_x, lval_y, lval_z, lval_w), rvec(rval_x, rval_y, rval_z, rval_w);
			Vec4f vec = lvec / rvec;
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
			const float x = 2.0f, y = 3.0f, z = -4.6f, w = 3.14f;
			const Vec4f vec(x, y, z, w);
			const float magn = vec.magn();
			Assertv(Float::equals(magn, std::sqrt(x * x + y * y + z * z+ w * w), 0.0001f), verbose);
			Assertv(Float::equals(magn, std::sqrt(std::pow(x, 2.0f) + std::pow(y, 2.0f) + std::pow(z, 2.0f) + std::pow(w, 2.0f)), 0.0001f), verbose);
		}
		{ // normal
			{
				const float x = 2.0f, y = 3.0f, z = -3.5f, w = 4.31f;
				const Vec4f vec(x, y, z, w);
				const float magn1 = std::sqrt(x * x + y * y + z * z + w * w);
				const float magn2 = std::sqrt(std::pow(x, 2.0f) + std::pow(y, 2.0f) + std::pow(z, 2.0f) + std::pow(w, 2.0f));
				const Vec4f norm_vec = vec.norm();
				const Vec4f norm_vec1 = vec / magn1;
				const Vec4f norm_vec2 = vec / magn2;
				Assertv(Float::equals(1.0f, norm_vec.magn(), 0.0001f), verbose);
				Assertv(Float::equals(1.0f, norm_vec1.magn(), 0.0001f), verbose);
				Assertv(Float::equals(1.0f, norm_vec2.magn(), 0.0001f), verbose);
				Assertv(Float::equals(1.0f, std::sqrt(norm_vec1.x * norm_vec1.x + norm_vec1.y * norm_vec1.y + norm_vec1.z * norm_vec1.z + norm_vec1.w * norm_vec1.w), 0.0001f), verbose);
				Assertv(Float::equals(1.0f, std::sqrt(std::pow(norm_vec2.x, 2.0f) + std::pow(norm_vec2.y, 2.0f) + std::pow(norm_vec2.z, 2.0f) + std::pow(norm_vec2.w, 2.0f)), 0.0001f), verbose);
			}
			{
				const float x = 2.0f, y = 3.0f, z = -4.5f, w = 4.12f;
				const Vec4f vec(x, y, z, w);
				Vec4f nvec(x, y, z, w);
				nvec.normalize();
				const float magn1 = std::sqrt(x * x + y * y + z * z + w * w);
				const Vec4f norm_vec = vec / magn1;
				Assertv(nvec.equals(norm_vec, 0.0001f), verbose);
				Assertv(Float::equals(1.0f, nvec.magn(), 0.0001f), verbose);
				Assertv(Float::equals(1.0f, norm_vec.magn(), 0.0001f), verbose);
				Assertv(vec.equals(nvec * vec.magn(), 0.0001f), verbose);
			}
		}
		{ // dot product
			const float lx = 2.0f, ly = 3.0f, lz = -3.5f, lw = 0.555f;
			const float rx = 4.0f, ry = -6.0f, rz = -9.5f, rw = 3.14f;
			const Vec4f lvec(lx, ly, lz, lw);
			const Vec4f rvec(rx, ry, rz, rw);
			const float dotplr = lvec.dot(rvec);
			const float dotprl = rvec.dot(lvec);
			Assertv(Float::equals(dotplr, (lx * rx + ly * ry + lz * rz+ lw * rw), 0.0001f), verbose);
			Assertv(Float::equals(dotprl, (lx * rx + ly * ry + lz * rz+ lw * rw), 0.0001f), verbose);
		}
	}
	{ // transforms
		{ // scale
			const float scale = 4.5f, scale_x = 1.56f, scale_y = 0.75f, scale_z = -90.0f, scale_w = 9.3f;
			{
				Vec4f vec(5.67f, 98.999f, 66.9f, 45.0f);
				Assertv(vec.equals(5.67f, 98.999f, 66.9f, 45.0f, 0.0001f), verbose);
				vec.scale(1.0f);
				Assertv(vec.equals(5.67f, 98.999f, 66.9f, 45.0f, 0.0001f), verbose);
			}
			{
				Vec4f vec(5.5f, 0.0f, 0.5f, 45.0f);
				Assertv(vec.equals(5.5f, 0.0f, 0.5f, 45.0f, 0.0001f), verbose);
				vec.scale(0.0f, 2.0f, 0.5f, 2.0f);
				Assertv(vec.equals(0.0f, 0.0f, 0.25f, 90.0f, 0.0001f), verbose);
			}
			{
				Vec4f vec(5.67f, 98.999f, 66.9f, 45.0f);
				Assertv(vec.equals(5.67f, 98.999f, 66.9f, 45.0f, 0.0001f), verbose);
				vec.scale(scale);
				Assertv(vec.equals(5.67f * scale, 98.999f * scale, 66.9f * scale, 45.0f * scale, 0.0001f), verbose);
			}
			{
				Vec4f vec(5.67f, 98.999f, 66.9f, 45.0f);
				Assertv(vec.equals(5.67f, 98.999f, 66.9f, 45.0f, 0.0001f), verbose);
				vec.scale(scale_x, scale_y, scale_z, scale_w);
				Assertv(vec.equals(5.67f * scale_x, 98.999f * scale_y, 66.9f * scale_z, 45.0f * scale_w, 0.0001f), verbose);
			}
		}
		{ // scaled
			const float scale = 4.5f, scale_x = 1.56f, scale_y = 0.75f, scale_z = -90.0f, scale_w = 9.5f;
			{
				const Vec4f vec(5.67f, 98.999f, 66.9f, 45.0f);
				Assertv(vec.equals(5.67f, 98.999f, 66.9f, 45.0f, 0.0001f), verbose);
				Assertv(vec.scaled(1.0f).equals(5.67f, 98.999f, 66.9f, 45.0f, 0.0001f), verbose);
			}
			{
				const Vec4f vec(5.5f, 0.0f, 0.5f, 45.0f);
				Assertv(vec.equals(5.5f, 0.0f, 0.5f, 45.0f, 0.0001f), verbose);
				Assertv(vec.scaled(0.0f, 2.0f, 0.5f, 2.0f).equals(0.0f, 0.0f, 0.25f, 90.0f, 0.0001f), verbose);
			}
			{
				const Vec4f vec(5.67f, 98.999f, 66.9f, 45.0f);
				Assertv(vec.equals(5.67f, 98.999f, 66.9f, 45.0f, 0.0001f), verbose);
				Assertv(vec.scaled(scale).equals(5.67f * scale, 98.999f * scale, 66.9f * scale, 45.0f * scale, 0.0001f), verbose);
			}
			{
				const Vec4f vec(5.67f, 98.999f, 66.9f, 45.0f);
				Assertv(vec.equals(5.67f, 98.999f, 66.9f, 45.0f, 0.0001f), verbose);
				Assertv(vec.scaled(scale_x, scale_y, scale_z, scale_w).equals(5.67f * scale_x, 98.999f * scale_y, 66.9f * scale_z, 45.0f * scale_w, 0.0001f), verbose);
			}
		}
		{ // translate
			{ // Vec4f
				const Vec4f delta(4.5f, -900.3434f, -44.66f, 45.0f);
				Vec4f vec(5.67f, 98.999f, -120.04f, 5.0f);
				Assertv(vec.equals(5.67f, 98.999f, -120.04f, 5.0f, 0.0001f), verbose);
				vec.translate(delta);
				Assertv(vec.equals(5.67f + delta.x, 98.999f + delta.y, -120.04f + delta.z, 5.0f + delta.w, 0.0001f), verbose);
			}
			{ // values
				const float delta_x = 4.5f, delta_y = -900.3434f, delta_z = -44.66f, delta_w = 35.0f;
				Vec4f vec(5.67f, 98.999f, -120.04f, -35.0f);
				Assertv(vec.equals(5.67f, 98.999f, -120.04f, -35.0f), verbose);
				vec.translate(delta_x, delta_y, delta_z, delta_w);
				Assertv(vec.equals(5.67f + delta_x, 98.999f + delta_y, -120.04f + delta_z, -35.0f + delta_w, 0.0001f), verbose);
			}
		}
		{ // translated
			{ // Vec4f
				const Vec4f delta(4.5f, -900.3434f, -44.66f, -35.0f);
				const Vec4f vec(5.67f, 98.999f, -120.04f, 5.0f);
				Assertv(vec.equals(5.67f, 98.999f, -120.04f, 5.0f, 0.0001f), verbose);
				Vec4f tvec = vec.translated(delta);
				Assertv(tvec.equals(vec.x + delta.x, vec.y + delta.y, vec.z + delta.z, vec.w + delta.w, 0.0001f), verbose);
			}
			{ // values
				const float delta_x = 4.5f, delta_y = -900.3434f, delta_z = -44.66f, delta_w = 5.0f;
				const Vec4f vec(5.67f, 98.999f, -120.04f, -35.0f);
				Assertv(vec.equals(5.67f, 98.999f, -120.04f, -35.0f), verbose);
				Vec4f tvec = vec.translated(delta_x, delta_y, delta_z, delta_w);
				Assertv(tvec.equals(vec.x + delta_x, vec.y + delta_y, vec.z + delta_z, -35.0f + delta_w, 0.0001f), verbose);
			}
		}
	}
	if(assert::_num_failed_tests <= 0)
		printf("ALL GOOD!\n");
	else
	{
		puts("----------------------------------------");
		printf("# %d Failed!\n", assert::_num_failed_tests);
	}
	return assert::_num_failed_tests;
}