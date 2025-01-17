#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include</Plus/MINESWEEPER/MINESWEEPER/headers/Render.h>
#include</Plus/MINESWEEPER/MINESWEEPER/headers/Constants.h>

Render::Render()
	:flags(FLAGS), renderLoop(true), pwindow(window)
{
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");
	renderer = SDL_CreateRenderer(pwindow, -1, SDL_RENDERER_ACCELERATED);
	sound = new Sound();
	ImportTextures();
	RenderLoop(window);
}
Render::~Render()
{
	FreeTextures();
	std::cout << "free textures" << std::endl;
}
void Render::RenderLoop(SDL_Window* window)
{
	//renderLoop = false;
	//InputEvents();
	while (renderLoop)
	{
		SDL_PollEvent(&event);    // window event

		SDL_RenderClear(renderer);
		for (int i = 0; i < TILE_ROWS; ++i)
		{
			for (int j = 0; j < TILE_ROWS; ++j)
			{
				RenderTiles(Tile::m_TileMatrix[i][j]);
				RenderTileNumberTextures(Tile::m_TileMatrix[i][j]);
			}
		}
		SDL_RenderPresent(renderer);

		if (event.type == SDL_QUIT)
		{
			renderLoop = false;
		}
		if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					int x, y;
					SDL_GetMouseState(&x, &y);
					int i = x / TILE_WIDTH;
					int j = y / TILE_HEIGHT;
					if (!Tile::m_TileMatrix[i][j].m_Revealed)	sound->PlayTileRevealSound();
					// if (!Tile::m_TileMatrix[i][j].m_Mine) sound->PlayExplosionSound();
					if (Tile::TileIndexValid(i, j) && !Tile::m_TileMatrix[i][j].m_Flagged)
					{
						TilesFloodFill(i, j);
					}
				}
				else if (event.button.button == SDL_BUTTON_RIGHT)
				{
					int x, y;
					SDL_GetMouseState(&x, &y);
					int i = x / TILE_WIDTH;
					int j = y / TILE_HEIGHT;

					if (Tile::TileIndexValid(i, j))
					{
						Tile::InsertFlag(i, j, flags);
						sound->PlayInsertFlagSound();
					}
				}
			}
		}
	}
}

void Render::RenderTiles(Tile tile)
{
	SDL_Rect destRect = { tile.i * TILE_WIDTH, tile.j * TILE_HEIGHT, 40, 40 };
	SDL_Texture* texture = p_TextureArray[TextureName::TEXTURE_UNKNOWN];

	if (!tile.m_Revealed && tile.m_Flagged)
	{
		SDL_RenderCopy(renderer, p_TextureArray[TextureName::TEXTURE_FLAG], NULL, &destRect);
		return;
	}
	else if (tile.m_Revealed)
	{
		if (tile.m_Mine)
		{
			texture = p_TextureArray[TextureName::TEXTURE_MINE];
		}
		else
		{
			texture = p_TextureArray[TextureName::TEXTURE_EMPTY];
		}
	}
	SDL_RenderCopy(renderer, texture, NULL, &destRect);
}

void Render::RevealTiles()
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	int i = x / TILE_WIDTH;
	int j = y / TILE_HEIGHT;
}
void Render::RenderTileNumberTextures(Tile tile)
{
	if (renderer == nullptr)
	{
		std::cout << "null renderer" << std::endl;
	}
	SDL_Texture* numberTexture = nullptr;
	SDL_Rect destRect = { tile.i * TILE_WIDTH, tile.j * TILE_HEIGHT, TILE_WIDTH,TILE_HEIGHT };

	if (tile.m_Revealed && tile.m_AdjacentMines > 0)
	{
		if (tile.m_AdjacentMines == 1)
		{
			numberTexture = p_TextureArray[TextureName::TEXTURE_NUM1];
		}
		else if (tile.m_AdjacentMines == 2)
		{
			numberTexture = p_TextureArray[TextureName::TEXTURE_NUM2];
		}
		else if (tile.m_AdjacentMines == 3)
		{
			numberTexture = p_TextureArray[TextureName::TEXTURE_NUM3];
		}
		else if (tile.m_AdjacentMines == 4)
		{
			numberTexture = p_TextureArray[TextureName::TEXTURE_NUM4];
		}
		else if (tile.m_AdjacentMines == 5)
		{
			numberTexture = p_TextureArray[TextureName::TEXTURE_NUM5];
		}
	}
	SDL_RenderCopy(renderer, numberTexture, NULL, &destRect);

}
void Render::TilesFloodFill(int i, int j)
{
	// Check if the index is valid and the tile is not revealed
	if (Tile::TileIndexValid(i, j) && !Tile::m_TileMatrix[i][j].m_Revealed)
	{
		//Reveal the tile
		Tile::m_TileMatrix[i][j].m_Revealed = true;

		// Check the number of adjacent mines
		int count = Tile::m_TileMatrix[i][j].m_AdjacentMines;

		//If the tile has zero adjacent mines, call FloodFill on its neighbors
		if (count == 0)
		{
			for (int i1 = -1; i1 <= 1; i1++)
			{
				for (int j1 = -1; j1 <= 1; j1++)
				{
					// Skip the current tile
					if (i1 == 0 && j1 == 0)
					{
						continue;
					}
					//	 Call FloodFill on the neighbor tile
					TilesFloodFill(i + i1, j + j1);
				}
			}
		}
	}
}

void Render::ImportTextures()
{
	p_TextureArray.push_back(IMG_LoadTexture(renderer, "C:/Plus/MINESWEEPER/Images/64x64/unknown_2_64x64.png"));                         // unknown
	p_TextureArray.push_back(IMG_LoadTexture(renderer, "C:/Plus/MINESWEEPER/Images/64x64/empty_64x64.png"));                                 // empty
	p_TextureArray.push_back(IMG_LoadTexture(renderer, "C:/Plus/MINESWEEPER/Images/64x64/bomb_exploded_64x64.png"));                 // exploded
	p_TextureArray.push_back(IMG_LoadTexture(renderer, "C:/Plus/MINESWEEPER/Images/64x64/1_64x64.png"));                                         // num 1
	p_TextureArray.push_back(IMG_LoadTexture(renderer, "C:/Plus/MINESWEEPER/Images/64x64/2_64x64.png"));                                         // num 2
	p_TextureArray.push_back(IMG_LoadTexture(renderer, "C:/Plus/MINESWEEPER/Images/64x64/3_64x64.png"));                                         // num 3
	p_TextureArray.push_back(IMG_LoadTexture(renderer, "C:/Plus/MINESWEEPER/Images/64x64/4_64x64.png"));                                         // num 4
	p_TextureArray.push_back(IMG_LoadTexture(renderer, "C:/Plus/MINESWEEPER/Images/64x64/5_64x64.png"));                                         // num 5
	p_TextureArray.push_back(IMG_LoadTexture(renderer, "C:/Plus/MINESWEEPER/Images/64x64/flag_1_64x64.png"));                                 // flag
}
void Render::FreeTextures()
{
	for (int i = 0; i < p_TextureArray.size(); i++)
	{
		SDL_DestroyTexture(p_TextureArray[i]);
	}
	p_TextureArray.clear();
}


