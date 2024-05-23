#include</Plus/MINESWEEPER/MINESWEEPER/headers/Sound.h>
#include<SDL_mixer.h>
#include<iostream>


Sound::Sound()
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) < 0)
	{
		std::cout << ("[FAILURE] - SDL_mixer could not be initialized! SDL Error: %s\n", Mix_GetError());
	}
	m_TileRevealSound = Mix_LoadWAV("C:/Plus/MINESWEEPER/Sounds/mixkit-Reveal.wav");
	m_InsertFlagSound = Mix_LoadWAV("C:/Plus/MINESWEEPER/Sounds/mixkit-Flag.wav");

	if (!m_TileRevealSound)
	{
		std::cout << "tile sound not imported" << std::endl;
	}
	if (!m_InsertFlagSound)
	{
		std::cout << "tile sound not imported" << std::endl;
	}
}
void Sound::PlayExplosionSound()
{
	Mix_HaltChannel(-1);
	Mix_PlayChannel(-1, m_ExplosionSound, 0);
	Mix_VolumeChunk(m_ExplosionSound, 5);
}
void Sound::PlayTileRevealSound()
{
	Mix_HaltChannel(-1);
	Mix_PlayChannel(-1, m_TileRevealSound, 0);
	Mix_VolumeChunk(m_TileRevealSound, 5);
}
void Sound::PlayInsertFlagSound()
{
	Mix_HaltChannel(-1);
	Mix_PlayChannel(-1, m_InsertFlagSound, 0);
	Mix_VolumeChunk(m_InsertFlagSound, 5);
}
Sound::~Sound()
{
	Mix_FreeChunk(m_TileRevealSound);
	Mix_FreeChunk(m_ExplosionSound);
	Mix_FreeChunk(m_InsertFlagSound);

	std::cout << "destructor called" << std::endl;
	Mix_Quit();
}
