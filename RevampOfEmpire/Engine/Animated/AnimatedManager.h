#pragma once

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <vector>
#include <algorithm>
#include "Animated.h"

namespace Engine
{
    class AnimatedManager
    {
    public:
        AnimatedManager();
        ~AnimatedManager();

        void CreateAnimation(Animated& animation);
        void RemoveAnimation(Animated& animation);

        void Play(Animated& animation);
        void Update();

    private:
        std::vector<Animated*> listAnimation;

        Animated* currentAnimation;
    };
}
