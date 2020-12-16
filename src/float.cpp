#include <axl.math/float.hpp>
#include <cstdint>
#include <cmath>
namespace axl {
namespace math {
namespace Float
{

volatile float _zero = 0.0f, __zero = 0.0f;
const float Nan =  _zero / __zero;
const float PosInf = 1.0f / _zero;
const float NegInf = -PosInf;

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
	return *((int32_t*)&n) == *((int32_t*)&Nan);
}
bool isFinite(float n)
{
	return !isNan(n) && n != PosInf && n != NegInf;
}
bool isInfinite(float n)
{
	return !isNan(n) && (n == PosInf || n == NegInf);
}
bool isPosInfinity(float n)
{
	return !isNan(n) && n == PosInf;
}
bool isNegInfinity(float n)
{
	return !isNan(n) && n == NegInf;
}

} // namespace Float
} // namespace axl.math
} // namespace axl
