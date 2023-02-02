#include "Global.h"

Global* Global::instance = nullptr;

//constructor for global class
Global::Global()
{
	asteroidSpawn = 8;
	maxBullet = 5;

	scrW = 800;
	scrH = 600;

	mapW = 1200;
	mapH = 1200;
}

Global* Global::getInstance()
{
	if (instance == nullptr)
	{
		instance = new Global();
	}
	return instance;
}

void Global::reset()
{
	//clear scr and queue bullets
	this->gameObjects.clear();
	std::queue<GameObject*> empty;
	std::swap(this->bullets, empty);

	asteroidCount = 0;
	asteroidId = 0;
	bulletId = 0;
}

Global::~Global()
{
	reset();
	delete instance;
}