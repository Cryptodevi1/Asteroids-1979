#include "Cursor.h"

Cursor::Cursor()
{
	cursor = createSprite("data/aim.png");
}
Cursor::~Cursor()
{
	delete this;
}
void Cursor::update()
{
	drawSprite(cursor, pos.x, pos.y);
}
void Cursor::moveCursor(Coordinate pos)
{
	this->pos = pos;
}