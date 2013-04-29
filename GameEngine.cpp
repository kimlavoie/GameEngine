/**
 * \file	GameEngine.cpp
 * \author	Kim Lavoie
 * \date	9 décembre 2012
 * \details	Renferme l'implémentation de la classe GameEngine
 */

#include <iostream>
#include "GameEngine.h"


GameEngine GameEngine::Game;

GameEngine::GameEngine() : 	App(sf::VideoMode(800,600,32), "GameEngine 1.0") , 
							Input(App.GetInput()),
							SceneMan(SceneManager::getSceneManager())							
{

}

GameEngine& GameEngine::getEngine(){
		
	return Game;
	
}

int GameEngine::run(Scene* firstScene){
	
	initialize(firstScene);
	
	while (App.IsOpened()){
		
		checkInput();
		update();
		draw();
		
	}
	
	shutdown();
	
	return 0;
	
}


void GameEngine::initialize(Scene* firstScene){
	//std::cout << "Game initializing ..." << std::endl;
	SceneMan.setFirstScene(firstScene);
}


void GameEngine::checkInput(){
	//std::cout << "Checking inputs ..." << std::endl;
	
	while (App.GetEvent(Event)){
		if (Event.Type == sf::Event::Closed)
			App.Close();
		
		if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Escape))
			App.Close();
	}
}

void GameEngine::update(){
	//std::cout << "Updating game status ..." << std::endl;
}


void GameEngine::draw(){
	//std::cout << "Drawing on the screen ..." << std::endl;
	
	App.Clear();
	
	SceneMan.drawCurrentScene(App);
	
	App.Display();
}


void GameEngine::shutdown(){
	//std::cout << "Shutting the game down ..." << std::endl;
}


