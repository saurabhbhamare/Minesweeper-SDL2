#pragma once
class Sound 
{
private: static Sound * instance; 
private: Sound ( ) { }

public:  
	static Sound*  ReturnInstance()
	{
		if (!instance)
		{
			instance = new Sound();
		}
		return instance; 
	}
	~Sound()
	{

	}
};