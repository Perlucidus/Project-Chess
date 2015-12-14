#ifndef _DEFINITIONS
#define _DEFINITIONS

#define BOARD_WIDTH		8
#define BOARD_HEIGHT	8

typedef int index_t;
typedef int move_code_t;
typedef int color_t;
typedef char piece_type_t;

enum class MoveCode : move_code_t {
	Valid = 0,
	Check = 1,
	InvalidSource = 2,
	InvalidDestination = 3,
	InvalidCheck = 4,
	InvalidIndex = 5,
	InvalidMove = 6,
	MatchingPoints = 7,
	CheckMate = 8
};

enum class Color : color_t {
	White = 0,
	Black = 1,
	Transparent = 2,
};

enum class PieceType : piece_type_t {
	Empty = '#',
	Rook = 'r',
	Knight = 'n',
	Bishop = 'b',
	King = 'k',
	Queen = 'q',
	Pawn = 'p'
};

#endif
