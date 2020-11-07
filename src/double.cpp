#include <axl.math/double.hpp>
#include <cmath>
namespace axl {
namespace math {
namespace Double
{

const static double _pos_inf = 1.0 / 0.0;
const static double _neg_inf = -1.0 / 0.0;

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
	return std::isnan(n);
}
bool isFinite(double n)
{
	return std::isfinite(n);
}
bool isInfinite(double n)
{
	return std::isinf(n);
}
bool isPosInfinity(double n)
{
	return n == _pos_inf;
}
bool isNegInfinity(double n)
{
	return n == _neg_inf;
}

} // namespace Double
} // namespace axl.math
} // namespace axl
