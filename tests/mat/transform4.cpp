#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include "../Assert.hpp"
#include "../lib.hpp"
#include <axl.math/angle.hpp>
#include <axl.math/float.hpp>
#include <axl.math/mat/Mat4d.hpp>
#include <axl.math/mat/Mat4f.hpp>
#include <axl.math/mat/transform4.hpp>

int main(int argc, char *argv[])
{
	bool verbose = argc > 1 && (0 == strcmp(argv[1], "-v") || 0 == strcmp(argv[1], "--verbose"));
	using namespace axl;
	using namespace axl::math;
	printf("axl.math - version %hu.%hu.%hu  %s %s\n", lib::VERSION.major, lib::VERSION.minor, lib::VERSION.patch, libType(lib::LIBRARY_TYPE), buildType(lib::BUILD_TYPE));
	puts("----------------------------------------");
	{ // Float
		// rotate*
		{ // RHS
			Rules::DefaultAxisRule = Rules::Axis::AXIS_RHS;
			Assertv((Transform4::rotateX(Angle::degToRad(90.0f)) * Vec4f(1, 0, 0, 1)).equals(1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateX(Angle::degToRad(90.0f)) * Vec4f(0, 1, 0, 1)).equals(0.0f, 0.0f, 1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateX(Angle::degToRad(90.0f)) * Vec4f(0, 0, 1, 1)).equals(0.0f, -1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateX(Angle::degToRad(90.0f)) * Vec4f(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateX(0.0f) * Vec4f(19, 72, 56, 1)).equals(19.0f, 72.0f, 56.0f, 1.0f, 0.0001f), verbose);
			
			Assertv((Transform4::rotateY(Angle::degToRad(90.0f)) * Vec4f(1, 0, 0, 1)).equals(0.0f, 0.0f, -1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateY(Angle::degToRad(90.0f)) * Vec4f(0, 1, 0, 1)).equals(0.0f, 1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateY(Angle::degToRad(90.0f)) * Vec4f(0, 0, 1, 1)).equals(1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateY(Angle::degToRad(90.0f)) * Vec4f(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateY(0.0f) * Vec4f(19, 72, 56, 1)).equals(19.0f, 72.0f, 56.0f, 1.0f, 0.0001f), verbose);

			Assertv((Transform4::rotateZ(Angle::degToRad(90.0f)) * Vec4f(1, 0, 0, 1)).equals(0.0f, 1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZ(Angle::degToRad(90.0f)) * Vec4f(0, 1, 0, 1)).equals(-1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZ(Angle::degToRad(90.0f)) * Vec4f(0, 0, 1, 1)).equals(0.0f, 0.0f, 1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZ(Angle::degToRad(90.0f)) * Vec4f(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZ(0.0f) * Vec4f(19, 72, 56, 1)).equals(19.0f, 72.0f, 56.0f, 1.0f, 0.0001f), verbose);
		}
		{ // LHS
			Rules::DefaultAxisRule = Rules::Axis::AXIS_LHS;
			Assertv((Transform4::rotateX(Angle::degToRad(90.0f)) * Vec4f(1, 0, 0, 1)).equals(1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateX(Angle::degToRad(90.0f)) * Vec4f(0, 1, 0, 1)).equals(0.0f, 0.0f, -1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateX(Angle::degToRad(90.0f)) * Vec4f(0, 0, 1, 1)).equals(0.0f, 1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateX(Angle::degToRad(90.0f)) * Vec4f(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateX(0.0f) * Vec4f(19, 72, 56, 1)).equals(19.0f, 72.0f, 56.0f, 1.0f, 0.0001f), verbose);

			Assertv((Transform4::rotateY(Angle::degToRad(90.0f)) * Vec4f(1, 0, 0, 1)).equals(0.0f, 0.0f, 1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateY(Angle::degToRad(90.0f)) * Vec4f(0, 1, 0, 1)).equals(0.0f, 1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateY(Angle::degToRad(90.0f)) * Vec4f(0, 0, 1, 1)).equals(-1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateY(Angle::degToRad(90.0f)) * Vec4f(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateY(0.0f) * Vec4f(19, 72, 56, 1)).equals(19.0f, 72.0f, 56.0f, 1.0f, 0.0001f), verbose);

			Assertv((Transform4::rotateZ(Angle::degToRad(90.0f)) * Vec4f(1, 0, 0, 1)).equals(0.0f, -1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZ(Angle::degToRad(90.0f)) * Vec4f(0, 1, 0, 1)).equals(1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZ(Angle::degToRad(90.0f)) * Vec4f(0, 0, 1, 1)).equals(0.0f, 0.0f, 1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZ(Angle::degToRad(90.0f)) * Vec4f(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZ(0.0f) * Vec4f(19, 72, 56, 1)).equals(19.0f, 72.0f, 56.0f, 1.0f, 0.0001f), verbose);
		}
		// rotate**
		{ // RHS
			Rules::DefaultAxisRule = Rules::Axis::AXIS_RHS;
			Assertv((Transform4::rotateXY(Vec3f(Angle::degToRad(90.0f), Angle::degToRad(90.0f), 0.0f)) * Vec4f(1, 0, 0, 1)).equals(0.0f, 1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXY(Vec3f(Angle::degToRad(90.0f), Angle::degToRad(90.0f), 0.0f)) * Vec4f(0, 1, 0, 1)).equals(0.0f, 0.0f, 1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXY(Vec3f(Angle::degToRad(90.0f), Angle::degToRad(90.0f), 0.0f)) * Vec4f(0, 0, 1, 1)).equals(1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXY(Vec3f(Angle::degToRad(90.0f), Angle::degToRad(90.0f), 0.0f)) * Vec4f(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXY(Vec3f(0.0f, 0.0f, 0.0f)) * Vec4f(5, 16, 35, 1)).equals(5.0f, 16.0f, 35.0f, 1.0f, 0.0001f), verbose);

			Assertv((Transform4::rotateYX(Vec3f(Angle::degToRad(90.0f), Angle::degToRad(90.0f), 0.0f)) * Vec4f(1, 0, 0, 1)).equals(0.0f, 0.0f, -1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYX(Vec3f(Angle::degToRad(90.0f), Angle::degToRad(90.0f), 0.0f)) * Vec4f(0, 1, 0, 1)).equals(1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYX(Vec3f(Angle::degToRad(90.0f), Angle::degToRad(90.0f), 0.0f)) * Vec4f(0, 0, 1, 1)).equals(0.0f, -1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYX(Vec3f(Angle::degToRad(90.0f), Angle::degToRad(90.0f), 0.0f)) * Vec4f(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYX(Vec3f(0.0f, 0.0f, 0.0f)) * Vec4f(5, 16, 35, 1)).equals(5.0f, 16.0f, 35.0f, 1.0f, 0.0001f), verbose);

			Assertv((Transform4::rotateYZ(Vec3f(0.0f, Angle::degToRad(90.0f), Angle::degToRad(90.0f))) * Vec4f(1, 0, 0, 1)).equals(0.0f, 1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYZ(Vec3f(0.0f, Angle::degToRad(90.0f), Angle::degToRad(90.0f))) * Vec4f(0, 1, 0, 1)).equals(0.0f, 0.0f, 1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYZ(Vec3f(0.0f, Angle::degToRad(90.0f), Angle::degToRad(90.0f))) * Vec4f(0, 0, 1, 1)).equals(1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYZ(Vec3f(0.0f, Angle::degToRad(90.0f), Angle::degToRad(90.0f))) * Vec4f(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYZ(Vec3f(0.0f, 0.0f, 0.0f)) * Vec4f(5, 16, 35, 1)).equals(5.0f, 16.0f, 35.0f, 1.0f, 0.0001f), verbose);

			Assertv((Transform4::rotateZY(Vec3f(0.0f, Angle::degToRad(90.0f), Angle::degToRad(90.0f))) * Vec4f(1, 0, 0, 1)).equals(0.0f, 0.0f, -1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZY(Vec3f(0.0f, Angle::degToRad(90.0f), Angle::degToRad(90.0f))) * Vec4f(0, 1, 0, 1)).equals(-1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZY(Vec3f(0.0f, Angle::degToRad(90.0f), Angle::degToRad(90.0f))) * Vec4f(0, 0, 1, 1)).equals(0.0f, 1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZY(Vec3f(0.0f, Angle::degToRad(90.0f), Angle::degToRad(90.0f))) * Vec4f(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZY(Vec3f(0.0f, 0.0f, 0.0f)) * Vec4f(5, 16, 35, 1)).equals(5.0f, 16.0f, 35.0f, 1.0f, 0.0001f), verbose);

			Assertv((Transform4::rotateXZ(Vec3f(Angle::degToRad(90.0f), 0.0f, Angle::degToRad(90.0f))) * Vec4f(1, 0, 0, 1)).equals(0.0f, 0.0f, 1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXZ(Vec3f(Angle::degToRad(90.0f), 0.0f, Angle::degToRad(90.0f))) * Vec4f(0, 1, 0, 1)).equals(-1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXZ(Vec3f(Angle::degToRad(90.0f), 0.0f, Angle::degToRad(90.0f))) * Vec4f(0, 0, 1, 1)).equals(0.0f, -1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXZ(Vec3f(Angle::degToRad(90.0f), 0.0f, Angle::degToRad(90.0f))) * Vec4f(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXZ(Vec3f(0.0f, 0.0f, 0.0f)) * Vec4f(5, 16, 35, 1)).equals(5.0f, 16.0f, 35.0f, 1.0f, 0.0001f), verbose);

			Assertv((Transform4::rotateZX(Vec3f(Angle::degToRad(90.0f), 0.0f, Angle::degToRad(90.0f))) * Vec4f(1, 0, 0, 1)).equals(0.0f, 1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZX(Vec3f(Angle::degToRad(90.0f), 0.0f, Angle::degToRad(90.0f))) * Vec4f(0, 1, 0, 1)).equals(0.0f, 0.0f, 1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZX(Vec3f(Angle::degToRad(90.0f), 0.0f, Angle::degToRad(90.0f))) * Vec4f(0, 0, 1, 1)).equals(1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZX(Vec3f(Angle::degToRad(90.0f), 0.0f, Angle::degToRad(90.0f))) * Vec4f(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZX(Vec3f(0.0f, 0.0f, 0.0f)) * Vec4f(5, 16, 35, 1)).equals(5.0f, 16.0f, 35.0f, 1.0f, 0.0001f), verbose);
		}
		{ // LHS
			Rules::DefaultAxisRule = Rules::Axis::AXIS_LHS;
			Assertv((Transform4::rotateXY(Vec3f(Angle::degToRad(90.0f), Angle::degToRad(90.0f), 0.0f)) * Vec4f(1, 0, 0, 1)).equals(0.0f, 1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXY(Vec3f(Angle::degToRad(90.0f), Angle::degToRad(90.0f), 0.0f)) * Vec4f(0, 1, 0, 1)).equals(0.0f, 0.0f, -1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXY(Vec3f(Angle::degToRad(90.0f), Angle::degToRad(90.0f), 0.0f)) * Vec4f(0, 0, 1, 1)).equals(-1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXY(Vec3f(Angle::degToRad(90.0f), Angle::degToRad(90.0f), 0.0f)) * Vec4f(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXY(Vec3f(0.0f, 0.0f, 0.0f)) * Vec4f(3, 13, 75, 1)).equals(3.0f, 13.0f, 75.0f, 1.0f, 0.0001f), verbose);

			Assertv((Transform4::rotateYX(Vec3f(Angle::degToRad(90.0f), Angle::degToRad(90.0f), 0.0f)) * Vec4f(1, 0, 0, 1)).equals(0.0f, 0.0f, 1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYX(Vec3f(Angle::degToRad(90.0f), Angle::degToRad(90.0f), 0.0f)) * Vec4f(0, 1, 0, 1)).equals(1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYX(Vec3f(Angle::degToRad(90.0f), Angle::degToRad(90.0f), 0.0f)) * Vec4f(0, 0, 1, 1)).equals(0.0f, 1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYX(Vec3f(Angle::degToRad(90.0f), Angle::degToRad(90.0f), 0.0f)) * Vec4f(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYX(Vec3f(0.0f, 0.0f, 0.0f)) * Vec4f(3, 13, 75, 1)).equals(3.0f, 13.0f, 75.0f, 1.0f, 0.0001f), verbose);

			Assertv((Transform4::rotateYZ(Vec3f(0.0f, Angle::degToRad(90.0f), Angle::degToRad(90.0f))) * Vec4f(1, 0, 0, 1)).equals(0.0f, -1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYZ(Vec3f(0.0f, Angle::degToRad(90.0f), Angle::degToRad(90.0f))) * Vec4f(0, 1, 0, 1)).equals(0.0f, 0.0f, 1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYZ(Vec3f(0.0f, Angle::degToRad(90.0f), Angle::degToRad(90.0f))) * Vec4f(0, 0, 1, 1)).equals(-1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYZ(Vec3f(0.0f, Angle::degToRad(90.0f), Angle::degToRad(90.0f))) * Vec4f(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYZ(Vec3f(0.0f, 0.0f, 0.0f)) * Vec4f(3, 13, 75, 1)).equals(3.0f, 13.0f, 75.0f, 1.0f, 0.0001f), verbose);

			Assertv((Transform4::rotateZY(Vec3f(0.0f, Angle::degToRad(90.0f), Angle::degToRad(90.0f))) * Vec4f(1, 0, 0, 1)).equals(0.0f, 0.0f, 1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZY(Vec3f(0.0f, Angle::degToRad(90.0f), Angle::degToRad(90.0f))) * Vec4f(0, 1, 0, 1)).equals(1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZY(Vec3f(0.0f, Angle::degToRad(90.0f), Angle::degToRad(90.0f))) * Vec4f(0, 0, 1, 1)).equals(0.0f, 1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZY(Vec3f(0.0f, Angle::degToRad(90.0f), Angle::degToRad(90.0f))) * Vec4f(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZY(Vec3f(0.0f, 0.0f, 0.0f)) * Vec4f(3, 13, 75, 1)).equals(3.0f, 13.0f, 75.0f, 1.0f, 0.0001f), verbose);

			Assertv((Transform4::rotateXZ(Vec3f(Angle::degToRad(90.0f), 0.0f, Angle::degToRad(90.0f))) * Vec4f(1, 0, 0, 1)).equals(0.0f, 0.0f, 1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXZ(Vec3f(Angle::degToRad(90.0f), 0.0f, Angle::degToRad(90.0f))) * Vec4f(0, 1, 0, 1)).equals(1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXZ(Vec3f(Angle::degToRad(90.0f), 0.0f, Angle::degToRad(90.0f))) * Vec4f(0, 0, 1, 1)).equals(0.0f, 1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXZ(Vec3f(Angle::degToRad(90.0f), 0.0f, Angle::degToRad(90.0f))) * Vec4f(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXZ(Vec3f(0.0f, 0.0f, 0.0f)) * Vec4f(3, 13, 75, 1)).equals(3.0f, 13.0f, 75.0f, 1.0f, 0.0001f), verbose);

			Assertv((Transform4::rotateZX(Vec3f(Angle::degToRad(90.0f), 0.0f, Angle::degToRad(90.0f))) * Vec4f(1, 0, 0, 1)).equals(0.0f, -1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZX(Vec3f(Angle::degToRad(90.0f), 0.0f, Angle::degToRad(90.0f))) * Vec4f(0, 1, 0, 1)).equals(0.0f, 0.0f, -1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZX(Vec3f(Angle::degToRad(90.0f), 0.0f, Angle::degToRad(90.0f))) * Vec4f(0, 0, 1, 1)).equals(1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZX(Vec3f(Angle::degToRad(90.0f), 0.0f, Angle::degToRad(90.0f))) * Vec4f(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZX(Vec3f(0.0f, 0.0f, 0.0f)) * Vec4f(3, 13, 75, 1)).equals(3.0f, 13.0f, 75.0f, 1.0f, 0.0001f), verbose);
		}
	}
	{ // Double
		// rotate*
		{ // RHS
			Rules::DefaultAxisRule = Rules::Axis::AXIS_RHS;
			Assertv((Transform4::rotateX(Angle::degToRad(90.0)) * Vec4d(1, 0, 0, 1)).equals(1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateX(Angle::degToRad(90.0)) * Vec4d(0, 1, 0, 1)).equals(0.0, 0.0, 1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateX(Angle::degToRad(90.0)) * Vec4d(0, 0, 1, 1)).equals(0.0, -1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateX(Angle::degToRad(90.0)) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateX(0.0) * Vec4d(19, 72, 56, 1)).equals(19.0, 72.0, 56.0, 1.0, 0.000001), verbose);

			Assertv((Transform4::rotateY(Angle::degToRad(90.0)) * Vec4d(1, 0, 0, 1)).equals(0.0, 0.0, -1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateY(Angle::degToRad(90.0)) * Vec4d(0, 1, 0, 1)).equals(0.0, 1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateY(Angle::degToRad(90.0)) * Vec4d(0, 0, 1, 1)).equals(1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateY(Angle::degToRad(90.0)) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateY(0.0) * Vec4d(19, 72, 56, 1)).equals(19.0, 72.0, 56.0, 1.0, 0.000001), verbose);

			Assertv((Transform4::rotateZ(Angle::degToRad(90.0)) * Vec4d(1, 0, 0, 1)).equals(0.0, 1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZ(Angle::degToRad(90.0)) * Vec4d(0, 1, 0, 1)).equals(-1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZ(Angle::degToRad(90.0)) * Vec4d(0, 0, 1, 1)).equals(0.0, 0.0, 1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZ(Angle::degToRad(90.0)) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZ(0.0) * Vec4d(19, 72, 56, 1)).equals(19.0, 72.0, 56.0, 1.0, 0.000001), verbose);
		}
		{ // LHS
			Rules::DefaultAxisRule = Rules::Axis::AXIS_LHS;
			Assertv((Transform4::rotateX(Angle::degToRad(90.0)) * Vec4d(1, 0, 0, 1)).equals(1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateX(Angle::degToRad(90.0)) * Vec4d(0, 1, 0, 1)).equals(0.0, 0.0, -1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateX(Angle::degToRad(90.0)) * Vec4d(0, 0, 1, 1)).equals(0.0, 1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateX(Angle::degToRad(90.0)) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateX(0.0) * Vec4d(19, 72, 56, 1)).equals(19.0, 72.0, 56.0, 1.0, 0.000001), verbose);

			Assertv((Transform4::rotateY(Angle::degToRad(90.0)) * Vec4d(1, 0, 0, 1)).equals(0.0, 0.0, 1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateY(Angle::degToRad(90.0)) * Vec4d(0, 1, 0, 1)).equals(0.0, 1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateY(Angle::degToRad(90.0)) * Vec4d(0, 0, 1, 1)).equals(-1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateY(Angle::degToRad(90.0)) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateY(0.0) * Vec4d(19, 72, 56, 1)).equals(19.0, 72.0, 56.0, 1.0, 0.000001), verbose);

			Assertv((Transform4::rotateZ(Angle::degToRad(90.0)) * Vec4d(1, 0, 0, 1)).equals(0.0, -1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZ(Angle::degToRad(90.0)) * Vec4d(0, 1, 0, 1)).equals(1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZ(Angle::degToRad(90.0)) * Vec4d(0, 0, 1, 1)).equals(0.0, 0.0, 1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZ(Angle::degToRad(90.0)) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZ(0.0) * Vec4d(19, 72, 56, 1)).equals(19.0, 72.0, 56.0, 1.0, 0.000001), verbose);
		}
		// rotate**
		{ // RHS
			Rules::DefaultAxisRule = Rules::Axis::AXIS_RHS;
			Assertv((Transform4::rotateXY(Vec3d(Angle::degToRad(90.0), Angle::degToRad(90.0), 0.0)) * Vec4d(1, 0, 0, 1)).equals(0.0, 1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXY(Vec3d(Angle::degToRad(90.0), Angle::degToRad(90.0), 0.0)) * Vec4d(0, 1, 0, 1)).equals(0.0, 0.0, 1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXY(Vec3d(Angle::degToRad(90.0), Angle::degToRad(90.0), 0.0)) * Vec4d(0, 0, 1, 1)).equals(1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXY(Vec3d(Angle::degToRad(90.0), Angle::degToRad(90.0), 0.0)) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXY(Vec3d(0.0, 0.0, 0.0)) * Vec4d(5, 16, 35, 1)).equals(5.0, 16.0, 35.0, 1.0, 0.000001), verbose);

			Assertv((Transform4::rotateYX(Vec3d(Angle::degToRad(90.0), Angle::degToRad(90.0), 0.0)) * Vec4d(1, 0, 0, 1)).equals(0.0, 0.0, -1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYX(Vec3d(Angle::degToRad(90.0), Angle::degToRad(90.0), 0.0)) * Vec4d(0, 1, 0, 1)).equals(1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYX(Vec3d(Angle::degToRad(90.0), Angle::degToRad(90.0), 0.0)) * Vec4d(0, 0, 1, 1)).equals(0.0, -1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYX(Vec3d(Angle::degToRad(90.0), Angle::degToRad(90.0), 0.0)) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYX(Vec3d(0.0, 0.0, 0.0)) * Vec4d(5, 16, 35, 1)).equals(5.0, 16.0, 35.0, 1.0, 0.000001), verbose);

			Assertv((Transform4::rotateYZ(Vec3d(0.0, Angle::degToRad(90.0), Angle::degToRad(90.0))) * Vec4d(1, 0, 0, 1)).equals(0.0, 1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYZ(Vec3d(0.0, Angle::degToRad(90.0), Angle::degToRad(90.0))) * Vec4d(0, 1, 0, 1)).equals(0.0, 0.0, 1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYZ(Vec3d(0.0, Angle::degToRad(90.0), Angle::degToRad(90.0))) * Vec4d(0, 0, 1, 1)).equals(1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYZ(Vec3d(0.0, Angle::degToRad(90.0), Angle::degToRad(90.0))) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYZ(Vec3d(0.0, 0.0, 0.0)) * Vec4d(5, 16, 35, 1)).equals(5.0, 16.0, 35.0, 1.0, 0.000001), verbose);

			Assertv((Transform4::rotateZY(Vec3d(0.0, Angle::degToRad(90.0), Angle::degToRad(90.0))) * Vec4d(1, 0, 0, 1)).equals(0.0, 0.0, -1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZY(Vec3d(0.0, Angle::degToRad(90.0), Angle::degToRad(90.0))) * Vec4d(0, 1, 0, 1)).equals(-1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZY(Vec3d(0.0, Angle::degToRad(90.0), Angle::degToRad(90.0))) * Vec4d(0, 0, 1, 1)).equals(0.0, 1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZY(Vec3d(0.0, Angle::degToRad(90.0), Angle::degToRad(90.0))) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZY(Vec3d(0.0, 0.0, 0.0)) * Vec4d(5, 16, 35, 1)).equals(5.0, 16.0, 35.0, 1.0, 0.000001), verbose);

			Assertv((Transform4::rotateXZ(Vec3d(Angle::degToRad(90.0), 0.0, Angle::degToRad(90.0))) * Vec4d(1, 0, 0, 1)).equals(0.0, 0.0, 1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXZ(Vec3d(Angle::degToRad(90.0), 0.0, Angle::degToRad(90.0))) * Vec4d(0, 1, 0, 1)).equals(-1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXZ(Vec3d(Angle::degToRad(90.0), 0.0, Angle::degToRad(90.0))) * Vec4d(0, 0, 1, 1)).equals(0.0, -1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXZ(Vec3d(Angle::degToRad(90.0), 0.0, Angle::degToRad(90.0))) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXZ(Vec3d(0.0, 0.0, 0.0)) * Vec4d(5, 16, 35, 1)).equals(5.0, 16.0, 35.0, 1.0, 0.000001), verbose);

			Assertv((Transform4::rotateZX(Vec3d(Angle::degToRad(90.0), 0.0, Angle::degToRad(90.0))) * Vec4d(1, 0, 0, 1)).equals(0.0, 1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZX(Vec3d(Angle::degToRad(90.0), 0.0, Angle::degToRad(90.0))) * Vec4d(0, 1, 0, 1)).equals(0.0, 0.0, 1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZX(Vec3d(Angle::degToRad(90.0), 0.0, Angle::degToRad(90.0))) * Vec4d(0, 0, 1, 1)).equals(1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZX(Vec3d(Angle::degToRad(90.0), 0.0, Angle::degToRad(90.0))) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZX(Vec3d(0.0, 0.0, 0.0)) * Vec4d(5, 16, 35, 1)).equals(5.0, 16.0, 35.0, 1.0, 0.000001), verbose);
		}
		{ // LHS
			Rules::DefaultAxisRule = Rules::Axis::AXIS_LHS;
			Assertv((Transform4::rotateXY(Vec3d(Angle::degToRad(90.0), Angle::degToRad(90.0), 0.0)) * Vec4d(1, 0, 0, 1)).equals(0.0, 1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXY(Vec3d(Angle::degToRad(90.0), Angle::degToRad(90.0), 0.0)) * Vec4d(0, 1, 0, 1)).equals(0.0, 0.0, -1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXY(Vec3d(Angle::degToRad(90.0), Angle::degToRad(90.0), 0.0)) * Vec4d(0, 0, 1, 1)).equals(-1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXY(Vec3d(Angle::degToRad(90.0), Angle::degToRad(90.0), 0.0)) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXY(Vec3d(0.0, 0.0, 0.0)) * Vec4d(3, 13, 75, 1)).equals(3.0, 13.0, 75.0, 1.0, 0.000001), verbose);

			Assertv((Transform4::rotateYX(Vec3d(Angle::degToRad(90.0), Angle::degToRad(90.0), 0.0)) * Vec4d(1, 0, 0, 1)).equals(0.0, 0.0, 1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYX(Vec3d(Angle::degToRad(90.0), Angle::degToRad(90.0), 0.0)) * Vec4d(0, 1, 0, 1)).equals(1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYX(Vec3d(Angle::degToRad(90.0), Angle::degToRad(90.0), 0.0)) * Vec4d(0, 0, 1, 1)).equals(0.0, 1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYX(Vec3d(Angle::degToRad(90.0), Angle::degToRad(90.0), 0.0)) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYX(Vec3d(0.0, 0.0, 0.0)) * Vec4d(3, 13, 75, 1)).equals(3.0, 13.0, 75.0, 1.0, 0.000001), verbose);

			Assertv((Transform4::rotateYZ(Vec3d(0.0, Angle::degToRad(90.0), Angle::degToRad(90.0))) * Vec4d(1, 0, 0, 1)).equals(0.0, -1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYZ(Vec3d(0.0, Angle::degToRad(90.0), Angle::degToRad(90.0))) * Vec4d(0, 1, 0, 1)).equals(0.0, 0.0, 1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYZ(Vec3d(0.0, Angle::degToRad(90.0), Angle::degToRad(90.0))) * Vec4d(0, 0, 1, 1)).equals(-1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYZ(Vec3d(0.0, Angle::degToRad(90.0), Angle::degToRad(90.0))) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYZ(Vec3d(0.0, 0.0, 0.0)) * Vec4d(3, 13, 75, 1)).equals(3.0, 13.0, 75.0, 1.0, 0.000001), verbose);

			Assertv((Transform4::rotateZY(Vec3d(0.0, Angle::degToRad(90.0), Angle::degToRad(90.0))) * Vec4d(1, 0, 0, 1)).equals(0.0, 0.0, 1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZY(Vec3d(0.0, Angle::degToRad(90.0), Angle::degToRad(90.0))) * Vec4d(0, 1, 0, 1)).equals(1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZY(Vec3d(0.0, Angle::degToRad(90.0), Angle::degToRad(90.0))) * Vec4d(0, 0, 1, 1)).equals(0.0, 1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZY(Vec3d(0.0, Angle::degToRad(90.0), Angle::degToRad(90.0))) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZY(Vec3d(0.0, 0.0, 0.0)) * Vec4d(3, 13, 75, 1)).equals(3.0, 13.0, 75.0, 1.0, 0.000001), verbose);

			Assertv((Transform4::rotateXZ(Vec3d(Angle::degToRad(90.0), 0.0, Angle::degToRad(90.0))) * Vec4d(1, 0, 0, 1)).equals(0.0, 0.0, 1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXZ(Vec3d(Angle::degToRad(90.0), 0.0, Angle::degToRad(90.0))) * Vec4d(0, 1, 0, 1)).equals(1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXZ(Vec3d(Angle::degToRad(90.0), 0.0, Angle::degToRad(90.0))) * Vec4d(0, 0, 1, 1)).equals(0.0, 1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXZ(Vec3d(Angle::degToRad(90.0), 0.0, Angle::degToRad(90.0))) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXZ(Vec3d(0.0, 0.0, 0.0)) * Vec4d(3, 13, 75, 1)).equals(3.0, 13.0, 75.0, 1.0, 0.000001), verbose);

			Assertv((Transform4::rotateZX(Vec3d(Angle::degToRad(90.0), 0.0, Angle::degToRad(90.0))) * Vec4d(1, 0, 0, 1)).equals(0.0, -1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZX(Vec3d(Angle::degToRad(90.0), 0.0, Angle::degToRad(90.0))) * Vec4d(0, 1, 0, 1)).equals(0.0, 0.0, -1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZX(Vec3d(Angle::degToRad(90.0), 0.0, Angle::degToRad(90.0))) * Vec4d(0, 0, 1, 1)).equals(1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZX(Vec3d(Angle::degToRad(90.0), 0.0, Angle::degToRad(90.0))) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZX(Vec3d(0.0, 0.0, 0.0)) * Vec4d(3, 13, 75, 1)).equals(3.0, 13.0, 75.0, 1.0, 0.000001), verbose);
		}
	}
	if(Assert::_num_failed_tests <= 0)
		printf("ALL GOOD!\n");
	else
	{
		puts("----------------------------------------");
		printf("# %d Failed!\n", Assert::_num_failed_tests);
	}
	return Assert::_num_failed_tests;
}