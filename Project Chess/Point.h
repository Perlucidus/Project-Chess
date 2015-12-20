#ifndef _POINT
#define _POINT

#include <utility>

class Point : public std::pair<int, int> {
public:
	Point(int, int);
	bool inBounds(int, int) const;
};

#endif
