#include <axl.math/rectangle/Rectanglef.hpp>

namespace axl {
namespace math {

Rectanglef::Rectanglef(float x1, float y1, float x2, float y2) :
	x1(x1), y1(y1), x2(x2), y2(y2)
{}
Rectanglef::Rectanglef(const Rectanglef& rectangle)
{
	this->x1 = rectangle.x1;
	this->y1 = rectangle.y1;
	this->x2 = rectangle.x2;
	this->y2 = rectangle.y2;
}
void Rectanglef::set(float x1, float y1, float x2, float y2)
{
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
}
bool Rectanglef::isOverlapping(const Rectanglef& rectangle) const
{
	return (x2 >= rectangle.x1 || rectangle.x2 >= x1) && (y2 >= rectangle.y1 || rectangle.y2 >= y1);
}

} // axl.math
} // axl
