#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <SFML/Graphics.hpp>
#include "Scene.h"
#include <memory>

class SceneManager{
	static SceneManager SceneMan;
	Scene* currentScene;			
	
	public:
		static SceneManager& getSceneManager();
		void drawCurrentScene(sf::RenderWindow&);
		void setFirstScene(Scene*);
		void changeCurrentScene(Scene*);
	private:
		SceneManager();
};

#endif