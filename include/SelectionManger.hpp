#pragma once
#include "Square.hpp"
#include "GameConsts.hpp"
#include "CheckerPiece.hpp"
#include "Queen.hpp"
#include "Board.hpp"

class SelectionManager
{
public:
	SelectionManager();
	~SelectionManager();

	void changeSelection(Square* newSelection);
	inline bool hasSquare() { if (selectedSquare == nullptr) { return false; } else { return true; } }
	inline bool selectedSquareHasPiece() { return selectedSquare->getHasPiece(); }
	bool takingPrep(Square* newSelection, Board* gameBoard);
	bool possibleTake(Square* newSelection);
	void makeTake(Square* middleSquare, Square* newSelection);
	void checkForPromotion();
	void promotePiece(Square* squareWithPiece);

private:
	int mousePosX;
	int mousePosY;

	bool movePiece(Square* newSelection);

	Square* selectedSquare;
};
