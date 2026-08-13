#include "Type.h"

namespace Engine
{
    Input::Input()
    {
        currentKeyboard = SDL_GetKeyboardState(nullptr);

        memcpy(
            previousKeyboard.data(),
            currentKeyboard,
            SDL_SCANCODE_COUNT * sizeof(bool)
        );
    }

    void Input::Update()
    {
        memcpy(
            previousKeyboard.data(),
            currentKeyboard,
            SDL_SCANCODE_COUNT * sizeof(bool)
        );

        currentKeyboard = SDL_GetKeyboardState(nullptr);
    }

    bool Input::KeyPressed(SDL_Scancode key)
    {
        return currentKeyboard[key] && !previousKeyboard[key];
    }

    bool Input::KeyHeld(SDL_Scancode key)
    {
        return currentKeyboard[key] && previousKeyboard[key];
    }

    bool Input::KeyReleased(SDL_Scancode key)
    {
        return !currentKeyboard[key] && previousKeyboard[key];
    }

    bool Input::KeyUp(SDL_Scancode key)
    {
        return !currentKeyboard[key] && previousKeyboard[key];
    }
}