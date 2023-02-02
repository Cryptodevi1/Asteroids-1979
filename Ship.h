#pragma once
#include "Framework.h"
#include "Global.h"
#include "GameObject.h"
#include "Bullet.h"

#include <math.h>
class Ship : public GameObject
{
public:
	float maxSpeed;
	Coordinate acceleration;
	bool canShoot;

	Ship();
	virtual ~Ship();

	void shoot(Coordinate destination);

	void onMouseClick(FRMouseButton button, bool isReleased);
	void onKeyPrsed(FRKey k);
	void onKeyRlsed(FRKey k);

	void update(float dt) override;
	void move(float dt) override;
	void collision(GameObject* obj) override;
	void destroy() override;
};