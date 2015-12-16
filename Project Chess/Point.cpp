#include "Point.h"

Point::Point(int x, int y) : _x(x), _y(y) {}

Point::~Point() {}

int Point::getX()
{
	return _x;
}

int Point::getY()
{
	return _y;
}

void Point::move(Point point)
{
	_x = point._x;
	_y = point._y;
}

void Point::move(int x, int y)
{
	_x = x;
	_y = y;
}

bool Point::inBounds(int width, int heigth)
{
	if (_x < 0 || _x >= width)
		return false;
	if (_y < 0 || _y >= width)
		return false;
	return true;
}

bool Point::equals(Point other)
{
	return _x == other._x && _y == other._y;
}
