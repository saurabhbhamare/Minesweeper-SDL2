#pragma once
#include<SDL_mixer.h>
#include<iostream>
class Sound
{
private:
	Sound();
	static Sound  s_Instance; 
	Mix_Chunk* p_TileRevealSound = nullptr;
	Mix_Chunk* p_ExplosionSound = nullptr;
	Mix_Chunk* p_InsertFlagSound = nullptr; 

public:
	  Sound(const Sound&) = delete;
	~Sound();
	static Sound& GetInstance()
	{
		return s_Instance; 
	} 
	void function()
	{
		std::cout << "get health" << std::endl;
	}

public:
	void PlayTileRevealSound();
	void PlayExplosionSound();
	void PlayInsertFlagSound(); 
};