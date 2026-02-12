#pragma once
#include "IScene.h"
#include <memory>

class Player;
class Enemy;

class InGameScene : public IScene
{
public:
	InGameScene();
	~InGameScene() override;
	void Initialize() override;
	void Update() override;
	void Draw() override;

private:
	std::unique_ptr<Player> player;
	std::unique_ptr<Enemy> enemy;
};

