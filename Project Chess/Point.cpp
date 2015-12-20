#include "Point.h"

Point::Point(int x, int y) : std::pair<int, int>(x, y) {}

bool Point::inBounds(int width, int height) const
{
	return first >= 0 && first < width && second >= 0 && second < height;
}
