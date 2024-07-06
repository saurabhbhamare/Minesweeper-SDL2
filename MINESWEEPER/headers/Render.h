#pragma once
#include<iostream>
#include<vector>
#include<SDL.h>
#include</Plus/MINESWEEPER/MINESWEEPER/headers/Window.h>
#include</Plus/MINESWEEPER/MINESWEEPER/headers/Tile.h>
#include</Plus/MINESWEEPER/MINESWEEPER/headers/Constants.h>
#include</Plus/MINESWEEPER/MINESWEEPER/headers/Sound.h>
#include</Plus/MINESWEEPER/MINESWEEPER/headers/Text.h>
class Tile;

class Render
{
private: 
	Window m_Window;
	bool m_RenderLoop;
	std::vector<SDL_Texture*> p_TextureArray;
	SDL_Renderer* p_Renderer = nullptr;
	//
	SDL_Rect m_DestinationRectangle;
	SDL_Event m_Event;
	SDL_Window* p_Window = nullptr;
//	Sound* p_Sound;
	ScreenState m_ScreenState;
	ScreenState m_CurrentState;
	Text text;
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
	void RenderGameOverScreenState();
	void FreeTextures();
	void RenderGameStates();
	void SwitchRenderState(ScreenState newState);
	void RenderGamePlayingState();
	void RenderGameWinningState();
};
