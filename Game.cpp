#include "Framework.h"
#include "Global.h"
#include <vector>

int w = 800;
int h = 800;

class GameGlobal : public Framework
{

public:
	/*Cursor* cursor;
	Ship* ship;
	Map* map;
	std::vector<GameObject*> gameObjs;*/
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
		//global->reset();
		//memory allocations here ...
		showCursor(false);
		return true;
	}

	virtual void Close() 
	{
		/*free memory here ...*/
	}

	virtual bool Tick() 
	{

		// Get the number of milliseconds since library initialization
		dt = getTickCount() - prevT;
		dt = dt / fps;
		prevT = getTickCount();

		//update obj here...

		return false;
	}

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative)
	{
		//move cursor and aim
	}

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased)
	{
		//shoot when click 
	}

	virtual void onKeyPressed(FRKey k)
	{
		//ship move
	}

	virtual void onKeyReleased(FRKey k)
	{
		//отпусккнопки
	}

	virtual const char* GetTitle() override
	{
		return "Asteroids(1979->2023)";
	}

private:

	struct sSpaceObject
	{
		float x;
		float y;
		float dx;
		float dy;
	};

	std::vector<sSpaceObject> vecAsteroids;
};

int main(int argc, char* argv[])
{
	Global* globalInstance = Global::getInstance();
	return run(new GameGlobal);
}
