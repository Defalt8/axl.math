#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include "../Assert.hpp"
#include "../lib.hpp"
#include <axl.math/vec/Vec2i.hpp>

int main(int argc, char *argv[])
{
	bool verbose = argc > 1 && (0 == strcmp(argv[1], "-v") || 0 == strcmp(argv[1], "--verbose"));
	using namespace axl;
	using namespace axl::math;
	printf("axl.math - version %hu.%hu.%hu  %s %s\n", lib::VERSION.major, lib::VERSION.minor, lib::VERSION.patch, libType(lib::LIBRARY_TYPE), buildType(lib::BUILD_TYPE));
	puts("----------------------------------------");
	{ // static values
		Assertv((0 ==  Vec2i::Zero.x), verbose);
		Assertv((0 ==  Vec2i::Zero.y), verbose);
		Assertv((1 ==  Vec2i::Identity.x), verbose);
		Assertv((1 ==  Vec2i::Identity.y), verbose);
		Assertv(Vec2i::filled(69).equals(69, 69), verbose);
		Assertv(Vec2i::Default.equals(0, 0), verbose);
	}
	{ // constructors
		{ // default constructor
			{
				Assertv(Vec2i::Default.equals(Vec2i::Zero), verbose);
				Vec2i vec;
				Assertv((Vec2i::Default.x ==  vec.x), verbose);
				Assertv((Vec2i::Default.y ==  vec.y), verbose);
			}
			{
				Vec2i::Default = Vec2i::Identity;
				Assertv(Vec2i::Default.equals(Vec2i::Identity), verbose);
				Vec2i vec;
				Assertv(vec.equals(Vec2i::Identity), verbose);
				Assertv((Vec2i::Default.x ==  vec.x), verbose);
				Assertv((Vec2i::Default.y ==  vec.y), verbose);
				Vec2i::Default = Vec2i::Zero;
				Assertv(Vec2i::Default.equals(Vec2i::Zero), verbose);
			}
		}
		{ // values constructor
			Vec2i vec(314, 672);
			Assertv((314 ==  vec.x), verbose);
			Assertv((672 ==  vec.y), verbose);
		}
		{ // copy constructor
			Vec2i vec(314, 672);
			Assertv((314 ==  vec.x), verbose);
			Assertv((672 ==  vec.y), verbose);
			Vec2i vec1(vec);
			Assertv((314 ==  vec1.x), verbose);
			Assertv((672 ==  vec1.y), verbose);
			Vec2i vec2 = vec;
			Assertv((314 ==  vec2.x), verbose);
			Assertv((672 ==  vec2.y), verbose);
		}
	}
	{ // array mode referencing
		const Vec2i vec(1,2);
		Assertv(vec.equals(1,2), verbose);
		Assertv(&(&vec.x)[0] == &vec.x, verbose);
		Assertv(&(&vec.x)[1] == &vec.y, verbose);
		Assertv(vec.equals((&vec.x)[0],(&vec.x)[1]), verbose);
	}
	{ // unary operators
		const Vec2i vec(34, 56);
		const Vec2i pvec = +vec;
		const Vec2i nvec = -vec;
		Assertv(pvec.equals(pvec), verbose);
		Assertv(nvec.equals(-pvec.x, -pvec.y), verbose);
		Assertv(vec.equals(-nvec), verbose);
	}
	{ // equality operators
		Assertv(Vec2i::Zero == 0, verbose);
		Assertv(Vec2i::Identity == 1, verbose);
		Assertv(Vec2i::Zero == Vec2i::Zero, verbose);
		Assertv(Vec2i::Identity == Vec2i::Identity, verbose);
		Assertv(!(Vec2i::Zero != 0), verbose);
		Assertv(!(Vec2i::Identity != 1), verbose);
		Assertv(!(Vec2i::Zero != Vec2i::Zero), verbose);
		Assertv(!(Vec2i::Identity != Vec2i::Identity), verbose);
		Vec2i vec(345, 45), vec2(123, 987);
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
			const Vec2i lvec(lval_x, lval_y), rvec(rval_x, rval_y);
			Vec2i vec = lvec + rvec;
			Assertv(vec.equals(lval_x + rval_x, lval_y + rval_y), verbose);
			
			vec = lvec + rval_y;
			Assertv(vec.equals(lval_x + rval_y, lval_y + rval_y), verbose);

			vec = lval_y + rvec;
			Assertv(vec.equals(lval_y + rval_x, lval_y + rval_y), verbose);

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
			const Vec2i lvec(lval_x, lval_y), rvec(rval_x, rval_y);
			Vec2i vec = lvec - rvec;
			Assertv(vec.equals(lval_x - rval_x, lval_y - rval_y), verbose);
			
			vec = lvec - rval_y;
			Assertv(vec.equals(lval_x - rval_y, lval_y - rval_y), verbose);

			vec = lval_y - rvec;
			Assertv(vec.equals(lval_y - rval_x, lval_y - rval_y), verbose);

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
			const Vec2i lvec(lval_x, lval_y), rvec(rval_x, rval_y);
			Vec2i vec = lvec * rvec;
			Assertv(vec.equals(lval_x * rval_x, lval_y * rval_y), verbose);
			
			vec = lvec * rval_y;
			Assertv(vec.equals(lval_x * rval_y, lval_y * rval_y), verbose);
			
			vec = lval_y * rvec;
			Assertv(vec.equals(lval_y * rval_x, lval_y * rval_y), verbose);

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
			const Vec2i lvec(lval_x, lval_y), rvec(rval_x, rval_y);
			Vec2i vec = lvec / rvec;
			Assertv(vec.equals(lval_x / rval_x, lval_y / rval_y), verbose);
			
			vec = lvec / rval_y;
			Assertv(vec.equals(lval_x / rval_y, lval_y / rval_y), verbose);
			
			vec = lval_y / rvec;
			Assertv(vec.equals(lval_y / rval_x, lval_y / rval_y), verbose);

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

	if(Assert::_num_failed_tests <= 0)
		printf("ALL GOOD!\n");
	else
	{
		puts("----------------------------------------");
		printf("# %d Failed!\n", Assert::_num_failed_tests);
	}
	return Assert::_num_failed_tests;
}