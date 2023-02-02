#pragma once
#include "GameObject.h"
#include "Global.h"
#include "GameObject.h"

class Asteroid : public GameObject
{
public:
	int size;
	Coordinate maxSpeed;
	Coordinate minSpeed;
	Coordinate deceleration;

	Asteroid(int size, Coordinate position, Coordinate maxSpeed);
	virtual ~Asteroid();

	void update(float dt) override;
	void move(float dt) override;
	void collision(GameObject* obj) override;
	void destroy() override;
};

