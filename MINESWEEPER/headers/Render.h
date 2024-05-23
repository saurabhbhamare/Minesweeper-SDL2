#pragma once
#include<iostream>
#include<SDL.h>
#include<vector>
#include</Plus/MINESWEEPER/MINESWEEPER/headers/Tile.h>
#include</Plus/MINESWEEPER/MINESWEEPER/headers/Constants.h>
class Tile;

class Render
{
public: 

	int flags; 
	bool renderLoop;

	 std::vector<SDL_Texture*> p_TextureArray;
     SDL_Renderer* renderer; 
	 SDL_Rect destRect;	
	 SDL_Event event; 
	 SDL_Window* pwindow; 
	
   
	Render(SDL_Window*);
	~Render();
	void RenderTiles( Tile tile);
	void RenderTileNumberTextures(Tile tile );
	void ImportTextures();
	void RenderLoop(SDL_Window*);
	void TakeInputCoordinates();
	void TilesFloodFill(int i, int j);
	void RevealTiles();
	void RevealAdjacentTiles();
	void FreeTextures();
//	void InputEvents(bool renderLoop);

};
