#include <iostream>
#include "FlyCamera.h"
#include "IntroductionApp.h"
#include <glfw3.h>
#include "Globals.h"

FlyCamera::FlyCamera()
{	
	speed = 1;
}

double mouseDeltaX = 0, mouseDeltaY = 0, mouseStartX = 0, mouseStartY = 0, mouseCurrentX = 0, mouseCurrentY = 0;
bool isDragging = false;

void FlyCamera::update(float deltatime)
{
	//       P
	//[1 0 0 0]
	//[0 1 0 0]
	//[0 0 1 0]
	//[0 0 0 1]

	auto window = glfwGetCurrentContext();

	glm::vec3 currentPosition = glm::vec3(getWorldTransform()[3].x, getWorldTransform()[3].y, getWorldTransform()[3].z);
	if (glfwGetKey(window, GLFW_KEY_W))
	{
		setPosition(currentPosition + (glm::vec3(0, 0, speed)));
	}
	if (glfwGetKey(window, GLFW_KEY_S))
	{
		setPosition(currentPosition + (glm::vec3(0, 0, -speed)));
	}
	if (glfwGetKey(window, GLFW_KEY_D))
	{
		setPosition(currentPosition + (glm::vec3(speed, 0, 0)));
	}
	if (glfwGetKey(window, GLFW_KEY_A))
	{
		setPosition(currentPosition + (glm::vec3(-speed, 0, 0)));
	}
	
	if (glfwGetKey(window, GLFW_KEY_F))
	{
		glm::vec3 worldPos = glm::vec3(10, 0, 0);
		setLookAt(worldPos, glm::vec3(0), glm::vec3(0, 1, 0));
	}

	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS)
	{
		if (isDragging == false)
		{
			isDragging = true;
			glfwGetCursorPos(window, &mouseStartX, &mouseStartY);
		}
		glfwGetCursorPos(window, &mouseCurrentX, &mouseCurrentY);
		mouseDeltaX = mouseCurrentX - mouseStartX;
		mouseDeltaY = mouseCurrentY - mouseStartY;
	}

	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_RELEASE)
	{
		isDragging = false;
		mouseDeltaX = mouseStartX = 0;
		mouseDeltaY = mouseStartY = 0;
	}

	int windowWidth, windowHeight;
	glfwGetWindowSize(window, &windowWidth, &windowHeight);

	if (mouseDeltaY != 0)
	{
		float angle = (mouseDeltaY/ windowHeight) * deltatime;
		Transform newTransform;
		newTransform.setWorld(projectionTransform);
		newTransform.rotate(-angle, glm::vec3(1, 0, 0));
		projectionTransform = newTransform.World;
	}
	if (mouseDeltaX != 0)
	{
		float angle = (mouseDeltaX/ windowWidth) * deltatime;
		Transform newTransform;
		newTransform.setWorld(projectionTransform);
		newTransform.rotate(-angle, glm::vec3(0,1,0));
		projectionTransform = newTransform.World;
	}
	

	setProjectionMatrix(projectionViewTransform, m_fov, m_aspectRatio, m_near, m_far);
	projectionViewTransform = projectionTransform * viewTransform;
}

void FlyCamera::setSpeed(float speed)
{
	this->speed = speed;
}
