#include "Map.h"

Map::Map(int width, int height)
{
	background = createSprite("data/background.png");
	getSpriteSize(background, spriteWidth, spriteHeight);
	this->width = width;
	this->height = height;
	col = (int)ceil((float)width / spriteWidth);
	row = (int)ceil((float)height / spriteHeight);
	shipTheshold.x = (float)width / 2;
	shipTheshold.y = (float)height / 2;

	int scrWidth;
	int scrHeight;
	getScreenSize(scrWidth, scrHeight);
	mapTreshold = Coordinate((float)(this->width-scrWidth)/2, (float)(this->height - scrHeight) / 2);
	mapOffset = mapOffset.sub(mapTreshold);


	global = Global::getInstance();
}

Map::~Map()
{
	destroySprite(background);
	delete this;
}

void Map::update(float dt)
{
	for (int i = 0; i < row; ++i) 
	{
		for (int j = 0; j < col; ++j)
		{
			int x = (spriteWidth * j) + (int)mapOffset.x;
			int y = (spriteWidth * i) + (int)mapOffset.y;
			drawSprite(background, x, y);
		}
	}
	checkColision();
	if (global->asteroidCount < global->asteroidSpawn / 3)
	{
		spawnAsteroids();
	}

	while (global->bullets.size() > global->maxBullet)
	{
		global->bullets.front()->needDestroy = true;
		global->bullets.pop();
	}

	moveAround(ship);
}

void Map::checkColision()
{
	for (auto obj : global->gameObjects)
	{
		checkMapOutCollision(obj);
		for (auto _obj : global->gameObjects)
		{
			if (obj == _obj)
			{
				continue;
			}

			if (checkObjectsCollision(obj, _obj))
			{
				obj->collision(_obj);
			}
		}
	}
}
bool Map::checkObjectsCollision(GameObject* object, GameObject* _object)
{
	Coordinate centerObjPosition = Coordinate(object->position.x + object->width / 2, object->position.y + object->height / 2);
	Coordinate center_ObjPosition = Coordinate(object->position.x + object->width / 2, object->position.y + object->height / 2);

	Coordinate distance = centerObjPosition.sub(center_ObjPosition);

	Coordinate fullDistance = Coordinate(object->width+_object->width/2, object->height + _object->height / 2);

	Coordinate fdistance = Coordinate(fmodf(distance.x, width - object->width / 2 - _object->width / 2), fmodf(distance.y, height - object->height / 2 - _object->height / 2));

	if (fabs(fdistance.x) < fullDistance.x && fabs(fdistance.y) < fullDistance.y)
	{
		return true;
	}

	return false;
}


void Map::checkMapOutCollision(GameObject* object)
{
	if (object->position.x < 0)
	{
		object->position.x += width - object->width;
	}
	if (object->position.y < 0)
	{
		object->position.y += height - object->height;
	}
	if (object->position.x + object->width > width)
	{
		object->position.x = fmod(object->position.x,width);
	}
	if (object->position.y + object->height > height)
	{
		object->position.y = fmod(object->position.y, height);
	}
}

void Map::spawnAsteroids()
{
	for (int i = 0; i < global->asteroidSpawn; ++i)
	{
		Coordinate positionAsteroid = getPosAsteroid();

		Coordinate directionAsteroid = Coordinate(positionAsteroid.x - ship->position.x, positionAsteroid.y - ship->position.y).getNormalize();

		Asteroid* _asteroid = new Asteroid((rand() % 2), positionAsteroid, directionAsteroid);

		for (auto obj : global->gameObjects)
		{
			while (obj->type == objectType::asteroid && checkObjectsCollision(_asteroid, obj))
				_asteroid->position = getPosAsteroid();
		}

		global->gameObjects.push_back(_asteroid);

	}
}

Coordinate Map::getPosAsteroid()
{
	Coordinate position = Coordinate(rand() % width + ship->position.x + shipTheshold.x, rand() % height + ship->position.y + shipTheshold.y);
	return position;
}

void Map::moveAround(GameObject* object)
{
	Coordinate centerObjPosition = Coordinate(object->position.x + object->width / 2, object->position.y + object->height / 2);

	int scrWidth = 0;
	int scrHeight = 0;
	getScreenSize(scrWidth, scrHeight);

	for (auto obj : global->gameObjects)
	{
		obj->relativePosition.x = obj->position.x + mapOffset.x;
		obj->relativePosition.y = obj->position.y + mapOffset.y;
	}

	mapOffset.x = -(object->position.x - scrWidth / 2);

	if (mapOffset.x > 0) mapOffset.x = 0;
	if (mapOffset.x < -mapTreshold.x * 2) mapOffset.x = -mapTreshold.x * 2;

	mapOffset.y = -(object->position.y - scrHeight / 2);

	if (mapOffset.y > 0) mapOffset.y = 0;
	if (mapOffset.y < -mapTreshold.y * 2) mapOffset.y = -mapTreshold.y * 2;
}
