#pragma once
//#include</Plus/MINESWEEPER/MINESWEEPER/headers/Render.h>
#include</Plus/MINESWEEPER/MINESWEEPER/headers/Constants.h>
#include</Plus/MINESWEEPER/MINESWEEPER/headers/Sound.h>
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

private:
	Sound* p_Sound;
public:
	Tile();

private:
	void InitializeTileMatrix();
	void PlaceMinesInTileMatrix();
	void TileInsertAdjacentNumbers();
	void PlaceAdjacentMineNumbersInTileMatrix();
};