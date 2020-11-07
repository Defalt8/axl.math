#pragma once
#include <cstdio>

#define Assertf(e) if(!(e)) axl::Assert::_assertionFailed(false, #e, __FILE__, __LINE__)
#define Assertfe(e) if(!(e)) axl::Assert::_assertionFailed(true, #e, __FILE__, __LINE__)
#define Assertv(e, verbose) if(!(e)) axl::Assert::_assertionFailed(false, #e, __FILE__, __LINE__); else if(verbose) axl::Assert::_assertionSucceeded(#e)
#define Assertve(e, verbose) if(!(e)) axl::Assert::_assertionFailed(true, #e, __FILE__, __LINE__); else if(verbose) axl::Assert::_assertionSucceeded(#e)

namespace axl {
namespace Assert {

static int _num_failed_tests = 0;

void _assertionFailed(bool exit_after, const char* e, const char* file, int line)
{
	fprintf(stderr, "*Fail - %s | FILE: %s:%d\n", e, file, line);
	++_num_failed_tests;
	if(exit_after) std::exit(1);
}

void _assertionSucceeded(const char* e)
{
	printf(" Pass + %s\n", e);
}

} // namespace axl.Assert
} // namespace axl