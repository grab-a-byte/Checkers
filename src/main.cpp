//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include "LWindow.hpp"
#include "GameConsts.hpp"
#include "Board.hpp"
#include "SelectionManger.hpp"
#include <iostream>

using namespace std;

//Screen dimension constants
//const int SCREEN_WIDTH = 800;
//const int SCREEN_HEIGHT = 800;

SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;

bool SdlInitHandler();

int main(int argc, char* args[])
{
	//own types variables
	Board *newBoard = new Board;
	SelectionManager* selectionManager = new SelectionManager;

	//init SDL and insantiate surface
	if (SdlInitHandler() == true)
	{
		SDL_FillRect(LWindow::obtainInstance()->getSurface(), NULL, SDL_MapRGB(LWindow::obtainInstance()->getSurface()->format, 0xFF, 0xFF, 0xFF));

		SDL_UpdateWindowSurface(LWindow::obtainInstance()->getWindow());
		
		//Main loop flag
		bool quit = false;

		//Event handler
		SDL_Event e;

		//While application is running
		while (!quit)
		{
			//Handle events on queue
			while (SDL_PollEvent(&e) != 0)
			{
				
				//User requests quit
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}

				if (e.type == SDL_MOUSEBUTTONDOWN)
				{
					Square* retrievedSquare = newBoard->getSquare();

					//sanity check
					if (nullptr == retrievedSquare)
					{
						cout << "NULL pointer error on square";
					}



					//checks pieces for promotion after every move

					//checking to see if pieces are going to collide when taking
					else if (selectionManager->possibleTake(retrievedSquare))
					{
						//preparing and taking piece
						selectionManager->takingPrep(retrievedSquare, newBoard);
						selectionManager->checkForPromotion();
					}

					else
					{
						//changes selection if not a taking move
						selectionManager->changeSelection(retrievedSquare);
						selectionManager->checkForPromotion();
					}
				}

			}

			//render out board
			newBoard->render();

			SDL_RenderPresent(LWindow::obtainInstance()->getRenderer());
		}

		//Clear screen
		SDL_SetRenderDrawColor(LWindow::obtainInstance()->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(LWindow::obtainInstance()->getRenderer());

	}

	//clearing up memory etc
	delete newBoard;
	delete selectionManager;
	SDL_Quit();

	return 0;
}

	

bool SdlInitHandler()
{
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) <0 )
	{
		success = false;
	}
	return success;
}



