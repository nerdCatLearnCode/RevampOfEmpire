#include "AnimatedManager.h"

using namespace Engine;

AnimatedManager::AnimatedManager()
    : currentAnimation(nullptr)
{
}

AnimatedManager::~AnimatedManager()
{
    listAnimation.clear();
    currentAnimation = nullptr;
}

void AnimatedManager::CreateAnimation(Animated& animation)
{
    listAnimation.push_back(&animation);
}

void AnimatedManager::RemoveAnimation(Animated& animation)
{
    if (currentAnimation == &animation)
    {
        currentAnimation = nullptr;
    }

    for (auto it = listAnimation.begin(); it != listAnimation.end(); ++it)
    {
        if (*it == &animation)
        {
            listAnimation.erase(it);
            return;
        }
    }
}

void AnimatedManager::Play(Animated& animation)
{
    // Đã play animation này rồi
    if (currentAnimation == &animation)
    {
        return;
    }

    // Tắt animation cũ
    if (currentAnimation != nullptr)
    {
        currentAnimation->SetPlay(false);
    }

    // Chuyển sang animation mới
    currentAnimation = &animation;

    // Bật animation mới
    currentAnimation->SetPlay(true);
}

void AnimatedManager::Update()
{
    if (currentAnimation != nullptr)
    {
        currentAnimation->Update();
    }
}