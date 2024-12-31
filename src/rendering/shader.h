#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/ext/matrix_float4x4.hpp>

class Shader
{
public:
	unsigned int ID;

	Shader(const char* vertexPath, const char* fragmentPath);

	void use();
	void setBool(const std::string & name, bool value) const;
	void setInt(const std::string & name, int value) const;
	void setFloat(const std::string & name, float value) const;
	void setMatrix4fv(const std::string& name, glm::mat4 & matrix) const;
	void set4f(const std::string& name, float v1, float v2, float v3, float v4);

};