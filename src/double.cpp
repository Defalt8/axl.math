#include <axl.math/double.hpp>
#include <cstdint>
#include <cmath>
namespace axl {
namespace math {
namespace Double
{

volatile double _zero = 0.0, __zero = 0.0;
const double Nan = _zero / __zero;
const double PosInf = 1.0 / _zero;
const double NegInf = -PosInf;

bool equals(double a, double b, double epsilon)
{
	const bool is_a_nan = isNan(a);
	const bool is_b_nan = isNan(b);
	if(is_a_nan && is_b_nan) return true;
	else if(is_a_nan || is_b_nan) return false;
	return std::fabs(a - b) <= epsilon;
}
bool isNan(double n)
{
	return *((int64_t*)&n) == *((int64_t*)&Nan);
}
bool isFinite(double n)
{
	return !isNan(n) && n != PosInf && n != NegInf;
}
bool isInfinite(double n)
{
	return !isNan(n) && (n == PosInf || n == NegInf);
}
bool isPosInfinity(double n)
{
	return !isNan(n) && n == PosInf;
}
bool isNegInfinity(double n)
{
	return !isNan(n) && n == NegInf;
}

} // namespace Double
} // namespace axl.math
} // namespace axl
