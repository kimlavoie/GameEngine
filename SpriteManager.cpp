#include <iostream>
#include <fstream>
#include <sstream>
#include "SpriteManager.h"


SpriteManager::SpriteManager(ImageManager& ImageManager, std::string initFilePath) : ImageMan(ImageManager)
{
	
	loadFromFile(initFilePath);
	

}
	
bool SpriteManager::loadSprite(std::string key, std::string imageKey, float x, float y){
	
	sf::Sprite Sprite(ImageMan.getImage(imageKey), sf::Vector2f(x,y));
	SpriteMap[key] = Sprite;
	
	return true;
		
}


bool SpriteManager::unloadSprite(std::string key){
	SpriteMap.erase(key);										/** \todo Vérifier fuite de mémoire */
}


sf::Sprite& SpriteManager::getSprite(std::string key){
	return SpriteMap[key];
}

void SpriteManager::drawSprites(sf::RenderWindow& Fenetre){
	for(std::map<std::string , sf::Sprite>::iterator i = SpriteMap.begin(); i != SpriteMap.end() ; i++){
		Fenetre.Draw(i->second);
	}

}

void SpriteManager::loadFromFile(std::string filePath){
	std::string 		line, spriteName, imageName;
	int 				x, y;
	std::istringstream 	iss;
	std::ifstream 		File(filePath.c_str());
	
	if(!File)
		std::cout << "Impossible d'ouvrir le fichier" << std::endl;
	else{	
		while(std::getline(File, line)){
			if(line[0] != '#'){
				iss.clear();
				iss.str(line);
				
				iss >> spriteName;
				iss >> imageName;
				iss >> x;
				iss >> y;
				
				loadSprite(spriteName, imageName, x, y);
			}
		}
	}
}
