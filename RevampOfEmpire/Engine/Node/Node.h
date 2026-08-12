#pragma once

#include <SDL3/SDL.h>
#include <Math/Vector2.h>
#include <Node/Transform/Transform.h>
#include <FPS/fps.h>
#include <Node/Rendering/Rendering.h>

namespace Engine
{
	class Node
	{
	public:
		Node(float delta_time_);

		virtual void Update() = 0;
		virtual void Render() = 0;
		virtual void HandleInput(const SDL_Event& event) = 0;
		
		virtual int GetZ() = 0;

		virtual ~Node();

	public:
		Transform transform;
		Rendering* rendering;
		float delta_time;
	};
}