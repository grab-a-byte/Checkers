#include "Board.hpp"
#include <iostream>

using namespace std;

void Board::render() 
{
	//Render each square

	for (int i = 0; i < 64; i++)
	{
		board[i]->render();
		//cout << i <<endl;
	}
}

Board::Board()
{

	//Creates a board of square and initialises Pieces on squares

	bool done = false;
	int colour = 0;
	int renderX = 0;
	int renderY = 0;
	int row = 0;

	for (int i = 0; i < 64; i++)
	{
		//create rows
		for (int c = 0; c < 8; c++)
		{
			renderY = (SCREENHEIGHT / 8) * row;
			//switching colour to alternate rows
			if (colour == 1)
			{
				colour = 0;
			}
			else colour = 1;

			//create columns
			for (int z = 0; z < 8; z++)
			{
				renderX = (SCREENWIDTH / 8) * z;

				board[i] = new Square();

				board[i]->setColour(colour);
				board[i]->setRenderX(renderX);
				board[i]->setRenderY(renderY);
				board[i]->setPosX(z + 1);
				board[i]->setPosY(c + 1);

				if (colour == BLACKSQUARE)
				{
					if (c == 0 || c == 1 || c == 6 || c == 7)
					{

						if (i < 32)
						{
							board[i]->setPiece(new CheckerPiece(BLUEPIECE));
							board[i]->setHasPiece(true);
						}
						else {
							board[i]->setPiece(new CheckerPiece(REDPIECE));
							board[i]->setHasPiece(true);
						}
					}
				}

				if (colour == WHITESQUARE)
				{
					colour = BLACKSQUARE;
				}
				else colour = WHITESQUARE;

				i++;
			}
			row++;
		}
	}
}

Board::~Board()
{
	//deletes each square

	for (int i = 0; i < 64; i++)
	{
		delete board[i];
		board[i] = nullptr;
	}
}


//Searches for square of unknown position based on mouse
Square* Board::getSquare()
{

	int mousePosX, mousePosY;
	SDL_GetMouseState(&mousePosX, &mousePosY);

	Square* returnedSquare = nullptr;
	for (int c = 0; c<64; c++)


		//Checks to see if mouse in in each square -----
	if (mousePosX > board[c]->getRenderX() && mousePosX < board[c]->getRenderX() + (SCREENWIDTH/8))
	{
		if (mousePosY > board[c]->getRenderY() && mousePosY < board[c]->getRenderY() + (SCREENHEIGHT / 8))
		{
			returnedSquare = board[c];
		}
	}
	//----

	return returnedSquare;
}



//searches for square of a known position
Square* Board::getSquare(int posX, int posY)
{
	for (int i = 0; i < 64; i++)
	{
		if (board[i]->getPosX() == posX)
		{
			if (board[i]->getPosY() == posY)
			{
				return board[i];
			}
		}
	}

	return nullptr;
}