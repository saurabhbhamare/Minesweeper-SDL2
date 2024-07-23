#include</Plus/MINESWEEPER/MINESWEEPER/headers/Text.h>
#include<iostream>
Text::Text()
{
	Initializettf ();
	p_SmallFont = TTF_OpenFont("C:/Plus/MINESWEEPER/Fonts/Doodle/JandaSnickerdoodleSerif.ttf", 25);
	p_MediumFont = TTF_OpenFont("C:/Plus/MINESWEEPER/Fonts/Doodle/JandaSnickerdoodleSerif.ttf", 40);
	p_LargeFont = TTF_OpenFont("C:/Plus/MINESWEEPER/Fonts/Doodle/JandaSnickerdoodleSerif.ttf", 60);
}
void Text::Initializettf()
{
	if (TTF_Init() != 0)
	{
		std::cout<<"TTF is not initialized"<<std::endl;	
	}
}
void Text::ShowGameOverScreenText(SDL_Renderer* renderer)
{
	SDL_Color textColor  = { 255, 255, 255 };
	SDL_Surface* textSurface = TTF_RenderText_Solid(p_MediumFont, " You Lose  ", textColor);
	if (!textSurface)
	{
		std::cout << "text surface is empty" << std::endl;
		return;
	}
	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	if (!textTexture)
	{
		std::cout << "text texture is empty" << std::endl;
	}
	SDL_Rect destinationRect = { 150, 200, textSurface->w, textSurface->h }; // Set the position and size
	SDL_RenderCopy(renderer, textTexture, nullptr, &destinationRect);
	SDL_FreeSurface(textSurface);
	SDL_DestroyTexture(textTexture);
}
void Text::ShowMainScreenText(SDL_Renderer* renderer)
{
	SDL_Color textColor = { 255, 255, 255 };
	SDL_Surface* textSurfaceGameName = TTF_RenderText_Solid(p_LargeFont, "MINESWEEPER", textColor);
	SDL_Surface* textSurfaceStartGame = TTF_RenderText_Solid(p_SmallFont, "Press [S] to Start the Game", textColor);
	SDL_Surface* textSurfaceQuitGame = TTF_RenderText_Solid(p_SmallFont, "Press [Q] to Quit", textColor);

	if (!textSurfaceGameName || !textSurfaceStartGame || !textSurfaceQuitGame)
	{
		std::cout << "one of your text surface is empty" << std::endl;
		return;
	}
	SDL_Texture* textTextureGameName = SDL_CreateTextureFromSurface(renderer, textSurfaceGameName);
	SDL_Texture* textTextureStartGame = SDL_CreateTextureFromSurface(renderer, textSurfaceStartGame);
	SDL_Texture* textTextureQuitGame = SDL_CreateTextureFromSurface(renderer, textSurfaceQuitGame);
	if (!textTextureGameName)
	{
		std::cout << "text texture is empty" << std::endl;
	}
	SDL_Rect destinationRectForGameName = { 65, 100, textSurfaceGameName->w, textSurfaceGameName->h }; // Set the position and size
	SDL_Rect destinationRectForStartGame = { 110, 240, textSurfaceStartGame->w, textSurfaceStartGame->h }; // Set the position and size
	SDL_Rect destinationRectForQuitGame = { 150, 300, textSurfaceQuitGame->w, textSurfaceQuitGame->h }; // Set the position and size

	SDL_RenderCopy(renderer, textTextureGameName, nullptr, &destinationRectForGameName);
	SDL_RenderCopy(renderer, textTextureStartGame, nullptr, &destinationRectForStartGame);
	SDL_RenderCopy(renderer, textTextureQuitGame, nullptr, &destinationRectForQuitGame);

	SDL_FreeSurface(textSurfaceGameName);
	SDL_FreeSurface(textSurfaceStartGame);
	SDL_FreeSurface(textSurfaceQuitGame);

	SDL_DestroyTexture(textTextureGameName);
	SDL_DestroyTexture(textTextureStartGame);
	SDL_DestroyTexture(textTextureQuitGame);
}
void Text::ShowGameWonText(SDL_Renderer * renderer)
{
	SDL_Color textColor = { 255, 255, 255 };
	SDL_Surface* textSurface = TTF_RenderText_Solid(p_MediumFont, " You Won :)  ", textColor);
	if (!textSurface)
	{
		std::cout << "text surface is empty" << std::endl;
		return;
	}
	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	if (!textTexture)
	{
		std::cout << "text texture is empty" << std::endl;
	}
	SDL_Rect destinationRect = { 150, 200, textSurface->w, textSurface->h }; // Set the position and size
	SDL_RenderCopy(renderer, textTexture, nullptr, &destinationRect);
	SDL_FreeSurface(textSurface);
	SDL_DestroyTexture(textTexture);
}