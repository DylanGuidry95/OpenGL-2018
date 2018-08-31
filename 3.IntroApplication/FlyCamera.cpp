#include <iostream>
#include "FlyCamera.h"
#include "IntroductionApp.h"
#include <glfw3.h>
#include "Globals.h"

FlyCamera::FlyCamera()
{	
	speed = 1;
}

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
	//
	//double mouseDeltaX, mouseDeltaY, mouseStartX, mouseStartY, mouseCurrentX, mouseCurrentY;
	//bool isDragging = false;

	//if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE)
	//{
	//	isDragging = false;
	//	mouseDeltaX = mouseDeltaY = 0;
	//	mouseStartX = mouseStartY = 0;
	//}

	//if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
	//{
	//	if (isDragging == false)
	//	{
	//		isDragging = true;
	//		glfwGetCursorPos(window, &mouseStartX, &mouseStartY);
	//	}
	//	glfwGetCursorPos(window, &mouseCurrentX, &mouseCurrentY);
	//	mouseDeltaX = mouseCurrentX - mouseCurrentX;
	//	mouseDeltaY = mouseCurrentY - mouseCurrentX;
	//}

	//int windowWidth, windowHeight;
	//glfwGetWindowSize(window, &windowWidth, &windowHeight);

	//if (mouseDeltaY != 0)
	//{
	//	float angle = (mouseDeltaY/ windowHeight) * deltatime;
	//	Transform newTransform;
	//	newTransform.setWorld(worldTransform);
	//	newTransform.rotateAround(angle, worldTransform[3]);
	//	worldTransform = newTransform.World;
	//}
	//if (mouseDeltaX != 0)
	//{
	//	float angle = (mouseDeltaX/ windowWidth) * deltatime;
	//	Transform newTransform;
	//	newTransform.setWorld(worldTransform);
	//	newTransform.rotateAround(angle, glm::vec3(0,1,0));
	//	worldTransform = newTransform.World;
	//}
	
	/*if (glfwGetKey(window, GLFW_KEY_F))
	{
		glm::vec3 worldPos = glm::vec3(worldTransform[3].x, worldTransform[3].y, worldTransform[3].z);
		setLookAt(worldPos, glm::vec3(0), glm::vec3(0, 1, 0));
	}*/

	//viewTransform = glm::inverse(worldTransform);
	//projectionViewTransform = projectionTransform * viewTransform;
}

void FlyCamera::setSpeed(float speed)
{
	this->speed = speed;
}
