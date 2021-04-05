#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "Assert.hpp"
#include "lib.hpp"
#include <axl.math/float.hpp>
#include <axl.math/double.hpp>
#include <axl.math/util.hpp>

int main(int argc, char *argv[])
{
	bool verbose = argc > 1 && (0 == strcmp(argv[1], "-v") || 0 == strcmp(argv[1], "--verbose"));
	using namespace axl;
	using namespace axl::math;
	using namespace axl::math;
	printf("axl.math - version %hu.%hu.%hu  %s %s\n", lib::VERSION.major, lib::VERSION.minor, lib::VERSION.patch, libType(lib::LIBRARY_TYPE), buildType(lib::BUILD_TYPE));
	puts("----------------------------------------");
	{ // clamp
		{ // float
			Assertv(axl::math::clamp(0.0f, 0.0f, 1.0f) == 0.0f, verbose);
			Assertv(Float::equals(axl::math::clamp(0.0001f, 0.0f, 1.0f), 0.0001f, 0.0001f), verbose);
			Assertv(Float::equals(axl::math::clamp(0.9999f, 0.0f, 1.0f), 0.9999f, 0.0001f), verbose);
			Assertv(axl::math::clamp(0.5f, 0.0f, 1.0f) == 0.5f, verbose);
			Assertv(axl::math::clamp(1.0f, 0.0f, 1.0f) == 1.0f, verbose);
			Assertv(axl::math::clamp(0.0f, 1.0f, 1.0f) == 1.0f, verbose);
			Assertv(axl::math::clamp(1.0f, 1.0f, 1.0f) == 1.0f, verbose);
			Assertv(axl::math::clamp(2.0f, 1.0f, 1.0f) == 1.0f, verbose);
		}
		{ // double
			Assertv(axl::math::clamp(0.0, 0.0, 1.0) == 0.0, verbose);
			Assertv(Double::equals(axl::math::clamp(0.0001, 0.0, 1.0), 0.0001, 0.000001), verbose);
			Assertv(Double::equals(axl::math::clamp(0.9999, 0.0, 1.0), 0.9999, 0.000001), verbose);
			Assertv(axl::math::clamp(0.5, 0.0, 1.0) == 0.5, verbose);
			Assertv(axl::math::clamp(1.0, 0.0, 1.0) == 1.0, verbose);
			Assertv(axl::math::clamp(0.0, 1.0, 1.0) == 1.0, verbose);
			Assertv(axl::math::clamp(1.0, 1.0, 1.0) == 1.0, verbose);
			Assertv(axl::math::clamp(2.0, 1.0, 1.0) == 1.0, verbose);
		}
	}
	{ // map
		{ // float
			Assertv(map(0, 0, 255, -1.0f, 1.0f) == -1.0, verbose);
			Assertv(Float::equals(map(32, 0, 255, -1.0f, 1.0f), -0.74902f, 0.0001f), verbose);
			Assertv(Float::equals(map(127, 0, 255, -1.0f, 1.0f), -0.00392f, 0.0001f), verbose);
			Assertv(map(255, 0, 255, -1.0f, 1.0f) == 1.0f, verbose);
			Assertv(Float::equals(map(50, 0, 100, 1.0f, 3.0f), 2.0f, 0.0001f), verbose);
		}
		{ // double
			Assertv(axl::math::map(0, 0, 255, -1.0, 1.0) == -1.0, verbose);
			Assertv(Double::equals(axl::math::map(32, 0, 255, -1.0, 1.0), -0.749019, 0.000001), verbose);
			Assertv(Double::equals(axl::math::map(127, 0, 255, -1.0, 1.0), -0.003922, 0.000001), verbose);
			Assertv(axl::math::map(255, 0, 255, -1.0, 1.0) == 1.0, verbose);
			Assertv(Double::equals(axl::math::map(50, 0, 100, 1.0, 3.0), 2.0, 0.000001), verbose);
		}
	}
	{ // round
		{ // float
			Assertv(Float::equals(axl::math::round(56.0f), 56.0f, 0.0001f), verbose);
			Assertv(Float::equals(axl::math::round(56.15f), 56.0f, 0.0001f), verbose);
			Assertv(Float::equals(axl::math::round(56.5f), 57.0f, 0.0001f), verbose);
			Assertv(Float::equals(axl::math::round(12.50f), 13.0f, 0.0001f), verbose);
			Assertv(Float::equals(axl::math::round(12.49f), 12.0f, 0.0001f), verbose);
			Assertv(Float::equals(axl::math::round(12.99f), 13.0f, 0.0001f), verbose);
		}
		{ // double
			Assertv(Double::equals(axl::math::round(56.0), 56.0, 0.000001), verbose);
			Assertv(Double::equals(axl::math::round(56.15), 56.0, 0.000001), verbose);
			Assertv(Double::equals(axl::math::round(56.5), 57.0, 0.000001), verbose);
			Assertv(Double::equals(axl::math::round(12.50), 13.0, 0.000001), verbose);
			Assertv(Double::equals(axl::math::round(12.49), 12.0, 0.000001), verbose);
			Assertv(Double::equals(axl::math::round(12.99), 13.0, 0.000001), verbose);
		}
	}
	{ // floor
		{ // float
			Assertv(Float::equals(axl::math::floor(56.0f), 56.0f, 0.0001f), verbose);
			Assertv(Float::equals(axl::math::floor(56.15f), 56.0f, 0.0001f), verbose);
			Assertv(Float::equals(axl::math::floor(56.5f), 56.0f, 0.0001f), verbose);
			Assertv(Float::equals(axl::math::floor(12.50f), 12.0f, 0.0001f), verbose);
			Assertv(Float::equals(axl::math::floor(12.49f), 12.0f, 0.0001f), verbose);
			Assertv(Float::equals(axl::math::floor(12.99f), 12.0f, 0.0001f), verbose);
		}
		{ // double
			Assertv(Double::equals(axl::math::floor(56.0), 56.0, 0.000001), verbose);
			Assertv(Double::equals(axl::math::floor(56.15), 56.0, 0.000001), verbose);
			Assertv(Double::equals(axl::math::floor(56.5), 56.0, 0.000001), verbose);
			Assertv(Double::equals(axl::math::floor(12.50), 12.0, 0.000001), verbose);
			Assertv(Double::equals(axl::math::floor(12.49), 12.0, 0.000001), verbose);
			Assertv(Double::equals(axl::math::floor(12.99), 12.0, 0.000001), verbose);
		}
	}
	{ // ceil
		{ // float
			Assertv(Float::equals(axl::math::ceil(56.0f), 56.0f, 0.0001f), verbose);
			Assertv(Float::equals(axl::math::ceil(56.15f), 57.0f, 0.0001f), verbose);
			Assertv(Float::equals(axl::math::ceil(56.5f), 57.0f, 0.0001f), verbose);
			Assertv(Float::equals(axl::math::ceil(12.50f), 13.0f, 0.0001f), verbose);
			Assertv(Float::equals(axl::math::ceil(12.49f), 13.0f, 0.0001f), verbose);
			Assertv(Float::equals(axl::math::ceil(12.99f), 13.0f, 0.0001f), verbose);
		}
		{ // double
			Assertv(Double::equals(axl::math::ceil(56.0), 56.0, 0.000001), verbose);
			Assertv(Double::equals(axl::math::ceil(56.15), 57.0, 0.000001), verbose);
			Assertv(Double::equals(axl::math::ceil(56.5), 57.0, 0.000001), verbose);
			Assertv(Double::equals(axl::math::ceil(12.50), 13.0, 0.000001), verbose);
			Assertv(Double::equals(axl::math::ceil(12.49), 13.0, 0.000001), verbose);
			Assertv(Double::equals(axl::math::ceil(12.99), 13.0, 0.000001), verbose);
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