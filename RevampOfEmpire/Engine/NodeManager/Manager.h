#pragma once

#include <SDL3/SDL.h>
#include <memory>
#include <vector>
#include <iostream>
#include <Node/Node.h>

namespace Engine
{
	class Engines;
}

namespace NodeManager
{

	class Manager
	{
	public:
		Manager(SDL_Renderer* renderer_, Engine::Engines& engine);
		~Manager() = default;
		void ConstUpdate();
		
		std::vector<std::unique_ptr<Engine::Node>>& GetNodes();

		virtual void Update() = 0;
		virtual void Render() = 0;

	private:
		SDL_Renderer* renderer;
		Engine::Engines* engine;
		SDL_Event* event;

		std::vector<std::unique_ptr<Engine::Node>> nodes;
	};
}