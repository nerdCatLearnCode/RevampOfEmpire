#include "Animated.h"

namespace Engine
{
	Animated::Animated(float sizeX, float sizeY, float mapSizeX, float mapSizeY)
		: lastTime(SDL_GetTicks()), 
		sizeX(sizeX), 
		sizeY(sizeY),
		mapSizeX(mapSizeX),
		mapSizeY(mapSizeY),
		direction(1)
	{
	}

	void Animated::SetMode(Mode mode)
	{
		this->mode = mode;
	}

	void Animated::PlayRange(float StartSrcX, float StartSrcY, float EndSrcX, float EndSrcY, float fps)
	{
		startSrcX = StartSrcX;
		startSrcY = StartSrcY;
		endSrcX = EndSrcX;
		endSrcY = EndSrcY;
		this->fps = fps;
		m_srcX = startSrcX;
		m_srcY = startSrcY;
	}

	void Animated::Update()
	{
		//static bool isPlaying = true;

		if (!isPlaying)
			return;

		currentTime = SDL_GetTicks();
		if (currentTime - lastTime >= 1000.0f / fps)
		{
			if (m_srcX + sizeX >= endSrcX)
			{
				if (m_srcY + sizeY >= endSrcY)
				{
					switch (mode)
					{
					case Mode::Once:
						isPlaying = false;
						break;
					case Mode::Loop:
						m_srcX = startSrcX;
						m_srcY = startSrcY;
						break;
					default:
						break;
					}
				}
				else
					m_srcY += sizeY*direction;
			} else
				m_srcX += sizeX*direction;

			lastTime = currentTime;
		}
	}

	float Animated::GetSrcX() const
	{
		return m_srcX;
	}

	float Animated::GetSrcY() const
	{
		return m_srcY;
	}

	void Animated::SetPlay(bool play)
	{
		isPlaying = play;
	}
	
}