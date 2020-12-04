cmake_minimum_required( VERSION 3.10 )

project( axl.math VERSION 0.13.19 DESCRIPTION "A simple C++ math library primarily designed for game engines." )

# Configure
set( LIBAXLMATH_SUFFIX "" )
set( CMAKE_CXX_STANDARD 11 CACHE STRING "C++ compiler standard.")
set( LIBAXLMATH_TYPE STATIC CACHE STRING "Library type." )
set( HEADERS_INSTALL_DIR "include" CACHE PATH "Relative path for header files to install." )
set( ARCHIVES_INSTALL_DIR "lib" CACHE PATH "Relative path for library archives to install." )
set( BINARY_INSTALL_DIR "bin" CACHE PATH "Relative path for runtime binaries to install." )
set( LIBAXLMATH_EXPORT_DIR "${PROJECT_BINARY_DIR}/tests" CACHE PATH "Binary directory relative path for runtime binaries to build to." )
set( INSTALL_HEADERS ON CACHE BOOL "" )
set( INSTALL_ARCHIVES ON CACHE BOOL "" )
set( INSTALL_BINARIES ON CACHE BOOL "" )
set( BUILD_TESTS OFF CACHE BOOL "" )
set( LIBAXLMATH_INSTALL_HEADERS ON CACHE BOOL "" )
set( LIBAXLMATH_INSTALL_ARCHIVES ON CACHE BOOL "" )
set( LIBAXLMATH_INSTALL_BINARIES ON CACHE BOOL "" )
set( LIBAXLMATH_BUILD_TESTS ON CACHE BOOL "" )
set( LIBAXLMATH_PRINT_CONFIGS OFF CACHE BOOL "" )

if( LIBAXLMATH_PRINT_CONFIGS )
	message( NOTICE "CMAKE_CXX_STANDARD:= ${CMAKE_CXX_STANDARD}" )
	message( NOTICE "LIBAXLMATH_TYPE:= ${LIBAXLMATH_TYPE}" )
	message( NOTICE "CMAKE_BUILD_TYPE:= ${CMAKE_BUILD_TYPE}" )
	message( NOTICE "HEADERS_INSTALL_DIR:= ${HEADERS_INSTALL_DIR}" )
	message( NOTICE "ARCHIVES_INSTALL_DIR:= ${ARCHIVES_INSTALL_DIR}" )
	message( NOTICE "BINARY_INSTALL_DIR:= ${BINARY_INSTALL_DIR}" )
	message( NOTICE "CMAKE_INSTALL_PREFIX:= ${CMAKE_INSTALL_PREFIX}" )
	message( NOTICE "LIBAXLMATH_EXPORT_DIR:= ${LIBAXLMATH_EXPORT_DIR}" )
	message( NOTICE "INSTALL_HEADERS:= ${INSTALL_HEADERS}" )
	message( NOTICE "INSTALL_ARCHIVES:= ${INSTALL_ARCHIVES}" )
	message( NOTICE "INSTALL_BINARIES:= ${INSTALL_BINARIES}" )
	message( NOTICE "BUILD_TESTS:= ${BUILD_TESTS}" )
	message( NOTICE "LIBAXLMATH_INSTALL_HEADERS:= ${INSTALL_HEADERS}" )
	message( NOTICE "LIBAXLMATH_INSTALL_ARCHIVES:= ${INSTALL_ARCHIVES}" )
	message( NOTICE "LIBAXLMATH_INSTALL_BINARIES:= ${INSTALL_BINARIES}" )
	message( NOTICE "LIBAXLMATH_BUILD_TESTS:= ${LIBAXLMATH_BUILD_TESTS}" )
endif()

if( "${CMAKE_BUILD_TYPE}" MATCHES "[Dd][Ee][Bb][Uu][Gg]" )
	add_compile_definitions( DEBUG )
elseif( "${CMAKE_BUILD_TYPE}" MATCHES "[Rr][Ee][Ll]" )
	add_compile_definitions( NDEBUG )
endif()

include_directories( include )

add_subdirectory( src "axl.math" )
if( BUILD_TESTS AND LIBAXLMATH_BUILD_TESTS )
	add_subdirectory( tests "tests" )
endif()

# install headers
if( INSTALL_HEADERS AND LIBAXLMATH_INSTALL_HEADERS )
	install( FILES
		"include/axl.math/lib.hpp"
		"include/axl.math/constants.hpp"
		"include/axl.math/rules.hpp"
		"include/axl.math/double.hpp"
		"include/axl.math/float.hpp"
		"include/axl.math/angle.hpp"
		"include/axl.math/util.hpp"
		DESTINATION "${HEADERS_INSTALL_DIR}/axl.math"
	)
	install( FILES
		"include/axl.math/vec/Vec2i.hpp"
		"include/axl.math/vec/Vec2f.hpp"
		"include/axl.math/vec/Vec2d.hpp"
		"include/axl.math/vec/Vec2.hpp"
		"include/axl.math/vec/Vec2.inl"
		"include/axl.math/vec/Vec3f.hpp"
		"include/axl.math/vec/Vec3d.hpp"
		"include/axl.math/vec/Vec3.hpp"
		"include/axl.math/vec/Vec3.inl"
		"include/axl.math/vec/Vec4f.hpp"
		"include/axl.math/vec/Vec4d.hpp"
		"include/axl.math/vec/Vec4.hpp"
		"include/axl.math/vec/Vec4.inl"
		DESTINATION "${HEADERS_INSTALL_DIR}/axl.math/vec"
	)
	install( FILES
		"include/axl.math/mat/Mat2f.hpp"
		"include/axl.math/mat/Mat2d.hpp"
		"include/axl.math/mat/Mat3f.hpp"
		"include/axl.math/mat/Mat3d.hpp"
		"include/axl.math/mat/Mat4f.hpp"
		DESTINATION "${HEADERS_INSTALL_DIR}/axl.math/mat"
	)
endif()
