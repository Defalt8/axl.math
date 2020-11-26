#pragma once
#include <axl.math/lib.hpp>

const char* libType(axl::math::lib::LibraryType lib_type)
{
	using namespace axl::math::lib;
	switch (lib_type)
	{
		case LT_SHARED: return "SHARED";
		default:
		case LT_STATIC: return "STATIC";
	}
}

const char* buildType(axl::math::lib::BuildType build_type)
{
	using namespace axl::math::lib;
	switch (build_type)
	{
		case BT_DEBUG: return "Debug";
		case BT_RELEASE: return "Release";
		default:
		case BT_OTHER: return "Other";
	}
}