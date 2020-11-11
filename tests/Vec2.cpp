#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include "Assert.hpp"
#include <axl.math/lib.hpp>
#include <axl.math/Vec2.hpp>

int main(int argc, char *argv[])
{
	bool verbose = argc > 1 && (0 == strcmp(argv[1], "-v") || 0 == strcmp(argv[1], "--verbose"));
	using namespace axl;
	using namespace axl::math;
	printf("library version: %u %u %u\n", lib::version.major, lib::version.minor, lib::version.patch);
	{ // static values
		Assertv((0 ==  Vec2<int>::Zero.x), verbose);
		Assertv((0 ==  Vec2<int>::Zero.y), verbose);
		Assertv((1 ==  Vec2<int>::Identity.x), verbose);
		Assertv((1 ==  Vec2<int>::Identity.y), verbose);
		Assertv(Vec2<int>::Default.equals(0, 0), verbose);
	}
	{ // constructors
		{ // default constructor
			{
				Assertv(Vec2<int>::Default.equals(Vec2<int>::Zero), verbose);
				Vec2<int> vec;
				Assertv((Vec2<int>::Default.x ==  vec.x), verbose);
				Assertv((Vec2<int>::Default.y ==  vec.y), verbose);
			}
			{
				Vec2<int>::Default = Vec2<int>::Identity;
				Assertv(Vec2<int>::Default.equals(Vec2<int>::Identity), verbose);
				Vec2<int> vec;
				Assertv(vec.equals(Vec2<int>::Identity), verbose);
				Assertv((Vec2<int>::Default.x ==  vec.x), verbose);
				Assertv((Vec2<int>::Default.y ==  vec.y), verbose);
				Vec2<int>::Default = Vec2<int>::Zero;
				Assertv(Vec2<int>::Default.equals(Vec2<int>::Zero), verbose);
			}
		}
		{ // values constructor
			Vec2<int> vec(314, 672);
			Assertv((314 ==  vec.x), verbose);
			Assertv((672 ==  vec.y), verbose);
		}
		{ // copy constructor
			Vec2<int> vec(314, 672);
			Assertv((314 ==  vec.x), verbose);
			Assertv((672 ==  vec.y), verbose);
			Vec2<int> vec1(vec);
			Assertv((314 ==  vec1.x), verbose);
			Assertv((672 ==  vec1.y), verbose);
			Vec2<int> vec2 = vec;
			Assertv((314 ==  vec2.x), verbose);
			Assertv((672 ==  vec2.y), verbose);
			Vec2<float> vec3 = vec;
			Assertv((314.0f ==  vec3.x), verbose);
			Assertv((672.0f ==  vec3.y), verbose);
		}
	}
	{ // unary operators
		const Vec2<int> vec(34, 56);
		const Vec2<int> pvec = +vec;
		const Vec2<int> nvec = -vec;
		Assertv(pvec.equals(pvec), verbose);
		Assertv(nvec.equals(-pvec.x, -pvec.y), verbose);
		Assertv(vec.equals(-nvec), verbose);
	}
	{ // equality operators
		Assertv(Vec2<int>::Zero == 0, verbose);
		Assertv(Vec2<int>::Identity == 1, verbose);
		Assertv(Vec2<int>::Zero == Vec2<int>::Zero, verbose);
		Assertv(Vec2<int>::Identity == Vec2<int>::Identity, verbose);
		Assertv(!(Vec2<int>::Zero != 0), verbose);
		Assertv(!(Vec2<int>::Identity != 1), verbose);
		Assertv(!(Vec2<int>::Zero != Vec2<int>::Zero), verbose);
		Assertv(!(Vec2<int>::Identity != Vec2<int>::Identity), verbose);
		Vec2<int> vec(345, 45), vec2(123, 987);
		Assertv(vec.equals(345, 45), verbose);
		Assertv(vec.equals(vec), verbose);
		Assertv(!vec.equals(vec2), verbose);
		Assertv(!vec.notEquals(345, 45), verbose);
		Assertv(!vec.notEquals(vec), verbose);
		Assertv(vec.notEquals(vec2), verbose);
	}
	{ // arthimetic operators
		{ // addition
			const int lval_x = 123, lval_y = 131, rval_x = 456, rval_y = 123;
			const Vec2<int> lvec(lval_x, lval_y), rvec(rval_x, rval_y);
			Vec2<int> vec = lvec + rvec;
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
			const int lval_x = 123, lval_y = 131, rval_x = 456, rval_y = 123;
			const Vec2<int> lvec(lval_x, lval_y), rvec(rval_x, rval_y);
			Vec2<int> vec = lvec - rvec;
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
			const int lval_x = 123, lval_y = 131, rval_x = 456, rval_y = 123;
			const Vec2<int> lvec(lval_x, lval_y), rvec(rval_x, rval_y);
			Vec2<int> vec = lvec * rvec;
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
			const int lval_x = 123, lval_y = 131, rval_x = 456, rval_y = 123;
			const Vec2<int> lvec(lval_x, lval_y), rvec(rval_x, rval_y);
			Vec2<int> vec = lvec / rvec;
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
	if(verbose) {
		puts("----------------------------------------");
		if(Assert::_num_failed_tests <= 0) printf("# All Good!\n", Assert::_num_failed_tests);
		else printf("# %d Failed!\n", Assert::_num_failed_tests);
	}
	return Assert::_num_failed_tests;
}