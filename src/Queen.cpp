#include "Queen.hpp"

int Queen::ID = QUEENPIECE;

Queen::Queen()
{

}

Queen::Queen(int colour)
{
	setColour(colour);
}

Queen::~Queen()
{

}

int Queen::getID()
{
	return ID;
}
int Queen::getColour()
{
	return colour;
}

void Queen::setColour(int colour)
{
	this->colour = colour;
}

bool Queen::checkMove(int x1, int y1, int x2, int y2)
{
	bool success = false;
	//Checks for both up and down

	if (x1 == x2 - 1 || x1 == x2 + 1)
	{
		if (y1 == y2 + 1 || y1 == y2 - 1)
		{
			success = true;
		}
	}

	return success; 
}

void Queen::render(int posX, int posY)
{

	//*-----------------------------------------------------------------------*//

	//function call wouldnt work :S SOS ASK CHRIS AS TO WHY
	//CheckerPiece::render(posX, posY);

	if (this != nullptr)
	{

		//Render colour
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

		//Render queen indicator 

		SDL_Rect queenRect = { posX + SCREENWIDTH / 24, posY + SCREENHEIGHT / 24, SCREENWIDTH / 24, SCREENHEIGHT / 24 };


		SDL_SetRenderDrawColor(LWindow::obtainInstance()->getRenderer(), 0x00, 0xFF, 0x00, 0xFF);

		SDL_RenderFillRect(LWindow::obtainInstance()->getRenderer(), &queenRect);
	}
}