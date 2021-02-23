#include <axl.math/rectangle/Rectangled.hpp>

namespace axl {
namespace math {

Rectangled::Rectangled(double x1, double y1, double x2, double y2) :
	x1(x1), y1(y1), x2(x2), y2(y2)
{}
Rectangled::Rectangled(const Rectangled& rectangle)
{
	this->x1 = rectangle.x1;
	this->y1 = rectangle.y1;
	this->x2 = rectangle.x2;
	this->y2 = rectangle.y2;
}
void Rectangled::set(double x1, double y1, double x2, double y2)
{
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
}
bool Rectangled::isOverlapping(const Rectangled& rectangle) const
{
	return (x2 >= rectangle.x1 || rectangle.x2 >= x1) && (y2 >= rectangle.y1 || rectangle.y2 >= y1);
}

} // axl.math
} // axl
