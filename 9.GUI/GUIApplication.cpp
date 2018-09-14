#include "GUIApplication.h"
#include <glm/glm/glm.hpp>
#include "imgui.h"
#include <gl_core_4_4.h>


GUIApplication::GUIApplication()
{
}

GUIApplication::~GUIApplication()
{
}

void GUIApplication::startup()
{
	m_model = glm::mat4(1);
	mesh = new MeshRenderer();
	shader = new Shader();
	m_transform = new Transform();

	MeshRenderer::Vertex A = { glm::vec4(-10, 10, 0, 1), glm::vec4(1, 0, 0, 1) };
	MeshRenderer::Vertex B = { glm::vec4(10, 10, 0, 1), glm::vec4(0, 1, 0, 1) };
	MeshRenderer::Vertex C = { glm::vec4(10, -10, 0, 1), glm::vec4(0, 0, 1, 1) };
	MeshRenderer::Vertex D = { glm::vec4(-10, -10, 0, 1), glm::vec4(0, 0, 0, 1) };
	std::vector<MeshRenderer::Vertex> vertices = { A, B, C, D };
	std::vector<unsigned int> indices = { 0, 1, 2, 2, 3, 0 };
	mesh->initialize(indices, vertices);
	shader->defaultLoad();
	shader->attach();
}

void GUIApplication::shutdown()
{
}



void GUIApplication::update(float dt)
{
	glm::vec3 eye = glm::vec3(0, -10, 20);
	m_view = glm::lookAt(eye, m_model[3].xyz(), glm::vec3(0, 1, 0));
	m_projection = glm::perspective(glm::quarter_pi<float>(), 800 / (float)600, 0.1f, 1000.f);
}

void GUIApplication::draw()
{

	if (ImGui::Button("Right", ImVec2(100, 100)))
	{
		m_transform->Translate(glm::vec3(1, 0, 0));
	}
	if (ImGui::Button("Left", ImVec2(100, 100)))
	{
		m_transform->Translate(glm::vec3(-1, 0, 0));
	}
	if (ImGui::Button("Up", ImVec2(100, 100)))
	{
		m_transform->Translate(glm::vec3(0, 1, 0));
	}
	if (ImGui::Button("Down", ImVec2(100, 100)))
	{
		m_transform->Translate(glm::vec3(0, -1, 0));
	}

	shader->Bind();
	int handle = shader->getUniform("ProjectionViewWorld");
	glm::mat4 mvp = m_projection * m_view * m_transform->getModel();
	glUniformMatrix4fv(handle, 1, GL_FALSE, &mvp[0][0]);
	mesh->render();
	shader->UnBind();
}
