#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include "../Assert.hpp"
#include "../lib.hpp"
#include <axl.math/vec/Vec3.hpp>

int main(int argc, char *argv[])
{
	bool verbose = argc > 1 && (0 == strcmp(argv[1], "-v") || 0 == strcmp(argv[1], "--verbose"));
	using namespace axl;
	using namespace axl::math;
	printf("axl.math - version %hu.%hu.%hu  %s %s\n", lib::VERSION.major, lib::VERSION.minor, lib::VERSION.patch, libType(lib::LIBRARY_TYPE), buildType(lib::BUILD_TYPE));
	puts("----------------------------------------");
	{ // static values
		Assertv((0 == Vec3<int>::Zero.x), verbose);
		Assertv((0 == Vec3<int>::Zero.y), verbose);
		Assertv((0 == Vec3<int>::Zero.z), verbose);
		Assertv((1 == Vec3<int>::Identity.x), verbose);
		Assertv((1 == Vec3<int>::Identity.y), verbose);
		Assertv((1 == Vec3<int>::Identity.z), verbose);
		Assertv(Vec3<int>::filled(69).equals(69, 69, 69), verbose);
		Assertv(Vec3<int>::Default.equals(0, 0, 0), verbose);
	}
	{ // constructors
		{ // default constructor
			{
				Assertv(Vec3<int>::Default.equals(Vec3<int>::Zero), verbose);
				Vec3<int> vec;
				Assertv((Vec3<int>::Default.x == vec.x), verbose);
				Assertv((Vec3<int>::Default.y == vec.y), verbose);
				Assertv((Vec3<int>::Default.z == vec.z), verbose);
			}
			{
				Vec3<int>::Default = Vec3<int>::Identity;
				Assertv(Vec3<int>::Default.equals(Vec3<int>::Identity), verbose);
				Vec3<int> vec;
				Assertv(vec.equals(Vec3<int>::Identity), verbose);
				Assertv((Vec3<int>::Default.x == vec.x), verbose);
				Assertv((Vec3<int>::Default.y == vec.y), verbose);
				Assertv((Vec3<int>::Default.z == vec.z), verbose);
				Vec3<int>::Default = Vec3<int>::Zero;
				Assertv(Vec3<int>::Default.equals(Vec3<int>::Zero), verbose);
			}
		}
		{ // values constructor
			Vec3<int> vec(3, 0, 456);
			Assertv((3 == vec.x), verbose);
			Assertv((0 == vec.y), verbose);
			Assertv((456 == vec.z), verbose);
		}
		{ // copy constructor
			{
				Vec3<int> vec(3, 0, 456);
				Assertv((3 == vec.x), verbose);
				Assertv((0 == vec.y), verbose);
				Assertv((456 == vec.z), verbose);
				Vec3<int> vec1(vec);
				Assertv((3 == vec1.x), verbose);
				Assertv((0 == vec1.y), verbose);
				Assertv((456 == vec1.z), verbose);
				Vec3<int> vec2 = vec;
				Assertv((3 == vec2.x), verbose);
				Assertv((0 == vec2.y), verbose);
				Assertv((456 == vec2.z), verbose);
				Vec3<float> vec3 = vec;
				Assertv((3 == vec3.x), verbose);
				Assertv((0 == vec3.y), verbose);
				Assertv((456 == vec3.z), verbose);
			}
			{
				const Vec2<short> vec2(1, 3);
				Assertv(vec2.equals(1, 3), verbose);
				{
					const Vec3<int> vec3(vec2);
					Assertv(vec3.equals(1, 3, 0), verbose);
				}
				{
					const Vec3<int> vec3(vec2, 6);
					Assertv(vec3.equals(1, 3, 6), verbose);
				}
			}
		}
	}
	{ // array mode referencing
		const Vec3<int> vec(1,2,3);
		Assertv(vec.equals(1,2,3), verbose);
		Assertv(&(&vec.x)[0] == &vec.x, verbose);
		Assertv(&(&vec.x)[1] == &vec.y, verbose);
		Assertv(&(&vec.x)[2] == &vec.z, verbose);
		Assertv(vec.equals((&vec.x)[0],(&vec.x)[1],(&vec.x)[2]), verbose);
	}
	{ // unary operators
		const Vec3<int> vec(3, 5, 1);
		const Vec3<int> pvec = +vec;
		const Vec3<int> nvec = -vec;
		Assertv(pvec.equals(pvec), verbose);
		Assertv(nvec.equals(-pvec.x, -pvec.y, -pvec.z), verbose);
		Assertv(vec.equals(-nvec), verbose);
	}
	{ // equality operators
		Assertv(Vec3<int>::Zero == 0, verbose);
		Assertv(Vec3<int>::Identity == 1, verbose);
		Assertv(Vec3<int>::Zero == Vec3<int>::Zero, verbose);
		Assertv(Vec3<int>::Identity == Vec3<int>::Identity, verbose);
		Assertv(!(Vec3<int>::Zero != 0), verbose);
		Assertv(!(Vec3<int>::Identity != 1), verbose);
		Assertv(!(Vec3<int>::Zero != Vec3<int>::Zero), verbose);
		Assertv(!(Vec3<int>::Identity != Vec3<int>::Identity), verbose);
		Vec3<int> vec(3, 4, 324), vec2(1, 0, 324);
		Assertv(vec.equals(3, 4, 324), verbose);
		Assertv(vec.equals(vec), verbose);
		Assertv(!vec.equals(vec2), verbose);
		Assertv(!vec.notEquals(3, 4, 324), verbose);
		Assertv(!vec.notEquals(vec), verbose);
		Assertv(vec.notEquals(vec2), verbose);
	}
	{ // arthimetic operators
		{ // addition
			const int lval_x = 12, lval_y = 131, lval_z = 0;
			const int rval_x = 4, rval_y = 12314, rval_z = 344;
			const Vec3<int> lvec(lval_x, lval_y, lval_z), rvec(rval_x, rval_y, rval_z);
			Vec3<int> vec = lvec + rvec;
			Assertv(vec.equals(lval_x + rval_x, lval_y + rval_y, lval_z + rval_z), verbose);
			
			vec = lvec + rval_y;
			Assertv(vec.equals(lval_x + rval_y, lval_y + rval_y, lval_z + rval_y), verbose);
			vec = lval_x + rvec;
			Assertv(vec.equals(lval_x + rval_x, lval_x + rval_y, lval_x + rval_z), verbose);

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
			const int lval_x = 12, lval_y = 131, lval_z = 0;
			const int rval_x = 4, rval_y = 12314, rval_z = 344;
			const Vec3<int> lvec(lval_x, lval_y, lval_z), rvec(rval_x, rval_y, rval_z);
			Vec3<int> vec = lvec - rvec;
			Assertv(vec.equals(lval_x - rval_x, lval_y - rval_y, lval_z - rval_z), verbose);
			
			vec = lvec - rval_y;
			Assertv(vec.equals(lval_x - rval_y, lval_y - rval_y, lval_z - rval_y), verbose);
			vec = lval_x - rvec;
			Assertv(vec.equals(lval_x - rval_x, lval_x - rval_y, lval_x - rval_z), verbose);

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
			const int lval_x = 12, lval_y = 131, lval_z = 0;
			const int rval_x = 4, rval_y = 12314, rval_z = 344;
			const Vec3<int> lvec(lval_x, lval_y, lval_z), rvec(rval_x, rval_y, rval_z);
			Vec3<int> vec = lvec * rvec;
			Assertv(vec.equals(lval_x * rval_x, lval_y * rval_y, lval_z * rval_z), verbose);
			
			vec = lvec * rval_y;
			Assertv(vec.equals(lval_x * rval_y, lval_y * rval_y, lval_z * rval_y), verbose);
			vec = lval_x * rvec;
			Assertv(vec.equals(lval_x * rval_x, lval_x * rval_y, lval_x * rval_z), verbose);

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
			const int lval_x = 12, lval_y = 131, lval_z = 0;
			const int rval_x = 4, rval_y = 12314, rval_z = 344;
			const Vec3<int> lvec(lval_x, lval_y, lval_z), rvec(rval_x, rval_y, rval_z);
			Vec3<int> vec = lvec / rvec;
			Assertv(vec.equals(lval_x / rval_x, lval_y / rval_y, lval_z / rval_z), verbose);
			
			vec = lvec / rval_y;
			Assertv(vec.equals(lval_x / rval_y, lval_y / rval_y, lval_z / rval_y), verbose);
			vec = lval_x / rvec;
			Assertv(vec.equals(lval_x / rval_x, lval_x / rval_y, lval_x / rval_z), verbose);

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

	if(assert::_num_failed_tests <= 0)
		printf("ALL GOOD!\n");
	else
	{
		puts("----------------------------------------");
		printf("# %d Failed!\n", assert::_num_failed_tests);
	}
	return assert::_num_failed_tests;
}