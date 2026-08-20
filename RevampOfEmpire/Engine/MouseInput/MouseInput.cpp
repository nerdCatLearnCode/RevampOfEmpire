#include "MouseInput.h"

void MouseInput::Update()
{
    previousButtons = currentButtons;

    currentButtons = SDL_GetMouseState(&mouseX, &mouseY);
}

bool MouseInput::ButtonPressed(Uint8 button)
{
    SDL_MouseButtonFlags mask = SDL_BUTTON_MASK(button);

    return (currentButtons & mask) &&
        !(previousButtons & mask);
}

bool MouseInput::ButtonReleased(Uint8 button)
{
    SDL_MouseButtonFlags mask = SDL_BUTTON_MASK(button);

    return !(currentButtons & mask) &&
        (previousButtons & mask);
}

bool MouseInput::ButtonHeld(Uint8 button)
{
    SDL_MouseButtonFlags mask = SDL_BUTTON_MASK(button);

    return (currentButtons & mask) &&
        (previousButtons & mask);
}

float MouseInput::GetX() const
{
    return mouseX;
}

float MouseInput::GetY() const
{
    return mouseY;
}