#pragma once
#include<SDL.h>
#include<SDL_ttf.h>
class Text
{
private : 



public :
	TTF_Font* p_Font; 
	Text();
	void ShowGameOverScreenText(SDL_Renderer* renderer);
	void ShowGameWonText(SDL_Renderer* renderer);
	void ShowYouWonText();
	void Initializettf();
};