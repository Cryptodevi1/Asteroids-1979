#pragma once
#include <vector>
#include <queue>

class GameObject;

//global func and variables for start/end game 
class Global
{
public:
	//создание сессии игры
	static Global* getInstance();

	std::vector<GameObject*> gameObjects;
	std::queue<GameObject*> bullets;

	int asteroidCount;
	int asteroidSpawn;
	int asteroidId;

	int maxBullet;
	int bulletId;

	int scrW;
	int scrH;

	int mapW;
	int mapH;

	//game reset
	void reset();

private:
	Global();
	~Global();
	static Global* instance;
};