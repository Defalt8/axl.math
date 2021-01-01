#include <axl.math/lib.hpp>

namespace axl {
namespace math {
namespace lib {

const Version VERSION = { AXLMATH_VERSION_MAJOR, AXLMATH_VERSION_MINOR, AXLMATH_VERSION_PATCH };

#if defined(AXLMATH_SHARED)
const LibraryType LIBRARY_TYPE = LibraryType::LT_SHARED;
#else
const LibraryType LIBRARY_TYPE = LibraryType::LT_STATIC;
#endif

#ifdef DEBUG
const BuildType BUILD_TYPE = BuildType::BT_DEBUG;
#elif defined(NDEBUG)
const BuildType BUILD_TYPE = BuildType::BT_RELEASE;
#else
const BuildType BUILD_TYPE = BuildType::BT_OTHER;
#endif

} // namespace axl.math.lib
} // namespace axl.math
} // namespace axl