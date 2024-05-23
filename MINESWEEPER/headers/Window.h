#pragma once
#include <SDL.h> 
#include<excpt.h>

class Window
{
private:
	SDL_Window* window;

	int m_windowPositionX;
	int m_windowPositionY;
	int m_windowWidth;
	int m_windowHeight;
	SDL_Event event;

public:
	void InitializeSDL();

	Window();
	~Window();

	operator SDL_Window* ();

};