#include "Player.h"
#include "InputManager.h"
#include "Enemy.h"

Player::Player()
{}

Player::~Player()
{}

void Player::Initialize()
{
	playerDrawInfo.positionX = 640.0f;
	playerDrawInfo.positionY = 600.0f;
	playerDrawInfo.sizeX = 30.0f;
	playerDrawInfo.sizeY = 30.0f;
	playerDrawInfo.color = 0xFFFFFFFF;
	bulletDrawInfo.positionX = 640.0f;
	bulletDrawInfo.positionY = 600.0f;
	bulletDrawInfo.sizeX = 5.0f;
	bulletDrawInfo.sizeY = 10.0f;
	bulletDrawInfo.color = 0xFFFFFFFF;

	fireBullet = false;
}

void Player::Update()
{
	if (inputManager->IsTriggered(DIK_SPACE) && !fireBullet)
	{
		Fire();
	}

	if (fireBullet)
	{
		bulletDrawInfo.positionY -= 5.0f;
		// 当たり判定
		if (bulletDrawInfo.positionY - bulletDrawInfo.sizeY / 2 <= enemy->positionY + enemy->sizeY / 2)
		{
			enemy->isDead = true;
			fireBullet = false;
		}
	}
}

void Player::Draw()
{
	if (fireBullet)bulletDrawInfo.Draw();
	playerDrawInfo.Draw();
}

void Player::Fire()
{
	fireBullet = true;
	bulletDrawInfo.positionX = playerDrawInfo.positionX;
	bulletDrawInfo.positionY = playerDrawInfo.positionY;
}
