#include "../headers/Player.h"

using namespace Engine;

Player::Player(SDL_Renderer* renderer_, Engine::Engines& engine, float delta_time)
	: Node(delta_time),
	renderer(renderer_),
	engine(&engine),
	fps(12.0f),
	W(false), A(false), S(false), D(false),
	input(new Input()),
	idle(new Engine::RenderTexture(renderer_, IMG_Load("D:/CppProject/RevampOfEmpire/RevampOfEmpire/assets/texture/Idle-Sheet.png"))),
	run(new Engine::RenderTexture(renderer_, IMG_Load("D:/CppProject/RevampOfEmpire/RevampOfEmpire/assets/texture/Run-Sheet.png"))),
	attack(new Engine::RenderTexture(renderer_, IMG_Load("D:/CppProject/RevampOfEmpire/RevampOfEmpire/assets/texture/Attack-01-Sheet.png")))
{
	collider = new Engine::Collider;
	animated = new Engine::Animated(64, 80, 64 * 4, 80);
	runAnimation = new Engine::Animated(80, 80, 80 * 8, 80);
	attackAnimation = new Engine::Animated(768/8, 80, 768, 80);

	animated->PlayRange(0, 0, 64 * 4, 80, fps);
	animated->SetMode(Mode::Loop);
	runAnimation->PlayRange(0, 0, 80 * 8, 80, 16);
	runAnimation->SetMode(Mode::Loop);
	attackAnimation->PlayRange(0, 0, 96 * 8, 80, 24);
	attackAnimation->SetMode(Mode::Loop);


	transform.scale = { 2, 2 };
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

	animationManager.CreateAnimation(*runAnimation);
	animationManager.CreateAnimation(*animated);
	animationManager.CreateAnimation(*attackAnimation);
	animationManager.Play(*animated);
}

Player::~Player()
{
	engine->GetCollisionManager().Remove(collider);

	animationManager.RemoveAnimation(*runAnimation);
	animationManager.RemoveAnimation(*animated);
	animationManager.RemoveAnimation(*attackAnimation);

	delete runAnimation;
	delete attackAnimation;
	delete input;
	delete collider;
	delete idle;
	delete run;
	delete attack;
	delete animated;
}

void Player::Render()
{
	Engine::RenderTexture* sprite;

	if (input->KeyHeld(SDL_SCANCODE_A) ||
		input->KeyHeld(SDL_SCANCODE_D))
	{
		sprite = run;

		transform.src.x = runAnimation->GetSrcX();
		transform.src.y = runAnimation->GetSrcY();

		transform.src_size.w = 80;
		transform.src_size.h = 80;

		transform.size = { 80, 80 };
	}
	else if (input->KeyHeld(SDL_SCANCODE_K))
	{
		sprite = attack;

		transform.src.x = attackAnimation->GetSrcX();
		transform.src.y = attackAnimation->GetSrcY();

		transform.src_size.w = 96;
		transform.src_size.h = 80;

		transform.size = { 96, 80 };
	}
	else
	{
		sprite = idle;

		transform.src.x = animated->GetSrcX();
		transform.src.y = animated->GetSrcY();

		transform.src_size.w = 64;
		transform.src_size.h = 80;

		transform.size = { 64, 80 };
	}

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

	sprite->Render(src, dst);
}

void Player::Update()
{
	input->Update();

	if (input->KeyHeld(SDL_SCANCODE_A) ||
		input->KeyHeld(SDL_SCANCODE_D))
	{
		animationManager.Play(*runAnimation);
	}
	else if (input->KeyHeld(SDL_SCANCODE_K))
	{
		animationManager.Play(*attackAnimation);
	}
	else
	{
		animationManager.Play(*animated);
	}

	animationManager.Update();

	rendering->Update();

	collider->pos =
	{
		transform.pos.x,
		transform.pos.y
	};
}

int Player::GetZ()
{
	return rendering->z_index;
}

void Player::UpdateEvent()
{
	if (input->KeyHeld(SDL_SCANCODE_A))
	{
		transform.pos.x -= 1000 * delta_time;
		rendering->flip_h = true;
	}
	if (input->KeyHeld(SDL_SCANCODE_D))
	{
		transform.pos.x += 1000 * delta_time;
		rendering->flip_h = false;
	}
}