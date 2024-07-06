#include</Plus/MINESWEEPER/MINESWEEPER/headers/Text.h>
#include<iostream>
Text::Text()
{
	Initializettf ();
	p_Font = TTF_OpenFont("C:/Plus/MINESWEEPER/Fonts/Peepo/Peepo.ttf", 40);
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
	SDL_Surface* textSurface = TTF_RenderText_Solid(p_Font, "Game Over", textColor);
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