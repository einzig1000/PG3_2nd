#include "ClearScene.h"

ClearScene::ClearScene(){}

ClearScene::~ClearScene(){}

void ClearScene::Initialize()
{
	requiredSceneType = SceneType::None;
}

void ClearScene::Update()
{
	if (inputManager->IsTriggered(DIK_SPACE))
	{
		requiredSceneType = SceneType::Title;
	}
}

void ClearScene::Draw()
{
	Novice::ScreenPrintf(640 - 50, 360 - 10, "ClearScene");
}
