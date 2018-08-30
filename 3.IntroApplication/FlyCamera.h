#pragma once
#include "Camera.h"

class FlyCamera : public Camera
{
private:
	float speed;
	glm::vec3 up;
public:
	FlyCamera();
	void update(float deltaTime);
	void setSpeed(float speed);
};

