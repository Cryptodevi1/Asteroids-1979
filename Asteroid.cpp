#include "Asteroid.h"

Asteroid::Asteroid(int size, Coordinate position, Coordinate maxSpeed) : GameObject()
{
	if (size >= 1) 
	{
		this->size = 1;
		spriteObj = createSprite("data/big_asteroid.png");
	}
	else if (size < 0)
	{
		this->size = 0;
		spriteObj = createSprite("data/small_asteroid.png");
	}
	else
	{
		this->size = size;
		spriteObj = createSprite("data/small_asteroid.png");
	}

	getSpriteSize(spriteObj, width, height);

	this->maxSpeed = maxSpeed.mult(speed);
	minSpeed.x = this->maxSpeed.x / 2;
	minSpeed.y = this->maxSpeed.y / 2;
	currentSpeed.x = this->currentSpeed.x;
	currentSpeed.y = this->currentSpeed.y;
	this->deceleration = this->maxSpeed.getNormalize().div(100);

	this->position.x = position.x;
	this->position.y = position.y;

	type = objectType::asteroid;
	id = gGlobal->asteroidId++;
	gGlobal->asteroidCount++;
	needDestroy = false;
}
Asteroid::~Asteroid()
{

}
void Asteroid::update(float dt)
{}
void Asteroid::move(float dt) 
{}
void Asteroid::collision(GameObject* obj)
{}
void Asteroid::destroy() 
{}