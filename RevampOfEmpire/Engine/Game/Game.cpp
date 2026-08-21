#include "Game.h"

namespace Engine
{
	Game::Game(SDL_Renderer* renderer, Engine::Engines& engine)
		: renderer(renderer),
		engine(&engine)
	{

	}

	void Game::Add(std::string name, std::unique_ptr<NodeManager::Manager> level)
	{
		level = std::make_unique<NodeManager::Manager>(renderer, engine);

		levels.insert({ std::move(name), std::move(level) });
	}

	void Game::Remove(std::string name)
	{
		levels.erase(name);
	}

	void Game::PlayLevel(const std::string name)
	{
		this->playingLevel = name;
	}


}