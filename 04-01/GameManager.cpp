#include "GameManager.h"
#include "TitleScene.h"
#include "InGameScene.h"
#include "ClearScene.h"
#include "InputManager.h"

GameManager::GameManager()
{
	titleScene = std::make_unique<TitleScene>();
	inGameScene = std::make_unique<InGameScene>();
	clearScene = std::make_unique<ClearScene>();

	inputManager = std::make_unique<InputManager>();

	titleScene->SetInputManager(inputManager.get());
	inGameScene->SetInputManager(inputManager.get());
	clearScene->SetInputManager(inputManager.get());

	ChangeScene(SceneType::Title);
}

GameManager::~GameManager()
{

}

void GameManager::Update()
{

	if (currentScene->GetRequiredSceneType() != SceneType::None) {
		ChangeScene(currentScene->GetRequiredSceneType());
	}
	currentScene->Update();
	inputManager->Update();
}

void GameManager::Draw()
{
	currentScene->Draw();
}

void GameManager::ChangeScene(SceneType sceneType)
{
	switch (sceneType) {
	case SceneType::Title:
		currentScene = titleScene.get();
		break;
	case SceneType::InGame:
		currentScene = inGameScene.get();
		break;
	case SceneType::Clear:
		currentScene = clearScene.get();
		break;
	default:
		break;
	}
	currentScene->Initialize();
}
