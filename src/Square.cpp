#include"Square.hpp"
#include<iostream>

using namespace std;

int Square::nextID = 12345;

Square::Square():
	ID(nextID)
{
	
}

Square::~Square()
{
}


void Square::setColour(int colour)
{
	this->colour = colour;
}

void Square::setRenderX(int renderX)
{
	this->renderX = renderX;
}

void Square::setRenderY(int renderY)
{
	this->renderY = renderY;
}

void Square::render()
{
	if (this == nullptr)
	{
		cout << "Render error on square";
	}

	else {

		SDL_Rect squareRect = { this->renderX, this->renderY, SCREENWIDTH / 8, SCREENHEIGHT / 8 };
		if (colour == BLACKSQUARE)
		{
			SDL_SetRenderDrawColor(LWindow::obtainInstance()->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
		}
		else if (colour == WHITESQUARE)
		{
			SDL_SetRenderDrawColor(LWindow::obtainInstance()->getRenderer(), 0x00, 0x00, 0x00, 0xFF);
		}

		else
		{
			cout << "Error in board colours";
		}

		if (selected == true)
		{
			SDL_SetRenderDrawColor(LWindow::obtainInstance()->getRenderer(), 0xFF, 0x00, 0xFF, 0xFF);
		}
		

		SDL_RenderFillRect(LWindow::obtainInstance()->getRenderer(), &squareRect);


		if (hasPiece == true)
		{
			heldPiece->render(renderX, renderY);
		}
	}
}