#include "Camera.h"
#include <GLFW/glfw3.h>


void Camera::UpdateProjectionView()
{
}

Camera::Camera()
{
	SetPerspective(glm::pi<float>() * .25f, 16 / 9.f, .1f, 1000.f);
	//SetOrtho(720.0f / 2, 720.0f / 2, 480.0f / 2, 480.0f / 2, .1, 1000);
}


Camera::~Camera()
{
}

glm::mat4 Camera::SetOrtho(float left, float right, float bottom, float top, float near, float far)
{
	m_projectionTransform[0].x = 2 / (right - left);
	m_projectionTransform[1].y = 2 / (top - bottom);
	m_projectionTransform[2].z = -2 / (far - near);
	m_projectionTransform[3].x = -((right + left) / (right - left));
	m_projectionTransform[3].y = -((top + bottom) / (top - bottom));
	m_projectionTransform[3].z = -((far + near) / (far - near));
	return m_projectionTransform;
}


glm::mat4 Camera::SetPerspective(float fieldOfView, float aspectRatio, float near, float far)
{
	m_projectionTransform[0].x = 1 / (aspectRatio * tan(fieldOfView / 2));
	m_projectionTransform[1].y = 1 / tan(fieldOfView / 2);
	m_projectionTransform[2].z = -((far + near) / (far - near));
	m_projectionTransform[2].w = -1;
	m_projectionTransform[3].z = ((2 * far * near) / (far - near));
	return m_projectionTransform;
}

void Camera::SetLookAt(glm::vec3 from, glm::vec3 to)
{
	glm::vec3 tmp = glm::vec3(0, 1, 0);
	glm::vec3 forward = glm::normalize(from - to);
	glm::vec3 right = glm::cross(glm::normalize(tmp), forward);
	glm::vec3 up = glm::cross(forward, right);

	m_viewTransform[0][0] = right.x;
	m_viewTransform[0][1] = right.y;
	m_viewTransform[0][2] = right.z;

	m_viewTransform[1][0] = up.x;
	m_viewTransform[1][1] = up.y;
	m_viewTransform[1][2] = up.z;

	m_viewTransform[2][0] = forward.x;
	m_viewTransform[2][1] = forward.y;
	m_viewTransform[2][2] = forward.z;

	m_viewTransform[3][0] = from.x;
	m_viewTransform[3][1] = from.y;
	m_viewTransform[3][2] = from.z;
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
