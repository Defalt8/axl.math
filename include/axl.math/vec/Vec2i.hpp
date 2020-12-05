#pragma once
#include "../lib.hpp"

namespace axl {
namespace math {

class AXLMATHCXXAPI Vec2i
{
	public:
		Vec2i(int x, int y);
		Vec2i(const Vec2i& vec = Default);
	public:
		Vec2i operator+() const;
		Vec2i operator-() const;
		Vec2i operator+(const Vec2i& vec) const;
		Vec2i operator-(const Vec2i& vec) const;
		Vec2i operator*(const Vec2i& vec) const;
		Vec2i operator/(const Vec2i& vec) const;
		Vec2i operator+(int v) const;
		Vec2i operator-(int v) const;
		Vec2i operator*(int v) const;
		Vec2i operator/(int v) const;
		Vec2i& operator+=(const Vec2i& vec);
		Vec2i& operator-=(const Vec2i& vec);
		Vec2i& operator*=(const Vec2i& vec);
		Vec2i& operator/=(const Vec2i& vec);
		Vec2i& operator+=(int v);
		Vec2i& operator-=(int v);
		Vec2i& operator*=(int v);
		Vec2i& operator/=(int v);
		bool operator==(const Vec2i& vec) const;
		bool operator!=(const Vec2i& vec) const;
		bool operator==(const int& v) const;
		bool operator!=(const int& v) const;
	public:
		bool equals(const Vec2i& vec) const;
		bool notEquals(const Vec2i& vec) const;
		bool equals(int x, int y) const;
		bool notEquals(int x, int y) const;
	public:
		Vec2i& set(int value);
		Vec2i& set(int x, int y);
	public:
		static Vec2i filled(int v);
		const static Vec2i Zero;
		const static Vec2i Identity;
		static Vec2i Default;
	public:
		int x, y;
};

Vec2i operator+(int v, const Vec2i& vec);
Vec2i operator-(int v, const Vec2i& vec);
Vec2i operator*(int v, const Vec2i& vec);
Vec2i operator/(int v, const Vec2i& vec);

} // namespace axl.math
} // namespace axl
