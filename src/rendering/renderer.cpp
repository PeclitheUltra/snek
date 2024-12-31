#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <thread>
#include <chrono>
#include "linmath.h"
#include <filesystem>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../src/obj_loader/fast_obj.h"
#include "shader.h"
#include "mesh.h"


void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

int CreateWindow(GLFWwindow*& window)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	window = glfwCreateWindow(1000, 1000, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	if (!gladLoadGL((GLADloadfunc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glViewport(0, 0, 1000, 1000);
	return 0;
}

int startRendering()
{
	GLFWwindow* window;
	int status = CreateWindow(window);
	if (status != 0)
		return status;

	Mesh sphere("./meshes/sphere.obj");
	Shader mainShader("./shaders/vertex.glsl", "./shaders/fragment.glsl");

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CW);


	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		//clear
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//draw
		mainShader.use();

		for (int i = 0; i < 3; i++)
		{
			glm::mat4 model = glm::mat4(1.0f);
			model = glm::translate(model, glm::vec3(1, i, 1));
			model = glm::rotate(model, glm::radians(90.0f * (float)glfwGetTime()), glm::vec3(0.3f, 0.3f, 0.0f));
			glm::mat4 view = glm::lookAt(glm::vec3(0.0f, 8.0f, -8.0f),
				glm::vec3(0.0f, 0.0f, 0.0f),
				glm::vec3(0.0f, 1.0f, 0.0f));
			glm::mat4 projection = glm::perspective(glm::radians(45.0f), 1000.0f / 1000.0f, 0.1f, 100.0f);

			mainShader.setMatrix4fv("model", model);
			mainShader.setMatrix4fv("view", view);
			mainShader.setMatrix4fv("projection", projection);

			sphere.draw();
		}


		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}
