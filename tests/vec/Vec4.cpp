#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include "../Assert.hpp"
#include "../lib.hpp"
#include <axl.math/vec/Vec4.hpp>

int main(int argc, char *argv[])
{
	bool verbose = argc > 1 && (0 == strcmp(argv[1], "-v") || 0 == strcmp(argv[1], "--verbose"));
	using namespace axl;
	using namespace axl::math;
	printf("axl.math - version %hu.%hu.%hu  %s %s\n", lib::VERSION.major, lib::VERSION.minor, lib::VERSION.patch, libType(lib::LIBRARY_TYPE), buildType(lib::BUILD_TYPE));
	puts("----------------------------------------");
	{ // static values
		Assertv((0 == Vec4<int>::Zero.x), verbose);
		Assertv((0 == Vec4<int>::Zero.y), verbose);
		Assertv((0 == Vec4<int>::Zero.z), verbose);
		Assertv((1 == Vec4<int>::Identity.x), verbose);
		Assertv((1 == Vec4<int>::Identity.y), verbose);
		Assertv((1 == Vec4<int>::Identity.z), verbose);
		Assertv(Vec4<int>::Default.equals(0, 0, 0, 0), verbose);
	}
	{ // constructors
		{ // default constructor
			{
				Assertv(Vec4<int>::Default.equals(Vec4<int>::Zero), verbose);
				Vec4<int> vec;
				Assertv((Vec4<int>::Default.x == vec.x), verbose);
				Assertv((Vec4<int>::Default.y == vec.y), verbose);
				Assertv((Vec4<int>::Default.z == vec.z), verbose);
				Assertv((Vec4<int>::Default.w == vec.w), verbose);
			}
			{
				Vec4<int>::Default = Vec4<int>::Identity;
				Assertv(Vec4<int>::Default.equals(Vec4<int>::Identity), verbose);
				Vec4<int> vec;
				Assertv(vec.equals(Vec4<int>::Identity), verbose);
				Assertv((Vec4<int>::Default.x == vec.x), verbose);
				Assertv((Vec4<int>::Default.y == vec.y), verbose);
				Assertv((Vec4<int>::Default.z == vec.z), verbose);
				Assertv((Vec4<int>::Default.w == vec.w), verbose);
				Vec4<int>::Default = Vec4<int>::Zero;
				Assertv(Vec4<int>::Default.equals(Vec4<int>::Zero), verbose);
			}
		}
		{ // values constructor
			Vec4<int> vec(3, 0, 456, 45);
			Assertv((3 == vec.x), verbose);
			Assertv((0 == vec.y), verbose);
			Assertv((456 == vec.z), verbose);
			Assertv((45 == vec.w), verbose);
		}
		{ // copy constructor
			{
				Vec4<int> vec(3, 0, 456, 45);
				Assertv((3 == vec.x), verbose);
				Assertv((0 == vec.y), verbose);
				Assertv((456 == vec.z), verbose);
				Assertv((45 == vec.w), verbose);
				Vec4<int> vec1(vec);
				Assertv((3 == vec1.x), verbose);
				Assertv((0 == vec1.y), verbose);
				Assertv((456 == vec1.z), verbose);
				Assertv((45 == vec1.w), verbose);
				Vec4<int> vec2 = vec;
				Assertv((3 == vec2.x), verbose);
				Assertv((0 == vec2.y), verbose);
				Assertv((456 == vec2.z), verbose);
				Assertv((45 == vec2.w), verbose);
				Vec4<float> vec3 = vec;
				Assertv((3 == vec3.x), verbose);
				Assertv((0 == vec3.y), verbose);
				Assertv((456 == vec3.z), verbose);
				Assertv((45 == vec3.w), verbose);
			}
			{
				const Vec2<short> vec2(1, 3);
				Assertv(vec2.equals(1, 3), verbose);
				{
					const Vec4<int> vec4(vec2);
					Assertv(vec4.equals(1, 3, 0, 0), verbose);
				}
				{
					const Vec4<int> vec4(vec2, 6, 7);
					Assertv(vec4.equals(1, 3, 6, 7), verbose);
				}
			}
			{
				const Vec3<short> vec3(1, 3, 5);
				Assertv(vec3.equals(1, 3, 5), verbose);
				{
					const Vec4<int> vec4(vec3);
					Assertv(vec4.equals(1, 3, 5, 0), verbose);
				}
				{
					const Vec4<int> vec4(vec3, 7);
					Assertv(vec4.equals(1, 3, 5, 7), verbose);
				}
			}
		}
	}
	{ // array mode referencing
		const Vec4<int> vec(1,2,3,4);
		Assertv(vec.equals(1,2,3,4), verbose);
		Assertv(&(&vec.x)[0] == &vec.x, verbose);
		Assertv(&(&vec.x)[1] == &vec.y, verbose);
		Assertv(&(&vec.x)[2] == &vec.z, verbose);
		Assertv(&(&vec.x)[3] == &vec.w, verbose);
		Assertv(vec.equals((&vec.x)[0],(&vec.x)[1],(&vec.x)[2],(&vec.x)[3]), verbose);
	}
	{ // unary operators
		const Vec4<int> vec(3, 5, 1, 45);
		const Vec4<int> pvec = +vec;
		const Vec4<int> nvec = -vec;
		Assertv(pvec.equals(pvec), verbose);
		Assertv(nvec.equals(-pvec.x, -pvec.y, -pvec.z, -pvec.w), verbose);
		Assertv(vec.equals(-nvec), verbose);
	}
	{ // equality operators
		Assertv(Vec4<int>::Zero == 0, verbose);
		Assertv(Vec4<int>::Identity == 1, verbose);
		Assertv(Vec4<int>::Zero == Vec4<int>::Zero, verbose);
		Assertv(Vec4<int>::Identity == Vec4<int>::Identity, verbose);
		Assertv(!(Vec4<int>::Zero != 0), verbose);
		Assertv(!(Vec4<int>::Identity != 1), verbose);
		Assertv(!(Vec4<int>::Zero != Vec4<int>::Zero), verbose);
		Assertv(!(Vec4<int>::Identity != Vec4<int>::Identity), verbose);
		Vec4<int> vec(3, 4, 324, 45), vec2(1, 0, 324, 45);
		Assertv(vec.equals(3, 4, 324, 45), verbose);
		Assertv(vec.equals(vec), verbose);
		Assertv(!vec.equals(vec2), verbose);
		Assertv(!vec.notEquals(3, 4, 324, 45), verbose);
		Assertv(!vec.notEquals(vec), verbose);
		Assertv(vec.notEquals(vec2), verbose);
	}
	{ // arthimetic operators
		{ // addition
			const int lval_x = 12, lval_y = 131, lval_z = 0, lval_w = 32;
			const int rval_x = 4, rval_y = 12314, rval_z = 344, rval_w = 89;
			const Vec4<int> lvec(lval_x, lval_y, lval_z, lval_w), rvec(rval_x, rval_y, rval_z, rval_w);
			Vec4<int> vec = lvec + rvec;
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
			const int lval_x = 12, lval_y = 131, lval_z = 0, lval_w = 32;
			const int rval_x = 4, rval_y = 12314, rval_z = 344, rval_w = 89;
			const Vec4<int> lvec(lval_x, lval_y, lval_z, lval_w), rvec(rval_x, rval_y, rval_z, rval_w);
			Vec4<int> vec = lvec - rvec;
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
			const int lval_x = 12, lval_y = 131, lval_z = 0, lval_w = 32;
			const int rval_x = 4, rval_y = 12314, rval_z = 344, rval_w = 89;
			const Vec4<int> lvec(lval_x, lval_y, lval_z, lval_w), rvec(rval_x, rval_y, rval_z, rval_w);
			Vec4<int> vec = lvec * rvec;
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
			const int lval_x = 12, lval_y = 131, lval_z = 0, lval_w = 32;
			const int rval_x = 4, rval_y = 12314, rval_z = 344, rval_w = 89;
			const Vec4<int> lvec(lval_x, lval_y, lval_z, lval_w), rvec(rval_x, rval_y, rval_z, rval_w);
			Vec4<int> vec = lvec / rvec;
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

	if(Assert::_num_failed_tests <= 0)
		printf("ALL GOOD!\n");
	else
	{
		puts("----------------------------------------");
		printf("# %d Failed!\n", Assert::_num_failed_tests);
	}
	return Assert::_num_failed_tests;
}