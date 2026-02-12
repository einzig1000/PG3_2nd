#include "Player.h"
#include <Novice.h>

Player::Player()
{
	x = 100;
}

void Player::Update()
{}

void Player::Draw()
{
	Novice::DrawBox(x - 25, 100, 50, 50, 0.0f, 0xFFFFFFFF, kFillModeSolid);
}

void Player::MoveLeft()
{
	x--;
}

void Player::MoveRight()
{
	x++;
}
