#include <axl.math/lib.hpp>

namespace axl {
namespace math {
namespace lib {

const Version VERSION = { AXLMATH_VERSION_MAJOR, AXLMATH_VERSION_MINOR, AXLMATH_VERSION_PATCH };

#if defined(AXLMATH_MODULE)
const LibraryType type = LT_MODULE;
#elif defined(AXLMATH_SHARED)
const LibraryType type = LT_SHARED;
#else
const LibraryType LIBRARY_TYPE = LT_STATIC;
#endif

#ifdef DEBUG
const BuildType BUILD_TYPE = BT_DEBUG;
#elif defined(RELEASE)
const BuildType BUILD_TYPE = BT_RELEASE;
#else
const BuildType BUILD_TYPE = BT_OTHER;
#endif

} // namespace axl.math.lib
} // namespace axl.math
} // namespace axl