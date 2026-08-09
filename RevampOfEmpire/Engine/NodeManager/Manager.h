#pragma once

#include <SDL3/SDL.h>
#include <headers/Player.h>
#include <Engine.h>
#include <memory>
#include <vector>

namespace NodeManager
{
	class Manager
	{
	public:
		Manager(SDL_Renderer* renderer);
		void Update();
	private:
		SDL_Renderer* renderer;
		Engine::Engines engine;

		std::vector<std::unique_ptr<Engine::Node>> nodes;
	};
}