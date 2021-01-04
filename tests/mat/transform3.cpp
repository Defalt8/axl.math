#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include "../Assert.hpp"
#include "../lib.hpp"
#include <axl.math/angle.hpp>
#include <axl.math/float.hpp>
#include <axl.math/mat/Mat3d.hpp>
#include <axl.math/mat/Mat3f.hpp>
#include <axl.math/mat/transform3.hpp>

int main(int argc, char* argv[])
{
	bool verbose = argc > 1 && (0 == strcmp(argv[1], "-v") || 0 == strcmp(argv[1], "--verbose"));
	using namespace axl;
	using namespace axl::math;
	printf("axl.math - version %hu.%hu.%hu  %s %s\n", lib::VERSION.major, lib::VERSION.minor, lib::VERSION.patch, libType(lib::LIBRARY_TYPE), buildType(lib::BUILD_TYPE));
	puts("----------------------------------------");
	// Float
	{
		const float DEG_90 = Angle::degToRad(90.0f);
		const float DEG_180 = Angle::degToRad(180.0f);
		// scale
		{
			Assertv((Transform3::scale(Vec2f(5.0f, -0.34f)) * Vec3f(-5.6f, 0.6f, 1.0f)).equals(5.0f * -5.6f, -0.34f * 0.6f, 1.0f, 0.0001f), verbose);
			Assertv((Transform3::scale(Vec2f(0.0f, 0.0f)) * Vec3f(-5.6f, 0.6f, 1.0f)).equals(0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform3::scale(Vec2f(2.0f, -0.5f)) * Vec3f(0.0f, 0.0f, 1.0f)).equals(0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform3::scale(Vec2f(0.0f, 0.0f)) * Vec3f(0.0f, 0.0f, 1.0f)).equals(0.0f, 0.0f, 1.0f, 0.0001f), verbose);
		}
		// translate
		{
			Assertv((Transform3::translate(Vec2f(-0.56f, 90.5f)) * Vec3f(0.0f, 0.0f, 1.0f)).equals(-0.56f, 90.5f, 1.0f, 0.0001f), verbose);
			Assertv((Transform3::translate(Vec2f(0.0f, 0.0f)) * Vec3f(0.0f, 0.0f, 1.0f)).equals(0.0f, 0.0f, 1.0f, 0.0001f), verbose);
		}
		// rotate
		// RHS
		{
			Rules::DefaultAxisRule = Rules::Axis::AXIS_RHS;
			Assertv((Transform3::rotate(0.0f) * Vec3f(1.0f, 0.0f, 1.0f)).equals(1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform3::rotate(DEG_90) * Vec3f(1.0f, 0.0f, 1.0f)).equals(0.0f, 1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform3::rotate(-DEG_90) * Vec3f(1.0f, 0.0f, 1.0f)).equals(0.0f, -1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform3::rotate(DEG_180) * Vec3f(1.0f, 0.0f, 1.0f)).equals(-1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform3::rotate(-DEG_180) * Vec3f(1.0f, 0.0f, 1.0f)).equals(-1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform3::rotate(0.0f) * Vec3f(0.0f, 1.0f, 1.0f)).equals(0.0f, 1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform3::rotate(DEG_90) * Vec3f(0.0f, 1.0f, 1.0f)).equals(-1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform3::rotate(-DEG_90) * Vec3f(0.0f, 1.0f, 1.0f)).equals(1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform3::rotate(DEG_180) * Vec3f(0.0f, 1.0f, 1.0f)).equals(0.0f, -1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform3::rotate(-DEG_180) * Vec3f(0.0f, 1.0f, 1.0f)).equals(0.0f, -1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform3::rotate(DEG_90) * Vec3f(0.0f, 0.0f, 1.0f)).equals(0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform3::rotate(DEG_180) * Vec3f(0.0f, 0.0f, 1.0f)).equals(0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform3::rotate(0.0f) * Vec3f(0.0f, 0.0f, 1.0f)).equals(0.0f, 0.0f, 1.0f, 0.0001f), verbose);
		}
		// LHS
		{
			Rules::DefaultAxisRule = Rules::Axis::AXIS_LHS;
			Assertv((Transform3::rotate(0.0f) * Vec3f(1.0f, 0.0f, 1.0f)).equals(1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform3::rotate(DEG_90) * Vec3f(1.0f, 0.0f, 1.0f)).equals(0.0f, -1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform3::rotate(-DEG_90) * Vec3f(1.0f, 0.0f, 1.0f)).equals(0.0f, 1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform3::rotate(DEG_180) * Vec3f(1.0f, 0.0f, 1.0f)).equals(-1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform3::rotate(-DEG_180) * Vec3f(1.0f, 0.0f, 1.0f)).equals(-1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform3::rotate(0.0f) * Vec3f(0.0f, 1.0f, 1.0f)).equals(0.0f, 1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform3::rotate(DEG_90) * Vec3f(0.0f, 1.0f, 1.0f)).equals(1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform3::rotate(-DEG_90) * Vec3f(0.0f, 1.0f, 1.0f)).equals(-1.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform3::rotate(DEG_180) * Vec3f(0.0f, 1.0f, 1.0f)).equals(0.0f, -1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform3::rotate(-DEG_180) * Vec3f(0.0f, 1.0f, 1.0f)).equals(0.0f, -1.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform3::rotate(DEG_90) * Vec3f(0.0f, 0.0f, 1.0f)).equals(0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform3::rotate(DEG_180) * Vec3f(0.0f, 0.0f, 1.0f)).equals(0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform3::rotate(0.0f) * Vec3f(0.0f, 0.0f, 1.0f)).equals(0.0f, 0.0f, 1.0f, 0.0001f), verbose);
		}
		// scaleTranslate
		{
			Assertv((Transform3::scaleTranslate(Vec2f(5.0f, -0.34f), Vec2f(-20.0f, 50.5f)) * Vec3f(-5.6f, 0.6f, 1.0f)).equals(5.0f * -5.6f - 20.0f, -0.34f * 0.6f + 50.5f, 1.0f, 0.0001f), verbose);
			Assertv((Transform3::scaleTranslate(Vec2f(0.0f, 0.0f), Vec2f(-20.0f, 50.5f)) * Vec3f(-5.6f, 0.6f, 1.0f)).equals(-20.0f, 50.5f, 1.0f, 0.0001f), verbose);
			Assertv((Transform3::scaleTranslate(Vec2f(5.0f, -0.34f), Vec2f(0.0f, 0.0f)) * Vec3f(-5.6f, 0.6f, 1.0f)).equals(5.0f * -5.6f, -0.34f * 0.6f, 1.0f, 0.0001f), verbose);
			Assertv((Transform3::scaleTranslate(Vec2f(5.0f, -0.34f), Vec2f(-20.0f, 50.5f)) * Vec3f(0.0f, 0.0f, 1.0f)).equals(-20.0f, 50.5f, 1.0f, 0.0001f), verbose);
			Assertv((Transform3::scaleTranslate(Vec2f(0.0f, 0.0f), Vec2f(0.0f, 0.0f)) * Vec3f(-5.6f, 0.6f, 1.0f)).equals(0.0f, 0.0f, 1.0f, 0.0001f), verbose);
		}
		// translateScale
		{
			Assertv((Transform3::translateScale(Vec2f(-20.0f, 50.5f), Vec2f(5.0f, -0.34f)) * Vec3f(-5.6f, 0.6f, 1.0f)).equals(5.0f * (-5.6f - 20.0f), -0.34f * (0.6f + 50.5f), 1.0f, 0.0001f), verbose);
			Assertv((Transform3::translateScale(Vec2f(-20.0f, 50.5f), Vec2f(0.0f, 0.0f)) * Vec3f(-5.6f, 0.6f, 1.0f)).equals(0.0f, 0.0f, 1.0f, 0.0001f), verbose);
			Assertv((Transform3::translateScale(Vec2f(0.0f, 0.0f), Vec2f(5.0f, -0.34f)) * Vec3f(-5.6f, 0.6f, 1.0f)).equals(5.0f * -5.6f, -0.34f * 0.6f, 1.0f, 0.0001f), verbose);
			Assertv((Transform3::translateScale(Vec2f(-20.0f, 50.5f), Vec2f(5.0f, -0.34f)) * Vec3f(0.0f, 0.0f, 1.0f)).equals(-20.0f * 5.0f, 50.5f * -0.34f, 1.0f, 0.0001f), verbose);
			Assertv((Transform3::translateScale(Vec2f(0.0f, 0.0f), Vec2f(0.0f, 0.0f)) * Vec3f(-5.6f, 0.6f, 1.0f)).equals(0.0f, 0.0f, 1.0f, 0.0001f), verbose);
		}
		// scaleRotate
		// RHS
		{
			Rules::DefaultAxisRule = Rules::Axis::AXIS_RHS;
			Assertv((Transform3::scaleRotate(Vec2f(-20.0f, 50.5f), DEG_90) * Vec3f(2.3f, 5.8f, 1.0f)).equals(Transform3::rotate(DEG_90) * Transform3::scale(Vec2f(-20.0f, 50.5f)) * Vec3f(2.3f, 5.8f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::scaleRotate(Vec2f(-20.0f, 50.5f), -DEG_90) * Vec3f(2.3f, 5.8f, 1.0f)).equals(Transform3::rotate(-DEG_90) * Transform3::scale(Vec2f(-20.0f, 50.5f)) * Vec3f(2.3f, 5.8f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::scaleRotate(Vec2f(-20.0f, 50.5f), DEG_180) * Vec3f(2.3f, 5.8f, 1.0f)).equals(Transform3::rotate(DEG_180) * Transform3::scale(Vec2f(-20.0f, 50.5f)) * Vec3f(2.3f, 5.8f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::scaleRotate(Vec2f(-20.0f, 50.5f), -DEG_180) * Vec3f(2.3f, 5.8f, 1.0f)).equals(Transform3::rotate(-DEG_180) * Transform3::scale(Vec2f(-20.0f, 50.5f)) * Vec3f(2.3f, 5.8f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::scaleRotate(Vec2f(0.0f, 0.0f), 0.0f) * Vec3f(2.3f, 5.8f, 1.0f)).equals(Transform3::rotate(0.0f) * Transform3::scale(Vec2f(0.0f, 0.0f)) * Vec3f(2.3f, 5.8f, 1.0f), 0.0001f), verbose);
		}
		// LHS
		{
			Rules::DefaultAxisRule = Rules::Axis::AXIS_LHS;
			Assertv((Transform3::scaleRotate(Vec2f(-20.0f, 50.5f), DEG_90) * Vec3f(2.3f, 5.8f, 1.0f)).equals(Transform3::rotate(DEG_90) * Transform3::scale(Vec2f(-20.0f, 50.5f)) * Vec3f(2.3f, 5.8f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::scaleRotate(Vec2f(-20.0f, 50.5f), -DEG_90) * Vec3f(2.3f, 5.8f, 1.0f)).equals(Transform3::rotate(-DEG_90) * Transform3::scale(Vec2f(-20.0f, 50.5f)) * Vec3f(2.3f, 5.8f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::scaleRotate(Vec2f(-20.0f, 50.5f), DEG_180) * Vec3f(2.3f, 5.8f, 1.0f)).equals(Transform3::rotate(DEG_180) * Transform3::scale(Vec2f(-20.0f, 50.5f)) * Vec3f(2.3f, 5.8f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::scaleRotate(Vec2f(-20.0f, 50.5f), -DEG_180) * Vec3f(2.3f, 5.8f, 1.0f)).equals(Transform3::rotate(-DEG_180) * Transform3::scale(Vec2f(-20.0f, 50.5f)) * Vec3f(2.3f, 5.8f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::scaleRotate(Vec2f(0.0f, 0.0f), 0.0f) * Vec3f(2.3f, 5.8f, 1.0f)).equals(Transform3::rotate(0.0f) * Transform3::scale(Vec2f(0.0f, 0.0f)) * Vec3f(2.3f, 5.8f, 1.0f), 0.0001f), verbose);
		}
		// rotateScale
		// RHS
		{
			Rules::DefaultAxisRule = Rules::Axis::AXIS_RHS;
			Assertv((Transform3::rotateScale(DEG_90, Vec2f(-20.0f, 50.5f)) * Vec3f(2.3f, 5.8f, 1.0f)).equals(Transform3::scale(Vec2f(-20.0f, 50.5f)) * Transform3::rotate(DEG_90) * Vec3f(2.3f, 5.8f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::rotateScale(-DEG_90, Vec2f(-20.0f, 50.5f)) * Vec3f(2.3f, 5.8f, 1.0f)).equals(Transform3::scale(Vec2f(-20.0f, 50.5f)) * Transform3::rotate(-DEG_90) * Vec3f(2.3f, 5.8f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::rotateScale(DEG_180, Vec2f(-20.0f, 50.5f)) * Vec3f(2.3f, 5.8f, 1.0f)).equals(Transform3::scale(Vec2f(-20.0f, 50.5f)) * Transform3::rotate(DEG_180) * Vec3f(2.3f, 5.8f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::rotateScale(-DEG_180, Vec2f(-20.0f, 50.5f)) * Vec3f(2.3f, 5.8f, 1.0f)).equals(Transform3::scale(Vec2f(-20.0f, 50.5f)) * Transform3::rotate(-DEG_180) * Vec3f(2.3f, 5.8f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::rotateScale(0.0f, Vec2f(0.0f, 0.0f)) * Vec3f(2.3f, 5.8f, 1.0f)).equals(Transform3::scale(Vec2f(0.0f, 0.0f)) * Transform3::rotate(0.0f)* Vec3f(2.3f, 5.8f, 1.0f), 0.0001f), verbose);
		}
		// LHS
		{
			Rules::DefaultAxisRule = Rules::Axis::AXIS_RHS;
			Assertv((Transform3::rotateScale(DEG_90, Vec2f(-20.0f, 50.5f)) * Vec3f(2.3f, 5.8f, 1.0f)).equals(Transform3::scale(Vec2f(-20.0f, 50.5f)) * Transform3::rotate(DEG_90) * Vec3f(2.3f, 5.8f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::rotateScale(-DEG_90, Vec2f(-20.0f, 50.5f)) * Vec3f(2.3f, 5.8f, 1.0f)).equals(Transform3::scale(Vec2f(-20.0f, 50.5f)) * Transform3::rotate(-DEG_90) * Vec3f(2.3f, 5.8f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::rotateScale(DEG_180, Vec2f(-20.0f, 50.5f)) * Vec3f(2.3f, 5.8f, 1.0f)).equals(Transform3::scale(Vec2f(-20.0f, 50.5f)) * Transform3::rotate(DEG_180) * Vec3f(2.3f, 5.8f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::rotateScale(-DEG_180, Vec2f(-20.0f, 50.5f)) * Vec3f(2.3f, 5.8f, 1.0f)).equals(Transform3::scale(Vec2f(-20.0f, 50.5f)) * Transform3::rotate(-DEG_180) * Vec3f(2.3f, 5.8f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::rotateScale(0.0f, Vec2f(0.0f, 0.0f)) * Vec3f(2.3f, 5.8f, 1.0f)).equals(Transform3::scale(Vec2f(0.0f, 0.0f)) * Transform3::rotate(0.0f) * Vec3f(2.3f, 5.8f, 1.0f), 0.0001f), verbose);
		}
		// translateRotate
		// RHS
		{
			Rules::DefaultAxisRule = Rules::Axis::AXIS_RHS;
			Assertv((Transform3::translateRotate(Vec2f(-20.0f, 50.5f), DEG_90) * Vec3f(2.3f, 5.8f, 1.0f)).equals(Transform3::rotate(DEG_90) * Transform3::translate(Vec2f(-20.0f, 50.5f)) * Vec3f(2.3f, 5.8f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::translateRotate(Vec2f(-20.0f, 50.5f), -DEG_90) * Vec3f(2.3f, 5.8f, 1.0f)).equals(Transform3::rotate(-DEG_90) * Transform3::translate(Vec2f(-20.0f, 50.5f)) * Vec3f(2.3f, 5.8f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::translateRotate(Vec2f(-20.0f, 50.5f), DEG_180) * Vec3f(2.3f, 5.8f, 1.0f)).equals(Transform3::rotate(DEG_180) * Transform3::translate(Vec2f(-20.0f, 50.5f)) * Vec3f(2.3f, 5.8f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::translateRotate(Vec2f(-20.0f, 50.5f), -DEG_180) * Vec3f(2.3f, 5.8f, 1.0f)).equals(Transform3::rotate(-DEG_180) * Transform3::translate(Vec2f(-20.0f, 50.5f)) * Vec3f(2.3f, 5.8f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::translateRotate(Vec2f(0.0f, 0.0f), 0.0f) * Vec3f(2.3f, 5.8f, 1.0f)).equals(Transform3::rotate(0.0f) * Transform3::translate(Vec2f(0.0f, 0.0f)) * Vec3f(2.3f, 5.8f, 1.0f), 0.0001f), verbose);
		}
		// LHS
		{
			Rules::DefaultAxisRule = Rules::Axis::AXIS_LHS;
			Assertv((Transform3::translateRotate(Vec2f(-20.0f, 50.5f), DEG_90) * Vec3f(2.3f, 5.8f, 1.0f)).equals(Transform3::rotate(DEG_90) * Transform3::translate(Vec2f(-20.0f, 50.5f)) * Vec3f(2.3f, 5.8f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::translateRotate(Vec2f(-20.0f, 50.5f), -DEG_90) * Vec3f(2.3f, 5.8f, 1.0f)).equals(Transform3::rotate(-DEG_90) * Transform3::translate(Vec2f(-20.0f, 50.5f)) * Vec3f(2.3f, 5.8f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::translateRotate(Vec2f(-20.0f, 50.5f), DEG_180) * Vec3f(2.3f, 5.8f, 1.0f)).equals(Transform3::rotate(DEG_180) * Transform3::translate(Vec2f(-20.0f, 50.5f)) * Vec3f(2.3f, 5.8f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::translateRotate(Vec2f(-20.0f, 50.5f), -DEG_180) * Vec3f(2.3f, 5.8f, 1.0f)).equals(Transform3::rotate(-DEG_180) * Transform3::translate(Vec2f(-20.0f, 50.5f)) * Vec3f(2.3f, 5.8f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::translateRotate(Vec2f(0.0f, 0.0f), 0.0f) * Vec3f(2.3f, 5.8f, 1.0f)).equals(Transform3::rotate(0.0f) * Transform3::translate(Vec2f(0.0f, 0.0f)) * Vec3f(2.3f, 5.8f, 1.0f), 0.0001f), verbose);
		}
		// rotateTranslate
		// RHS
		{
			Rules::DefaultAxisRule = Rules::Axis::AXIS_RHS;
			Assertv((Transform3::rotateTranslate(DEG_90, Vec2f(-20.0f, 50.5f)) * Vec3f(2.3f, 5.8f, 1.0f)).equals(Transform3::translate(Vec2f(-20.0f, 50.5f)) * Transform3::rotate(DEG_90)* Vec3f(2.3f, 5.8f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::rotateTranslate(-DEG_90, Vec2f(-20.0f, 50.5f)) * Vec3f(2.3f, 5.8f, 1.0f)).equals(Transform3::translate(Vec2f(-20.0f, 50.5f)) * Transform3::rotate(-DEG_90) * Vec3f(2.3f, 5.8f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::rotateTranslate(DEG_180, Vec2f(-20.0f, 50.5f)) * Vec3f(2.3f, 5.8f, 1.0f)).equals(Transform3::translate(Vec2f(-20.0f, 50.5f)) * Transform3::rotate(DEG_180)* Vec3f(2.3f, 5.8f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::rotateTranslate(-DEG_180, Vec2f(-20.0f, 50.5f)) * Vec3f(2.3f, 5.8f, 1.0f)).equals(Transform3::translate(Vec2f(-20.0f, 50.5f)) * Transform3::rotate(-DEG_180)* Vec3f(2.3f, 5.8f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::rotateTranslate(0.0f, Vec2f(0.0f, 0.0f)) * Vec3f(2.3f, 5.8f, 1.0f)).equals( Transform3::translate(Vec2f(0.0f, 0.0f)) * Transform3::rotate(0.0f) * Vec3f(2.3f, 5.8f, 1.0f), 0.0001f), verbose);
		}
		// LHS
		{
			Rules::DefaultAxisRule = Rules::Axis::AXIS_LHS;
			Assertv((Transform3::rotateTranslate(DEG_90, Vec2f(-20.0f, 50.5f))* Vec3f(2.3f, 5.8f, 1.0f)).equals(Transform3::translate(Vec2f(-20.0f, 50.5f))* Transform3::rotate(DEG_90)* Vec3f(2.3f, 5.8f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::rotateTranslate(-DEG_90, Vec2f(-20.0f, 50.5f))* Vec3f(2.3f, 5.8f, 1.0f)).equals(Transform3::translate(Vec2f(-20.0f, 50.5f))* Transform3::rotate(-DEG_90)* Vec3f(2.3f, 5.8f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::rotateTranslate(DEG_180, Vec2f(-20.0f, 50.5f))* Vec3f(2.3f, 5.8f, 1.0f)).equals(Transform3::translate(Vec2f(-20.0f, 50.5f))* Transform3::rotate(DEG_180)* Vec3f(2.3f, 5.8f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::rotateTranslate(-DEG_180, Vec2f(-20.0f, 50.5f))* Vec3f(2.3f, 5.8f, 1.0f)).equals(Transform3::translate(Vec2f(-20.0f, 50.5f))* Transform3::rotate(-DEG_180)* Vec3f(2.3f, 5.8f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::rotateTranslate(0.0f, Vec2f(0.0f, 0.0f))* Vec3f(2.3f, 5.8f, 1.0f)).equals(Transform3::translate(Vec2f(0.0f, 0.0f))* Transform3::rotate(0.0f)* Vec3f(2.3f, 5.8f, 1.0f), 0.0001f), verbose);
		}
		// scaleTranslateRotate
		// RHS
		{
			Rules::DefaultAxisRule = Rules::AXIS_RHS;
			Assertv((Transform3::scaleTranslateRotate(Vec2f(2.5f, -0.4f), Vec2f(-10.5f, -5.5f), DEG_90) * Vec3f(45.6f, -23.0f, 1.0f)).equals(Transform3::rotate(DEG_90) * Transform3::translate(Vec2f(-10.5f, -5.5f)) * Transform3::scale(Vec2f(2.5f, -0.4f)) * Vec3f(45.6f, -23.0f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::scaleTranslateRotate(Vec2f(0.0f, 0.0f), Vec2f(-10.5f, -5.5f), DEG_90) * Vec3f(45.6f, -23.0f, 1.0f)).equals(Transform3::rotate(DEG_90) * Transform3::translate(Vec2f(-10.5f, -5.5f)) * Transform3::scale(Vec2f(0.0f, 0.0f)) * Vec3f(45.6f, -23.0f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::scaleTranslateRotate(Vec2f(0.0f, 0.0f), Vec2f(0.0f, 0.0f), 0.0f) * Vec3f(45.6f, -23.0f, 1.0f)).equals(Transform3::rotate(0.0f) * Transform3::translate(Vec2f(0.0f, 0.0f)) * Transform3::scale(Vec2f(0.0f, 0.0f)) * Vec3f(45.6f, -23.0f, 1.0f), 0.0001f), verbose);
		}
		// LHS
		{
			Rules::DefaultAxisRule = Rules::AXIS_LHS;
			Assertv((Transform3::scaleTranslateRotate(Vec2f(2.5f, -0.4f), Vec2f(-10.5f, -5.5f), DEG_90) * Vec3f(45.6f, -23.0f, 1.0f)).equals(Transform3::rotate(DEG_90) * Transform3::translate(Vec2f(-10.5f, -5.5f)) * Transform3::scale(Vec2f(2.5f, -0.4f)) * Vec3f(45.6f, -23.0f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::scaleTranslateRotate(Vec2f(0.0f, 0.0f), Vec2f(-10.5f, -5.5f), DEG_90) * Vec3f(45.6f, -23.0f, 1.0f)).equals(Transform3::rotate(DEG_90) * Transform3::translate(Vec2f(-10.5f, -5.5f)) * Transform3::scale(Vec2f(0.0f, 0.0f)) * Vec3f(45.6f, -23.0f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::scaleTranslateRotate(Vec2f(0.0f, 0.0f), Vec2f(0.0f, 0.0f), 0.0f) * Vec3f(45.6f, -23.0f, 1.0f)).equals(Transform3::rotate(0.0f) * Transform3::translate(Vec2f(0.0f, 0.0f)) * Transform3::scale(Vec2f(0.0f, 0.0f)) * Vec3f(45.6f, -23.0f, 1.0f), 0.0001f), verbose);
		}
		// scaleRotateTranslate
		// RHS
		{
			Rules::DefaultAxisRule = Rules::AXIS_RHS;
			Assertv((Transform3::scaleRotateTranslate(Vec2f(2.5f, -0.4f), DEG_90, Vec2f(-10.5f, -5.5f)) * Vec3f(45.6f, -23.0f, 1.0f)).equals(Transform3::translate(Vec2f(-10.5f, -5.5f)) * Transform3::rotate(DEG_90)* Transform3::scale(Vec2f(2.5f, -0.4f)) * Vec3f(45.6f, -23.0f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::scaleRotateTranslate(Vec2f(0.0f, 0.0f), DEG_90, Vec2f(-10.5f, -5.5f)) * Vec3f(45.6f, -23.0f, 1.0f)).equals(Transform3::translate(Vec2f(-10.5f, -5.5f)) * Transform3::rotate(DEG_90)* Transform3::scale(Vec2f(0.0f, 0.0f)) * Vec3f(45.6f, -23.0f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::scaleRotateTranslate(Vec2f(0.0f, 0.0f), 0.0f, Vec2f(0.0f, 0.0f)) * Vec3f(45.6f, -23.0f, 1.0f)).equals(Transform3::translate(Vec2f(0.0f, 0.0f)) * Transform3::rotate(0.0f)* Transform3::scale(Vec2f(0.0f, 0.0f)) * Vec3f(45.6f, -23.0f, 1.0f), 0.0001f), verbose);
		}
		// LHS
		{
			Rules::DefaultAxisRule = Rules::AXIS_LHS;
			Assertv((Transform3::scaleRotateTranslate(Vec2f(2.5f, -0.4f), DEG_90, Vec2f(-10.5f, -5.5f)) * Vec3f(45.6f, -23.0f, 1.0f)).equals(Transform3::translate(Vec2f(-10.5f, -5.5f)) * Transform3::rotate(DEG_90) * Transform3::scale(Vec2f(2.5f, -0.4f)) * Vec3f(45.6f, -23.0f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::scaleRotateTranslate(Vec2f(0.0f, 0.0f), DEG_90, Vec2f(-10.5f, -5.5f)) * Vec3f(45.6f, -23.0f, 1.0f)).equals(Transform3::translate(Vec2f(-10.5f, -5.5f)) * Transform3::rotate(DEG_90) * Transform3::scale(Vec2f(0.0f, 0.0f)) * Vec3f(45.6f, -23.0f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::scaleRotateTranslate(Vec2f(0.0f, 0.0f), 0.0f, Vec2f(0.0f, 0.0f)) * Vec3f(45.6f, -23.0f, 1.0f)).equals(Transform3::translate(Vec2f(0.0f, 0.0f)) * Transform3::rotate(0.0f) * Transform3::scale(Vec2f(0.0f, 0.0f)) * Vec3f(45.6f, -23.0f, 1.0f), 0.0001f), verbose);
		}
		// translateScaleRotate
		// RHS
		{
			Rules::DefaultAxisRule = Rules::AXIS_RHS;
			Assertv((Transform3::translateScaleRotate(Vec2f(-10.5f, -5.5f), Vec2f(2.5f, -0.4f), DEG_90) * Vec3f(45.6f, -23.0f, 1.0f)).equals(Transform3::rotate(DEG_90) * Transform3::scale(Vec2f(2.5f, -0.4f)) * Transform3::translate(Vec2f(-10.5f, -5.5f)) * Vec3f(45.6f, -23.0f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::translateScaleRotate(Vec2f(-10.5f, -5.5f), Vec2f(0.0f, 0.0f), DEG_90) * Vec3f(45.6f, -23.0f, 1.0f)).equals(Transform3::rotate(DEG_90) * Transform3::scale(Vec2f(0.0f, 0.0f)) * Transform3::translate(Vec2f(-10.5f, -5.5f)) * Vec3f(45.6f, -23.0f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::translateScaleRotate(Vec2f(0.0f, 0.0f), Vec2f(0.0f, 0.0f), 0.0f) * Vec3f(45.6f, -23.0f, 1.0f)).equals(Transform3::rotate(0.0f) * Transform3::scale(Vec2f(0.0f, 0.0f)) * Transform3::translate(Vec2f(0.0f, 0.0f)) * Vec3f(45.6f, -23.0f, 1.0f), 0.0001f), verbose);
		}
		// LHS
		{
			Rules::DefaultAxisRule = Rules::AXIS_LHS;
			Assertv((Transform3::translateScaleRotate(Vec2f(-10.5f, -5.5f), Vec2f(2.5f, -0.4f), DEG_90)* Vec3f(45.6f, -23.0f, 1.0f)).equals(Transform3::rotate(DEG_90) * Transform3::scale(Vec2f(2.5f, -0.4f)) * Transform3::translate(Vec2f(-10.5f, -5.5f)) * Vec3f(45.6f, -23.0f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::translateScaleRotate(Vec2f(-10.5f, -5.5f), Vec2f(0.0f, 0.0f), DEG_90) * Vec3f(45.6f, -23.0f, 1.0f)).equals(Transform3::rotate(DEG_90) * Transform3::scale(Vec2f(0.0f, 0.0f)) * Transform3::translate(Vec2f(-10.5f, -5.5f)) * Vec3f(45.6f, -23.0f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::translateScaleRotate(Vec2f(0.0f, 0.0f), Vec2f(0.0f, 0.0f), 0.0f) * Vec3f(45.6f, -23.0f, 1.0f)).equals(Transform3::rotate(0.0f) * Transform3::scale(Vec2f(0.0f, 0.0f)) * Transform3::translate(Vec2f(0.0f, 0.0f)) * Vec3f(45.6f, -23.0f, 1.0f), 0.0001f), verbose);
		}
		// translateRotateScale
		// RHS
		{
			Rules::DefaultAxisRule = Rules::AXIS_RHS;
			Assertv((Transform3::translateRotateScale(Vec2f(-10.5f, -5.5f), DEG_90, Vec2f(2.5f, -0.4f))* Vec3f(45.6f, -23.0f, 1.0f)).equals(Transform3::scale(Vec2f(2.5f, -0.4f)) * Transform3::rotate(DEG_90) * Transform3::translate(Vec2f(-10.5f, -5.5f))* Vec3f(45.6f, -23.0f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::translateRotateScale(Vec2f(-10.5f, -5.5f), DEG_90, Vec2f(0.0f, 0.0f )) * Vec3f(45.6f, -23.0f, 1.0f)).equals(Transform3::scale(Vec2f(0.0f, 0.0f)) * Transform3::rotate(DEG_90) * Transform3::translate(Vec2f(-10.5f, -5.5f)) * Vec3f(45.6f, -23.0f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::translateRotateScale(Vec2f(0.0f, 0.0f), 0.0f, Vec2f(0.0f, 0.0f)) * Vec3f(45.6f, -23.0f, 1.0f)).equals(Transform3::scale(Vec2f(0.0f, 0.0f)) * Transform3::rotate(0.0f) * Transform3::translate(Vec2f(0.0f, 0.0f)) * Vec3f(45.6f, -23.0f, 1.0f), 0.0001f), verbose);
		}
		// LHS
		{
			Rules::DefaultAxisRule = Rules::AXIS_LHS;
			Assertv((Transform3::translateRotateScale(Vec2f(-10.5f, -5.5f), DEG_90, Vec2f(2.5f, -0.4f)) * Vec3f(45.6f, -23.0f, 1.0f)).equals(Transform3::scale(Vec2f(2.5f, -0.4f)) * Transform3::rotate(DEG_90) * Transform3::translate(Vec2f(-10.5f, -5.5f)) * Vec3f(45.6f, -23.0f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::translateRotateScale(Vec2f(-10.5f, -5.5f), DEG_90, Vec2f(0.0f, 0.0f)) * Vec3f(45.6f, -23.0f, 1.0f)).equals(Transform3::scale(Vec2f(0.0f, 0.0f)) * Transform3::rotate(DEG_90) * Transform3::translate(Vec2f(-10.5f, -5.5f)) * Vec3f(45.6f, -23.0f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::translateRotateScale(Vec2f(0.0f, 0.0f), 0.0f, Vec2f(0.0f, 0.0f)) * Vec3f(45.6f, -23.0f, 1.0f)).equals(Transform3::scale(Vec2f(0.0f, 0.0f)) * Transform3::rotate(0.0f) * Transform3::translate(Vec2f(0.0f, 0.0f)) * Vec3f(45.6f, -23.0f, 1.0f), 0.0001f), verbose);
		}
		// rotateScaleTranslate
		// RHS
		{
			Rules::DefaultAxisRule = Rules::AXIS_RHS;
			Assertv((Transform3::rotateScaleTranslate(DEG_90, Vec2f(2.5f, -0.4f), Vec2f(-10.5f, -5.5f)) * Vec3f(45.6f, -23.0f, 1.0f)).equals(Transform3::rotate(DEG_90) * Transform3::scale(Vec2f(2.5f, -0.4f)) * Transform3::translate(Vec2f(-10.5f, -5.5f)) * Vec3f(45.6f, -23.0f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::rotateScaleTranslate(DEG_90, Vec2f(0.0f, 0.0f), Vec2f(-10.5f, -5.5f)) * Vec3f(45.6f, -23.0f, 1.0f)).equals(Transform3::rotate(DEG_90) * Transform3::scale(Vec2f(0.0f, 0.0f)) * Transform3::translate(Vec2f(-10.5f, -5.5f)) * Vec3f(45.6f, -23.0f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::rotateScaleTranslate(0.0f, Vec2f(0.0f, 0.0f), Vec2f(0.0f, 0.0f)) * Vec3f(45.6f, -23.0f, 1.0f)).equals(Transform3::rotate(0.0f) * Transform3::scale(Vec2f(0.0f, 0.0f)) * Transform3::translate(Vec2f(0.0f, 0.0f)) * Vec3f(45.6f, -23.0f, 1.0f), 0.0001f), verbose);
		}
		// LHS
		{
			Rules::DefaultAxisRule = Rules::AXIS_LHS;
			Assertv((Transform3::rotateScaleTranslate(DEG_90, Vec2f(2.5f, -0.4f), Vec2f(-10.5f, -5.5f)) * Vec3f(45.6f, -23.0f, 1.0f)).equals(Transform3::rotate(DEG_90) * Transform3::scale(Vec2f(2.5f, -0.4f)) * Transform3::translate(Vec2f(-10.5f, -5.5f)) * Vec3f(45.6f, -23.0f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::rotateScaleTranslate(DEG_90, Vec2f(0.0f, 0.0f), Vec2f(-10.5f, -5.5f)) * Vec3f(45.6f, -23.0f, 1.0f)).equals(Transform3::rotate(DEG_90) * Transform3::scale(Vec2f(0.0f, 0.0f)) * Transform3::translate(Vec2f(-10.5f, -5.5f)) * Vec3f(45.6f, -23.0f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::rotateScaleTranslate(0.0f, Vec2f(0.0f, 0.0f), Vec2f(0.0f, 0.0f)) * Vec3f(45.6f, -23.0f, 1.0f)).equals(Transform3::rotate(0.0f) * Transform3::scale(Vec2f(0.0f, 0.0f)) * Transform3::translate(Vec2f(0.0f, 0.0f)) * Vec3f(45.6f, -23.0f, 1.0f), 0.0001f), verbose);
		}
		// rotateTranslateScale
		// RHS
		{
			Rules::DefaultAxisRule = Rules::AXIS_RHS;
			Assertv((Transform3::rotateTranslateScale(DEG_90, Vec2f(-10.5f, -5.5f), Vec2f(2.5f, -0.4f)) * Vec3f(45.6f, -23.0f, 1.0f)).equals(Transform3::scale(Vec2f(2.5f, -0.4f)) * Transform3::translate(Vec2f(-10.5f, -5.5f)) * Transform3::rotate(DEG_90) * Vec3f(45.6f, -23.0f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::rotateTranslateScale(DEG_90, Vec2f(-10.5f, -5.5f), Vec2f(0.0f, 0.0f)) * Vec3f(45.6f, -23.0f, 1.0f)).equals(Transform3::scale(Vec2f(0.0f, 0.0f)) * Transform3::translate(Vec2f(-10.5f, -5.5f)) * Transform3::rotate(DEG_90) * Vec3f(45.6f, -23.0f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::rotateTranslateScale(0.0f, Vec2f(0.0f, 0.0f), Vec2f(0.0f, 0.0f)) * Vec3f(45.6f, -23.0f, 1.0f)).equals(Transform3::scale(Vec2f(0.0f, 0.0f)) * Transform3::translate(Vec2f(0.0f, 0.0f)) * Transform3::rotate(0.0f) * Vec3f(45.6f, -23.0f, 1.0f), 0.0001f), verbose);
		}
		// LHS
		{
			Rules::DefaultAxisRule = Rules::AXIS_LHS;
			Assertv((Transform3::rotateTranslateScale(DEG_90, Vec2f(-10.5f, -5.5f), Vec2f(2.5f, -0.4f))* Vec3f(45.6f, -23.0f, 1.0f)).equals(Transform3::scale(Vec2f(2.5f, -0.4f))* Transform3::translate(Vec2f(-10.5f, -5.5f))* Transform3::rotate(DEG_90)* Vec3f(45.6f, -23.0f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::rotateTranslateScale(DEG_90, Vec2f(-10.5f, -5.5f), Vec2f(0.0f, 0.0f))* Vec3f(45.6f, -23.0f, 1.0f)).equals(Transform3::scale(Vec2f(0.0f, 0.0f))* Transform3::translate(Vec2f(-10.5f, -5.5f))* Transform3::rotate(DEG_90)* Vec3f(45.6f, -23.0f, 1.0f), 0.0001f), verbose);
			Assertv((Transform3::rotateTranslateScale(0.0f, Vec2f(0.0f, 0.0f), Vec2f(0.0f, 0.0f))* Vec3f(45.6f, -23.0f, 1.0f)).equals(Transform3::scale(Vec2f(0.0f, 0.0f))* Transform3::translate(Vec2f(0.0f, 0.0f))* Transform3::rotate(0.0f)* Vec3f(45.6f, -23.0f, 1.0f), 0.0001f), verbose);
		}
	}
	// Double
	{
		const double DEG_90 = Angle::degToRad(90.0);
		const double DEG_180 = Angle::degToRad(180.0);
		// scale
		{
			Assertv((Transform3::scale(Vec2d(5.0, -0.34)) * Vec3d(-5.6, 0.6, 1.0)).equals(5.0 * -5.6, -0.34 * 0.6, 1.0, 0.000001), verbose);
			Assertv((Transform3::scale(Vec2d(0.0, 0.0)) * Vec3d(-5.6, 0.6, 1.0)).equals(0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform3::scale(Vec2d(2.0, -0.5)) * Vec3d(0.0, 0.0, 1.0)).equals(0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform3::scale(Vec2d(0.0, 0.0)) * Vec3d(0.0, 0.0, 1.0)).equals(0.0, 0.0, 1.0, 0.000001), verbose);
		}
		// translate
		{
			Assertv((Transform3::translate(Vec2d(-0.56, 90.5)) * Vec3d(0.0, 0.0, 1.0)).equals(-0.56, 90.5, 1.0, 0.000001), verbose);
			Assertv((Transform3::translate(Vec2d(0.0, 0.0)) * Vec3d(0.0, 0.0, 1.0)).equals(0.0, 0.0, 1.0, 0.000001), verbose);
		}
		// rotate
		// RHS
		{
			Rules::DefaultAxisRule = Rules::Axis::AXIS_RHS;
			Assertv((Transform3::rotate(0.0) * Vec3d(1.0, 0.0, 1.0)).equals(1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform3::rotate(DEG_90) * Vec3d(1.0, 0.0, 1.0)).equals(0.0, 1.0, 1.0, 0.000001), verbose);
			Assertv((Transform3::rotate(-DEG_90) * Vec3d(1.0, 0.0, 1.0)).equals(0.0, -1.0, 1.0, 0.000001), verbose);
			Assertv((Transform3::rotate(DEG_180) * Vec3d(1.0, 0.0, 1.0)).equals(-1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform3::rotate(-DEG_180) * Vec3d(1.0, 0.0, 1.0)).equals(-1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform3::rotate(0.0) * Vec3d(0.0, 1.0, 1.0)).equals(0.0, 1.0, 1.0, 0.000001), verbose);
			Assertv((Transform3::rotate(DEG_90) * Vec3d(0.0, 1.0, 1.0)).equals(-1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform3::rotate(-DEG_90) * Vec3d(0.0, 1.0, 1.0)).equals(1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform3::rotate(DEG_180) * Vec3d(0.0, 1.0, 1.0)).equals(0.0, -1.0, 1.0, 0.000001), verbose);
			Assertv((Transform3::rotate(-DEG_180) * Vec3d(0.0, 1.0, 1.0)).equals(0.0, -1.0, 1.0, 0.000001), verbose);
			Assertv((Transform3::rotate(DEG_90) * Vec3d(0.0, 0.0, 1.0)).equals(0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform3::rotate(DEG_180) * Vec3d(0.0, 0.0, 1.0)).equals(0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform3::rotate(0.0) * Vec3d(0.0, 0.0, 1.0)).equals(0.0, 0.0, 1.0, 0.000001), verbose);
		}
		// LHS
		{
			Rules::DefaultAxisRule = Rules::Axis::AXIS_LHS;
			Assertv((Transform3::rotate(0.0) * Vec3d(1.0, 0.0, 1.0)).equals(1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform3::rotate(DEG_90) * Vec3d(1.0, 0.0, 1.0)).equals(0.0, -1.0, 1.0, 0.000001), verbose);
			Assertv((Transform3::rotate(-DEG_90) * Vec3d(1.0, 0.0, 1.0)).equals(0.0, 1.0, 1.0, 0.000001), verbose);
			Assertv((Transform3::rotate(DEG_180) * Vec3d(1.0, 0.0, 1.0)).equals(-1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform3::rotate(-DEG_180) * Vec3d(1.0, 0.0, 1.0)).equals(-1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform3::rotate(0.0) * Vec3d(0.0, 1.0, 1.0)).equals(0.0, 1.0, 1.0, 0.000001), verbose);
			Assertv((Transform3::rotate(DEG_90) * Vec3d(0.0, 1.0, 1.0)).equals(1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform3::rotate(-DEG_90) * Vec3d(0.0, 1.0, 1.0)).equals(-1.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform3::rotate(DEG_180) * Vec3d(0.0, 1.0, 1.0)).equals(0.0, -1.0, 1.0, 0.000001), verbose);
			Assertv((Transform3::rotate(-DEG_180) * Vec3d(0.0, 1.0, 1.0)).equals(0.0, -1.0, 1.0, 0.000001), verbose);
			Assertv((Transform3::rotate(DEG_90) * Vec3d(0.0, 0.0, 1.0)).equals(0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform3::rotate(DEG_180) * Vec3d(0.0, 0.0, 1.0)).equals(0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform3::rotate(0.0) * Vec3d(0.0, 0.0, 1.0)).equals(0.0, 0.0, 1.0, 0.000001), verbose);
		}
		// scaleTranslate
		{
			Assertv((Transform3::scaleTranslate(Vec2d(5.0, -0.34), Vec2d(-20.0, 50.5)) * Vec3d(-5.6, 0.6, 1.0)).equals(5.0 * -5.6 - 20.0, -0.34 * 0.6 + 50.5, 1.0, 0.000001), verbose);
			Assertv((Transform3::scaleTranslate(Vec2d(0.0, 0.0), Vec2d(-20.0, 50.5)) * Vec3d(-5.6, 0.6, 1.0)).equals(-20.0, 50.5, 1.0, 0.000001), verbose);
			Assertv((Transform3::scaleTranslate(Vec2d(5.0, -0.34), Vec2d(0.0, 0.0)) * Vec3d(-5.6, 0.6, 1.0)).equals(5.0 * -5.6, -0.34 * 0.6, 1.0, 0.000001), verbose);
			Assertv((Transform3::scaleTranslate(Vec2d(5.0, -0.34), Vec2d(-20.0, 50.5)) * Vec3d(0.0, 0.0, 1.0)).equals(-20.0, 50.5, 1.0, 0.000001), verbose);
			Assertv((Transform3::scaleTranslate(Vec2d(0.0, 0.0), Vec2d(0.0, 0.0)) * Vec3d(-5.6, 0.6, 1.0)).equals(0.0, 0.0, 1.0, 0.000001), verbose);
		}
		// translateScale
		{
			Assertv((Transform3::translateScale(Vec2d(-20.0, 50.5), Vec2d(5.0, -0.34)) * Vec3d(-5.6, 0.6, 1.0)).equals(5.0 * (-5.6 - 20.0), -0.34 * (0.6 + 50.5), 1.0, 0.000001), verbose);
			Assertv((Transform3::translateScale(Vec2d(-20.0, 50.5), Vec2d(0.0, 0.0)) * Vec3d(-5.6, 0.6, 1.0)).equals(0.0, 0.0, 1.0, 0.000001), verbose);
			Assertv((Transform3::translateScale(Vec2d(0.0, 0.0), Vec2d(5.0, -0.34)) * Vec3d(-5.6, 0.6, 1.0)).equals(5.0 * -5.6, -0.34 * 0.6, 1.0, 0.000001), verbose);
			Assertv((Transform3::translateScale(Vec2d(-20.0, 50.5), Vec2d(5.0, -0.34)) * Vec3d(0.0, 0.0, 1.0)).equals(-20.0 * 5.0, 50.5 * -0.34, 1.0, 0.000001), verbose);
			Assertv((Transform3::translateScale(Vec2d(0.0, 0.0), Vec2d(0.0, 0.0)) * Vec3d(-5.6, 0.6, 1.0)).equals(0.0, 0.0, 1.0, 0.000001), verbose);
		}
		// scaleRotate
		// RHS
		{
			Rules::DefaultAxisRule = Rules::Axis::AXIS_RHS;
			Assertv((Transform3::scaleRotate(Vec2d(-20.0, 50.5), DEG_90) * Vec3d(2.3, 5.8, 1.0)).equals(Transform3::rotate(DEG_90) * Transform3::scale(Vec2d(-20.0, 50.5)) * Vec3d(2.3, 5.8, 1.0), 0.000001), verbose);
			Assertv((Transform3::scaleRotate(Vec2d(-20.0, 50.5), -DEG_90) * Vec3d(2.3, 5.8, 1.0)).equals(Transform3::rotate(-DEG_90) * Transform3::scale(Vec2d(-20.0, 50.5)) * Vec3d(2.3, 5.8, 1.0), 0.000001), verbose);
			Assertv((Transform3::scaleRotate(Vec2d(-20.0, 50.5), DEG_180) * Vec3d(2.3, 5.8, 1.0)).equals(Transform3::rotate(DEG_180) * Transform3::scale(Vec2d(-20.0, 50.5)) * Vec3d(2.3, 5.8, 1.0), 0.000001), verbose);
			Assertv((Transform3::scaleRotate(Vec2d(-20.0, 50.5), -DEG_180) * Vec3d(2.3, 5.8, 1.0)).equals(Transform3::rotate(-DEG_180) * Transform3::scale(Vec2d(-20.0, 50.5)) * Vec3d(2.3, 5.8, 1.0), 0.000001), verbose);
			Assertv((Transform3::scaleRotate(Vec2d(0.0, 0.0), 0.0) * Vec3d(2.3, 5.8, 1.0)).equals(Transform3::rotate(0.0) * Transform3::scale(Vec2d(0.0, 0.0)) * Vec3d(2.3, 5.8, 1.0), 0.000001), verbose);
		}
		// LHS
		{
			Rules::DefaultAxisRule = Rules::Axis::AXIS_LHS;
			Assertv((Transform3::scaleRotate(Vec2d(-20.0, 50.5), DEG_90) * Vec3d(2.3, 5.8, 1.0)).equals(Transform3::rotate(DEG_90) * Transform3::scale(Vec2d(-20.0, 50.5)) * Vec3d(2.3, 5.8, 1.0), 0.000001), verbose);
			Assertv((Transform3::scaleRotate(Vec2d(-20.0, 50.5), -DEG_90) * Vec3d(2.3, 5.8, 1.0)).equals(Transform3::rotate(-DEG_90) * Transform3::scale(Vec2d(-20.0, 50.5)) * Vec3d(2.3, 5.8, 1.0), 0.000001), verbose);
			Assertv((Transform3::scaleRotate(Vec2d(-20.0, 50.5), DEG_180) * Vec3d(2.3, 5.8, 1.0)).equals(Transform3::rotate(DEG_180) * Transform3::scale(Vec2d(-20.0, 50.5)) * Vec3d(2.3, 5.8, 1.0), 0.000001), verbose);
			Assertv((Transform3::scaleRotate(Vec2d(-20.0, 50.5), -DEG_180) * Vec3d(2.3, 5.8, 1.0)).equals(Transform3::rotate(-DEG_180) * Transform3::scale(Vec2d(-20.0, 50.5)) * Vec3d(2.3, 5.8, 1.0), 0.000001), verbose);
			Assertv((Transform3::scaleRotate(Vec2d(0.0, 0.0), 0.0) * Vec3d(2.3, 5.8, 1.0)).equals(Transform3::rotate(0.0) * Transform3::scale(Vec2d(0.0, 0.0)) * Vec3d(2.3, 5.8, 1.0), 0.000001), verbose);
		}
		// rotateScale
		// RHS
		{
			Rules::DefaultAxisRule = Rules::Axis::AXIS_RHS;
			Assertv((Transform3::rotateScale(DEG_90, Vec2d(-20.0, 50.5)) * Vec3d(2.3, 5.8, 1.0)).equals(Transform3::scale(Vec2d(-20.0, 50.5)) * Transform3::rotate(DEG_90) * Vec3d(2.3, 5.8, 1.0), 0.000001), verbose);
			Assertv((Transform3::rotateScale(-DEG_90, Vec2d(-20.0, 50.5)) * Vec3d(2.3, 5.8, 1.0)).equals(Transform3::scale(Vec2d(-20.0, 50.5)) * Transform3::rotate(-DEG_90) * Vec3d(2.3, 5.8, 1.0), 0.000001), verbose);
			Assertv((Transform3::rotateScale(DEG_180, Vec2d(-20.0, 50.5)) * Vec3d(2.3, 5.8, 1.0)).equals(Transform3::scale(Vec2d(-20.0, 50.5)) * Transform3::rotate(DEG_180) * Vec3d(2.3, 5.8, 1.0), 0.000001), verbose);
			Assertv((Transform3::rotateScale(-DEG_180, Vec2d(-20.0, 50.5)) * Vec3d(2.3, 5.8, 1.0)).equals(Transform3::scale(Vec2d(-20.0, 50.5)) * Transform3::rotate(-DEG_180) * Vec3d(2.3, 5.8, 1.0), 0.000001), verbose);
			Assertv((Transform3::rotateScale(0.0, Vec2d(0.0, 0.0)) * Vec3d(2.3, 5.8, 1.0)).equals(Transform3::scale(Vec2d(0.0, 0.0)) * Transform3::rotate(0.0) * Vec3d(2.3, 5.8, 1.0), 0.000001), verbose);
		}
		// LHS
		{
			Rules::DefaultAxisRule = Rules::Axis::AXIS_RHS;
			Assertv((Transform3::rotateScale(DEG_90, Vec2d(-20.0, 50.5)) * Vec3d(2.3, 5.8, 1.0)).equals(Transform3::scale(Vec2d(-20.0, 50.5)) * Transform3::rotate(DEG_90) * Vec3d(2.3, 5.8, 1.0), 0.000001), verbose);
			Assertv((Transform3::rotateScale(-DEG_90, Vec2d(-20.0, 50.5)) * Vec3d(2.3, 5.8, 1.0)).equals(Transform3::scale(Vec2d(-20.0, 50.5)) * Transform3::rotate(-DEG_90) * Vec3d(2.3, 5.8, 1.0), 0.000001), verbose);
			Assertv((Transform3::rotateScale(DEG_180, Vec2d(-20.0, 50.5)) * Vec3d(2.3, 5.8, 1.0)).equals(Transform3::scale(Vec2d(-20.0, 50.5)) * Transform3::rotate(DEG_180) * Vec3d(2.3, 5.8, 1.0), 0.000001), verbose);
			Assertv((Transform3::rotateScale(-DEG_180, Vec2d(-20.0, 50.5)) * Vec3d(2.3, 5.8, 1.0)).equals(Transform3::scale(Vec2d(-20.0, 50.5)) * Transform3::rotate(-DEG_180) * Vec3d(2.3, 5.8, 1.0), 0.000001), verbose);
			Assertv((Transform3::rotateScale(0.0, Vec2d(0.0, 0.0)) * Vec3d(2.3, 5.8, 1.0)).equals(Transform3::scale(Vec2d(0.0, 0.0)) * Transform3::rotate(0.0) * Vec3d(2.3, 5.8, 1.0), 0.000001), verbose);
		}
		// translateRotate
		// RHS
		{
			Rules::DefaultAxisRule = Rules::Axis::AXIS_RHS;
			Assertv((Transform3::translateRotate(Vec2d(-20.0, 50.5), DEG_90) * Vec3d(2.3, 5.8, 1.0)).equals(Transform3::rotate(DEG_90) * Transform3::translate(Vec2d(-20.0, 50.5)) * Vec3d(2.3, 5.8, 1.0), 0.000001), verbose);
			Assertv((Transform3::translateRotate(Vec2d(-20.0, 50.5), -DEG_90) * Vec3d(2.3, 5.8, 1.0)).equals(Transform3::rotate(-DEG_90) * Transform3::translate(Vec2d(-20.0, 50.5)) * Vec3d(2.3, 5.8, 1.0), 0.000001), verbose);
			Assertv((Transform3::translateRotate(Vec2d(-20.0, 50.5), DEG_180) * Vec3d(2.3, 5.8, 1.0)).equals(Transform3::rotate(DEG_180) * Transform3::translate(Vec2d(-20.0, 50.5)) * Vec3d(2.3, 5.8, 1.0), 0.000001), verbose);
			Assertv((Transform3::translateRotate(Vec2d(-20.0, 50.5), -DEG_180) * Vec3d(2.3, 5.8, 1.0)).equals(Transform3::rotate(-DEG_180) * Transform3::translate(Vec2d(-20.0, 50.5)) * Vec3d(2.3, 5.8, 1.0), 0.000001), verbose);
			Assertv((Transform3::translateRotate(Vec2d(0.0, 0.0), 0.0) * Vec3d(2.3, 5.8, 1.0)).equals(Transform3::rotate(0.0) * Transform3::translate(Vec2d(0.0, 0.0)) * Vec3d(2.3, 5.8, 1.0), 0.000001), verbose);
		}
		// LHS
		{
			Rules::DefaultAxisRule = Rules::Axis::AXIS_LHS;
			Assertv((Transform3::translateRotate(Vec2d(-20.0, 50.5), DEG_90) * Vec3d(2.3, 5.8, 1.0)).equals(Transform3::rotate(DEG_90) * Transform3::translate(Vec2d(-20.0, 50.5)) * Vec3d(2.3, 5.8, 1.0), 0.000001), verbose);
			Assertv((Transform3::translateRotate(Vec2d(-20.0, 50.5), -DEG_90) * Vec3d(2.3, 5.8, 1.0)).equals(Transform3::rotate(-DEG_90) * Transform3::translate(Vec2d(-20.0, 50.5)) * Vec3d(2.3, 5.8, 1.0), 0.000001), verbose);
			Assertv((Transform3::translateRotate(Vec2d(-20.0, 50.5), DEG_180) * Vec3d(2.3, 5.8, 1.0)).equals(Transform3::rotate(DEG_180) * Transform3::translate(Vec2d(-20.0, 50.5)) * Vec3d(2.3, 5.8, 1.0), 0.000001), verbose);
			Assertv((Transform3::translateRotate(Vec2d(-20.0, 50.5), -DEG_180) * Vec3d(2.3, 5.8, 1.0)).equals(Transform3::rotate(-DEG_180) * Transform3::translate(Vec2d(-20.0, 50.5)) * Vec3d(2.3, 5.8, 1.0), 0.000001), verbose);
			Assertv((Transform3::translateRotate(Vec2d(0.0, 0.0), 0.0) * Vec3d(2.3, 5.8, 1.0)).equals(Transform3::rotate(0.0) * Transform3::translate(Vec2d(0.0, 0.0)) * Vec3d(2.3, 5.8, 1.0), 0.000001), verbose);
		}
		// rotateTranslate
		// RHS
		{
			Rules::DefaultAxisRule = Rules::Axis::AXIS_RHS;
			Assertv((Transform3::rotateTranslate(DEG_90, Vec2d(-20.0, 50.5)) * Vec3d(2.3, 5.8, 1.0)).equals(Transform3::translate(Vec2d(-20.0, 50.5)) * Transform3::rotate(DEG_90) * Vec3d(2.3, 5.8, 1.0), 0.000001), verbose);
			Assertv((Transform3::rotateTranslate(-DEG_90, Vec2d(-20.0, 50.5)) * Vec3d(2.3, 5.8, 1.0)).equals(Transform3::translate(Vec2d(-20.0, 50.5)) * Transform3::rotate(-DEG_90) * Vec3d(2.3, 5.8, 1.0), 0.000001), verbose);
			Assertv((Transform3::rotateTranslate(DEG_180, Vec2d(-20.0, 50.5)) * Vec3d(2.3, 5.8, 1.0)).equals(Transform3::translate(Vec2d(-20.0, 50.5)) * Transform3::rotate(DEG_180) * Vec3d(2.3, 5.8, 1.0), 0.000001), verbose);
			Assertv((Transform3::rotateTranslate(-DEG_180, Vec2d(-20.0, 50.5)) * Vec3d(2.3, 5.8, 1.0)).equals(Transform3::translate(Vec2d(-20.0, 50.5)) * Transform3::rotate(-DEG_180) * Vec3d(2.3, 5.8, 1.0), 0.000001), verbose);
			Assertv((Transform3::rotateTranslate(0.0, Vec2d(0.0, 0.0)) * Vec3d(2.3, 5.8, 1.0)).equals(Transform3::translate(Vec2d(0.0, 0.0)) * Transform3::rotate(0.0) * Vec3d(2.3, 5.8, 1.0), 0.000001), verbose);
		}
		// LHS
		{
			Rules::DefaultAxisRule = Rules::Axis::AXIS_LHS;
			Assertv((Transform3::rotateTranslate(DEG_90, Vec2d(-20.0, 50.5)) * Vec3d(2.3, 5.8, 1.0)).equals(Transform3::translate(Vec2d(-20.0, 50.5)) * Transform3::rotate(DEG_90) * Vec3d(2.3, 5.8, 1.0), 0.000001), verbose);
			Assertv((Transform3::rotateTranslate(-DEG_90, Vec2d(-20.0, 50.5)) * Vec3d(2.3, 5.8, 1.0)).equals(Transform3::translate(Vec2d(-20.0, 50.5)) * Transform3::rotate(-DEG_90) * Vec3d(2.3, 5.8, 1.0), 0.000001), verbose);
			Assertv((Transform3::rotateTranslate(DEG_180, Vec2d(-20.0, 50.5)) * Vec3d(2.3, 5.8, 1.0)).equals(Transform3::translate(Vec2d(-20.0, 50.5)) * Transform3::rotate(DEG_180) * Vec3d(2.3, 5.8, 1.0), 0.000001), verbose);
			Assertv((Transform3::rotateTranslate(-DEG_180, Vec2d(-20.0, 50.5)) * Vec3d(2.3, 5.8, 1.0)).equals(Transform3::translate(Vec2d(-20.0, 50.5)) * Transform3::rotate(-DEG_180) * Vec3d(2.3, 5.8, 1.0), 0.000001), verbose);
			Assertv((Transform3::rotateTranslate(0.0, Vec2d(0.0, 0.0)) * Vec3d(2.3, 5.8, 1.0)).equals(Transform3::translate(Vec2d(0.0, 0.0)) * Transform3::rotate(0.0) * Vec3d(2.3, 5.8, 1.0), 0.000001), verbose);
		}
		// scaleTranslateRotate
		// RHS
		{
			Rules::DefaultAxisRule = Rules::AXIS_RHS;
			Assertv((Transform3::scaleTranslateRotate(Vec2d(2.5, -0.4), Vec2d(-10.5, -5.5), DEG_90) * Vec3d(45.6, -23.0, 1.0)).equals(Transform3::rotate(DEG_90) * Transform3::translate(Vec2d(-10.5, -5.5)) * Transform3::scale(Vec2d(2.5, -0.4)) * Vec3d(45.6, -23.0, 1.0), 0.000001), verbose);
			Assertv((Transform3::scaleTranslateRotate(Vec2d(0.0, 0.0), Vec2d(-10.5, -5.5), DEG_90) * Vec3d(45.6, -23.0, 1.0)).equals(Transform3::rotate(DEG_90) * Transform3::translate(Vec2d(-10.5, -5.5)) * Transform3::scale(Vec2d(0.0, 0.0)) * Vec3d(45.6, -23.0, 1.0), 0.000001), verbose);
			Assertv((Transform3::scaleTranslateRotate(Vec2d(0.0, 0.0), Vec2d(0.0, 0.0), 0.0) * Vec3d(45.6, -23.0, 1.0)).equals(Transform3::rotate(0.0) * Transform3::translate(Vec2d(0.0, 0.0)) * Transform3::scale(Vec2d(0.0, 0.0)) * Vec3d(45.6, -23.0, 1.0), 0.000001), verbose);
		}
		// LHS
		{
			Rules::DefaultAxisRule = Rules::AXIS_LHS;
			Assertv((Transform3::scaleTranslateRotate(Vec2d(2.5, -0.4), Vec2d(-10.5, -5.5), DEG_90) * Vec3d(45.6, -23.0, 1.0)).equals(Transform3::rotate(DEG_90) * Transform3::translate(Vec2d(-10.5, -5.5)) * Transform3::scale(Vec2d(2.5, -0.4)) * Vec3d(45.6, -23.0, 1.0), 0.000001), verbose);
			Assertv((Transform3::scaleTranslateRotate(Vec2d(0.0, 0.0), Vec2d(-10.5, -5.5), DEG_90) * Vec3d(45.6, -23.0, 1.0)).equals(Transform3::rotate(DEG_90) * Transform3::translate(Vec2d(-10.5, -5.5)) * Transform3::scale(Vec2d(0.0, 0.0)) * Vec3d(45.6, -23.0, 1.0), 0.000001), verbose);
			Assertv((Transform3::scaleTranslateRotate(Vec2d(0.0, 0.0), Vec2d(0.0, 0.0), 0.0) * Vec3d(45.6, -23.0, 1.0)).equals(Transform3::rotate(0.0) * Transform3::translate(Vec2d(0.0, 0.0)) * Transform3::scale(Vec2d(0.0, 0.0)) * Vec3d(45.6, -23.0, 1.0), 0.000001), verbose);
		}
		// scaleRotateTranslate
		// RHS
		{
			Rules::DefaultAxisRule = Rules::AXIS_RHS;
			Assertv((Transform3::scaleRotateTranslate(Vec2d(2.5, -0.4), DEG_90, Vec2d(-10.5, -5.5)) * Vec3d(45.6, -23.0, 1.0)).equals(Transform3::translate(Vec2d(-10.5, -5.5)) * Transform3::rotate(DEG_90) * Transform3::scale(Vec2d(2.5, -0.4)) * Vec3d(45.6, -23.0, 1.0), 0.000001), verbose);
			Assertv((Transform3::scaleRotateTranslate(Vec2d(0.0, 0.0), DEG_90, Vec2d(-10.5, -5.5)) * Vec3d(45.6, -23.0, 1.0)).equals(Transform3::translate(Vec2d(-10.5, -5.5)) * Transform3::rotate(DEG_90) * Transform3::scale(Vec2d(0.0, 0.0)) * Vec3d(45.6, -23.0, 1.0), 0.000001), verbose);
			Assertv((Transform3::scaleRotateTranslate(Vec2d(0.0, 0.0), 0.0, Vec2d(0.0, 0.0)) * Vec3d(45.6, -23.0, 1.0)).equals(Transform3::translate(Vec2d(0.0, 0.0)) * Transform3::rotate(0.0) * Transform3::scale(Vec2d(0.0, 0.0)) * Vec3d(45.6, -23.0, 1.0), 0.000001), verbose);
		}
		// LHS
		{
			Rules::DefaultAxisRule = Rules::AXIS_LHS;
			Assertv((Transform3::scaleRotateTranslate(Vec2d(2.5, -0.4), DEG_90, Vec2d(-10.5, -5.5)) * Vec3d(45.6, -23.0, 1.0)).equals(Transform3::translate(Vec2d(-10.5, -5.5)) * Transform3::rotate(DEG_90) * Transform3::scale(Vec2d(2.5, -0.4)) * Vec3d(45.6, -23.0, 1.0), 0.000001), verbose);
			Assertv((Transform3::scaleRotateTranslate(Vec2d(0.0, 0.0), DEG_90, Vec2d(-10.5, -5.5)) * Vec3d(45.6, -23.0, 1.0)).equals(Transform3::translate(Vec2d(-10.5, -5.5)) * Transform3::rotate(DEG_90) * Transform3::scale(Vec2d(0.0, 0.0)) * Vec3d(45.6, -23.0, 1.0), 0.000001), verbose);
			Assertv((Transform3::scaleRotateTranslate(Vec2d(0.0, 0.0), 0.0, Vec2d(0.0, 0.0)) * Vec3d(45.6, -23.0, 1.0)).equals(Transform3::translate(Vec2d(0.0, 0.0)) * Transform3::rotate(0.0) * Transform3::scale(Vec2d(0.0, 0.0)) * Vec3d(45.6, -23.0, 1.0), 0.000001), verbose);
		}
		// translateScaleRotate
		// RHS
		{
			Rules::DefaultAxisRule = Rules::AXIS_RHS;
			Assertv((Transform3::translateScaleRotate(Vec2d(-10.5, -5.5), Vec2d(2.5, -0.4), DEG_90) * Vec3d(45.6, -23.0, 1.0)).equals(Transform3::rotate(DEG_90) * Transform3::scale(Vec2d(2.5, -0.4)) * Transform3::translate(Vec2d(-10.5, -5.5)) * Vec3d(45.6, -23.0, 1.0), 0.000001), verbose);
			Assertv((Transform3::translateScaleRotate(Vec2d(-10.5, -5.5), Vec2d(0.0, 0.0), DEG_90) * Vec3d(45.6, -23.0, 1.0)).equals(Transform3::rotate(DEG_90) * Transform3::scale(Vec2d(0.0, 0.0)) * Transform3::translate(Vec2d(-10.5, -5.5)) * Vec3d(45.6, -23.0, 1.0), 0.000001), verbose);
			Assertv((Transform3::translateScaleRotate(Vec2d(0.0, 0.0), Vec2d(0.0, 0.0), 0.0) * Vec3d(45.6, -23.0, 1.0)).equals(Transform3::rotate(0.0) * Transform3::scale(Vec2d(0.0, 0.0)) * Transform3::translate(Vec2d(0.0, 0.0)) * Vec3d(45.6, -23.0, 1.0), 0.000001), verbose);
		}
		// LHS
		{
			Rules::DefaultAxisRule = Rules::AXIS_LHS;
			Assertv((Transform3::translateScaleRotate(Vec2d(-10.5, -5.5), Vec2d(2.5, -0.4), DEG_90) * Vec3d(45.6, -23.0, 1.0)).equals(Transform3::rotate(DEG_90) * Transform3::scale(Vec2d(2.5, -0.4)) * Transform3::translate(Vec2d(-10.5, -5.5)) * Vec3d(45.6, -23.0, 1.0), 0.000001), verbose);
			Assertv((Transform3::translateScaleRotate(Vec2d(-10.5, -5.5), Vec2d(0.0, 0.0), DEG_90) * Vec3d(45.6, -23.0, 1.0)).equals(Transform3::rotate(DEG_90) * Transform3::scale(Vec2d(0.0, 0.0)) * Transform3::translate(Vec2d(-10.5, -5.5)) * Vec3d(45.6, -23.0, 1.0), 0.000001), verbose);
			Assertv((Transform3::translateScaleRotate(Vec2d(0.0, 0.0), Vec2d(0.0, 0.0), 0.0) * Vec3d(45.6, -23.0, 1.0)).equals(Transform3::rotate(0.0) * Transform3::scale(Vec2d(0.0, 0.0)) * Transform3::translate(Vec2d(0.0, 0.0)) * Vec3d(45.6, -23.0, 1.0), 0.000001), verbose);
		}
		// translateRotateScale
		// RHS
		{
			Rules::DefaultAxisRule = Rules::AXIS_RHS;
			Assertv((Transform3::translateRotateScale(Vec2d(-10.5, -5.5), DEG_90, Vec2d(2.5, -0.4)) * Vec3d(45.6, -23.0, 1.0)).equals(Transform3::scale(Vec2d(2.5, -0.4)) * Transform3::rotate(DEG_90) * Transform3::translate(Vec2d(-10.5, -5.5)) * Vec3d(45.6, -23.0, 1.0), 0.000001), verbose);
			Assertv((Transform3::translateRotateScale(Vec2d(-10.5, -5.5), DEG_90, Vec2d(0.0, 0.0)) * Vec3d(45.6, -23.0, 1.0)).equals(Transform3::scale(Vec2d(0.0, 0.0)) * Transform3::rotate(DEG_90) * Transform3::translate(Vec2d(-10.5, -5.5)) * Vec3d(45.6, -23.0, 1.0), 0.000001), verbose);
			Assertv((Transform3::translateRotateScale(Vec2d(0.0, 0.0), 0.0, Vec2d(0.0, 0.0)) * Vec3d(45.6, -23.0, 1.0)).equals(Transform3::scale(Vec2d(0.0, 0.0)) * Transform3::rotate(0.0) * Transform3::translate(Vec2d(0.0, 0.0)) * Vec3d(45.6, -23.0, 1.0), 0.000001), verbose);
		}
		// LHS
		{
			Rules::DefaultAxisRule = Rules::AXIS_LHS;
			Assertv((Transform3::translateRotateScale(Vec2d(-10.5, -5.5), DEG_90, Vec2d(2.5, -0.4)) * Vec3d(45.6, -23.0, 1.0)).equals(Transform3::scale(Vec2d(2.5, -0.4)) * Transform3::rotate(DEG_90) * Transform3::translate(Vec2d(-10.5, -5.5)) * Vec3d(45.6, -23.0, 1.0), 0.000001), verbose);
			Assertv((Transform3::translateRotateScale(Vec2d(-10.5, -5.5), DEG_90, Vec2d(0.0, 0.0)) * Vec3d(45.6, -23.0, 1.0)).equals(Transform3::scale(Vec2d(0.0, 0.0)) * Transform3::rotate(DEG_90) * Transform3::translate(Vec2d(-10.5, -5.5)) * Vec3d(45.6, -23.0, 1.0), 0.000001), verbose);
			Assertv((Transform3::translateRotateScale(Vec2d(0.0, 0.0), 0.0, Vec2d(0.0, 0.0)) * Vec3d(45.6, -23.0, 1.0)).equals(Transform3::scale(Vec2d(0.0, 0.0)) * Transform3::rotate(0.0) * Transform3::translate(Vec2d(0.0, 0.0)) * Vec3d(45.6, -23.0, 1.0), 0.000001), verbose);
		}
		// rotateScaleTranslate
		// RHS
		{
			Rules::DefaultAxisRule = Rules::AXIS_RHS;
			Assertv((Transform3::rotateScaleTranslate(DEG_90, Vec2d(2.5, -0.4), Vec2d(-10.5, -5.5)) * Vec3d(45.6, -23.0, 1.0)).equals(Transform3::rotate(DEG_90) * Transform3::scale(Vec2d(2.5, -0.4)) * Transform3::translate(Vec2d(-10.5, -5.5)) * Vec3d(45.6, -23.0, 1.0), 0.000001), verbose);
			Assertv((Transform3::rotateScaleTranslate(DEG_90, Vec2d(0.0, 0.0), Vec2d(-10.5, -5.5)) * Vec3d(45.6, -23.0, 1.0)).equals(Transform3::rotate(DEG_90) * Transform3::scale(Vec2d(0.0, 0.0)) * Transform3::translate(Vec2d(-10.5, -5.5)) * Vec3d(45.6, -23.0, 1.0), 0.000001), verbose);
			Assertv((Transform3::rotateScaleTranslate(0.0, Vec2d(0.0, 0.0), Vec2d(0.0, 0.0)) * Vec3d(45.6, -23.0, 1.0)).equals(Transform3::rotate(0.0) * Transform3::scale(Vec2d(0.0, 0.0)) * Transform3::translate(Vec2d(0.0, 0.0)) * Vec3d(45.6, -23.0, 1.0), 0.000001), verbose);
		}
		// LHS
		{
			Rules::DefaultAxisRule = Rules::AXIS_LHS;
			Assertv((Transform3::rotateScaleTranslate(DEG_90, Vec2d(2.5, -0.4), Vec2d(-10.5, -5.5)) * Vec3d(45.6, -23.0, 1.0)).equals(Transform3::rotate(DEG_90) * Transform3::scale(Vec2d(2.5, -0.4)) * Transform3::translate(Vec2d(-10.5, -5.5)) * Vec3d(45.6, -23.0, 1.0), 0.000001), verbose);
			Assertv((Transform3::rotateScaleTranslate(DEG_90, Vec2d(0.0, 0.0), Vec2d(-10.5, -5.5)) * Vec3d(45.6, -23.0, 1.0)).equals(Transform3::rotate(DEG_90) * Transform3::scale(Vec2d(0.0, 0.0)) * Transform3::translate(Vec2d(-10.5, -5.5)) * Vec3d(45.6, -23.0, 1.0), 0.000001), verbose);
			Assertv((Transform3::rotateScaleTranslate(0.0, Vec2d(0.0, 0.0), Vec2d(0.0, 0.0)) * Vec3d(45.6, -23.0, 1.0)).equals(Transform3::rotate(0.0) * Transform3::scale(Vec2d(0.0, 0.0)) * Transform3::translate(Vec2d(0.0, 0.0)) * Vec3d(45.6, -23.0, 1.0), 0.000001), verbose);
		}
		// rotateTranslateScale
		// RHS
		{
			Rules::DefaultAxisRule = Rules::AXIS_RHS;
			Assertv((Transform3::rotateTranslateScale(DEG_90, Vec2d(-10.5, -5.5), Vec2d(2.5, -0.4)) * Vec3d(45.6, -23.0, 1.0)).equals(Transform3::scale(Vec2d(2.5, -0.4)) * Transform3::translate(Vec2d(-10.5, -5.5)) * Transform3::rotate(DEG_90) * Vec3d(45.6, -23.0, 1.0), 0.000001), verbose);
			Assertv((Transform3::rotateTranslateScale(DEG_90, Vec2d(-10.5, -5.5), Vec2d(0.0, 0.0)) * Vec3d(45.6, -23.0, 1.0)).equals(Transform3::scale(Vec2d(0.0, 0.0)) * Transform3::translate(Vec2d(-10.5, -5.5)) * Transform3::rotate(DEG_90) * Vec3d(45.6, -23.0, 1.0), 0.000001), verbose);
			Assertv((Transform3::rotateTranslateScale(0.0, Vec2d(0.0, 0.0), Vec2d(0.0, 0.0)) * Vec3d(45.6, -23.0, 1.0)).equals(Transform3::scale(Vec2d(0.0, 0.0)) * Transform3::translate(Vec2d(0.0, 0.0)) * Transform3::rotate(0.0) * Vec3d(45.6, -23.0, 1.0), 0.000001), verbose);
		}
		// LHS
		{
			Rules::DefaultAxisRule = Rules::AXIS_LHS;
			Assertv((Transform3::rotateTranslateScale(DEG_90, Vec2d(-10.5, -5.5), Vec2d(2.5, -0.4)) * Vec3d(45.6, -23.0, 1.0)).equals(Transform3::scale(Vec2d(2.5, -0.4)) * Transform3::translate(Vec2d(-10.5, -5.5)) * Transform3::rotate(DEG_90) * Vec3d(45.6, -23.0, 1.0), 0.000001), verbose);
			Assertv((Transform3::rotateTranslateScale(DEG_90, Vec2d(-10.5, -5.5), Vec2d(0.0, 0.0)) * Vec3d(45.6, -23.0, 1.0)).equals(Transform3::scale(Vec2d(0.0, 0.0)) * Transform3::translate(Vec2d(-10.5, -5.5)) * Transform3::rotate(DEG_90) * Vec3d(45.6, -23.0, 1.0), 0.000001), verbose);
			Assertv((Transform3::rotateTranslateScale(0.0, Vec2d(0.0, 0.0), Vec2d(0.0, 0.0)) * Vec3d(45.6, -23.0, 1.0)).equals(Transform3::scale(Vec2d(0.0, 0.0)) * Transform3::translate(Vec2d(0.0, 0.0)) * Transform3::rotate(0.0) * Vec3d(45.6, -23.0, 1.0), 0.000001), verbose);
		}
	}
	if (Assert::_num_failed_tests <= 0)
		printf("ALL GOOD!\n");
	else
	{
		puts("----------------------------------------");
		printf("# %d Failed!\n", Assert::_num_failed_tests);
	}
	return Assert::_num_failed_tests;
}