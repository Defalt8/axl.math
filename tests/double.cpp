#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "Assert.hpp"
#include "lib.hpp"
#include <axl.math/double.hpp>

int main(int argc, char *argv[])
{
	bool verbose = argc > 1 && (0 == strcmp(argv[1], "-v") || 0 == strcmp(argv[1], "--verbose"));
	using namespace axl;
	using namespace axl::math;
	printf("axl.math - version %hu.%hu.%hu  %s %s\n", lib::VERSION.major, lib::VERSION.minor, lib::VERSION.patch, libType(lib::LIBRARY_TYPE), buildType(lib::BUILD_TYPE));
	puts("----------------------------------------");
	// Double::Equals tests
	Assertv(Double::equals(0.0, 0.0), verbose);
	Assertv(Double::equals(19821412.5673453, 19821412.5673453), verbose);
	Assertv(!Double::equals(123123.6876123, 324324.23423), verbose);
	Assertv(Double::equals(Double::Nan, Double::Nan), verbose);
	Assertv(!Double::equals(0.0, Double::Nan), verbose);
	Assertv(Double::equals(Double::PosInf, Double::PosInf), verbose);
	Assertv(Double::equals(Double::NegInf, Double::NegInf), verbose);
	Assertv(!Double::equals(Double::PosInf, Double::NegInf), verbose);
	Assertv(!Double::equals(Double::NegInf, Double::PosInf), verbose);
	Assertv(!Double::equals(Double::NegInf, Double::Nan), verbose);
	Assertv(!Double::equals(Double::Nan, Double::PosInf), verbose);
	// // Double::isNan tests
	Assertv(Double::isNan(Double::Nan), verbose);
	Assertv(!Double::isNan(0.0), verbose);
	Assertv(!Double::isNan(12312.56753), verbose);
	Assertv(!Double::isNan(Double::NegInf), verbose);
	Assertv(!Double::isNan(Double::PosInf), verbose);
	// Double::isFinite tests
	Assertv(Double::isFinite(0.0), verbose);
	Assertv(Double::isFinite(2434.0543545), verbose);
	Assertv(!Double::isFinite(Double::PosInf), verbose);
	Assertv(!Double::isFinite(Double::NegInf), verbose);
	Assertv(!Double::isFinite(Double::Nan), verbose);
	// Double::isInfinite tests
	Assertv(Double::isInfinite(Double::PosInf), verbose);
	Assertv(Double::isInfinite(Double::NegInf), verbose);
	Assertv(!Double::isInfinite(Double::Nan), verbose);
	Assertv(!Double::isInfinite(-Double::Nan), verbose);
	Assertv(!Double::isInfinite(0.0), verbose);
	Assertv(!Double::isInfinite(21312.412), verbose);
	// Double::isPosInfinity tests
	Assertv(Double::isPosInfinity(Double::PosInf), verbose);
	Assertv(!Double::isPosInfinity(Double::NegInf), verbose);
	Assertv(!Double::isPosInfinity(0.0), verbose);
	Assertv(!Double::isPosInfinity(2434.0543545), verbose);
	// Double::NegInfinity tests
	Assertv(Double::isNegInfinity(Double::NegInf), verbose);
	Assertv(!Double::isNegInfinity(Double::PosInf), verbose);
	Assertv(!Double::isNegInfinity(0.0), verbose);
	Assertv(!Double::isNegInfinity(2434.0543545), verbose);

	if(Assert::_num_failed_tests <= 0)
		printf("ALL GOOD!\n");
	else
	{
		puts("----------------------------------------");
		printf("# %d Failed!\n", Assert::_num_failed_tests);
	}
	return Assert::_num_failed_tests;
}