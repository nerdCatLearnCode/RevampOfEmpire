#include "Texture.h"

namespace Engine
{
    RenderTexture::RenderTexture(SDL_Renderer* renderer, SDL_Surface* surface)
        : renderer_(renderer),
        surface_(surface),
        texture_(nullptr)
    {
        if (!surface_)
        {
            SDL_Log("IMG_Load failed: %s", SDL_GetError());
            return;
        }

        texture_ = SDL_CreateTextureFromSurface(renderer_, surface_);

        if (!texture_)
        {
            SDL_Log("CreateTextureFromSurface failed: %s", SDL_GetError());
            return;
        }

        SDL_SetTextureScaleMode(texture_, SDL_SCALEMODE_NEAREST);
    }

	RenderTexture::~RenderTexture()
	{
        if (texture_)
		    SDL_DestroyTexture(texture_);
		if (surface_)
            SDL_DestroySurface(surface_);
	}

    void RenderTexture::SetSurface(SDL_Surface* surface_)
    {
        this->surface_ = surface_;
    }

	void RenderTexture::Render(SDL_FRect src, SDL_FRect dsl)
	{
		SDL_RenderTexture(renderer_, texture_, &src, &dsl);
	}
}