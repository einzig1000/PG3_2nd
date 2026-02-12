#include "InputHandler.h"
#include <Novice.h>

InputHandler::InputHandler()
{}

ICommand* InputHandler::HandleInput(char* key)
{
    if (key[DIK_A]) return &moveLeft;
    if (key[DIK_D]) return &moveRight;
    return nullptr;
}
