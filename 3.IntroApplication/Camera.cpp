#include <glfw3.h>
#include <glm/glm.hpp>
#include <glm/fwd.hpp>
#include <glm/ext.hpp>
#include "Camera.h"

Camera::Camera()
{
	worldTransform = glm::mat4(1);
	//viewTransform = glm::lookAt(glm::vec3(10, 10, 10), glm::vec3(0), glm::vec3(0, 1, 0));
	//projectionViewTransform = glm::perspective(glm::pi<float>() * .25f, 16 / 9.f, .1f, 1000.f);
	m_fov = glm::pi<float>() * 0.25f;
	m_aspectRatio = 16 / 9.0f;
	m_near = 0.1f;
	m_far = 1000.0f;
	setPerspective(m_fov, m_aspectRatio, m_near, m_far);}

void Camera::setPerspective(float fieldOfView, float aspectRatio, float near, float far)
{
	projectionTransform = glm::perspective(fieldOfView, aspectRatio, near, far);
	//m_fov = fieldOfView;
	//m_aspectRatio = aspectRatio;
	//m_near = near;
	//m_far = far;

	//const float x = 1.f / (m_aspectRatio * tan(m_fov / 2.f));
	//const float y = 1.f / tan(m_fov / 2.f);
	//const float z = -1.f * ((m_far + m_near) / (m_far - m_near));
	//const float w = -1.f * ((2.f * m_far * m_near) / (m_far - m_near));

	//const glm::mat4 projection = glm::mat4(
	//	glm::vec4(x, 0, 0, 0),//xcol
	//	glm::vec4(0, y, 0, 0),//ycol
	//	glm::vec4(0, 0, z, -1),//zcol
	//	glm::vec4(0, 0, w, 0));//wcol or translation


	//projectionTransform = projection;
}

void Camera::setLookAt(glm::vec3 from, glm::vec3 to, glm::vec3 up)
{
	viewTransform = glm::lookAt(from, to, up);
	//m_target = m_target;
	//m_up = up;

	//const glm::vec3 z = normalize(eye - target);
	//const glm::vec3 x = normalize(cross(up, z));
	//const glm::vec3 y = cross(z, x);

	//const glm::mat4 V = glm::mat4(
	//	glm::vec4(x.x, y.x, z.x, 0),
	//	glm::vec4(x.y, y.y, z.y, 0),
	//	glm::vec4(x.z, y.z, z.z, 0),
	//	glm::vec4(0.0, 0.0, 0.0, 1)
	//);

	//const glm::mat4 T = glm::mat4(
	//	glm::vec4(1, 0, 0, 0),
	//	glm::vec4(0, 1, 0, 0),
	//	glm::vec4(0, 0, 1, 0),
	//	glm::vec4(-eye, 1)
	//);

	//glm::mat4 actual = V * T;
	//glm::mat4 expected = lookAt(eye, target, up);
	//assert(actual == expected);
	//m_view = V * T;
	//m_world = glm::inverse(m_view);
	//m_transform.setWorld(m_world);
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
