#include <gl_core_4_4.h>
#include <glm/glm.hpp>
#include <glfw3.h>
#include <Gizmos.h>
#include <glm\ext.hpp>

//How to set up openGL
//To set up the window in openGL, the first thing you should do is link the appropriate libraries(glfw3.lib, opengl32.lib). When that is set up, you need to add the
//gl_core_4_4.c and Gizmos header files into your project. Now that thats all set up, you can open up the project and include the <gl_core_4_4.h>, <glm / glm.hpp>,
//<glfw3.h>, <Gizmos.h>, <glm\ext.hpp> files at the top of the project. Now you need to initialize glfw. Once that is done, make a window with the glfwCreateWindow function.
//After that, set the instance of the window to the current openGL context. Next you need to use the ogl_LoadFunctions to get all of the openGL functions. Next create a while
//loop that can keep the window open so you can view it. Then swap buffers with glfwSwapBuffers function and put your window as the argument. Then call PollEvents. When
//you run this, it should open up a blank window.


//we need a base class to inherit from
//this base class will provide all the functionality we need to make seperate instances of our program
//each program


GLFWwindow* window;



void Update()
{
	glm::mat4 model = glm::mat4(1);
	glm::mat4 view = glm::lookAt(glm::vec3(10, 10, 10), glm::vec3(0), glm::vec3(0, 1, 0));
	glm::mat4 projection = glm::perspective(glm::pi<float>() * .25f, 16 / 9.f, .1f, 1000.f);

	while(glfwWindowShouldClose(window) || glfwGetKey(window, GLFW_KEY_ESCAPE))
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


#include "IntrodunctionApp.h"
int main()
{
	Application *newApp = new IntrodunctionApp();
}