cmake_minimum_required( VERSION 3.17 )
project( axl.math VERSION 1.0 )

# default initial configurations
if( "${CMAKE_BUILD_TYPE}" STREQUAL "" )
	set( CMAKE_BUILD_TYPE Debug )
endif()
if( "${BUILD_TESTS}" STREQUAL "" )
	set( BUILD_TESTS ON )
endif()
if( "${PRINT_CONFIGS}" STREQUAL "" )
	set( PRINT_CONFIGS ON )
endif()

# print configurations
message( "PRINT_CONFIGS: ${PRINT_CONFIGS}" )
if( ${PRINT_CONFIGS} )
	message( "CMAKE_INSTALL_PREFIX: ${CMAKE_INSTALL_PREFIX}" )
	message( "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}" )
	message( "BUILD_TESTS: ${BUILD_TESTS}" )
endif()

# configure
if( ${CMAKE_BUILD_TYPE} STREQUAL Debug )
	add_compile_definitions( DEBUG )
	add_compile_options( -Og )
elseif( ${CMAKE_BUILD_TYPE} STREQUAL Release )
	add_compile_definitions( NDEBUG )
	add_compile_options( -O3 )
endif()

# include directories
include_directories( include )

#install header files
install( FILES
	include/axl.math/lib.hpp
	include/axl.math/constants.hpp
	include/axl.math/double.hpp
	include/axl.math/float.hpp
	include/axl.math/angle.hpp
	include/axl.math/Vec2f.hpp
	include/axl.math/Vec2d.hpp
	DESTINATION include/axl.math
)

# add sub-directories to build
add_subdirectory( src )
if( ${BUILD_TESTS} )
	add_subdirectory( tests )
endif()

install( TARGETS
	axl.math
	CONFIGURATIONS "" Release
	DESTINATION lib
)
install( TARGETS
	axl.math
	CONFIGURATIONS Debug
	DESTINATION lib/debug
)