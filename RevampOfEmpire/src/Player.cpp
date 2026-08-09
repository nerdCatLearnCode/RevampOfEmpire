#include "../headers/Player.h"

Player::Player(SDL_Renderer* renderer_, Engine::CollisionManager& collisionManager)
	: renderer(renderer_)
{
	collider = new Collider;
	animated = new Engine::Animated(64, 80, 64*4, 80);

	animated->PlayRange(0, 0, 64 * 4, 80, 8);
	animated->SetMode(Mode::Loop);

	x = y = 512;

	w = srcW = 64;
	h = srcH = 80;

	srcX = srcY = 0;

	collider->pos =
	{
		x,
		y
	};

	collider->size =
	{
		w,
		h
	};

	collider->id = "player";

	collisionManager.Add(collider);
}

Player::~Player()
{
	delete collider;
	delete animated;
}

void Player::Render()
{
	Engine::RenderTexture sprite(renderer, IMG_Load("D:/CppProject/RevampOfEmpire/RevampOfEmpire/assets/texture/Idle-Sheet.png"));

	srcX = animated->GetSrcX();
	srcY = animated->GetSrcY();

	SDL_FRect src =
	{
		srcX,
		srcY,
		srcW,
		srcH
	};

	SDL_FRect dst =
	{
		x,
		y,
		w,
		h
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