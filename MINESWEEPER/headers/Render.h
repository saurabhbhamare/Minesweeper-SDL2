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
	Window window;
	int flags;
	bool renderLoop;
	std::vector<SDL_Texture*> p_TextureArray;
	SDL_Renderer* renderer;
	SDL_Rect destRect;
	SDL_Event event;
	SDL_Window* pwindow;
	Sound* sound;
	ScreenState screenState;

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
	//void RevealAdjacentTiles();
	void FreeTextures();
};
