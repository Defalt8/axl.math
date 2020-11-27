#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "Assert.hpp"
#include "lib.hpp"
#include <axl.math/float.hpp>

const static float Float::Nan = _fzero / _fzero;

int main(int argc, char *argv[])
{
	bool verbose = argc > 1 && (0 == strcmp(argv[1], "-v") || 0 == strcmp(argv[1], "--verbose"));
	using namespace axl;
	using namespace axl::math;
	printf("axl.math - version %hu.%hu.%hu  %s %s\n", lib::VERSION.major, lib::VERSION.minor, lib::VERSION.patch, libType(lib::LIBRARY_TYPE), buildType(lib::BUILD_TYPE));
	puts("----------------------------------------");
	// Float::Equals tests
	Assertv(Float::equals(0.0f, 0.0f), verbose);
	Assertv(Float::equals(19821412.5673453f, 19821412.5673453f), verbose);
	Assertv(!Float::equals(123123.6876123f, 324324.23423f), verbose);
	Assertv(Float::equals(Float::Nan, Float::Nan), verbose);
	Assertv(!Float::equals(0.0f, Float::Nan), verbose);
	Assertv(Float::equals(1.0f/_fzero, 1.0f/_fzero), verbose);
	Assertv(Float::equals(-1.0f/_fzero, -1.0f/_fzero), verbose);
	Assertv(!Float::equals(1.0f/_fzero, -1.0f/_fzero), verbose);
	Assertv(!Float::equals(-1.0f/_fzero, 1.0f/_fzero), verbose);
	Assertv(!Float::equals(-1.0f/_fzero, Float::Nan), verbose);
	Assertv(!Float::equals(Float::Nan, 1.0f/_fzero), verbose);
	// Float::isNan tests
	Assertv(Float::isNan(Float::Nan), verbose);
	Assertv(!Float::isNan(0.0f), verbose);
	Assertv(!Float::isNan(12312.56753f), verbose);
	Assertv(!Float::isNan(-1.0f/_fzero), verbose);
	Assertv(!Float::isNan(1.0f/_fzero), verbose);
	// Float::isFinite tests
	Assertv(Float::isFinite(0.0f), verbose);
	Assertv(Float::isFinite(2434.0543545f), verbose);
	Assertv(!Float::isFinite(1.0f/_fzero), verbose);
	Assertv(!Float::isFinite(-1.0f/_fzero), verbose);
	Assertv(!Float::isFinite(Float::Nan), verbose);
	// Float::isInfinite tests
	Assertv(Float::isInfinite(1.0f/_fzero), verbose);
	Assertv(Float::isInfinite(-1.0f/_fzero), verbose);
	Assertv(!Float::isInfinite(Float::Nan), verbose);
	Assertv(!Float::isInfinite(-Float::Nan), verbose);
	Assertv(!Float::isInfinite(0.0f), verbose);
	Assertv(!Float::isInfinite(21312.412f), verbose);
	// Float::isPosInfinity tests
	Assertv(Float::isPosInfinity(1.0f/_fzero), verbose);
	Assertv(!Float::isPosInfinity(-1.0f/_fzero), verbose);
	Assertv(!Float::isPosInfinity(0.0f), verbose);
	Assertv(!Float::isPosInfinity(2434.0543545f), verbose);
	// Float::NegInfinity tests
	Assertv(Float::isNegInfinity(-1.0f/_fzero), verbose);
	Assertv(!Float::isNegInfinity(1.0f/_fzero), verbose);
	Assertv(!Float::isNegInfinity(0.0f), verbose);
	Assertv(!Float::isNegInfinity(2434.0543545f), verbose);

	if(Assert::_num_failed_tests <= 0)
		printf("# All Good!\n", Assert::_num_failed_tests);
	else
	{
		puts("----------------------------------------");
		printf("# %d Failed!\n", Assert::_num_failed_tests);
	}
	return Assert::_num_failed_tests;
}