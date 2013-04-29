-all: Test clean

Test: main.o GameEngine.o ImageManager.o SpriteManager.o SceneManager.o Scene.o
	g++ -g -o Test SoundManager.o ImageManager.o SpriteManager.o Scene.o SceneManager.o GameEngine.o main.o -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio

main.o: main.cpp GameEngine.o Scene.o
	g++ -c main.cpp -o main.o -I.
	
GameEngine.o: GameEngine.cpp SceneManager.o Scene.o
	g++ -c GameEngine.cpp -o GameEngine.o -I.
	
SceneManager.o: SceneManager.cpp Scene.o
	g++ -c SceneManager.cpp -o SceneManager.o -I.
	
Scene.o: Scene.cpp SpriteManager.o ImageManager.o SoundManager.o
	g++ -c Scene.cpp -o Scene.o -I.
	
SpriteManager.o: SpriteManager.cpp ImageManager.o
	g++ -c SpriteManager.cpp -o SpriteManager.o -I.
	
ImageManager.o: ImageManager.cpp
	g++ -c ImageManager.cpp -o ImageManager.o -I.

SoundManager.o: SoundManager.cpp
	g++ -c SoundManager.cpp -o SoundManager.o -I.

clean:
	rm *.o

