#include "Enemy.h"
#include <iostream>

void (Enemy::* Enemy::spFunctions_[])() =
{
	&Enemy::Approach,
	&Enemy::Attack,
	&Enemy::Retreat,
};

Enemy::Enemy()
{
	state_ = EnemyState::STATE_APPROACH;
}

void Enemy::Update()
{
	(this->*spFunctions_[static_cast<size_t>(state_)])();
}

void Enemy::Approach()
{
	printf("enemy approaching...\n");
	SetState(EnemyState::STATE_ATTACK);
}

void Enemy::Attack()
{
	printf("enemy attacking!\n");
	SetState(EnemyState::STATE_RETREAT);
}

void Enemy::Retreat()
{
	printf("enemy retreating...\n");
	SetState(EnemyState::STATE_APPROACH);
}
