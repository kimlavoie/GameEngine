#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <string>
#include <SFML/Audio.hpp>
#include <map>

class SoundManager{
	std::map<std::string, sf::Sound> SoundMap;
	std::map<std::string, sf::SoundBuffer> BufferMap;
	std::map<std::string, sf::Music*> MusicMap;
	sf::Music* currentMusic;
	
	public:
		SoundManager(std::string, std::string);
		~SoundManager();
		
		void loadSoundFromFile(std::string);
		sf::Sound& getSound(std::string);
		bool loadSound(std::string, std::string);
		bool unloadSound(std::string);
		void playSound(std::string);
		
		void loadMusicFromFile(std::string);
		sf::Music* getMusic(std::string);
		bool loadMusic(std::string, std::string);
		bool unloadMusic(std::string);
		void playMusic();
		void playMusic(std::string);
		void stopMusic();
		
};

#endif