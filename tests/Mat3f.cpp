#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include "Assert.hpp"
#include "lib.hpp"
#include <axl.math/float.hpp>
#include <axl.math/Mat3f.hpp>
#include <axl.math/Mat3d.hpp>

int main(int argc, char *argv[])
{
	bool verbose = argc > 1 && (0 == strcmp(argv[1], "-v") || 0 == strcmp(argv[1], "--verbose"));
	using namespace axl;
	using namespace axl::math;
	printf("axl.math - version %hu.%hu.%hu  %s %s\n", lib::VERSION.major, lib::VERSION.minor, lib::VERSION.patch, libType(lib::LIBRARY_TYPE), buildType(lib::BUILD_TYPE));
	puts("----------------------------------------");
	{ // static values
		Assertv(Float::equals(0.0f, Mat3f::Zero.values[0]), verbose);
		Assertv(Float::equals(0.0f, Mat3f::Zero.values[1]), verbose);
		Assertv(Float::equals(0.0f, Mat3f::Zero.values[2]), verbose);
		Assertv(Float::equals(0.0f, Mat3f::Zero.values[3]), verbose);
		Assertv(Float::equals(0.0f, Mat3f::Zero.values[4]), verbose);
		Assertv(Float::equals(0.0f, Mat3f::Zero.values[5]), verbose);
		Assertv(Float::equals(0.0f, Mat3f::Zero.values[6]), verbose);
		Assertv(Float::equals(0.0f, Mat3f::Zero.values[7]), verbose);
		Assertv(Float::equals(0.0f, Mat3f::Zero.values[8]), verbose);
		Assertv(Float::equals(1.0f, Mat3f::Identity.values[0]), verbose);
		Assertv(Float::equals(0.0f, Mat3f::Identity.values[1]), verbose);
		Assertv(Float::equals(0.0f, Mat3f::Identity.values[2]), verbose);
		Assertv(Float::equals(0.0f, Mat3f::Identity.values[3]), verbose);
		Assertv(Float::equals(1.0f, Mat3f::Identity.values[4]), verbose);
		Assertv(Float::equals(0.0f, Mat3f::Identity.values[5]), verbose);
		Assertv(Float::equals(0.0f, Mat3f::Identity.values[6]), verbose);
		Assertv(Float::equals(0.0f, Mat3f::Identity.values[7]), verbose);
		Assertv(Float::equals(1.0f, Mat3f::Identity.values[8]), verbose);
		Assertv(Mat3f::filled(4.0f).equals(4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f), verbose);
	}
	{ // constructors
		{ // default constructor
			const Mat3f mat;
			Assertv(Float::equals(0.0f, mat.values[0]), verbose);
			Assertv(Float::equals(0.0f, mat.values[1]), verbose);
			Assertv(Float::equals(0.0f, mat.values[2]), verbose);
			Assertv(Float::equals(0.0f, mat.values[3]), verbose);
			Assertv(Float::equals(0.0f, mat.values[4]), verbose);
			Assertv(Float::equals(0.0f, mat.values[5]), verbose);
			Assertv(Float::equals(0.0f, mat.values[6]), verbose);
			Assertv(Float::equals(0.0f, mat.values[7]), verbose);
			Assertv(Float::equals(0.0f, mat.values[8]), verbose);
		}
		{ // value constructor
			const Mat3f mat(3.1415f);
			Assertv(mat.equals(3.1415f, 0.0f, 0.0f, 0.0f, 3.1415f, 0.0f, 0.0f, 0.0f, 3.1415f), verbose);
		}
		{ // values constructor
			const Mat3f mat(3.1415f, 0.6734f, 3.45f, 0.44f, 45.67f, 0.5f, 1.2f, 3.333f, 1.09f);
			Assertv(mat.equals(3.1415f, 0.6734f, 3.45f, 0.44f, 45.67f, 0.5f, 1.2f, 3.333f, 1.09f), verbose);
		}
		{ // copy constructor
			const Mat3f mat(3.1415f, 0.6734f, 3.45f, 0.44f, 45.67f, 0.5f, 1.2f, 3.333f, 1.09f);
			Assertv(mat.equals(3.1415f, 0.6734f, 3.45f, 0.44f, 45.67f, 0.5f, 1.2f, 3.333f, 1.09f), verbose);
			const Mat3f mat1(mat);
			Assertv(mat1.equals(3.1415f, 0.6734f, 3.45f, 0.44f, 45.67f, 0.5f, 1.2f, 3.333f, 1.09f, 0.0001f), verbose);
			const Mat3f mat2 = mat;
			Assertv(mat2.equals(3.1415f, 0.6734f, 3.45f, 0.44f, 45.67f, 0.5f, 1.2f, 3.333f, 1.09f), verbose);
			Assertv(Mat3f(Mat3d(3.1415, 0.6734, 3.45, 0.44, 45.67, 0.5, 1.2, 3.333, 1.09)).equals(3.1415f, 0.6734f, 3.45f, 0.44f, 45.67f, 0.5f, 1.2f, 3.333f, 1.09f), verbose);
		}
	}
	{ // square bracket operators
		const Mat3f mat(3.1415f, 0.6734f, 3.45f, 0.44f, 45.67f, 0.5f, 1.2f, 3.333f, 1.09f);
		Assertv(mat.equals(3.1415f, 0.6734f, 3.45f, 0.44f, 45.67f, 0.5f, 1.2f, 3.333f, 1.09f), verbose);
	}
	{ // equality operators
		Assertv(Mat3f::Zero == 0.0f, verbose);
		Assertv(Mat3f::filled(1.0f) == 1.0f, verbose);
		Assertv(Mat3f::Zero == Mat3f::Zero, verbose);
		Assertv(Mat3f::Identity == Mat3f::Identity, verbose);
		Assertv(!(Mat3f::Zero != 0.0f), verbose);
		Assertv(!(Mat3f::filled(1.0f) != 1.0f), verbose);
		Assertv(!(Mat3f::Zero != Mat3f::Zero), verbose);
		Assertv(!(Mat3f::Identity != Mat3f::Identity), verbose);
		Mat3f mat(3.1415f, 0.6734f, 3.45f, 0.44f, 45.67f, 0.5f, 1.2f, 3.333f, 1.09f), mat2(3.1415f, 0.6734f, 1.2345f, 0.987654f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f);
		Assertv(mat.equals(3.1415f, 0.6734f, 3.45f, 0.44f, 45.67f, 0.5f, 1.2f, 3.333f, 1.09f), verbose);
		Assertv(mat.equals(mat), verbose);
		Assertv(!mat.equals(3.1415f), verbose);
		Assertv(!mat.equals(3.45f), verbose);
		Assertv(!mat.equals(mat2), verbose);
		Assertv(!mat.notEquals(3.1415f, 0.6734f, 3.45f, 0.44f, 45.67f, 0.5f, 1.2f, 3.333f, 1.09f), verbose);
		Assertv(!mat.notEquals(mat), verbose);
		Assertv(mat.notEquals(3.1415f), verbose);
		Assertv(mat.notEquals(3.45f), verbose);
		Assertv(mat.notEquals(mat2), verbose);
	}
	{ // arthimetic operators
		const float lval_0 = 12.344f, lval_1 = 131.04f, lval_2 = 0.4555f, lval_3 = 23000.45f, lval_4 = 45.67f, lval_5 = 0.5f, lval_6 = 1.2f, lval_7 = 3.333f, lval_8 = 1.09f;
		const float rval_0 = 10023.54f, rval_1 = 45.323f, rval_2 = 1.233f, rval_3 = 0.5f, rval_4 = 145.67f, rval_5 = 10.5f, rval_6 = 11.2f, rval_7 = 13.333f, rval_8 = 11.09f;
		{ // scalar addition
			const Mat3f lmat(lval_0, lval_1, lval_2, lval_3, lval_4, lval_5, lval_6, lval_7, lval_8);
			const Mat3f rmat(rval_0, rval_1, rval_2, rval_3, rval_4, rval_5, rval_6, rval_7, rval_8);
			Assertv(lmat.equals(lval_0, lval_1, lval_2, lval_3, lval_4, lval_5, lval_6, lval_7, lval_8), verbose);
			Assertv(rmat.equals(rval_0, rval_1, rval_2, rval_3, rval_4, rval_5, rval_6, rval_7, rval_8), verbose);
			Mat3f mat = lmat + rmat;
			Assertv(mat.equals(lval_0 + rval_0, lval_1 + rval_1, lval_2 + rval_2, lval_3 + rval_3, lval_4 + rval_4, lval_5 + rval_5, lval_6 + rval_6, lval_7 + rval_7, lval_8 + rval_8), verbose );
			
			mat = lmat + rval_0;
			Assertv(mat.equals(lval_0 + rval_0, lval_1 + rval_0, lval_2 + rval_0, lval_3 + rval_0, lval_4 + rval_0, lval_5 + rval_0, lval_6 + rval_0, lval_7 + rval_0, lval_8 + rval_0), verbose );

			mat = lmat;
			Assertv(mat.equals(lval_0, lval_1, lval_2, lval_3, lval_4, lval_5, lval_6, lval_7, lval_8), verbose);
			mat += rmat;
			Assertv(mat.equals(lval_0 + rval_0, lval_1 + rval_1, lval_2 + rval_2, lval_3 + rval_3, lval_4 + rval_4, lval_5 + rval_5, lval_6 + rval_6, lval_7 + rval_7, lval_8 + rval_8), verbose );

			mat = lmat;
			Assertv(mat.equals(lval_0, lval_1, lval_2, lval_3, lval_4, lval_5, lval_6, lval_7, lval_8), verbose);
			mat += rval_1;
			Assertv(mat.equals(lval_0 + rval_1, lval_1 + rval_1, lval_2 + rval_1, lval_3 + rval_1, lval_4 + rval_1, lval_5 + rval_1, lval_6 + rval_1, lval_7 + rval_1, lval_8 + rval_1), verbose);
		}
		{ // scalar subtraction
			const Mat3f lmat(lval_0, lval_1, lval_2, lval_3, lval_4, lval_5, lval_6, lval_7, lval_8);
			const Mat3f rmat(rval_0, rval_1, rval_2, rval_3, rval_4, rval_5, rval_6, rval_7, rval_8);
			Assertv(lmat.equals(lval_0, lval_1, lval_2, lval_3, lval_4, lval_5, lval_6, lval_7, lval_8), verbose);
			Assertv(rmat.equals(rval_0, rval_1, rval_2, rval_3, rval_4, rval_5, rval_6, rval_7, rval_8), verbose);
			Mat3f mat = lmat - rmat;
			Assertv(mat.equals(lval_0 - rval_0, lval_1 - rval_1, lval_2 - rval_2, lval_3 - rval_3, lval_4 - rval_4, lval_5 - rval_5, lval_6 - rval_6, lval_7 - rval_7, lval_8 - rval_8), verbose );
			
			mat = lmat - rval_0;
			Assertv(mat.equals(lval_0 - rval_0, lval_1 - rval_0, lval_2 - rval_0, lval_3 - rval_0, lval_4 - rval_0, lval_5 - rval_0, lval_6 - rval_0, lval_7 - rval_0, lval_8 - rval_0), verbose );

			mat = lmat;
			Assertv(mat.equals(lval_0, lval_1, lval_2, lval_3, lval_4, lval_5, lval_6, lval_7, lval_8), verbose);
			mat -= rmat;
			Assertv(mat.equals(lval_0 - rval_0, lval_1 - rval_1, lval_2 - rval_2, lval_3 - rval_3, lval_4 - rval_4, lval_5 - rval_5, lval_6 - rval_6, lval_7 - rval_7, lval_8 - rval_8), verbose );

			mat = lmat;
			Assertv(mat.equals(lval_0, lval_1, lval_2, lval_3, lval_4, lval_5, lval_6, lval_7, lval_8), verbose);
			mat -= rval_1;
			Assertv(mat.equals(lval_0 - rval_1, lval_1 - rval_1, lval_2 - rval_1, lval_3 - rval_1, lval_4 - rval_1, lval_5 - rval_1, lval_6 - rval_1, lval_7 - rval_1, lval_8 - rval_1), verbose);
		}
		{ // scalar multiplication
			const Mat3f lmat(lval_0, lval_1, lval_2, lval_3, lval_4, lval_5, lval_6, lval_7, lval_8);
			const Mat3f rmat(rval_0, rval_1, rval_2, rval_3, rval_4, rval_5, rval_6, rval_7, rval_8);
			Assertv(lmat.equals(lval_0, lval_1, lval_2, lval_3, lval_4, lval_5, lval_6, lval_7, lval_8), verbose);
			Assertv(rmat.equals(rval_0, rval_1, rval_2, rval_3, rval_4, rval_5, rval_6, rval_7, rval_8), verbose);
			Mat3f mat = lmat.scMul(rmat);
			Assertv(mat.equals(lval_0 * rval_0, lval_1 * rval_1, lval_2 * rval_2, lval_3 * rval_3, lval_4 * rval_4, lval_5 * rval_5, lval_6 * rval_6, lval_7 * rval_7, lval_8 * rval_8), verbose );
			
			mat = lmat * rval_0;
			Assertv(mat.equals(lval_0 * rval_0, lval_1 * rval_0, lval_2 * rval_0, lval_3 * rval_0, lval_4 * rval_0, lval_5 * rval_0, lval_6 * rval_0, lval_7 * rval_0, lval_8 * rval_0), verbose );

			mat = lmat;
			Assertv(mat.equals(lval_0, lval_1, lval_2, lval_3, lval_4, lval_5, lval_6, lval_7, lval_8), verbose);
			mat = mat.scMul(rmat);
			Assertv(mat.equals(lval_0 * rval_0, lval_1 * rval_1, lval_2 * rval_2, lval_3 * rval_3, lval_4 * rval_4, lval_5 * rval_5, lval_6 * rval_6, lval_7 * rval_7, lval_8 * rval_8), verbose );

			mat = lmat;
			Assertv(mat.equals(lval_0, lval_1, lval_2, lval_3, lval_4, lval_5, lval_6, lval_7, lval_8), verbose);
			mat *= rval_1;
			Assertv(mat.equals(lval_0 * rval_1, lval_1 * rval_1, lval_2 * rval_1, lval_3 * rval_1, lval_4 * rval_1, lval_5 * rval_1, lval_6 * rval_1, lval_7 * rval_1, lval_8 * rval_1), verbose);
		}
		{ // scalar division
			const Mat3f lmat(lval_0, lval_1, lval_2, lval_3, lval_4, lval_5, lval_6, lval_7, lval_8);
			const Mat3f rmat(rval_0, rval_1, rval_2, rval_3, rval_4, rval_5, rval_6, rval_7, rval_8);
			Assertv(lmat.equals(lval_0, lval_1, lval_2, lval_3, lval_4, lval_5, lval_6, lval_7, lval_8), verbose);
			Assertv(rmat.equals(rval_0, rval_1, rval_2, rval_3, rval_4, rval_5, rval_6, rval_7, rval_8), verbose);
			Mat3f mat = lmat.scDiv(rmat);
			Assertv(mat.equals(lval_0 / rval_0, lval_1 / rval_1, lval_2 / rval_2, lval_3 / rval_3, lval_4 / rval_4, lval_5 / rval_5, lval_6 / rval_6, lval_7 / rval_7, lval_8 / rval_8), verbose );
			
			mat = lmat / rval_0;
			Assertv(mat.equals(lval_0 / rval_0, lval_1 / rval_0, lval_2 / rval_0, lval_3 / rval_0, lval_4 / rval_0, lval_5 / rval_0, lval_6 / rval_0, lval_7 / rval_0, lval_8 / rval_0), verbose );

			mat = lmat;
			Assertv(mat.equals(lval_0, lval_1, lval_2, lval_3, lval_4, lval_5, lval_6, lval_7, lval_8), verbose);
			mat = mat.scDiv(rmat);
			Assertv(mat.equals(lval_0 / rval_0, lval_1 / rval_1, lval_2 / rval_2, lval_3 / rval_3, lval_4 / rval_4, lval_5 / rval_5, lval_6 / rval_6, lval_7 / rval_7, lval_8 / rval_8), verbose );

			mat = lmat;
			Assertv(mat.equals(lval_0, lval_1, lval_2, lval_3, lval_4, lval_5, lval_6, lval_7, lval_8), verbose);
			mat /= rval_1;
			Assertv(mat.equals(lval_0 / rval_1, lval_1 / rval_1, lval_2 / rval_1, lval_3 / rval_1, lval_4 / rval_1, lval_5 / rval_1, lval_6 / rval_1, lval_7 / rval_1, lval_8 / rval_1), verbose);
		}
		{ // matrix multiplication
			const Mat3f lmat(lval_0, lval_1, lval_2, lval_3, lval_4, lval_5, lval_6, lval_7, lval_8);
			const Mat3f rmat(rval_0, rval_1, rval_2, rval_3, rval_4, rval_5, rval_6, rval_7, rval_8);
			Assertv(lmat.equals(lval_0, lval_1, lval_2, lval_3, lval_4, lval_5, lval_6, lval_7, lval_8), verbose);
			Assertv(rmat.equals(rval_0, rval_1, rval_2, rval_3, rval_4, rval_5, rval_6, rval_7, rval_8), verbose);
			const Mat3f pmat = lmat * rmat;
			Assertv(pmat.equals(
				lval_0*rval_0+lval_3*rval_1+lval_6*rval_2,
				lval_1*rval_0+lval_4*rval_1+lval_7*rval_2,
				lval_2*rval_0+lval_5*rval_1+lval_8*rval_2,
				lval_0*rval_3+lval_3*rval_4+lval_6*rval_5,
				lval_1*rval_3+lval_4*rval_4+lval_7*rval_5,
				lval_2*rval_3+lval_5*rval_4+lval_8*rval_5,
				lval_0*rval_6+lval_3*rval_7+lval_6*rval_8,
				lval_1*rval_6+lval_4*rval_7+lval_7*rval_8,
				lval_2*rval_6+lval_5*rval_7+lval_8*rval_8
			), verbose);
			const Mat3f p2mat = rmat * lmat;
			Assertv(p2mat.equals(
				rval_0*lval_0+rval_3*lval_1+rval_6*lval_2,
				rval_1*lval_0+rval_4*lval_1+rval_7*lval_2,
				rval_2*lval_0+rval_5*lval_1+rval_8*lval_2,
				rval_0*lval_3+rval_3*lval_4+rval_6*lval_5,
				rval_1*lval_3+rval_4*lval_4+rval_7*lval_5,
				rval_2*lval_3+rval_5*lval_4+rval_8*lval_5,
				rval_0*lval_6+rval_3*lval_7+rval_6*lval_8,
				rval_1*lval_6+rval_4*lval_7+rval_7*lval_8,
				rval_2*lval_6+rval_5*lval_7+rval_8*lval_8
			), verbose);
		}
		{ // matrix division
			const Mat3f lmat(lval_0, lval_1, lval_2, lval_3, lval_4, lval_5, lval_6, lval_7, lval_8);
			const Mat3f rmat(rval_0, rval_1, rval_2, rval_3, rval_4, rval_5, rval_6, rval_7, rval_8);
			Assertv(lmat.equals(lval_0, lval_1, lval_2, lval_3, lval_4, lval_5, lval_6, lval_7, lval_8), verbose);
			Assertv(rmat.equals(rval_0, rval_1, rval_2, rval_3, rval_4, rval_5, rval_6, rval_7, rval_8), verbose);
			const Mat3f mat = lmat / rmat;
			const Mat3f rimat = rmat.inverse();
			const float ival_0 = rimat.values[0], ival_1 = rimat.values[1], ival_2 = rimat.values[2], ival_3 = rimat.values[3], ival_4 = rimat.values[4], ival_5 = rimat.values[5], ival_6 = rimat.values[6], ival_7 = rimat.values[7], ival_8 = rimat.values[8];
			Assertv(mat.equals(
				lval_0*ival_0+lval_3*ival_1+lval_6*ival_2,
				lval_1*ival_0+lval_4*ival_1+lval_7*ival_2,
				lval_2*ival_0+lval_5*ival_1+lval_8*ival_2,
				lval_0*ival_3+lval_3*ival_4+lval_6*ival_5,
				lval_1*ival_3+lval_4*ival_4+lval_7*ival_5,
				lval_2*ival_3+lval_5*ival_4+lval_8*ival_5,
				lval_0*ival_6+lval_3*ival_7+lval_6*ival_8,
				lval_1*ival_6+lval_4*ival_7+lval_7*ival_8,
				lval_2*ival_6+lval_5*ival_7+lval_8*ival_8
			), verbose);
		}
		{ // matrix - vector multiplication
			const Mat3f mat(3.0f, 1.344f, 0.44f, 12220.5f, 45.67f, 0.5f, 1.2f, 3.333f, 1.09f);
			const Vec3f vec(3.4f, 0.455f, 9.55f);
			const Vec3f pvec = mat * vec;
			Assertv(pvec.equals(
				mat.at(0,0) * vec.x + mat.at(1,0) * vec.y + mat.at(2,0) * vec.z,
				mat.at(0,1) * vec.x + mat.at(1,1) * vec.y + mat.at(2,1) * vec.z,
				mat.at(0,2) * vec.x + mat.at(1,2) * vec.y + mat.at(2,2) * vec.z
			), verbose);
		}
	}
	{ // at
		{
			const Mat3f mat(3.0f, 1.344f, 0.44f, 12220.5f, 45.67f, 0.5f, 1.2f, 3.333f, 1.09f);
			Assertv(Float::equals(mat.at(0, 0), 3.0f, 0.0001f), verbose);
			Assertv(Float::equals(mat.at(0, 1), 1.344f, 0.0001f), verbose);
			Assertv(Float::equals(mat.at(0, 2), 0.44f, 0.0001f), verbose);
			Assertv(Float::equals(mat.at(1, 0), 12220.5f, 0.0001f), verbose);
			Assertv(Float::equals(mat.at(1, 1), 45.67f, 0.0001f), verbose);
			Assertv(Float::equals(mat.at(1, 2), 0.5f, 0.0001f), verbose);
			Assertv(Float::equals(mat.at(2, 0), 1.2f, 0.0001f), verbose);
			Assertv(Float::equals(mat.at(2, 1), 3.333f, 0.0001f), verbose);
			Assertv(Float::equals(mat.at(2, 2), 1.09f, 0.0001f), verbose);
		}
		{
			Mat3f::Default = Mat3f::Identity;
			Mat3f mat;
			Assertv(mat.equals(Mat3f::Identity), verbose);
			Assertv(Float::equals((mat.at(0, 0) = 3.0f), 3.0f, 0.0001f), verbose);
			Assertv(Float::equals((mat.at(0, 1) = 1.344f), 1.344f, 0.0001f), verbose);
			Assertv(Float::equals((mat.at(0, 2) = 0.44f), 0.44f, 0.0001f), verbose);
			Assertv(Float::equals((mat.at(1, 0) = 12220.5f), 12220.5f, 0.0001f), verbose);
			Assertv(Float::equals((mat.at(1, 1) = 45.67f), 45.67f, 0.0001f), verbose);
			Assertv(Float::equals((mat.at(1, 2) = 0.5f), 0.5f, 0.0001f), verbose);
			Assertv(Float::equals((mat.at(2, 0) = 1.2f), 1.2f, 0.0001f), verbose);
			Assertv(Float::equals((mat.at(2, 1) = 3.333f), 3.333f, 0.0001f), verbose);
			Assertv(Float::equals((mat.at(2, 2) = 1.09f), 1.09f, 0.0001f), verbose);
			Assertv(mat.equals(3.0f, 1.344f, 0.44f, 12220.5f, 45.67f, 0.5f, 1.2f, 3.333f, 1.09f), verbose);
		}
	}
	{ // set values
		Mat3f mat(0);
		Assertv(mat.equals(Mat3f::Zero), verbose);
		Assertv(&mat == &(mat.set(3.0f, 1.344f, 0.44f, 12220.5f, 45.67f, 0.5f, 1.2f, 3.333f, 1.09f)), verbose);
		Assertv(Float::equals(mat.at(0, 0), 3.0f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(0, 1), 1.344f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(0, 2), 0.44f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(1, 0), 12220.5f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(1, 1), 45.67f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(1, 2), 0.5f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(2, 0), 1.2f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(2, 1), 3.333f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(2, 2), 1.09f, 0.0001f), verbose);
	}
	{ // set from array
		Mat3f mat(0);
		Assertv(mat.equals(Mat3f::Zero), verbose);
		const float pv[] = {3.0f, 1.344f, 0.44f, 12220.5f, 45.67f, 0.5f, 1.2f, 3.333f, 1.09f};
		Assertv(&mat == &(mat.set(pv)), verbose);
		Assertv(Float::equals(mat.at(0, 0), 3.0f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(0, 1), 1.344f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(0, 2), 0.44f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(1, 0), 12220.5f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(1, 1), 45.67f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(1, 2), 0.5f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(2, 0), 1.2f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(2, 1), 3.333f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(2, 2), 1.09f, 0.0001f), verbose);
	}
	{ // setValue
		Mat3f mat(0);
		Assertv(mat.equals(Mat3f::Zero), verbose);
		mat.setValue(0, 0, 3.0f);
		Assertv(Float::equals(mat.at(0, 0), 3.0f, 0.0001f), verbose);
		mat.setValue(0, 1, 1.344f);
		Assertv(Float::equals(mat.at(0, 1), 1.344f, 0.0001f), verbose);
		mat.setValue(0, 2, 5.4f);
		Assertv(Float::equals(mat.at(0, 2), 5.4f, 0.0001f), verbose);
		mat.setValue(1, 0, 0.44f);
		Assertv(Float::equals(mat.at(1, 0), 0.44f, 0.0001f), verbose);
		mat.setValue(1, 1, 9.56f);
		Assertv(Float::equals(mat.at(1, 1), 9.56f, 0.0001f), verbose);
		mat.setValue(1, 2, 10.05f);
		Assertv(Float::equals(mat.at(1, 2), 10.05f, 0.0001f), verbose);
		mat.setValue(2, 0, 6.666f);
		Assertv(Float::equals(mat.at(2, 0), 6.666f, 0.0001f), verbose);
		mat.setValue(2, 1, 34.56f);
		Assertv(Float::equals(mat.at(2, 1), 34.56f, 0.0001f), verbose);
		mat.setValue(2, 2, 12220.5f);
		Assertv(Float::equals(mat.at(0, 0), 3.0f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(0, 1), 1.344f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(0, 2), 5.4f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(1, 0), 0.44f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(1, 1), 9.56f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(1, 2), 10.05f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(2, 0), 6.666f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(2, 1), 34.56f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(2, 2), 12220.5f, 0.0001f), verbose);
	}
	{ // Nan
		{
			const Mat3f mat(0.0f, 2.0f, 1.0f, 34.4f, 45.67f, 0.5f, 1.2f, 3.333f, 1.09f);
			Assertv(mat.equals(0.0f, 2.0f, 1.0f, 34.4f, 45.67f, 0.5f, 1.2f, 3.333f, 1.09f), verbose);
			Assertv(!mat.isNan(), verbose);
			Assertv(mat.isNotNan(), verbose);
			Assertv(!mat.hasNan(), verbose);
			Assertv(mat.hasNoNan(), verbose);
		}
		{
			const Mat3f mat(0.0f, Float::Nan, 1.0f, 34.4f, 45.67f, 0.5f, 1.2f, 3.333f, 1.09f);
			Assertv(mat.equals(0.0f, Float::Nan, 1.0f, 34.4f, 45.67f, 0.5f, 1.2f, 3.333f, 1.09f), verbose);
			Assertv(!mat.isNan(), verbose);
			Assertv(mat.isNotNan(), verbose);
			Assertv(mat.hasNan(), verbose);
			Assertv(!mat.hasNoNan(), verbose);
		}
		{
			const Mat3f mat(Float::Nan, Float::Nan, Float::Nan, Float::PosInf, Float::Nan, Float::Nan, Float::Nan, Float::PosInf, Float::PosInf);
			Assertv(mat.equals(Float::Nan, Float::Nan, Float::Nan, Float::PosInf, Float::Nan, Float::Nan, Float::Nan, Float::PosInf, Float::PosInf), verbose);
			Assertv(!mat.isNan(), verbose);
			Assertv(mat.isNotNan(), verbose);
			Assertv(mat.hasNan(), verbose);
			Assertv(!mat.hasNoNan(), verbose);
		}
		{
			const Mat3f mat(Float::Nan, Float::Nan, Float::Nan, Float::Nan, Float::Nan, Float::Nan, Float::Nan, Float::Nan, Float::Nan);
			Assertv(mat.isNan(), verbose);
			Assertv(!mat.isNotNan(), verbose);
			Assertv(mat.hasNan(), verbose);
			Assertv(!mat.hasNoNan(), verbose);
		}
	}
	{ // determinant
		Assertv(Mat3f(2, 1, 2, 3, 1, 1, 4, 2, 0).determinant() == 4.0f, verbose);
		Assertv(Mat3f(1, 2, -1, 3, -1, 1, -29, -2, -3).determinant() == 0.0f, verbose);
	}
	{ // transpose
		Assertv(Mat3f(1,2,3,4,5,6,7,8,9).transpose().equals(1,4,7,2,5,8,3,6,9), verbose);
		Assertv(Mat3f(1,0,0,0,2,0,0,0,-3).transpose().equals(1,0,0,0,2,0,0,0,-3), verbose);
	}
	{ // inverse
		{ // identity
			const Mat3f mat(1.0f);
			const Mat3f imat = mat.inverse();
			Assertv(mat.isInvertible(), verbose);
			Assertv(imat.isInvertible(), verbose);
			Assertv(!imat.hasNan(), verbose);
			Assertv(!imat.isNan(), verbose);
			Assertv(mat.equals(Mat3f::Identity), verbose);
			Assertv(imat.equals(Mat3f::Identity), verbose);
			Assertv(mat.equals(imat), verbose);
			Assertv((mat*imat).equals(Mat3f::Identity), verbose);
		}
		{ // invertible values
			const Mat3f mat(2, 3, 2, 1, 2, 1, 1, 1, 2);
			const Mat3f imat = mat.inverse();
			Assertv(mat.isInvertible(), verbose);
			Assertv(imat.isInvertible(), verbose);
			Assertv(!imat.hasNan(), verbose);
			Assertv(!imat.isNan(), verbose);
			Mat3f pmat = mat*imat;
			Assertv(pmat.equals(Mat3f::Identity, 0.01f), verbose);
		}
		{ // non-invertible matrix values
			const Mat3f mat(1, 2, -1, 3, -1, 1, -29, -2, -3);
			Assertv(mat.determinant() == 0.0f, verbose);
			const Mat3f imat = mat.inverse();
			Assertv(!mat.isInvertible(), verbose);
			Assertv(!imat.isInvertible(), verbose);
			Assertv(imat.hasNan(), verbose);
			Assertv(imat.isNan(), verbose);
			if(!imat.hasNan())
			{
				Assertv((mat*imat).equals(Mat3f::Identity), verbose);
			}
		}
		{ // non-invertible matrix values
			const Mat3f mat(4.0f, Float::Nan, 4.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f);
			const Mat3f imat = mat.inverse();
			Assertv(!mat.isInvertible(), verbose);
			Assertv(!imat.isInvertible(), verbose);
			Assertv(mat.hasNan(), verbose);
			Assertv(!mat.isNan(), verbose);
			Assertv(imat.hasNan(), verbose);
			Assertv(imat.isNan(), verbose);
			if(!imat.hasNan())
			{
				Assertv((mat*imat).equals(Mat3f::Identity), verbose);
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