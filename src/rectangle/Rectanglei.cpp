#include <axl.math/rectangle/Rectanglei.hpp>

namespace axl {
namespace math {

Rectanglei::Rectanglei(int x1, int y1, int x2, int y2) :
	x1(x1), y1(y1), x2(x2), y2(y2)
{}
Rectanglei::Rectanglei(const Rectanglei& rectangle)
{
	this->x1 = rectangle.x1;
	this->y1 = rectangle.y1;
	this->x2 = rectangle.x2;
	this->y2 = rectangle.y2;
}
void Rectanglei::set(int x1, int y1, int x2, int y2)
{
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
}
bool Rectanglei::isOverlapping(const Rectanglei& rectangle) const
{
	return (x2 >= rectangle.x1 || rectangle.x2 >= x1) && (y2 >= rectangle.y1 || rectangle.y2 >= y1);
}

} // axl.math
} // axl
