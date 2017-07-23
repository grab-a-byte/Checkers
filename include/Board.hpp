#pragma once
#ifndef _BOARD_
#define _BOARD__


#include "SDL.h"
#include "Square.hpp"
#include "LWindow.hpp"
#include "CheckerPiece.hpp"


class Board
{
public:
	Board();
	~Board();
	void render();
	Square* getSquare();
	Square* getSquare(int posY, int posX);


	

private:
	Square* board[64];

};

#endif // !_BOARD
