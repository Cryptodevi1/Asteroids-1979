#pragma once
#include "Global.h"
#include "GameObject.h"

class Bullet : public GameObject
{
public:
	Bullet(Coordinate currentSpeed, Coordinate position);
	virtual ~Bullet();

	void update(float dt) override;
	void move(float dt) override;
	void collision(GameObject* obj) override;
	void destroy() override;
};