#include "Manager.h"

namespace NodeManager
{
	Manager::Manager(SDL_Renderer* renderer_)
		: renderer(renderer_)
	{
		nodes.push_back(std::make_unique<Player>(renderer_, engine, engine.GetFPS().GetDeltaTime()));
	}

	void Manager::Update()
	{
		engine.Initialize();
		float dt = engine.GetFPS().GetDeltaTime();

		for (auto& node : nodes)
		{
			node->delta_time = dt;
			node->Update();
			node->Render();
			node->UpdateEvent();
		}
	}
	
}