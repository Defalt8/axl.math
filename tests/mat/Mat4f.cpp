#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include "../Assert.hpp"
#include "../lib.hpp"
#include <axl.math/float.hpp>
#include <axl.math/mat/Mat4d.hpp>
#include <axl.math/mat/Mat4f.hpp>

int main(int argc, char *argv[])
{
	bool verbose = argc > 1 && (0 == strcmp(argv[1], "-v") || 0 == strcmp(argv[1], "--verbose"));
	using namespace axl;
	using namespace axl::math;
	printf("axl.math - version %hu.%hu.%hu  %s %s\n", lib::VERSION.major, lib::VERSION.minor, lib::VERSION.patch, libType(lib::LIBRARY_TYPE), buildType(lib::BUILD_TYPE));
	puts("----------------------------------------");
	{ // static values
		Assertv(Float::equals(0.0f, Mat4f::Zero.values[0]), verbose);
		Assertv(Float::equals(0.0f, Mat4f::Zero.values[1]), verbose);
		Assertv(Float::equals(0.0f, Mat4f::Zero.values[2]), verbose);
		Assertv(Float::equals(0.0f, Mat4f::Zero.values[3]), verbose);
		Assertv(Float::equals(0.0f, Mat4f::Zero.values[4]), verbose);
		Assertv(Float::equals(0.0f, Mat4f::Zero.values[5]), verbose);
		Assertv(Float::equals(0.0f, Mat4f::Zero.values[6]), verbose);
		Assertv(Float::equals(0.0f, Mat4f::Zero.values[7]), verbose);
		Assertv(Float::equals(0.0f, Mat4f::Zero.values[8]), verbose);
		Assertv(Float::equals(0.0f, Mat4f::Zero.values[9]), verbose);
		Assertv(Float::equals(0.0f, Mat4f::Zero.values[10]), verbose);
		Assertv(Float::equals(0.0f, Mat4f::Zero.values[11]), verbose);
		Assertv(Float::equals(0.0f, Mat4f::Zero.values[12]), verbose);
		Assertv(Float::equals(0.0f, Mat4f::Zero.values[13]), verbose);
		Assertv(Float::equals(0.0f, Mat4f::Zero.values[14]), verbose);
		Assertv(Float::equals(0.0f, Mat4f::Zero.values[15]), verbose);
		Assertv(Float::equals(1.0f, Mat4f::Identity.values[0]), verbose);
		Assertv(Float::equals(0.0f, Mat4f::Identity.values[1]), verbose);
		Assertv(Float::equals(0.0f, Mat4f::Identity.values[2]), verbose);
		Assertv(Float::equals(0.0f, Mat4f::Identity.values[3]), verbose);
		Assertv(Float::equals(0.0f, Mat4f::Identity.values[4]), verbose);
		Assertv(Float::equals(1.0f, Mat4f::Identity.values[5]), verbose);
		Assertv(Float::equals(0.0f, Mat4f::Identity.values[6]), verbose);
		Assertv(Float::equals(0.0f, Mat4f::Identity.values[7]), verbose);
		Assertv(Float::equals(0.0f, Mat4f::Identity.values[8]), verbose);
		Assertv(Float::equals(0.0f, Mat4f::Identity.values[9]), verbose);
		Assertv(Float::equals(1.0f, Mat4f::Identity.values[10]), verbose);
		Assertv(Float::equals(0.0f, Mat4f::Identity.values[11]), verbose);
		Assertv(Float::equals(0.0f, Mat4f::Identity.values[12]), verbose);
		Assertv(Float::equals(0.0f, Mat4f::Identity.values[13]), verbose);
		Assertv(Float::equals(0.0f, Mat4f::Identity.values[14]), verbose);
		Assertv(Float::equals(1.0f, Mat4f::Identity.values[15]), verbose);
		Assertv(Mat4f::filled(4.0f).equals(4.0f,4.0f,4.0f,4.0f,4.0f,4.0f,4.0f,4.0f,4.0f,4.0f,4.0f,4.0f,4.0f,4.0f,4.0f,4.0f), verbose);
	}
	{ // constructors
		{ // default constructor
			{
				const Mat4f mat;
				Assertv(Float::equals(0.0f, mat.values[0]), verbose);
				Assertv(Float::equals(0.0f, mat.values[1]), verbose);
				Assertv(Float::equals(0.0f, mat.values[2]), verbose);
				Assertv(Float::equals(0.0f, mat.values[3]), verbose);
				Assertv(Float::equals(0.0f, mat.values[4]), verbose);
				Assertv(Float::equals(0.0f, mat.values[5]), verbose);
				Assertv(Float::equals(0.0f, mat.values[6]), verbose);
				Assertv(Float::equals(0.0f, mat.values[7]), verbose);
				Assertv(Float::equals(0.0f, mat.values[8]), verbose);
				Assertv(Float::equals(0.0f, mat.values[9]), verbose);
				Assertv(Float::equals(0.0f, mat.values[10]), verbose);
				Assertv(Float::equals(0.0f, mat.values[11]), verbose);
				Assertv(Float::equals(0.0f, mat.values[12]), verbose);
				Assertv(Float::equals(0.0f, mat.values[13]), verbose);
				Assertv(Float::equals(0.0f, mat.values[14]), verbose);
				Assertv(Float::equals(0.0f, mat.values[15]), verbose);
			}
			{
				Mat4f::Default = Mat4f::Identity;
				const Mat4f mat;
				Assertv(Float::equals(1.0f, mat.values[0]), verbose);
				Assertv(Float::equals(0.0f, mat.values[1]), verbose);
				Assertv(Float::equals(0.0f, mat.values[2]), verbose);
				Assertv(Float::equals(0.0f, mat.values[3]), verbose);
				Assertv(Float::equals(0.0f, mat.values[4]), verbose);
				Assertv(Float::equals(1.0f, mat.values[5]), verbose);
				Assertv(Float::equals(0.0f, mat.values[6]), verbose);
				Assertv(Float::equals(0.0f, mat.values[7]), verbose);
				Assertv(Float::equals(0.0f, mat.values[8]), verbose);
				Assertv(Float::equals(0.0f, mat.values[9]), verbose);
				Assertv(Float::equals(1.0f, mat.values[10]), verbose);
				Assertv(Float::equals(0.0f, mat.values[11]), verbose);
				Assertv(Float::equals(0.0f, mat.values[12]), verbose);
				Assertv(Float::equals(0.0f, mat.values[13]), verbose);
				Assertv(Float::equals(0.0f, mat.values[14]), verbose);
				Assertv(Float::equals(1.0f, mat.values[15]), verbose);
			}
		}
		{ // value constructor
			const Mat4f mat(3.1415f);
			Assertv(mat.equals(3.1415f, 0.0f, 0.0f, 0.0f, 0.0f, 3.1415f, 0.0f, 0.0f, 0.0f, 0.0f, 3.1415f, 0.0f, 0.0f, 0.0f, 0.0f, 3.1415f), verbose);
		}
		{ // values constructor
			const Mat4f mat(3.1415f, 0.6734f, 3.45f, 0.44f, 45.67f, 0.5f, 1.2f, 3.333f, 1.09f, 12.9f, 45.6f, 76.77f, 90.0f, 55.5f, 22.2f, 33.3f);
			Assertv(mat.equals(3.1415f, 0.6734f, 3.45f, 0.44f, 45.67f, 0.5f, 1.2f, 3.333f, 1.09f, 12.9f, 45.6f, 76.77f, 90.0f, 55.5f, 22.2f, 33.3f, 0.0001f), verbose);
		}
		{ // copy constructor
			const Mat4f mat(3.1415f, 0.6734f, 3.45f, 0.44f, 45.67f, 0.5f, 1.2f, 3.333f, 1.09f, 12.9f, 45.6f, 76.77f, 90.0f, 55.5f, 22.2f, 33.3f);
			Assertv(mat.equals(3.1415f, 0.6734f, 3.45f, 0.44f, 45.67f, 0.5f, 1.2f, 3.333f, 1.09f, 12.9f, 45.6f, 76.77f, 90.0f, 55.5f, 22.2f, 33.3f, 0.0001f), verbose);
			const Mat4f mat1(mat);
			Assertv(mat1.equals(3.1415f, 0.6734f, 3.45f, 0.44f, 45.67f, 0.5f, 1.2f, 3.333f, 1.09f, 12.9f, 45.6f, 76.77f, 90.0f, 55.5f, 22.2f, 33.3f, 0.0001f), verbose);
			const Mat4f mat2 = mat;
			Assertv(mat2.equals(3.1415f, 0.6734f, 3.45f, 0.44f, 45.67f, 0.5f, 1.2f, 3.333f, 1.09f, 12.9f, 45.6f, 76.77f, 90.0f, 55.5f, 22.2f, 33.3f, 0.0001f), verbose);
			Assertv(Mat4f(Mat4d(3.1415, 0.6734, 3.45, 0.44, 45.67, 0.5, 1.2, 3.333, 1.09, 12.9, 45.6, 76.77, 90.0, 55.5, 22.2, 33.3)).equals(3.1415f, 0.6734f, 3.45f, 0.44f, 45.67f, 0.5f, 1.2f, 3.333f, 1.09f, 12.9f, 45.6f, 76.77f, 90.0f, 55.5f, 22.2f, 33.3f), verbose);
		}
	}
	{ // square bracket operators
		const Mat4f mat(3.1415f, 0.6734f, 3.45f, 0.44f, 45.67f, 0.5f, 1.2f, 3.333f, 1.09f, 12.9f, 45.6f, 76.77f, 90.0f, 55.5f, 22.2f, 33.3f);
		Assertv(Float::equals(mat[0][0], 3.1415f, 0.0001f), verbose);
		Assertv(Float::equals(mat[0][1], 0.6734f, 0.0001f), verbose); 
		Assertv(Float::equals(mat[0][2], 3.45f, 0.0001f), verbose);
		Assertv(Float::equals(mat[0][3], 0.44f, 0.0001f), verbose);
		Assertv(Float::equals(mat[1][0], 45.67f, 0.0001f), verbose);
		Assertv(Float::equals(mat[1][1], 0.5f, 0.0001f), verbose);
		Assertv(Float::equals(mat[1][2], 1.2f, 0.0001f), verbose);
		Assertv(Float::equals(mat[1][3], 3.333f, 0.0001f), verbose);
		Assertv(Float::equals(mat[2][0], 1.09f, 0.0001f), verbose);
		Assertv(Float::equals(mat[2][1], 12.9f, 0.0001f), verbose);
		Assertv(Float::equals(mat[2][2], 45.6f, 0.0001f), verbose);
		Assertv(Float::equals(mat[2][3], 76.77f, 0.0001f), verbose);
		Assertv(Float::equals(mat[3][0], 90.0f, 0.0001f), verbose);
		Assertv(Float::equals(mat[3][1], 55.5f, 0.0001f), verbose);
		Assertv(Float::equals(mat[3][2], 22.2f, 0.0001f), verbose);
		Assertv(Float::equals(mat[3][3], 33.3f, 0.0001f), verbose);
	}
	{ // equality operators
		Assertv(Mat4f::Zero == 0.0f, verbose);
		Assertv(Mat4f::filled(1.0f) == 1.0f, verbose);
		Assertv(Mat4f::Zero == Mat4f::Zero, verbose);
		Assertv(Mat4f::Identity == Mat4f::Identity, verbose);
		Assertv(!(Mat4f::Zero != 0.0f), verbose);
		Assertv(!(Mat4f::filled(1.0f) != 1.0f), verbose);
		Assertv(!(Mat4f::Zero != Mat4f::Zero), verbose);
		Assertv(!(Mat4f::Identity != Mat4f::Identity), verbose);
		Mat4f mat(3.1415f, 0.6734f, 3.45f, 0.44f, 45.67f, 0.5f, 1.2f, 3.333f, 1.09f, 12.9f, 45.6f, 76.77f, 90.0f, 55.5f, 22.2f, 33.3f), mat2(3.1415f, 0.6734f, 1.2345f, 0.987654f, 4.0f, 5.0f, 12.9f, 45.6f, 76.77f, 90.0f, 55.5f, 22.2f, 33.3f, 6.0f, 7.0f, 8.0f);
		Assertv(mat.equals(3.1415f, 0.6734f, 3.45f, 0.44f, 45.67f, 0.5f, 1.2f, 3.333f, 1.09f, 12.9f, 45.6f, 76.77f, 90.0f, 55.5f, 22.2f, 33.3f), verbose);
		Assertv(mat.equals(mat), verbose);
		Assertv(!mat.equals(3.1415f), verbose);
		Assertv(!mat.equals(3.45f), verbose);
		Assertv(!mat.equals(mat2), verbose);
		Assertv(!mat.notEquals(3.1415f, 0.6734f, 3.45f, 0.44f, 45.67f, 0.5f, 1.2f, 3.333f, 1.09f, 12.9f, 45.6f, 76.77f, 90.0f, 55.5f, 22.2f, 33.3f), verbose);
		Assertv(!mat.notEquals(mat), verbose);
		Assertv(mat.notEquals(3.1415f), verbose);
		Assertv(mat.notEquals(3.45f), verbose);
		Assertv(mat.notEquals(mat2), verbose);
	}
	{ // arthimetic operators
		const float lval_0 = 12.344f, lval_1 = 131.04f, lval_2 = 0.4555f, lval_3 = 23000.45f, lval_4 = 45.67f, lval_5 = 0.5f, lval_6 = 1.2f, lval_7 = 3.333f, lval_8 = 1.09f, lval_9 = 12.9f, lval_10 = 45.6f, lval_11 = 76.77f, lval_12 = 90.0f, lval_13 = 55.5f, lval_14 = 22.2f, lval_15 = 33.3f;
		const float rval_0 = 10023.54f, rval_1 = 45.323f, rval_2 = 1.233f, rval_3 = 0.5f, rval_4 = 145.67f, rval_5 = 10.5f, rval_6 = 11.2f, rval_7 = 13.333f, rval_8 = 11.09f, rval_9 = 31.49f, rval_10 = 34.46f, rval_11 = 37.477f, rval_12 = 39.40f, rval_13 = 35.45f, rval_14 = 32.42f, rval_15 = 33.43f;
		{ // scalar addition
			const Mat4f lmat(lval_0, lval_1, lval_2, lval_3, lval_4, lval_5, lval_6, lval_7, lval_8, lval_9, lval_10, lval_11, lval_12, lval_13, lval_14, lval_15);
			const Mat4f rmat(rval_0, rval_1, rval_2, rval_3, rval_4, rval_5, rval_6, rval_7, rval_8, rval_9, rval_10, rval_11, rval_12, rval_13, rval_14, rval_15);
			Mat4f mat = lmat + rmat;
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
			const Mat4f lmat(lval_0, lval_1, lval_2, lval_3, lval_4, lval_5, lval_6, lval_7, lval_8, lval_9, lval_10, lval_11, lval_12, lval_13, lval_14, lval_15);
			const Mat4f rmat(rval_0, rval_1, rval_2, rval_3, rval_4, rval_5, rval_6, rval_7, rval_8, rval_9, rval_10, rval_11, rval_12, rval_13, rval_14, rval_15);
			Mat4f mat = lmat - rmat;
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
			const Mat4f lmat(lval_0, lval_1, lval_2, lval_3, lval_4, lval_5, lval_6, lval_7, lval_8, lval_9, lval_10, lval_11, lval_12, lval_13, lval_14, lval_15);
			const Mat4f rmat(rval_0, rval_1, rval_2, rval_3, rval_4, rval_5, rval_6, rval_7, rval_8, rval_9, rval_10, rval_11, rval_12, rval_13, rval_14, rval_15);
			Mat4f mat = lmat.scMul(rmat);
			Assertv(mat.equals(lval_0 * rval_0, lval_1 * rval_1, lval_2 * rval_2, lval_3 * rval_3, lval_4 * rval_4, lval_5 * rval_5, lval_6 * rval_6, lval_7 * rval_7, lval_8 * rval_8, lval_9 * rval_9, lval_10 * rval_10, lval_11 * rval_11, lval_12 * rval_12, lval_13 * rval_13, lval_14 * rval_14, lval_15 * rval_15), verbose );
			mat = lmat * rval_0;
			Assertv(mat.equals(lval_0 * rval_0, lval_1 * rval_0, lval_2 * rval_0, lval_3 * rval_0, lval_4 * rval_0, lval_5 * rval_0, lval_6 * rval_0, lval_7 * rval_0, lval_8 * rval_0, lval_9 * rval_0, lval_10 * rval_0, lval_11 * rval_0, lval_12 * rval_0, lval_13 * rval_0, lval_14 * rval_0, lval_15 * rval_0), verbose );
			mat = lmat;
			mat *= rval_1;
			Assertv(mat.equals(lval_0 * rval_1, lval_1 * rval_1, lval_2 * rval_1, lval_3 * rval_1, lval_4 * rval_1, lval_5 * rval_1, lval_6 * rval_1, lval_7 * rval_1, lval_8 * rval_1, lval_9 * rval_1, lval_10 * rval_1, lval_11 * rval_1, lval_12 * rval_1, lval_13 * rval_1, lval_14 * rval_1, lval_15 * rval_1), verbose);
		}
		{ // scalar division
			const Mat4f lmat(lval_0, lval_1, lval_2, lval_3, lval_4, lval_5, lval_6, lval_7, lval_8, lval_9, lval_10, lval_11, lval_12, lval_13, lval_14, lval_15);
			const Mat4f rmat(rval_0, rval_1, rval_2, rval_3, rval_4, rval_5, rval_6, rval_7, rval_8, rval_9, rval_10, rval_11, rval_12, rval_13, rval_14, rval_15);
			Mat4f mat = lmat.scDiv(rmat);
			Assertv(mat.equals(lval_0 / rval_0, lval_1 / rval_1, lval_2 / rval_2, lval_3 / rval_3, lval_4 / rval_4, lval_5 / rval_5, lval_6 / rval_6, lval_7 / rval_7, lval_8 / rval_8, lval_9 / rval_9, lval_10 / rval_10, lval_11 / rval_11, lval_12 / rval_12, lval_13 / rval_13, lval_14 / rval_14, lval_15 / rval_15), verbose );
			mat = lmat / rval_0;
			Assertv(mat.equals(lval_0 / rval_0, lval_1 / rval_0, lval_2 / rval_0, lval_3 / rval_0, lval_4 / rval_0, lval_5 / rval_0, lval_6 / rval_0, lval_7 / rval_0, lval_8 / rval_0, lval_9 / rval_0, lval_10 / rval_0, lval_11 / rval_0, lval_12 / rval_0, lval_13 / rval_0, lval_14 / rval_0, lval_15 / rval_0), verbose );
			mat = lmat;
			mat /= rval_1;
			Assertv(mat.equals(lval_0 / rval_1, lval_1 / rval_1, lval_2 / rval_1, lval_3 / rval_1, lval_4 / rval_1, lval_5 / rval_1, lval_6 / rval_1, lval_7 / rval_1, lval_8 / rval_1, lval_9 / rval_1, lval_10 / rval_1, lval_11 / rval_1, lval_12 / rval_1, lval_13 / rval_1, lval_14 / rval_1, lval_15 / rval_1), verbose);
		}
		{ // matrix multiplication
			const Mat4f lmat(lval_0, lval_1, lval_2, lval_3, lval_4, lval_5, lval_6, lval_7, lval_8, lval_9, lval_10, lval_11, lval_12, lval_13, lval_14, lval_15);
			const Mat4f rmat(rval_0, rval_1, rval_2, rval_3, rval_4, rval_5, rval_6, rval_7, rval_8, rval_9, rval_10, rval_11, rval_12, rval_13, rval_14, rval_15);
			const Mat4f pmat = lmat * rmat;
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
				0.0001f
			), verbose);
			const Mat4f p2mat = rmat * lmat;
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
				0.0001f
			), verbose);
		}
		{ // matrix - vector multiplication
			const Mat4f mat(3.0f, 1.344f, 0.44f, 12220.5f, 45.67f, 0.5f, 1.2f, 3.333f, 1.09f, 12.9f, 45.6f, 76.77f, 90.0f, 55.5f, 22.2f, 33.3f);
			const Vec4f fvec(3.4f, 0.455f, 9.55f, 6.5f);
			const Vec4d dvec(3.4, 0.455, 9.55, 6.5);
			const Vec4f pfvec = mat * fvec;
			const Vec4d pdvec = mat * dvec;
			Assertv(pfvec.equals(
				mat[0][0] * fvec.x + mat[1][0] * fvec.y + mat[2][0] * fvec.z + mat[3][0] * fvec.w,
				mat[0][1] * fvec.x + mat[1][1] * fvec.y + mat[2][1] * fvec.z + mat[3][1] * fvec.w,
				mat[0][2] * fvec.x + mat[1][2] * fvec.y + mat[2][2] * fvec.z + mat[3][2] * fvec.w,
				mat[0][3] * fvec.x + mat[1][3] * fvec.y + mat[2][3] * fvec.z + mat[3][3] * fvec.w,
				0.0001f
			), verbose);
			Assertv(pdvec.equals(
				mat[0][0] * dvec.x + mat[1][0] * dvec.y + mat[2][0] * dvec.z + mat[3][0] * dvec.w,
				mat[0][1] * dvec.x + mat[1][1] * dvec.y + mat[2][1] * dvec.z + mat[3][1] * dvec.w,
				mat[0][2] * dvec.x + mat[1][2] * dvec.y + mat[2][2] * dvec.z + mat[3][2] * dvec.w,
				mat[0][3] * dvec.x + mat[1][3] * dvec.y + mat[2][3] * dvec.z + mat[3][3] * dvec.w,
				0.0001f
			), verbose);
		}
	}
	{ // at
		{
			const Mat4f mat(3.0f, 1.344f, 0.44f, 12220.5f, 45.67f, 0.5f, 1.2f, 3.333f, 1.09f, 12.9f, 45.6f, 76.77f, 90.0f, 55.5f, 22.2f, 33.3f);
			Assertv(Float::equals(mat.at(0, 0), 3.0f, 0.0001f), verbose);
			Assertv(Float::equals(mat.at(0, 1), 1.344f, 0.0001f), verbose);
			Assertv(Float::equals(mat.at(0, 2), 0.44f, 0.0001f), verbose);
			Assertv(Float::equals(mat.at(0, 3), 12220.5f, 0.0001f), verbose);
			Assertv(Float::equals(mat.at(1, 0), 45.67f, 0.0001f), verbose);
			Assertv(Float::equals(mat.at(1, 1), 0.5f, 0.0001f), verbose);
			Assertv(Float::equals(mat.at(1, 2), 1.2f, 0.0001f), verbose);
			Assertv(Float::equals(mat.at(1, 3), 3.333f, 0.0001f), verbose);
			Assertv(Float::equals(mat.at(2, 0), 1.09f, 0.0001f), verbose);
			Assertv(Float::equals(mat.at(2, 1), 12.9f, 0.0001f), verbose);
			Assertv(Float::equals(mat.at(2, 2), 45.6f, 0.0001f), verbose);
			Assertv(Float::equals(mat.at(2, 3), 76.77f, 0.0001f), verbose);
			Assertv(Float::equals(mat.at(3, 0), 90.0f, 0.0001f), verbose);
			Assertv(Float::equals(mat.at(3, 1), 55.5f, 0.0001f), verbose);
			Assertv(Float::equals(mat.at(3, 2), 22.2f, 0.0001f), verbose);
			Assertv(Float::equals(mat.at(3, 3), 33.3f, 0.0001f), verbose);
		}
		{
			Mat4f::Default = Mat4f::Identity;
			Mat4f mat;
			Assertv(mat.equals(Mat4f::Identity), verbose);
			Assertv(Float::equals((mat.at(0, 0) = 3.0f), 3.0f, 0.0001f), verbose);
			Assertv(Float::equals((mat.at(0, 1) = 1.344f), 1.344f, 0.0001f), verbose);
			Assertv(Float::equals((mat.at(0, 2) = 0.44f), 0.44f, 0.0001f), verbose);
			Assertv(Float::equals((mat.at(0, 3) = 12220.5f), 12220.5f, 0.0001f), verbose);
			Assertv(Float::equals((mat.at(1, 0) = 45.67f), 45.67f, 0.0001f), verbose);
			Assertv(Float::equals((mat.at(1, 1) = 0.5f), 0.5f, 0.0001f), verbose);
			Assertv(Float::equals((mat.at(1, 2) = 1.2f), 1.2f, 0.0001f), verbose);
			Assertv(Float::equals((mat.at(1, 3) = 3.333f), 3.333f, 0.0001f), verbose);
			Assertv(Float::equals((mat.at(2, 0) = 1.09f), 1.09f, 0.0001f), verbose);
			Assertv(Float::equals((mat.at(2, 1) = 12.9f), 12.9f, 0.0001f), verbose);
			Assertv(Float::equals((mat.at(2, 2) = 45.6f), 45.6f, 0.0001f), verbose);
			Assertv(Float::equals((mat.at(2, 3) = 76.77f), 76.77f, 0.0001f), verbose);
			Assertv(Float::equals((mat.at(3, 0) = 90.0f), 90.0f, 0.0001f), verbose);
			Assertv(Float::equals((mat.at(3, 1) = 55.5f), 55.5f, 0.0001f), verbose);
			Assertv(Float::equals((mat.at(3, 2) = 22.2f), 22.2f, 0.0001f), verbose);
			Assertv(Float::equals((mat.at(3, 3) = 33.3f), 33.3f, 0.0001f), verbose);
			Assertv(mat.equals(3.0f, 1.344f, 0.44f, 12220.5f, 45.67f, 0.5f, 1.2f, 3.333f, 1.09f, 12.9f, 45.6f, 76.77f, 90.0f, 55.5f, 22.2f, 33.3f), verbose);
		}
	}
	{ // set values
		Mat4f mat(0);
		Assertv(mat.equals(Mat4f::Zero), verbose);
		Assertv(&mat == &(mat.set(3.0f, 1.344f, 0.44f, 12220.5f, 45.67f, 0.5f, 1.2f, 3.333f, 1.09f, 12.9f, 45.6f, 76.77f, 90.0f, 55.5f, 22.2f, 33.3f)), verbose);
		Assertv(Float::equals(mat.at(0, 0), 3.0f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(0, 1), 1.344f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(0, 2), 0.44f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(0, 3), 12220.5f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(1, 0), 45.67f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(1, 1), 0.5f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(1, 2), 1.2f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(1, 3), 3.333f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(2, 0), 1.09f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(2, 1), 12.9f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(2, 2), 45.6f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(2, 3), 76.77f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(3, 0), 90.0f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(3, 1), 55.5f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(3, 2), 22.2f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(3, 3), 33.3f, 0.0001f), verbose);
	}
	{ // set from array
		Mat4f mat(0);
		Assertv(mat.equals(Mat4f::Zero), verbose);
		const float pv[] = {3.0f, 1.344f, 0.44f, 12220.5f, 45.67f, 0.5f, 1.2f, 3.333f, 1.09f, 12.9f, 45.6f, 76.77f, 90.0f, 55.5f, 22.2f, 33.3f};
		Assertv(&mat == &(mat.set(pv)), verbose);
		Assertv(Float::equals(mat.at(0, 0), 3.0f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(0, 1), 1.344f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(0, 2), 0.44f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(0, 3), 12220.5f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(1, 0), 45.67f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(1, 1), 0.5f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(1, 2), 1.2f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(1, 3), 3.333f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(2, 0), 1.09f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(2, 1), 12.9f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(2, 2), 45.6f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(2, 3), 76.77f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(3, 0), 90.0f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(3, 1), 55.5f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(3, 2), 22.2f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(3, 3), 33.3f, 0.0001f), verbose);
	}
	{ // setValue
		Mat4f mat(0);
		Assertv(mat.equals(Mat4f::Zero), verbose);
		mat.setValue(0, 0, 3.0f);
		Assertv(Float::equals(mat.at(0, 0), 3.0f, 0.0001f), verbose);
		mat.setValue(0, 1, 1.344f);
		Assertv(Float::equals(mat.at(0, 1), 1.344f, 0.0001f), verbose);
		mat.setValue(0, 2, 5.4f);
		Assertv(Float::equals(mat.at(0, 2), 5.4f, 0.0001f), verbose);
		mat.setValue(0, 3, 0.44f);
		Assertv(Float::equals(mat.at(0, 3), 0.44f, 0.0001f), verbose);
		mat.setValue(1, 0, 9.56f);
		Assertv(Float::equals(mat.at(1, 0), 9.56f, 0.0001f), verbose);
		mat.setValue(1, 1, 10.05f);
		Assertv(Float::equals(mat.at(1, 1), 10.05f, 0.0001f), verbose);
		mat.setValue(1, 2, 6.666f);
		Assertv(Float::equals(mat.at(1, 2), 6.666f, 0.0001f), verbose);
		mat.setValue(1, 3, 34.56f);
		Assertv(Float::equals(mat.at(1, 3), 34.56f, 0.0001f), verbose);
		mat.setValue(2, 0, 12220.5f);
		Assertv(Float::equals(mat.at(2, 0), 12220.5f, 0.0001f), verbose);
		mat.setValue(2, 1, 12.9f);
		Assertv(Float::equals(mat.at(2, 1), 12.9f, 0.0001f), verbose);
		mat.setValue(2, 2, 45.6f);
		Assertv(Float::equals(mat.at(2, 2), 45.6f, 0.0001f), verbose);
		mat.setValue(2, 3, 76.77f);
		Assertv(Float::equals(mat.at(2, 3), 76.77f, 0.0001f), verbose);
		mat.setValue(3, 0, 90.0f);
		Assertv(Float::equals(mat.at(3, 0), 90.0f, 0.0001f), verbose);
		mat.setValue(3, 1, 55.5f);
		Assertv(Float::equals(mat.at(3, 1), 55.5f, 0.0001f), verbose);
		mat.setValue(3, 2, 22.2f);
		Assertv(Float::equals(mat.at(3, 2), 22.2f, 0.0001f), verbose);
		mat.setValue(3, 3, 33.3f);
		Assertv(Float::equals(mat.at(0, 0), 3.0f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(0, 1), 1.344f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(0, 2), 5.4f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(0, 3), 0.44f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(1, 0), 9.56f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(1, 1), 10.05f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(1, 2), 6.666f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(1, 3), 34.56f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(2, 0), 12220.5f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(2, 1), 12.9f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(2, 2), 45.6f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(2, 3), 76.77f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(3, 0), 90.0f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(3, 1), 55.5f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(3, 2), 22.2f, 0.0001f), verbose);
		Assertv(Float::equals(mat.at(3, 3), 33.3f, 0.0001f), verbose);
	}
	{ // Nan
		{
			const Mat4f mat(0.0f, 2.0f, 1.0f, 34.4f, 45.67f, 0.5f, 1.2f, 3.333f, 1.09f, 12.9f, 45.6f, 76.77f, 90.0f, 55.5f, 22.2f, 33.3f);
			Assertv(mat.equals(0.0f, 2.0f, 1.0f, 34.4f, 45.67f, 0.5f, 1.2f, 3.333f, 1.09f, 12.9f, 45.6f, 76.77f, 90.0f, 55.5f, 22.2f, 33.3f), verbose);
			Assertv(!mat.isNan(), verbose);
			Assertv(mat.isNotNan(), verbose);
			Assertv(!mat.hasNan(), verbose);
			Assertv(mat.hasNoNan(), verbose);
		}
		{
			const Mat4f mat(0.0f, Float::Nan, 1.0f, 34.4f, 45.67f, 0.5f, 1.2f, 3.333f, 1.09f, 12.9f, 45.6f, 76.77f, 90.0f, 55.5f, 22.2f, 33.3f);
			Assertv(mat.equals(0.0f, Float::Nan, 1.0f, 34.4f, 45.67f, 0.5f, 1.2f, 3.333f, 1.09f, 12.9f, 45.6f, 76.77f, 90.0f, 55.5f, 22.2f, 33.3f), verbose);
			Assertv(!mat.isNan(), verbose);
			Assertv(mat.isNotNan(), verbose);
			Assertv(mat.hasNan(), verbose);
			Assertv(!mat.hasNoNan(), verbose);
		}
		{
			const Mat4f mat(0.0f, 1.0f, 34.4f, 45.67f, 0.5f, 1.2f, 3.333f, 1.09f, 12.9f, 45.6f, 76.77f, 90.0f, 55.5f, 22.2f, Float::Nan, 33.3f);
			Assertv(mat.equals(0.0f, 1.0f, 34.4f, 45.67f, 0.5f, 1.2f, 3.333f, 1.09f, 12.9f, 45.6f, 76.77f, 90.0f, 55.5f, 22.2f, Float::Nan, 33.3f), verbose);
			Assertv(!mat.isNan(), verbose);
			Assertv(mat.isNotNan(), verbose);
			Assertv(mat.hasNan(), verbose);
			Assertv(!mat.hasNoNan(), verbose);
		}
		{
			const Mat4f mat(Float::Nan, Float::Nan, Float::Nan, Float::PosInf, Float::Nan, Float::Nan, Float::Nan, Float::PosInf, Float::NegInf, Float::Nan, Float::Nan, Float::Nan, Float::PosInf, Float::Nan, Float::Nan, Float::Nan);
			Assertv(mat.equals(Float::Nan, Float::Nan, Float::Nan, Float::PosInf, Float::Nan, Float::Nan, Float::Nan, Float::PosInf, Float::NegInf, Float::Nan, Float::Nan, Float::Nan, Float::PosInf, Float::Nan, Float::Nan, Float::Nan), verbose);
			Assertv(!mat.isNan(), verbose);
			Assertv(mat.isNotNan(), verbose);
			Assertv(mat.hasNan(), verbose);
			Assertv(!mat.hasNoNan(), verbose);
		}
		{
			const Mat4f mat(Float::Nan, Float::Nan, Float::Nan, Float::Nan, Float::Nan, Float::Nan, Float::Nan, Float::Nan, Float::Nan, Float::Nan, Float::Nan, Float::Nan, Float::Nan, Float::Nan, Float::Nan, Float::Nan);
			Assertv(mat.isNan(), verbose);
			Assertv(!mat.isNotNan(), verbose);
			Assertv(mat.hasNan(), verbose);
			Assertv(!mat.hasNoNan(), verbose);
		}
	}
	{ // transpose
		Assertv(Mat4f(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16).transpose().equals(1,5,9,13,2,6,10,14,3,7,11,15,4,8,12,16, 0.0001f), verbose);
		Assertv(Mat4f(1,0,0,0,0,-2,0,0,0,0,3,0,0,0,0,-4).transpose().equals(1,0,0,0,0,-2,0,0,0,0,3,0,0,0,0,-4, 0.0001f), verbose);
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