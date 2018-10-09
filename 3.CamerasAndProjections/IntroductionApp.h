#pragma once
#include "Application.h"
#include "Transform.h"

class CameraApp : public Application
{
public:
	CameraApp();
	 
protected:
	void startup() override;
	void shutdown() override;
	void update(float dt) override;
	void draw() override;
public:
	~CameraApp() override;

protected:
	glm::mat4 model = glm::mat4(1);
	glm::mat4 view = glm::lookAt(glm::vec3(10, 10, 10), glm::vec3(0), glm::vec3(0, 1, 0));
	glm::mat4 projection = glm::perspective(glm::pi<float>() * .25f, 16 / 9.f, .1f, 1000.f);
};

