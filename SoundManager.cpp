#include "SoundManager.h"
#include <iostream>
#include <sstream>
#include <fstream>

SoundManager::SoundManager(std::string initSoundPath, std::string initMusicPath){
	loadSoundFromFile(initSoundPath);
	loadMusicFromFile(initMusicPath);
	currentMusic = NULL;
}

SoundManager::~SoundManager(){												
	std::map<std::string, sf::Music*>::iterator it;
	for(it = MusicMap.begin(); it != MusicMap.end(); it++){
		delete it->second;
	}
}

void SoundManager::loadSoundFromFile(std::string filePath){
	std::string 		line, name, path;
	std::istringstream 	iss;
	std::ifstream 		File(filePath.c_str());
	
	if(!File)
		std::cout << "Impossible d'ouvrir le fichier" << std::endl;
	else{	
		while(std::getline(File, line)){
			if(line[0] != '#'){
				iss.clear();
				iss.str(line);
				iss >> name;
				iss >> path;
				loadSound(name, path);
			}
		}
	}
}

sf::Sound& SoundManager::getSound(std::string soundName){
	return SoundMap[soundName];
}

bool SoundManager::loadSound(std::string soundName, std::string path){
	sf::Sound sound;
	sf::SoundBuffer buffer;
	
	if(!buffer.LoadFromFile(path)){
		std::cerr << "Cannot open the sound " << path << std::endl; 
		return false;
	}
	
	
	BufferMap[soundName] = buffer;
	sound.SetBuffer(BufferMap[soundName]);
	SoundMap[soundName] = sound;
	return true;
}

bool SoundManager::unloadSound(std::string name){
	if(SoundMap.erase(name) && BufferMap.erase(name)){
		return true;
	}
	else{
		return false;
	}
}

void SoundManager::playSound(std::string name){
	SoundMap[name].Play();
}


void SoundManager::loadMusicFromFile(std::string filePath){
	std::string 		line, name, path;
	std::istringstream 	iss;
	std::ifstream 		File(filePath.c_str());
	
	if(!File)
		std::cout << "Impossible d'ouvrir le fichier" << std::endl;
	else{	
		while(std::getline(File, line)){
			if(line[0] != '#'){
				iss.clear();
				iss.str(line);
				iss >> name;
				iss >> path;
				loadMusic(name, path);
			}
		}
	}
}

sf::Music* SoundManager::getMusic(std::string musicName){
	return MusicMap[musicName];
}

bool SoundManager::loadMusic(std::string name, std::string path){
	
	sf::Music* music = new sf::Music();
	if(!music->OpenFromFile(path)){
		std::cerr << "Can't open the music " << path << std::endl;
		return false;
	}
	
	MusicMap[name] = music;
	
	return true;
}

bool SoundManager::unloadMusic(std::string name){
	delete MusicMap[name];
	return MusicMap.erase(name);
}

void SoundManager::playMusic(){
	if(currentMusic){
		currentMusic->Play();
	}
}

void SoundManager::playMusic(std::string name){
	if(currentMusic){
		currentMusic->Stop();
	}
	currentMusic = MusicMap[name];
	currentMusic->Play();
}

void SoundManager::stopMusic(){
	if(currentMusic){
		currentMusic->Stop();
	}
}


