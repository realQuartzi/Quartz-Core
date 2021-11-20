#include "graphics/mesh.h"

#include "glad/glad.h"

namespace Quartz::Graphics
{

	// Vertex Array, Vertex Count, Dimensions
	Mesh::Mesh(float* vArray, uint64_t vCount, uint64_t dim) : vertexCount(vCount)
	{
		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);

		glGenBuffers(1, &positionVbo);
		glBindBuffer(GL_ARRAY_BUFFER, positionVbo);

		glBufferData(GL_ARRAY_BUFFER, vCount * dim * sizeof(float), vArray, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, (GLint)dim, GL_FLOAT, GL_FALSE, 0, 0);
		glDisableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glBindVertexArray(0);
	}

	Mesh::~Mesh()
	{
		glDeleteBuffers(1, &positionVbo);
		glDeleteVertexArrays(1, &vao);
	}

	void Mesh::Bind()
	{
		glBindVertexArray(vao);
		glEnableVertexAttribArray(0);
	}

	void Mesh::Unbind() 
	{
		glDisableVertexAttribArray(0);
		glBindVertexArray(0);
	}
}