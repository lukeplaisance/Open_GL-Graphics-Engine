#include "FlyCamera.h"
#include <GLFW\glfw3.h>


FlyCamera::FlyCamera()
{
}


FlyCamera::~FlyCamera()
{
}

double mouseDeltaX = 0, mouseDeltaY = 0, mouseStartX = 0, mouseStartY = 0,
mouseCurrentX = 0, mouseCurrentY = 0;
bool isDragging = false;

void FlyCamera::Update(float dt)
{
	auto window = glfwGetCurrentContext();
	auto currentPos = glm::vec3((getWorldTransform()[3].x), (getWorldTransform()[3].y), (getWorldTransform()[3].z));
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		SetPosition(currentPos += glm::vec3(0, 0, m_speed) * dt);
	}

	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		SetPosition(currentPos -= glm::vec3(0, 0, m_speed) * dt);
	}

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		SetPosition(currentPos += glm::vec3(-m_speed, 0, 0) * dt);
	}

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		SetPosition(currentPos += glm::vec3(m_speed, 0, 0) * dt);
	}
	m_projectionViewTransform = m_viewTransform * m_projectionTransform;

	

	if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_RELEASE)
	{
		isDragging = false;
		mouseDeltaX = mouseStartX = 0;
		mouseDeltaY = mouseStartY = 0;
	}

	if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS)
	{
		if(isDragging == false)
		{
			isDragging = true;
			glfwGetCursorPos(window, &mouseStartX, &mouseStartY);
		}
		glfwGetCursorPos(window, &mouseCurrentX, &mouseCurrentY);
		mouseDeltaX = mouseCurrentX - mouseStartX;
		mouseDeltaY = mouseCurrentY - mouseStartY;
	}

	int windowWidth, windowHeight;
	glfwGetWindowSize(window, &windowWidth, &windowHeight);

	if (mouseDeltaY != 0)
	{
		float angle = (mouseDeltaY / windowHeight) * dt;
		Transform newTransform;
		newTransform.m_world = m_projectionTransform;
		newTransform.Rotate(-angle, glm::vec3(1, 0, 0));
		m_projectionTransform = newTransform.m_world;
	}
	if (mouseDeltaX != 0)
	{
		float angle = (mouseDeltaX / windowWidth) * dt;
		Transform newTransform;
		newTransform.m_world = m_projectionTransform;
		newTransform.Rotate(-angle, glm::vec3(0, 1, 0));
		m_projectionTransform = newTransform.m_world;
	}
}

void FlyCamera::SetSpeed(float speed)
{
	m_speed = speed;
}
