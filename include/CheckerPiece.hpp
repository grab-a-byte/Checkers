#pragma once
#ifndef _CHECKERPIECE_
#define _CHECKERPIECE_

#include "SDL_image.h"
#include "GameConsts.hpp"
#include "LWindow.hpp"

class CheckerPiece
{
public:
	CheckerPiece();
	CheckerPiece(int Colour);
	~CheckerPiece();

	virtual bool checkMove(int x1, int y1, int x2, int y2);
	virtual void render(int posX, int posY);
	virtual int getID();
	virtual int getColour();

protected:

private:
	int colour;
	static int ID;

};

#endif