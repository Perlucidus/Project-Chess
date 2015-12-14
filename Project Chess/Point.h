#pragma once

class Point
{
public:
	Point(int, int);
	~Point();
	int getX();
	int getY();
	void setX(int);
	void setY(int);
	void move(int, int);
	bool inBounds(int, int);
	bool equals(Point);
private:
	int _x;
	int _y;
};