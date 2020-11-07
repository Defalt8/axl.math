#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "Assert.hpp"
#include <axl.math/lib.hpp>

int main(int argc, char *argv[])
{
	bool verbose = argc > 1 && (0 == strcmp(argv[1], "-v") || 0 == strcmp(argv[1], "--verbose"));
	using namespace axl;
	using namespace axl::math;
	printf("library version: %u %u %u\n", lib::version.major, lib::version.minor, lib::version.patch);
	
	if(verbose) {
		puts("----------------------------------------");
		if(Assert::_num_failed_tests <= 0) printf("# All Good!\n", Assert::_num_failed_tests);
		else printf("# %d Failed!\n", Assert::_num_failed_tests);
	}
	return Assert::_num_failed_tests;
}