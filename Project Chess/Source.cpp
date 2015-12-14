#include "Pipe.h"
#include <iostream>
#include <thread>

using namespace std;
void main()
{
	Pipe p;
	if (!p.connect())
	{
		cout << "Failed to connect to graphics." << endl;
		p.close();
		return;
	}
	
	char msgToGraphics[1024];
	// TODO: send the board to graphics
	strcpy_s(msgToGraphics, "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1");
	
	p.sendMessageToGraphics(msgToGraphics);

	string msgFromGraphics;
	while ((msgFromGraphics = p.getMessageFromGraphics()) != "quit")
	{
		// TODO: handle the string the sent from graphics
		strcpy_s(msgToGraphics, "");
		p.sendMessageToGraphics(msgToGraphics);
		msgFromGraphics = p.getMessageFromGraphics();
	}

	p.close();
}