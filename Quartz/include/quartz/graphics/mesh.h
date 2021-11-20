#pragma once

#include <cstdint>

namespace Quartz::Graphics
{
	class Mesh
	{
	public:
		Mesh(float* vertexArray, uint64_t vertexCount, uint64_t dimensions);
		~Mesh();

		void Bind();
		void Unbind();

	private:
		uint64_t vertexCount;
		uint32_t vao;
		uint32_t positionVbo;
	};
}