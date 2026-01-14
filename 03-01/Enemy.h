#pragma once

enum class EnemyState
{
	// 接近
	STATE_APPROACH = 0,
	// 攻撃
	STATE_ATTACK = 1,
	// 離脱
	STATE_RETREAT = 2,
};

class Enemy
{
public:
	Enemy();
	void Update();
	void SetState(EnemyState state) { state_ = state; }

	// 接近
	void Approach();
	// 攻撃
	void Attack();
	// 離脱
	void Retreat();

private:
	static void (Enemy::*spFunctions_[])();

	EnemyState state_;
};

