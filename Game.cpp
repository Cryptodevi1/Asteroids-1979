#include "Framework.h"
#include "Global.h"
#include "Cursor.h"
#include "Ship.h"
#include "Asteroid.h"
#include "GameObject.h"
#include "Map.h"

#include <vector>
#include <iostream>

int w = 800;
int h = 800;

class GameGlobal : public Framework
{

public:
	Cursor* cursor;
	Ship* ship;
	Map* map;
	std::vector<GameObject*> gameObjs;
	Global* global;
	float prevT, dt = 0;
	float fps = 120;


	// no function calls are available here, this function should only return width, height and fullscreen values
	virtual void PreInit(int& width, int& height, bool& fullscreen)
	{
		width = w;
		height = h;
		fullscreen = false;
	}

	// return : true - ok, false - failed, application will exit
	virtual bool Init()
	{
		global = Global::getInstance();
		cursor = new Cursor();
		global->reset();
		ship = new Ship();
		map = new Map(global->mapW, global->mapH);
		ship->position = Coordinate(global->mapW / 2, global->mapH / 2);
		map->player = ship;
		global->gameObjects.push_back(ship);
		gameObjs = global->gameObjects;
		showCursor(false);
		return true;
	}

	virtual void Close() 
	{
		/*free memory here ...*/
	}

	virtual bool Tick() 
	{
		if (ship->needDestroy)
		{
			ship->destroy();
			gameObjs.clear();
			delete map;
			Init();
		}

		// Get the number of milliseconds since library initialization
		dt = getTickCount() - prevT;
		dt = dt / fps;
		prevT = getTickCount();

		map->update(dt);
		gameObjs = global->gameObjects;

		for (auto object : gameObjs)
		{
			object->update(dt);
		}

		for (auto object : gameObjs)
		{
			if (object->needDestroy && object->type != objectType::ship)
			{
				object->destroy();
			}
		}

		cursor->update();
		return false;
	}

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative)
	{
		ship->shoot(Coordinate(x, y));
		cursor->moveCursor(Coordinate(x, y));
	}

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased)
	{
		ship->onMouseClick(button, isReleased);
	}

	virtual void onKeyPressed(FRKey k)
	{
		ship->onKeyPrsed(k);
	}

	virtual void onKeyReleased(FRKey k)
	{
		ship->onKeyRlsed(k);
	}

	virtual const char* GetTitle() override
	{
		return "Asteroids(1979->2023)";
	}
};

int main(int argc, char* argv[])
{
	Global* globalInstance = Global::getInstance();
	return run(new GameGlobal);
}
