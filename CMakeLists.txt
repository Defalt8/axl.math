cmake_minimum_required( VERSION 3.4 )

project( axl.math VERSION 0.28.34 DESCRIPTION "A simple C++ math library primarily designed for game engines." LANGUAGES CXX )

if( "${CMAKE_SOURCE_DIR}" STREQUAL "${PROJECT_SOURCE_DIR}" )
	set( AXLMATH_STANDALONE TRUE )
else()
	set( AXLMATH_STANDALONE FALSE )
endif()

set( CMAKE_CXX_STANDARD 11 CACHE STRING "C++ compiler standard.")
set( CMAKE_CXX_STANDARD_REQUIRED TRUE CACHE BOOL "" )
set( CMAKE_BUILD_TYPE Debug CACHE STRING "Build configuration type: ${CMAKE_CONFIGURATION_TYPES}." )
set( AXLMATH_TYPE STATIC CACHE STRING "Library type." )
set( AXLMATH_RUNTIME_DIR "${PROJECT_BINARY_DIR}/bin" CACHE PATH "Path to build ruintime objects like shared library." )
set( AXLMATH_ARCHIVE_DIR "${PROJECT_BINARY_DIR}/lib" CACHE PATH "Path to build ruintime objects like shared library." )
set( AXLMATH_INSTALL_HEADERS ${AXLMATH_STANDALONE} CACHE BOOL "" )
set( AXLMATH_BUILD_TESTS ${AXLMATH_STANDALONE} CACHE BOOL "" )
set( AXLMATH_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include" )

add_subdirectory( src axl.math )
if( AXLMATH_BUILD_TESTS )
	add_subdirectory( tests axl.math.tests )
endif()


# install headers
if( AXLMATH_INSTALL_HEADERS )
	install( FILES
		"${AXLMATH_INCLUDE_DIR}/axl.math/everything.hpp"
		"${AXLMATH_INCLUDE_DIR}/axl.math/lib.hpp"
		"${AXLMATH_INCLUDE_DIR}/axl.math/constants.hpp"
		"${AXLMATH_INCLUDE_DIR}/axl.math/rules.hpp"
		"${AXLMATH_INCLUDE_DIR}/axl.math/orders.hpp"
		"${AXLMATH_INCLUDE_DIR}/axl.math/basic.hpp"
		"${AXLMATH_INCLUDE_DIR}/axl.math/double.hpp"
		"${AXLMATH_INCLUDE_DIR}/axl.math/float.hpp"
		"${AXLMATH_INCLUDE_DIR}/axl.math/angle.hpp"
		"${AXLMATH_INCLUDE_DIR}/axl.math/util.hpp"
		"${AXLMATH_INCLUDE_DIR}/axl.math/vec.hpp"
		"${AXLMATH_INCLUDE_DIR}/axl.math/mat.hpp"
		"${AXLMATH_INCLUDE_DIR}/axl.math/rectangle.hpp"
		DESTINATION "include/axl.math"
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
		DESTINATION "include/axl.math/vec"
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
		DESTINATION "include/axl.math/mat"
	)
	install( FILES
		"${AXLMATH_INCLUDE_DIR}/axl.math/rectangle/Rectanglei.hpp"
		"${AXLMATH_INCLUDE_DIR}/axl.math/rectangle/Rectanglef.hpp"
		"${AXLMATH_INCLUDE_DIR}/axl.math/rectangle/Rectangled.hpp"
		DESTINATION "include/axl.math/rectangle"
	)
	install( FILES
		"${AXLMATH_INCLUDE_DIR}/axl.math/transform/Transform4f.hpp"
		"${AXLMATH_INCLUDE_DIR}/axl.math/transform/Transform4d.hpp"
		DESTINATION "include/axl.math/transform"
	)
endif()
