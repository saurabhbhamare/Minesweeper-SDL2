#pragma once

enum ScreenState
{
	MAIN,
	PLAYING,
	PAUSE,
	WIN,
	LOSE
};
enum  TextureName
{
	TEXTURE_UNKNOWN,
	TEXTURE_EMPTY,
	TEXTURE_MINE,
	TEXTURE_NUM1,
	TEXTURE_NUM2,
	TEXTURE_NUM3,
	TEXTURE_NUM4,
	TEXTURE_NUM5,
	TEXTURE_FLAG
};

#define MAXMINES 22
#define FLAGS 22
const int SCREEN_WIDTH = 480;
const int SCREEN_HEIGHT = 480;
const int TILE_ROWS = 12;
const int TILE_COLS = 12;
const int TILE_WIDTH = SCREEN_WIDTH / TILE_COLS;
const int TILE_HEIGHT = SCREEN_HEIGHT / TILE_ROWS;



// unknown
// empty
// exploded
// num 1
// num 2
// num 3
// num 4
// num 5
// flag

