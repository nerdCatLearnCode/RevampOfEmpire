#pragma once

#include <SDL3/SDL.h>

namespace Engine
{
	class FPS
	{
	public:
		FPS();
		
		void Update();

		float GetDeltaTime() const;

		float GetFPS() const;

	private:
		Uint64 start;
		float delta_time;

		float fps;
	};
}