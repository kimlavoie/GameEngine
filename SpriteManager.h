/**
 * \file	SpriteManager.h
 * \author	Kim Lavoie
 * \date	9 décembre 2012
 * \details	Renferme la définition de la classe SpriteManager
 */

#ifndef SPRITEMANAGER_H
#define SPRITEMANAGER_H

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include "ImageManager.h"

class SpriteManager {
	std::map<std::string , sf::Sprite> SpriteMap; 
	ImageManager& ImageMan;
	
public:
	SpriteManager(ImageManager&, std::string);
	
	bool loadSprite(std::string, std::string, float, float);		//key, imageKey, x, y
	bool unloadSprite(std::string);
	sf::Sprite& getSprite(std::string);
	void drawSprites(sf::RenderWindow&);
	void loadFromFile(std::string);
	
};

#endif

