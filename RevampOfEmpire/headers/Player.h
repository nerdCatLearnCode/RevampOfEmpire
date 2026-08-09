#pragma once

#include <Texture/Texture.h>
#include <Collision/Collision.h>
#include <Animated/Animated.h>
#include <Engine.h>

class Player
{
public:
	Player(SDL_Renderer* renderer_, Engine::Engines& engine);

	~Player();

	void Render();

	void Update();

private:
	Engine::Collider* collider;
	Engine::Animated* animated;
	Engine::Engines* engine;

	float w, h, x, y;
	float srcX, srcY, srcW, srcH;
	float fps;

	SDL_Renderer* renderer;
};

