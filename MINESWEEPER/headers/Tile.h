#pragma once
//#include</Plus/MINESWEEPER/MINESWEEPER/headers/Render.h>
#include</Plus/MINESWEEPER/MINESWEEPER/headers/Constants.h>
class Tile
{
public:
	int i;
	int j;
	int  m_AdjacentMines;
	bool m_Revealed;
	bool m_Mine;
	bool m_Flagged;

public:
	static Tile m_TileMatrix[TILE_ROWS][TILE_COLS];
	static bool TileIndexValid(int, int);
	static void InsertFlag(int i, int j, int& flags);
	static int TileNearMineCount(int i, int j);

public:
	Tile();

private:
	void TileInsertAdjacentNumbers();
	void InitializeTileMatrix();
	void PlaceMinesInTileMatrix();
	void PlaceAdjacentMineNumbersInTileMatrix();
};