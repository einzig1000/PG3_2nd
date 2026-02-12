#pragma once
#include "InputManager.h"
#include <Novice.h>

enum class SceneType
{
	None,
	Title,
	InGame,
	Clear,
};

class IScene
{
public:
	virtual ~IScene() = default;
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void SetInputManager(InputManager* IM);
	virtual SceneType GetRequiredSceneType() const { return requiredSceneType; }

protected:
	InputManager* inputManager = nullptr;

	SceneType requiredSceneType = SceneType::None;
};

