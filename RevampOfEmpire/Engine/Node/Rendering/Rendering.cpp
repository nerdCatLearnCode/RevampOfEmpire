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
		transform->pos.x += transform->size.w * abs(transform->scale.x);
	}
	
	if (!flip_h && transform->scale.x < 0)
	{
		transform->scale.x *= -1;
		transform->pos.x -= transform->size.w * abs(transform->scale.x);
	}

	if (flip_v && transform->scale.y > 0)
	{
		transform->scale.y *= -1;
		transform->pos.y += transform->size.h * abs(transform->scale.y);
	}

	if (!flip_v && transform->scale.y < 0)
	{
		transform->scale.y *= -1;
		transform->pos.y -= transform->size.h * abs(transform->scale.y);
	}
}