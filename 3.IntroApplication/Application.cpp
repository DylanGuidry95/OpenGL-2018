#include "Application.h"
#include "gl_core_4_4.h"
#include <glfw3.h>
#include<iostream>

Application::Application() :
	m_window(nullptr),
	m_gameOver(false),
	m_clearColor{ 1, 1, 1, 1 },
	m_runningTime(0)
{
	m_Camera = new FlyCamera();
}

Application::~Application()
{
}


void Application::run(const char * title, unsigned int width, unsigned int height, bool fullscreen)
{
	glfwInit();
	m_window = glfwCreateWindow(width, height, title, NULL, NULL);
	glfwMakeContextCurrent(m_window);

	auto load = ogl_LoadFunctions();
	auto major = ogl_GetMajorVersion();
	auto minor = ogl_GetMinorVersion();


	glClearColor(0, 0, 0, 1.f);
	glEnable(GL_DEPTH_TEST);

	startup();

	m_Camera->setPosition(glm::vec3(0, 0, 0));
	m_Camera->setSpeed(5);

	float prevTime = glfwGetTime();

	while(glfwWindowShouldClose(m_window) == false)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				std::cout << m_Camera->getWorldTransform()[j][i] << ",";
			}
			std::cout << std::endl;
		}
		float currentTime = glfwGetTime();
		float deltaTime = currentTime - prevTime;
		prevTime = currentTime;
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		m_Camera->update(deltaTime);
		update(deltaTime);
		draw();

		glfwSwapBuffers(m_window);
		glfwPollEvents();

		if (glfwGetKey(m_window, GLFW_KEY_ESCAPE))
			break;

		if (m_gameOver)
			shutdown();
	}
}
