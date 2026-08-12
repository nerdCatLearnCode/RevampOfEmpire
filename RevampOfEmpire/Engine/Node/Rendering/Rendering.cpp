#include "Rendering.h"

Rendering::Rendering(Transform& transform)
	: transform(&transform)
{
}

void Rendering::Update()
{
	if (flip_h && transform->scale.x > 0)
	{
		transform->scale.x *= -1;
	}
	
	if (!flip_h && transform->scale.x < 0)
	{
		transform->scale.x *= -1;
	}

	if (flip_v && transform->scale.y > 0)
	{
		transform->scale.y *= -1;
	}

	if (!flip_v && transform->scale.y < 0)
	{
		transform->scale.y *= -1;
	}
}