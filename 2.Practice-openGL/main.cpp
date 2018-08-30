#define GLM_ENABLE_EXPERIMENTAL
#include <gl_core_4_4.h>
#include <glfw3.h>
#include <Gizmos.h>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm\ext.hpp>


GLFWwindow* window;
int Start()
{
	glfwInit();

	window = glfwCreateWindow(800, 800, "open GL", NULL, NULL);
	glfwMakeContextCurrent(window);

	auto loaded = ogl_LoadFunctions();
	auto major = ogl_GetMajorVersion();
	auto minor = ogl_GetMinorVersion();

	Gizmos::create();
	return 0;
}

void Update()
{
	glm::mat4 model = glm::mat4(1);
	glm::mat4 view = glm::lookAt(glm::vec3(10, 10, 10), glm::vec3(0), glm::vec3(0, 1, 0));
	glm::mat4 projection = glm::perspective(glm::pi<float>() * .25f, 16 / 9.f, .1f, 1000.f);

	while (glfwWindowShouldClose(window) || glfwGetKey(window, GLFW_KEY_ESCAPE))
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

int main()
{
	Start();
	Update();
}