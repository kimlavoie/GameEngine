#include "ImageManager.h"
#include <iostream>
#include <fstream>
#include <sstream>

ImageManager::ImageManager(std::string initFilePath)
{
	loadFromFile(initFilePath);
}
	
bool ImageManager::loadImage(std::string key, std::string path){
	sf::Image Image;
	
	if(!Image.LoadFromFile(path)){
		std::cerr << "Impossible de charger l'image" << std::endl;
		return false;
	}
	
	ImageMap[key] = Image;
	return true;		
}


bool ImageManager::unloadImage(std::string key){
	return ImageMap.erase(key);
}


sf::Image& ImageManager::getImage(std::string key){
	return ImageMap[key];
}

void ImageManager::loadFromFile(std::string filePath){
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
				loadImage(name, path);
			}
		}
	}
}
