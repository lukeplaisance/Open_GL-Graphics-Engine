#include "IntroductionApp.h"
#include <glm/glm/glm.hpp>
#include "Gizmos.h"


//finish header file
//make main work that abides to the header file

CameraApp::CameraApp()
{
}

CameraApp::~CameraApp()
{
}


void CameraApp::startup()
{
	Gizmos::create();
	model = glm::mat4(1);
	cam->SetLookAt(glm::vec3(10, 10, 10), glm::vec3(0));
	cam->SetSpeed(3.0f);
}

void CameraApp::shutdown()
{
	Gizmos::destroy();
}

void CameraApp::draw()
{
	Gizmos::clear();
	Gizmos::addSphere(glm::vec3(0, 0, 0), 5.f, 30, 30, glm::vec4(10, 0, 0, .5), &model);
	Gizmos::draw(cam->getProjection() * cam->getView() * cam->getWorldTransform());
}

void CameraApp::update(float dt)
{
	Transform trans = Transform();
	trans.m_world = model;
	model = trans.Rotate(dt, glm::vec3(0, 1, 0));
	trans.m_world = cam->getWorldTransform();
}
