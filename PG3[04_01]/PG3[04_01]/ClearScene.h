#pragma once
#include "IScene.h"

class ClearScene : public IScene
{
public:
	ClearScene();
	~ClearScene() override;
	void Initialize() override;
	void Update() override;
	void Draw() override;
};

