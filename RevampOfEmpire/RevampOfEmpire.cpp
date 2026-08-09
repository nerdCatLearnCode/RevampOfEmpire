#include <iostream>
#include <SDL3/SDL.h>
#include <NodeManager/Manager.h>


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
	
	//engine
	NodeManager::Manager* manager = new NodeManager::Manager(renderer);

	while (running)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_EVENT_QUIT)
				running = false;
		}

		SDL_RenderClear(renderer);

		//Update
		manager->Update();

		//Render
		manager->Render();

		SDL_RenderPresent(renderer);
	}

	delete manager;
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}