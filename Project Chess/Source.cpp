#include "Definitions.h"
#include "Pipe.h"
#include "ChessUtility.h"
#include "Board.h"
#include <iostream>

using namespace std;

void main() {
	Pipe p;
	if (!p.connect()) {
		cout << "Failed to connect to graphics." << endl;
		p.close();
		return;
	}

	Board board;
	Color currentPlayer = Color::White;

	char msgToGraphics[1024];
	strcpy_s(msgToGraphics, board.toString().c_str());
	strcat_s(msgToGraphics, "0");
	//strcpy_s(msgToGraphics, "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1");

	p.sendMessageToGraphics(msgToGraphics);

	string msgFromGraphics;
	while ((msgFromGraphics = p.getMessageFromGraphics()) != "quit") {
		Point src = ChessUtility::parsePoint(msgFromGraphics.substr(0, 2));
		Point dst = ChessUtility::parsePoint(msgFromGraphics.substr(2, 4));
		MoveCode result = ChessUtility::makeMove(board, currentPlayer, src, dst);
		msgToGraphics[0] = '0' + (int)result;
		msgToGraphics[1] = '\0';
		p.sendMessageToGraphics(msgToGraphics);
		if (result == MoveCode::Valid || result == MoveCode::Check)
			currentPlayer = (currentPlayer == Color::White) ? Color::Black : Color::White;
	}

	p.close();
}