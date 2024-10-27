#pragma once
#include <SDL.h> 
#include<excpt.h>

class Window
{
private:
	SDL_Window* window;

	int m_WindowPositionX;
	int m_WindowPositionY;
	int m_WindowWidth;
	int m_WindowHeight;
//	SDL_Event m_Event;

public:
	void InitializeSDL();

	Window();
	~Window();

	operator SDL_Window* ();

};