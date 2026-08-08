#include "Collision.h"

namespace Engine
{
	void CollisionManager::Add(Collider* collider)
	{
		Colliders.push_back(collider);
	}

	void CollisionManager::Remove(Collider* collider)
	{
		auto it = std::find(Colliders.begin(), Colliders.end(), collider);

		if (it != Colliders.end())
		{
			Colliders.erase(it);
		}
	}

	void CollisionManager::Update()
	{
		for (size_t i = 0; i < Colliders.size();i++)
		{
			for (size_t j = i + 1; j < Colliders.size();j++)
			{
				SDL_Log(
					"Checking %s vs %s",
					Colliders[i]->id.c_str(),
					Colliders[j]->id.c_str()
				);

				if (isCollide(*Colliders[i], *Colliders[j]))
				{
					SDL_Log("COLLISION!");

					Colliders[i]->isCollide = false;
					Colliders[j]->isCollide = false;
				}
			}
		}
	}

	bool CollisionManager::isCollide(const Collider& a, const Collider& b)
	{
		return 
			a.pos.x < b.pos.x + b.size.x &&
			a.pos.x + a.size.x > b.pos.x &&
			a.pos.y < b.pos.y + b.size.y &&
			a.pos.y + a.size.y > b.pos.y;
	}
}