#pragma once
#include "ICommand.h"
#include "MoveLeftCommand.h"
#include "MoveRightCommand.h"

class InputHandler
{
public:
    InputHandler();

    ICommand* HandleInput(char* key);

private:
    MoveLeftCommand moveLeft;
    MoveRightCommand moveRight;
};
