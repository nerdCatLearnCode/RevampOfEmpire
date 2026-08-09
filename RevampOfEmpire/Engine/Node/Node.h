#pragma once

#include <Math/Vector2.h>

namespace Engine
{
	class Node
	{
	public:
		virtual void Update() = 0;
		virtual void Render() = 0;

		virtual ~Node() = default;

		void SetScale(Vector2 scale);

		void SetZIndex(int z_index);

		int GetZIndex() const;

		Vector2 GetScale() const;

	private:
		Vector2 scale;
		int z_index;
	};
}