#include "Node.h"

namespace Engine
{
	Node::Node(float delta_time_)
	{
		delta_time = delta_time_;
		transform.pos = { 0, 0 };
		transform.src = { 0, 0 };
		transform.scale = { 1, 1 };
		transform.z_index = 1;
		transform.hide = false;
		transform.flip_h = false;
		transform.flip_v = false;
	}

	void Node::SetScale(Vector2 scale)
	{
		transform.scale = scale;
	}
	void Node::SetZIndex(int z_index_)
	{
		transform.z_index = z_index_;
	}
	int Node::GetZIndex() const
	{
		return transform.z_index;
	}

	Vector2 Node::GetScale() const
	{
		return transform.scale;
	}
	void Node::SetDeltaTime(float delta_time_)
	{
		delta_time = delta_time_;
	}
}