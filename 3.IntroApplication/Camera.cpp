#include <glfw3.h>
#include <glm/glm.hpp>
#include <glm/fwd.hpp>
#include <glm/ext.hpp>
#include "Camera.h"

Camera::Camera()
{
	worldTransform = glm::mat4(1);
	viewTransform = glm::lookAt(glm::vec3(worldTransform[3].x, worldTransform[3].x, worldTransform[3].x), glm::vec3(0), glm::vec3(0, 1, 0));
	projectionViewTransform = glm::perspective(glm::pi<float>() * .25f, 16 / 9.f, .1f, 1000.f);
	m_fov = glm::pi<float>() * 0.25f;
	m_aspectRatio = 16 / 9.0f;
	m_near = 0.1f;
	m_far = 1000.0f;
	setPerspective(m_fov, m_aspectRatio, m_near, m_far);
	setProjectionMatrix(projectionViewTransform, m_fov, m_aspectRatio, m_near, m_far);
}


void Camera::setPerspective(float fieldOfView, float aspectRatio, float near, float far)
{
	projectionTransform = glm::perspective(fieldOfView, aspectRatio, near, far);
}
void Camera::setProjectionMatrix(glm::mat4 orthographic, float fieldOfView, float aspectRatio, float near, float far)
{
	orthographic[0].x = 1/aspectRatio * tan(fieldOfView / 2);
	orthographic[1].y = 1 / tan(fieldOfView / 2);
	orthographic[2].z = -((far + near) / (far - near));
	orthographic[2].w = -1;
	orthographic[3].z = -(2 * (far*near) / (far - near));
}

void Camera::setLookAt(glm::vec3 from, glm::vec3 to, glm::vec3 up)
{
	viewTransform = glm::lookAt(from, to, up);
}

void Camera::setPosition(glm::vec3 position)
{
	worldTransform[3].x = position[0];
	worldTransform[3].y = position[1];
	worldTransform[3].z = position[2];	
}

glm::mat4 Camera::getWorldTransform()
{
	return this->worldTransform;
}

glm::mat4 Camera::getView()
{
	return this->viewTransform;
}

glm::mat4 Camera::getProjection()
{
	return this->projectionTransform;
}

glm::mat4 Camera::getProjectionView()
{
	return this->projectionViewTransform;
}

void Camera::updateProjetionViewTransform()
{
}
