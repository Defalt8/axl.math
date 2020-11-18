#pragma once

#if defined(AXLMATH_MODULE)
#	ifdef WIN32
#		ifdef AXLMATH_BUILD
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
#elif defined(AXLMATH_SHARED)
#	ifdef WIN32
#		ifdef AXLMATH_BUILD
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
#	ifndef AXLMATH_STATIC
#		define AXLMATH_STATIC
#	endif
#	define AXLMATHAPI extern
#	define AXLMATHCXXAPI
#endif

namespace axl {
namespace math {
namespace lib {

enum LibraryType {
	LT_STATIC,
	LT_SHARED,
	LT_MODULE
};
typedef enum LibraryType LibraryType;

enum BuildType {
	BT_DEBUG,
	BT_RELEASE,
	BT_OTHER
};
typedef enum BuildType BuildType;

struct Version
{
	unsigned short major;
	unsigned short minor;
	unsigned short patch;
};
typedef struct Version Version;

AXLMATHAPI const Version VERSION;
AXLMATHAPI const LibraryType LIBRARY_TYPE;
AXLMATHAPI const BuildType BUILD_TYPE;


} // namespace axl.math.lib
} // namespace axl.math
} // namespace axl