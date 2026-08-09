#pragma once

#include <SDL3/SDL.h>
#include <headers/Player.h>

namespace NodeManager
{
	class Manager
	{
	public:
		Manager(SDL_Renderer* renderer);
		void Update();
		void Render();
	private:
		SDL_Renderer* renderer;
		Engine::Engines engine;

		Player* player;
	};
}