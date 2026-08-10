#include "../headers/Player.h"

using namespace Engine;

Player::Player(SDL_Renderer* renderer_, Engine::Engines& engine)
	: renderer(renderer_),
	engine(&engine),
	fps(12.0f)
{
	collider = new Engine::Collider;
	animated = new Engine::Animated(64, 80, 64*4, 80);

	animated->PlayRange(0, 0, 64 * 4, 80, fps);
	animated->SetMode(Mode::Loop);

	SetZIndex(1);
	SetScale({ -2, 2 });


	transform.pos.x = transform.pos.y = 512;

	transform.size.w = transform.src_size.w = 64;
	transform.size.h = transform.src_size.h = 80;

	transform.src.x = transform.src.y = 0;

	collider->pos =
	{
		transform.pos.x,
		transform.pos.y
	};

	collider->size =
	{
		transform.size.w,
		transform.size.h
	};

	collider->id = "player";

	engine.GetCollisionManager().Add(collider);
}

Player::~Player()
{
	engine->GetCollisionManager().Remove(collider);
	delete collider;
	delete animated;
}

void Player::Render()
{
	Engine::RenderTexture sprite(renderer, IMG_Load("D:/CppProject/RevampOfEmpire/RevampOfEmpire/assets/texture/Idle-Sheet.png"));

	transform.src.x = animated->GetSrcX();
	transform.src.y = animated->GetSrcY();

	SDL_FRect src =
	{
		transform.src.x,
		transform.src.y,
		transform.src_size.w,
		transform.src_size.h
	};

	SDL_FRect dst =
	{
		transform.pos.x,
		transform.pos.y,
		transform.size.w * GetScale().x,
		transform.size.h * GetScale().y
	};

	sprite.Render(src, dst);
}

void Player::Update()
{
	animated->Update();
	if (!collider->isCollide)
	{
		SDL_Log("collide!");
	}
}