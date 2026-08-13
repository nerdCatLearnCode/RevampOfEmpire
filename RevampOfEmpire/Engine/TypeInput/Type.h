#pragma once

#include <SDL3/SDL.h>
#include <array>

namespace Engine
{
    class Input
    {
    private:
        const bool* currentKeyboard = nullptr;

        std::array<bool, SDL_SCANCODE_COUNT> previousKeyboard{};

    public:
        Input();

        void Update();

        bool KeyPressed(SDL_Scancode key);
        bool KeyHeld(SDL_Scancode key);
        bool KeyReleased(SDL_Scancode key);
        bool KeyUp(SDL_Scancode key);
    };
}