#include "Manager.h"	
#include <Engine/Engine.h>
			
namespace NodeManager			
{			
	Manager::Manager(SDL_Renderer* renderer_, Engine::Engines& engine)		
		: renderer(renderer_),
		engine(&engine)
	{		
			
	}	

	std::vector<std::unique_ptr<Engine::Node>>& Manager::GetNodes() 
	{
		return nodes;
	}
			
	void Manager::ConstUpdate()		
	{
		float dt = engine->GetFPS().GetDeltaTime();	
			
		for (auto& node : nodes)	
		{	
			node->delta_time = dt;
			node->Update();
			node->Render();
			node->UpdateEvent();
		}	
	}		
			
}			
