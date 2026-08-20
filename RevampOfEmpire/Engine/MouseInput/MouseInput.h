#pragma once

#include <SDL3/SDL.h>

class MouseInput
{
public:
    void Update();

    bool ButtonPressed(Uint8 button);
    bool ButtonHeld(Uint8 button);
    bool ButtonReleased(Uint8 button);

    float GetX() const;
    float GetY() const;

private:
    SDL_MouseButtonFlags currentButtons = 0;
    SDL_MouseButtonFlags previousButtons = 0;

    float mouseX = 0;
    float mouseY = 0;
};

