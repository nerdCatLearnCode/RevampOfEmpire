#pragma once

#include <SDL3/SDL.h>
#include <vector>
#include <algorithm>
#include <string>

namespace Engine
{
	typedef struct Vector2
	{
		float x, y;
	};

	typedef struct Collider
	{
		Vector2 pos;
		Vector2 size;

		bool isCollide = true;
		std::string id;
	};

	class CollisionManager
	{
	public:
		void Add(Collider* collider);
		void Remove(Collider* collider);

		bool isCollide(const Collider& a, const Collider& b);

		void Update();
	private:
		std::vector<Collider*> Colliders;
	};
		
}

