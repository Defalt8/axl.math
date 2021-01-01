# library
set( LIBAXLMATH_OUTPUT_NAME axl.math )
add_library( axl.math ${LIBAXLMATH_TYPE}
	"lib.cpp"
	"rules.cpp"
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
)
target_compile_definitions( axl.math
	PRIVATE LIBAXLMATH_BUILD
	PUBLIC LIBAXLMATH_VERSION_MAJOR=${axl.math_VERSION_MAJOR}
	PUBLIC LIBAXLMATH_VERSION_MINOR=${axl.math_VERSION_MINOR}
	PUBLIC LIBAXLMATH_VERSION_PATCH=${axl.math_VERSION_PATCH}
)
if( "${LIBAXLMATH_TYPE}" MATCHES "^[Ss][Tt][Aa][Tt][Ii][Cc]$" )
	set( LIBAXLMATH_SUFFIX s )
	target_compile_definitions( axl.math
		PUBLIC LIBAXLMATH_STATIC
	)
	if( INSTALL_ARCHIVES AND LIBAXLMATH_INSTALL_ARCHIVES )
		install( TARGETS axl.math
			ARCHIVE DESTINATION "${CMAKE_INSTALL_PREFIX}/${ARCHIVES_INSTALL_DIR}"
		)
	endif()
elseif( "${LIBAXLMATH_TYPE}" MATCHES "^[Ss][Hh][Aa][Rr][Ee][Dd]$" )
	target_compile_definitions( axl.math
		PUBLIC LIBAXLMATH_SHARED
	)
	if( INSTALL_ARCHIVES AND LIBAXLMATH_INSTALL_ARCHIVES )
		install( TARGETS axl.math
			ARCHIVE DESTINATION "${CMAKE_INSTALL_PREFIX}/${ARCHIVES_INSTALL_DIR}"
		)
	endif()
	if( INSTALL_BINARIES AND LIBAXLMATH_INSTALL_BINARIES )
		install( TARGETS axl.math
			RUNTIME DESTINATION "${CMAKE_INSTALL_PREFIX}/${BINARY_INSTALL_DIR}"
		)
	endif()
else()
	set( LIBAXLMATH_SUFFIX l )
endif()

if( "${CMAKE_BUILD_TYPE}" MATCHES "[Dd][Ee][Bb][Uu][Gg]" )
	set( LIBAXLMATH_SUFFIX "${LIBAXLMATH_SUFFIX}d" )
endif()

set_target_properties( axl.math PROPERTIES
	OUTPUT_NAME "${LIBAXLMATH_OUTPUT_NAME}${LIBAXLMATH_SUFFIX}"
	ARCHIVE_OUTPUT_NAME "${LIBAXLMATH_OUTPUT_NAME}${LIBAXLMATH_SUFFIX}"
	LIBRARY_OUTPUT_NAME "${LIBAXLMATH_OUTPUT_NAME}${LIBAXLMATH_SUFFIX}"
	RUNTIME_OUTPUT_NAME "${LIBAXLMATH_OUTPUT_NAME}${LIBAXLMATH_SUFFIX}"
	LIBRARY_OUTPUT_DIRECTORY "${LIBAXLMATH_EXPORT_DIR}"
	RUNTIME_OUTPUT_DIRECTORY "${LIBAXLMATH_EXPORT_DIR}"
)
