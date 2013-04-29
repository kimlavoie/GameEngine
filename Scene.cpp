#include "Scene.h"
#include <iostream>

Scene::Scene(std::string imageInitPath, std::string spriteInitPath, std::string soundInitPath, std::string musicInitPath):	
			ImageMan(imageInitPath),
			SpriteMan(ImageMan, spriteInitPath),
			SoundMan(soundInitPath, musicInitPath)
																		
{
	SoundMan.playMusic("boss");
	SoundMan.playSound("heal");
	SoundMan.stopMusic();
	SoundMan.playMusic();
	
}

void Scene::drawScene(sf::RenderWindow& Fenetre){
	SpriteMan.drawSprites(Fenetre);
}