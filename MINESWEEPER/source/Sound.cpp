#include</Plus/MINESWEEPER/MINESWEEPER/headers/Sound.h>
#include<SDL_mixer.h>
#include<iostream>

Sound Sound:: s_Instance;

Sound::Sound()
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) < 0)
	{
		std::cout << ("[FAILURE] - SDL_mixer could not be initialized! SDL Error: %s\n", Mix_GetError());
	}
	p_TileRevealSound = Mix_LoadWAV("C:/Plus/MINESWEEPER/Sounds/mixkit-Reveal.wav");
	p_InsertFlagSound = Mix_LoadWAV("C:/Plus/MINESWEEPER/Sounds/mixkit-Flag.wav");

	if (!p_TileRevealSound)
	{
		std::cout << "tile sound not imported" << std::endl;
	}
	if (!p_InsertFlagSound)
	{ 
		std::cout << "tile sound not imported" << std::endl;
	}
}
void Sound::PlayExplosionSound()
{
	Mix_HaltChannel(-1);
	Mix_PlayChannel(-1, p_ExplosionSound, 0);
	Mix_VolumeChunk(p_ExplosionSound, 5);
}
void Sound::PlayTileRevealSound()
{
	Mix_HaltChannel(-1);
	Mix_PlayChannel(-1, p_TileRevealSound, 0);
	Mix_VolumeChunk(p_TileRevealSound, 5);
}
void Sound::PlayInsertFlagSound()
{
	Mix_HaltChannel(-1);
	Mix_PlayChannel(-1, p_InsertFlagSound, 0);
	Mix_VolumeChunk(p_InsertFlagSound, 5);
}
Sound::~Sound()
{
	Mix_FreeChunk(p_TileRevealSound);
	Mix_FreeChunk(p_ExplosionSound);
	Mix_FreeChunk(p_InsertFlagSound);

	std::cout << "destructor called" << std::endl;
	Mix_Quit();
}

