#include "GameObject.h"

GameObject::GameObject() 
{
	speed = 50;
	gGlobal = Global::getInstance();
	type = objectType::NONE;
	width = 0;
	height = 0;
	needDestroy = false;
	id = 0;
	spriteObj = NULL;
}

GameObject::~GameObject()
{
	destroySprite(spriteObj);
}