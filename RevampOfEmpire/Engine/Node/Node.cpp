#include "Node.h"

namespace Engine
{
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
}