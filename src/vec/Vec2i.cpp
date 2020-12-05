#include <cmath>
#include <axl.math/vec/Vec2i.hpp>

namespace axl {
namespace math {


Vec2i::Vec2i(int _x, int _y) :
	x(_x), y(_y)
{}

Vec2i::Vec2i(const Vec2i& vec) :
	x(vec.x), y(vec.y)
{}


Vec2i Vec2i::operator+() const
{
	return Vec2i(x, y);
}

Vec2i Vec2i::operator-() const
{
	return Vec2i(-x, -y);
}

Vec2i Vec2i::operator+(const Vec2i& vec) const 
{
	return Vec2i(x + vec.x, y + vec.y);
}

Vec2i Vec2i::operator-(const Vec2i& vec) const 
{
	return Vec2i(x - vec.x, y - vec.y);
}

Vec2i Vec2i::operator*(const Vec2i& vec) const 
{
	return Vec2i(x * vec.x, y * vec.y);
}

Vec2i Vec2i::operator/(const Vec2i& vec) const 
{
	return Vec2i(x / vec.x, y / vec.y);
}

Vec2i Vec2i::operator+(int v) const 
{
	return Vec2i(x + v, y + v);
}

Vec2i Vec2i::operator-(int v) const 
{
	return Vec2i(x - v, y - v);
}

Vec2i Vec2i::operator*(int v) const 
{
	return Vec2i(x * v, y * v);
}

Vec2i Vec2i::operator/(int v) const 
{
	return Vec2i(x / v, y / v);
}

Vec2i& Vec2i::operator+=(const Vec2i& vec) 
{
	x = (x + vec.x); y = (y + vec.y); return *this;
}

Vec2i& Vec2i::operator-=(const Vec2i& vec) 
{
	x = (x - vec.x); y = (y - vec.y); return *this;
}

Vec2i& Vec2i::operator*=(const Vec2i& vec) 
{
	x = (x * vec.x); y = (y * vec.y); return *this;
}

Vec2i& Vec2i::operator/=(const Vec2i& vec) 
{
	x = (x / vec.x); y = (y / vec.y); return *this;
}

Vec2i& Vec2i::operator+=(int v) 
{
	x = x + v; y = y + v; return *this;
}

Vec2i& Vec2i::operator-=(int v) 
{
	x = x - v; y = y - v; return *this;
}

Vec2i& Vec2i::operator*=(int v) 
{
	x = x * v; y = y * v; return *this;
}

Vec2i& Vec2i::operator/=(int v) 
{
	x = x / v; y = y / v; return *this;
}

bool Vec2i::operator==(const Vec2i& vec) const 
{
	return (x == vec.x && y == vec.y);
}

bool Vec2i::operator!=(const Vec2i& vec) const 
{
	return (x != vec.x || y != vec.y);
}

bool Vec2i::operator==(const int& v) const 
{
	return (x == v && y == v);
}

bool Vec2i::operator!=(const int& v) const 
{
	return (x != v || y != v);
}


bool Vec2i::equals(const Vec2i& vec) const
{
	return (x == vec.x && y == vec.y);
}

bool Vec2i::notEquals(const Vec2i& vec) const
{
	return (x != vec.x || y != vec.y);
}

bool Vec2i::equals(int _x, int _y) const
{
	return (x == _x && y == _y);
}

bool Vec2i::notEquals(int _x, int _y) const
{
	return (x != _x || y != _y);
}


Vec2i& Vec2i::set(int value)
{
	this->x = (value);
	this->y = (value);
	return *this;
}

Vec2i& Vec2i::set(int _x, int _y)
{
	this->x = (_x);
	this->y = (_y);
	return *this;
}


Vec2i operator+(int v, const Vec2i& vec)
{
	return Vec2i(v + vec.x,v + vec.y);
}

Vec2i operator-(int v, const Vec2i& vec)
{
	return Vec2i(v - vec.x,v - vec.y);
}

Vec2i operator*(int v, const Vec2i& vec)
{
	return Vec2i(v * vec.x,v * vec.y);
}

Vec2i operator/(int v, const Vec2i& vec)
{
	return Vec2i(v / vec.x,v / vec.y);
}

Vec2i Vec2i::filled(int v) { return Vec2i(v, v); }
const Vec2i Vec2i::Zero(0, 0);
const Vec2i Vec2i::Identity(1, 1);
Vec2i Vec2i::Default(0, 0);

} // namespace axl.math
} // namespace axl
