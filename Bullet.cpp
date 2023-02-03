#include "Bullet.h"

Bullet::Bullet(Coordinate currentSpeed, Coordinate position) : GameObject()
{
	spriteObj = createSprite("data/bullet.png");
	getSpriteSize(spriteObj, width, height);
	type = objectType::bullet;
	needDestroy = false;
	this->currentSpeed = currentSpeed;
	this->position = position;

	id = gGlobal->bulletId++; 
}

Bullet::~Bullet()
{
	delete this;
}

void Bullet::update(float dt)
{
	drawSprite(spriteObj, (int)relativePosition.x, (int)relativePosition.y);
	move(dt);
}
void Bullet::move(float dt) 
{
	position.x += currentSpeed.x * dt;
	position.y += currentSpeed.y * dt;
	relativePosition.x += currentSpeed.x * dt;
	relativePosition.y += currentSpeed.y * dt;
}

void Bullet::collision(GameObject* obj) 
{
	if (obj->type == objectType::asteroid)
	{
		this->needDestroy = true;
	}
}

void Bullet::destroy() 
{
	for (auto i = gGlobal->gameObjects.begin(); i != gGlobal->gameObjects.end(); ++i)
	{
		if ((*i)->type == this->type && (*i)->id == this->id)
		{
			gGlobal->gameObjects.erase(i);
			break;
		}
	}
	delete this;
}