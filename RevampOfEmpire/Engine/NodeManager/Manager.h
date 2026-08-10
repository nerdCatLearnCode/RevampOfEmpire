#pragma once

#include <SDL3/SDL.h>
#include <headers/Player.h>
#include <Engine.h>
#include <memory>
#include <vector>
#include <iostream>

namespace NodeManager
{
	class Manager
	{
	public:
		Manager(SDL_Renderer* renderer_);
		void Update();
		void HandleInput(const SDL_Event& event);
	private:
		SDL_Renderer* renderer;
		Engine::Engines engine;
		SDL_Event* event;

		std::vector<std::unique_ptr<Engine::Node>> nodes;
	};
}