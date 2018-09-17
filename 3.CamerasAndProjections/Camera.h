#pragma once
#include <glm/glm.hpp>
#include <glm/glm/ext.hpp>

class Camera
{

	void UpdateProjectionView();

protected:
	glm::mat4 m_worldTransform = glm::mat4 {1};
	glm::mat4 m_viewTransform = glm::lookAt(glm::vec3(10, 10, 10), glm::vec3(0), glm::vec3(0, 1, 0));
	glm::mat4 m_projectionTransform = glm::perspective(glm::pi<float>() * .25f, 16 / 9.f, .1f, 1000.f);
	glm::mat4 m_projectionViewTransform = glm::mat4{ 0 };

public:
	Camera();
	virtual ~Camera();

	virtual void Update(float dt) = 0;
	void SetPerspective(float fieldOfView, float aspectRatio, float near, float far);
	void SetOrtho(float left, float right, float bottom, float top, float near, float far);
	void SetLookAt(glm::vec3 from, glm::vec3 to, glm::vec3 up);
	void SetPosition(glm::vec3 position);
	glm::mat4 getWorldTransform();
	glm::mat4 getView();
	glm::mat4 getProjection();
	glm::mat4 getProjectionView();
};

