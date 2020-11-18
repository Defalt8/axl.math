cmake_minimum_required( VERSION 3.17 )

# Library
add_library( axl.math ${LIB_TYPE}
	"lib.cpp"
	"double.cpp"
	"float.cpp"
	"angle.cpp"
	"Vec2f.cpp"
	"Vec2d.cpp"
	"Vec3f.cpp"
	"Vec3d.cpp"
)
# Target link libraries
if( ${MSVC} )
	set( LIBM m.lib )
elseif( ${WIN32} )
	set( LIBM -lm )
else()
	set( LIBM -lm )
endif()
target_link_libraries( axl.math ${LIBM} )
# Target compile definitions
target_compile_definitions( axl.math
	PUBLIC AXLMATH_${LIB_TYPE}
)
target_compile_definitions( axl.math
	PRIVATE AXLMATH_BUILD
	PRIVATE AXLMATH_VERSION_MAJOR=${PROJECT_VERSION_MAJOR}
	PRIVATE AXLMATH_VERSION_MINOR=${PROJECT_VERSION_MINOR}
	PRIVATE AXLMATH_VERSION_PATCH=${PROJECT_VERSION_PATCH}
)
# Target properties
set_target_properties( axl.math PROPERTIES
	LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/tests"
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/tests"
)
set_target_properties( axl.math PROPERTIES
	ARCHIVE_OUTPUT_NAME axl.math${LIB_SUFFIX}
	RUNTIME_OUTPUT_NAME axl.math${LIB_SUFFIX}
	LIBRARY_OUTPUT_NAME axl.math${LIB_SUFFIX}
)
