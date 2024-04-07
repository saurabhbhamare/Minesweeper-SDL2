#include<iostream>

#include</Plus/MINESWEEPER/MINESWEEPER/headers/Tile.h>
#include</Plus/MINESWEEPER/MINESWEEPER/headers/Render.h>
#include</Plus/MINESWEEPER/MINESWEEPER/headers/Constants.h>


Tile Tile:: m_TileMatrix[TILE_ROWS][TILE_COLS];

Tile::Tile()
{
	InitializeTileMatrix();
	PlaceMinesInTileMatrix();
	PlaceAdjacentMineNumbersInTileMatrix();
	
}
void Tile::InitializeTileMatrix()
{
		for (int i = 0; i < TILE_ROWS; i++)
	{
		for (int j = 0; j < TILE_ROWS; j++)
		{
			m_TileMatrix[i][j].i = i;
			m_TileMatrix[i][j].j = j;
			m_TileMatrix[i][j].m_Revealed = false;
			m_TileMatrix[i][j].m_Mine = false;
			m_TileMatrix[i][j].m_AdjacentMines = -1;
			m_TileMatrix[i][j].m_Flagged = false;
		}
	}
}
void Tile::PlaceMinesInTileMatrix()
{
	srand(time(NULL));

	int numOfMines = MAXMINES;
		while (numOfMines > 0)
	{
		int i = rand() % TILE_ROWS;
		int j = rand() % TILE_COLS;
		if (!m_TileMatrix[i][j].m_Mine)
		{
			m_TileMatrix[i][j].m_Mine = true;
			numOfMines--;
		}
	}
}
bool Tile::TileIndexValid(int i , int j)
{
	return  (i >= 0 && i < TILE_ROWS) && (j >= 0 && j < TILE_COLS);
}

void Tile:: InsertFlag(int i , int j, int&flags)
{
	
		if (m_TileMatrix[i][j].m_Revealed)
		{
			std::cout << " Tile Revealed" << std::endl;
			return;
		}
	if (!m_TileMatrix[i][j].m_Flagged && flags <= 0)
	{
		return;
	}
	m_TileMatrix[i][j].m_Flagged = !m_TileMatrix[i][j].m_Flagged;
	if (m_TileMatrix[i][j].m_Flagged)
	{
		flags--;
	}
	else
	{
		flags++;
	}
}
int Tile::TileNearMineCount(int  i , int j )
{
	int count = 0;
	//Count Near By Mines
	for (int i1 = -1; i1 <= 1; i1++)
	{
		for (int j1 = -1; j1 <= 1; j1++)
		{
			if (i1 == 0 && j1 == 0)
			{
				continue;
			}
			if (!Tile::TileIndexValid(i + i1, j + j1))
			{
				continue;
			}
			if (Tile::m_TileMatrix[i + i1][j + j1].m_Mine)
			{
				count++;
			}
		}
	}
	return count;
}
void Tile::PlaceAdjacentMineNumbersInTileMatrix()
{
	for (int i = 0; i < TILE_ROWS; i++)
	{
		for (int j = 0; j < TILE_ROWS; j++)
		{
			if (!Tile::m_TileMatrix[i][j].m_Mine)
			{
				m_TileMatrix[i][j].m_AdjacentMines = TileNearMineCount(i, j);
			}
		
		}
	}
}
 
