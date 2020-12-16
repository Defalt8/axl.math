#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "Assert.hpp"
#include "lib.hpp"
#include <axl.math/constants.hpp>
#include <axl.math/float.hpp>
#include <axl.math/double.hpp>
#include <axl.math/angle.hpp>

int main(int argc, char *argv[])
{
	bool verbose = argc > 1 && (0 == strcmp(argv[1], "-v") || 0 == strcmp(argv[1], "--verbose"));
	using namespace axl;
	using namespace axl::math;
	using namespace axl::math::Constants;
	printf("axl.math - version %hu.%hu.%hu  %s %s\n", lib::VERSION.major, lib::VERSION.minor, lib::VERSION.patch, libType(lib::LIBRARY_TYPE), buildType(lib::BUILD_TYPE));
	puts("----------------------------------------");
	{ // double
		{
			const double deg = 238.56;
			const double rad = 4.1636574635576726387;
			const double norm = 0.6626666666666666667;
			Assertv(Double::equals(Angle::degToRad(deg), rad, 0.00000001), verbose);
			Assertv(Double::equals(Angle::radToDeg(rad), deg, 0.00000001), verbose);
			Assertv(Double::equals(Angle::normToRad(norm), rad, 0.00000001), verbose);
			Assertv(Double::equals(Angle::radToNorm(rad), norm, 0.00000001), verbose);
			Assertv(Double::equals(Angle::normToDeg(norm), deg, 0.00000001), verbose);
			Assertv(Double::equals(Angle::degToNorm(deg), norm, 0.00000001), verbose);
		}
		{
			const double deg = 146.7343188645281021312;
			const double rad = deg * D_1_180TH_PI;
			const double norm = deg / 360.0;
			Assertv(Double::equals(Angle::degToRad(deg), rad, 0.00000001), verbose);
			Assertv(Double::equals(Angle::radToDeg(rad), deg, 0.00000001), verbose);
			Assertv(Double::equals(Angle::normToRad(norm), rad, 0.00000001), verbose);
			Assertv(Double::equals(Angle::radToNorm(rad), norm, 0.00000001), verbose);
			Assertv(Double::equals(Angle::normToDeg(norm), deg, 0.00000001), verbose);
			Assertv(Double::equals(Angle::degToNorm(deg), norm, 0.00000001), verbose);
		}
	}
	{ // float
		{
			const float deg = 238.56f;
			const float rad = 4.1636574635576726387f;
			const float norm = 0.6626666666666666667f;
			Assertv(Float::equals(Angle::degToRad(deg), rad, 0.0001f), verbose);
			Assertv(Float::equals(Angle::radToDeg(rad), deg, 0.0001f), verbose);
			Assertv(Float::equals(Angle::normToRad(norm), rad, 0.0001f), verbose);
			Assertv(Float::equals(Angle::radToNorm(rad), norm, 0.0001f), verbose);
			Assertv(Float::equals(Angle::normToDeg(norm), deg, 0.0001f), verbose);
			Assertv(Float::equals(Angle::degToNorm(deg), norm, 0.0001f), verbose);
		}
		{
			const float deg = 159.34123923f;
			const float rad = deg * F_1_180TH_PI;
			const float norm = deg / 360.0f;
			Assertv(Float::equals(Angle::degToRad(deg), rad, 0.000001f), verbose);
			Assertv(Float::equals(Angle::radToDeg(rad), deg, 0.000001f), verbose);
			Assertv(Float::equals(Angle::normToRad(norm), rad, 0.000001f), verbose);
			Assertv(Float::equals(Angle::radToNorm(rad), norm, 0.000001f), verbose);
			Assertv(Float::equals(Angle::normToDeg(norm), deg, 0.000001f), verbose);
			Assertv(Float::equals(Angle::degToNorm(deg), norm, 0.000001f), verbose);
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