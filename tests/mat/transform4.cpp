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
	// Float
	{
		const float DEG_90 = Angle::degToRad(90.0f);
		// scale
		{
			Assertv((Transform4::scale(Vec3f(0.5f, -2.0f, 3.5f)) * Vec4f(12.6f, 36.66f, 50.08f, 1.0f)).equals(12.6f*0.5f, 36.66f*-2.0f, 50.08f*3.5f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::scale(Vec3f(0.5f, -2.0f, 3.5f)) * Vec4f(0.0f, 0.0f, 0.0f, 1.0f)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::scale(Vec3f(0.0f, 0.0f, 0.0f)) * Vec4f(12.6f, -36.66f, 50.08f, 1.0f)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
		}
		// translate
		{
			Assertv((Transform4::translate(Vec3f(12.4f, 13.5f, -16.6f)) * Vec4f(-50.0f, 6.6f, 67.0f, 1.0f)).equals(12.4f-50.0f, 13.5f+6.6f, -16.6f+67.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::translate(Vec3f(0.0f, 0.0f, 0.0f)) * Vec4f(0.0f, 0.0f, 0.0f, 1.0f)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::translate(Vec3f(12.4f, 13.5f, -16.6f)) * Vec4f(0.0f, 0.0f, 0.0f, 1.0f)).equals(12.4f, 13.5f, -16.6f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::translate(Vec3f(0.0f, 0.0f, 0.0f)) * Vec4f(12.4f, 13.5f, -16.6f, 1.0f)).equals(12.4f, 13.5f, -16.6f, 1.0f, 0.0001f), verbose);
		}
		// scaleTranslate
		{
			Assertv((Transform4::scaleTranslate(Vec3f(0.5f, -2.0f, 3.5f), Vec3f(12.4f, 13.5f, 16.6f)) * Vec4f(-50.0f, 6.6f, 67.0f, 1.0f)).equals(0.5f * -50.0f  + 12.4f, -2.0f * 6.6f + 13.5f, 3.5f * 67.0f + 16.6f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::scaleTranslate(Vec3f(0.5f, -2.0f, 3.5f), Vec3f(0.0f, 0.0f, 0.0f)) * Vec4f(0.0f, 0.0f, 0.0f, 1.0f)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::scaleTranslate(Vec3f(0.5f, -2.0f, 3.5f), Vec3f(12.4f, 13.5f, 16.6f)) * Vec4f(0.0f, 0.0f, 0.0f, 1.0f)).equals(12.4f, 13.5f, 16.6f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::scaleTranslate(Vec3f(0.5f, -2.0f, 3.5f), Vec3f(0.0f, 0.0f, 0.0f)) * Vec4f(12.4f, 13.5f, 16.6f, 1.0f)).equals(0.5f * 12.4f, -2.0f * 13.5f, 3.5f * 16.6f, 1.0f, 0.0001f), verbose);
		}
		// translateScale
		{
			Assertv((Transform4::translateScale(Vec3f(12.4f, 13.5f, 16.6f), Vec3f(0.5f, -2.0f, 3.5f)) * Vec4f(-50.0f, 6.6f, 67.0f, 1.0f)).equals(0.5f * (-50.0f + 12.4f), -2.0f * (6.6f + 13.5f), 3.5f * (67.0f + 16.6f), 1.0f, 0.0001f), verbose);
			Assertv((Transform4::translateScale(Vec3f(0.0f, 0.0f, 0.0f), Vec3f(0.5f, -2.0f, 3.5f)) * Vec4f(0.0f, 0.0f, 0.0f, 1.0f)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::translateScale(Vec3f(12.4f, 13.5f, 16.6f), Vec3f(0.5f, -2.0f, 3.5f)) * Vec4f(0.0f, 0.0f, 0.0f, 1.0f)).equals(0.5f * 12.4f, -2.0f * 13.5f, 3.5f * 16.6f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::translateScale(Vec3f(0.0f, 0.0f, 0.0f), Vec3f(0.5f, -2.0f, 3.5f)) * Vec4f(12.4f, 13.5f, 16.6f, 1.0f)).equals(0.5f * 12.4f, -2.0f * 13.5f, 3.5f * 16.6f, 1.0f, 0.0001f), verbose);
		}
		// rotate*
		{ // RHS
			Rules::DefaultAxisRule = Rules::Axis::RHS;
			Assertv((Transform4::rotateX(DEG_90) * Vec4d(1, 0, 0, 1)).equals(1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateX(DEG_90) * Vec4d(0, 1, 0, 1)).equals(0.0f, 0.0f, 1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateX(DEG_90) * Vec4d(0, 0, 1, 1)).equals(0.0f, -1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateX(DEG_90) * Vec4d(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateX(0.0f) * Vec4d(19, 72, 56, 1)).equals(19.0f, 72.0f, 56.0f, 1.0f, 0.0001f), verbose);
			
			Assertv((Transform4::rotateY(DEG_90) * Vec4d(1, 0, 0, 1)).equals(0.0f, 0.0f, -1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateY(DEG_90) * Vec4d(0, 1, 0, 1)).equals(0.0f, 1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateY(DEG_90) * Vec4d(0, 0, 1, 1)).equals(1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateY(DEG_90) * Vec4d(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateY(0.0f) * Vec4d(19, 72, 56, 1)).equals(19.0f, 72.0f, 56.0f, 1.0f, 0.0001f), verbose);

			Assertv((Transform4::rotateZ(DEG_90) * Vec4d(1, 0, 0, 1)).equals(0.0f, 1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZ(DEG_90) * Vec4d(0, 1, 0, 1)).equals(-1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZ(DEG_90) * Vec4d(0, 0, 1, 1)).equals(0.0f, 0.0f, 1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZ(DEG_90) * Vec4d(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZ(0.0f) * Vec4d(19, 72, 56, 1)).equals(19.0f, 72.0f, 56.0f, 1.0f, 0.0001f), verbose);
		}
		{ // LHS
			Rules::DefaultAxisRule = Rules::Axis::LHS;
			Assertv((Transform4::rotateX(DEG_90) * Vec4d(1, 0, 0, 1)).equals(1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateX(DEG_90) * Vec4d(0, 1, 0, 1)).equals(0.0f, 0.0f, -1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateX(DEG_90) * Vec4d(0, 0, 1, 1)).equals(0.0f, 1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateX(DEG_90) * Vec4d(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateX(0.0f) * Vec4d(19, 72, 56, 1)).equals(19.0f, 72.0f, 56.0f, 1.0f, 0.0001f), verbose);

			Assertv((Transform4::rotateY(DEG_90) * Vec4d(1, 0, 0, 1)).equals(0.0f, 0.0f, 1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateY(DEG_90) * Vec4d(0, 1, 0, 1)).equals(0.0f, 1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateY(DEG_90) * Vec4d(0, 0, 1, 1)).equals(-1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateY(DEG_90) * Vec4d(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateY(0.0f) * Vec4d(19, 72, 56, 1)).equals(19.0f, 72.0f, 56.0f, 1.0f, 0.0001f), verbose);

			Assertv((Transform4::rotateZ(DEG_90) * Vec4d(1, 0, 0, 1)).equals(0.0f, -1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZ(DEG_90) * Vec4d(0, 1, 0, 1)).equals(1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZ(DEG_90) * Vec4d(0, 0, 1, 1)).equals(0.0f, 0.0f, 1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZ(DEG_90) * Vec4d(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZ(0.0f) * Vec4d(19, 72, 56, 1)).equals(19.0f, 72.0f, 56.0f, 1.0f, 0.0001f), verbose);
		}
		// rotate**
		{ // RHS
			Rules::DefaultAxisRule = Rules::Axis::RHS;
			Assertv((Transform4::rotateXY(Vec3d(DEG_90, DEG_90, 0.0f)) * Vec4d(1, 0, 0, 1)).equals(0.0f, 1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXY(Vec3d(DEG_90, DEG_90, 0.0f)) * Vec4d(0, 1, 0, 1)).equals(0.0f, 0.0f, 1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXY(Vec3d(DEG_90, DEG_90, 0.0f)) * Vec4d(0, 0, 1, 1)).equals(1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXY(Vec3d(DEG_90, DEG_90, 0.0f)) * Vec4d(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXY(Vec3d(0.0f, 0.0f, 0.0f)) * Vec4d(5, 16, 35, 1)).equals(5.0f, 16.0f, 35.0f, 1.0f, 0.0001f), verbose);

			Assertv((Transform4::rotateYX(Vec3d(DEG_90, DEG_90, 0.0f)) * Vec4d(1, 0, 0, 1)).equals(0.0f, 0.0f, -1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYX(Vec3d(DEG_90, DEG_90, 0.0f)) * Vec4d(0, 1, 0, 1)).equals(1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYX(Vec3d(DEG_90, DEG_90, 0.0f)) * Vec4d(0, 0, 1, 1)).equals(0.0f, -1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYX(Vec3d(DEG_90, DEG_90, 0.0f)) * Vec4d(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYX(Vec3d(0.0f, 0.0f, 0.0f)) * Vec4d(5, 16, 35, 1)).equals(5.0f, 16.0f, 35.0f, 1.0f, 0.0001f), verbose);

			Assertv((Transform4::rotateYZ(Vec3d(0.0f, DEG_90, DEG_90)) * Vec4d(1, 0, 0, 1)).equals(0.0f, 1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYZ(Vec3d(0.0f, DEG_90, DEG_90)) * Vec4d(0, 1, 0, 1)).equals(0.0f, 0.0f, 1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYZ(Vec3d(0.0f, DEG_90, DEG_90)) * Vec4d(0, 0, 1, 1)).equals(1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYZ(Vec3d(0.0f, DEG_90, DEG_90)) * Vec4d(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYZ(Vec3d(0.0f, 0.0f, 0.0f)) * Vec4d(5, 16, 35, 1)).equals(5.0f, 16.0f, 35.0f, 1.0f, 0.0001f), verbose);

			Assertv((Transform4::rotateZY(Vec3d(0.0f, DEG_90, DEG_90)) * Vec4d(1, 0, 0, 1)).equals(0.0f, 0.0f, -1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZY(Vec3d(0.0f, DEG_90, DEG_90)) * Vec4d(0, 1, 0, 1)).equals(-1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZY(Vec3d(0.0f, DEG_90, DEG_90)) * Vec4d(0, 0, 1, 1)).equals(0.0f, 1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZY(Vec3d(0.0f, DEG_90, DEG_90)) * Vec4d(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZY(Vec3d(0.0f, 0.0f, 0.0f)) * Vec4d(5, 16, 35, 1)).equals(5.0f, 16.0f, 35.0f, 1.0f, 0.0001f), verbose);

			Assertv((Transform4::rotateXZ(Vec3d(DEG_90, 0.0f, DEG_90)) * Vec4d(1, 0, 0, 1)).equals(0.0f, 0.0f, 1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXZ(Vec3d(DEG_90, 0.0f, DEG_90)) * Vec4d(0, 1, 0, 1)).equals(-1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXZ(Vec3d(DEG_90, 0.0f, DEG_90)) * Vec4d(0, 0, 1, 1)).equals(0.0f, -1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXZ(Vec3d(DEG_90, 0.0f, DEG_90)) * Vec4d(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXZ(Vec3d(0.0f, 0.0f, 0.0f)) * Vec4d(5, 16, 35, 1)).equals(5.0f, 16.0f, 35.0f, 1.0f, 0.0001f), verbose);

			Assertv((Transform4::rotateZX(Vec3d(DEG_90, 0.0f, DEG_90)) * Vec4d(1, 0, 0, 1)).equals(0.0f, 1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZX(Vec3d(DEG_90, 0.0f, DEG_90)) * Vec4d(0, 1, 0, 1)).equals(0.0f, 0.0f, 1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZX(Vec3d(DEG_90, 0.0f, DEG_90)) * Vec4d(0, 0, 1, 1)).equals(1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZX(Vec3d(DEG_90, 0.0f, DEG_90)) * Vec4d(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZX(Vec3d(0.0f, 0.0f, 0.0f)) * Vec4d(5, 16, 35, 1)).equals(5.0f, 16.0f, 35.0f, 1.0f, 0.0001f), verbose);
		}
		{ // LHS
			Rules::DefaultAxisRule = Rules::Axis::LHS;
			Assertv((Transform4::rotateXY(Vec3d(DEG_90, DEG_90, 0.0f)) * Vec4d(1, 0, 0, 1)).equals(0.0f, 1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXY(Vec3d(DEG_90, DEG_90, 0.0f)) * Vec4d(0, 1, 0, 1)).equals(0.0f, 0.0f, -1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXY(Vec3d(DEG_90, DEG_90, 0.0f)) * Vec4d(0, 0, 1, 1)).equals(-1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXY(Vec3d(DEG_90, DEG_90, 0.0f)) * Vec4d(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXY(Vec3d(0.0f, 0.0f, 0.0f)) * Vec4d(3, 13, 75, 1)).equals(3.0f, 13.0f, 75.0f, 1.0f, 0.0001f), verbose);

			Assertv((Transform4::rotateYX(Vec3d(DEG_90, DEG_90, 0.0f)) * Vec4d(1, 0, 0, 1)).equals(0.0f, 0.0f, 1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYX(Vec3d(DEG_90, DEG_90, 0.0f)) * Vec4d(0, 1, 0, 1)).equals(1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYX(Vec3d(DEG_90, DEG_90, 0.0f)) * Vec4d(0, 0, 1, 1)).equals(0.0f, 1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYX(Vec3d(DEG_90, DEG_90, 0.0f)) * Vec4d(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYX(Vec3d(0.0f, 0.0f, 0.0f)) * Vec4d(3, 13, 75, 1)).equals(3.0f, 13.0f, 75.0f, 1.0f, 0.0001f), verbose);

			Assertv((Transform4::rotateYZ(Vec3d(0.0f, DEG_90, DEG_90)) * Vec4d(1, 0, 0, 1)).equals(0.0f, -1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYZ(Vec3d(0.0f, DEG_90, DEG_90)) * Vec4d(0, 1, 0, 1)).equals(0.0f, 0.0f, 1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYZ(Vec3d(0.0f, DEG_90, DEG_90)) * Vec4d(0, 0, 1, 1)).equals(-1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYZ(Vec3d(0.0f, DEG_90, DEG_90)) * Vec4d(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYZ(Vec3d(0.0f, 0.0f, 0.0f)) * Vec4d(3, 13, 75, 1)).equals(3.0f, 13.0f, 75.0f, 1.0f, 0.0001f), verbose);

			Assertv((Transform4::rotateZY(Vec3d(0.0f, DEG_90, DEG_90)) * Vec4d(1, 0, 0, 1)).equals(0.0f, 0.0f, 1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZY(Vec3d(0.0f, DEG_90, DEG_90)) * Vec4d(0, 1, 0, 1)).equals(1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZY(Vec3d(0.0f, DEG_90, DEG_90)) * Vec4d(0, 0, 1, 1)).equals(0.0f, 1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZY(Vec3d(0.0f, DEG_90, DEG_90)) * Vec4d(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZY(Vec3d(0.0f, 0.0f, 0.0f)) * Vec4d(3, 13, 75, 1)).equals(3.0f, 13.0f, 75.0f, 1.0f, 0.0001f), verbose);

			Assertv((Transform4::rotateXZ(Vec3d(DEG_90, 0.0f, DEG_90)) * Vec4d(1, 0, 0, 1)).equals(0.0f, 0.0f, 1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXZ(Vec3d(DEG_90, 0.0f, DEG_90)) * Vec4d(0, 1, 0, 1)).equals(1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXZ(Vec3d(DEG_90, 0.0f, DEG_90)) * Vec4d(0, 0, 1, 1)).equals(0.0f, 1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXZ(Vec3d(DEG_90, 0.0f, DEG_90)) * Vec4d(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXZ(Vec3d(0.0f, 0.0f, 0.0f)) * Vec4d(3, 13, 75, 1)).equals(3.0f, 13.0f, 75.0f, 1.0f, 0.0001f), verbose);

			Assertv((Transform4::rotateZX(Vec3d(DEG_90, 0.0f, DEG_90)) * Vec4d(1, 0, 0, 1)).equals(0.0f, -1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZX(Vec3d(DEG_90, 0.0f, DEG_90)) * Vec4d(0, 1, 0, 1)).equals(0.0f, 0.0f, -1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZX(Vec3d(DEG_90, 0.0f, DEG_90)) * Vec4d(0, 0, 1, 1)).equals(1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZX(Vec3d(DEG_90, 0.0f, DEG_90)) * Vec4d(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZX(Vec3d(0.0f, 0.0f, 0.0f)) * Vec4d(3, 13, 75, 1)).equals(3.0f, 13.0f, 75.0f, 1.0f, 0.0001f), verbose);
		}
		// rotate***
		{ // RHS
			Rules::DefaultAxisRule = Rules::Axis::RHS;
			Assertv((Transform4::rotateXYZ(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(1, 0, 0, 1)).equals(0.0f, 0.0f, 1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXYZ(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 1, 0, 1)).equals(0.0f, -1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXYZ(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 0, 1, 1)).equals(1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXYZ(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXYZ(Vec3d(0.0f, 0.0f, 0.0f)) * Vec4d(5, 16, 35, 1)).equals(5.0f, 16.0f, 35.0f, 1.0f, 0.0001f), verbose);

			Assertv((Transform4::rotateXZY(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(1, 0, 0, 1)).equals(0.0f, 1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXZY(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 1, 0, 1)).equals(-1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXZY(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 0, 1, 1)).equals(0.0f, 0.0f, 1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXZY(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXZY(Vec3d(0.0f, 0.0f, 0.0f))* Vec4d(5, 16, 35, 1)).equals(5.0f, 16.0f, 35.0f, 1.0f, 0.0001f), verbose);

			Assertv((Transform4::rotateYXZ(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(1, 0, 0, 1)).equals(1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYXZ(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 1, 0, 1)).equals(0.0f, 0.0f, 1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYXZ(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 0, 1, 1)).equals(0.0f, -1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYXZ(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYXZ(Vec3d(0.0f, 0.0f, 0.0f)) * Vec4d(5, 16, 35, 1)).equals(5.0f, 16.0f, 35.0f, 1.0f, 0.0001f), verbose);

			Assertv((Transform4::rotateYZX(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(1, 0, 0, 1)).equals(0.0f, 1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYZX(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 1, 0, 1)).equals(1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYZX(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 0, 1, 1)).equals(0.0f, 0.0f, -1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYZX(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYZX(Vec3d(0.0f, 0.0f, 0.0f)) * Vec4d(5, 16, 35, 1)).equals(5.0f, 16.0f, 35.0f, 1.0f, 0.0001f), verbose);

			Assertv((Transform4::rotateZXY(Vec3d(DEG_90, DEG_90, DEG_90))* Vec4d(1, 0, 0, 1)).equals(-1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZXY(Vec3d(DEG_90, DEG_90, DEG_90))* Vec4d(0, 1, 0, 1)).equals(0.0f, 0.0f, 1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZXY(Vec3d(DEG_90, DEG_90, DEG_90))* Vec4d(0, 0, 1, 1)).equals(0.0f, 1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZXY(Vec3d(DEG_90, DEG_90, DEG_90))* Vec4d(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZXY(Vec3d(0.0f, 0.0f, 0.0f))* Vec4d(5, 16, 35, 1)).equals(5.0f, 16.0f, 35.0f, 1.0f, 0.0001f), verbose);

			Assertv((Transform4::rotateZYX(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(1, 0, 0, 1)).equals(0.0f, 0.0f, -1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZYX(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 1, 0, 1)).equals(0.0f, 1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZYX(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 0, 1, 1)).equals(1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZYX(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZYX(Vec3d(0.0f, 0.0f, 0.0f)) * Vec4d(5, 16, 35, 1)).equals(5.0f, 16.0f, 35.0f, 1.0f, 0.0001f), verbose);
		}
		{ // LHS
			Rules::DefaultAxisRule = Rules::Axis::LHS;
			Assertv((Transform4::rotateXYZ(Vec3d(DEG_90, DEG_90, DEG_90))* Vec4d(1, 0, 0, 1)).equals(0.0f, 0.0f, 1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXYZ(Vec3d(DEG_90, DEG_90, DEG_90))* Vec4d(0, 1, 0, 1)).equals(0.0f, 1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXYZ(Vec3d(DEG_90, DEG_90, DEG_90))* Vec4d(0, 0, 1, 1)).equals(-1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXYZ(Vec3d(DEG_90, DEG_90, DEG_90))* Vec4d(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXYZ(Vec3d(0.0f, 0.0f, 0.0f))* Vec4d(5, 16, 35, 1)).equals(5.0f, 16.0f, 35.0f, 1.0f, 0.0001f), verbose);

			Assertv((Transform4::rotateXZY(Vec3d(DEG_90, DEG_90, DEG_90))* Vec4d(1, 0, 0, 1)).equals(0.0f, 1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXZY(Vec3d(DEG_90, DEG_90, DEG_90))* Vec4d(0, 1, 0, 1)).equals(1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXZY(Vec3d(DEG_90, DEG_90, DEG_90))* Vec4d(0, 0, 1, 1)).equals(0.0f, 0.0f, -1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXZY(Vec3d(DEG_90, DEG_90, DEG_90))* Vec4d(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateXZY(Vec3d(0.0f, 0.0f, 0.0f))* Vec4d(5, 16, 35, 1)).equals(5.0f, 16.0f, 35.0f, 1.0f, 0.0001f), verbose);

			Assertv((Transform4::rotateYXZ(Vec3d(DEG_90, DEG_90, DEG_90))* Vec4d(1, 0, 0, 1)).equals(-1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYXZ(Vec3d(DEG_90, DEG_90, DEG_90))* Vec4d(0, 1, 0, 1)).equals(0.0f, 0.0f, 1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYXZ(Vec3d(DEG_90, DEG_90, DEG_90))* Vec4d(0, 0, 1, 1)).equals(0.0f, 1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYXZ(Vec3d(DEG_90, DEG_90, DEG_90))* Vec4d(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYXZ(Vec3d(0.0f, 0.0f, 0.0f))* Vec4d(5, 16, 35, 1)).equals(5.0f, 16.0f, 35.0f, 1.0f, 0.0001f), verbose);

			Assertv((Transform4::rotateYZX(Vec3d(DEG_90, DEG_90, DEG_90))* Vec4d(1, 0, 0, 1)).equals(0.0f, -1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYZX(Vec3d(DEG_90, DEG_90, DEG_90))* Vec4d(0, 1, 0, 1)).equals(1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYZX(Vec3d(DEG_90, DEG_90, DEG_90))* Vec4d(0, 0, 1, 1)).equals(0.0f, 0.0f, 1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYZX(Vec3d(DEG_90, DEG_90, DEG_90))* Vec4d(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateYZX(Vec3d(0.0f, 0.0f, 0.0f))* Vec4d(5, 16, 35, 1)).equals(5.0f, 16.0f, 35.0f, 1.0f, 0.0001f), verbose);

			Assertv((Transform4::rotateZXY(Vec3d(DEG_90, DEG_90, DEG_90))* Vec4d(1, 0, 0, 1)).equals(1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZXY(Vec3d(DEG_90, DEG_90, DEG_90))* Vec4d(0, 1, 0, 1)).equals(0.0f, 0.0f, -1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZXY(Vec3d(DEG_90, DEG_90, DEG_90))* Vec4d(0, 0, 1, 1)).equals(0.0f, 1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZXY(Vec3d(DEG_90, DEG_90, DEG_90))* Vec4d(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZXY(Vec3d(0.0f, 0.0f, 0.0f))* Vec4d(5, 16, 35, 1)).equals(5.0f, 16.0f, 35.0f, 1.0f, 0.0001f), verbose);

			Assertv((Transform4::rotateZYX(Vec3d(DEG_90, DEG_90, DEG_90))* Vec4d(1, 0, 0, 1)).equals(0.0f, 0.0f, 1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZYX(Vec3d(DEG_90, DEG_90, DEG_90))* Vec4d(0, 1, 0, 1)).equals(0.0f, -1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZYX(Vec3d(DEG_90, DEG_90, DEG_90))* Vec4d(0, 0, 1, 1)).equals(1.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZYX(Vec3d(DEG_90, DEG_90, DEG_90))* Vec4d(0, 0, 0, 1)).equals(0.0f, 0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform4::rotateZYX(Vec3d(0.0f, 0.0f, 0.0f))* Vec4d(5, 16, 35, 1)).equals(5.0f, 16.0f, 35.0f, 1.0f, 0.0001f), verbose);
		}
	}
	// Double	
	{
		const double DEG_90 = Angle::degToRad(90.0);
		// scale
		{
			Assertv((Transform4::scale(Vec3d(0.5, -2.0, 3.5)) * Vec4d(12.6, 36.66, 50.08, 1.0)).equals(12.6 * 0.5, 36.66 * -2.0, 50.08 * 3.5, 1.0, 0.000001), verbose);
			Assertv((Transform4::scale(Vec3d(0.5, -2.0, 3.5)) * Vec4d(0.0, 0.0, 0.0, 1.0)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::scale(Vec3d(0.0, 0.0, 0.0)) * Vec4d(12.6, -36.66, 50.08, 1.0)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
		}
		// translate
		{
			Assertv((Transform4::translate(Vec3d(12.4, 13.5, -16.6)) * Vec4d(-50.0, 6.6, 67.0, 1.0)).equals(12.4 - 50.0, 13.5 + 6.6, -16.6 + 67.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::translate(Vec3d(0.0, 0.0, 0.0)) * Vec4d(0.0, 0.0, 0.0, 1.0)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::translate(Vec3d(12.4, 13.5, -16.6)) * Vec4d(0.0, 0.0, 0.0, 1.0)).equals(12.4, 13.5, -16.6, 1.0, 0.000001), verbose);
			Assertv((Transform4::translate(Vec3d(0.0, 0.0, 0.0)) * Vec4d(12.4, 13.5, -16.6, 1.0)).equals(12.4, 13.5, -16.6, 1.0, 0.000001), verbose);
		}
		// scaleTranslate
		{
			Assertv((Transform4::scaleTranslate(Vec3d(0.5, -2.0, 3.5), Vec3d(12.4, 13.5, 16.6)) * Vec4d(-50.0, 6.6, 67.0, 1.0)).equals(0.5 * -50.0  + 12.4, -2.0 * 6.6 + 13.5, 3.5 * 67.0 + 16.6, 1.0, 0.000001), verbose);
			Assertv((Transform4::scaleTranslate(Vec3d(0.5, -2.0, 3.5), Vec3d(0.0, 0.0, 0.0)) * Vec4d(0.0, 0.0, 0.0, 1.0)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::scaleTranslate(Vec3d(0.5, -2.0, 3.5), Vec3d(12.4, 13.5, 16.6)) * Vec4d(0.0, 0.0, 0.0, 1.0)).equals(12.4, 13.5, 16.6, 1.0, 0.000001), verbose);
			Assertv((Transform4::scaleTranslate(Vec3d(0.5, -2.0, 3.5), Vec3d(0.0, 0.0, 0.0)) * Vec4d(12.4, 13.5, 16.6, 1.0)).equals(0.5 * 12.4, -2.0 * 13.5, 3.5 * 16.6, 1.0, 0.000001), verbose);
		}
		// translateScale
		{
			Assertv((Transform4::translateScale(Vec3d(12.4, 13.5, 16.6), Vec3d(0.5, -2.0, 3.5)) * Vec4d(-50.0, 6.6, 67.0, 1.0)).equals(0.5 * (-50.0 + 12.4), -2.0 * (6.6 + 13.5), 3.5 * (67.0 + 16.6), 1.0, 0.000001), verbose);
			Assertv((Transform4::translateScale(Vec3d(0.0, 0.0, 0.0), Vec3d(0.5, -2.0, 3.5)) * Vec4d(0.0, 0.0, 0.0, 1.0)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::translateScale(Vec3d(12.4, 13.5, 16.6), Vec3d(0.5, -2.0, 3.5)) * Vec4d(0.0, 0.0, 0.0, 1.0)).equals(0.5 * 12.4, -2.0 * 13.5, 3.5 * 16.6, 1.0, 0.000001), verbose);
			Assertv((Transform4::translateScale(Vec3d(0.0, 0.0, 0.0), Vec3d(0.5, -2.0, 3.5)) * Vec4d(12.4, 13.5, 16.6, 1.0)).equals(0.5 * 12.4, -2.0 * 13.5, 3.5 * 16.6, 1.0, 0.000001), verbose);
		}
		// rotate*
		{ // RHS
			Rules::DefaultAxisRule = Rules::Axis::RHS;
			Assertv((Transform4::rotateX(DEG_90) * Vec4d(1, 0, 0, 1)).equals(1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateX(DEG_90) * Vec4d(0, 1, 0, 1)).equals(0.0, 0.0, 1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateX(DEG_90) * Vec4d(0, 0, 1, 1)).equals(0.0, -1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateX(DEG_90) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateX(0.0) * Vec4d(19, 72, 56, 1)).equals(19.0, 72.0, 56.0, 1.0, 0.000001), verbose);

			Assertv((Transform4::rotateY(DEG_90) * Vec4d(1, 0, 0, 1)).equals(0.0, 0.0, -1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateY(DEG_90) * Vec4d(0, 1, 0, 1)).equals(0.0, 1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateY(DEG_90) * Vec4d(0, 0, 1, 1)).equals(1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateY(DEG_90) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateY(0.0) * Vec4d(19, 72, 56, 1)).equals(19.0, 72.0, 56.0, 1.0, 0.000001), verbose);

			Assertv((Transform4::rotateZ(DEG_90) * Vec4d(1, 0, 0, 1)).equals(0.0, 1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZ(DEG_90) * Vec4d(0, 1, 0, 1)).equals(-1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZ(DEG_90) * Vec4d(0, 0, 1, 1)).equals(0.0, 0.0, 1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZ(DEG_90) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZ(0.0) * Vec4d(19, 72, 56, 1)).equals(19.0, 72.0, 56.0, 1.0, 0.000001), verbose);
		}
		{ // LHS
			Rules::DefaultAxisRule = Rules::Axis::LHS;
			Assertv((Transform4::rotateX(DEG_90) * Vec4d(1, 0, 0, 1)).equals(1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateX(DEG_90) * Vec4d(0, 1, 0, 1)).equals(0.0, 0.0, -1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateX(DEG_90) * Vec4d(0, 0, 1, 1)).equals(0.0, 1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateX(DEG_90) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateX(0.0) * Vec4d(19, 72, 56, 1)).equals(19.0, 72.0, 56.0, 1.0, 0.000001), verbose);

			Assertv((Transform4::rotateY(DEG_90) * Vec4d(1, 0, 0, 1)).equals(0.0, 0.0, 1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateY(DEG_90) * Vec4d(0, 1, 0, 1)).equals(0.0, 1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateY(DEG_90) * Vec4d(0, 0, 1, 1)).equals(-1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateY(DEG_90) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateY(0.0) * Vec4d(19, 72, 56, 1)).equals(19.0, 72.0, 56.0, 1.0, 0.000001), verbose);

			Assertv((Transform4::rotateZ(DEG_90) * Vec4d(1, 0, 0, 1)).equals(0.0, -1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZ(DEG_90) * Vec4d(0, 1, 0, 1)).equals(1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZ(DEG_90) * Vec4d(0, 0, 1, 1)).equals(0.0, 0.0, 1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZ(DEG_90) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZ(0.0) * Vec4d(19, 72, 56, 1)).equals(19.0, 72.0, 56.0, 1.0, 0.000001), verbose);
		}
		// rotate**
		{ // RHS
			Rules::DefaultAxisRule = Rules::Axis::RHS;
			Assertv((Transform4::rotateXY(Vec3d(DEG_90, DEG_90, 0.0)) * Vec4d(1, 0, 0, 1)).equals(0.0, 1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXY(Vec3d(DEG_90, DEG_90, 0.0)) * Vec4d(0, 1, 0, 1)).equals(0.0, 0.0, 1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXY(Vec3d(DEG_90, DEG_90, 0.0)) * Vec4d(0, 0, 1, 1)).equals(1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXY(Vec3d(DEG_90, DEG_90, 0.0)) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXY(Vec3d(0.0, 0.0, 0.0)) * Vec4d(5, 16, 35, 1)).equals(5.0, 16.0, 35.0, 1.0, 0.000001), verbose);

			Assertv((Transform4::rotateYX(Vec3d(DEG_90, DEG_90, 0.0)) * Vec4d(1, 0, 0, 1)).equals(0.0, 0.0, -1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYX(Vec3d(DEG_90, DEG_90, 0.0)) * Vec4d(0, 1, 0, 1)).equals(1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYX(Vec3d(DEG_90, DEG_90, 0.0)) * Vec4d(0, 0, 1, 1)).equals(0.0, -1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYX(Vec3d(DEG_90, DEG_90, 0.0)) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYX(Vec3d(0.0, 0.0, 0.0)) * Vec4d(5, 16, 35, 1)).equals(5.0, 16.0, 35.0, 1.0, 0.000001), verbose);

			Assertv((Transform4::rotateYZ(Vec3d(0.0, DEG_90, DEG_90)) * Vec4d(1, 0, 0, 1)).equals(0.0, 1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYZ(Vec3d(0.0, DEG_90, DEG_90)) * Vec4d(0, 1, 0, 1)).equals(0.0, 0.0, 1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYZ(Vec3d(0.0, DEG_90, DEG_90)) * Vec4d(0, 0, 1, 1)).equals(1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYZ(Vec3d(0.0, DEG_90, DEG_90)) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYZ(Vec3d(0.0, 0.0, 0.0)) * Vec4d(5, 16, 35, 1)).equals(5.0, 16.0, 35.0, 1.0, 0.000001), verbose);

			Assertv((Transform4::rotateZY(Vec3d(0.0, DEG_90, DEG_90)) * Vec4d(1, 0, 0, 1)).equals(0.0, 0.0, -1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZY(Vec3d(0.0, DEG_90, DEG_90)) * Vec4d(0, 1, 0, 1)).equals(-1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZY(Vec3d(0.0, DEG_90, DEG_90)) * Vec4d(0, 0, 1, 1)).equals(0.0, 1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZY(Vec3d(0.0, DEG_90, DEG_90)) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZY(Vec3d(0.0, 0.0, 0.0)) * Vec4d(5, 16, 35, 1)).equals(5.0, 16.0, 35.0, 1.0, 0.000001), verbose);

			Assertv((Transform4::rotateXZ(Vec3d(DEG_90, 0.0, DEG_90)) * Vec4d(1, 0, 0, 1)).equals(0.0, 0.0, 1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXZ(Vec3d(DEG_90, 0.0, DEG_90)) * Vec4d(0, 1, 0, 1)).equals(-1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXZ(Vec3d(DEG_90, 0.0, DEG_90)) * Vec4d(0, 0, 1, 1)).equals(0.0, -1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXZ(Vec3d(DEG_90, 0.0, DEG_90)) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXZ(Vec3d(0.0, 0.0, 0.0)) * Vec4d(5, 16, 35, 1)).equals(5.0, 16.0, 35.0, 1.0, 0.000001), verbose);

			Assertv((Transform4::rotateZX(Vec3d(DEG_90, 0.0, DEG_90)) * Vec4d(1, 0, 0, 1)).equals(0.0, 1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZX(Vec3d(DEG_90, 0.0, DEG_90)) * Vec4d(0, 1, 0, 1)).equals(0.0, 0.0, 1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZX(Vec3d(DEG_90, 0.0, DEG_90)) * Vec4d(0, 0, 1, 1)).equals(1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZX(Vec3d(DEG_90, 0.0, DEG_90)) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZX(Vec3d(0.0, 0.0, 0.0)) * Vec4d(5, 16, 35, 1)).equals(5.0, 16.0, 35.0, 1.0, 0.000001), verbose);
		}
		{ // LHS
			Rules::DefaultAxisRule = Rules::Axis::LHS;
			Assertv((Transform4::rotateXY(Vec3d(DEG_90, DEG_90, 0.0)) * Vec4d(1, 0, 0, 1)).equals(0.0, 1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXY(Vec3d(DEG_90, DEG_90, 0.0)) * Vec4d(0, 1, 0, 1)).equals(0.0, 0.0, -1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXY(Vec3d(DEG_90, DEG_90, 0.0)) * Vec4d(0, 0, 1, 1)).equals(-1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXY(Vec3d(DEG_90, DEG_90, 0.0)) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXY(Vec3d(0.0, 0.0, 0.0)) * Vec4d(3, 13, 75, 1)).equals(3.0, 13.0, 75.0, 1.0, 0.000001), verbose);

			Assertv((Transform4::rotateYX(Vec3d(DEG_90, DEG_90, 0.0)) * Vec4d(1, 0, 0, 1)).equals(0.0, 0.0, 1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYX(Vec3d(DEG_90, DEG_90, 0.0)) * Vec4d(0, 1, 0, 1)).equals(1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYX(Vec3d(DEG_90, DEG_90, 0.0)) * Vec4d(0, 0, 1, 1)).equals(0.0, 1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYX(Vec3d(DEG_90, DEG_90, 0.0)) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYX(Vec3d(0.0, 0.0, 0.0)) * Vec4d(3, 13, 75, 1)).equals(3.0, 13.0, 75.0, 1.0, 0.000001), verbose);

			Assertv((Transform4::rotateYZ(Vec3d(0.0, DEG_90, DEG_90)) * Vec4d(1, 0, 0, 1)).equals(0.0, -1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYZ(Vec3d(0.0, DEG_90, DEG_90)) * Vec4d(0, 1, 0, 1)).equals(0.0, 0.0, 1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYZ(Vec3d(0.0, DEG_90, DEG_90)) * Vec4d(0, 0, 1, 1)).equals(-1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYZ(Vec3d(0.0, DEG_90, DEG_90)) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYZ(Vec3d(0.0, 0.0, 0.0)) * Vec4d(3, 13, 75, 1)).equals(3.0, 13.0, 75.0, 1.0, 0.000001), verbose);

			Assertv((Transform4::rotateZY(Vec3d(0.0, DEG_90, DEG_90)) * Vec4d(1, 0, 0, 1)).equals(0.0, 0.0, 1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZY(Vec3d(0.0, DEG_90, DEG_90)) * Vec4d(0, 1, 0, 1)).equals(1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZY(Vec3d(0.0, DEG_90, DEG_90)) * Vec4d(0, 0, 1, 1)).equals(0.0, 1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZY(Vec3d(0.0, DEG_90, DEG_90)) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZY(Vec3d(0.0, 0.0, 0.0)) * Vec4d(3, 13, 75, 1)).equals(3.0, 13.0, 75.0, 1.0, 0.000001), verbose);

			Assertv((Transform4::rotateXZ(Vec3d(DEG_90, 0.0, DEG_90)) * Vec4d(1, 0, 0, 1)).equals(0.0, 0.0, 1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXZ(Vec3d(DEG_90, 0.0, DEG_90)) * Vec4d(0, 1, 0, 1)).equals(1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXZ(Vec3d(DEG_90, 0.0, DEG_90)) * Vec4d(0, 0, 1, 1)).equals(0.0, 1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXZ(Vec3d(DEG_90, 0.0, DEG_90)) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXZ(Vec3d(0.0, 0.0, 0.0)) * Vec4d(3, 13, 75, 1)).equals(3.0, 13.0, 75.0, 1.0, 0.000001), verbose);

			Assertv((Transform4::rotateZX(Vec3d(DEG_90, 0.0, DEG_90)) * Vec4d(1, 0, 0, 1)).equals(0.0, -1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZX(Vec3d(DEG_90, 0.0, DEG_90)) * Vec4d(0, 1, 0, 1)).equals(0.0, 0.0, -1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZX(Vec3d(DEG_90, 0.0, DEG_90)) * Vec4d(0, 0, 1, 1)).equals(1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZX(Vec3d(DEG_90, 0.0, DEG_90)) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZX(Vec3d(0.0, 0.0, 0.0)) * Vec4d(3, 13, 75, 1)).equals(3.0, 13.0, 75.0, 1.0, 0.000001), verbose);
		}
		// rotate***
		{ // RHS
			Rules::DefaultAxisRule = Rules::Axis::RHS;
			Assertv((Transform4::rotateXYZ(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(1, 0, 0, 1)).equals(0.0, 0.0, 1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXYZ(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 1, 0, 1)).equals(0.0, -1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXYZ(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 0, 1, 1)).equals(1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXYZ(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXYZ(Vec3d(0.0, 0.0, 0.0)) * Vec4d(5, 16, 35, 1)).equals(5.0, 16.0, 35.0, 1.0, 0.000001), verbose);

			Assertv((Transform4::rotateXZY(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(1, 0, 0, 1)).equals(0.0, 1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXZY(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 1, 0, 1)).equals(-1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXZY(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 0, 1, 1)).equals(0.0, 0.0, 1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXZY(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXZY(Vec3d(0.0, 0.0, 0.0)) * Vec4d(5, 16, 35, 1)).equals(5.0, 16.0, 35.0, 1.0, 0.000001), verbose);

			Assertv((Transform4::rotateYXZ(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(1, 0, 0, 1)).equals(1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYXZ(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 1, 0, 1)).equals(0.0, 0.0, 1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYXZ(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 0, 1, 1)).equals(0.0, -1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYXZ(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYXZ(Vec3d(0.0, 0.0, 0.0)) * Vec4d(5, 16, 35, 1)).equals(5.0, 16.0, 35.0, 1.0, 0.000001), verbose);

			Assertv((Transform4::rotateYZX(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(1, 0, 0, 1)).equals(0.0, 1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYZX(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 1, 0, 1)).equals(1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYZX(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 0, 1, 1)).equals(0.0, 0.0, -1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYZX(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYZX(Vec3d(0.0, 0.0, 0.0)) * Vec4d(5, 16, 35, 1)).equals(5.0, 16.0, 35.0, 1.0, 0.000001), verbose);

			Assertv((Transform4::rotateZXY(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(1, 0, 0, 1)).equals(-1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZXY(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 1, 0, 1)).equals(0.0, 0.0, 1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZXY(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 0, 1, 1)).equals(0.0, 1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZXY(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZXY(Vec3d(0.0, 0.0, 0.0)) * Vec4d(5, 16, 35, 1)).equals(5.0, 16.0, 35.0, 1.0, 0.000001), verbose);

			Assertv((Transform4::rotateZYX(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(1, 0, 0, 1)).equals(0.0, 0.0, -1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZYX(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 1, 0, 1)).equals(0.0, 1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZYX(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 0, 1, 1)).equals(1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZYX(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZYX(Vec3d(0.0, 0.0, 0.0)) * Vec4d(5, 16, 35, 1)).equals(5.0, 16.0, 35.0, 1.0, 0.000001), verbose);
		}
		{ // LHS
			Rules::DefaultAxisRule = Rules::Axis::LHS;
			Assertv((Transform4::rotateXYZ(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(1, 0, 0, 1)).equals(0.0, 0.0, 1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXYZ(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 1, 0, 1)).equals(0.0, 1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXYZ(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 0, 1, 1)).equals(-1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXYZ(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXYZ(Vec3d(0.0, 0.0, 0.0)) * Vec4d(5, 16, 35, 1)).equals(5.0, 16.0, 35.0, 1.0, 0.000001), verbose);

			Assertv((Transform4::rotateXZY(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(1, 0, 0, 1)).equals(0.0, 1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXZY(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 1, 0, 1)).equals(1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXZY(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 0, 1, 1)).equals(0.0, 0.0, -1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXZY(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateXZY(Vec3d(0.0, 0.0, 0.0)) * Vec4d(5, 16, 35, 1)).equals(5.0, 16.0, 35.0, 1.0, 0.000001), verbose);

			Assertv((Transform4::rotateYXZ(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(1, 0, 0, 1)).equals(-1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYXZ(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 1, 0, 1)).equals(0.0, 0.0, 1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYXZ(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 0, 1, 1)).equals(0.0, 1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYXZ(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYXZ(Vec3d(0.0, 0.0, 0.0)) * Vec4d(5, 16, 35, 1)).equals(5.0, 16.0, 35.0, 1.0, 0.000001), verbose);

			Assertv((Transform4::rotateYZX(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(1, 0, 0, 1)).equals(0.0, -1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYZX(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 1, 0, 1)).equals(1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYZX(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 0, 1, 1)).equals(0.0, 0.0, 1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYZX(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateYZX(Vec3d(0.0, 0.0, 0.0)) * Vec4d(5, 16, 35, 1)).equals(5.0, 16.0, 35.0, 1.0, 0.000001), verbose);

			Assertv((Transform4::rotateZXY(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(1, 0, 0, 1)).equals(1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZXY(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 1, 0, 1)).equals(0.0, 0.0, -1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZXY(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 0, 1, 1)).equals(0.0, 1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZXY(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZXY(Vec3d(0.0, 0.0, 0.0)) * Vec4d(5, 16, 35, 1)).equals(5.0, 16.0, 35.0, 1.0, 0.000001), verbose);

			Assertv((Transform4::rotateZYX(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(1, 0, 0, 1)).equals(0.0, 0.0, 1.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZYX(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 1, 0, 1)).equals(0.0, -1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZYX(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 0, 1, 1)).equals(1.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZYX(Vec3d(DEG_90, DEG_90, DEG_90)) * Vec4d(0, 0, 0, 1)).equals(0.0, 0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform4::rotateZYX(Vec3d(0.0, 0.0, 0.0)) * Vec4d(5, 16, 35, 1)).equals(5.0, 16.0, 35.0, 1.0, 0.000001), verbose);
		}
	}
	if(assert::_num_failed_tests <= 0)
		printf("ALL GOOD!\n");
	else
	{
		puts("----------------------------------------");
		printf("# %d Failed!\n", assert::_num_failed_tests);
	}
	return assert::_num_failed_tests;
}