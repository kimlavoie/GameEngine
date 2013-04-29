#ifndef SCENE_H
#define SCENE_H

#include "SpriteManager.h"
#include "ImageManager.h"
#include "SoundManager.h"
#include <string>

class Scene{
	ImageManager ImageMan;
	SpriteManager SpriteMan;
	SoundManager SoundMan;
	
	public:
		Scene(std::string, std::string, std::string, std::string);
		void drawScene(sf::RenderWindow& Fenetre);
};

#endif