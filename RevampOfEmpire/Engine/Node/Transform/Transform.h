#pragma once

#include <Math/Vector2.h>

struct Transform
{
	Vector2 pos;
	Vector2 src;
	Vector2 scale;

	struct Size
	{
		float w, h;
	} size;
	Size src_size;
};