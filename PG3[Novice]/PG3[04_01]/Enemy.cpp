#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{}

void Enemy::Initialize()
{
	positionX = 640.0f;
	positionY = 200.0f;
	sizeX = 30.0f;
	sizeY = 30.0f;
	isDead = false;
}

void Enemy::Update()
{
}

void Enemy::Draw()
{
	Novice::DrawBox(
		static_cast<int>(positionX - sizeX / 2),
		static_cast<int>(positionY - sizeY / 2),
		static_cast<int>(sizeX),
		static_cast<int>(sizeY),
		0.0f,
		0xFF0000FF,
		kFillModeSolid);
}