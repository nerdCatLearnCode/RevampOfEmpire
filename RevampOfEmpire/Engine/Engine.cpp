#include "Engine.h"

namespace Engine
{
	Engines::Engines()
		: collisionManager(), 
		fps()
	{
	}
	void Engines::Initialize()
	{
		collisionManager.Update();
		fps.Update();
	}

	CollisionManager Engines::GetCollisionManager() const
	{
		return collisionManager;
	}
	FPS Engines::GetFPS() const
	{
		return fps;
	}
}