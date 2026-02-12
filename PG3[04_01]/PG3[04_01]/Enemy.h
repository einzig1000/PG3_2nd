#pragma once
#include <Novice.h>

class Enemy
{
public:
	Enemy();
	~Enemy();
	void Initialize();
	void Update();
	void Draw();

	bool isDead = false;
	float positionX = 600.0f;
	float positionY = 200.0f;
	float sizeX = 100.0f;
	float sizeY = 100.0f;
};

