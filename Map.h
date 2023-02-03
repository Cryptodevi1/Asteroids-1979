#pragma once
#include "Gameobject.h"
#include "Global.h"
#include "Ship.h"
#include "Asteroid.h"
#include <math.h>
#include <vector>

class Map
{
private:
	Coordinate getPosAsteroid();
	int spriteWidth;
	int spriteHeight;

	int row;
	int col;
public:
	int width;
	int height;

	Ship* ship;
	Sprite* background;
	Global* global;

	Coordinate shipTheshold;
	Coordinate mapTreshold;
	Coordinate mapOffset;

	Map(int width, int height);
	~Map();

	void update(float dt);

	void checkColision();
	bool checkObjectsCollision(GameObject* object, GameObject* _object);
	void checkMapOutCollision(GameObject* object);

	void spawnAsteroids();
	void moveAround(GameObject* object);
};

