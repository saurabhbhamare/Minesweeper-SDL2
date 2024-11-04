#pragma once
#include<iostream>
#include<vector>
#include<SDL.h>
#include</Plus/MINESWEEPER/MINESWEEPER/headers/Window.h>
#include</Plus/MINESWEEPER/MINESWEEPER/headers/Tile.h>
#include</Plus/MINESWEEPER/MINESWEEPER/headers/Constants.h>
#include</Plus/MINESWEEPER/MINESWEEPER/headers/Sound.h>
#include</Plus/MINESWEEPER/MINESWEEPER/headers/Text.h>

class Render
{
private: 
	Window m_Window;
	bool m_RenderLoop;
	std::vector<SDL_Texture*> p_TextureArray;
	SDL_Renderer* p_Renderer = nullptr;
	SDL_Rect m_DestinationRectangle;
	SDL_Event m_Event;
	SDL_Window* p_Window = nullptr;
	ScreenState m_ScreenState;
	ScreenState m_CurrentState;
	Text text;
	int flags;
	int numOfTotalNonMineTiles = (TILE_COLS * TILE_HEIGHT) + (MAXMINES);
	int numOfOpenedTiles;

public: 
	Render();
	~Render();
	void RenderLoop(SDL_Window*);

private: 
	void ImportTextures();
	void RenderTiles(Tile tile);
	void RenderTileNumberTextures(Tile tile);
	void RenderGameMainScreenState();
	void RevealTiles();
	void TilesFloodFill(int i, int j); 
	void RenderGamePlayingState();
	void RenderGameWinningState();
	void RenderGameOverScreenState();
	void WinCondition();
	void QuitEverything();
	
	
	void FreeTextures();
};
