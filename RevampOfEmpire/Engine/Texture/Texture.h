#pragma once

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

namespace Engine
{
	class RenderTexture
	{
	public:
		RenderTexture(SDL_Renderer* renderer, SDL_Surface* surface);
		~RenderTexture();

		void Render(SDL_FRect src, SDL_FRect dsl);

		void SetSurface(SDL_Surface* surface_);

		RenderTexture(const RenderTexture&) = delete;
		RenderTexture& operator=(const RenderTexture&) = delete;

	private:

		SDL_Renderer* renderer_;

		SDL_Surface* surface_;
		SDL_Texture* texture_;

	};
}