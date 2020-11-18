#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "Assert.hpp"
#include "lib.hpp"
#include <axl.math/double.hpp>

float _zero = 0.0;
const static float _nan = _zero / _zero;

int main(int argc, char *argv[])
{
	bool verbose = argc > 1 && (0 == strcmp(argv[1], "-v") || 0 == strcmp(argv[1], "--verbose"));
	using namespace axl;
	using namespace axl::math;
	printf("axl.math - version %hu.%hu.%hu  %s %s\n", lib::VERSION.major, lib::VERSION.minor, lib::VERSION.patch, cstrLibType(lib::LIBRARY_TYPE), cstrBuildType(lib::BUILD_TYPE));
	puts("----------------------------------------");
	// Double::Equals tests
	Assertv(Double::equals(0.0, 0.0), verbose);
	Assertv(Double::equals(19821412.5673453, 19821412.5673453), verbose);
	Assertv(!Double::equals(123123.6876123, 324324.23423), verbose);
	Assertv(Double::equals(_nan, _nan), verbose);
	Assertv(!Double::equals(0.0, _nan), verbose);
	Assertv(Double::equals(1.0/_zero, 1.0/_zero), verbose);
	Assertv(Double::equals(-1.0/_zero, -1.0/_zero), verbose);
	Assertv(!Double::equals(1.0/_zero, -1.0/_zero), verbose);
	Assertv(!Double::equals(-1.0/_zero, 1.0/_zero), verbose);
	Assertv(!Double::equals(-1.0/_zero, _nan), verbose);
	Assertv(!Double::equals(_nan, 1.0/_zero), verbose);
	// // Double::isNan tests
	Assertv(Double::isNan(_nan), verbose);
	Assertv(!Double::isNan(0.0), verbose);
	Assertv(!Double::isNan(12312.56753), verbose);
	Assertv(!Double::isNan(-1.0/_zero), verbose);
	Assertv(!Double::isNan(1.0/_zero), verbose);
	// Double::isFinite tests
	Assertv(Double::isFinite(0.0), verbose);
	Assertv(Double::isFinite(2434.0543545), verbose);
	Assertv(!Double::isFinite(1.0/_zero), verbose);
	Assertv(!Double::isFinite(-1.0/_zero), verbose);
	Assertv(!Double::isFinite(_nan), verbose);
	// Double::isInfinite tests
	Assertv(Double::isInfinite(1.0/_zero), verbose);
	Assertv(Double::isInfinite(-1.0/_zero), verbose);
	Assertv(!Double::isInfinite(_nan), verbose);
	Assertv(!Double::isInfinite(-_nan), verbose);
	Assertv(!Double::isInfinite(0.0), verbose);
	Assertv(!Double::isInfinite(21312.412), verbose);
	// Double::isPosInfinity tests
	Assertv(Double::isPosInfinity(1.0/_zero), verbose);
	Assertv(!Double::isPosInfinity(-1.0/_zero), verbose);
	Assertv(!Double::isPosInfinity(0.0), verbose);
	Assertv(!Double::isPosInfinity(2434.0543545), verbose);
	// Double::NegInfinity tests
	Assertv(Double::isNegInfinity(-1.0/_zero), verbose);
	Assertv(!Double::isNegInfinity(1.0/_zero), verbose);
	Assertv(!Double::isNegInfinity(0.0), verbose);
	Assertv(!Double::isNegInfinity(2434.0543545), verbose);

	if(Assert::_num_failed_tests <= 0)
		printf("# All Good!\n", Assert::_num_failed_tests);
	else
	{
		puts("----------------------------------------");
		printf("# %d Failed!\n", Assert::_num_failed_tests);
	}
	return Assert::_num_failed_tests;
}