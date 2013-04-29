/**
 * \file	main.cpp
 * \author	Kim Lavoie
 * \date	9 décembre 2012
 * \details	Point d'entrée du moteur de jeu
 * 
 */

#include <iostream>
#include "GameEngine.h"
#include "SoundManager.h"

int main(){

	GameEngine& Game = GameEngine::getEngine();
	Scene* firstScene = new Scene("Initialisations/Images.txt", 
									"Initialisations/Sprites.txt", 
									"Initialisations/Sounds.txt",
									"Initialisations/Music.txt");
	return Game.run(firstScene);
	
}
