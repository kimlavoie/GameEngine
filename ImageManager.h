/**
 * \file	ImageManager.h
 * \author	Kim Lavoie
 * \date	9 décembre 2012
 * \details	Renferme la définition de la classe ImageManager
 */

#ifndef IMAGEMANAGER_H
#define IMAGEMANAGER_H

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class ImageManager {
	
	std::map<std::string , sf::Image> ImageMap; 

public:
	ImageManager(std::string);
	
	bool loadImage(std::string, std::string);
	bool unloadImage(std::string);
	sf::Image& getImage(std::string);
	void loadFromFile(std::string);
	
};

#endif
