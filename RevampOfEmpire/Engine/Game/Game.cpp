#include "Game.h"
#include <Engine/Engine.h>

namespace Engine
{
	Game::Game(SDL_Renderer* renderer, Engine::Engines& engine)
		: renderer(renderer),
		engine(&engine)
	{

	}

	void Game::AddLevel(std::string name, std::unique_ptr<NodeManager::Manager> level)
	{

		levels.insert({ std::move(name), std::move(level) });
	}

	void Game::RemoveLevel(std::string name)
	{
		levels.erase(name);
	}

	void Game::PlayLevel(const std::string name)
	{
		this->playingLevel = name;
	}

	void Game::Update()
	{
		auto it = levels.find(playingLevel);

		if (it == levels.end())
		{
			return;
		}

		it->second->ConstUpdate();
		it->second->Update();
		it->second->Render();
	}

}