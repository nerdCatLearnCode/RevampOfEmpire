#pragma once

#include <Texture/Texture.h>
#include <Collision/Collision.h>
#include <Animated/Animated.h>
#include <Node/Node.h>
#include <Engine.h>
#include <TypeInput/Type.h>

class Player : public Engine::Node
{
public:
	Player(SDL_Renderer* renderer_, Engine::Engines& engine, float delta_time);

	~Player();

	void Render() override;

	void Update() override;

	void UpdateEvent() override;

	int GetZ() override;
private:
	Engine::Collider* collider;
	Engine::Animated* animated;
	Engine::Engines* engine;
	Engine::Input* input;

	float fps;
	bool isRunning = false;

	Engine::RenderTexture* idle;
	Engine::RenderTexture* run;

	Engine::Animated* runAnimation;

	bool W, A, S, D;

	SDL_Renderer* renderer;
};

