#include "SelectionManger.hpp"
#include <iostream>

using namespace std;

SelectionManager::SelectionManager()
{
}

SelectionManager::~SelectionManager()
{
}

void SelectionManager::changeSelection(Square* newSelection)
{

	//only allows you to slect white squares
	if (newSelection->getColour() == WHITESQUARE)
	{ }
	else
	{
		//sanity check
		if (selectedSquare != nullptr)
		{
			selectedSquare->setSelected(false);

		}

		if (!movePiece(newSelection))
		{
			selectedSquare = newSelection;
			selectedSquare->setSelected(true);
		}
		else { selectedSquare = nullptr; }
	}
}

bool SelectionManager::movePiece(Square* newSelection)
{
	bool moved = false;
	if (selectedSquare != nullptr)
	{
		if (selectedSquare->getHasPiece() == true && selectedSquare->getPieceColour() == PLAYERTURN)
		{

			//checking standard move (not taking)
			if (newSelection->getHasPiece() == false)
			{
				//makes piece check move based off square positions
				if (selectedSquare->getPiece()->checkMove(selectedSquare->getPosX(), selectedSquare->getPosY(), newSelection->getPosX(), newSelection->getPosY()) == true)
				{
					newSelection->setPiece(selectedSquare->getPiece());
					newSelection->setHasPiece(true);

					//Switches turns after every move
					selectedSquare->setHasPiece(false);
					if (PLAYERTURN == REDPIECE)
					{
						PLAYERTURN = BLUEPIECE;
					}
					else { PLAYERTURN = REDPIECE; }
					moved = true;
				}
				else { selectedSquare == nullptr; }
			}
		}
	}

	return moved;
}

bool SelectionManager::possibleTake(Square* newSelection)
{
	bool success = false;

	if (selectedSquare != nullptr)
		if (selectedSquare->getHasPiece())
		{
			{
				if (selectedSquare->getPieceID() == NORMALPIECE)
				{
					if (selectedSquare->getPieceColour() == REDPIECE)
					{
						if (newSelection->getPosY() + 2 == selectedSquare->getPosY())
						{
							if (newSelection->getPosX() - 2 == selectedSquare->getPosX() || newSelection->getPosX() + 2 == selectedSquare->getPosX());
							{
								success = true;
							}
						}
					}
					else if (selectedSquare->getPieceColour() == BLUEPIECE)
					{
						if (newSelection->getPosY() - 2 == selectedSquare->getPosY())
						{
							if (newSelection->getPosX() - 2 == selectedSquare->getPosX() || newSelection->getPosX() + 2 == selectedSquare->getPosX());
							{
								success = true;
							}
						}
					}
				}

				else if (selectedSquare->getPieceID() == QUEENPIECE)
				{
					if (newSelection->getPosY() + 2 == selectedSquare->getPosY() || newSelection->getPosY() - 2 == selectedSquare->getPosY())
					{
						if (newSelection->getPosX() - 2 == selectedSquare->getPosX() || newSelection->getPosX() + 2 == selectedSquare->getPosX());
						{
							success = true;
						}
					}
				}
			}
	}

	return success;
}


void SelectionManager::makeTake(Square* middleSquare, Square* newSelection)
{

	if (middleSquare == nullptr || newSelection== nullptr)
	{ }
	else if (selectedSquare->getPieceColour() == PLAYERTURN)
	{
		//deletes the middle piece that is to be taken
		middleSquare->setHasPiece(false);
		delete middleSquare->getPiece();
		middleSquare->setPiece(nullptr);

		//makes piece jump
		newSelection->setPiece(selectedSquare->getPiece());
		newSelection->setHasPiece(true);

		//removes selection of a square
		selectedSquare->setHasPiece(false);
		selectedSquare->setSelected(false);
		selectedSquare = nullptr;
	}
	else {}

}

bool SelectionManager::takingPrep(Square* newSelection, Board* gameBoard)
{
	bool success = false;

	if (newSelection->getHasPiece() == false)
	{
		//gets position of square to be jumped
		int moveX = -(newSelection->getPosX() - selectedSquare->getPosX()) / 2;
		int moveY = -(newSelection->getPosY() - selectedSquare->getPosY()) / 2;

		//gets pointer for middle square to be jumped
		Square* squareForJump = gameBoard->getSquare(newSelection->getPosX() + moveX, newSelection->getPosY() + moveY);

		if (squareForJump != nullptr)
		{
			//checks to see if square over is free
			if (squareForJump->getHasPiece() == true)
			{
				newSelection->setSelected(false);

				makeTake(squareForJump, newSelection);

				success = true;
			}
		}
	}
	return success;
}

void SelectionManager::checkForPromotion()
{

	if (selectedSquare != nullptr && selectedSquare->getHasPiece() == true)

	{
		if (selectedSquare->getPieceColour() == REDPIECE)
		{
			//Checks if at top of board
			if (selectedSquare->getPosY() == 1)
			{
				promotePiece(selectedSquare);
			}
		}
		//checks if at bottom of board
		else if (selectedSquare->getPieceColour() == BLUEPIECE)
		{
			if (selectedSquare->getPosY() == 8)
			{
				promotePiece(selectedSquare);
			}
		}
	}
}

void SelectionManager::promotePiece(Square* squareWithPiece)
{
		Queen* newQueen = new Queen(squareWithPiece->getPiece()->getColour());
		delete squareWithPiece->getPiece();
		squareWithPiece->setPiece(newQueen);
}