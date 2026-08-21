#pragma once

#include <NodeManager/Manager.h>
#include <SDL3/SDL.h>
#include <memory>
#include <string>
#include <map>
#include <algorithm>

namespace Engine
{
	class Game
	{
	public:
		Game(SDL_Renderer* renderer, Engine::Engines& engine);
		~Game() = default;

		void Add(std::string name, std::unique_ptr<NodeManager::Manager> level);

		void PlayLevel(const std::string name);

		void Remove(std::string name);

		void Update();

	private:
		Engine::Engines* engine;

		std::map<std::string, std::unique_ptr<NodeManager::Manager>> levels;

		std::string playingLevel;

		SDL_Renderer* renderer;
	};
}
