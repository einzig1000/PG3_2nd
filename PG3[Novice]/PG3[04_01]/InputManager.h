#pragma once

class InputManager
{
public:
	InputManager();
	~InputManager();
	void Update();

	/// そのフレームで押されているか
	bool IsPressed(unsigned char key) const;

	/// そのフレームに押されたか
	bool IsTriggered(unsigned char key) const;

	/// そのフレームに離されたか
	bool IsReleased(unsigned char key) const;

private:

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};
};



