cmake_minimum_required( VERSION 3.4 )

project( axl.math VERSION 0.28.32 DESCRIPTION "A simple C++ math library primarily designed for game engines." LANGUAGES CXX )

if( "${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_CURRENT_SOURCE_DIR}" )
	set( AXLMATH_STANDALONE TRUE )
else()
	set( AXLMATH_STANDALONE FALSE )
endif()
# Configure
set( CMAKE_CXX_STANDARD 11 CACHE STRING "C++ compiler standard.")
set( AXLMATH_TYPE STATIC CACHE STRING "Library type." )
set( AXLMATH_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include" CACHE PATH "axl.math headers path." )
set( AXLMATH_RUNTIME_DIR "${PROJECT_BINARY_DIR}/bin" CACHE PATH "Path to build ruintime objects like shared library." )
set( AXLMATH_ARCHIVE_DIR "${PROJECT_BINARY_DIR}/lib" CACHE PATH "Path to build ruintime objects like shared library." )
set( AXLMATH_INSTALL_HEADERS ${AXLMATH_STANDALONE} CACHE BOOL "" )
set( AXLMATH_INSTALL_ARCHIVES ${AXLMATH_STANDALONE} CACHE BOOL "" )
set( AXLMATH_INSTALL_RUNTIME ${AXLMATH_STANDALONE} CACHE BOOL "" )
set( AXLMATH_BUILD_TESTS ${AXLMATH_STANDALONE} CACHE BOOL "" )

if( BUILD_SHARED_LIBS )
	set( AXLMATH_TYPE SHARED )
endif()

add_subdirectory( src "axl.math" )
if( BUILD_TESTS AND AXLMATH_BUILD_TESTS )
	add_subdirectory( tests "axl.math.tests" )
endif()
