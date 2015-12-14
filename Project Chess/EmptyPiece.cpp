#include "EmptyPiece.h"

EmptyPiece::EmptyPiece(Color c, Point p) : ChessPiece(p, c, PieceType::Empty){}

EmptyPiece::EmptyPiece(Color c, int x, int y) : ChessPiece(x, y, c, PieceType::Empty){}

EmptyPiece::~EmptyPiece(){}