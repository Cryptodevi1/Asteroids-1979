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
	delete this;
}
void Asteroid::update(float dt)
{
	drawSprite(spriteObj, (int)relativePosition.x, (int)relativePosition.y);
	move(dt);
}

void Asteroid::move(float dt) 
{
	currentSpeed.x = (fabs(currentSpeed.x) >= fabs(minSpeed.x) ? currentSpeed.x - deceleration.x * currentSpeed.x : minSpeed.x);
	currentSpeed.y = (fabs(currentSpeed.y) >= fabs(minSpeed.y) ? currentSpeed.y - deceleration.y * currentSpeed.y : minSpeed.y);
	position.x += currentSpeed.x * dt;
	position.y += currentSpeed.y * dt;
	relativePosition.x += currentSpeed.x * dt;
	relativePosition.y += currentSpeed.y * dt;
}
void Asteroid::collision(GameObject* obj)
{
	if (obj->type == objectType::bullet) 
	{
		this->needDestroy = true;
	}

	if (obj->type == objectType::asteroid)
	{
		Coordinate tempCurrSpeed = this->currentSpeed;
		Coordinate tempMaxSpeed = this->maxSpeed;
		Coordinate tempMinSpeed = this->minSpeed;
		Coordinate tempDeceleration = this->deceleration;

		this->currentSpeed = ((Asteroid*)obj)->currentSpeed;
		this->maxSpeed = ((Asteroid*)obj)->maxSpeed;;
		this->minSpeed = ((Asteroid*)obj)->minSpeed;;
		this->deceleration = ((Asteroid*)obj)->deceleration;

		((Asteroid*)obj)->currentSpeed = tempCurrSpeed;
		((Asteroid*)obj)->minSpeed = tempMinSpeed;
		((Asteroid*)obj)->maxSpeed = tempMaxSpeed;
		((Asteroid*)obj)->deceleration = tempDeceleration;
		this->move(0.1);
		obj->move(0.1);
	}
}
void Asteroid::destroy() 
{
	for (auto i = gGlobal->gameObjects.begin(); i != gGlobal->gameObjects.end(); ++i) 
	{
		if ((*i)->type == this->type && (*i)->id == this->id) 
		{
			gGlobal->gameObjects.erase(i);
			gGlobal->asteroidCount--;
			break;
		}
	}

	if (size == 1)
	{
		gGlobal->gameObjects.push_back(new Asteroid(0,this->position, this->maxSpeed.getNormalize().mult(0.5)));
		gGlobal->gameObjects.push_back(new Asteroid(0, this->position, this->maxSpeed.getNormalize().mult(-0.5)));
	}
	delete this;
}