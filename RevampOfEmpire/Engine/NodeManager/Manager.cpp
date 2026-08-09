#include "Manager.h"

namespace NodeManager
{
	Manager::Manager(SDL_Renderer* renderer_)
		: renderer(renderer_)
	{
		nodes.push_back(std::make_unique<Player>(renderer_, engine));
	}

	void Manager::Update()
	{
		for (auto& node : nodes)
		{
			node->Update();
			node->Render();
		}
	}
	
}