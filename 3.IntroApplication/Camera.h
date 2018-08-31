#pragma once
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/matrix.hpp>
#include "Transform.h"

class Camera
{	

protected:
	glm::mat4 worldTransform = glm::mat4{ 1 };
	glm::mat4 viewTransform;
	glm::mat4 projectionTransform;
	glm::mat4 projectionViewTransform;
	float m_fov;
	float m_aspectRatio;
	float m_near;
	float m_far;
	Transform m_target;

public:
	Camera();
	virtual void update(float deltaTime) = 0;
	void setPerspective(float fieldOfView, float aspectRatio, float near, float far);
	void setLookAt(glm::vec3 from, glm::vec3 to, glm::vec3 up);
	void setPosition(glm::vec3 position);
	glm::mat4 getWorldTransform();
	glm::mat4 getView();
	glm::mat4 getProjection();
	glm::mat4 getProjectionView();
	void updateProjetionViewTransform();
};