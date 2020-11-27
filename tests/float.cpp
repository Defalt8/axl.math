#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "Assert.hpp"
#include "lib.hpp"
#include <axl.math/float.hpp>

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
	Assertv(Float::equals(Float::PosInf, Float::PosInf), verbose);
	Assertv(Float::equals(Float::NegInf, Float::NegInf), verbose);
	Assertv(!Float::equals(Float::PosInf, Float::NegInf), verbose);
	Assertv(!Float::equals(Float::NegInf, Float::PosInf), verbose);
	Assertv(!Float::equals(Float::NegInf, Float::Nan), verbose);
	Assertv(!Float::equals(Float::Nan, Float::PosInf), verbose);
	// Float::isNan tests
	Assertv(Float::isNan(Float::Nan), verbose);
	Assertv(!Float::isNan(0.0f), verbose);
	Assertv(!Float::isNan(12312.56753f), verbose);
	Assertv(!Float::isNan(Float::NegInf), verbose);
	Assertv(!Float::isNan(Float::PosInf), verbose);
	// Float::isFinite tests
	Assertv(Float::isFinite(0.0f), verbose);
	Assertv(Float::isFinite(2434.0543545f), verbose);
	Assertv(!Float::isFinite(Float::PosInf), verbose);
	Assertv(!Float::isFinite(Float::NegInf), verbose);
	Assertv(!Float::isFinite(Float::Nan), verbose);
	// Float::isInfinite tests
	Assertv(Float::isInfinite(Float::PosInf), verbose);
	Assertv(Float::isInfinite(Float::NegInf), verbose);
	Assertv(!Float::isInfinite(Float::Nan), verbose);
	Assertv(!Float::isInfinite(-Float::Nan), verbose);
	Assertv(!Float::isInfinite(0.0f), verbose);
	Assertv(!Float::isInfinite(21312.412f), verbose);
	// Float::isPosInfinity tests
	Assertv(Float::isPosInfinity(Float::PosInf), verbose);
	Assertv(!Float::isPosInfinity(Float::NegInf), verbose);
	Assertv(!Float::isPosInfinity(0.0f), verbose);
	Assertv(!Float::isPosInfinity(2434.0543545f), verbose);
	// Float::NegInfinity tests
	Assertv(Float::isNegInfinity(Float::NegInf), verbose);
	Assertv(!Float::isNegInfinity(Float::PosInf), verbose);
	Assertv(!Float::isNegInfinity(0.0f), verbose);
	Assertv(!Float::isNegInfinity(2434.0543545f), verbose);

	if(Assert::_num_failed_tests <= 0)
		printf("ALL GOOD!\n");
	else
	{
		puts("----------------------------------------");
		printf("# %d Failed!\n", Assert::_num_failed_tests);
	}
	return Assert::_num_failed_tests;
}