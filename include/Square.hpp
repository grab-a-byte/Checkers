#pragma once
#ifndef _SQUARE_
#define _SQUARE_

#include "GameConsts.hpp"
#include "SDL_image.h"
#include "LWindow.hpp"
#include "CheckerPiece.hpp";

class Square
{
public:
	Square();
	~Square();
	void setColour(int colour);
	void setRenderX(int renderX);
	void setRenderY(int renderY);
	inline void setHasPiece(bool selection) { hasPiece = selection; }
	inline void setPiece(CheckerPiece* heldPiece) { this->heldPiece = heldPiece; }
	inline void setSelected(bool selection) { this->selected = selection; }
	inline void setPosX(int posX) { this->posX = posX; }
	inline void setPosY(int posY) { this->posY = posY; }

	inline int getRenderX() { return renderX; }
	inline int getRenderY() { return renderY; }
	inline bool getHasPiece() { return hasPiece; }
	inline CheckerPiece* getPiece() { return heldPiece; }
	inline bool getSelected() { return selected; }
	inline int getColour() { return colour; }
	inline int getPosX() { return posX; }
	inline int getPosY() { return posY; }
	inline int getPieceID() { return heldPiece->getID(); }
	inline int getPieceColour() { return  heldPiece->getColour(); }


	void render();

private:
	int colour;
	int posX;
	int posY;
	int renderX;
	int renderY;
	int ID;
	static int nextID;
	bool hasPiece;
	bool selected;
	CheckerPiece* heldPiece;
};

#endif //!_SQUARE_
