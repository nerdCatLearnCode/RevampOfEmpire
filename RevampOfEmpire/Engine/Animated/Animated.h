#pragma once

#include <SDL3/SDL.h>
#include "Mode.h"

namespace Engine
{
	class Animated
	{
	public:
		Animated(float sizeX, float sizeY, float mapSizeX, float mapSizeY);

		void PlayRange(float StartSrcX, float StartSrcY, float EndSrcX, float EndSrcY, float fps);
		void SetMode(Mode mode);
		void SetPlay(bool play);

		void Update();

		float GetSrcX() const;
		float GetSrcY() const;

		void SetMapSize(float MapSizeX, float MapSizeY);

	private:
		Uint64 lastTime;
		Uint64 currentTime;

		bool isPlaying = true;

		Mode mode;

		int direction;

		float fps;
		float startSrcX, startSrcY;
		float endSrcX, endSrcY;
		float sizeX, sizeY;
		float m_srcX, m_srcY;
		float mapSizeX, mapSizeY;
	};
}