#pragma once
#include "Camera.h"
#include "Transform.h"

class FlyCamera : public Camera
{
	float m_speed;
	glm::vec3 m_up;

public:
	FlyCamera();
	~FlyCamera();
	
	void Update(float dt);
	void SetSpeed(float speed);
};

