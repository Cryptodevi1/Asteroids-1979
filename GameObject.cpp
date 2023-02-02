#include "GameObject.h"

GameObject::GameObject() 
{
	speed = 30;
	gGlobal = Global::getInstance();
}

GameObject::~GameObject()
{
	destroySprite(spriteObj);
}