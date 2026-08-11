#pragma once

#include <SDL3/SDL.h>

class TypeInput
{
public:
	TypeInput(SDL_Event& event);
	~TypeInput();

private:
	SDL_Event* event;
};