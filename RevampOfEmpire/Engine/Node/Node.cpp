#include "Node.h"

namespace Engine
{
	Node::Node(float delta_time_)
		: rendering(new Rendering(transform))
	{
		delta_time = delta_time_;
		transform.pos = { 0, 0 };
		transform.src = { 0, 0 };
		transform.scale = { 1, 1 };
	}

	Node::~Node()
	{
		delete rendering;
	}
}