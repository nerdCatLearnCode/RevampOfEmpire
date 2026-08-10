#include "../headers/Player.h"

using namespace Engine;

Player::Player(SDL_Renderer* renderer_, Engine::Engines& engine, float delta_time)
	: Node(delta_time),
	renderer(renderer_),
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
	collider->pos =
	{
		transform.pos.x,
		transform.pos.y
	};
	if (!collider->isCollide)
	{
		SDL_Log("collide!");
	}
}

void Player::HandleInput(const SDL_Event& event)
{
	if (event.type == SDL_EVENT_KEY_DOWN)
	{
		if (event.key.key == SDLK_W)
		{
			SDL_Log("W key pressed");
			transform.pos.y -= 1000*delta_time;
		}
		else if (event.key.key == SDLK_S)
		{
			SDL_Log("S key pressed");
			transform.pos.y += 1000*delta_time;
		}
		else if (event.key.key == SDLK_A)
		{
			SDL_Log("A key pressed");
			transform.pos.x -= 1000*delta_time;
		}
		else if (event.key.key == SDLK_D)
		{
			SDL_Log("delta_time = %f", delta_time);
			SDL_Log("D key pressed");
			transform.pos.x += 1000*delta_time;
			SDL_Log("Player position: (%f, %f)", transform.pos.x, transform.pos.y);
		}
	}
}