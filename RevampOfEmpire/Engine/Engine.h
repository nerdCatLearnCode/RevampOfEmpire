#pragma once

#include <Collision/Collision.h>
#include <FPS/FPS.h>
#include <Game/Game.h>

namespace Engine
{
	class Engines
	{
	public:
		Engines(SDL_Renderer* renderer);

		void Initialize();

		void Node();

		const CollisionManager& GetCollisionManager() const;


		const FPS& GetFPS() const;

		Game& GetGame();
		const Game& GetGame() const;

	private:
		CollisionManager collisionManager;
		FPS fps;
		Game game;

		SDL_Renderer* renderer;
	};
}