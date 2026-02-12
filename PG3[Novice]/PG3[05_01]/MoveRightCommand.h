#pragma once
#include "ICommand.h"

class MoveRightCommand : public ICommand
{
public:
    void Execute(Player& player) override
    {
        player.MoveRight();
    }
};