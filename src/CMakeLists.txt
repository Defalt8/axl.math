# library
set( AXLMATH_OUTPUT_NAME axl.math )
add_library( axl.math ${AXLMATH_TYPE}
	"lib.cpp"
	"rules.cpp"
	"basic.cpp"
	"double.cpp"
	"float.cpp"
	"angle.cpp"
	"util.cpp"
	"vec/Vec2i.cpp"
	"vec/Vec2f.cpp"
	"vec/Vec2d.cpp"
	"vec/Vec3f.cpp"
	"vec/Vec3d.cpp"
	"vec/Vec4f.cpp"
	"vec/Vec4d.cpp"
	"mat/Mat2f.cpp"
	"mat/Mat2d.cpp"
	"mat/Mat3f.cpp"
	"mat/Mat3d.cpp"
	"mat/Mat4f.cpp"
	"mat/Mat4d.cpp"
	"mat/transform2.cpp"
	"mat/transform3.cpp"
	"mat/transform4.cpp"

	"../include/axl.math/lib.hpp"
	"../include/axl.math/rules.hpp"
	"../include/axl.math/basic.hpp"
	"../include/axl.math/double.hpp"
	"../include/axl.math/float.hpp"
	"../include/axl.math/angle.hpp"
	"../include/axl.math/util.hpp"
	"../include/axl.math/vec/Vec2i.hpp"
	"../include/axl.math/vec/Vec2f.hpp"
	"../include/axl.math/vec/Vec2d.hpp"
	"../include/axl.math/vec/Vec3f.hpp"
	"../include/axl.math/vec/Vec3d.hpp"
	"../include/axl.math/vec/Vec4f.hpp"
	"../include/axl.math/vec/Vec4d.hpp"
	"../include/axl.math/mat/Mat2f.hpp"
	"../include/axl.math/mat/Mat2d.hpp"
	"../include/axl.math/mat/Mat3f.hpp"
	"../include/axl.math/mat/Mat3d.hpp"
	"../include/axl.math/mat/Mat4f.hpp"
	"../include/axl.math/mat/Mat4d.hpp"
	"../include/axl.math/mat/transform2.hpp"
	"../include/axl.math/mat/transform3.hpp"
	"../include/axl.math/mat/transform4.hpp"
)
target_compile_definitions( axl.math
	PRIVATE AXLMATH_BUILD
	PUBLIC AXLMATH_VERSION_MAJOR=${axl.math_VERSION_MAJOR}
	PUBLIC AXLMATH_VERSION_MINOR=${axl.math_VERSION_MINOR}
	PUBLIC AXLMATH_VERSION_PATCH=${axl.math_VERSION_PATCH}
)
if( "${AXLMATH_TYPE}" MATCHES "^[Ss][Tt][Aa][Tt][Ii][Cc]$" )
	set( AXLMATH_SUFFIX s )
	target_compile_definitions( axl.math
		PUBLIC AXLMATH_STATIC
	)
	if( INSTALL_ARCHIVES AND AXLMATH_INSTALL_ARCHIVES )
		install( TARGETS axl.math
			ARCHIVE DESTINATION "${CMAKE_INSTALL_PREFIX}/${ARCHIVES_INSTALL_DIR}"
		)
	endif()
elseif( "${AXLMATH_TYPE}" MATCHES "^[Ss][Hh][Aa][Rr][Ee][Dd]$" )
	target_compile_definitions( axl.math
		PUBLIC AXLMATH_SHARED
	)
	if( INSTALL_ARCHIVES AND AXLMATH_INSTALL_ARCHIVES )
		install( TARGETS axl.math
			ARCHIVE DESTINATION "${CMAKE_INSTALL_PREFIX}/${ARCHIVES_INSTALL_DIR}"
		)
	endif()
	if( INSTALL_BINARIES AND AXLMATH_INSTALL_BINARIES )
		install( TARGETS axl.math
			RUNTIME DESTINATION "${CMAKE_INSTALL_PREFIX}/${BINARY_INSTALL_DIR}"
		)
	endif()
else()
	set( AXLMATH_SUFFIX l )
endif()

if( "${CMAKE_BUILD_TYPE}" MATCHES "[Dd][Ee][Bb][Uu][Gg]" )
	set( AXLMATH_SUFFIX "${AXLMATH_SUFFIX}d" )
endif()

set_target_properties( axl.math PROPERTIES
	OUTPUT_NAME "${AXLMATH_OUTPUT_NAME}${AXLMATH_SUFFIX}"
	ARCHIVE_OUTPUT_NAME "${AXLMATH_OUTPUT_NAME}${AXLMATH_SUFFIX}"
	LIBRARY_OUTPUT_NAME "${AXLMATH_OUTPUT_NAME}${AXLMATH_SUFFIX}"
	RUNTIME_OUTPUT_NAME "${AXLMATH_OUTPUT_NAME}${AXLMATH_SUFFIX}"
	LIBRARY_OUTPUT_DIRECTORY "${AXLMATH_EXPORT_DIR}"
	RUNTIME_OUTPUT_DIRECTORY "${AXLMATH_EXPORT_DIR}"
)
