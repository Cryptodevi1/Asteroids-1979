#pragma once
#include "Global.h"
#include "GameObject.h"
#include "Ship.h"
#include "Asteroid.h"
#include <math.h>
#include <vector>

class Map
{
private:
	int spriteW;
	int spriteH;

	int row;
	int col;

public:
	int width;
	int height;

	Coordinate mapOffset;
	Coordinate mapTreshold;
	Coordinate playerTreshold;

	Ship* player;
	Sprite* background;
	Global* global;

public:
	Map(int width, int height);
	~Map();

	void update(float dt);
	void checkColision();
	void checkMapOutCollision(GameObject* object);
	void spawnAsteroids();
	void moveAround(GameObject* object);

	bool checkObjectsCollision(GameObject* object, GameObject* _object);

private:
	Coordinate getAsteroidPosition();
};