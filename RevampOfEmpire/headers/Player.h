#pragma once

#include <Texture/Texture.h>
#include <Collision/Collision.h>
#include <Animated/Animated.h>
#include <Node/Node.h>
#include <Engine.h>

class Player : public Engine::Node
{
public:
	Player(SDL_Renderer* renderer_, Engine::Engines& engine);

	~Player();

	void Render() override;

	void Update() override;

private:
	Engine::Collider* collider;
	Engine::Animated* animated;
	Engine::Engines* engine;

	float fps;

	SDL_Renderer* renderer;
};

