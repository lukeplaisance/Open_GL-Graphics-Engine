
#include "IntroductionApp.h"
#include "Gizmos.h"
#include "Transform.h"
#include <glm/glm/glm.hpp>
#include <glm/glm/ext.hpp>
#include <glm/glm/fwd.hpp>
#include <glm/glm/common.hpp>





CameraApp::CameraApp(): model(1)
{
	modelTransform = new Transform();
}


CameraApp::~CameraApp()
{
}

void CameraApp::startup()
{
	Gizmos::create();
	
}

void CameraApp::shutdown()
{
	Gizmos::destroy();
}

void CameraApp::update(float dt)
{
	modelTransform->Translate(glm::vec3(glm::cos(dt), 0, 0));	
	model = modelTransform->getModel();
}

void CameraApp::draw()
{	
	glm::mat4 view = glm::lookAt(glm::vec3(10, 10, 25), glm::vec3(0), glm::vec3(0, 1, 0));//view
	glm::mat4 projection = glm::perspective(glm::pi<float>() * 0.25f, 16 / 9.f, 0.1f, 1000.f);//projection

																						//loop through the window
	bool lines = false;
	Gizmos::clear();
	
	Gizmos::addSphere(modelTransform->getLocalPosition(), 5, 10, 10, glm::vec4(.5, .25, .25, 1), &model);
	Gizmos::draw(projection * view);//draw
	 

}
