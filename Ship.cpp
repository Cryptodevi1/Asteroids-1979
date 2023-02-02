#include "Ship.h"

Ship::Ship():GameObject()
{
	spriteObj = createSprite("data/ship.png");
	getSpriteSize(spriteObj, width, height);
	type = objectType::ship;
    needDestroy = false;
	canShoot = false;

	position.x = 320;
	position.y = 100;
	acceleration.x = 0;
	acceleration.y = 0;
	maxSpeed = 0.5f * speed;
}

Ship::~Ship()
{
	destroy();
}

void Ship::onMouseClick(FRMouseButton button, bool isReleased)
{
	if (button == FRMouseButton::LEFT && !isReleased)
	{
		canShoot = true;
	}
}
void Ship::onKeyPrsed(FRKey k)
{
	switch (k)
	{
	case FRKey::LEFT :
		currentSpeed.x = -maxSpeed;
		currentSpeed.y = 0;
		acceleration.x = 0;
		break;
	case FRKey::RIGHT:
		currentSpeed.x = maxSpeed;
		currentSpeed.y = 0;
		acceleration.x = 0;
		break;
	case FRKey::UP:
		currentSpeed.y = -maxSpeed;
		acceleration.y = 0;
		break;
	case FRKey::DOWN:
		currentSpeed.y = maxSpeed;
		acceleration.y = 0;
		break;
	default:
		break;
	}
}
void Ship::onKeyRlsed(FRKey k)
{
	switch (k)
	{
	case FRKey::LEFT:
		acceleration.x = 0.001f;
		break;
	case FRKey::RIGHT:
		acceleration.x = -0.001f;
	case FRKey::UP:
		acceleration.y = 0.001f;
		break;
	case FRKey::DOWN:
		acceleration.y = -0.001f;
		break;
	default:
		break;
	}
}

void Ship::shoot(Coordinate destination)
{
	if (canShoot)
	{
		//bullets 
		canShoot = false;
	}
}

void Ship::update(float dt)
{
	drawSprite(spriteObj, (int)relativePosition.x, (int)relativePosition.y);
	move(dt);
}

void Ship::move(float dt)
{
	currentSpeed.x += abs(currentSpeed.x) <= maxSpeed ? acceleration.x * abs(currentSpeed.x) : 0;
	currentSpeed.y += abs(currentSpeed.y) <= maxSpeed ? acceleration.y * abs(currentSpeed.y) : 0;
	position.x += currentSpeed.x * dt;
	position.y += currentSpeed.y * dt;
	relativePosition.x += currentSpeed.x * dt;
	relativePosition.y += currentSpeed.y * dt;
}
void Ship::collision(GameObject* obj)
{
	//collision with asteroids
}

void Ship::destroy()
{
	delete this;
}

