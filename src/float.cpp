#include <axl.math/float.hpp>
#include <cmath>
namespace axl {
namespace math {
namespace Float
{

const static float _pos_inf = 1.0f / 0.0f;
const static float _neg_inf = -1.0f / 0.0f;

bool equals(float a, float b, float epsilon)
{
	switch (sizeof(float))
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
bool isNan(float n)
{
	return std::isnan(n);
}
bool isFinite(float n)
{
	return std::isfinite(n);
}
bool isInfinite(float n)
{
	return std::isinf(n);
}
bool isPosInfinity(float n)
{
	return n == _pos_inf;
}
bool isNegInfinity(float n)
{
	return n == _neg_inf;
}

} // namespace Float
} // namespace axl.math
} // namespace axl