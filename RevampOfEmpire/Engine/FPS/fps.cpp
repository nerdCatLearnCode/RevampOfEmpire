#include "fps.h"

namespace Engine
{
	FPS::FPS()
		: start(SDL_GetTicks())
		, delta_time(0.0f)
		, fps(0.0f)
	{
	}

	void FPS::Update()
	{
		Uint64 end = SDL_GetTicks();

		delta_time = (end - start) / 1000.0f;

		if (delta_time > 0.0f)
			fps = 1.0f / delta_time;

		start = end;
	}

	float FPS::GetDeltaTime() const
	{
		return delta_time;
	}

	float FPS::GetFPS() const
	{
		return fps;
	}
}