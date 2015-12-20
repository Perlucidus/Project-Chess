#ifndef _POINT
#define _POINT

class Point {
public:
	Point(int, int);
	~Point();
	int getX();
	int getY();
	void move(Point);
	void move(int, int);
	bool inBounds(int, int);
	bool equals(Point);
private:
	int _x;
	int _y;
};

#endif
