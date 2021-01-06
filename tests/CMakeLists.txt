
link_libraries( axl.math )

add_executable( "axl.math.lib" "lib.cpp" )
add_executable( "axl.math.double" "double.cpp" )
add_executable( "axl.math.float" "float.cpp" )
add_executable( "axl.math.angle" "angle.cpp" )
add_executable( "axl.math.util" "util.cpp" )
add_executable( "axl.math.Vec2i" "vec/Vec2i.cpp" )
add_executable( "axl.math.Vec2f" "vec/Vec2f.cpp" )
add_executable( "axl.math.Vec2d" "vec/Vec2d.cpp" )
add_executable( "axl.math.Vec2" "vec/Vec2.cpp" )
add_executable( "axl.math.Vec3f" "vec/Vec3f.cpp" )
add_executable( "axl.math.Vec3d" "vec/Vec3d.cpp" )
add_executable( "axl.math.Vec3" "vec/Vec3.cpp" )
add_executable( "axl.math.Vec4f" "vec/Vec4f.cpp" )
add_executable( "axl.math.Vec4d" "vec/Vec4d.cpp" )
add_executable( "axl.math.Vec4" "vec/Vec4.cpp" )
add_executable( "axl.math.Mat2f" "mat/Mat2f.cpp" )
add_executable( "axl.math.Mat2d" "mat/Mat2d.cpp" )
add_executable( "axl.math.Mat3f" "mat/Mat3f.cpp" )
add_executable( "axl.math.Mat3d" "mat/Mat3d.cpp" )
add_executable( "axl.math.Mat4f" "mat/Mat4f.cpp" )
add_executable( "axl.math.Mat4d" "mat/Mat4d.cpp" )
add_executable( "axl.math.transform3" "mat/transform3.cpp" )
add_executable( "axl.math.transform4" "mat/transform4.cpp" )

set_target_properties( 
	"axl.math.lib"
	"axl.math.double"
	"axl.math.float"
	"axl.math.angle"
	"axl.math.util"
	"axl.math.Vec2i"
	"axl.math.Vec2f"
	"axl.math.Vec2d"
	"axl.math.Vec2"
	"axl.math.Vec3f"
	"axl.math.Vec3d"
	"axl.math.Vec3"
	"axl.math.Vec4f"
	"axl.math.Vec4d"
	"axl.math.Vec4"
	"axl.math.Mat2f"
	"axl.math.Mat2d"
	"axl.math.Mat3f"
	"axl.math.Mat3d"
	"axl.math.Mat4f"
	"axl.math.Mat4d"
	"axl.math.transform3"
	"axl.math.transform4"
	PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY "${AXLMATH_RUNTIME_DIR}"
)