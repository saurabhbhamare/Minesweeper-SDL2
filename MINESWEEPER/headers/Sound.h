#pragma once
#include<SDL_mixer.h>
class Sound
{
private:
	Mix_Chunk* p_TileRevealSound;
	Mix_Chunk* p_ExplosionSound;
	Mix_Chunk* p_InsertFlagSound; 

public:
	Sound();
	~Sound();

public:
	void PlayTileRevealSound();
	void PlayExplosionSound();
	void PlayInsertFlagSound(); 
	//void Play


};