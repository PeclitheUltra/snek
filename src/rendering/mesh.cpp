#include "mesh.h"
#include "../src/obj_loader/fast_obj.h"
#include <glad/gl.h>


Mesh::Mesh(const char* path)
{
	mesh = fast_obj_read(path);
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	vertexCount = mesh->position_count * 3;
	vertices = new float[vertexCount];
	for (int i = 0; i < vertexCount; i++)
	{
		vertices[i] = mesh->positions[i];
	}
	indexCount = mesh->index_count;
	indices = new unsigned int[indexCount];
	for (int i = 0; i < indexCount; i++)
	{
		indices[i] = mesh->indices[i].p;
	}


}

void Mesh::draw() 
{
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertexCount, vertices, GL_STATIC_DRAW);

	glBindVertexArray(VAO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indexCount, indices, GL_STATIC_DRAW);

	glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);
}