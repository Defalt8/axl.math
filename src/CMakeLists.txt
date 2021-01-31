# library
set( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE )
set( MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>" )

if( "${AXLMATH_TYPE}" MATCHES "^[Ss][Hh][Aa][Rr][Ee][Dd]$" )
	set( AXLMATH_TYPE SHARED )
	set( TYPE_SUFFIX "" )
else()
	set( AXLMATH_TYPE STATIC )
	set( TYPE_SUFFIX s )
endif()

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

	"${AXLMATH_INCLUDE_DIR}/axl.math/lib.hpp"
	"${AXLMATH_INCLUDE_DIR}/axl.math/rules.hpp"
	"${AXLMATH_INCLUDE_DIR}/axl.math/basic.hpp"
	"${AXLMATH_INCLUDE_DIR}/axl.math/double.hpp"
	"${AXLMATH_INCLUDE_DIR}/axl.math/float.hpp"
	"${AXLMATH_INCLUDE_DIR}/axl.math/angle.hpp"
	"${AXLMATH_INCLUDE_DIR}/axl.math/util.hpp"
	"${AXLMATH_INCLUDE_DIR}/axl.math/vec/Vec2i.hpp"
	"${AXLMATH_INCLUDE_DIR}/axl.math/vec/Vec2f.hpp"
	"${AXLMATH_INCLUDE_DIR}/axl.math/vec/Vec2d.hpp"
	"${AXLMATH_INCLUDE_DIR}/axl.math/vec/Vec3f.hpp"
	"${AXLMATH_INCLUDE_DIR}/axl.math/vec/Vec3d.hpp"
	"${AXLMATH_INCLUDE_DIR}/axl.math/vec/Vec4f.hpp"
	"${AXLMATH_INCLUDE_DIR}/axl.math/vec/Vec4d.hpp"
	"${AXLMATH_INCLUDE_DIR}/axl.math/mat/Mat2f.hpp"
	"${AXLMATH_INCLUDE_DIR}/axl.math/mat/Mat2d.hpp"
	"${AXLMATH_INCLUDE_DIR}/axl.math/mat/Mat3f.hpp"
	"${AXLMATH_INCLUDE_DIR}/axl.math/mat/Mat3d.hpp"
	"${AXLMATH_INCLUDE_DIR}/axl.math/mat/Mat4f.hpp"
	"${AXLMATH_INCLUDE_DIR}/axl.math/mat/Mat4d.hpp"
	"${AXLMATH_INCLUDE_DIR}/axl.math/mat/transform2.hpp"
	"${AXLMATH_INCLUDE_DIR}/axl.math/mat/transform3.hpp"
	"${AXLMATH_INCLUDE_DIR}/axl.math/mat/transform4.hpp"
)
target_include_directories( axl.math PUBLIC "${AXLMATH_INCLUDE_DIR}" )
target_compile_definitions( axl.math
	PRIVATE AXLMATH_BUILD
	PUBLIC AXLMATH_VERSION_MAJOR=${PROJECT_VERSION_MAJOR}
	PUBLIC AXLMATH_VERSION_MINOR=${PROJECT_VERSION_MINOR}
	PUBLIC AXLMATH_VERSION_PATCH=${PROJECT_VERSION_PATCH}
)
if( "${CMAKE_BUILD_TYPE}" MATCHES "[Dd][Ee][Bb][Uu][Gg]" )
	set( DEBUG_SUFFIX d )
else()
	set( DEBUG_SUFFIX "" )
endif()
set_target_properties( axl.math PROPERTIES
	OUTPUT_NAME "axl.math${TYPE_SUFFIX}${DEBUG_SUFFIX}"
	ARCHIVE_OUTPUT_NAME "axl.math${TYPE_SUFFIX}${DEBUG_SUFFIX}"
	RUNTIME_OUTPUT_NAME "axl.math${TYPE_SUFFIX}${DEBUG_SUFFIX}"
	ARCHIVE_OUTPUT_DIRECTORY "${AXLMATH_ARCHIVE_DIR}"
	RUNTIME_OUTPUT_DIRECTORY "${AXLMATH_RUNTIME_DIR}"
)
if( "${AXLMATH_TYPE}" STREQUAL "SHARED" )
	target_compile_definitions( axl.math PUBLIC AXLMATH_SHARED )
else()
	target_compile_definitions( axl.math PUBLIC AXLMATH_STATIC )
endif()

