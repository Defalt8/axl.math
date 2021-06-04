#pragma once
#include <axl.math/lib.hpp>

const char* libType(axl::math::lib::LibraryType lib_type)
{
	using namespace axl::math::lib;
	switch (lib_type)
	{
		case LibraryType::LT_SHARED: return "SHARED";
		default:
		case LibraryType::LT_STATIC: return "STATIC";
	}
}

const char* buildType(axl::math::lib::BuildType build_type)
{
	using namespace axl::math::lib;
	switch (build_type)
	{
		case BuildType::BT_DEBUG: return "Debug";
		case BuildType::BT_RELEASE: return "Release";
		default:
		case BuildType::BT_OTHER: return "Other";
	}
}