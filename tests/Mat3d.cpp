#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include "Assert.hpp"
#include "lib.hpp"
#include <axl.math/Double.hpp>
#include <axl.math/Mat3d.hpp>
#include <axl.math/Mat3f.hpp>

int main(int argc, char *argv[])
{
	bool verbose = argc > 1 && (0 == strcmp(argv[1], "-v") || 0 == strcmp(argv[1], "--verbose"));
	using namespace axl;
	using namespace axl::math;
	printf("axl.math - version %hu.%hu.%hu  %s %s\n", lib::VERSION.major, lib::VERSION.minor, lib::VERSION.patch, libType(lib::LIBRARY_TYPE), buildType(lib::BUILD_TYPE));
	puts("----------------------------------------");
	{ // static values
		Assertv(Double::equals(0.0, Mat3d::Zero.values[0]), verbose);
		Assertv(Double::equals(0.0, Mat3d::Zero.values[1]), verbose);
		Assertv(Double::equals(0.0, Mat3d::Zero.values[2]), verbose);
		Assertv(Double::equals(0.0, Mat3d::Zero.values[3]), verbose);
		Assertv(Double::equals(0.0, Mat3d::Zero.values[4]), verbose);
		Assertv(Double::equals(0.0, Mat3d::Zero.values[5]), verbose);
		Assertv(Double::equals(0.0, Mat3d::Zero.values[6]), verbose);
		Assertv(Double::equals(0.0, Mat3d::Zero.values[7]), verbose);
		Assertv(Double::equals(0.0, Mat3d::Zero.values[8]), verbose);
		Assertv(Double::equals(1.0, Mat3d::Identity.values[0]), verbose);
		Assertv(Double::equals(0.0, Mat3d::Identity.values[1]), verbose);
		Assertv(Double::equals(0.0, Mat3d::Identity.values[2]), verbose);
		Assertv(Double::equals(0.0, Mat3d::Identity.values[3]), verbose);
		Assertv(Double::equals(1.0, Mat3d::Identity.values[4]), verbose);
		Assertv(Double::equals(0.0, Mat3d::Identity.values[5]), verbose);
		Assertv(Double::equals(0.0, Mat3d::Identity.values[6]), verbose);
		Assertv(Double::equals(0.0, Mat3d::Identity.values[7]), verbose);
		Assertv(Double::equals(1.0, Mat3d::Identity.values[8]), verbose);
		Assertv(Mat3d::filled(4.0).equals(4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0), verbose);
	}
	{ // constructors
		{ // default constructor
			const Mat3d mat;
			Assertv(Double::equals(0.0, mat.values[0]), verbose);
			Assertv(Double::equals(0.0, mat.values[1]), verbose);
			Assertv(Double::equals(0.0, mat.values[2]), verbose);
			Assertv(Double::equals(0.0, mat.values[3]), verbose);
			Assertv(Double::equals(0.0, mat.values[4]), verbose);
			Assertv(Double::equals(0.0, mat.values[5]), verbose);
			Assertv(Double::equals(0.0, mat.values[6]), verbose);
			Assertv(Double::equals(0.0, mat.values[7]), verbose);
			Assertv(Double::equals(0.0, mat.values[8]), verbose);
		}
		{ // value constructor
			const Mat3d mat(3.1415);
			Assertv(mat.equals(3.1415, 0.0, 0.0, 0.0, 3.1415, 0.0, 0.0, 0.0, 3.1415), verbose);
		}
		{ // values constructor
			const Mat3d mat(3.1415, 0.6734, 3.45, 0.44, 45.67, 0.5, 1.2, 3.333, 1.09);
			Assertv(mat.equals(3.1415, 0.6734, 3.45, 0.44, 45.67, 0.5, 1.2, 3.333, 1.09), verbose);
		}
		{ // copy constructor
			const Mat3d mat(3.1415, 0.6734, 3.45, 0.44, 45.67, 0.5, 1.2, 3.333, 1.09);
			Assertv(mat.equals(3.1415, 0.6734, 3.45, 0.44, 45.67, 0.5, 1.2, 3.333, 1.09), verbose);
			const Mat3d mat1(mat);
			Assertv(mat1.equals(3.1415, 0.6734, 3.45, 0.44, 45.67, 0.5, 1.2, 3.333, 1.09, 0.000001), verbose);
			const Mat3d mat2 = mat;
			Assertv(mat2.equals(3.1415, 0.6734, 3.45, 0.44, 45.67, 0.5, 1.2, 3.333, 1.09), verbose);
			Assertv(Mat3d(Mat3f(3.1415f, 0.6734f, 3.45f, 0.44f, 45.67f, 0.5f, 1.2f, 3.333f, 1.09f)).equals(3.1415, 0.6734, 3.45, 0.44, 45.67, 0.5, 1.2, 3.333, 1.09, 0.0001), verbose);
		}
	}
	{ // square bracket operators
		const Mat3d mat(3.1415, 0.6734, 3.45, 0.44, 45.67, 0.5, 1.2, 3.333, 1.09);
		Assertv(mat.equals(3.1415, 0.6734, 3.45, 0.44, 45.67, 0.5, 1.2, 3.333, 1.09), verbose);
	}
	{ // equality operators
		Assertv(Mat3d::Zero == 0.0, verbose);
		Assertv(Mat3d::filled(1.0) == 1.0, verbose);
		Assertv(Mat3d::Zero == Mat3d::Zero, verbose);
		Assertv(Mat3d::Identity == Mat3d::Identity, verbose);
		Assertv(!(Mat3d::Zero != 0.0), verbose);
		Assertv(!(Mat3d::filled(1.0) != 1.0), verbose);
		Assertv(!(Mat3d::Zero != Mat3d::Zero), verbose);
		Assertv(!(Mat3d::Identity != Mat3d::Identity), verbose);
		Mat3d mat(3.1415, 0.6734, 3.45, 0.44, 45.67, 0.5, 1.2, 3.333, 1.09), mat2(3.1415, 0.6734, 1.2345, 0.987654, 4.0, 5.0, 6.0, 7.0, 8.0);
		Assertv(mat.equals(3.1415, 0.6734, 3.45, 0.44, 45.67, 0.5, 1.2, 3.333, 1.09), verbose);
		Assertv(mat.equals(mat), verbose);
		Assertv(!mat.equals(3.1415), verbose);
		Assertv(!mat.equals(3.45), verbose);
		Assertv(!mat.equals(mat2), verbose);
		Assertv(!mat.notEquals(3.1415, 0.6734, 3.45, 0.44, 45.67, 0.5, 1.2, 3.333, 1.09), verbose);
		Assertv(!mat.notEquals(mat), verbose);
		Assertv(mat.notEquals(3.1415), verbose);
		Assertv(mat.notEquals(3.45), verbose);
		Assertv(mat.notEquals(mat2), verbose);
	}
	{ // arthimetic operators
		const double lval_0 = 12.344, lval_1 = 131.04, lval_2 = 0.4555, lval_3 = 23000.45, lval_4 = 45.67, lval_5 = 0.5, lval_6 = 1.2, lval_7 = 3.333, lval_8 = 1.09;
		const double rval_0 = 10023.54, rval_1 = 45.323, rval_2 = 1.233, rval_3 = 0.5, rval_4 = 145.67, rval_5 = 10.5, rval_6 = 11.2, rval_7 = 13.333, rval_8 = 11.09;
		{ // scalar addition
			const Mat3d lmat(lval_0, lval_1, lval_2, lval_3, lval_4, lval_5, lval_6, lval_7, lval_8);
			const Mat3d rmat(rval_0, rval_1, rval_2, rval_3, rval_4, rval_5, rval_6, rval_7, rval_8);
			Assertv(lmat.equals(lval_0, lval_1, lval_2, lval_3, lval_4, lval_5, lval_6, lval_7, lval_8), verbose);
			Assertv(rmat.equals(rval_0, rval_1, rval_2, rval_3, rval_4, rval_5, rval_6, rval_7, rval_8), verbose);
			Mat3d mat = lmat + rmat;
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
			const Mat3d lmat(lval_0, lval_1, lval_2, lval_3, lval_4, lval_5, lval_6, lval_7, lval_8);
			const Mat3d rmat(rval_0, rval_1, rval_2, rval_3, rval_4, rval_5, rval_6, rval_7, rval_8);
			Assertv(lmat.equals(lval_0, lval_1, lval_2, lval_3, lval_4, lval_5, lval_6, lval_7, lval_8), verbose);
			Assertv(rmat.equals(rval_0, rval_1, rval_2, rval_3, rval_4, rval_5, rval_6, rval_7, rval_8), verbose);
			Mat3d mat = lmat - rmat;
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
			const Mat3d lmat(lval_0, lval_1, lval_2, lval_3, lval_4, lval_5, lval_6, lval_7, lval_8);
			const Mat3d rmat(rval_0, rval_1, rval_2, rval_3, rval_4, rval_5, rval_6, rval_7, rval_8);
			Assertv(lmat.equals(lval_0, lval_1, lval_2, lval_3, lval_4, lval_5, lval_6, lval_7, lval_8), verbose);
			Assertv(rmat.equals(rval_0, rval_1, rval_2, rval_3, rval_4, rval_5, rval_6, rval_7, rval_8), verbose);
			Mat3d mat = lmat.scMul(rmat);
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
			const Mat3d lmat(lval_0, lval_1, lval_2, lval_3, lval_4, lval_5, lval_6, lval_7, lval_8);
			const Mat3d rmat(rval_0, rval_1, rval_2, rval_3, rval_4, rval_5, rval_6, rval_7, rval_8);
			Assertv(lmat.equals(lval_0, lval_1, lval_2, lval_3, lval_4, lval_5, lval_6, lval_7, lval_8), verbose);
			Assertv(rmat.equals(rval_0, rval_1, rval_2, rval_3, rval_4, rval_5, rval_6, rval_7, rval_8), verbose);
			Mat3d mat = lmat.scDiv(rmat);
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
			const Mat3d lmat(lval_0, lval_1, lval_2, lval_3, lval_4, lval_5, lval_6, lval_7, lval_8);
			const Mat3d rmat(rval_0, rval_1, rval_2, rval_3, rval_4, rval_5, rval_6, rval_7, rval_8);
			Assertv(lmat.equals(lval_0, lval_1, lval_2, lval_3, lval_4, lval_5, lval_6, lval_7, lval_8), verbose);
			Assertv(rmat.equals(rval_0, rval_1, rval_2, rval_3, rval_4, rval_5, rval_6, rval_7, rval_8), verbose);
			const Mat3d pmat = lmat * rmat;
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
			const Mat3d p2mat = rmat * lmat;
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
			const Mat3d lmat(lval_0, lval_1, lval_2, lval_3, lval_4, lval_5, lval_6, lval_7, lval_8);
			const Mat3d rmat(rval_0, rval_1, rval_2, rval_3, rval_4, rval_5, rval_6, rval_7, rval_8);
			Assertv(lmat.equals(lval_0, lval_1, lval_2, lval_3, lval_4, lval_5, lval_6, lval_7, lval_8), verbose);
			Assertv(rmat.equals(rval_0, rval_1, rval_2, rval_3, rval_4, rval_5, rval_6, rval_7, rval_8), verbose);
			const Mat3d mat = lmat / rmat;
			const Mat3d rimat = rmat.inverse();
			const double ival_0 = rimat.values[0], ival_1 = rimat.values[1], ival_2 = rimat.values[2], ival_3 = rimat.values[3], ival_4 = rimat.values[4], ival_5 = rimat.values[5], ival_6 = rimat.values[6], ival_7 = rimat.values[7], ival_8 = rimat.values[8];
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
			const Mat3d mat(3.0, 1.344, 0.44, 12220.5, 45.67, 0.5, 1.2, 3.333, 1.09);
			const Vec3f vec(3.4f, 0.455f, 9.55f);
			const Vec3f pvec = mat * vec;
			Assertv(pvec.equals(
				(float)(mat.at(0,0) * vec.x + mat.at(1,0) * vec.y + mat.at(2,0) * vec.z),
				(float)(mat.at(0,1) * vec.x + mat.at(1,1) * vec.y + mat.at(2,1) * vec.z),
				(float)(mat.at(0,2) * vec.x + mat.at(1,2) * vec.y + mat.at(2,2) * vec.z)
			), verbose);
		}
	}
	{ // at
		{
			const Mat3d mat(3.0, 1.344, 0.44, 12220.5, 45.67, 0.5, 1.2, 3.333, 1.09);
			Assertv(Double::equals(mat.at(0, 0), 3.0, 0.000001), verbose);
			Assertv(Double::equals(mat.at(0, 1), 1.344, 0.000001), verbose);
			Assertv(Double::equals(mat.at(0, 2), 0.44, 0.000001), verbose);
			Assertv(Double::equals(mat.at(1, 0), 12220.5, 0.000001), verbose);
			Assertv(Double::equals(mat.at(1, 1), 45.67, 0.000001), verbose);
			Assertv(Double::equals(mat.at(1, 2), 0.5, 0.000001), verbose);
			Assertv(Double::equals(mat.at(2, 0), 1.2, 0.000001), verbose);
			Assertv(Double::equals(mat.at(2, 1), 3.333, 0.000001), verbose);
			Assertv(Double::equals(mat.at(2, 2), 1.09, 0.000001), verbose);
		}
		{
			Mat3d::Default = Mat3d::Identity;
			Mat3d mat;
			Assertv(mat.equals(Mat3d::Identity), verbose);
			Assertv(Double::equals((mat.at(0, 0) = 3.0), 3.0, 0.000001), verbose);
			Assertv(Double::equals((mat.at(0, 1) = 1.344), 1.344, 0.000001), verbose);
			Assertv(Double::equals((mat.at(0, 2) = 0.44), 0.44, 0.000001), verbose);
			Assertv(Double::equals((mat.at(1, 0) = 12220.5), 12220.5, 0.000001), verbose);
			Assertv(Double::equals((mat.at(1, 1) = 45.67), 45.67, 0.000001), verbose);
			Assertv(Double::equals((mat.at(1, 2) = 0.5), 0.5, 0.000001), verbose);
			Assertv(Double::equals((mat.at(2, 0) = 1.2), 1.2, 0.000001), verbose);
			Assertv(Double::equals((mat.at(2, 1) = 3.333), 3.333, 0.000001), verbose);
			Assertv(Double::equals((mat.at(2, 2) = 1.09), 1.09, 0.000001), verbose);
			Assertv(mat.equals(3.0, 1.344, 0.44, 12220.5, 45.67, 0.5, 1.2, 3.333, 1.09), verbose);
		}
	}
	{ // set values
		Mat3d mat(0);
		Assertv(mat.equals(Mat3d::Zero), verbose);
		Assertv(&mat == &(mat.set(3.0, 1.344, 0.44, 12220.5, 45.67, 0.5, 1.2, 3.333, 1.09)), verbose);
		Assertv(Double::equals(mat.at(0, 0), 3.0, 0.000001), verbose);
		Assertv(Double::equals(mat.at(0, 1), 1.344, 0.000001), verbose);
		Assertv(Double::equals(mat.at(0, 2), 0.44, 0.000001), verbose);
		Assertv(Double::equals(mat.at(1, 0), 12220.5, 0.000001), verbose);
		Assertv(Double::equals(mat.at(1, 1), 45.67, 0.000001), verbose);
		Assertv(Double::equals(mat.at(1, 2), 0.5, 0.000001), verbose);
		Assertv(Double::equals(mat.at(2, 0), 1.2, 0.000001), verbose);
		Assertv(Double::equals(mat.at(2, 1), 3.333, 0.000001), verbose);
		Assertv(Double::equals(mat.at(2, 2), 1.09, 0.000001), verbose);
	}
	{ // set from array
		Mat3d mat(0);
		Assertv(mat.equals(Mat3d::Zero), verbose);
		const double pv[] = {3.0, 1.344, 0.44, 12220.5, 45.67, 0.5, 1.2, 3.333, 1.09};
		Assertv(&mat == &(mat.set(pv)), verbose);
		Assertv(Double::equals(mat.at(0, 0), 3.0, 0.000001), verbose);
		Assertv(Double::equals(mat.at(0, 1), 1.344, 0.000001), verbose);
		Assertv(Double::equals(mat.at(0, 2), 0.44, 0.000001), verbose);
		Assertv(Double::equals(mat.at(1, 0), 12220.5, 0.000001), verbose);
		Assertv(Double::equals(mat.at(1, 1), 45.67, 0.000001), verbose);
		Assertv(Double::equals(mat.at(1, 2), 0.5, 0.000001), verbose);
		Assertv(Double::equals(mat.at(2, 0), 1.2, 0.000001), verbose);
		Assertv(Double::equals(mat.at(2, 1), 3.333, 0.000001), verbose);
		Assertv(Double::equals(mat.at(2, 2), 1.09, 0.000001), verbose);
	}
	{ // setValue
		Mat3d mat(0);
		Assertv(mat.equals(Mat3d::Zero), verbose);
		mat.setValue(0, 0, 3.0);
		Assertv(Double::equals(mat.at(0, 0), 3.0, 0.000001), verbose);
		mat.setValue(0, 1, 1.344);
		Assertv(Double::equals(mat.at(0, 1), 1.344, 0.000001), verbose);
		mat.setValue(0, 2, 5.4);
		Assertv(Double::equals(mat.at(0, 2), 5.4, 0.000001), verbose);
		mat.setValue(1, 0, 0.44);
		Assertv(Double::equals(mat.at(1, 0), 0.44, 0.000001), verbose);
		mat.setValue(1, 1, 9.56);
		Assertv(Double::equals(mat.at(1, 1), 9.56, 0.000001), verbose);
		mat.setValue(1, 2, 10.05);
		Assertv(Double::equals(mat.at(1, 2), 10.05, 0.000001), verbose);
		mat.setValue(2, 0, 6.666);
		Assertv(Double::equals(mat.at(2, 0), 6.666, 0.000001), verbose);
		mat.setValue(2, 1, 34.56);
		Assertv(Double::equals(mat.at(2, 1), 34.56, 0.000001), verbose);
		mat.setValue(2, 2, 12220.5);
		Assertv(Double::equals(mat.at(0, 0), 3.0, 0.000001), verbose);
		Assertv(Double::equals(mat.at(0, 1), 1.344, 0.000001), verbose);
		Assertv(Double::equals(mat.at(0, 2), 5.4, 0.000001), verbose);
		Assertv(Double::equals(mat.at(1, 0), 0.44, 0.000001), verbose);
		Assertv(Double::equals(mat.at(1, 1), 9.56, 0.000001), verbose);
		Assertv(Double::equals(mat.at(1, 2), 10.05, 0.000001), verbose);
		Assertv(Double::equals(mat.at(2, 0), 6.666, 0.000001), verbose);
		Assertv(Double::equals(mat.at(2, 1), 34.56, 0.000001), verbose);
		Assertv(Double::equals(mat.at(2, 2), 12220.5, 0.000001), verbose);
	}
	{ // Nan
		{
			const Mat3d mat(0.0, 2.0, 1.0, 34.4, 45.67, 0.5, 1.2, 3.333, 1.09);
			Assertv(mat.equals(0.0, 2.0, 1.0, 34.4, 45.67, 0.5, 1.2, 3.333, 1.09), verbose);
			Assertv(!mat.isNan(), verbose);
			Assertv(mat.isNotNan(), verbose);
			Assertv(!mat.hasNan(), verbose);
			Assertv(mat.hasNoNan(), verbose);
		}
		{
			const Mat3d mat(0.0, Double::Nan, 1.0, 34.4, 45.67, 0.5, 1.2, 3.333, 1.09);
			Assertv(mat.equals(0.0, Double::Nan, 1.0, 34.4, 45.67, 0.5, 1.2, 3.333, 1.09), verbose);
			Assertv(!mat.isNan(), verbose);
			Assertv(mat.isNotNan(), verbose);
			Assertv(mat.hasNan(), verbose);
			Assertv(!mat.hasNoNan(), verbose);
		}
		{
			const Mat3d mat(Double::Nan, Double::Nan, Double::Nan, Double::PosInf, Double::Nan, Double::Nan, Double::Nan, Double::PosInf, Double::PosInf);
			Assertv(mat.equals(Double::Nan, Double::Nan, Double::Nan, Double::PosInf, Double::Nan, Double::Nan, Double::Nan, Double::PosInf, Double::PosInf), verbose);
			Assertv(!mat.isNan(), verbose);
			Assertv(mat.isNotNan(), verbose);
			Assertv(mat.hasNan(), verbose);
			Assertv(!mat.hasNoNan(), verbose);
		}
		{
			const Mat3d mat(Double::Nan, Double::Nan, Double::Nan, Double::Nan, Double::Nan, Double::Nan, Double::Nan, Double::Nan, Double::Nan);
			Assertv(mat.isNan(), verbose);
			Assertv(!mat.isNotNan(), verbose);
			Assertv(mat.hasNan(), verbose);
			Assertv(!mat.hasNoNan(), verbose);
		}
	}
	{ // determinant
		Assertv(Mat3d(2, 1, 2, 3, 1, 1, 4, 2, 0).determinant() == 4.0, verbose);
		Assertv(Mat3d(1, 2, -1, 3, -1, 1, -29, -2, -3).determinant() == 0.0, verbose);
	}
	{ // transpose
		Assertv(Mat3d(1,2,3,4,5,6,7,8,9).transpose().equals(1,4,7,2,5,8,3,6,9), verbose);
		Assertv(Mat3d(1,0,0,0,2,0,0,0,-3).transpose().equals(1,0,0,0,2,0,0,0,-3), verbose);
	}
	{ // inverse
		{ // identity
			const Mat3d mat(1.0);
			const Mat3d imat = mat.inverse();
			Assertv(mat.isInvertible(), verbose);
			Assertv(imat.isInvertible(), verbose);
			Assertv(!imat.hasNan(), verbose);
			Assertv(!imat.isNan(), verbose);
			Assertv(mat.equals(Mat3d::Identity), verbose);
			Assertv(imat.equals(Mat3d::Identity), verbose);
			Assertv(mat.equals(imat), verbose);
			Assertv((mat*imat).equals(Mat3d::Identity), verbose);
		}
		{ // invertible values
			const Mat3d mat(2, 3, 2, 1, 2, 1, 1, 1, 2);
			const Mat3d imat = mat.inverse();
			Assertv(mat.isInvertible(), verbose);
			Assertv(imat.isInvertible(), verbose);
			Assertv(!imat.hasNan(), verbose);
			Assertv(!imat.isNan(), verbose);
			Mat3d pmat = mat*imat;
			Assertv(pmat.equals(Mat3d::Identity, 0.01), verbose);
		}
		{ // non-invertible matrix values
			const Mat3d mat(1, 2, -1, 3, -1, 1, -29, -2, -3);
			Assertv(mat.determinant() == 0.0, verbose);
			const Mat3d imat = mat.inverse();
			Assertv(!mat.isInvertible(), verbose);
			Assertv(!imat.isInvertible(), verbose);
			Assertv(imat.hasNan(), verbose);
			Assertv(imat.isNan(), verbose);
			if(!imat.hasNan())
			{
				Assertv((mat*imat).equals(Mat3d::Identity), verbose);
			}
		}
		{ // non-invertible matrix values
			const Mat3d mat(4.0, Double::Nan, 4.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0);
			const Mat3d imat = mat.inverse();
			Assertv(!mat.isInvertible(), verbose);
			Assertv(!imat.isInvertible(), verbose);
			Assertv(mat.hasNan(), verbose);
			Assertv(!mat.isNan(), verbose);
			Assertv(imat.hasNan(), verbose);
			Assertv(imat.isNan(), verbose);
			if(!imat.hasNan())
			{
				Assertv((mat*imat).equals(Mat3d::Identity), verbose);
			}
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