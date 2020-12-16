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
	switch (sizeof(double))
	{
		case 2U:
			if(*((short*)&a) == *((short*)&b)) return true;
			break;
		case 4U:
			if(*((long*)&a) == *((long*)&b)) return true;
			break;
		case 8U:
			if(*((long long*)&a) == *((long long*)&b)) return true;
			break;
		default:
			{
				const register bool is_a_nan = isNan(a);
				const register bool is_b_nan = isNan(b);
				if(is_a_nan && is_b_nan) return true;
				else if(is_a_nan || is_b_nan) return false;
				const register bool is_a_inf = isInfinite(a);
				const register bool is_b_inf = isInfinite(b);
				if(is_a_inf && is_b_inf && (isPosInfinity(a) && isPosInfinity(b))) return true;
				else if(is_a_inf || is_b_inf) return false;
			}
			break;
	}
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
