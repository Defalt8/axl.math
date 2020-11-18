cmake_minimum_required( VERSION 3.17 )

project( axl.math VERSION 0.5.1 )

# Configure
option( BUILD_TESTS OFF )
if( "${LIB_TYPE}" STREQUAL "" )
	set( LIB_TYPE "STATIC" )
endif()
if( "${CMAKE_BUILD_TYPE}" STREQUAL "" )
	set( CMAKE_BUILD_TYPE "Debug" )
endif()

# Configure library type
set( LIB_SUFFIX "" )
if( "${LIB_TYPE}" STREQUAL "MODULE" )
# ---
elseif( "${LIB_TYPE}" STREQUAL "SHARED" )
	set( LIB_SUFFIX ${LIB_SUFFIX}r )
else()
	set( LIB_TYPE STATIC )
	set( LIB_SUFFIX ${LIB_SUFFIX}s )
endif()

# Configure build type
if( "${CMAKE_BUILD_TYPE}" STREQUAL "Debug" )
	add_compile_definitions( DEBUG )
	set( LIB_SUFFIX ${LIB_SUFFIX}d )
	if( ${MSVC} )
		add_compile_options( /DEBUG /Od )
	else()
		add_compile_options( -g -Og )
	endif()
elseif( "${CMAKE_BUILD_TYPE}" STREQUAL "Release" )
	add_compile_definitions( NDEBUG RELEASE )
	if( ${MSVC} )
		add_compile_options( /Ot )
	else()
		add_compile_options( -O3 )
	endif()
endif()

# Configure install dirs
if( "${CMAKE_INSTALL_INCDIR}" STREQUAL "" )
set( CMAKE_INSTALL_INCDIR include )
endif()
if( "${CMAKE_INSTALL_LIBDIR}" STREQUAL "" )
	set( CMAKE_INSTALL_LIBDIR lib )
endif()
if( "${CMAKE_INSTALL_BINDIR}" STREQUAL "" )
	set( CMAKE_INSTALL_BINDIR bin )
endif()

set( CMAKE_CXX_STANDARD 11 )

# Print configurations
message( "Project: ${PROJECT_NAME}" )
message( "LIB_TYPE= ${LIB_TYPE}" )
message( "CMAKE_BUILD_TYPE= ${CMAKE_BUILD_TYPE}" )
message( "CMAKE_CXX_STANDARD= ${CMAKE_CXX_STANDARD}" )
message( "CMAKE_INSTALL_PREFIX= ${CMAKE_INSTALL_PREFIX}" )
message( "CMAKE_INSTALL_INCDIR= ${CMAKE_INSTALL_INCDIR}" )
message( "CMAKE_INSTALL_LIBDIR= ${CMAKE_INSTALL_LIBDIR}" )
message( "CMAKE_INSTALL_BINDIR= ${CMAKE_INSTALL_BINDIR}" )
message( "BUILD_TESTS= ${BUILD_TESTS}" )
message( "------------------------------------------" )

include_directories( include )
add_subdirectory( src )
if( ${BUILD_TESTS} )
	add_subdirectory( tests )
endif()

# Install
install( FILES
	"include/axl.math/lib.hpp"
	"include/axl.math/constants.hpp"
	"include/axl.math/rules.hpp"
	"include/axl.math/double.hpp"
	"include/axl.math/float.hpp"
	"include/axl.math/angle.hpp"
	"include/axl.math/Vec2f.hpp"
	"include/axl.math/Vec2d.hpp"
	"include/axl.math/Vec2.hpp"
	"include/axl.math/Vec2.inl"
	"include/axl.math/Vec3f.hpp"
	"include/axl.math/Vec3d.hpp"
	"include/axl.math/Vec3.hpp"
	"include/axl.math/Vec3.inl"
	DESTINATION "include/axl.math"
)
install( TARGETS axl.math
	ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
	LIBRARY DESTINATION "${CMAKE_INSTALL_BINDIR}"
	RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
	CONFIGURATIONS "" Debug Release
)
