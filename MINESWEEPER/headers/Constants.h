#pragma once

enum ScreenState
{
	PLAYING,
	PAUSE,
	WIN, 
	LOSE
};

#define MAXMINES 22
#define FLAGS 22
const int SCREEN_WIDTH = 480;
const int SCREEN_HEIGHT = 480;
const int TILE_ROWS = 12;
const int TILE_COLS = 12;
const int TILE_WIDTH = SCREEN_WIDTH / TILE_COLS;
const int TILE_HEIGHT = SCREEN_HEIGHT / TILE_ROWS;

