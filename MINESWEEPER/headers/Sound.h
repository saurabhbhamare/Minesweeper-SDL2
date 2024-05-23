#pragma once
#include<SDL_mixer.h>
class Sound
{
private:
	Mix_Chunk* m_TileRevealSound;
	Mix_Chunk* m_ExplosionSound;
	Mix_Chunk* m_InsertFlagSound; 
	//Mix_Chunk* m_
	//Mix_Chunk* tileReveal;
public:
	Sound();
	~Sound();

public:
	void PlayTileRevealSound();
	void PlayExplosionSound();
	void PlayInsertFlagSound(); 
	//void Play


};