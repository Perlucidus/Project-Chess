#pragma once
#include "ChessPiece.h"
#include <vector>
#include <iostream>

using namespace std;

class Rook : public ChessPiece
{
public:
	Rook(Point, Color);
	~Rook();
	vector<Point> getAvaliableMoves(Board*);
};