#pragma once
#include "ICommand.h"

class MoveLeftCommand : public ICommand
{
public:
    void Execute(Player& player) override
    {
        player.MoveLeft();
    }
};