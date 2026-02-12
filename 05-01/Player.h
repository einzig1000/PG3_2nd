#pragma once


class Player
{
public:
    Player();
	void Update();
	void Draw();


    void MoveLeft();
    void MoveRight();

private:
    int x;
};


