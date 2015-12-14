#pragma once
#include "Definitions.h"
#include "ChessPiece.h"

class EmptyPiece : public ChessPiece
{
public:
	EmptyPiece(Color, Point);
	EmptyPiece(Color, int, int);
	~EmptyPiece();
};