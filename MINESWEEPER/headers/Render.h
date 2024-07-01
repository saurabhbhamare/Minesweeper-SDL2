#pragma once
#include<iostream>
#include<vector>
#include<SDL.h>
#include</Plus/MINESWEEPER/MINESWEEPER/headers/Window.h>
#include</Plus/MINESWEEPER/MINESWEEPER/headers/Tile.h>
#include</Plus/MINESWEEPER/MINESWEEPER/headers/Constants.h>
#include</Plus/MINESWEEPER/MINESWEEPER/headers/Sound.h>

class Tile;

class Render
{
private: 
	Window m_Window;
	bool m_RenderLoop;
	std::vector<SDL_Texture*> p_TextureArray;
	SDL_Renderer* p_Renderer;
	SDL_Rect m_DestRect;
	SDL_Event m_Event;
	SDL_Window* p_Window;
	Sound* p_Sound;
	ScreenState m_ScreenState;
	int flags;

public: 
	Render();
	~Render();
	void RenderLoop(SDL_Window*);

private: 
	void RenderTiles(Tile tile);
	void RenderTileNumberTextures(Tile tile);
	void ImportTextures();
	void TakeInputCoordinates();
	void TilesFloodFill(int i, int j);
	void RevealTiles();
	void RenderGameOverScreen();
	void FreeTextures();
	void RenderGameStates();
};
