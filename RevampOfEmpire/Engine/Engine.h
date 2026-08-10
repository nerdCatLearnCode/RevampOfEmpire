#pragma once

#include <Collision/Collision.h>
#include <FPS/FPS.h>

namespace Engine
{
	class Engines
	{
	public:
		Engines();

		void Initialize();

		void Node();

		CollisionManager GetCollisionManager() const;


		FPS GetFPS() const;

	private:
		CollisionManager collisionManager;
		FPS fps;
	};
}