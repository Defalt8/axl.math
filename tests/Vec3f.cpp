#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include "Assert.hpp"
#include "lib.hpp"
#include <axl.math/constants.hpp>
#include <axl.math/angle.hpp>
#include <axl.math/float.hpp>
#include <axl.math/Vec3f.hpp>

int main(int argc, char *argv[])
{
	bool verbose = argc > 1 && (0 == strcmp(argv[1], "-v") || 0 == strcmp(argv[1], "--verbose"));
	using namespace axl;
	using namespace axl::math;
	using namespace axl::math::Constants;
	using namespace axl::math::Angle;
	printf("axl.math - version %hu.%hu.%hu  %s %s\n", lib::VERSION.major, lib::VERSION.minor, lib::VERSION.patch, libType(lib::LIBRARY_TYPE), buildType(lib::BUILD_TYPE));
	puts("----------------------------------------");
	const float sq2 = std::sqrt(2.0f);
	{ // static values
		Assertv(Float::equals(0.0f, Vec3f::Zero.x), verbose);
		Assertv(Float::equals(0.0f, Vec3f::Zero.y), verbose);
		Assertv(Float::equals(0.0f, Vec3f::Zero.z), verbose);
		Assertv(Float::equals(1.0f, Vec3f::Identity.x), verbose);
		Assertv(Float::equals(1.0f, Vec3f::Identity.y), verbose);
		Assertv(Float::equals(1.0f, Vec3f::Identity.z), verbose);
		Assertv(Vec3f::Default.equals(0.0f, 0.0f, 0.0f, 0.0001f), verbose);
	}
	{ // constructors
		{ // default constructor
			{
				Assertv(Vec3f::Default.equals(Vec3f::Zero), verbose);
				Vec3f vec;
				Assertv(Float::equals(Vec3f::Default.x, vec.x), verbose);
				Assertv(Float::equals(Vec3f::Default.y, vec.y), verbose);
				Assertv(Float::equals(Vec3f::Default.z, vec.z), verbose);
			}
			{
				Vec3f::Default = Vec3f::Identity;
				Assertv(Vec3f::Default.equals(Vec3f::Identity), verbose);
				Vec3f vec;
				Assertv(vec.equals(Vec3f::Identity), verbose);
				Assertv(Float::equals(Vec3f::Default.x, vec.x), verbose);
				Assertv(Float::equals(Vec3f::Default.y, vec.y), verbose);
				Assertv(Float::equals(Vec3f::Default.z, vec.z), verbose);
				Vec3f::Default = Vec3f::Zero;
				Assertv(Vec3f::Default.equals(Vec3f::Zero), verbose);
			}
		}
		{ // values constructor
			Vec3f vec(3.1415f, 0.6721234f, 456.3422f);
			Assertv(Float::equals(3.1415f, vec.x), verbose);
			Assertv(Float::equals(0.6721234f, vec.y), verbose);
			Assertv(Float::equals(456.3422f, vec.z), verbose);
		}
		{ // copy constructor
			{
				Vec3f vec(3.1415f, 0.6721234f, 456.3422f);
				Assertv(Float::equals(3.1415f, vec.x), verbose);
				Assertv(Float::equals(0.6721234f, vec.y), verbose);
				Assertv(Float::equals(456.3422f, vec.z), verbose);
				Vec3f vec1(vec);
				Assertv(Float::equals(3.1415f, vec1.x), verbose);
				Assertv(Float::equals(0.6721234f, vec1.y), verbose);
				Assertv(Float::equals(456.3422f, vec1.z), verbose);
				Vec3f vec2 = vec;
				Assertv(Float::equals(3.1415f, vec2.x), verbose);
				Assertv(Float::equals(0.6721234f, vec2.y), verbose);
				Assertv(Float::equals(456.3422f, vec2.z), verbose);
			}
			{
				const Vec2f vec2(1.23f, 3.45f);
				Assertv(vec2.equals(1.23f, 3.45f, 0.0001f), verbose);
				{
					const Vec3f vec3(vec2);
					Assertv(vec3.equals(1.23f, 3.45f, 0.0f, 0.0001f), verbose);
				}
				{
					const Vec3f vec3(vec2, 6.9f);
					Assertv(vec3.equals(1.23f, 3.45f, 6.9f, 0.0001f), verbose);
				}
			}
		}
	}
	{ // array mode referencing
		const Vec3f vec(1.4f,2.5f,5.6f);
		Assertv(vec.equals(1.4f,2.5f,5.6f), verbose);
		Assertv(&(&vec.x)[0] == &vec.x, verbose);
		Assertv(&(&vec.x)[1] == &vec.y, verbose);
		Assertv(&(&vec.x)[2] == &vec.z, verbose);
		Assertv(vec.equals((&vec.x)[0],(&vec.x)[1],(&vec.x)[2]), verbose);
	}
	{ // unary operators
		const Vec3f vec(3.4f, 5.6f, 1.2345f);
		const Vec3f pvec = +vec;
		const Vec3f nvec = -vec;
		Assertv(pvec.equals(pvec), verbose);
		Assertv(nvec.equals(-pvec.x, -pvec.y, -pvec.z, 0.001f), verbose);
		Assertv(vec.equals(-nvec, 0.0001f), verbose);
	}
	{ // Nan
		{
			const Vec3f vec(Float::Nan, Float::Nan, Float::Nan);
			Assertv(vec.isNan(), verbose);
			Assertv(vec.hasNan(), verbose);
			Assertv(!vec.hasNoNan(), verbose);
		}
		{
			const Vec3f vec(0.6f, Float::Nan, Float::Nan);
			Assertv(!vec.isNan(), verbose);
			Assertv(vec.hasNan(), verbose);
			Assertv(!vec.hasNoNan(), verbose);
		}
		{
			const Vec3f vec(0.6f, Float::Nan, 5.5f);
			Assertv(!vec.isNan(), verbose);
			Assertv(vec.hasNan(), verbose);
			Assertv(!vec.hasNoNan(), verbose);
		}
		{
			const Vec3f vec(0.5f, 1.0f, 6.4f);
			Assertv(!vec.isNan(), verbose);
			Assertv(!vec.hasNan(), verbose);
			Assertv(vec.hasNoNan(), verbose);
		}
	}
	{ // equality operators
		Assertv(Vec3f::Zero == 0.0f, verbose);
		Assertv(Vec3f::Identity == 1.0f, verbose);
		Assertv(Vec3f::Zero == Vec3f::Zero, verbose);
		Assertv(Vec3f::Identity == Vec3f::Identity, verbose);
		Assertv(!(Vec3f::Zero != 0.0f), verbose);
		Assertv(!(Vec3f::Identity != 1.0f), verbose);
		Assertv(!(Vec3f::Zero != Vec3f::Zero), verbose);
		Assertv(!(Vec3f::Identity != Vec3f::Identity), verbose);
		Vec3f vec(3.45f, 4.5f, 324.23f), vec2(1.2345f, 0.987654f, 324.23f);
		Assertv(vec.equals(3.45f, 4.5f, 324.23f), verbose);
		Assertv(vec.equals(vec), verbose);
		Assertv(!vec.equals(vec2), verbose);
		Assertv(!vec.notEquals(3.45f, 4.5f, 324.23f), verbose);
		Assertv(!vec.notEquals(vec), verbose);
		Assertv(vec.notEquals(vec2), verbose);
	}
	{ // arthimetic operators
		{ // addition
			const float lval_x = 12.344f, lval_y = 131.04f, lval_z = 0.3445453f;
			const float rval_x = 4.5664f, rval_y = 12314.43005f, rval_z = 344.56f;
			const Vec3f lvec(lval_x, lval_y, lval_z), rvec(rval_x, rval_y, rval_z);
			Vec3f vec = lvec + rvec;
			Assertv(vec.equals(lval_x + rval_x, lval_y + rval_y, lval_z + rval_z), verbose);
			
			vec = lvec + rval_y;
			Assertv(vec.equals(lval_x + rval_y, lval_y + rval_y, lval_z + rval_y), verbose);

			vec = lvec;
			Assertv(vec.equals(lval_x, lval_y, lval_z), verbose);
			vec += rvec;
			Assertv(vec.equals(lval_x + rval_x, lval_y + rval_y, lval_z + rval_z), verbose);

			vec = lvec;
			Assertv(vec.equals(lval_x, lval_y, lval_z), verbose);
			vec += rval_x;
			Assertv(vec.equals(lval_x + rval_x, lval_y + rval_x, lval_z + rval_x), verbose);
		}
		{ // subtraction
			const float lval_x = 12.344f, lval_y = 131.04f, lval_z = 0.3445453f;
			const float rval_x = 4.5664f, rval_y = 12314.43005f, rval_z = 344.56f;
			const Vec3f lvec(lval_x, lval_y, lval_z), rvec(rval_x, rval_y, rval_z);
			Vec3f vec = lvec - rvec;
			Assertv(vec.equals(lval_x - rval_x, lval_y - rval_y, lval_z - rval_z), verbose);
			
			vec = lvec - rval_y;
			Assertv(vec.equals(lval_x - rval_y, lval_y - rval_y, lval_z - rval_y), verbose);

			vec = lvec;
			Assertv(vec.equals(lval_x, lval_y, lval_z), verbose);
			vec -= rvec;
			Assertv(vec.equals(lval_x - rval_x, lval_y - rval_y, lval_z - rval_z), verbose);

			vec = lvec;
			Assertv(vec.equals(lval_x, lval_y, lval_z), verbose);
			vec -= rval_x;
			Assertv(vec.equals(lval_x - rval_x, lval_y - rval_x, lval_z - rval_x), verbose);
		}
		{ // multiplication
			const float lval_x = 12.344f, lval_y = 131.04f, lval_z = 0.3445453f;
			const float rval_x = 4.5664f, rval_y = 12314.43005f, rval_z = 344.56f;
			const Vec3f lvec(lval_x, lval_y, lval_z), rvec(rval_x, rval_y, rval_z);
			Vec3f vec = lvec * rvec;
			Assertv(vec.equals(lval_x * rval_x, lval_y * rval_y, lval_z * rval_z), verbose);
			
			vec = lvec * rval_y;
			Assertv(vec.equals(lval_x * rval_y, lval_y * rval_y, lval_z * rval_y), verbose);

			vec = lvec;
			Assertv(vec.equals(lval_x, lval_y, lval_z), verbose);
			vec *= rvec;
			Assertv(vec.equals(lval_x * rval_x, lval_y * rval_y, lval_z * rval_z), verbose);

			vec = lvec;
			Assertv(vec.equals(lval_x, lval_y, lval_z), verbose);
			vec *= rval_x;
			Assertv(vec.equals(lval_x * rval_x, lval_y * rval_x, lval_z * rval_x), verbose);
		}
		{ // division
			const float lval_x = 12.344f, lval_y = 131.04f, lval_z = 0.3445453f;
			const float rval_x = 4.5664f, rval_y = 12314.43005f, rval_z = 344.56f;
			const Vec3f lvec(lval_x, lval_y, lval_z), rvec(rval_x, rval_y, rval_z);
			Vec3f vec = lvec / rvec;
			Assertv(vec.equals(lval_x / rval_x, lval_y / rval_y, lval_z / rval_z), verbose);
			
			vec = lvec / rval_y;
			Assertv(vec.equals(lval_x / rval_y, lval_y / rval_y, lval_z / rval_y), verbose);

			vec = lvec;
			Assertv(vec.equals(lval_x, lval_y, lval_z), verbose);
			vec /= rvec;
			Assertv(vec.equals(lval_x / rval_x, lval_y / rval_y, lval_z / rval_z), verbose);

			vec = lvec;
			Assertv(vec.equals(lval_x, lval_y, lval_z), verbose);
			vec /= rval_x;
			Assertv(vec.equals(lval_x / rval_x, lval_y / rval_x, lval_z / rval_x), verbose);
		}
	}
	{ // vector operations
		{ // magnitude
			const float x = 2.0f, y = 3.0f, z = -4.6f;
			const Vec3f vec(x, y, z);
			const float magn = vec.magn();
			Assertv(Float::equals(magn, std::sqrt(x * x + y * y + z * z), 0.0001f), verbose);
			Assertv(Float::equals(magn, std::sqrt(std::pow(x, 2.0f) + std::pow(y, 2.0f) + std::pow(z, 2.0f)), 0.0001f), verbose);
		}
		{ // normal
			{
				const float x = 2.0f, y = 3.0f, z = -3.5f;
				const Vec3f vec(x, y, z);
				const float magn1 = std::sqrt(x * x + y * y + z * z);
				const float magn2 = std::sqrt(std::pow(x, 2.0f) + std::pow(y, 2.0f) + std::pow(z, 2.0f));
				const Vec3f norm_vec = vec.norm();
				const Vec3f norm_vec1 = vec / magn1;
				const Vec3f norm_vec2 = vec / magn2;
				Assertv(Float::equals(1.0f, norm_vec.magn(), 0.0001f), verbose);
				Assertv(Float::equals(1.0f, norm_vec1.magn(), 0.0001f), verbose);
				Assertv(Float::equals(1.0f, norm_vec2.magn(), 0.0001f), verbose);
				Assertv(Float::equals(1.0f, std::sqrt(norm_vec1.x * norm_vec1.x + norm_vec1.y * norm_vec1.y + norm_vec1.z * norm_vec1.z), 0.0001f), verbose);
				Assertv(Float::equals(1.0f, std::sqrt(std::pow(norm_vec2.x, 2.0f) + std::pow(norm_vec2.y, 2.0f) + std::pow(norm_vec2.z, 2.0f)), 0.0001f), verbose);
			}
			{
				const float x = 2.0f, y = 3.0f, z = -4.5f;
				const Vec3f vec(x, y, z);
				Vec3f nvec(x, y, z);
				nvec.normalize();
				const float magn1 = std::sqrt(x * x + y * y + z * z);
				const Vec3f norm_vec = vec / magn1;
				Assertv(nvec.equals(norm_vec, 0.0001f), verbose);
				Assertv(Float::equals(1.0f, nvec.magn(), 0.0001f), verbose);
				Assertv(Float::equals(1.0f, norm_vec.magn(), 0.0001f), verbose);
				Assertv(vec.equals(nvec * vec.magn(), 0.0001f), verbose);
			}
		}
		{ // dot product
			const float lx = 2.0f, ly = 3.0f, lz = -3.5f;
			const float rx = 4.0f, ry = -6.0f, rz = -9.5f;
			const Vec3f lvec(lx, ly, lz);
			const Vec3f rvec(rx, ry, rz);
			const float dotplr = lvec.dot(rvec);
			const float dotprl = rvec.dot(lvec);
			Assertv(Float::equals(dotplr, (lx * rx + ly * ry + lz * rz), 0.0001f), verbose);
			Assertv(Float::equals(dotprl, (lx * rx + ly * ry + lz * rz), 0.0001f), verbose);
		}
		{ // cross product
			const float lx = 2.0f, ly = 3.0f, lz = -3.5f;
			const float rx = 4.0f, ry = -6.0f, rz = -9.5f;
			const Vec3f lvec(lx, ly, lz);
			const Vec3f rvec(rx, ry, rz);
			const Vec3f crossplr = lvec.cross(rvec);
			const Vec3f crossprl = rvec.cross(lvec);
			Assertv(crossplr.equals((ly * rz - lz * ry), -(lx * rz - lz * rx), (lx * ry - ly * rx), 0.0001f), verbose);
			Assertv(crossprl.equals((ry * lz - rz * ly), -(rx * lz - rz * lx), (rx * ly - ry * lx), 0.0001f), verbose);

		}
		{ // euler angle
			Vec3f::DefaultAxisRule = Rules::AXIS_RHS;
			Assertve(Vec3f::DefaultAxisRule == Rules::AXIS_RHS, verbose);
			{ // RHS
				Assertv(Vec3f(0, 0, 0).euler().equals(0.0f, 0.0f, 0.0f, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).euler().equals(0.0f, degToRad(90.0f), 0.0f, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).euler().equals(0.0f, 0.0f, degToRad(90.0f), 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).euler().equals(degToRad(90.0f), 0.0f, 0.0f, 0.0001f), verbose);
				Assertv(Vec3f(5, 5, 0).euler().equals(0.0f, degToRad(90.0f), degToRad(45.0f), 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 5).euler().equals(degToRad(90.0f), degToRad(45.0f), 0.0f, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 5).euler().equals(degToRad(45.0f), 0.0f, degToRad(90.0f), 0.0001f), verbose);
				Assertv(Vec3f(5, 5, 5).euler().equals(degToRad(45.0f), degToRad(45.0f), degToRad(45.0f), 0.0001f), verbose);
				Assertv((Vec3f(-5, 0, 0)).euler().equals(0.0f, degToRad(-90.0f), degToRad(180.0f), 0.0001f), verbose);
				Assertv((Vec3f(0, -5, 0)).euler().equals(degToRad(180.0f), 0.0f, degToRad(-90.0f), 0.0001f), verbose);
				Assertv((Vec3f(0, 0, -5)).euler().equals(degToRad(-90.0f), degToRad(180.0f), 0.0f, 0.0001f), verbose);
				///
				const Vec3f ref_vec(10, 10, 10);
				Assertv(Vec3f(0, 0, 0).euler(ref_vec).equals(degToRad(-45.0f), degToRad(-45.0f), degToRad(-45.0f), 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).euler(ref_vec).equals(degToRad(-45.0f), degToRad(45.0f), degToRad(-45.0f), 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).euler(ref_vec).equals(degToRad(-45.0f), degToRad(-45.0f), degToRad(45.0f), 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).euler(ref_vec).equals(degToRad(45.0f), degToRad(-45.0f), degToRad(-45.0f), 0.0001f), verbose);
				Assertv(Vec3f(5, 5, 0).euler(ref_vec).equals(degToRad(-45.0f), degToRad(45.0f), degToRad(0.0f), 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 5).euler(ref_vec).equals(degToRad(45.0f), degToRad(0.0f), degToRad(-45.0f), 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 5).euler(ref_vec).equals(degToRad(0.0f), degToRad(-45.0f), degToRad(45.0f), 0.0001f), verbose);
				Assertv(Vec3f(5, 5, 5).euler(ref_vec).equals(degToRad(0.0f), degToRad(0.0f), degToRad(0.0f), 0.0001f), verbose);
				Assertv((Vec3f(-5, 0, 0)).euler(ref_vec).equals(degToRad(-45.0f), degToRad(-135.0f), degToRad(135.0f), 0.0001f), verbose);
				Assertv((Vec3f(0, -5, 0)).euler(ref_vec).equals(degToRad(135.0f), degToRad(-45.0f), degToRad(-135.0f), 0.0001f), verbose);
				Assertv((Vec3f(0, 0, -5)).euler(ref_vec).equals(degToRad(-135.0f), degToRad(135.0f), degToRad(-45.0f), 0.0001f), verbose);
			}
			Vec3f::DefaultAxisRule = Rules::AXIS_LHS;
			Assertve(Vec3f::DefaultAxisRule == Rules::AXIS_LHS, verbose);
			{ // LHS
				Assertv(Vec3f(0, 0, 0).euler().equals(0.0f, 0.0f, 0.0f, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).euler().equals(0.0f, 0.0f, degToRad(90.0f), 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).euler().equals(degToRad(90.0f), 0.0f, 0.0f, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).euler().equals(0.0f, degToRad(90.0f), 0.0f, 0.0001f), verbose);
				Assertv(Vec3f(5, 5, 0).euler().equals(degToRad(90.0f), 0.0f, degToRad(45.0f), 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 5).euler().equals(0.0f, degToRad(45.0f), degToRad(90.0f), 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 5).euler().equals(degToRad(45.0f), degToRad(90.0f), 0.0f, 0.0001f), verbose);
				Assertv(Vec3f(5, 5, 5).euler().equals(degToRad(45.0f), degToRad(45.0f), degToRad(45.0f), 0.0001f), verbose);
				Assertv((Vec3f(-5, 0, 0)).euler().equals(0.0f, degToRad(180.0f), degToRad(-90.0f), 0.0001f), verbose);
				Assertv((Vec3f(0, -5, 0)).euler().equals(degToRad(-90.0f), 0.0f, degToRad(180.0f), 0.0001f), verbose);
				Assertv((Vec3f(0, 0, -5)).euler().equals(degToRad(180.0f), degToRad(-90.0f), 0.0f, 0.0001f), verbose);
				///
				const Vec3f ref_vec(10, 10, 10);
				Assertv(ref_vec.euler().equals(degToRad(45.0f), degToRad(45.0f), degToRad(45.0f), 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 0).euler(ref_vec).equals(degToRad(-45.0f), degToRad(-45.0f), degToRad(-45.0f), 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).euler(ref_vec).equals(degToRad(-45.0f), degToRad(-45.0f), degToRad(45.0f), 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).euler(ref_vec).equals(degToRad(45.0f), degToRad(-45.0f), degToRad(-45.0f), 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).euler(ref_vec).equals(degToRad(-45.0f), degToRad(45.0f), degToRad(-45.0f), 0.0001f), verbose);
				Assertv(Vec3f(5, 5, 0).euler(ref_vec).equals(degToRad(45.0f), degToRad(-45.0f), degToRad(0.0f), 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 5).euler(ref_vec).equals(degToRad(-45.0f), degToRad(0.0f), degToRad(45.0f), 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 5).euler(ref_vec).equals(degToRad(0.0f), degToRad(45.0f), degToRad(-45.0f), 0.0001f), verbose);
				Assertv(Vec3f(5, 5, 5).euler(ref_vec).equals(degToRad(0.0f), degToRad(0.0f), degToRad(0.0f), 0.0001f), verbose);
				Assertv((Vec3f(-5, 0, 0)).euler(ref_vec).equals(degToRad(-45.0f), degToRad(135.0f), degToRad(-135.0f), 0.0001f), verbose);
				Assertv((Vec3f(0, -5, 0)).euler(ref_vec).equals(degToRad(-135.0f), degToRad(-45.0f), degToRad(135.0f), 0.0001f), verbose);
				Assertv((Vec3f(0, 0, -5)).euler(ref_vec).equals(degToRad(135.0f), degToRad(-135.0f), degToRad(-45.0f), 0.0001f), verbose);
			}
		}
	}
	{ // transforms
		{ // scale
			const float scale = 4.5f, scale_x = 1.56f, scale_y = 0.75f, scale_z = -90.0f;
			{
				Vec3f vec(5.67f, 98.999f, 66.9f);
				Assertv(vec.equals(5.67f, 98.999f, 66.9f, 0.0001f), verbose);
				vec.scale(1.0f);
				Assertv(vec.equals(5.67f, 98.999f, 66.9f, 0.0001f), verbose);
			}
			{
				Vec3f vec(5.5f, 0.0f, 0.5f);
				Assertv(vec.equals(5.5f, 0.0f, 0.5f, 0.0001f), verbose);
				vec.scale(0.0f, 2.0f, 0.5f);
				Assertv(vec.equals(0.0f, 0.0f, 0.25f, 0.0001f), verbose);
			}
			{
				Vec3f vec(5.67f, 98.999f, 66.9f);
				Assertv(vec.equals(5.67f, 98.999f, 66.9f, 0.0001f), verbose);
				vec.scale(scale);
				Assertv(vec.equals(5.67f * scale, 98.999f * scale, 66.9f * scale, 0.0001f), verbose);
			}
			{
				Vec3f vec(5.67f, 98.999f, 66.9f);
				Assertv(vec.equals(5.67f, 98.999f, 66.9f, 0.0001f), verbose);
				vec.scale(scale_x, scale_y, scale_z);
				Assertv(vec.equals(5.67f * scale_x, 98.999f * scale_y, 66.9f * scale_z, 0.0001f), verbose);
			}
		}
		{ // scaled
			const float scale = 4.5f, scale_x = 1.56f, scale_y = 0.75f, scale_z = -90.0f;
			{
				const Vec3f vec(5.67f, 98.999f, 66.9f);
				Assertv(vec.equals(5.67f, 98.999f, 66.9f, 0.0001f), verbose);
				Assertv(vec.scaled(1.0f).equals(5.67f, 98.999f, 66.9f, 0.0001f), verbose);
			}
			{
				const Vec3f vec(5.5f, 0.0f, 0.5f);
				Assertv(vec.equals(5.5f, 0.0f, 0.5f, 0.0001f), verbose);
				Assertv(vec.scaled(0.0f, 2.0f, 0.5f).equals(0.0f, 0.0f, 0.25f, 0.0001f), verbose);
			}
			{
				const Vec3f vec(5.67f, 98.999f, 66.9f);
				Assertv(vec.equals(5.67f, 98.999f, 66.9f, 0.0001f), verbose);
				Assertv(vec.scaled(scale).equals(5.67f * scale, 98.999f * scale, 66.9f * scale, 0.0001f), verbose);
			}
			{
				const Vec3f vec(5.67f, 98.999f, 66.9f);
				Assertv(vec.equals(5.67f, 98.999f, 66.9f, 0.0001f), verbose);
				Assertv(vec.scaled(scale_x, scale_y, scale_z).equals(5.67f * scale_x, 98.999f * scale_y, 66.9f * scale_z, 0.0001f), verbose);
			}
		}
		{ // translate
			{ // Vec3f
				const Vec3f delta(4.5f, -900.3434f, -44.66f);
				Vec3f vec(5.67f, 98.999f, -120.04f);
				Assertv(vec.equals(5.67f, 98.999f, -120.04f, 0.0001f), verbose);
				vec.translate(delta);
				Assertv(vec.equals(5.67f + delta.x, 98.999f + delta.y, -120.04f + delta.z, 0.0001f), verbose);
			}
			{ // values
				const float delta_x = 4.5f, delta_y = -900.3434f, delta_z = -44.66f;
				Vec3f vec(5.67f, 98.999f, -120.04f);
				Assertv(vec.equals(5.67f, 98.999f, -120.04f), verbose);
				vec.translate(delta_x, delta_y, delta_z);
				Assertv(vec.equals(5.67f + delta_x, 98.999f + delta_y, -120.04f + delta_z, 0.0001f), verbose);
			}
		}
		{ // translated
			{ // Vec3f
				const Vec3f delta(4.5f, -900.3434f, -44.66f);
				const Vec3f vec(5.67f, 98.999f, -120.04f);
				Assertv(vec.equals(5.67f, 98.999f, -120.04f, 0.0001f), verbose);
				Vec3f tvec = vec.translated(delta);
				Assertv(tvec.equals(vec.x + delta.x, vec.y + delta.y, vec.z + delta.z, 0.0001f), verbose);
			}
			{ // values
				const float delta_x = 4.5f, delta_y = -900.3434f, delta_z = -44.66f;
				const Vec3f vec(5.67f, 98.999f, -120.04f);
				Assertv(vec.equals(5.67f, 98.999f, -120.04f), verbose);
				Vec3f tvec = vec.translated(delta_x, delta_y, delta_z);
				Assertv(tvec.equals(vec.x + delta_x, vec.y + delta_y, vec.z + delta_z, 0.0001f), verbose);
			}
		}
		{ // rotate
			{ // RHS
				Vec3f::DefaultAxisRule = Rules::AXIS_RHS;
				Assertve(Vec3f::DefaultAxisRule == Rules::AXIS_RHS, verbose);
				Assertv(Vec3f(5, 5, 5).rotate(degToRad(0.0f), degToRad(0.0f), degToRad(0.0f)).equals(5, 5, 5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotate(degToRad(90.0f), degToRad(0.0f), degToRad(0.0f)).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotate(degToRad(0.0f), degToRad(90.0f), degToRad(0.0f)).equals(0, 0, -5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotate(degToRad(0.0f), degToRad(0.0f), degToRad(90.0f)).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotate(degToRad(90.0f), degToRad(0.0f), degToRad(0.0f)).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotate(degToRad(0.0f), degToRad(90.0f), degToRad(0.0f)).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotate(degToRad(0.0f), degToRad(0.0f), degToRad(90.0f)).equals(-5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotate(degToRad(90.0f), degToRad(0.0f), degToRad(0.0f)).equals(0, -5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotate(degToRad(0.0f), degToRad(90.0f), degToRad(0.0f)).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotate(degToRad(0.0f), degToRad(0.0f), degToRad(90.0f)).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotate(degToRad(-90.0f), degToRad(0.0f), degToRad(0.0f)).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotate(degToRad(0.0f), degToRad(-90.0f), degToRad(0.0f)).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotate(degToRad(0.0f), degToRad(0.0f), degToRad(-90.0f)).equals(0, -5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotate(degToRad(-90.0f), degToRad(0.0f), degToRad(0.0f)).equals(0, 0, -5, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotate(degToRad(0.0f), degToRad(-90.0f), degToRad(0.0f)).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotate(degToRad(0.0f), degToRad(0.0f), degToRad(-90.0f)).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotate(degToRad(-90.0f), degToRad(0.0f), degToRad(0.0f)).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotate(degToRad(0.0f), degToRad(-90.0f), degToRad(0.0f)).equals(-5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotate(degToRad(0.0f), degToRad(0.0f), degToRad(-90.0f)).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotate(degToRad(45.0f), degToRad(0.0f), degToRad(0.0f)).equals(sq2, 1, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotate(degToRad(-45.0f), degToRad(0.0f), degToRad(0.0f)).equals(sq2, 1, -1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotate(degToRad(0.0f), degToRad(45.0f), degToRad(0.0f)).equals(1, sq2, -1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotate(degToRad(0.0f), degToRad(-45.0f), degToRad(0.0f)).equals(1, sq2, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotate(degToRad(0.0f), degToRad(0.0f), degToRad(45.0f)).equals(0, 2, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotate(degToRad(0.0f), degToRad(0.0f), degToRad(-45.0f)).equals(2, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotate(degToRad(45.0f), degToRad(0.0f), degToRad(0.0f)).equals(sq2, -1, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotate(degToRad(-45.0f), degToRad(0.0f), degToRad(0.0f)).equals(sq2, 1, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotate(degToRad(0.0f), degToRad(45.0f), degToRad(0.0f)).equals(2, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotate(degToRad(0.0f), degToRad(-45.0f), degToRad(0.0f)).equals(0, 0, 2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotate(degToRad(0.0f), degToRad(0.0f), degToRad(45.0f)).equals(1, 1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotate(degToRad(0.0f), degToRad(0.0f), degToRad(-45.0f)).equals(1, -1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotate(degToRad(45.0f), degToRad(0.0f), degToRad(0.0f)).equals(0, 0, 2, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotate(degToRad(-45.0f), degToRad(0.0f), degToRad(0.0f)).equals(0, 2, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotate(degToRad(0.0f), degToRad(45.0f), degToRad(0.0f)).equals(1, sq2, 1, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotate(degToRad(0.0f), degToRad(-45.0f), degToRad(0.0f)).equals(-1, sq2, 1, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotate(degToRad(0.0f), degToRad(0.0f), degToRad(45.0f)).equals(-1, 1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotate(degToRad(0.0f), degToRad(0.0f), degToRad(-45.0f)).equals(1, 1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotate(degToRad(45.0f), degToRad(0.0f), degToRad(0.0f)).equals(sq2, 0, 2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotate(degToRad(-45.0f), degToRad(0.0f), degToRad(0.0f)).equals(sq2, 2, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotate(degToRad(0.0f), degToRad(45.0f), degToRad(0.0f)).equals(2, sq2, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotate(degToRad(0.0f), degToRad(-45.0f), degToRad(0.0f)).equals(0, sq2, 2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotate(degToRad(0.0f), degToRad(0.0f), degToRad(45.0f)).equals(0, 2, sq2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotate(degToRad(0.0f), degToRad(0.0f), degToRad(-45.0f)).equals(2, 0, sq2, 0.0001f), verbose);
			}
			{ // LHS
				Vec3f::DefaultAxisRule = Rules::AXIS_LHS;
				Assertve(Vec3f::DefaultAxisRule == Rules::AXIS_LHS, verbose);
				Assertv(Vec3f(5, 5, 5).rotate(degToRad(0.0f), degToRad(0.0f), degToRad(0.0f)).equals(5, 5, 5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotate(degToRad(90.0f), degToRad(0.0f), degToRad(0.0f)).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotate(degToRad(0.0f), degToRad(90.0f), degToRad(0.0f)).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotate(degToRad(0.0f), degToRad(0.0f), degToRad(90.0f)).equals(0, -5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotate(degToRad(90.0f), degToRad(0.0f), degToRad(0.0f)).equals(0, 0, -5, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotate(degToRad(0.0f), degToRad(90.0f), degToRad(0.0f)).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotate(degToRad(0.0f), degToRad(0.0f), degToRad(90.0f)).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotate(degToRad(90.0f), degToRad(0.0f), degToRad(0.0f)).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotate(degToRad(0.0f), degToRad(90.0f), degToRad(0.0f)).equals(-5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotate(degToRad(0.0f), degToRad(0.0f), degToRad(90.0f)).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotate(degToRad(-90.0f), degToRad(0.0f), degToRad(0.0f)).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotate(degToRad(0.0f), degToRad(-90.0f), degToRad(0.0f)).equals(0, 0, -5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotate(degToRad(0.0f), degToRad(0.0f), degToRad(-90.0f)).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotate(degToRad(-90.0f), degToRad(0.0f), degToRad(0.0f)).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotate(degToRad(0.0f), degToRad(-90.0f), degToRad(0.0f)).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotate(degToRad(0.0f), degToRad(0.0f), degToRad(-90.0f)).equals(-5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotate(degToRad(-90.0f), degToRad(0.0f), degToRad(0.0f)).equals(0, -5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotate(degToRad(0.0f), degToRad(-90.0f), degToRad(0.0f)).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotate(degToRad(0.0f), degToRad(0.0f), degToRad(-90.0f)).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotate(degToRad(45.0f), degToRad(0.0f), degToRad(0.0f)).equals(sq2, 1, -1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotate(degToRad(-45.0f), degToRad(0.0f), degToRad(0.0f)).equals(sq2, 1, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotate(degToRad(0.0f), degToRad(45.0f), degToRad(0.0f)).equals(1, sq2, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotate(degToRad(0.0f), degToRad(-45.0f), degToRad(0.0f)).equals(1, sq2, -1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotate(degToRad(0.0f), degToRad(0.0f), degToRad(45.0f)).equals(2, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotate(degToRad(0.0f), degToRad(0.0f), degToRad(-45.0f)).equals(0, 2, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotate(degToRad(45.0f), degToRad(0.0f), degToRad(0.0f)).equals(sq2, 1, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotate(degToRad(-45.0f), degToRad(0.0f), degToRad(0.0f)).equals(sq2, -1, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotate(degToRad(0.0f), degToRad(45.0f), degToRad(0.0f)).equals(0, 0, 2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotate(degToRad(0.0f), degToRad(-45.0f), degToRad(0.0f)).equals(2, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotate(degToRad(0.0f), degToRad(0.0f), degToRad(45.0f)).equals(1, -1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotate(degToRad(0.0f), degToRad(0.0f), degToRad(-45.0f)).equals(1, 1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotate(degToRad(45.0f), degToRad(0.0f), degToRad(0.0f)).equals(0, 2, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotate(degToRad(-45.0f), degToRad(0.0f), degToRad(0.0f)).equals(0, 0, 2, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotate(degToRad(0.0f), degToRad(45.0f), degToRad(0.0f)).equals(-1, sq2, 1, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotate(degToRad(0.0f), degToRad(-45.0f), degToRad(0.0f)).equals(1, sq2, 1, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotate(degToRad(0.0f), degToRad(0.0f), degToRad(45.0f)).equals(1, 1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotate(degToRad(0.0f), degToRad(0.0f), degToRad(-45.0f)).equals(-1, 1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotate(degToRad(45.0f), degToRad(0.0f), degToRad(0.0f)).equals(sq2, 2, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotate(degToRad(-45.0f), degToRad(0.0f), degToRad(0.0f)).equals(sq2, 0, 2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotate(degToRad(0.0f), degToRad(45.0f), degToRad(0.0f)).equals(0, sq2, 2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotate(degToRad(0.0f), degToRad(-45.0f), degToRad(0.0f)).equals(2, sq2, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotate(degToRad(0.0f), degToRad(0.0f), degToRad(45.0f)).equals(2, 0, sq2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotate(degToRad(0.0f), degToRad(0.0f), degToRad(-45.0f)).equals(0, 2, sq2, 0.0001f), verbose);
			}
		}
		{ // rotate - angle_vec
			{ // RHS
				Vec3f::DefaultAxisRule = Rules::AXIS_RHS;
				Assertve(Vec3f::DefaultAxisRule == Rules::AXIS_RHS, verbose);
				Assertv(Vec3f(5, 5, 5).rotate(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(0.0f))).equals(5, 5, 5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotate(Vec3f(degToRad(90.0f), degToRad(0.0f), degToRad(0.0f))).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotate(Vec3f(degToRad(0.0f), degToRad(90.0f), degToRad(0.0f))).equals(0, 0, -5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotate(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(90.0f))).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotate(Vec3f(degToRad(90.0f), degToRad(0.0f), degToRad(0.0f))).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotate(Vec3f(degToRad(0.0f), degToRad(90.0f), degToRad(0.0f))).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotate(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(90.0f))).equals(-5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotate(Vec3f(degToRad(90.0f), degToRad(0.0f), degToRad(0.0f))).equals(0, -5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotate(Vec3f(degToRad(0.0f), degToRad(90.0f), degToRad(0.0f))).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotate(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(90.0f))).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotate(Vec3f(degToRad(-90.0f), degToRad(0.0f), degToRad(0.0f))).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotate(Vec3f(degToRad(0.0f), degToRad(-90.0f), degToRad(0.0f))).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotate(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(-90.0f))).equals(0, -5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotate(Vec3f(degToRad(-90.0f), degToRad(0.0f), degToRad(0.0f))).equals(0, 0, -5, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotate(Vec3f(degToRad(0.0f), degToRad(-90.0f), degToRad(0.0f))).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotate(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(-90.0f))).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotate(Vec3f(degToRad(-90.0f), degToRad(0.0f), degToRad(0.0f))).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotate(Vec3f(degToRad(0.0f), degToRad(-90.0f), degToRad(0.0f))).equals(-5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotate(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(-90.0f))).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotate(Vec3f(degToRad(45.0f), degToRad(0.0f), degToRad(0.0f))).equals(sq2, 1, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotate(Vec3f(degToRad(-45.0f), degToRad(0.0f), degToRad(0.0f))).equals(sq2, 1, -1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotate(Vec3f(degToRad(0.0f), degToRad(45.0f), degToRad(0.0f))).equals(1, sq2, -1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotate(Vec3f(degToRad(0.0f), degToRad(-45.0f), degToRad(0.0f))).equals(1, sq2, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotate(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(45.0f))).equals(0, 2, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotate(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(-45.0f))).equals(2, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotate(Vec3f(degToRad(45.0f), degToRad(0.0f), degToRad(0.0f))).equals(sq2, -1, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotate(Vec3f(degToRad(-45.0f), degToRad(0.0f), degToRad(0.0f))).equals(sq2, 1, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotate(Vec3f(degToRad(0.0f), degToRad(45.0f), degToRad(0.0f))).equals(2, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotate(Vec3f(degToRad(0.0f), degToRad(-45.0f), degToRad(0.0f))).equals(0, 0, 2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotate(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(45.0f))).equals(1, 1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotate(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(-45.0f))).equals(1, -1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotate(Vec3f(degToRad(45.0f), degToRad(0.0f), degToRad(0.0f))).equals(0, 0, 2, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotate(Vec3f(degToRad(-45.0f), degToRad(0.0f), degToRad(0.0f))).equals(0, 2, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotate(Vec3f(degToRad(0.0f), degToRad(45.0f), degToRad(0.0f))).equals(1, sq2, 1, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotate(Vec3f(degToRad(0.0f), degToRad(-45.0f), degToRad(0.0f))).equals(-1, sq2, 1, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotate(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(45.0f))).equals(-1, 1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotate(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(-45.0f))).equals(1, 1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotate(Vec3f(degToRad(45.0f), degToRad(0.0f), degToRad(0.0f))).equals(sq2, 0, 2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotate(Vec3f(degToRad(-45.0f), degToRad(0.0f), degToRad(0.0f))).equals(sq2, 2, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotate(Vec3f(degToRad(0.0f), degToRad(45.0f), degToRad(0.0f))).equals(2, sq2, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotate(Vec3f(degToRad(0.0f), degToRad(-45.0f), degToRad(0.0f))).equals(0, sq2, 2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotate(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(45.0f))).equals(0, 2, sq2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotate(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(-45.0f))).equals(2, 0, sq2, 0.0001f), verbose);
			}
			{ // LHS
				Vec3f::DefaultAxisRule = Rules::AXIS_LHS;
				Assertve(Vec3f::DefaultAxisRule == Rules::AXIS_LHS, verbose);
				Assertv(Vec3f(5, 5, 5).rotate(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(0.0f))).equals(5, 5, 5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotate(Vec3f(degToRad(90.0f), degToRad(0.0f), degToRad(0.0f))).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotate(Vec3f(degToRad(0.0f), degToRad(90.0f), degToRad(0.0f))).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotate(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(90.0f))).equals(0, -5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotate(Vec3f(degToRad(90.0f), degToRad(0.0f), degToRad(0.0f))).equals(0, 0, -5, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotate(Vec3f(degToRad(0.0f), degToRad(90.0f), degToRad(0.0f))).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotate(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(90.0f))).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotate(Vec3f(degToRad(90.0f), degToRad(0.0f), degToRad(0.0f))).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotate(Vec3f(degToRad(0.0f), degToRad(90.0f), degToRad(0.0f))).equals(-5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotate(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(90.0f))).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotate(Vec3f(degToRad(-90.0f), degToRad(0.0f), degToRad(0.0f))).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotate(Vec3f(degToRad(0.0f), degToRad(-90.0f), degToRad(0.0f))).equals(0, 0, -5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotate(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(-90.0f))).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotate(Vec3f(degToRad(-90.0f), degToRad(0.0f), degToRad(0.0f))).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotate(Vec3f(degToRad(0.0f), degToRad(-90.0f), degToRad(0.0f))).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotate(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(-90.0f))).equals(-5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotate(Vec3f(degToRad(-90.0f), degToRad(0.0f), degToRad(0.0f))).equals(0, -5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotate(Vec3f(degToRad(0.0f), degToRad(-90.0f), degToRad(0.0f))).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotate(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(-90.0f))).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotate(Vec3f(degToRad(45.0f), degToRad(0.0f), degToRad(0.0f))).equals(sq2, 1, -1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotate(Vec3f(degToRad(-45.0f), degToRad(0.0f), degToRad(0.0f))).equals(sq2, 1, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotate(Vec3f(degToRad(0.0f), degToRad(45.0f), degToRad(0.0f))).equals(1, sq2, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotate(Vec3f(degToRad(0.0f), degToRad(-45.0f), degToRad(0.0f))).equals(1, sq2, -1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotate(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(45.0f))).equals(2, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotate(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(-45.0f))).equals(0, 2, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotate(Vec3f(degToRad(45.0f), degToRad(0.0f), degToRad(0.0f))).equals(sq2, 1, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotate(Vec3f(degToRad(-45.0f), degToRad(0.0f), degToRad(0.0f))).equals(sq2, -1, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotate(Vec3f(degToRad(0.0f), degToRad(45.0f), degToRad(0.0f))).equals(0, 0, 2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotate(Vec3f(degToRad(0.0f), degToRad(-45.0f), degToRad(0.0f))).equals(2, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotate(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(45.0f))).equals(1, -1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotate(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(-45.0f))).equals(1, 1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotate(Vec3f(degToRad(45.0f), degToRad(0.0f), degToRad(0.0f))).equals(0, 2, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotate(Vec3f(degToRad(-45.0f), degToRad(0.0f), degToRad(0.0f))).equals(0, 0, 2, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotate(Vec3f(degToRad(0.0f), degToRad(45.0f), degToRad(0.0f))).equals(-1, sq2, 1, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotate(Vec3f(degToRad(0.0f), degToRad(-45.0f), degToRad(0.0f))).equals(1, sq2, 1, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotate(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(45.0f))).equals(1, 1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotate(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(-45.0f))).equals(-1, 1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotate(Vec3f(degToRad(45.0f), degToRad(0.0f), degToRad(0.0f))).equals(sq2, 2, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotate(Vec3f(degToRad(-45.0f), degToRad(0.0f), degToRad(0.0f))).equals(sq2, 0, 2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotate(Vec3f(degToRad(0.0f), degToRad(45.0f), degToRad(0.0f))).equals(0, sq2, 2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotate(Vec3f(degToRad(0.0f), degToRad(-45.0f), degToRad(0.0f))).equals(2, sq2, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotate(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(45.0f))).equals(2, 0, sq2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotate(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(-45.0f))).equals(0, 2, sq2, 0.0001f), verbose);
			}
		}
		{ // rotateX
			{ // RHS
				Vec3f::DefaultAxisRule = Rules::AXIS_RHS;
				Assertve(Vec3f::DefaultAxisRule == Rules::AXIS_RHS, verbose);
				Assertv(Vec3f(5, 5, 5).rotateX(degToRad(0.0f)).equals(5, 5, 5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotateX(degToRad(90.0f)).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotateX(degToRad(90.0f)).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotateX(degToRad(90.0f)).equals(0, -5, 0, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotateX(degToRad(-90.0f)).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotateX(degToRad(-90.0f)).equals(0, 0, -5, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotateX(degToRad(-90.0f)).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotateX(degToRad(45.0f)).equals(sq2, 1, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotateX(degToRad(-45.0f)).equals(sq2, 1, -1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotateX(degToRad(45.0f)).equals(sq2, -1, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotateX(degToRad(-45.0f)).equals(sq2, 1, 1, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotateX(degToRad(45.0f)).equals(0, 0, 2, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotateX(degToRad(-45.0f)).equals(0, 2, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotateX(degToRad(45.0f)).equals(sq2, 0, 2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotateX(degToRad(-45.0f)).equals(sq2, 2, 0, 0.0001f), verbose);
			}
			{ // LHS
				Vec3f::DefaultAxisRule = Rules::AXIS_LHS;
				Assertve(Vec3f::DefaultAxisRule == Rules::AXIS_LHS, verbose);
				Assertv(Vec3f(5, 5, 5).rotateX(degToRad(0.0f)).equals(5, 5, 5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotateX(degToRad(90.0f)).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotateX(degToRad(90.0f)).equals(0, 0, -5, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotateX(degToRad(90.0f)).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotateX(degToRad(-90.0f)).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotateX(degToRad(-90.0f)).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotateX(degToRad(-90.0f)).equals(0, -5, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotateX(degToRad(45.0f)).equals(sq2, 1, -1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotateX(degToRad(-45.0f)).equals(sq2, 1, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotateX(degToRad(45.0f)).equals(sq2, 1, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotateX(degToRad(-45.0f)).equals(sq2, -1, 1, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotateX(degToRad(45.0f)).equals(0, 2, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotateX(degToRad(-45.0f)).equals(0, 0, 2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotateX(degToRad(45.0f)).equals(sq2, 2, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotateX(degToRad(-45.0f)).equals(sq2, 0, 2, 0.0001f), verbose);
			}
		}
		{ // rotateY
			{ // RHS
				Vec3f::DefaultAxisRule = Rules::AXIS_RHS;
				Assertve(Vec3f::DefaultAxisRule == Rules::AXIS_RHS, verbose);
				Assertv(Vec3f(5, 5, 5).rotateY(degToRad(0.0f)).equals(5, 5, 5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotateY(degToRad(90.0f)).equals(0, 0, -5, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotateY(degToRad(90.0f)).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotateY(degToRad(90.0f)).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotateY(degToRad(-90.0f)).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotateY(degToRad(-90.0f)).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotateY(degToRad(-90.0f)).equals(-5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotateY(degToRad(45.0f)).equals(1, sq2, -1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotateY(degToRad(-45.0f)).equals(1, sq2, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotateY(degToRad(45.0f)).equals(2, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotateY(degToRad(-45.0f)).equals(0, 0, 2, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotateY(degToRad(45.0f)).equals(1, sq2, 1, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotateY(degToRad(-45.0f)).equals(-1, sq2, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotateY(degToRad(45.0f)).equals(2, sq2, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotateY(degToRad(-45.0f)).equals(0, sq2, 2, 0.0001f), verbose);
			}
			{ // LHS
				Vec3f::DefaultAxisRule = Rules::AXIS_LHS;
				Assertve(Vec3f::DefaultAxisRule == Rules::AXIS_LHS, verbose);
				Assertv(Vec3f(5, 5, 5).rotateY(degToRad(0.0f)).equals(5, 5, 5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotateY(degToRad(90.0f)).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotateY(degToRad(90.0f)).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotateY(degToRad(90.0f)).equals(-5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotateY(degToRad(-90.0f)).equals(0, 0, -5, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotateY(degToRad(-90.0f)).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotateY(degToRad(-90.0f)).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotateY(degToRad(45.0f)).equals(1, sq2, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotateY(degToRad(-45.0f)).equals(1, sq2, -1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotateY(degToRad(45.0f)).equals(0, 0, 2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotateY(degToRad(-45.0f)).equals(2, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotateY(degToRad(45.0f)).equals(-1, sq2, 1, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotateY(degToRad(-45.0f)).equals(1, sq2, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotateY(degToRad(45.0f)).equals(0, sq2, 2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotateY(degToRad(-45.0f)).equals(2, sq2, 0, 0.0001f), verbose);
			}
		}
		{ // rotateZ
			{ // RHS
				Vec3f::DefaultAxisRule = Rules::AXIS_RHS;
				Assertve(Vec3f::DefaultAxisRule == Rules::AXIS_RHS, verbose);
				Assertv(Vec3f(5, 5, 5).rotateZ(degToRad(0.0f)).equals(5, 5, 5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotateZ(degToRad(90.0f)).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotateZ(degToRad(90.0f)).equals(-5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotateZ(degToRad(90.0f)).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotateZ(degToRad(-90.0f)).equals(0, -5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotateZ(degToRad(-90.0f)).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotateZ(degToRad(-90.0f)).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotateZ(degToRad(45.0f)).equals(0, 2, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotateZ(degToRad(-45.0f)).equals(2, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotateZ(degToRad(45.0f)).equals(1, 1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotateZ(degToRad(-45.0f)).equals(1, -1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotateZ(degToRad(45.0f)).equals(-1, 1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotateZ(degToRad(-45.0f)).equals(1, 1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotateZ(degToRad(45.0f)).equals(0, 2, sq2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotateZ(degToRad(-45.0f)).equals(2, 0, sq2, 0.0001f), verbose);
			}
			{ // LHS
				Vec3f::DefaultAxisRule = Rules::AXIS_LHS;
				Assertve(Vec3f::DefaultAxisRule == Rules::AXIS_LHS, verbose);
				Assertv(Vec3f(5, 5, 5).rotateZ(degToRad(0.0f)).equals(5, 5, 5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotateZ(degToRad(90.0f)).equals(0, -5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotateZ(degToRad(90.0f)).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotateZ(degToRad(90.0f)).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotateZ(degToRad(-90.0f)).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotateZ(degToRad(-90.0f)).equals(-5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotateZ(degToRad(-90.0f)).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotateZ(degToRad(45.0f)).equals(2, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotateZ(degToRad(-45.0f)).equals(0, 2, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotateZ(degToRad(45.0f)).equals(1, -1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotateZ(degToRad(-45.0f)).equals(1, 1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotateZ(degToRad(45.0f)).equals(1, 1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotateZ(degToRad(-45.0f)).equals(-1, 1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotateZ(degToRad(45.0f)).equals(2, 0, sq2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotateZ(degToRad(-45.0f)).equals(0, 2, sq2, 0.0001f), verbose);
			}
		}
		{ // rotated
			{ // RHS
				Vec3f::DefaultAxisRule = Rules::AXIS_RHS;
				Assertve(Vec3f::DefaultAxisRule == Rules::AXIS_RHS, verbose);
				Assertv(Vec3f(5, 5, 5).rotated(degToRad(0.0f), degToRad(0.0f), degToRad(0.0f)).equals(5, 5, 5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotated(degToRad(90.0f), degToRad(0.0f), degToRad(0.0f)).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotated(degToRad(0.0f), degToRad(90.0f), degToRad(0.0f)).equals(0, 0, -5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotated(degToRad(0.0f), degToRad(0.0f), degToRad(90.0f)).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotated(degToRad(90.0f), degToRad(0.0f), degToRad(0.0f)).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotated(degToRad(0.0f), degToRad(90.0f), degToRad(0.0f)).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotated(degToRad(0.0f), degToRad(0.0f), degToRad(90.0f)).equals(-5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotated(degToRad(90.0f), degToRad(0.0f), degToRad(0.0f)).equals(0, -5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotated(degToRad(0.0f), degToRad(90.0f), degToRad(0.0f)).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotated(degToRad(0.0f), degToRad(0.0f), degToRad(90.0f)).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotated(degToRad(-90.0f), degToRad(0.0f), degToRad(0.0f)).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotated(degToRad(0.0f), degToRad(-90.0f), degToRad(0.0f)).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotated(degToRad(0.0f), degToRad(0.0f), degToRad(-90.0f)).equals(0, -5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotated(degToRad(-90.0f), degToRad(0.0f), degToRad(0.0f)).equals(0, 0, -5, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotated(degToRad(0.0f), degToRad(-90.0f), degToRad(0.0f)).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotated(degToRad(0.0f), degToRad(0.0f), degToRad(-90.0f)).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotated(degToRad(-90.0f), degToRad(0.0f), degToRad(0.0f)).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotated(degToRad(0.0f), degToRad(-90.0f), degToRad(0.0f)).equals(-5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotated(degToRad(0.0f), degToRad(0.0f), degToRad(-90.0f)).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotated(degToRad(45.0f), degToRad(0.0f), degToRad(0.0f)).equals(sq2, 1, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotated(degToRad(-45.0f), degToRad(0.0f), degToRad(0.0f)).equals(sq2, 1, -1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotated(degToRad(0.0f), degToRad(45.0f), degToRad(0.0f)).equals(1, sq2, -1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotated(degToRad(0.0f), degToRad(-45.0f), degToRad(0.0f)).equals(1, sq2, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotated(degToRad(0.0f), degToRad(0.0f), degToRad(45.0f)).equals(0, 2, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotated(degToRad(0.0f), degToRad(0.0f), degToRad(-45.0f)).equals(2, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotated(degToRad(45.0f), degToRad(0.0f), degToRad(0.0f)).equals(sq2, -1, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotated(degToRad(-45.0f), degToRad(0.0f), degToRad(0.0f)).equals(sq2, 1, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotated(degToRad(0.0f), degToRad(45.0f), degToRad(0.0f)).equals(2, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotated(degToRad(0.0f), degToRad(-45.0f), degToRad(0.0f)).equals(0, 0, 2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotated(degToRad(0.0f), degToRad(0.0f), degToRad(45.0f)).equals(1, 1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotated(degToRad(0.0f), degToRad(0.0f), degToRad(-45.0f)).equals(1, -1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotated(degToRad(45.0f), degToRad(0.0f), degToRad(0.0f)).equals(0, 0, 2, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotated(degToRad(-45.0f), degToRad(0.0f), degToRad(0.0f)).equals(0, 2, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotated(degToRad(0.0f), degToRad(45.0f), degToRad(0.0f)).equals(1, sq2, 1, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotated(degToRad(0.0f), degToRad(-45.0f), degToRad(0.0f)).equals(-1, sq2, 1, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotated(degToRad(0.0f), degToRad(0.0f), degToRad(45.0f)).equals(-1, 1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotated(degToRad(0.0f), degToRad(0.0f), degToRad(-45.0f)).equals(1, 1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotated(degToRad(45.0f), degToRad(0.0f), degToRad(0.0f)).equals(sq2, 0, 2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotated(degToRad(-45.0f), degToRad(0.0f), degToRad(0.0f)).equals(sq2, 2, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotated(degToRad(0.0f), degToRad(45.0f), degToRad(0.0f)).equals(2, sq2, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotated(degToRad(0.0f), degToRad(-45.0f), degToRad(0.0f)).equals(0, sq2, 2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotated(degToRad(0.0f), degToRad(0.0f), degToRad(45.0f)).equals(0, 2, sq2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotated(degToRad(0.0f), degToRad(0.0f), degToRad(-45.0f)).equals(2, 0, sq2, 0.0001f), verbose);
			}
			{ // LHS
				Vec3f::DefaultAxisRule = Rules::AXIS_LHS;
				Assertve(Vec3f::DefaultAxisRule == Rules::AXIS_LHS, verbose);
				Assertv(Vec3f(5, 5, 5).rotated(degToRad(0.0f), degToRad(0.0f), degToRad(0.0f)).equals(5, 5, 5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotated(degToRad(90.0f), degToRad(0.0f), degToRad(0.0f)).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotated(degToRad(0.0f), degToRad(90.0f), degToRad(0.0f)).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotated(degToRad(0.0f), degToRad(0.0f), degToRad(90.0f)).equals(0, -5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotated(degToRad(90.0f), degToRad(0.0f), degToRad(0.0f)).equals(0, 0, -5, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotated(degToRad(0.0f), degToRad(90.0f), degToRad(0.0f)).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotated(degToRad(0.0f), degToRad(0.0f), degToRad(90.0f)).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotated(degToRad(90.0f), degToRad(0.0f), degToRad(0.0f)).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotated(degToRad(0.0f), degToRad(90.0f), degToRad(0.0f)).equals(-5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotated(degToRad(0.0f), degToRad(0.0f), degToRad(90.0f)).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotated(degToRad(-90.0f), degToRad(0.0f), degToRad(0.0f)).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotated(degToRad(0.0f), degToRad(-90.0f), degToRad(0.0f)).equals(0, 0, -5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotated(degToRad(0.0f), degToRad(0.0f), degToRad(-90.0f)).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotated(degToRad(-90.0f), degToRad(0.0f), degToRad(0.0f)).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotated(degToRad(0.0f), degToRad(-90.0f), degToRad(0.0f)).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotated(degToRad(0.0f), degToRad(0.0f), degToRad(-90.0f)).equals(-5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotated(degToRad(-90.0f), degToRad(0.0f), degToRad(0.0f)).equals(0, -5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotated(degToRad(0.0f), degToRad(-90.0f), degToRad(0.0f)).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotated(degToRad(0.0f), degToRad(0.0f), degToRad(-90.0f)).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotated(degToRad(45.0f), degToRad(0.0f), degToRad(0.0f)).equals(sq2, 1, -1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotated(degToRad(-45.0f), degToRad(0.0f), degToRad(0.0f)).equals(sq2, 1, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotated(degToRad(0.0f), degToRad(45.0f), degToRad(0.0f)).equals(1, sq2, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotated(degToRad(0.0f), degToRad(-45.0f), degToRad(0.0f)).equals(1, sq2, -1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotated(degToRad(0.0f), degToRad(0.0f), degToRad(45.0f)).equals(2, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotated(degToRad(0.0f), degToRad(0.0f), degToRad(-45.0f)).equals(0, 2, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotated(degToRad(45.0f), degToRad(0.0f), degToRad(0.0f)).equals(sq2, 1, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotated(degToRad(-45.0f), degToRad(0.0f), degToRad(0.0f)).equals(sq2, -1, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotated(degToRad(0.0f), degToRad(45.0f), degToRad(0.0f)).equals(0, 0, 2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotated(degToRad(0.0f), degToRad(-45.0f), degToRad(0.0f)).equals(2, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotated(degToRad(0.0f), degToRad(0.0f), degToRad(45.0f)).equals(1, -1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotated(degToRad(0.0f), degToRad(0.0f), degToRad(-45.0f)).equals(1, 1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotated(degToRad(45.0f), degToRad(0.0f), degToRad(0.0f)).equals(0, 2, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotated(degToRad(-45.0f), degToRad(0.0f), degToRad(0.0f)).equals(0, 0, 2, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotated(degToRad(0.0f), degToRad(45.0f), degToRad(0.0f)).equals(-1, sq2, 1, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotated(degToRad(0.0f), degToRad(-45.0f), degToRad(0.0f)).equals(1, sq2, 1, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotated(degToRad(0.0f), degToRad(0.0f), degToRad(45.0f)).equals(1, 1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotated(degToRad(0.0f), degToRad(0.0f), degToRad(-45.0f)).equals(-1, 1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotated(degToRad(45.0f), degToRad(0.0f), degToRad(0.0f)).equals(sq2, 2, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotated(degToRad(-45.0f), degToRad(0.0f), degToRad(0.0f)).equals(sq2, 0, 2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotated(degToRad(0.0f), degToRad(45.0f), degToRad(0.0f)).equals(0, sq2, 2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotated(degToRad(0.0f), degToRad(-45.0f), degToRad(0.0f)).equals(2, sq2, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotated(degToRad(0.0f), degToRad(0.0f), degToRad(45.0f)).equals(2, 0, sq2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotated(degToRad(0.0f), degToRad(0.0f), degToRad(-45.0f)).equals(0, 2, sq2, 0.0001f), verbose);
			}
		}
		{ // rotated - angle_vec
			{ // RHS
				Vec3f::DefaultAxisRule = Rules::AXIS_RHS;
				Assertve(Vec3f::DefaultAxisRule == Rules::AXIS_RHS, verbose);
				Assertv(Vec3f(5, 5, 5).rotated(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(0.0f))).equals(5, 5, 5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotated(Vec3f(degToRad(90.0f), degToRad(0.0f), degToRad(0.0f))).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotated(Vec3f(degToRad(0.0f), degToRad(90.0f), degToRad(0.0f))).equals(0, 0, -5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotated(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(90.0f))).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotated(Vec3f(degToRad(90.0f), degToRad(0.0f), degToRad(0.0f))).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotated(Vec3f(degToRad(0.0f), degToRad(90.0f), degToRad(0.0f))).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotated(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(90.0f))).equals(-5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotated(Vec3f(degToRad(90.0f), degToRad(0.0f), degToRad(0.0f))).equals(0, -5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotated(Vec3f(degToRad(0.0f), degToRad(90.0f), degToRad(0.0f))).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotated(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(90.0f))).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotated(Vec3f(degToRad(-90.0f), degToRad(0.0f), degToRad(0.0f))).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotated(Vec3f(degToRad(0.0f), degToRad(-90.0f), degToRad(0.0f))).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotated(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(-90.0f))).equals(0, -5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotated(Vec3f(degToRad(-90.0f), degToRad(0.0f), degToRad(0.0f))).equals(0, 0, -5, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotated(Vec3f(degToRad(0.0f), degToRad(-90.0f), degToRad(0.0f))).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotated(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(-90.0f))).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotated(Vec3f(degToRad(-90.0f), degToRad(0.0f), degToRad(0.0f))).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotated(Vec3f(degToRad(0.0f), degToRad(-90.0f), degToRad(0.0f))).equals(-5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotated(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(-90.0f))).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotated(Vec3f(degToRad(45.0f), degToRad(0.0f), degToRad(0.0f))).equals(sq2, 1, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotated(Vec3f(degToRad(-45.0f), degToRad(0.0f), degToRad(0.0f))).equals(sq2, 1, -1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotated(Vec3f(degToRad(0.0f), degToRad(45.0f), degToRad(0.0f))).equals(1, sq2, -1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotated(Vec3f(degToRad(0.0f), degToRad(-45.0f), degToRad(0.0f))).equals(1, sq2, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotated(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(45.0f))).equals(0, 2, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotated(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(-45.0f))).equals(2, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotated(Vec3f(degToRad(45.0f), degToRad(0.0f), degToRad(0.0f))).equals(sq2, -1, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotated(Vec3f(degToRad(-45.0f), degToRad(0.0f), degToRad(0.0f))).equals(sq2, 1, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotated(Vec3f(degToRad(0.0f), degToRad(45.0f), degToRad(0.0f))).equals(2, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotated(Vec3f(degToRad(0.0f), degToRad(-45.0f), degToRad(0.0f))).equals(0, 0, 2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotated(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(45.0f))).equals(1, 1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotated(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(-45.0f))).equals(1, -1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotated(Vec3f(degToRad(45.0f), degToRad(0.0f), degToRad(0.0f))).equals(0, 0, 2, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotated(Vec3f(degToRad(-45.0f), degToRad(0.0f), degToRad(0.0f))).equals(0, 2, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotated(Vec3f(degToRad(0.0f), degToRad(45.0f), degToRad(0.0f))).equals(1, sq2, 1, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotated(Vec3f(degToRad(0.0f), degToRad(-45.0f), degToRad(0.0f))).equals(-1, sq2, 1, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotated(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(45.0f))).equals(-1, 1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotated(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(-45.0f))).equals(1, 1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotated(Vec3f(degToRad(45.0f), degToRad(0.0f), degToRad(0.0f))).equals(sq2, 0, 2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotated(Vec3f(degToRad(-45.0f), degToRad(0.0f), degToRad(0.0f))).equals(sq2, 2, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotated(Vec3f(degToRad(0.0f), degToRad(45.0f), degToRad(0.0f))).equals(2, sq2, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotated(Vec3f(degToRad(0.0f), degToRad(-45.0f), degToRad(0.0f))).equals(0, sq2, 2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotated(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(45.0f))).equals(0, 2, sq2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotated(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(-45.0f))).equals(2, 0, sq2, 0.0001f), verbose);
			}
			{ // LHS
				Vec3f::DefaultAxisRule = Rules::AXIS_LHS;
				Assertve(Vec3f::DefaultAxisRule == Rules::AXIS_LHS, verbose);
				Assertv(Vec3f(5, 5, 5).rotated(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(0.0f))).equals(5, 5, 5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotated(Vec3f(degToRad(90.0f), degToRad(0.0f), degToRad(0.0f))).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotated(Vec3f(degToRad(0.0f), degToRad(90.0f), degToRad(0.0f))).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotated(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(90.0f))).equals(0, -5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotated(Vec3f(degToRad(90.0f), degToRad(0.0f), degToRad(0.0f))).equals(0, 0, -5, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotated(Vec3f(degToRad(0.0f), degToRad(90.0f), degToRad(0.0f))).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotated(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(90.0f))).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotated(Vec3f(degToRad(90.0f), degToRad(0.0f), degToRad(0.0f))).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotated(Vec3f(degToRad(0.0f), degToRad(90.0f), degToRad(0.0f))).equals(-5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotated(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(90.0f))).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotated(Vec3f(degToRad(-90.0f), degToRad(0.0f), degToRad(0.0f))).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotated(Vec3f(degToRad(0.0f), degToRad(-90.0f), degToRad(0.0f))).equals(0, 0, -5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotated(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(-90.0f))).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotated(Vec3f(degToRad(-90.0f), degToRad(0.0f), degToRad(0.0f))).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotated(Vec3f(degToRad(0.0f), degToRad(-90.0f), degToRad(0.0f))).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotated(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(-90.0f))).equals(-5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotated(Vec3f(degToRad(-90.0f), degToRad(0.0f), degToRad(0.0f))).equals(0, -5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotated(Vec3f(degToRad(0.0f), degToRad(-90.0f), degToRad(0.0f))).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotated(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(-90.0f))).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotated(Vec3f(degToRad(45.0f), degToRad(0.0f), degToRad(0.0f))).equals(sq2, 1, -1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotated(Vec3f(degToRad(-45.0f), degToRad(0.0f), degToRad(0.0f))).equals(sq2, 1, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotated(Vec3f(degToRad(0.0f), degToRad(45.0f), degToRad(0.0f))).equals(1, sq2, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotated(Vec3f(degToRad(0.0f), degToRad(-45.0f), degToRad(0.0f))).equals(1, sq2, -1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotated(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(45.0f))).equals(2, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotated(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(-45.0f))).equals(0, 2, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotated(Vec3f(degToRad(45.0f), degToRad(0.0f), degToRad(0.0f))).equals(sq2, 1, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotated(Vec3f(degToRad(-45.0f), degToRad(0.0f), degToRad(0.0f))).equals(sq2, -1, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotated(Vec3f(degToRad(0.0f), degToRad(45.0f), degToRad(0.0f))).equals(0, 0, 2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotated(Vec3f(degToRad(0.0f), degToRad(-45.0f), degToRad(0.0f))).equals(2, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotated(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(45.0f))).equals(1, -1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotated(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(-45.0f))).equals(1, 1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotated(Vec3f(degToRad(45.0f), degToRad(0.0f), degToRad(0.0f))).equals(0, 2, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotated(Vec3f(degToRad(-45.0f), degToRad(0.0f), degToRad(0.0f))).equals(0, 0, 2, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotated(Vec3f(degToRad(0.0f), degToRad(45.0f), degToRad(0.0f))).equals(-1, sq2, 1, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotated(Vec3f(degToRad(0.0f), degToRad(-45.0f), degToRad(0.0f))).equals(1, sq2, 1, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotated(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(45.0f))).equals(1, 1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotated(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(-45.0f))).equals(-1, 1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotated(Vec3f(degToRad(45.0f), degToRad(0.0f), degToRad(0.0f))).equals(sq2, 2, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotated(Vec3f(degToRad(-45.0f), degToRad(0.0f), degToRad(0.0f))).equals(sq2, 0, 2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotated(Vec3f(degToRad(0.0f), degToRad(45.0f), degToRad(0.0f))).equals(0, sq2, 2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotated(Vec3f(degToRad(0.0f), degToRad(-45.0f), degToRad(0.0f))).equals(2, sq2, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotated(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(45.0f))).equals(2, 0, sq2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotated(Vec3f(degToRad(0.0f), degToRad(0.0f), degToRad(-45.0f))).equals(0, 2, sq2, 0.0001f), verbose);
			}
		}
		{ // rotatedX
			{ // RHS
				Vec3f::DefaultAxisRule = Rules::AXIS_RHS;
				Assertve(Vec3f::DefaultAxisRule == Rules::AXIS_RHS, verbose);
				Assertv(Vec3f(5, 5, 5).rotatedX(degToRad(0.0f)).equals(5, 5, 5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotatedX(degToRad(90.0f)).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotatedX(degToRad(90.0f)).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotatedX(degToRad(90.0f)).equals(0, -5, 0, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotatedX(degToRad(-90.0f)).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotatedX(degToRad(-90.0f)).equals(0, 0, -5, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotatedX(degToRad(-90.0f)).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotatedX(degToRad(45.0f)).equals(sq2, 1, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotatedX(degToRad(-45.0f)).equals(sq2, 1, -1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotatedX(degToRad(45.0f)).equals(sq2, -1, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotatedX(degToRad(-45.0f)).equals(sq2, 1, 1, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotatedX(degToRad(45.0f)).equals(0, 0, 2, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotatedX(degToRad(-45.0f)).equals(0, 2, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotatedX(degToRad(45.0f)).equals(sq2, 0, 2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotatedX(degToRad(-45.0f)).equals(sq2, 2, 0, 0.0001f), verbose);
			}
			{ // LHS
				Vec3f::DefaultAxisRule = Rules::AXIS_LHS;
				Assertve(Vec3f::DefaultAxisRule == Rules::AXIS_LHS, verbose);
				Assertv(Vec3f(5, 5, 5).rotatedX(degToRad(0.0f)).equals(5, 5, 5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotatedX(degToRad(90.0f)).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotatedX(degToRad(90.0f)).equals(0, 0, -5, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotatedX(degToRad(90.0f)).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotatedX(degToRad(-90.0f)).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotatedX(degToRad(-90.0f)).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotatedX(degToRad(-90.0f)).equals(0, -5, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotatedX(degToRad(45.0f)).equals(sq2, 1, -1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotatedX(degToRad(-45.0f)).equals(sq2, 1, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotatedX(degToRad(45.0f)).equals(sq2, 1, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotatedX(degToRad(-45.0f)).equals(sq2, -1, 1, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotatedX(degToRad(45.0f)).equals(0, 2, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotatedX(degToRad(-45.0f)).equals(0, 0, 2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotatedX(degToRad(45.0f)).equals(sq2, 2, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotatedX(degToRad(-45.0f)).equals(sq2, 0, 2, 0.0001f), verbose);
			}
		}
		{ // rotatedY
			{ // RHS
				Vec3f::DefaultAxisRule = Rules::AXIS_RHS;
				Assertve(Vec3f::DefaultAxisRule == Rules::AXIS_RHS, verbose);
				Assertv(Vec3f(5, 5, 5).rotatedY(degToRad(0.0f)).equals(5, 5, 5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotatedY(degToRad(90.0f)).equals(0, 0, -5, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotatedY(degToRad(90.0f)).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotatedY(degToRad(90.0f)).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotatedY(degToRad(-90.0f)).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotatedY(degToRad(-90.0f)).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotatedY(degToRad(-90.0f)).equals(-5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotatedY(degToRad(45.0f)).equals(1, sq2, -1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotatedY(degToRad(-45.0f)).equals(1, sq2, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotatedY(degToRad(45.0f)).equals(2, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotatedY(degToRad(-45.0f)).equals(0, 0, 2, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotatedY(degToRad(45.0f)).equals(1, sq2, 1, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotatedY(degToRad(-45.0f)).equals(-1, sq2, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotatedY(degToRad(45.0f)).equals(2, sq2, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotatedY(degToRad(-45.0f)).equals(0, sq2, 2, 0.0001f), verbose);
			}
			{ // LHS
				Vec3f::DefaultAxisRule = Rules::AXIS_LHS;
				Assertve(Vec3f::DefaultAxisRule == Rules::AXIS_LHS, verbose);
				Assertv(Vec3f(5, 5, 5).rotatedY(degToRad(0.0f)).equals(5, 5, 5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotatedY(degToRad(90.0f)).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotatedY(degToRad(90.0f)).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotatedY(degToRad(90.0f)).equals(-5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotatedY(degToRad(-90.0f)).equals(0, 0, -5, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotatedY(degToRad(-90.0f)).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotatedY(degToRad(-90.0f)).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotatedY(degToRad(45.0f)).equals(1, sq2, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotatedY(degToRad(-45.0f)).equals(1, sq2, -1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotatedY(degToRad(45.0f)).equals(0, 0, 2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotatedY(degToRad(-45.0f)).equals(2, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotatedY(degToRad(45.0f)).equals(-1, sq2, 1, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotatedY(degToRad(-45.0f)).equals(1, sq2, 1, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotatedY(degToRad(45.0f)).equals(0, sq2, 2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotatedY(degToRad(-45.0f)).equals(2, sq2, 0, 0.0001f), verbose);
			}
		}
		{ // rotatedZ
			{ // RHS
				Vec3f::DefaultAxisRule = Rules::AXIS_RHS;
				Assertve(Vec3f::DefaultAxisRule == Rules::AXIS_RHS, verbose);
				Assertv(Vec3f(5, 5, 5).rotatedZ(degToRad(0.0f)).equals(5, 5, 5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotatedZ(degToRad(90.0f)).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotatedZ(degToRad(90.0f)).equals(-5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotatedZ(degToRad(90.0f)).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotatedZ(degToRad(-90.0f)).equals(0, -5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotatedZ(degToRad(-90.0f)).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotatedZ(degToRad(-90.0f)).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotatedZ(degToRad(45.0f)).equals(0, 2, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotatedZ(degToRad(-45.0f)).equals(2, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotatedZ(degToRad(45.0f)).equals(1, 1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotatedZ(degToRad(-45.0f)).equals(1, -1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotatedZ(degToRad(45.0f)).equals(-1, 1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotatedZ(degToRad(-45.0f)).equals(1, 1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotatedZ(degToRad(45.0f)).equals(0, 2, sq2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotatedZ(degToRad(-45.0f)).equals(2, 0, sq2, 0.0001f), verbose);
			}
			{ // LHS
				Vec3f::DefaultAxisRule = Rules::AXIS_LHS;
				Assertve(Vec3f::DefaultAxisRule == Rules::AXIS_LHS, verbose);
				Assertv(Vec3f(5, 5, 5).rotatedZ(degToRad(0.0f)).equals(5, 5, 5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotatedZ(degToRad(90.0f)).equals(0, -5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotatedZ(degToRad(90.0f)).equals(5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotatedZ(degToRad(90.0f)).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(5, 0, 0).rotatedZ(degToRad(-90.0f)).equals(0, 5, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 5, 0).rotatedZ(degToRad(-90.0f)).equals(-5, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(0, 0, 5).rotatedZ(degToRad(-90.0f)).equals(0, 0, 5, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotatedZ(degToRad(45.0f)).equals(2, 0, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, 0).rotatedZ(degToRad(-45.0f)).equals(0, 2, 0, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotatedZ(degToRad(45.0f)).equals(1, -1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, 0, sq2).rotatedZ(degToRad(-45.0f)).equals(1, 1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotatedZ(degToRad(45.0f)).equals(1, 1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(0, sq2, sq2).rotatedZ(degToRad(-45.0f)).equals(-1, 1, sq2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotatedZ(degToRad(45.0f)).equals(2, 0, sq2, 0.0001f), verbose);
				Assertv(Vec3f(sq2, sq2, sq2).rotatedZ(degToRad(-45.0f)).equals(0, 2, sq2, 0.0001f), verbose);
			}
		}
	}

	if(Assert::_num_failed_tests <= 0)
		printf("# All Good!\n", Assert::_num_failed_tests);
	else
	{
		puts("----------------------------------------");
		printf("# %d Failed!\n", Assert::_num_failed_tests);
	}
	return Assert::_num_failed_tests;
}