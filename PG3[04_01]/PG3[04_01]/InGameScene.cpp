#include "InGameScene.h"
#include "Player.h"
#include "Enemy.h"

InGameScene::InGameScene()
{
	player = std::make_unique<Player>();
	enemy = std::make_unique<Enemy>();

}

InGameScene::~InGameScene()
{}

void InGameScene::Initialize()
{
	requiredSceneType = SceneType::None;
	player->SetEnemy(enemy.get());
	player->SetInputManager(inputManager);
	player->Initialize();
	enemy->Initialize();
}

void InGameScene::Update()
{
	player->Update();
	enemy->Update();
	if (enemy->isDead)
	{
		requiredSceneType = SceneType::Clear;
	}
}

void InGameScene::Draw()
{
	player->Draw();
	enemy->Draw();
}
