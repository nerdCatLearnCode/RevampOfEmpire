#include "Manager.h"

namespace NodeManager
{
	Manager::Manager(SDL_Renderer* renderer_)
		: renderer(renderer_),
		player(new Player(renderer_, engine))
	{
	}
	void Manager::Update()
	{
		engine.Run();

		player->Update();
	}
	void Manager::Render()
	{
		player->Render();
	}
}