#pragma once

#include <Texture/Texture.h>
#include <Collision/Collision.h>

using namespace Engine;

class Player
{
public:
	Player(SDL_Renderer* renderer_, Engine::CollisionManager& collisionManager);

	~Player();

	void Render();

	void Update();

private:
	Collider* collider;

	float w, h, x, y;
	float srcX, srcY, srcW, srcH;

	SDL_Renderer* renderer;
};

