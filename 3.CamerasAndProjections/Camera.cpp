#include "Camera.h"
#include <glfw3.h>


void Camera::UpdateProjectionView()
{
}

Camera::Camera()
{
	//SetPerspective(glm::pi<float>() * .25f, 16 / 9.f, .1f, 1000.f);
	//SetOrtho(720.0f / 2, 720.0f / 2, 480.0f / 2, 480.0f / 2, .1, 1000);
}


Camera::~Camera()
{
}

void Camera::SetOrtho(float left, float right, float bottom, float top, float near, float far)
{
	m_projectionTransform = glm::ortho(left, right, bottom, top, near, far);
}


void Camera::SetPerspective(float fieldOfView, float aspectRatio, float near, float far)
{
	m_projectionTransform = glm::perspective(fieldOfView, aspectRatio, near, far);
}

void Camera::SetLookAt(glm::vec3 from, glm::vec3 to, glm::vec3 up)
{
	float cam_radius = 10.0f;
	float camX = sin(glfwGetTime()) * cam_radius;
	float camZ = cos(glfwGetTime()) * cam_radius;

	from = glm::vec3(camX, 0, camZ);
	to = glm::vec3(0, 0, 0);
	up = glm::vec3(0, 1, 0);

	m_viewTransform = glm::lookAt(glm::vec3(10, 10, 10), glm::vec3(0), glm::vec3(0, 1, 0));
}

void Camera::SetPosition(glm::vec3 position)
{
	m_worldTransform[3].x = position.x;
	m_worldTransform[3].y = position.y;
	m_worldTransform[3].z = position.z;
}

glm::mat4 Camera::getWorldTransform()
{
	return this->m_worldTransform;
}

glm::mat4 Camera::getView()
{
	return this->m_viewTransform;
}

glm::mat4 Camera::getProjection()
{
	return this->m_projectionTransform;
}

glm::mat4 Camera::getProjectionView()
{
	return m_projectionViewTransform;
}
