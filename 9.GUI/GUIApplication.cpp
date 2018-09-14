#include "GUIApplication.h"
#include "imgui.h"
#include <gl_core_4_4.h>

void GUIApplication::startup()
{
	/*shader = new Shader();

	MeshRenderer::Vertex A = { glm::vec4(-10, 10, 0, 1), glm::vec4(1, 0, 0, 1) };
	MeshRenderer::Vertex B = { glm::vec4(10, 10, 0, 1), glm::vec4(0, 1, 0, 1) };
	MeshRenderer::Vertex C = { glm::vec4(10, -10, 0, 1), glm::vec4(0, 0, 1, 1) };
	MeshRenderer::Vertex D = { glm::vec4(-10, -10, 0, 1), glm::vec4(0, 0, 0, 1) };
	std::vector<MeshRenderer::Vertex> vertices = { A, B, C, D };
	std::vector<unsigned int> indices = { 0, 1, 2, 2, 3, 0 };
	mesh->initialize(indices, vertices);
	shader->defaultLoad();
	shader->attach();*/
}

void GUIApplication::shutdown()
{
}

void GUIApplication::update(float dt)
{
}

void GUIApplication::draw()
{
	ImGui::Button("button");
}
