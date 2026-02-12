#include "TitleScene.h"

TitleScene::TitleScene(){}

TitleScene::~TitleScene(){}

void TitleScene::Initialize()
{
	requiredSceneType = SceneType::None;
}

void TitleScene::Update()
{
	if (inputManager->IsTriggered(DIK_SPACE))
	{
		requiredSceneType = SceneType::InGame;
	}
}

void TitleScene::Draw()
{
	Novice::ScreenPrintf(640 - 50, 360 - 10, "TitleScene");
}
