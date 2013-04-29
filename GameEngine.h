/**
 * \file	GameEngine.h
 * \author	Kim Lavoie
 * \date	9 décembre 2012
 * \details	Renferme la définition de la classe GameEngine
 */

#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <SFML/Graphics.hpp>
#include "SceneManager.h"
#include "Scene.h"

class GameEngine {

	static GameEngine Game;
	SceneManager& SceneMan;		
	sf::RenderWindow App;					
	sf::Event Event;						
	const sf::Input &Input;
	
public:
	static GameEngine& getEngine();			
	int run(Scene*);
	
private:
	GameEngine();

	void initialize(Scene*);
	void checkInput();
	void update();
	void draw();
	void shutdown();
	
};

#endif
