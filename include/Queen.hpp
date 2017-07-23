#pragma once
#include "CheckerPiece.hpp"
#include "GameConsts.hpp"

class Queen : public CheckerPiece
{
public:
	Queen();
	Queen(int colour);
	~Queen();
	bool checkMove(int x1, int y1, int x2, int y2) override;
	void setColour(int colour);
	int getID() override;
	int getColour() override;
	void render(int posX, int posY) override;


protected:
private:
	static int ID;
	int colour;
};