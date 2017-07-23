#include "CheckerPiece.hpp"

int CheckerPiece::ID = NORMALPIECE;

CheckerPiece::CheckerPiece()
{

}


CheckerPiece::CheckerPiece(int Colour):
	colour(Colour)
{
 
}

CheckerPiece::~CheckerPiece()
{

}

int CheckerPiece::getID()
{
	return ID;
}

int CheckerPiece::getColour()
{
	return colour;
}

bool CheckerPiece::checkMove(int x1, int y1, int x2, int y2)
{
	bool success = false;

	if (x1 == x2 - 1 || x1 == x2 + 1)
	{

		if (this->colour == REDPIECE)
		{
			//checks to see if it is a downward movement
			if (y1 == y2 + 1)
			{
				success = true;
			}
		}
		else if (this->colour == BLUEPIECE)
		{
			//checks to se if it is an upwards movement
			if (y1 == y2 - 1)
			{
				success = true;
			}
		}
	}

	return success;
}

void CheckerPiece::render(int posX, int posY)
{
	if (this != nullptr)
	{
		SDL_Rect pieceRect = { posX + SCREENWIDTH / 32, posY + SCREENHEIGHT / 32, SCREENWIDTH / 16, SCREENHEIGHT / 16 };

		if (colour == REDPIECE)
		{
			SDL_SetRenderDrawColor(LWindow::obtainInstance()->getRenderer(), 0xFF, 0x00, 0x00, 0xFF);
		}

		if (colour == BLUEPIECE)
		{
			SDL_SetRenderDrawColor(LWindow::obtainInstance()->getRenderer(), 0x00, 0x00, 0xFF, 0xFF);
		}
		SDL_RenderFillRect(LWindow::obtainInstance()->getRenderer(), &pieceRect);
	}
}