if( "${CMAKE_BUILD_TYPE}" MATCHES "[Dd][Ee][Bb][Uu][Gg]" )
	target_compile_definitions( axl.math PRIVATE DEBUG )
elseif( "${CMAKE_BUILD_TYPE}" MATCHES "[Rr][Ee][Ll]" )
	target_compile_definitions( axl.math PRIVATE NDEBUG )
endif()

if( AXLMATH_INSTALL_ARCHIVES AND AXLMATH_INSTALL_RUNTIME )
	install( TARGETS axl.math
		ARCHIVE DESTINATION "lib"
		RUNTIME DESTINATION "bin"
	)
elseif( AXLMATH_INSTALL_ARCHIVES )
	install( TARGETS axl.math
		ARCHIVE DESTINATION "lib"
	)
elseif( AXLMATH_INSTALL_RUNTIME )
	install( TARGETS axl.math
		RUNTIME DESTINATION "bin"
	)
endif()
# install headers
if( AXLMATH_INSTALL_HEADERS )
	install( FILES
		"${AXLMATH_INCLUDE_DIR}/axl.math/lib.hpp"
		"${AXLMATH_INCLUDE_DIR}/axl.math/constants.hpp"
		"${AXLMATH_INCLUDE_DIR}/axl.math/rules.hpp"
		"${AXLMATH_INCLUDE_DIR}/axl.math/basic.hpp"
		"${AXLMATH_INCLUDE_DIR}/axl.math/double.hpp"
		"${AXLMATH_INCLUDE_DIR}/axl.math/float.hpp"
		"${AXLMATH_INCLUDE_DIR}/axl.math/angle.hpp"
		"${AXLMATH_INCLUDE_DIR}/axl.math/util.hpp"
		"${AXLMATH_INCLUDE_DIR}/axl.math/vec.hpp"
		"${AXLMATH_INCLUDE_DIR}/axl.math/mat.hpp"
		DESTINATION "${HEADERS_INSTALL_DIR}/axl.math"
	)
	install( FILES
		"${AXLMATH_INCLUDE_DIR}/axl.math/vec/Vec2i.hpp"
		"${AXLMATH_INCLUDE_DIR}/axl.math/vec/Vec2f.hpp"
		"${AXLMATH_INCLUDE_DIR}/axl.math/vec/Vec2d.hpp"
		"${AXLMATH_INCLUDE_DIR}/axl.math/vec/Vec2.hpp"
		"${AXLMATH_INCLUDE_DIR}/axl.math/vec/Vec2.inl"
		"${AXLMATH_INCLUDE_DIR}/axl.math/vec/Vec3f.hpp"
		"${AXLMATH_INCLUDE_DIR}/axl.math/vec/Vec3d.hpp"
		"${AXLMATH_INCLUDE_DIR}/axl.math/vec/Vec3.hpp"
		"${AXLMATH_INCLUDE_DIR}/axl.math/vec/Vec3.inl"
		"${AXLMATH_INCLUDE_DIR}/axl.math/vec/Vec4f.hpp"
		"${AXLMATH_INCLUDE_DIR}/axl.math/vec/Vec4d.hpp"
		"${AXLMATH_INCLUDE_DIR}/axl.math/vec/Vec4.hpp"
		"${AXLMATH_INCLUDE_DIR}/axl.math/vec/Vec4.inl"
		DESTINATION "${HEADERS_INSTALL_DIR}/axl.math/vec"
	)
	install( FILES
		"${AXLMATH_INCLUDE_DIR}/axl.math/mat/Mat2f.hpp"
		"${AXLMATH_INCLUDE_DIR}/axl.math/mat/Mat2d.hpp"
		"${AXLMATH_INCLUDE_DIR}/axl.math/mat/Mat3f.hpp"
		"${AXLMATH_INCLUDE_DIR}/axl.math/mat/Mat3d.hpp"
		"${AXLMATH_INCLUDE_DIR}/axl.math/mat/Mat4f.hpp"
		"${AXLMATH_INCLUDE_DIR}/axl.math/mat/Mat4d.hpp"
		"${AXLMATH_INCLUDE_DIR}/axl.math/mat/transform2.hpp"
		"${AXLMATH_INCLUDE_DIR}/axl.math/mat/transform3.hpp"
		"${AXLMATH_INCLUDE_DIR}/axl.math/mat/transform4.hpp"
		DESTINATION "${HEADERS_INSTALL_DIR}/axl.math/mat"
	)
endif()

