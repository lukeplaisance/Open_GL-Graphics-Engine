#include "RenderingGeometryApp.h"
#include <gl_core_4_4.h>
#include <glm/glm/glm.hpp>



RenderingGeometryApp::RenderingGeometryApp()
{
}


RenderingGeometryApp::~RenderingGeometryApp()
{
}

std::vector<glm::vec4> RenderingGeometryApp::GenHalfCircle(int np, int radius)
{
	std::vector<glm::vec4> points;
	int angle = 3.14 / np;
	for (float theta = 0; theta < 3.14; theta += angle)
	{
		points.push_back(glm::vec4(glm::cos(theta), glm::sin(theta), 0, 1));
	}

	return points;
}

std::vector<glm::vec4> RenderingGeometryApp::GenShpere(std::vector<glm::vec4> points, 
											std::vector<glm::vec4> allPoints, int numRotations)
{
	for (int i = 0; i < numRotations; i++)
	{
		
	}
	return std::vector<glm::vec4>();
}

void RenderingGeometryApp::startup()
{
	// A----B
	// |\	|
	// | \	|
	// |  \ |
	//D|---\|C
	//
	//
	mesh = new MeshRenderer();
	shader = new Shader();

	MeshRenderer::Vertex A = { glm::vec4(-10, 10, 0, 1), glm::vec4(1, 0, 0, 1) };
	MeshRenderer::Vertex B = { glm::vec4(10, 10, 0, 1), glm::vec4(0, 1, 0, 1) };
	MeshRenderer::Vertex C = { glm::vec4(10, -10, 0, 1), glm::vec4(0, 0, 1, 1) };
	MeshRenderer::Vertex D = { glm::vec4(-10, -10, 0, 1), glm::vec4(0, 0, 0, 1) };
	std::vector<MeshRenderer::Vertex> vertices = { A, B, C, D };
	std::vector<unsigned int> indices = { 0, 1, 2, 2, 3, 0 };
	mesh->initialize(indices, vertices);
	shader->defaultLoad();
	shader->attach();
	};

void RenderingGeometryApp::shutdown()
{
}

void RenderingGeometryApp::update(float dt)
{
	m_model = glm::mat4(1);
	glm::vec3 eye = glm::vec3(0, -10, -20);
	m_view = glm::lookAt(eye, m_model[3].xyz(), glm::vec3(0, 1, 0));
	m_projection = glm::perspective(glm::quarter_pi<float>(), 800 / (float)600, 0.1f, 1000.f);
}

void RenderingGeometryApp::draw()
{
	shader->Bind();
	int handle = shader->getUniform("ProjectionViewWorld");
	glm::mat4 mvp = m_projection * m_view * m_model;
	glUniformMatrix4fv(handle, 1, GL_FALSE, &mvp[0][0]);
	mesh->render();
	shader->UnBind();
}
