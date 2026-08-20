#include "Manager.h"			
			
namespace NodeManager			
{			
	Manager::Manager(SDL_Renderer* renderer_)		
		: renderer(renderer_)	
	{		
			
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
