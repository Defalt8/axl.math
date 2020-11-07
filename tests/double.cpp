#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "Assert.hpp"
#include <axl.math/lib.hpp>
#include <axl.math/double.hpp>

int main(int argc, char *argv[])
{
	bool verbose = argc > 1 && (0 == strcmp(argv[1], "-v") || 0 == strcmp(argv[1], "--verbose"));
	using namespace axl;
	using namespace axl::math;
	printf("library version: %u %u %u\n", lib::version.major, lib::version.minor, lib::version.patch);
	// Double::Equals tests
	Assertv(Double::equals(0.0, 0.0), verbose);
	Assertv(Double::equals(19821412.5673453, 19821412.5673453), verbose);
	Assertv(!Double::equals(123123.6876123, 324324.23423), verbose);
	Assertv(Double::equals(0.0/0.0, 0.0/0.0), verbose);
	Assertv(!Double::equals(0.0, 0.0/0.0), verbose);
	Assertv(Double::equals(1.0/0.0, 1.0/0.0), verbose);
	Assertv(Double::equals(-1.0/0.0, -1.0/0.0), verbose);
	Assertv(!Double::equals(1.0/0.0, -1.0/0.0), verbose);
	Assertv(!Double::equals(-1.0/0.0, 1.0/0.0), verbose);
	Assertv(!Double::equals(-1.0/0.0, 0.0/0.0), verbose);
	Assertv(!Double::equals(0.0/0.0, 1.0/0.0), verbose);
	// // Double::isNan tests
	Assertv(Double::isNan(0.0/0.0), verbose);
	Assertv(!Double::isNan(0.0), verbose);
	Assertv(!Double::isNan(12312.56753), verbose);
	Assertv(!Double::isNan(-1.0/0.0), verbose);
	Assertv(!Double::isNan(1.0/0.0), verbose);
	// Double::isFinite tests
	Assertv(Double::isFinite(0.0), verbose);
	Assertv(Double::isFinite(2434.0543545), verbose);
	Assertv(!Double::isFinite(1.0/0.0), verbose);
	Assertv(!Double::isFinite(-1.0/0.0), verbose);
	Assertv(!Double::isFinite(0.0/0.0), verbose);
	// Double::isInfinite tests
	Assertv(Double::isInfinite(1.0/0.0), verbose);
	Assertv(Double::isInfinite(-1.0/0.0), verbose);
	Assertv(!Double::isInfinite(0.0/0.0), verbose);
	Assertv(!Double::isInfinite(-0.0/0.0), verbose);
	Assertv(!Double::isInfinite(0.0), verbose);
	Assertv(!Double::isInfinite(21312.412), verbose);
	// Double::isPosInfinity tests
	Assertv(Double::isPosInfinity(1.0/0.0), verbose);
	Assertv(!Double::isPosInfinity(-1.0/0.0), verbose);
	Assertv(!Double::isPosInfinity(0.0), verbose);
	Assertv(!Double::isPosInfinity(2434.0543545), verbose);
	// Double::NegInfinity tests
	Assertv(Double::isNegInfinity(-1.0/0.0), verbose);
	Assertv(!Double::isNegInfinity(1.0/0.0), verbose);
	Assertv(!Double::isNegInfinity(0.0), verbose);
	Assertv(!Double::isNegInfinity(2434.0543545), verbose);
	if(verbose) {
		puts("----------------------------------------");
		if(Assert::_num_failed_tests <= 0) printf("# All Good!\n", Assert::_num_failed_tests);
		else printf("# %d Failed!\n", Assert::_num_failed_tests);
	}
	return Assert::_num_failed_tests;
}