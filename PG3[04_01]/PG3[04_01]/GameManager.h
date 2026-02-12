#pragma once
#include <memory>
#include "IScene.h"

class TitleScene;
class InGameScene;
class ClearScene;

class InputManager;

class GameManager
{
public:
	GameManager();
	~GameManager();
	void Update();
	void Draw();

	void ChangeScene(SceneType sceneType);

	std::unique_ptr<InputManager> inputManager;
private:
	IScene* currentScene;
	std::unique_ptr<TitleScene> titleScene;
	std::unique_ptr<InGameScene> inGameScene;
	std::unique_ptr<ClearScene> clearScene;


};

