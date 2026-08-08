#include <iostream>
#include <SDL3/SDL.h>
#include <Engine/Collision/Collision.h>
#include <headers/Player.h>
#include <headers/player2.h>


bool running = true;

int WIDTH = 1080;
int HEIGHT = 720;

int GetScaleWidth()
{
	return WIDTH / 1080;
}

int GetScaleHeight()
{
	return HEIGHT / 720;
}

int main()
{
	//Engine
	Engine::CollisionManager collisionManager;

	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window* window;
	window = SDL_CreateWindow("RevampOfEmpire",
		WIDTH,
		HEIGHT,
		SDL_WINDOW_RESIZABLE);

	SDL_MaximizeWindow(window);
	SDL_GetWindowSize(window,
		&WIDTH,
		&HEIGHT);
	
	SDL_Renderer* renderer;
	renderer = SDL_CreateRenderer(window, nullptr);

	SDL_Event event;

	Player player(renderer, collisionManager);
	

	while (running)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_EVENT_QUIT)
				running = false;
		}

		SDL_RenderClear(renderer);

		//update
		collisionManager.Update();
		player.Update();

		//Render
		player.Render();

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}