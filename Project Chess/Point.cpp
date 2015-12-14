#include "Point.h"

Point::Point(int y, int x)
{
	_x = x;
	_y = y;
}

Point::~Point()
{

}

int Point::getX()
{
	return _x;
}

int Point::getY()
{
	return _y;
}

void Point::setX(int x)
{
	_x = x;
}

void Point::setY(int y)
{
	_y = y;
}

void Point::move(int y, int x)
{
	_y = y;
	_x = x;
}

bool Point::inBounds(int width, int heigth)
{
	return(_x >= 0 && _x <= width && _y >= 0 && _y <= heigth);
}

bool Point::equals(Point point)
{
	return(_x == point._x && _y == point._y);
}