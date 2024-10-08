#pragma once
#include<SDL.h>
#include<SDL_ttf.h>
class Text
{
public :
	TTF_Font* p_SmallFont = nullptr; 
	TTF_Font* p_LargeFont = nullptr;
	TTF_Font* p_MediumFont = nullptr; 
	Text();
	void ShowGameOverScreenText
	(SDL_Renderer* renderer);
    void ShowGameWonText(SDL_Renderer* renderer);
	void Initializettf();
	void ShowMainScreenText(SDL_Renderer* renderer);
};