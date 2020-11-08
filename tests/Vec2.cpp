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
	if(verbose) {
		puts("----------------------------------------");
		if(Assert::_num_failed_tests <= 0) printf("# All Good!\n", Assert::_num_failed_tests);
		else printf("# %d Failed!\n", Assert::_num_failed_tests);
	}
	return Assert::_num_failed_tests;
}