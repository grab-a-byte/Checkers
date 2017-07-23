#include"LWindow.hpp"
#include <iostream>

using namespace std;

LWindow* LWindow::pInstance = nullptr;

LWindow* LWindow::obtainInstance() {
	if (pInstance == nullptr)
	{
		pInstance = new LWindow;
	}
	return pInstance;
}



LWindow::LWindow()
{
	pWindow = nullptr;
	pSurface = nullptr;
	pRenderer = nullptr;

	windowInit();
}



LWindow::~LWindow()
{
	SDL_DestroyRenderer(pRenderer);
	SDL_DestroyWindow(pWindow);

	pRenderer = nullptr;
	pWindow = nullptr;
}

void LWindow::HandleEvent(SDL_Event& e)
{

}

void LWindow::windowInit()
{
	pWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREENWIDTH, SCREENHEIGHT, SDL_WINDOW_SHOWN);
	if (pWindow == nullptr)
	{
		cout << "Window could not be made";
	}
	else
	{
		pSurface = SDL_GetWindowSurface(pWindow);
		if (pSurface == nullptr)
		{
			cout << "No surface can be found";
		}

		else {
			pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		}
	}
}