#pragma once
#include "../src/obj_loader/fast_obj.h"

class Mesh
{
public:
	Mesh(const char* path);
	void draw();
private:
	fastObjMesh* mesh;
	unsigned int VAO = 0;
	unsigned int VBO = 0;
	unsigned int EBO = 0;
	float* vertices;
	unsigned int* indices;
	unsigned int indexCount = 0;
	unsigned int vertexCount = 0;
};
