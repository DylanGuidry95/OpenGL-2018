#define GLM_ENABLE_EXPERIMENTAL
#include <iostream>
#include <gl_core_4_4.h>
#include <glfw3.h>
#include <Gizmos.h>
#include <glm\gtx\string_cast.hpp>
#include <glm\glm.hpp>

#include <glm/ext.hpp>

GLFWwindow* window;
void Update()
{
	glm::mat4 model = glm::mat4(1); //model
	glm::mat4 view = glm::lookAt(glm::vec3(10, 10, 10), glm::vec3(0), glm::vec3(0, 1, 0));//view
	glm::mat4 projection = glm::perspective(glm::pi<float>() * 0.25f, 16 / 9.f, 0.1f, 1000.f);//projection

	//loop through window
	while (glfwWindowShouldClose(window) == false || glfwGetKey(window, GLFW_KEY_ESCAPE))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		Gizmos::clear();
		model = glm::mat4(1);
		Gizmos::addSphere(glm::vec3(0, 0, 0), 10.f, 10, 10, glm::vec4(.5, .5, .5, 1), &model);
		Gizmos::draw(projection * view * model);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

int Start()
{
	glfwInit(); //initialize glfw first
	//GLFW:
	//graphics library file wrangler
 
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL); //make a window

	glfwMakeContextCurrent(window); //make the window you made, the current openGL target

	auto loaded = ogl_LoadFunctions();//initializes openGL
	auto major = ogl_GetMajorVersion();
	auto minor = ogl_GetMinorVersion();
	std::printf("major :: %i.%i", major, minor);
	Gizmos::create();//initializes gizmos class
	glClearColor(.8f, .8f, 0.8f, 1); //sets the clear color for the window
	glEnable(GL_DEPTH_TEST);//enables the depth buffer
	return 0;
	
}

int main()
{
	Start();
	Update();
}
