#pragma once

#ifndef _LWINDOW_
#define _LWINDOW_

#include "SDL.h"
#include "GameConsts.hpp"

class LWindow
{
public:
	static LWindow* obtainInstance();
	inline SDL_Window* getWindow() { return pWindow; }
	inline SDL_Renderer* getRenderer() { return pRenderer; }
	inline SDL_Surface* getSurface() { return pSurface; }

	void HandleEvent(SDL_Event& e);

protected:

private:
	static LWindow* pInstance;
	SDL_Window* pWindow;
	SDL_Renderer* pRenderer;
	SDL_Surface* pSurface;
	SDL_Texture* pTexture;

	void windowInit();


	//Make this a singleton
	LWindow();
	~LWindow();

};
#endif // !_LWINDOW_
