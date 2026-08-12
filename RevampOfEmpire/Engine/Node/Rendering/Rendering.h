#pragma once

#include <Node/Transform/Transform.h>

class Rendering
{
public:

	Rendering(Transform& transform);
	
	int z_index;
	bool hide;
	bool flip_h, flip_v;

	void Update();

private:
	Transform* transform;
};
