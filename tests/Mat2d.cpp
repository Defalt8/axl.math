#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include "Assert.hpp"
#include "lib.hpp"
#include <axl.math/double.hpp>
#include <axl.math/Mat2d.hpp>
#include <axl.math/Mat2f.hpp>

double _fzero = 0.0;
const static double _fnan = _fzero / _fzero;

int main(int argc, char *argv[])
{
	bool verbose = argc > 1 && (0 == strcmp(argv[1], "-v") || 0 == strcmp(argv[1], "--verbose"));
	using namespace axl;
	using namespace axl::math;
	printf("axl.math - version %hu.%hu.%hu  %s %s\n", lib::VERSION.major, lib::VERSION.minor, lib::VERSION.patch, libType(lib::LIBRARY_TYPE), buildType(lib::BUILD_TYPE));
	puts("----------------------------------------");
	{ // static values
		Assertv(Double::equals(0.0, Mat2d::Zero.values[0]), verbose);
		Assertv(Double::equals(0.0, Mat2d::Zero.values[1]), verbose);
		Assertv(Double::equals(0.0, Mat2d::Zero.values[2]), verbose);
		Assertv(Double::equals(0.0, Mat2d::Zero.values[3]), verbose);
		Assertv(Double::equals(1.0, Mat2d::Identity.values[0]), verbose);
		Assertv(Double::equals(0.0, Mat2d::Identity.values[1]), verbose);
		Assertv(Double::equals(0.0, Mat2d::Identity.values[2]), verbose);
		Assertv(Double::equals(1.0, Mat2d::Identity.values[3]), verbose);
		Assertv(Mat2d::filled(4.0).equals(4.0, 4.0, 4.0, 4.0), verbose);
	}
	{ // constructors
		{ // default constructor
			const Mat2d mat;
			Assertv(Double::equals(0.0, mat.values[0]), verbose);
			Assertv(Double::equals(0.0, mat.values[1]), verbose);
			Assertv(Double::equals(0.0, mat.values[2]), verbose);
			Assertv(Double::equals(0.0, mat.values[3]), verbose);
		}
		{ // value constructor
			const Mat2d mat(3.1415);
			Assertv(mat.equals(3.1415, 0.0, 0.0, 3.1415), verbose);
			Assertv(Double::equals(3.1415, mat.values[0]), verbose);
			Assertv(Double::equals(0.0, mat.values[1]), verbose);
			Assertv(Double::equals(0.0, mat.values[2]), verbose);
			Assertv(Double::equals(3.1415, mat.values[3]), verbose);
		}
		{ // values constructor
			const Mat2d mat(3.1415, 0.6734, 3.45, 0.44);
			Assertv(mat.equals(3.1415, 0.6734, 3.45, 0.44), verbose);
			Assertv(Double::equals(3.1415, mat.values[0]), verbose);
			Assertv(Double::equals(0.6734, mat.values[1]), verbose);
			Assertv(Double::equals(3.45, mat.values[2]), verbose);
			Assertv(Double::equals(0.44, mat.values[3]), verbose);
		}
		{ // copy constructor
			const Mat2d mat(3.1415, 0.6734, 3.45, 0.44);
			Assertv(mat.equals(3.1415, 0.6734, 3.45, 0.44), verbose);
			Assertv(Double::equals(3.1415, mat.values[0]), verbose);
			Assertv(Double::equals(0.6734, mat.values[1]), verbose);
			Assertv(Double::equals(3.45, mat.values[2]), verbose);
			Assertv(Double::equals(0.44, mat.values[3]), verbose);
			const Mat2d mat1(mat);
			Assertv(mat1.equals(3.1415, 0.6734, 3.45, 0.44), verbose);
			Assertv(Double::equals(3.1415, mat1.values[0]), verbose);
			Assertv(Double::equals(0.6734, mat1.values[1]), verbose);
			Assertv(Double::equals(3.45, mat1.values[2]), verbose);
			Assertv(Double::equals(0.44, mat1.values[3]), verbose);
			const Mat2d mat2 = mat;
			Assertv(mat2.equals(3.1415, 0.6734, 3.45, 0.44), verbose);
			Assertv(Double::equals(3.1415, mat2.values[0]), verbose);
			Assertv(Double::equals(0.6734, mat2.values[1]), verbose);
			Assertv(Double::equals(3.45, mat2.values[2]), verbose);
			Assertv(Double::equals(0.44, mat2.values[3]), verbose);
			const Mat2d mat3(Mat2f(1.3f, 3.45f, 1.2222f, 0.33333f));
			Assertv(mat3.equals(1.3, 3.45, 1.2222, 0.33333, 0.000001), verbose);
		}
	}
	{ // square bracket operators
		const Mat2d mat(3.1415, 0.6734, 3.45, 0.44);
		Assertv(mat.equals(3.1415, 0.6734, 3.45, 0.44), verbose);
		Assertv(Double::equals(3.1415, mat[0][0]), verbose);
		Assertv(Double::equals(0.6734, mat[0][1]), verbose);
		Assertv(Double::equals(3.45, mat[1][0]), verbose);
		Assertv(Double::equals(0.44, mat[1][1]), verbose);
	}
	{ // equality operators
		Assertv(Mat2d::Zero == 0.0, verbose);
		Assertv(Mat2d::filled(1.0) == 1.0, verbose);
		Assertv(Mat2d::Zero == Mat2d::Zero, verbose);
		Assertv(Mat2d::Identity == Mat2d::Identity, verbose);
		Assertv(!(Mat2d::Zero != 0.0), verbose);
		Assertv(!(Mat2d::filled(1.0) != 1.0), verbose);
		Assertv(!(Mat2d::Zero != Mat2d::Zero), verbose);
		Assertv(!(Mat2d::Identity != Mat2d::Identity), verbose);
		Mat2d mat(3.1415, 0.6734, 3.45, 0.44), mat2(3.1415, 0.6734, 1.2345, 0.987654);
		Assertv(mat.equals(3.1415, 0.6734, 3.45, 0.44), verbose);
		Assertv(mat.equals(mat), verbose);
		Assertv(!mat.equals(3.1415), verbose);
		Assertv(!mat.equals(3.45), verbose);
		Assertv(!mat.equals(mat2), verbose);
		Assertv(!mat.notEquals(3.1415, 0.6734, 3.45, 0.44), verbose);
		Assertv(!mat.notEquals(mat), verbose);
		Assertv(mat.notEquals(3.1415), verbose);
		Assertv(mat.notEquals(3.45), verbose);
		Assertv(mat.notEquals(mat2), verbose);
	}
	{ // arthimetic operators
		{ // scalar addition
			const double lval_0 = 12.344, lval_1 = 131.04, lval_2 = 0.4555, lval_3 = 23000.45;
			const double rval_0 = 10023.54, rval_1 = 45.323, rval_2 = 1.233, rval_3 = 0.5;
			const Mat2d lmat(lval_0, lval_1, lval_2, lval_3);
			const Mat2d rmat(rval_0, rval_1, rval_2, rval_3);
			Assertv(lmat.equals(lval_0, lval_1, lval_2, lval_3), verbose);
			Assertv(rmat.equals(rval_0, rval_1, rval_2, rval_3), verbose);
			Mat2d mat = lmat + rmat;
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
			const double lval_0 = 12.344, lval_1 = 131.04, lval_2 = 0.4555, lval_3 = 23000.45;
			const double rval_0 = 10023.54, rval_1 = 45.323, rval_2 = 1.233, rval_3 = 0.5;
			const Mat2d lmat(lval_0, lval_1, lval_2, lval_3);
			const Mat2d rmat(rval_0, rval_1, rval_2, rval_3);
			Assertv(lmat.equals(lval_0, lval_1, lval_2, lval_3), verbose);
			Assertv(rmat.equals(rval_0, rval_1, rval_2, rval_3), verbose);
			Mat2d mat = lmat - rmat;
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
			const double lval_0 = 12.344, lval_1 = 131.04, lval_2 = 0.4555, lval_3 = 23000.45;
			const double rval_0 = 10023.54, rval_1 = 45.323, rval_2 = 1.233, rval_3 = 0.5;
			const Mat2d lmat(lval_0, lval_1, lval_2, lval_3);
			const Mat2d rmat(rval_0, rval_1, rval_2, rval_3);
			Assertv(lmat.equals(lval_0, lval_1, lval_2, lval_3), verbose);
			Assertv(rmat.equals(rval_0, rval_1, rval_2, rval_3), verbose);
			Mat2d mat = lmat.scMul(rmat);
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
			const double lval_0 = 12.344, lval_1 = 131.04, lval_2 = 0.4555, lval_3 = 23000.45;
			const double rval_0 = 10023.54, rval_1 = 45.323, rval_2 = 1.233, rval_3 = 0.5;
			const Mat2d lmat(lval_0, lval_1, lval_2, lval_3);
			const Mat2d rmat(rval_0, rval_1, rval_2, rval_3);
			Assertv(lmat.equals(lval_0, lval_1, lval_2, lval_3), verbose);
			Assertv(rmat.equals(rval_0, rval_1, rval_2, rval_3), verbose);
			Mat2d mat = lmat.scDiv(rmat);
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
			const double lval_0 = 12.344, lval_1 = 13.04, lval_2 = 0.4555, lval_3 = 23.45;
			const double rval_0 = 13.54, rval_1 = 45.323, rval_2 = 1.233, rval_3 = 0.5;
			const Mat2d lmat(lval_0, lval_1, lval_2, lval_3);
			const Mat2d rmat(rval_0, rval_1, rval_2, rval_3);
			Assertv(lmat.equals(lval_0, lval_1, lval_2, lval_3), verbose);
			Assertv(rmat.equals(rval_0, rval_1, rval_2, rval_3), verbose);
			const Mat2d pmat = lmat * rmat;
			Assertv(pmat.equals(lval_0*rval_0+lval_2*rval_1, lval_1*rval_0+lval_3*rval_1, lval_0*rval_2+lval_2*rval_3, lval_1*rval_2+lval_3*rval_3), verbose);
			Assertv(pmat.notEquals(rval_0*lval_0+rval_2*lval_1, rval_1*lval_0+rval_3*lval_1, rval_0*lval_2+rval_2*lval_3, rval_1*lval_2+rval_3*lval_3), verbose);
			const Mat2d p2mat = rmat * lmat;
			Assertv(p2mat.equals(rval_0*lval_0+rval_2*lval_1, rval_1*lval_0+rval_3*lval_1, rval_0*lval_2+rval_2*lval_3, rval_1*lval_2+rval_3*lval_3), verbose);
			Assertv(p2mat.notEquals(lval_0*rval_0+lval_2*rval_1, lval_1*rval_0+lval_3*rval_1, lval_0*rval_2+lval_2*rval_3, lval_1*rval_2+lval_3*rval_3), verbose);
		}
		{ // matrix division
			const double lval_0 = 12.344, lval_1 = 131.04, lval_2 = 0.4555, lval_3 = 23000.45;
			const double rval_0 = 10023.54, rval_1 = 45.323, rval_2 = 1.233, rval_3 = 0.5;
			const Mat2d lmat(lval_0, lval_1, lval_2, lval_3);
			const Mat2d rmat(rval_0, rval_1, rval_2, rval_3);
			Assertv(lmat.equals(lval_0, lval_1, lval_2, lval_3), verbose);
			Assertv(rmat.equals(rval_0, rval_1, rval_2, rval_3), verbose);
			const Mat2d mat = lmat / rmat;
			const Mat2d rimat = rmat.inverse();
			const double ival_0 = rimat.values[0], ival_1 = rimat.values[1], ival_2 = rimat.values[2], ival_3 = rimat.values[3];
			Assertv(mat.equals(lval_0*ival_0+lval_2*ival_1, lval_1*ival_0+lval_3*ival_1, lval_0*ival_2+lval_2*ival_3, lval_1*ival_2+lval_3*ival_3), verbose);
		}
		{ // matrix - vector multiplication
			const Mat2d mat(3.0, 1.344, 0.44, 12220.5);
			const Vec2d vec(3.4, 0.455);
			Assertv((mat * vec).equals(3.0 * vec.x + 0.44 * vec.y, 1.344 * vec.x + 12220.5 * vec.y, 0.000001), verbose);
			const Vec2f vecf(4.5, 99.9);
			Assertv((mat * vecf).equals(3.0 * vecf.x + 0.44 * vecf.y, 1.344 * vecf.x + 12220.5 * vecf.y, 0.0001f), verbose);
		}
	}
	{ // at
		{
			const Mat2d mat(3.0, 1.344, 0.44, 12220.5);
			Assertv(Double::equals(mat.at(0, 0), 3.0), verbose);
			Assertv(Double::equals(mat.at(0, 1), 1.344), verbose);
			Assertv(Double::equals(mat.at(1, 0), 0.44), verbose);
			Assertv(Double::equals(mat.at(1, 1), 12220.5), verbose);
		}
		{
			Mat2d::Default = Mat2d::Identity;
			Mat2d mat;
			Assertv(mat.equals(Mat2d::Identity), verbose);
			Assertv(Double::equals((mat.at(0, 0) = 3.0), 3.0), verbose);
			Assertv(Double::equals((mat.at(0, 1) = 1.344), 1.344), verbose);
			Assertv(Double::equals((mat.at(1, 0) = 0.44), 0.44), verbose);
			Assertv(Double::equals((mat.at(1, 1) = 12220.5), 12220.5), verbose);
			Assertv(mat.equals(3.0, 1.344, 0.44, 12220.5), verbose);
		}
	}
	{ // set values
		Mat2d mat(0);
		Assertv(mat.equals(Mat2d::Zero), verbose);
		Assertv(&mat == &(mat.set(3.0, 1.344, 0.44, 12220.5)), verbose);
		Assertv(Double::equals(mat.at(0, 0), 3.0), verbose);
		Assertv(Double::equals(mat.at(0, 1), 1.344), verbose);
		Assertv(Double::equals(mat.at(1, 0), 0.44), verbose);
		Assertv(Double::equals(mat.at(1, 1), 12220.5), verbose);
	}
	{ // set from array
		Mat2d mat(0);
		Assertv(mat.equals(Mat2d::Zero), verbose);
		const double pv[] = {3.0, 1.344, 0.44, 12220.5};
		Assertv(&mat == &(mat.set(pv)), verbose);
		Assertv(Double::equals(mat.at(0, 0), 3.0), verbose);
		Assertv(Double::equals(mat.at(0, 1), 1.344), verbose);
		Assertv(Double::equals(mat.at(1, 0), 0.44), verbose);
		Assertv(Double::equals(mat.at(1, 1), 12220.5), verbose);
	}
	{ // setValue
		Mat2d mat(0);
		Assertv(mat.equals(Mat2d::Zero), verbose);
		mat.setValue(0, 0, 3.0);
		Assertv(Double::equals(mat.at(0, 0), 3.0), verbose);
		mat.setValue(0, 1, 1.344);
		Assertv(Double::equals(mat.at(0, 1), 1.344), verbose);
		mat.setValue(1, 0, 0.44);
		Assertv(Double::equals(mat.at(1, 0), 0.44), verbose);
		mat.setValue(1, 1, 12220.5);
		Assertv(Double::equals(mat.at(0, 0), 3.0), verbose);
		Assertv(Double::equals(mat.at(0, 1), 1.344), verbose);
		Assertv(Double::equals(mat.at(1, 0), 0.44), verbose);
		Assertv(Double::equals(mat.at(1, 1), 12220.5), verbose);
	}
	{ // Nan
		{
			const Mat2d mat(0.0, 0.0/0.0, 1.0, 34.4);
			Assertv(mat.equals(0.0, 0.0/0.0, 1.0, 34.4), verbose);
			Assertv(mat.hasNan(), verbose);
			Assertv(!mat.isNan(), verbose);
		}
		{
			const Mat2d mat(0.0/0.0, 0.0/0.0, 0.0/0.0, 1.0/0.0);
			Assertv(mat.equals(0.0/0.0, 0.0/0.0, 0.0/0.0, 1.0/0.0), verbose);
			Assertv(mat.hasNan(), verbose);
			Assertv(!mat.isNan(), verbose);
		}
		{
			const Mat2d mat(0.0/0.0, 0.0/0.0, 0.0/0.0, 0.0/0.0);
			Assertv(mat.equals(0.0/0.0, 0.0/0.0, 0.0/0.0, 0.0/0.0), verbose);
			Assertv(mat.hasNan(), verbose);
			Assertv(mat.isNan(), verbose);
		}
	}
	{ // determinant
		Assertv(Mat2d(2,3,1,0).determinant() == -3.0, verbose);
		Assertv(Mat2d(1,2,3,6).determinant() == 0.0, verbose);
	}
	{ // transpose
		Assertv(Mat2d(1,2,3,4).transpose().equals(1,3,2,4), verbose);
		Assertv(Mat2d(1,0,-2,0).transpose().equals(1,-2,0,0), verbose);
	}
	{ // inverse
		{ // identity
			const Mat2d mat(1);
			const Mat2d imat = mat.inverse();
			Assertv(mat.isInvertible(), verbose);
			Assertv(imat.isInvertible(), verbose);
			Assertv(!imat.hasNan(), verbose);
			Assertv(!imat.isNan(), verbose);
			Assertv(mat.equals(Mat2d::Identity), verbose);
			Assertv(imat.equals(Mat2d::Identity), verbose);
			Assertv(mat.equals(imat), verbose);
			Assertv((mat*imat).equals(Mat2d::Identity), verbose);
		}
		{ // other values
			const Mat2d mat(12.344, 131.04, 0.4555, 23000.45);
			const Mat2d imat = mat.inverse();
			Assertv(mat.isInvertible(), verbose);
			Assertv(imat.isInvertible(), verbose);
			Assertv(!imat.hasNan(), verbose);
			Assertv(!imat.isNan(), verbose);
			Assertv((mat*imat).equals(Mat2d::Identity), verbose);
		}
		{ // non-invertible matrix values
			const Mat2d mat(4.0, 0.0, 4.0, 0.0);
			const Mat2d imat = mat.inverse();
			Assertv(!mat.isInvertible(), verbose);
			Assertv(!imat.isInvertible(), verbose);
			Assertv(imat.hasNan(), verbose);
			Assertv(imat.isNan(), verbose);
			if(!imat.hasNan())
			{
				Assertv((mat*imat).equals(Mat2d::Identity), verbose);
			}
		}
		{ // non-invertible matrix values
			const Mat2d mat(4.0, 0.0/0.0, 4.0, 0.0);
			const Mat2d imat = mat.inverse();
			Assertv(!mat.isInvertible(), verbose);
			Assertv(!imat.isInvertible(), verbose);
			Assertv(mat.hasNan(), verbose);
			Assertv(!mat.isNan(), verbose);
			Assertv(imat.hasNan(), verbose);
			Assertv(imat.isNan(), verbose);
			if(!imat.hasNan())
			{
				Assertv((mat*imat).equals(Mat2d::Identity), verbose);
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