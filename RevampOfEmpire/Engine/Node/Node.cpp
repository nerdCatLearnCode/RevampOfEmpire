#include "Node.h"

namespace Engine
{
	void Node::SetScale(Vector2 scale)
	{
		this->scale = scale;
	}
	void Node::SetZIndex(int z_index_)
	{
		this->z_index = z_index_;
	}
	int Node::GetZIndex() const
	{
		return z_index;
	}

	Vector2 Node::GetScale() const
	{
		return scale;
	}
}