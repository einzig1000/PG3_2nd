#pragma once
#include "Player.h"

class ICommand
{
public:
	virtual ~ICommand() = default;
	virtual void Execute(Player& player) = 0;
};