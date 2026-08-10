#pragma once

#include <SDL3/SDL.h>
#include <Math/Vector2.h>
#include <Node/Transform/Transform.h>
#include <FPS/fps.h>

namespace Engine
{
	class Node
	{
	public:
		Node(float delta_time_);

		virtual void Update() = 0;
		virtual void Render() = 0;
		virtual void HandleInput(const SDL_Event& event) = 0;

		virtual ~Node() = default;

		void SetScale(Vector2 scale);

		void SetZIndex(int z_index);

		void SetDeltaTime(float delta_time_);

		int GetZIndex() const;

		Vector2 GetScale() const;

	public:
		Transform transform;
		float delta_time;
	};
}