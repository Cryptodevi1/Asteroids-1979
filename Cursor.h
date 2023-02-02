#pragma once
#include "Framework.h"
#include "Coordinate.h"

class Cursor
{
public:
	Cursor();
	~Cursor();
	void update();
	void moveCursor(Coordinate pos);
private:
	Sprite* cursor;
	Coordinate pos;
};