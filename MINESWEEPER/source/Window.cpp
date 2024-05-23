#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include</Plus/MINESWEEPER/MINESWEEPER/headers/WIndow.h>
#include</Plus/MINESWEEPER/MINESWEEPER/headers/Constants.h>

Window::Window() :m_windowPositionX(SDL_WINDOWPOS_CENTERED), m_windowPositionY(SDL_WINDOWPOS_CENTERED), m_windowWidth(SCREEN_WIDTH), m_windowHeight(SCREEN_HEIGHT)
{
	// Initializing SDL                               
	InitializeSDL();       
	//window creation 
	window = SDL_CreateWindow("MINESWEEPER", m_windowPositionX, m_windowPositionY, m_windowWidth, m_windowHeight, SDL_WINDOW_SHOWN);

	if (window == nullptr)
	{
		throw std::runtime_error("Unable to create window");
	}
}
void Window::InitializeSDL()
{
	//sdl initialization
	int imgFlags = IMG_INIT_PNG;
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		std::cout << "SDL is not Initialized \n";
	}
	if ((IMG_Init(imgFlags) & imgFlags) != imgFlags)
	{
		std::cerr << "SDL_image initialization failed: " << IMG_GetError() << std::endl;
	}
}
Window::~Window()
{
	SDL_DestroyWindow(window);
	SDL_Quit();
}
Window :: operator SDL_Window* () { return window; 
}

