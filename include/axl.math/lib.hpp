#pragma once

#if defined(LIBAXLMATH_SHARED)
#	ifdef WIN32
#		ifdef LIBAXLMATH_BUILD
#			define AXLMATHAPI extern __declspec(dllexport)
#			define AXLMATHCXXAPI __declspec(dllexport)
#		else
#			define AXLMATHAPI extern __declspec(dllimport)
#			define AXLMATHCXXAPI __declspec(dllimport)
#		endif
#	else
#		define AXLMATHAPI extern
#		define AXLMATHCXXAPI
#	endif
#else
#	define AXLMATHAPI extern
#	define AXLMATHCXXAPI
#endif

#if __cplusplus >= 201103L
#	if _MSC_VER && _MSC_VER < 1900 // less than MSVC++ 2015
#		define AXLMATHCONSTMODIFIER const static
#	else
#		define AXLMATHCONSTMODIFIER constexpr
#	endif
#	define ENUM_CLASS enum class
#else
#	define AXLMATHCONSTMODIFIER const static
#	define ENUM_CLASS enum
#endif

namespace axl {
namespace math {
namespace lib {

typedef enum LibraryType {
	LT_STATIC,
	LT_SHARED
} LibraryType;

typedef enum BuildType {
	BT_DEBUG,
	BT_RELEASE,
	BT_OTHER
} BuildType;

typedef struct Version
{
	unsigned short major;
	unsigned short minor;
	unsigned short patch;
} Version;

AXLMATHAPI const Version VERSION;
AXLMATHAPI const LibraryType LIBRARY_TYPE;
AXLMATHAPI const BuildType BUILD_TYPE;


} // namespace axl.math.lib
} // namespace axl.math
} // namespace axl