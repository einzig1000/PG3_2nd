#include "InputManager.h"
#include <Novice.h>

InputManager::InputManager()
{}

InputManager::~InputManager()
{}

void InputManager::Update()
{
	// キー入力を受け取る
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);
}

bool InputManager::IsPressed(unsigned char key) const
{
	return keys[key] != 0;
}

bool InputManager::IsTriggered(unsigned char key) const
{
	return preKeys[key] == 0 && keys[key] != 0;
}

bool InputManager::IsReleased(unsigned char key) const
{
	return preKeys[key] != 0 && keys[key] == 0;
}


