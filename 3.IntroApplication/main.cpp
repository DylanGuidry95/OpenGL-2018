
#include "IntroductionApp.h"
#include "Transform.h"
#include <glm/gtx/string_cast.hpp>
#include <assert.h>

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


int main()
{
	Application* app = new IntroductionApp();
	app->run("Application", 800, 600, false);
}