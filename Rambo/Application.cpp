#include "Application.h"
#include "gl_core_4_4.h"
#include <glfw3.h>
#include <Gizmos.h>

Application::Application() :
	m_window(nullptr),
	m_gameOver(false),
	m_clearColor{ 1, 1, 1, 1 },
	m_runningTime(0)
{}

void Application::run(const char * title, unsigned int width, unsigned int height, bool fullscreen)
{
	glfwInit();
	m_window = glfwCreateWindow(width, height, title, NULL, NULL);
	glfwMakeContextCurrent(m_window);

	auto load = ogl_LoadFunctions();
	auto major = ogl_GetMajorVersion();
	auto minor = ogl_GetMinorVersion();


	glClearColor(1.f, 1.f, 1.f, 1.f);
	glEnable(GL_DEPTH_TEST);

	startup();

	while(glfwWindowShouldClose(m_window) == false)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		update(0);
		draw();

		glfwSwapBuffers(m_window);
		glfwPollEvents();

		if (glfwGetKey(m_window, GLFW_KEY_ESCAPE))
			break;

		if (m_gameOver)
			shutdown();
	}
}