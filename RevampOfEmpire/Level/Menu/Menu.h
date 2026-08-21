#pragma once

#include <Engine/NodeManager/Manager.h>

namespace Engine
{
	class Engines;
}

class Menu : public NodeManager::Manager
{
public:
	Menu(SDL_Renderer* renderer, Engine::Engines& engine);
	~Menu() = default;

	void Update() override;
	void Render() override;
};

