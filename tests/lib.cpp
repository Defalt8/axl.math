#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "Assert.hpp"
#include "lib.hpp"

int main(int argc, char *argv[])
{
	bool verbose = argc > 1 && (0 == strcmp(argv[1], "-v") || 0 == strcmp(argv[1], "--verbose"));
	using namespace axl;
	using namespace axl::math;
	printf("axl.math - version %hu.%hu.%hu  %s %s\n", lib::VERSION.major, lib::VERSION.minor, lib::VERSION.patch, libType(lib::LIBRARY_TYPE), buildType(lib::BUILD_TYPE));
	puts("----------------------------------------");
	if(assert::_num_failed_tests <= 0)
		printf("ALL GOOD!\n");
	else
	{
		puts("----------------------------------------");
		printf("# %d Failed!\n", assert::_num_failed_tests);
	}
	return assert::_num_failed_tests;
}