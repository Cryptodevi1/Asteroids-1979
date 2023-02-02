#include "GameObject.h"

GameObject::GameObject() 
{
	speed = 30;
	gGlobal = Global::getInstance();
	type = objectType::NONE;
}

GameObject::~GameObject()
{
	destroySprite(spriteObj);
}