#pragma once
#include "Framework.h"
#include "Global.h"
#include "Coordinate.h"

enum class objectType 
{
	ship,
	bullet,
	asteroid,
	NONE,
};

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	int width;
	int height;
	int id;

	float speed;
	bool needDestroy;

	Coordinate currentSpeed;
	Coordinate position;
	Coordinate relativePosition;

	Global* gGlobal;
	objectType type;

	virtual void update(float dt) = 0;
	virtual void move(float dt) = 0;
	virtual void collision(GameObject* obj) = 0;
	virtual void destroy() = 0;

protected:
	Sprite* spriteObj;
};

