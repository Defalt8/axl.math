#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include "../Assert.hpp"
#include "../lib.hpp"
#include <axl.math/double.hpp>
#include <axl.math/mat/Mat4f.hpp>
#include <axl.math/mat/Mat4d.hpp>

int main(int argc, char *argv[])
{
	bool verbose = argc > 1 && (0 == strcmp(argv[1], "-v") || 0 == strcmp(argv[1], "--verbose"));
	using namespace axl;
	using namespace axl::math;
	printf("axl.math - version %hu.%hu.%hu  %s %s\n", lib::VERSION.major, lib::VERSION.minor, lib::VERSION.patch, libType(lib::LIBRARY_TYPE), buildType(lib::BUILD_TYPE));
	puts("----------------------------------------");
	{ // static values
		Assertv(Double::equals(0.0, Mat4d::Zero.values[0]), verbose);
		Assertv(Double::equals(0.0, Mat4d::Zero.values[1]), verbose);
		Assertv(Double::equals(0.0, Mat4d::Zero.values[2]), verbose);
		Assertv(Double::equals(0.0, Mat4d::Zero.values[3]), verbose);
		Assertv(Double::equals(0.0, Mat4d::Zero.values[4]), verbose);
		Assertv(Double::equals(0.0, Mat4d::Zero.values[5]), verbose);
		Assertv(Double::equals(0.0, Mat4d::Zero.values[6]), verbose);
		Assertv(Double::equals(0.0, Mat4d::Zero.values[7]), verbose);
		Assertv(Double::equals(0.0, Mat4d::Zero.values[8]), verbose);
		Assertv(Double::equals(0.0, Mat4d::Zero.values[9]), verbose);
		Assertv(Double::equals(0.0, Mat4d::Zero.values[10]), verbose);
		Assertv(Double::equals(0.0, Mat4d::Zero.values[11]), verbose);
		Assertv(Double::equals(0.0, Mat4d::Zero.values[12]), verbose);
		Assertv(Double::equals(0.0, Mat4d::Zero.values[13]), verbose);
		Assertv(Double::equals(0.0, Mat4d::Zero.values[14]), verbose);
		Assertv(Double::equals(0.0, Mat4d::Zero.values[15]), verbose);
		Assertv(Double::equals(1.0, Mat4d::Identity.values[0]), verbose);
		Assertv(Double::equals(0.0, Mat4d::Identity.values[1]), verbose);
		Assertv(Double::equals(0.0, Mat4d::Identity.values[2]), verbose);
		Assertv(Double::equals(0.0, Mat4d::Identity.values[3]), verbose);
		Assertv(Double::equals(0.0, Mat4d::Identity.values[4]), verbose);
		Assertv(Double::equals(1.0, Mat4d::Identity.values[5]), verbose);
		Assertv(Double::equals(0.0, Mat4d::Identity.values[6]), verbose);
		Assertv(Double::equals(0.0, Mat4d::Identity.values[7]), verbose);
		Assertv(Double::equals(0.0, Mat4d::Identity.values[8]), verbose);
		Assertv(Double::equals(0.0, Mat4d::Identity.values[9]), verbose);
		Assertv(Double::equals(1.0, Mat4d::Identity.values[10]), verbose);
		Assertv(Double::equals(0.0, Mat4d::Identity.values[11]), verbose);
		Assertv(Double::equals(0.0, Mat4d::Identity.values[12]), verbose);
		Assertv(Double::equals(0.0, Mat4d::Identity.values[13]), verbose);
		Assertv(Double::equals(0.0, Mat4d::Identity.values[14]), verbose);
		Assertv(Double::equals(1.0, Mat4d::Identity.values[15]), verbose);
		Assertv(Mat4d::filled(4.0).equals(4.0,4.0,4.0,4.0,4.0,4.0,4.0,4.0,4.0,4.0,4.0,4.0,4.0,4.0,4.0,4.0), verbose);
	}
	{ // constructors
		{ // default constructor
			{
				const Mat4d mat;
				Assertv(Double::equals(0.0, mat.values[0]), verbose);
				Assertv(Double::equals(0.0, mat.values[1]), verbose);
				Assertv(Double::equals(0.0, mat.values[2]), verbose);
				Assertv(Double::equals(0.0, mat.values[3]), verbose);
				Assertv(Double::equals(0.0, mat.values[4]), verbose);
				Assertv(Double::equals(0.0, mat.values[5]), verbose);
				Assertv(Double::equals(0.0, mat.values[6]), verbose);
				Assertv(Double::equals(0.0, mat.values[7]), verbose);
				Assertv(Double::equals(0.0, mat.values[8]), verbose);
				Assertv(Double::equals(0.0, mat.values[9]), verbose);
				Assertv(Double::equals(0.0, mat.values[10]), verbose);
				Assertv(Double::equals(0.0, mat.values[11]), verbose);
				Assertv(Double::equals(0.0, mat.values[12]), verbose);
				Assertv(Double::equals(0.0, mat.values[13]), verbose);
				Assertv(Double::equals(0.0, mat.values[14]), verbose);
				Assertv(Double::equals(0.0, mat.values[15]), verbose);
			}
			{
				Mat4d::Default = Mat4d::Identity;
				const Mat4d mat;
				Assertv(Double::equals(1.0, mat.values[0]), verbose);
				Assertv(Double::equals(0.0, mat.values[1]), verbose);
				Assertv(Double::equals(0.0, mat.values[2]), verbose);
				Assertv(Double::equals(0.0, mat.values[3]), verbose);
				Assertv(Double::equals(0.0, mat.values[4]), verbose);
				Assertv(Double::equals(1.0, mat.values[5]), verbose);
				Assertv(Double::equals(0.0, mat.values[6]), verbose);
				Assertv(Double::equals(0.0, mat.values[7]), verbose);
				Assertv(Double::equals(0.0, mat.values[8]), verbose);
				Assertv(Double::equals(0.0, mat.values[9]), verbose);
				Assertv(Double::equals(1.0, mat.values[10]), verbose);
				Assertv(Double::equals(0.0, mat.values[11]), verbose);
				Assertv(Double::equals(0.0, mat.values[12]), verbose);
				Assertv(Double::equals(0.0, mat.values[13]), verbose);
				Assertv(Double::equals(0.0, mat.values[14]), verbose);
				Assertv(Double::equals(1.0, mat.values[15]), verbose);
			}
		}
		{ // value constructor
			const Mat4d mat(3.1415);
			Assertv(mat.equals(3.1415, 0.0, 0.0, 0.0, 0.0, 3.1415, 0.0, 0.0, 0.0, 0.0, 3.1415, 0.0, 0.0, 0.0, 0.0, 3.1415), verbose);
		}
		{ // values constructor
			const Mat4d mat(3.1415, 0.6734, 3.45, 0.44, 45.67, 0.5, 1.2, 3.333, 1.09, 12.9, 45.6, 76.77, 90.0, 55.5, 22.2, 33.3);
			Assertv(mat.equals(3.1415, 0.6734, 3.45, 0.44, 45.67, 0.5, 1.2, 3.333, 1.09, 12.9, 45.6, 76.77, 90.0, 55.5, 22.2, 33.3, 0.000001), verbose);
		}
		{ // copy constructor
			const Mat4d mat(3.1415, 0.6734, 3.45, 0.44, 45.67, 0.5, 1.2, 3.333, 1.09, 12.9, 45.6, 76.77, 90.0, 55.5, 22.2, 33.3);
			Assertv(mat.equals(3.1415, 0.6734, 3.45, 0.44, 45.67, 0.5, 1.2, 3.333, 1.09, 12.9, 45.6, 76.77, 90.0, 55.5, 22.2, 33.3, 0.000001), verbose);
			const Mat4d mat1(mat);
			Assertv(mat1.equals(3.1415, 0.6734, 3.45, 0.44, 45.67, 0.5, 1.2, 3.333, 1.09, 12.9, 45.6, 76.77, 90.0, 55.5, 22.2, 33.3, 0.000001), verbose);
			const Mat4d mat2 = mat;
			Assertv(mat2.equals(3.1415, 0.6734, 3.45, 0.44, 45.67, 0.5, 1.2, 3.333, 1.09, 12.9, 45.6, 76.77, 90.0, 55.5, 22.2, 33.3, 0.000001), verbose);
			Assertv(Mat4d(Mat4f(3.1415f, 0.6734f, 3.45f, 0.44f, 45.67f, 0.5f, 1.2f, 3.333f, 1.09f, 12.9f, 45.6f, 76.77f, 90.0f, 55.5f, 22.2f, 33.3f)).equals(3.1415, 0.6734, 3.45, 0.44, 45.67, 0.5, 1.2, 3.333, 1.09, 12.9, 45.6, 76.77, 90.0, 55.5, 22.2, 33.3, 0.0001), verbose);
		}
	}
	{ // square bracket operators
		const Mat4d mat(3.1415, 0.6734, 3.45, 0.44, 45.67, 0.5, 1.2, 3.333, 1.09, 12.9, 45.6, 76.77, 90.0, 55.5, 22.2, 33.3);
		Assertv(Double::equals(mat[0][0], 3.1415, 0.000001), verbose);
		Assertv(Double::equals(mat[0][1], 0.6734, 0.000001), verbose); 
		Assertv(Double::equals(mat[0][2], 3.45, 0.000001), verbose);
		Assertv(Double::equals(mat[0][3], 0.44, 0.000001), verbose);
		Assertv(Double::equals(mat[1][0], 45.67, 0.000001), verbose);
		Assertv(Double::equals(mat[1][1], 0.5, 0.000001), verbose);
		Assertv(Double::equals(mat[1][2], 1.2, 0.000001), verbose);
		Assertv(Double::equals(mat[1][3], 3.333, 0.000001), verbose);
		Assertv(Double::equals(mat[2][0], 1.09, 0.000001), verbose);
		Assertv(Double::equals(mat[2][1], 12.9, 0.000001), verbose);
		Assertv(Double::equals(mat[2][2], 45.6, 0.000001), verbose);
		Assertv(Double::equals(mat[2][3], 76.77, 0.000001), verbose);
		Assertv(Double::equals(mat[3][0], 90.0, 0.000001), verbose);
		Assertv(Double::equals(mat[3][1], 55.5, 0.000001), verbose);
		Assertv(Double::equals(mat[3][2], 22.2, 0.000001), verbose);
		Assertv(Double::equals(mat[3][3], 33.3, 0.000001), verbose);
	}
	{ // equality operators
		Assertv(Mat4d::Zero == 0.0, verbose);
		Assertv(Mat4d::filled(1.0) == 1.0, verbose);
		Assertv(Mat4d::Zero == Mat4d::Zero, verbose);
		Assertv(Mat4d::Identity == Mat4d::Identity, verbose);
		Assertv(!(Mat4d::Zero != 0.0), verbose);
		Assertv(!(Mat4d::filled(1.0) != 1.0), verbose);
		Assertv(!(Mat4d::Zero != Mat4d::Zero), verbose);
		Assertv(!(Mat4d::Identity != Mat4d::Identity), verbose);
		Mat4d mat(3.1415, 0.6734, 3.45, 0.44, 45.67, 0.5, 1.2, 3.333, 1.09, 12.9, 45.6, 76.77, 90.0, 55.5, 22.2, 33.3), mat2(3.1415, 0.6734, 1.2345, 0.987654, 4.0, 5.0, 12.9, 45.6, 76.77, 90.0, 55.5, 22.2, 33.3, 6.0, 7.0, 8.0);
		Assertv(mat.equals(3.1415, 0.6734, 3.45, 0.44, 45.67, 0.5, 1.2, 3.333, 1.09, 12.9, 45.6, 76.77, 90.0, 55.5, 22.2, 33.3), verbose);
		Assertv(mat.equals(mat), verbose);
		Assertv(!mat.equals(3.1415), verbose);
		Assertv(!mat.equals(3.45), verbose);
		Assertv(!mat.equals(mat2), verbose);
		Assertv(!mat.notEquals(3.1415, 0.6734, 3.45, 0.44, 45.67, 0.5, 1.2, 3.333, 1.09, 12.9, 45.6, 76.77, 90.0, 55.5, 22.2, 33.3), verbose);
		Assertv(!mat.notEquals(mat), verbose);
		Assertv(mat.notEquals(3.1415), verbose);
		Assertv(mat.notEquals(3.45), verbose);
		Assertv(mat.notEquals(mat2), verbose);
	}
	{ // arthimetic operators
		const double lval_0 = 12.344, lval_1 = 131.04, lval_2 = 0.4555, lval_3 = 23000.45, lval_4 = 45.67, lval_5 = 0.5, lval_6 = 1.2, lval_7 = 3.333, lval_8 = 1.09, lval_9 = 12.9, lval_10 = 45.6, lval_11 = 76.77, lval_12 = 90.0, lval_13 = 55.5, lval_14 = 22.2, lval_15 = 33.3;
		const double rval_0 = 10023.54, rval_1 = 45.323, rval_2 = 1.233, rval_3 = 0.5, rval_4 = 145.67, rval_5 = 10.5, rval_6 = 11.2, rval_7 = 13.333, rval_8 = 11.09, rval_9 = 31.49, rval_10 = 34.46, rval_11 = 37.477, rval_12 = 39.40, rval_13 = 35.45, rval_14 = 32.42, rval_15 = 33.43;
		{ // scalar addition
			const Mat4d lmat(lval_0, lval_1, lval_2, lval_3, lval_4, lval_5, lval_6, lval_7, lval_8, lval_9, lval_10, lval_11, lval_12, lval_13, lval_14, lval_15);
			const Mat4d rmat(rval_0, rval_1, rval_2, rval_3, rval_4, rval_5, rval_6, rval_7, rval_8, rval_9, rval_10, rval_11, rval_12, rval_13, rval_14, rval_15);
			Mat4d mat = lmat + rmat;
			Assertv(mat.equals(lval_0 + rval_0, lval_1 + rval_1, lval_2 + rval_2, lval_3 + rval_3, lval_4 + rval_4, lval_5 + rval_5, lval_6 + rval_6, lval_7 + rval_7, lval_8 + rval_8, lval_9 + rval_9, lval_10 + rval_10, lval_11 + rval_11, lval_12 + rval_12, lval_13 + rval_13, lval_14 + rval_14, lval_15 + rval_15), verbose );
			mat = lmat + rval_0;
			Assertv(mat.equals(lval_0 + rval_0, lval_1 + rval_0, lval_2 + rval_0, lval_3 + rval_0, lval_4 + rval_0, lval_5 + rval_0, lval_6 + rval_0, lval_7 + rval_0, lval_8 + rval_0, lval_9 + rval_0, lval_10 + rval_0, lval_11 + rval_0, lval_12 + rval_0, lval_13 + rval_0, lval_14 + rval_0, lval_15 + rval_0), verbose );
			mat = lmat;
			mat += rmat;
			Assertv(mat.equals(lval_0 + rval_0, lval_1 + rval_1, lval_2 + rval_2, lval_3 + rval_3, lval_4 + rval_4, lval_5 + rval_5, lval_6 + rval_6, lval_7 + rval_7, lval_8 + rval_8, lval_9 + rval_9, lval_10 + rval_10, lval_11 + rval_11, lval_12 + rval_12, lval_13 + rval_13, lval_14 + rval_14, lval_15 + rval_15), verbose );
			mat = lmat;
			mat += rval_1;
			Assertv(mat.equals(lval_0 + rval_1, lval_1 + rval_1, lval_2 + rval_1, lval_3 + rval_1, lval_4 + rval_1, lval_5 + rval_1, lval_6 + rval_1, lval_7 + rval_1, lval_8 + rval_1, lval_9 + rval_1, lval_10 + rval_1, lval_11 + rval_1, lval_12 + rval_1, lval_13 + rval_1, lval_14 + rval_1, lval_15 + rval_1), verbose);
		}
		{ // scalar subtraction
			const Mat4d lmat(lval_0, lval_1, lval_2, lval_3, lval_4, lval_5, lval_6, lval_7, lval_8, lval_9, lval_10, lval_11, lval_12, lval_13, lval_14, lval_15);
			const Mat4d rmat(rval_0, rval_1, rval_2, rval_3, rval_4, rval_5, rval_6, rval_7, rval_8, rval_9, rval_10, rval_11, rval_12, rval_13, rval_14, rval_15);
			Mat4d mat = lmat - rmat;
			Assertv(mat.equals(lval_0 - rval_0, lval_1 - rval_1, lval_2 - rval_2, lval_3 - rval_3, lval_4 - rval_4, lval_5 - rval_5, lval_6 - rval_6, lval_7 - rval_7, lval_8 - rval_8, lval_9 - rval_9, lval_10 - rval_10, lval_11 - rval_11, lval_12 - rval_12, lval_13 - rval_13, lval_14 - rval_14, lval_15 - rval_15), verbose );
			mat = lmat - rval_0;
			Assertv(mat.equals(lval_0 - rval_0, lval_1 - rval_0, lval_2 - rval_0, lval_3 - rval_0, lval_4 - rval_0, lval_5 - rval_0, lval_6 - rval_0, lval_7 - rval_0, lval_8 - rval_0, lval_9 - rval_0, lval_10 - rval_0, lval_11 - rval_0, lval_12 - rval_0, lval_13 - rval_0, lval_14 - rval_0, lval_15 - rval_0), verbose );
			mat = lmat;
			mat -= rmat;
			Assertv(mat.equals(lval_0 - rval_0, lval_1 - rval_1, lval_2 - rval_2, lval_3 - rval_3, lval_4 - rval_4, lval_5 - rval_5, lval_6 - rval_6, lval_7 - rval_7, lval_8 - rval_8, lval_9 - rval_9, lval_10 - rval_10, lval_11 - rval_11, lval_12 - rval_12, lval_13 - rval_13, lval_14 - rval_14, lval_15 - rval_15), verbose );
			mat = lmat;
			mat -= rval_1;
			Assertv(mat.equals(lval_0 - rval_1, lval_1 - rval_1, lval_2 - rval_1, lval_3 - rval_1, lval_4 - rval_1, lval_5 - rval_1, lval_6 - rval_1, lval_7 - rval_1, lval_8 - rval_1, lval_9 - rval_1, lval_10 - rval_1, lval_11 - rval_1, lval_12 - rval_1, lval_13 - rval_1, lval_14 - rval_1, lval_15 - rval_1), verbose);
		}
		{ // scalar multiplication
			const Mat4d lmat(lval_0, lval_1, lval_2, lval_3, lval_4, lval_5, lval_6, lval_7, lval_8, lval_9, lval_10, lval_11, lval_12, lval_13, lval_14, lval_15);
			const Mat4d rmat(rval_0, rval_1, rval_2, rval_3, rval_4, rval_5, rval_6, rval_7, rval_8, rval_9, rval_10, rval_11, rval_12, rval_13, rval_14, rval_15);
			Mat4d mat = lmat.scMul(rmat);
			Assertv(mat.equals(lval_0 * rval_0, lval_1 * rval_1, lval_2 * rval_2, lval_3 * rval_3, lval_4 * rval_4, lval_5 * rval_5, lval_6 * rval_6, lval_7 * rval_7, lval_8 * rval_8, lval_9 * rval_9, lval_10 * rval_10, lval_11 * rval_11, lval_12 * rval_12, lval_13 * rval_13, lval_14 * rval_14, lval_15 * rval_15), verbose );
			mat = lmat * rval_0;
			Assertv(mat.equals(lval_0 * rval_0, lval_1 * rval_0, lval_2 * rval_0, lval_3 * rval_0, lval_4 * rval_0, lval_5 * rval_0, lval_6 * rval_0, lval_7 * rval_0, lval_8 * rval_0, lval_9 * rval_0, lval_10 * rval_0, lval_11 * rval_0, lval_12 * rval_0, lval_13 * rval_0, lval_14 * rval_0, lval_15 * rval_0), verbose );
			mat = lmat;
			mat *= rval_1;
			Assertv(mat.equals(lval_0 * rval_1, lval_1 * rval_1, lval_2 * rval_1, lval_3 * rval_1, lval_4 * rval_1, lval_5 * rval_1, lval_6 * rval_1, lval_7 * rval_1, lval_8 * rval_1, lval_9 * rval_1, lval_10 * rval_1, lval_11 * rval_1, lval_12 * rval_1, lval_13 * rval_1, lval_14 * rval_1, lval_15 * rval_1), verbose);
		}
		{ // scalar division
			const Mat4d lmat(lval_0, lval_1, lval_2, lval_3, lval_4, lval_5, lval_6, lval_7, lval_8, lval_9, lval_10, lval_11, lval_12, lval_13, lval_14, lval_15);
			const Mat4d rmat(rval_0, rval_1, rval_2, rval_3, rval_4, rval_5, rval_6, rval_7, rval_8, rval_9, rval_10, rval_11, rval_12, rval_13, rval_14, rval_15);
			Mat4d mat = lmat.scDiv(rmat);
			Assertv(mat.equals(lval_0 / rval_0, lval_1 / rval_1, lval_2 / rval_2, lval_3 / rval_3, lval_4 / rval_4, lval_5 / rval_5, lval_6 / rval_6, lval_7 / rval_7, lval_8 / rval_8, lval_9 / rval_9, lval_10 / rval_10, lval_11 / rval_11, lval_12 / rval_12, lval_13 / rval_13, lval_14 / rval_14, lval_15 / rval_15), verbose );
			mat = lmat / rval_0;
			Assertv(mat.equals(lval_0 / rval_0, lval_1 / rval_0, lval_2 / rval_0, lval_3 / rval_0, lval_4 / rval_0, lval_5 / rval_0, lval_6 / rval_0, lval_7 / rval_0, lval_8 / rval_0, lval_9 / rval_0, lval_10 / rval_0, lval_11 / rval_0, lval_12 / rval_0, lval_13 / rval_0, lval_14 / rval_0, lval_15 / rval_0), verbose );
			mat = lmat;
			mat /= rval_1;
			Assertv(mat.equals(lval_0 / rval_1, lval_1 / rval_1, lval_2 / rval_1, lval_3 / rval_1, lval_4 / rval_1, lval_5 / rval_1, lval_6 / rval_1, lval_7 / rval_1, lval_8 / rval_1, lval_9 / rval_1, lval_10 / rval_1, lval_11 / rval_1, lval_12 / rval_1, lval_13 / rval_1, lval_14 / rval_1, lval_15 / rval_1), verbose);
		}
		{ // matrix multiplication
			const Mat4d lmat(lval_0, lval_1, lval_2, lval_3, lval_4, lval_5, lval_6, lval_7, lval_8, lval_9, lval_10, lval_11, lval_12, lval_13, lval_14, lval_15);
			const Mat4d rmat(rval_0, rval_1, rval_2, rval_3, rval_4, rval_5, rval_6, rval_7, rval_8, rval_9, rval_10, rval_11, rval_12, rval_13, rval_14, rval_15);
			const Mat4d pmat = lmat * rmat;
			Assertv(pmat.equals(
				lval_0 * rval_0 + lval_4 * rval_1 + lval_8 * rval_2 + lval_12 * rval_3,
				lval_1 * rval_0 + lval_5 * rval_1 + lval_9 * rval_2 + lval_13 * rval_3,
				lval_2 * rval_0 + lval_6 * rval_1 + lval_10 * rval_2 + lval_14 * rval_3,
				lval_3 * rval_0 + lval_7 * rval_1 + lval_11 * rval_2 + lval_15 * rval_3,
				lval_0 * rval_4 + lval_4 * rval_5 + lval_8 * rval_6 + lval_12 * rval_7,
				lval_1 * rval_4 + lval_5 * rval_5 + lval_9 * rval_6 + lval_13 * rval_7,
				lval_2 * rval_4 + lval_6 * rval_5 + lval_10 * rval_6 + lval_14 * rval_7,
				lval_3 * rval_4 + lval_7 * rval_5 + lval_11 * rval_6 + lval_15 * rval_7,
				lval_0 * rval_8 + lval_4 * rval_9 + lval_8 * rval_10 + lval_12 * rval_11,
				lval_1 * rval_8 + lval_5 * rval_9 + lval_9 * rval_10 + lval_13 * rval_11,
				lval_2 * rval_8 + lval_6 * rval_9 + lval_10 * rval_10 + lval_14 * rval_11,
				lval_3 * rval_8 + lval_7 * rval_9 + lval_11 * rval_10 + lval_15 * rval_11,
				lval_0 * rval_12 + lval_4 * rval_13 + lval_8 * rval_14 + lval_12 * rval_15,
				lval_1 * rval_12 + lval_5 * rval_13 + lval_9 * rval_14 + lval_13 * rval_15,
				lval_2 * rval_12 + lval_6 * rval_13 + lval_10 * rval_14 + lval_14 * rval_15,
				lval_3 * rval_12 + lval_7 * rval_13 + lval_11 * rval_14 + lval_15 * rval_15,
				0.000001
			), verbose);
			const Mat4d p2mat = rmat * lmat;
			Assertv(p2mat.equals(
				rval_0 * lval_0 + rval_4 * lval_1 + rval_8 * lval_2 + rval_12 * lval_3,
				rval_1 * lval_0 + rval_5 * lval_1 + rval_9 * lval_2 + rval_13 * lval_3,
				rval_2 * lval_0 + rval_6 * lval_1 + rval_10 * lval_2 + rval_14 * lval_3,
				rval_3 * lval_0 + rval_7 * lval_1 + rval_11 * lval_2 + rval_15 * lval_3,
				rval_0 * lval_4 + rval_4 * lval_5 + rval_8 * lval_6 + rval_12 * lval_7,
				rval_1 * lval_4 + rval_5 * lval_5 + rval_9 * lval_6 + rval_13 * lval_7,
				rval_2 * lval_4 + rval_6 * lval_5 + rval_10 * lval_6 + rval_14 * lval_7,
				rval_3 * lval_4 + rval_7 * lval_5 + rval_11 * lval_6 + rval_15 * lval_7,
				rval_0 * lval_8 + rval_4 * lval_9 + rval_8 * lval_10 + rval_12 * lval_11,
				rval_1 * lval_8 + rval_5 * lval_9 + rval_9 * lval_10 + rval_13 * lval_11,
				rval_2 * lval_8 + rval_6 * lval_9 + rval_10 * lval_10 + rval_14 * lval_11,
				rval_3 * lval_8 + rval_7 * lval_9 + rval_11 * lval_10 + rval_15 * lval_11,
				rval_0 * lval_12 + rval_4 * lval_13 + rval_8 * lval_14 + rval_12 * lval_15,
				rval_1 * lval_12 + rval_5 * lval_13 + rval_9 * lval_14 + rval_13 * lval_15,
				rval_2 * lval_12 + rval_6 * lval_13 + rval_10 * lval_14 + rval_14 * lval_15,
				rval_3 * lval_12 + rval_7 * lval_13 + rval_11 * lval_14 + rval_15 * lval_15,
				0.000001
			), verbose);
		}
		{ // matrix - vector multiplication
			const Mat4d mat(3.0, 1.344, 0.44, 12220.5, 45.67, 0.5, 1.2, 3.333, 1.09, 12.9, 45.6, 76.77, 90.0, 55.5, 22.2, 33.3);
			const Vec4f fvec(3.4f, 0.455f, 9.55f, 6.5f);
			const Vec4d dvec(3.4, 0.455, 9.55, 6.5);
			const Vec4f pfvec = mat * fvec;
			const Vec4d pdvec = mat * dvec;
			Assertv(pfvec.equals(
				(float)(mat[0][0] * fvec.x + mat[1][0] * fvec.y + mat[2][0] * fvec.z + mat[3][0] * fvec.w),
				(float)(mat[0][1] * fvec.x + mat[1][1] * fvec.y + mat[2][1] * fvec.z + mat[3][1] * fvec.w),
				(float)(mat[0][2] * fvec.x + mat[1][2] * fvec.y + mat[2][2] * fvec.z + mat[3][2] * fvec.w),
				(float)(mat[0][3] * fvec.x + mat[1][3] * fvec.y + mat[2][3] * fvec.z + mat[3][3] * fvec.w),
				0.0001f
			), verbose);
			Assertv(pdvec.equals(
				mat[0][0] * dvec.x + mat[1][0] * dvec.y + mat[2][0] * dvec.z + mat[3][0] * dvec.w,
				mat[0][1] * dvec.x + mat[1][1] * dvec.y + mat[2][1] * dvec.z + mat[3][1] * dvec.w,
				mat[0][2] * dvec.x + mat[1][2] * dvec.y + mat[2][2] * dvec.z + mat[3][2] * dvec.w,
				mat[0][3] * dvec.x + mat[1][3] * dvec.y + mat[2][3] * dvec.z + mat[3][3] * dvec.w,
				0.000001
			), verbose);
		}
	}
	{ // at
		{
			const Mat4d mat(3.0, 1.344, 0.44, 12220.5, 45.67, 0.5, 1.2, 3.333, 1.09, 12.9, 45.6, 76.77, 90.0, 55.5, 22.2, 33.3);
			Assertv(Double::equals(mat.at(0, 0), 3.0, 0.000001), verbose);
			Assertv(Double::equals(mat.at(0, 1), 1.344, 0.000001), verbose);
			Assertv(Double::equals(mat.at(0, 2), 0.44, 0.000001), verbose);
			Assertv(Double::equals(mat.at(0, 3), 12220.5, 0.000001), verbose);
			Assertv(Double::equals(mat.at(1, 0), 45.67, 0.000001), verbose);
			Assertv(Double::equals(mat.at(1, 1), 0.5, 0.000001), verbose);
			Assertv(Double::equals(mat.at(1, 2), 1.2, 0.000001), verbose);
			Assertv(Double::equals(mat.at(1, 3), 3.333, 0.000001), verbose);
			Assertv(Double::equals(mat.at(2, 0), 1.09, 0.000001), verbose);
			Assertv(Double::equals(mat.at(2, 1), 12.9, 0.000001), verbose);
			Assertv(Double::equals(mat.at(2, 2), 45.6, 0.000001), verbose);
			Assertv(Double::equals(mat.at(2, 3), 76.77, 0.000001), verbose);
			Assertv(Double::equals(mat.at(3, 0), 90.0, 0.000001), verbose);
			Assertv(Double::equals(mat.at(3, 1), 55.5, 0.000001), verbose);
			Assertv(Double::equals(mat.at(3, 2), 22.2, 0.000001), verbose);
			Assertv(Double::equals(mat.at(3, 3), 33.3, 0.000001), verbose);
		}
		{
			Mat4d::Default = Mat4d::Identity;
			Mat4d mat;
			Assertv(mat.equals(Mat4d::Identity), verbose);
			Assertv(Double::equals((mat.at(0, 0) = 3.0), 3.0, 0.000001), verbose);
			Assertv(Double::equals((mat.at(0, 1) = 1.344), 1.344, 0.000001), verbose);
			Assertv(Double::equals((mat.at(0, 2) = 0.44), 0.44, 0.000001), verbose);
			Assertv(Double::equals((mat.at(0, 3) = 12220.5), 12220.5, 0.000001), verbose);
			Assertv(Double::equals((mat.at(1, 0) = 45.67), 45.67, 0.000001), verbose);
			Assertv(Double::equals((mat.at(1, 1) = 0.5), 0.5, 0.000001), verbose);
			Assertv(Double::equals((mat.at(1, 2) = 1.2), 1.2, 0.000001), verbose);
			Assertv(Double::equals((mat.at(1, 3) = 3.333), 3.333, 0.000001), verbose);
			Assertv(Double::equals((mat.at(2, 0) = 1.09), 1.09, 0.000001), verbose);
			Assertv(Double::equals((mat.at(2, 1) = 12.9), 12.9, 0.000001), verbose);
			Assertv(Double::equals((mat.at(2, 2) = 45.6), 45.6, 0.000001), verbose);
			Assertv(Double::equals((mat.at(2, 3) = 76.77), 76.77, 0.000001), verbose);
			Assertv(Double::equals((mat.at(3, 0) = 90.0), 90.0, 0.000001), verbose);
			Assertv(Double::equals((mat.at(3, 1) = 55.5), 55.5, 0.000001), verbose);
			Assertv(Double::equals((mat.at(3, 2) = 22.2), 22.2, 0.000001), verbose);
			Assertv(Double::equals((mat.at(3, 3) = 33.3), 33.3, 0.000001), verbose);
			Assertv(mat.equals(3.0, 1.344, 0.44, 12220.5, 45.67, 0.5, 1.2, 3.333, 1.09, 12.9, 45.6, 76.77, 90.0, 55.5, 22.2, 33.3), verbose);
		}
	}
	{ // set values
		Mat4d mat(0);
		Assertv(mat.equals(Mat4d::Zero), verbose);
		Assertv(&mat == &(mat.set(3.0, 1.344, 0.44, 12220.5, 45.67, 0.5, 1.2, 3.333, 1.09, 12.9, 45.6, 76.77, 90.0, 55.5, 22.2, 33.3)), verbose);
		Assertv(Double::equals(mat.at(0, 0), 3.0, 0.000001), verbose);
		Assertv(Double::equals(mat.at(0, 1), 1.344, 0.000001), verbose);
		Assertv(Double::equals(mat.at(0, 2), 0.44, 0.000001), verbose);
		Assertv(Double::equals(mat.at(0, 3), 12220.5, 0.000001), verbose);
		Assertv(Double::equals(mat.at(1, 0), 45.67, 0.000001), verbose);
		Assertv(Double::equals(mat.at(1, 1), 0.5, 0.000001), verbose);
		Assertv(Double::equals(mat.at(1, 2), 1.2, 0.000001), verbose);
		Assertv(Double::equals(mat.at(1, 3), 3.333, 0.000001), verbose);
		Assertv(Double::equals(mat.at(2, 0), 1.09, 0.000001), verbose);
		Assertv(Double::equals(mat.at(2, 1), 12.9, 0.000001), verbose);
		Assertv(Double::equals(mat.at(2, 2), 45.6, 0.000001), verbose);
		Assertv(Double::equals(mat.at(2, 3), 76.77, 0.000001), verbose);
		Assertv(Double::equals(mat.at(3, 0), 90.0, 0.000001), verbose);
		Assertv(Double::equals(mat.at(3, 1), 55.5, 0.000001), verbose);
		Assertv(Double::equals(mat.at(3, 2), 22.2, 0.000001), verbose);
		Assertv(Double::equals(mat.at(3, 3), 33.3, 0.000001), verbose);
	}
	{ // set from array
		Mat4d mat(0);
		Assertv(mat.equals(Mat4d::Zero), verbose);
		const double pv[] = {3.0, 1.344, 0.44, 12220.5, 45.67, 0.5, 1.2, 3.333, 1.09, 12.9, 45.6, 76.77, 90.0, 55.5, 22.2, 33.3};
		Assertv(&mat == &(mat.set(pv)), verbose);
		Assertv(Double::equals(mat.at(0, 0), 3.0, 0.000001), verbose);
		Assertv(Double::equals(mat.at(0, 1), 1.344, 0.000001), verbose);
		Assertv(Double::equals(mat.at(0, 2), 0.44, 0.000001), verbose);
		Assertv(Double::equals(mat.at(0, 3), 12220.5, 0.000001), verbose);
		Assertv(Double::equals(mat.at(1, 0), 45.67, 0.000001), verbose);
		Assertv(Double::equals(mat.at(1, 1), 0.5, 0.000001), verbose);
		Assertv(Double::equals(mat.at(1, 2), 1.2, 0.000001), verbose);
		Assertv(Double::equals(mat.at(1, 3), 3.333, 0.000001), verbose);
		Assertv(Double::equals(mat.at(2, 0), 1.09, 0.000001), verbose);
		Assertv(Double::equals(mat.at(2, 1), 12.9, 0.000001), verbose);
		Assertv(Double::equals(mat.at(2, 2), 45.6, 0.000001), verbose);
		Assertv(Double::equals(mat.at(2, 3), 76.77, 0.000001), verbose);
		Assertv(Double::equals(mat.at(3, 0), 90.0, 0.000001), verbose);
		Assertv(Double::equals(mat.at(3, 1), 55.5, 0.000001), verbose);
		Assertv(Double::equals(mat.at(3, 2), 22.2, 0.000001), verbose);
		Assertv(Double::equals(mat.at(3, 3), 33.3, 0.000001), verbose);
	}
	{ // setValue
		Mat4d mat(0);
		Assertv(mat.equals(Mat4d::Zero), verbose);
		mat.setValue(0, 0, 3.0);
		Assertv(Double::equals(mat.at(0, 0), 3.0, 0.000001), verbose);
		mat.setValue(0, 1, 1.344);
		Assertv(Double::equals(mat.at(0, 1), 1.344, 0.000001), verbose);
		mat.setValue(0, 2, 5.4);
		Assertv(Double::equals(mat.at(0, 2), 5.4, 0.000001), verbose);
		mat.setValue(0, 3, 0.44);
		Assertv(Double::equals(mat.at(0, 3), 0.44, 0.000001), verbose);
		mat.setValue(1, 0, 9.56);
		Assertv(Double::equals(mat.at(1, 0), 9.56, 0.000001), verbose);
		mat.setValue(1, 1, 10.05);
		Assertv(Double::equals(mat.at(1, 1), 10.05, 0.000001), verbose);
		mat.setValue(1, 2, 6.666);
		Assertv(Double::equals(mat.at(1, 2), 6.666, 0.000001), verbose);
		mat.setValue(1, 3, 34.56);
		Assertv(Double::equals(mat.at(1, 3), 34.56, 0.000001), verbose);
		mat.setValue(2, 0, 12220.5);
		Assertv(Double::equals(mat.at(2, 0), 12220.5, 0.000001), verbose);
		mat.setValue(2, 1, 12.9);
		Assertv(Double::equals(mat.at(2, 1), 12.9, 0.000001), verbose);
		mat.setValue(2, 2, 45.6);
		Assertv(Double::equals(mat.at(2, 2), 45.6, 0.000001), verbose);
		mat.setValue(2, 3, 76.77);
		Assertv(Double::equals(mat.at(2, 3), 76.77, 0.000001), verbose);
		mat.setValue(3, 0, 90.0);
		Assertv(Double::equals(mat.at(3, 0), 90.0, 0.000001), verbose);
		mat.setValue(3, 1, 55.5);
		Assertv(Double::equals(mat.at(3, 1), 55.5, 0.000001), verbose);
		mat.setValue(3, 2, 22.2);
		Assertv(Double::equals(mat.at(3, 2), 22.2, 0.000001), verbose);
		mat.setValue(3, 3, 33.3);
		Assertv(Double::equals(mat.at(0, 0), 3.0, 0.000001), verbose);
		Assertv(Double::equals(mat.at(0, 1), 1.344, 0.000001), verbose);
		Assertv(Double::equals(mat.at(0, 2), 5.4, 0.000001), verbose);
		Assertv(Double::equals(mat.at(0, 3), 0.44, 0.000001), verbose);
		Assertv(Double::equals(mat.at(1, 0), 9.56, 0.000001), verbose);
		Assertv(Double::equals(mat.at(1, 1), 10.05, 0.000001), verbose);
		Assertv(Double::equals(mat.at(1, 2), 6.666, 0.000001), verbose);
		Assertv(Double::equals(mat.at(1, 3), 34.56, 0.000001), verbose);
		Assertv(Double::equals(mat.at(2, 0), 12220.5, 0.000001), verbose);
		Assertv(Double::equals(mat.at(2, 1), 12.9, 0.000001), verbose);
		Assertv(Double::equals(mat.at(2, 2), 45.6, 0.000001), verbose);
		Assertv(Double::equals(mat.at(2, 3), 76.77, 0.000001), verbose);
		Assertv(Double::equals(mat.at(3, 0), 90.0, 0.000001), verbose);
		Assertv(Double::equals(mat.at(3, 1), 55.5, 0.000001), verbose);
		Assertv(Double::equals(mat.at(3, 2), 22.2, 0.000001), verbose);
		Assertv(Double::equals(mat.at(3, 3), 33.3, 0.000001), verbose);
	}
	{ // Nan
		{
			const Mat4d mat(0.0, 2.0, 1.0, 34.4, 45.67, 0.5, 1.2, 3.333, 1.09, 12.9, 45.6, 76.77, 90.0, 55.5, 22.2, 33.3);
			Assertv(mat.equals(0.0, 2.0, 1.0, 34.4, 45.67, 0.5, 1.2, 3.333, 1.09, 12.9, 45.6, 76.77, 90.0, 55.5, 22.2, 33.3), verbose);
			Assertv(!mat.isNan(), verbose);
			Assertv(mat.isNotNan(), verbose);
			Assertv(!mat.hasNan(), verbose);
			Assertv(mat.hasNoNan(), verbose);
		}
		{
			const Mat4d mat(0.0, Double::Nan, 1.0, 34.4, 45.67, 0.5, 1.2, 3.333, 1.09, 12.9, 45.6, 76.77, 90.0, 55.5, 22.2, 33.3);
			Assertv(mat.equals(0.0, Double::Nan, 1.0, 34.4, 45.67, 0.5, 1.2, 3.333, 1.09, 12.9, 45.6, 76.77, 90.0, 55.5, 22.2, 33.3), verbose);
			Assertv(!mat.isNan(), verbose);
			Assertv(mat.isNotNan(), verbose);
			Assertv(mat.hasNan(), verbose);
			Assertv(!mat.hasNoNan(), verbose);
		}
		{
			const Mat4d mat(0.0, 1.0, 34.4, 45.67, 0.5, 1.2, 3.333, 1.09, 12.9, 45.6, 76.77, 90.0, 55.5, 22.2, Double::Nan, 33.3);
			Assertv(mat.equals(0.0, 1.0, 34.4, 45.67, 0.5, 1.2, 3.333, 1.09, 12.9, 45.6, 76.77, 90.0, 55.5, 22.2, Double::Nan, 33.3), verbose);
			Assertv(!mat.isNan(), verbose);
			Assertv(mat.isNotNan(), verbose);
			Assertv(mat.hasNan(), verbose);
			Assertv(!mat.hasNoNan(), verbose);
		}
		{
			const Mat4d mat(Double::Nan, Double::Nan, Double::Nan, Double::PosInf, Double::Nan, Double::Nan, Double::Nan, Double::PosInf, Double::NegInf, Double::Nan, Double::Nan, Double::Nan, Double::PosInf, Double::Nan, Double::Nan, Double::Nan);
			Assertv(mat.equals(Double::Nan, Double::Nan, Double::Nan, Double::PosInf, Double::Nan, Double::Nan, Double::Nan, Double::PosInf, Double::NegInf, Double::Nan, Double::Nan, Double::Nan, Double::PosInf, Double::Nan, Double::Nan, Double::Nan), verbose);
			Assertv(!mat.isNan(), verbose);
			Assertv(mat.isNotNan(), verbose);
			Assertv(mat.hasNan(), verbose);
			Assertv(!mat.hasNoNan(), verbose);
		}
		{
			const Mat4d mat(Double::Nan, Double::Nan, Double::Nan, Double::Nan, Double::Nan, Double::Nan, Double::Nan, Double::Nan, Double::Nan, Double::Nan, Double::Nan, Double::Nan, Double::Nan, Double::Nan, Double::Nan, Double::Nan);
			Assertv(mat.isNan(), verbose);
			Assertv(!mat.isNotNan(), verbose);
			Assertv(mat.hasNan(), verbose);
			Assertv(!mat.hasNoNan(), verbose);
		}
	}
	{ // transpose
		Assertv(Mat4d(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16).transpose().equals(1,5,9,13,2,6,10,14,3,7,11,15,4,8,12,16, 0.000001), verbose);
		Assertv(Mat4d(1,0,0,0,0,-2,0,0,0,0,3,0,0,0,0,-4).transpose().equals(1,0,0,0,0,-2,0,0,0,0,3,0,0,0,0,-4, 0.000001), verbose);
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