#include "SceneManager.h"

SceneManager SceneManager::SceneMan;

SceneManager::SceneManager(): currentScene(NULL)
{}

SceneManager& SceneManager::getSceneManager(){
	return SceneMan;
}

void SceneManager::drawCurrentScene(sf::RenderWindow& Fenetre){
	currentScene->drawScene(Fenetre);
}

void SceneManager::setFirstScene(Scene* scene){
	currentScene = scene;
}

void SceneManager::changeCurrentScene(Scene* newScene){
	delete currentScene;
	currentScene = newScene;
}