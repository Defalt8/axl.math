#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include "Assert.hpp"
#include "lib.hpp"
#include <axl.math/float.hpp>
#include <axl.math/Mat2f.hpp>
#include <axl.math/Mat2d.hpp>

float _fzero = 0.0f;
const static float _fnan = _fzero / _fzero;

int main(int argc, char *argv[])
{
	bool verbose = argc > 1 && (0 == strcmp(argv[1], "-v") || 0 == strcmp(argv[1], "--verbose"));
	using namespace axl;
	using namespace axl::math;
	printf("axl.math - version %hu.%hu.%hu  %s %s\n", lib::VERSION.major, lib::VERSION.minor, lib::VERSION.patch, libType(lib::LIBRARY_TYPE), buildType(lib::BUILD_TYPE));
	puts("----------------------------------------");
	{ // static values
		Assertv(Float::equals(0.0f, Mat2f::Zero.values[0]), verbose);
		Assertv(Float::equals(0.0f, Mat2f::Zero.values[1]), verbose);
		Assertv(Float::equals(0.0f, Mat2f::Zero.values[2]), verbose);
		Assertv(Float::equals(0.0f, Mat2f::Zero.values[3]), verbose);
		Assertv(Float::equals(1.0f, Mat2f::Identity.values[0]), verbose);
		Assertv(Float::equals(0.0f, Mat2f::Identity.values[1]), verbose);
		Assertv(Float::equals(0.0f, Mat2f::Identity.values[2]), verbose);
		Assertv(Float::equals(1.0f, Mat2f::Identity.values[3]), verbose);
		Assertv(Mat2f::filled(4.0f).equals(4.0f, 4.0f, 4.0f, 4.0f), verbose);
	}
	{ // constructors
		{ // default constructor
			const Mat2f mat;
			Assertv(Float::equals(0.0f, mat.values[0]), verbose);
			Assertv(Float::equals(0.0f, mat.values[1]), verbose);
			Assertv(Float::equals(0.0f, mat.values[2]), verbose);
			Assertv(Float::equals(0.0f, mat.values[3]), verbose);
		}
		{ // value constructor
			const Mat2f mat(3.1415f);
			Assertv(mat.equals(3.1415f, 0.0f, 0.0f, 3.1415f), verbose);
			Assertv(Float::equals(3.1415f, mat.values[0]), verbose);
			Assertv(Float::equals(0.0f, mat.values[1]), verbose);
			Assertv(Float::equals(0.0f, mat.values[2]), verbose);
			Assertv(Float::equals(3.1415f, mat.values[3]), verbose);
		}
		{ // values constructor
			const Mat2f mat(3.1415f, 0.6734f, 3.45f, 0.44f);
			Assertv(mat.equals(3.1415f, 0.6734f, 3.45f, 0.44f), verbose);
			Assertv(Float::equals(3.1415f, mat.values[0]), verbose);
			Assertv(Float::equals(0.6734f, mat.values[1]), verbose);
			Assertv(Float::equals(3.45f, mat.values[2]), verbose);
			Assertv(Float::equals(0.44f, mat.values[3]), verbose);
		}
		{ // copy constructor
			const Mat2f mat(3.1415f, 0.6734f, 3.45f, 0.44f);
			Assertv(mat.equals(3.1415f, 0.6734f, 3.45f, 0.44f), verbose);
			Assertv(Float::equals(3.1415f, mat.values[0]), verbose);
			Assertv(Float::equals(0.6734f, mat.values[1]), verbose);
			Assertv(Float::equals(3.45f, mat.values[2]), verbose);
			Assertv(Float::equals(0.44f, mat.values[3]), verbose);
			const Mat2f mat1(mat);
			Assertv(mat1.equals(3.1415f, 0.6734f, 3.45f, 0.44f), verbose);
			Assertv(Float::equals(3.1415f, mat1.values[0]), verbose);
			Assertv(Float::equals(0.6734f, mat1.values[1]), verbose);
			Assertv(Float::equals(3.45f, mat1.values[2]), verbose);
			Assertv(Float::equals(0.44f, mat1.values[3]), verbose);
			const Mat2f mat2 = mat;
			Assertv(mat2.equals(3.1415f, 0.6734f, 3.45f, 0.44f), verbose);
			Assertv(Float::equals(3.1415f, mat2.values[0]), verbose);
			Assertv(Float::equals(0.6734f, mat2.values[1]), verbose);
			Assertv(Float::equals(3.45f, mat2.values[2]), verbose);
			Assertv(Float::equals(0.44f, mat2.values[3]), verbose);
			const Mat2f mat3(Mat2d(1.3, 3.45, 1.2222, 0.33333));
			Assertv(mat3.equals(1.3f, 3.45f, 1.2222f, 0.33333f, 0.000001), verbose);
		}
	}
	{ // square bracket operators
		const Mat2f mat(3.1415f, 0.6734f, 3.45f, 0.44f);
		Assertv(mat.equals(3.1415f, 0.6734f, 3.45f, 0.44f), verbose);
		Assertv(Float::equals(3.1415f, mat[0][0]), verbose);
		Assertv(Float::equals(0.6734f, mat[0][1]), verbose);
		Assertv(Float::equals(3.45f, mat[1][0]), verbose);
		Assertv(Float::equals(0.44f, mat[1][1]), verbose);
	}
	{ // equality operators
		Assertv(Mat2f::Zero == 0.0f, verbose);
		Assertv(Mat2f::filled(1.0f) == 1.0f, verbose);
		Assertv(Mat2f::Zero == Mat2f::Zero, verbose);
		Assertv(Mat2f::Identity == Mat2f::Identity, verbose);
		Assertv(!(Mat2f::Zero != 0.0f), verbose);
		Assertv(!(Mat2f::filled(1.0f) != 1.0f), verbose);
		Assertv(!(Mat2f::Zero != Mat2f::Zero), verbose);
		Assertv(!(Mat2f::Identity != Mat2f::Identity), verbose);
		Mat2f mat(3.1415f, 0.6734f, 3.45f, 0.44f), mat2(3.1415f, 0.6734f, 1.2345f, 0.987654f);
		Assertv(mat.equals(3.1415f, 0.6734f, 3.45f, 0.44f), verbose);
		Assertv(mat.equals(mat), verbose);
		Assertv(!mat.equals(3.1415f), verbose);
		Assertv(!mat.equals(3.45f), verbose);
		Assertv(!mat.equals(mat2), verbose);
		Assertv(!mat.notEquals(3.1415f, 0.6734f, 3.45f, 0.44f), verbose);
		Assertv(!mat.notEquals(mat), verbose);
		Assertv(mat.notEquals(3.1415f), verbose);
		Assertv(mat.notEquals(3.45f), verbose);
		Assertv(mat.notEquals(mat2), verbose);
	}
	{ // arthimetic operators
		{ // scalar addition
			const float lval_0 = 12.344f, lval_1 = 131.04f, lval_2 = 0.4555f, lval_3 = 23000.45f;
			const float rval_0 = 10023.54f, rval_1 = 45.323f, rval_2 = 1.233f, rval_3 = 0.5f;
			const Mat2f lmat(lval_0, lval_1, lval_2, lval_3);
			const Mat2f rmat(rval_0, rval_1, rval_2, rval_3);
			Assertv(lmat.equals(lval_0, lval_1, lval_2, lval_3), verbose);
			Assertv(rmat.equals(rval_0, rval_1, rval_2, rval_3), verbose);
			Mat2f mat = lmat + rmat;
			Assertv(mat.equals(lval_0 + rval_0, lval_1 + rval_1, lval_2 + rval_2, lval_3 + rval_3), verbose);
			
			mat = lmat + rval_0;
			Assertv(mat.equals(lval_0 + rval_0, lval_1 + rval_0, lval_2 + rval_0, lval_3 + rval_0), verbose);

			mat = lmat;
			Assertv(mat.equals(lval_0, lval_1, lval_2, lval_3), verbose);
			mat += rmat;
			Assertv(mat.equals(lval_0 + rval_0, lval_1 + rval_1, lval_2 + rval_2, lval_3 + rval_3), verbose);

			mat = lmat;
			Assertv(mat.equals(lval_0, lval_1, lval_2, lval_3), verbose);
			mat += rval_1;
			Assertv(mat.equals(lval_0 + rval_1, lval_1 + rval_1, lval_2 + rval_1, lval_3 + rval_1), verbose);
		}
		{ // scalar subtraction
			const float lval_0 = 12.344f, lval_1 = 131.04f, lval_2 = 0.4555f, lval_3 = 23000.45f;
			const float rval_0 = 10023.54f, rval_1 = 45.323f, rval_2 = 1.233f, rval_3 = 0.5f;
			const Mat2f lmat(lval_0, lval_1, lval_2, lval_3);
			const Mat2f rmat(rval_0, rval_1, rval_2, rval_3);
			Assertv(lmat.equals(lval_0, lval_1, lval_2, lval_3), verbose);
			Assertv(rmat.equals(rval_0, rval_1, rval_2, rval_3), verbose);
			Mat2f mat = lmat - rmat;
			Assertv(mat.equals(lval_0 - rval_0, lval_1 - rval_1, lval_2 - rval_2, lval_3 - rval_3), verbose);
			
			mat = lmat - rval_0;
			Assertv(mat.equals(lval_0 - rval_0, lval_1 - rval_0, lval_2 - rval_0, lval_3 - rval_0), verbose);

			mat = lmat;
			Assertv(mat.equals(lval_0, lval_1, lval_2, lval_3), verbose);
			mat -= rmat;
			Assertv(mat.equals(lval_0 - rval_0, lval_1 - rval_1, lval_2 - rval_2, lval_3 - rval_3), verbose);

			mat = lmat;
			Assertv(mat.equals(lval_0, lval_1, lval_2, lval_3), verbose);
			mat -= rval_1;
			Assertv(mat.equals(lval_0 - rval_1, lval_1 - rval_1, lval_2 - rval_1, lval_3 - rval_1), verbose);
		}
		{ // scalar multiplication
			const float lval_0 = 12.344f, lval_1 = 131.04f, lval_2 = 0.4555f, lval_3 = 23000.45f;
			const float rval_0 = 10023.54f, rval_1 = 45.323f, rval_2 = 1.233f, rval_3 = 0.5f;
			const Mat2f lmat(lval_0, lval_1, lval_2, lval_3);
			const Mat2f rmat(rval_0, rval_1, rval_2, rval_3);
			Assertv(lmat.equals(lval_0, lval_1, lval_2, lval_3), verbose);
			Assertv(rmat.equals(rval_0, rval_1, rval_2, rval_3), verbose);
			Mat2f mat = lmat.scMul(rmat);
			Assertv(mat.equals(lval_0 * rval_0, lval_1 * rval_1, lval_2 * rval_2, lval_3 * rval_3), verbose);
			
			mat = lmat * rval_0;
			Assertv(mat.equals(lval_0 * rval_0, lval_1 * rval_0, lval_2 * rval_0, lval_3 * rval_0), verbose);

			mat = lmat;
			Assertv(mat.equals(lval_0, lval_1, lval_2, lval_3), verbose);
			mat = mat.scMul(rmat);
			Assertv(mat.equals(lval_0 * rval_0, lval_1 * rval_1, lval_2 * rval_2, lval_3 * rval_3), verbose);

			mat = lmat;
			Assertv(mat.equals(lval_0, lval_1, lval_2, lval_3), verbose);
			mat *= rval_1;
			Assertv(mat.equals(lval_0 * rval_1, lval_1 * rval_1, lval_2 * rval_1, lval_3 * rval_1), verbose);
		}
		{ // scalar division
			const float lval_0 = 12.344f, lval_1 = 131.04f, lval_2 = 0.4555f, lval_3 = 23000.45f;
			const float rval_0 = 10023.54f, rval_1 = 45.323f, rval_2 = 1.233f, rval_3 = 0.5f;
			const Mat2f lmat(lval_0, lval_1, lval_2, lval_3);
			const Mat2f rmat(rval_0, rval_1, rval_2, rval_3);
			Assertv(lmat.equals(lval_0, lval_1, lval_2, lval_3), verbose);
			Assertv(rmat.equals(rval_0, rval_1, rval_2, rval_3), verbose);
			Mat2f mat = lmat.scDiv(rmat);
			Assertv(mat.equals(lval_0 / rval_0, lval_1 / rval_1, lval_2 / rval_2, lval_3 / rval_3), verbose);
			
			mat = lmat / rval_0;
			Assertv(mat.equals(lval_0 / rval_0, lval_1 / rval_0, lval_2 / rval_0, lval_3 / rval_0), verbose);

			mat = lmat;
			Assertv(mat.equals(lval_0, lval_1, lval_2, lval_3), verbose);
			mat = mat.scDiv(rmat);
			Assertv(mat.equals(lval_0 / rval_0, lval_1 / rval_1, lval_2 / rval_2, lval_3 / rval_3), verbose);

			mat = lmat;
			Assertv(mat.equals(lval_0, lval_1, lval_2, lval_3), verbose);
			mat /= rval_1;
			Assertv(mat.equals(lval_0 / rval_1, lval_1 / rval_1, lval_2 / rval_1, lval_3 / rval_1), verbose);
		}
		{ // matrix multiplication
			const float lval_0 = 12.344f, lval_1 = 13.04f, lval_2 = 0.4555f, lval_3 = 23.45f;
			const float rval_0 = 13.54f, rval_1 = 45.323f, rval_2 = 1.233f, rval_3 = 0.5f;
			const Mat2f lmat(lval_0, lval_1, lval_2, lval_3);
			const Mat2f rmat(rval_0, rval_1, rval_2, rval_3);
			Assertv(lmat.equals(lval_0, lval_1, lval_2, lval_3), verbose);
			Assertv(rmat.equals(rval_0, rval_1, rval_2, rval_3), verbose);
			const Mat2f pmat = lmat * rmat;
			Assertv(pmat.equals(lval_0*rval_0+lval_2*rval_1, lval_1*rval_0+lval_3*rval_1, lval_0*rval_2+lval_2*rval_3, lval_1*rval_2+lval_3*rval_3), verbose);
			Assertv(pmat.notEquals(rval_0*lval_0+rval_2*lval_1, rval_1*lval_0+rval_3*lval_1, rval_0*lval_2+rval_2*lval_3, rval_1*lval_2+rval_3*lval_3), verbose);
			const Mat2f p2mat = rmat * lmat;
			Assertv(p2mat.equals(rval_0*lval_0+rval_2*lval_1, rval_1*lval_0+rval_3*lval_1, rval_0*lval_2+rval_2*lval_3, rval_1*lval_2+rval_3*lval_3), verbose);
			Assertv(p2mat.notEquals(lval_0*rval_0+lval_2*rval_1, lval_1*rval_0+lval_3*rval_1, lval_0*rval_2+lval_2*rval_3, lval_1*rval_2+lval_3*rval_3), verbose);
		}
		{ // matrix division
			const float lval_0 = 12.344f, lval_1 = 131.04f, lval_2 = 0.4555f, lval_3 = 23000.45f;
			const float rval_0 = 10023.54f, rval_1 = 45.323f, rval_2 = 1.233f, rval_3 = 0.5f;
			const Mat2f lmat(lval_0, lval_1, lval_2, lval_3);
			const Mat2f rmat(rval_0, rval_1, rval_2, rval_3);
			Assertv(lmat.equals(lval_0, lval_1, lval_2, lval_3), verbose);
			Assertv(rmat.equals(rval_0, rval_1, rval_2, rval_3), verbose);
			const Mat2f mat = lmat / rmat;
			const Mat2f rimat = rmat.inverse();
			const float ival_0 = rimat.values[0], ival_1 = rimat.values[1], ival_2 = rimat.values[2], ival_3 = rimat.values[3];
			Assertv(mat.equals(lval_0*ival_0+lval_2*ival_1, lval_1*ival_0+lval_3*ival_1, lval_0*ival_2+lval_2*ival_3, lval_1*ival_2+lval_3*ival_3), verbose);
		}
		{ // matrix - vector multiplication
			const Mat2f mat(3.0f, 1.344f, 0.44f, 12220.5f);
			const Vec2f vec(3.4f, 0.455f);
			Assertv((mat * vec).equals(3.0f * vec.x + 0.44f * vec.y, 1.344f * vec.x + 12220.5f * vec.y, 0.0001f), verbose);
			const Vec2d vecd(4.5, 99.9);
			Assertv((mat * vecd).equals(3.0f * vecd.x + 0.44f * vecd.y, 1.344f * vecd.x + 12220.5f * vecd.y, 0.000001), verbose);
		}
	}
	{ // at
		{
			const Mat2f mat(3.0f, 1.344f, 0.44f, 12220.5f);
			Assertv(Float::equals(mat.at(0, 0), 3.0f), verbose);
			Assertv(Float::equals(mat.at(0, 1), 1.344f), verbose);
			Assertv(Float::equals(mat.at(1, 0), 0.44f), verbose);
			Assertv(Float::equals(mat.at(1, 1), 12220.5f), verbose);
		}
		{
			Mat2f::Default = Mat2f::Identity;
			Mat2f mat;
			Assertv(mat.equals(Mat2f::Identity), verbose);
			Assertv(Float::equals((mat.at(0, 0) = 3.0f), 3.0f), verbose);
			Assertv(Float::equals((mat.at(0, 1) = 1.344f), 1.344f), verbose);
			Assertv(Float::equals((mat.at(1, 0) = 0.44f), 0.44f), verbose);
			Assertv(Float::equals((mat.at(1, 1) = 12220.5f), 12220.5f), verbose);
			Assertv(mat.equals(3.0f, 1.344f, 0.44f, 12220.5f), verbose);
		}
	}
	{ // set values
		Mat2f mat(0);
		Assertv(mat.equals(Mat2f::Zero), verbose);
		Assertv(&mat == &(mat.set(3.0f, 1.344f, 0.44f, 12220.5f)), verbose);
		Assertv(Float::equals(mat.at(0, 0), 3.0f), verbose);
		Assertv(Float::equals(mat.at(0, 1), 1.344f), verbose);
		Assertv(Float::equals(mat.at(1, 0), 0.44f), verbose);
		Assertv(Float::equals(mat.at(1, 1), 12220.5f), verbose);
	}
	{ // set from array
		Mat2f mat(0);
		Assertv(mat.equals(Mat2f::Zero), verbose);
		const float pv[] = {3.0f, 1.344f, 0.44f, 12220.5f};
		Assertv(&mat == &(mat.set(pv)), verbose);
		Assertv(Float::equals(mat.at(0, 0), 3.0f), verbose);
		Assertv(Float::equals(mat.at(0, 1), 1.344f), verbose);
		Assertv(Float::equals(mat.at(1, 0), 0.44f), verbose);
		Assertv(Float::equals(mat.at(1, 1), 12220.5f), verbose);
	}
	{ // setValue
		Mat2f mat(0);
		Assertv(mat.equals(Mat2f::Zero), verbose);
		mat.setValue(0, 0, 3.0f);
		Assertv(Float::equals(mat.at(0, 0), 3.0f), verbose);
		mat.setValue(0, 1, 1.344f);
		Assertv(Float::equals(mat.at(0, 1), 1.344f), verbose);
		mat.setValue(1, 0, 0.44f);
		Assertv(Float::equals(mat.at(1, 0), 0.44f), verbose);
		mat.setValue(1, 1, 12220.5f);
		Assertv(Float::equals(mat.at(0, 0), 3.0f), verbose);
		Assertv(Float::equals(mat.at(0, 1), 1.344f), verbose);
		Assertv(Float::equals(mat.at(1, 0), 0.44f), verbose);
		Assertv(Float::equals(mat.at(1, 1), 12220.5f), verbose);
	}
	{ // Nan
		{
			const Mat2f mat(0.0f, 0.0f/0.0f, 1.0f, 34.4f);
			Assertv(mat.equals(0.0f, 0.0f/0.0f, 1.0f, 34.4f), verbose);
			Assertv(mat.hasNan(), verbose);
			Assertv(!mat.isNan(), verbose);
		}
		{
			const Mat2f mat(0.0f/0.0f, 0.0f/0.0f, 0.0f/0.0f, 1.0f/0.0f);
			Assertv(mat.equals(0.0f/0.0f, 0.0f/0.0f, 0.0f/0.0f, 1.0f/0.0f), verbose);
			Assertv(mat.hasNan(), verbose);
			Assertv(!mat.isNan(), verbose);
		}
		{
			const Mat2f mat(0.0f/0.0f, 0.0f/0.0f, 0.0f/0.0f, 0.0f/0.0f);
			Assertv(mat.equals(0.0f/0.0f, 0.0f/0.0f, 0.0f/0.0f, 0.0f/0.0f), verbose);
			Assertv(mat.hasNan(), verbose);
			Assertv(mat.isNan(), verbose);
		}
	}
	{ // determinant
		Assertv(Mat2f(2,3,1,0).determinant() == -3.0f, verbose);
		Assertv(Mat2f(1,2,3,6).determinant() == 0.0f, verbose);
	}
	{ // transpose
		Assertv(Mat2f(1,2,3,4).transpose().equals(1,3,2,4), verbose);
		Assertv(Mat2f(1,0,-2,0).transpose().equals(1,-2,0,0), verbose);
	}
	{ // inverse
		{ // identity
			const Mat2f mat(1);
			const Mat2f imat = mat.inverse();
			Assertv(mat.isInvertible(), verbose);
			Assertv(imat.isInvertible(), verbose);
			Assertv(!imat.hasNan(), verbose);
			Assertv(!imat.isNan(), verbose);
			Assertv(mat.equals(Mat2f::Identity), verbose);
			Assertv(imat.equals(Mat2f::Identity), verbose);
			Assertv(mat.equals(imat), verbose);
			Assertv((mat*imat).equals(Mat2f::Identity), verbose);
		}
		{ // other values
			const Mat2f mat(12.344f, 131.04f, 0.4555f, 23000.45f);
			const Mat2f imat = mat.inverse();
			Assertv(mat.isInvertible(), verbose);
			Assertv(imat.isInvertible(), verbose);
			Assertv(!imat.hasNan(), verbose);
			Assertv(!imat.isNan(), verbose);
			Assertv((mat*imat).equals(Mat2f::Identity), verbose);
		}
		{ // non-invertible matrix values
			const Mat2f mat(4.0f, 0.0f, 4.0f, 0.0f);
			const Mat2f imat = mat.inverse();
			Assertv(!mat.isInvertible(), verbose);
			Assertv(!imat.isInvertible(), verbose);
			Assertv(imat.hasNan(), verbose);
			Assertv(imat.isNan(), verbose);
			if(!imat.hasNan())
			{
				Assertv((mat*imat).equals(Mat2f::Identity), verbose);
			}
		}
		{ // non-invertible matrix values
			const Mat2f mat(4.0f, 0.0f/0.0f, 4.0f, 0.0f);
			const Mat2f imat = mat.inverse();
			Assertv(!mat.isInvertible(), verbose);
			Assertv(!imat.isInvertible(), verbose);
			Assertv(mat.hasNan(), verbose);
			Assertv(!mat.isNan(), verbose);
			Assertv(imat.hasNan(), verbose);
			Assertv(imat.isNan(), verbose);
			if(!imat.hasNan())
			{
				Assertv((mat*imat).equals(Mat2f::Identity), verbose);
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