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

	virtual void update(float dt) = NULL;
	virtual void move(float dt) = NULL;
	virtual void collision(GameObject* obj) = NULL;
	virtual void destroy() = NULL;

protected:
	Sprite* spriteObj;
};

