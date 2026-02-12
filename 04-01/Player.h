#pragma once
#include <Novice.h>

class Enemy;
class InputManager;

struct DrawInfo
{
	float positionX = 0.0f;
	float positionY = 0.0f;
	float sizeX = 0.0f;
	float sizeY = 0.0f;
	unsigned int color = 0xFFFFFFFF;

	void Draw() const
	{
		Novice::DrawBox(
			static_cast<int>(positionX - sizeX / 2),
			static_cast<int>(positionY - sizeY / 2),
			static_cast<int>(sizeX),
			static_cast<int>(sizeY),
			0.0f,
			color,
			kFillModeSolid);
	}
};

class Player
{
public:
	Player();
	~Player();
	void Initialize();
	void Update();
	void Draw();

	void SetEnemy(Enemy* enemyPtr) { enemy = enemyPtr; }
	void SetInputManager(InputManager* inputMgr) { inputManager = inputMgr; }

private:
	void Fire();
	bool fireBullet = false;

	DrawInfo bulletDrawInfo;
	DrawInfo playerDrawInfo;


	InputManager* inputManager = nullptr;
	Enemy* enemy = nullptr;
};

