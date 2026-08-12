#include "../headers/Player.h"

using namespace Engine;

Player::Player(SDL_Renderer* renderer_, Engine::Engines& engine, float delta_time)
	: Node(delta_time),
	renderer(renderer_),
	engine(&engine),
	fps(12.0f),
	W(false), A(false), S(false), D(false)
{
	collider = new Engine::Collider;
	animated = new Engine::Animated(64, 80, 64*4, 80);

	animated->PlayRange(0, 0, 64 * 4, 80, fps);
	animated->SetMode(Mode::Loop);

	
	transform.scale = { 1, 1 };
	rendering->z_index = 1;

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
		transform.size.w * transform.scale.x,
		transform.size.h * transform.scale.y
	};

	sprite.Render(src, dst);
}

void Player::Update()
{
	animated->Update();
	rendering->Update();
	collider->pos =
	{
		transform.pos.x,
		transform.pos.y
	};
	if (!collider->isCollide)
	{
		SDL_Log("collide!");
	}

	if (D)
	{
		transform.pos.x += 1000 * delta_time;
		rendering->flip_h = false;
	}
	if (A)
	{
		transform.pos.x -= 1000 * delta_time;
		rendering->flip_h = true;
	}
}

int Player::GetZ()
{
	return rendering->z_index;
}

void Player::HandleInput(const SDL_Event& event)
{
	if (event.type == SDL_EVENT_KEY_DOWN)
	{
		switch (event.key.key)
		{
		case SDLK_W:
			W = true;
			break;
		case SDLK_A:
			A = true;
			break;
		case SDLK_S:
			S = true;
			break;
		case SDLK_D:
			D = true;
			break;
		default:
			break;
		}
	}
	else if (event.type == SDL_EVENT_KEY_UP)
	{
		switch (event.key.key)
		{
		case SDLK_W:
			W = false;
			break;
		case SDLK_A:
			A = false;
			break;
		case SDLK_S:
			S = false;
			break;
		case SDLK_D:
			D = false;
			break;
		default:
			break;
		}
	}
	
}