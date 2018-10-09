#pragma once
#include "Application.h"
#include <Transform.h>
#include "MeshRenderer.h"
#include "Shader.h"
#include "Camera.h"

class GUIApplication : public Application
{
public:

	MeshRenderer* mesh;
	Shader* shader;
	unsigned int m_program;

	glm::mat4 m_model;
	glm::mat4 m_view;
	glm::mat4 m_projection;

	int v4[4];
	Transform* m_transform;
	Camera* m_camera;

	std::vector<glm::vec4> GenHalfCircle(int np, int radius);

	void GenSphere(int radius, int np, int nm);

	std::vector<unsigned int> GenIndices(unsigned int np, unsigned int nm);

	std::vector<glm::vec4> RotatePoints(std::vector<glm::vec4> points,
		unsigned int numMeridians);

	std::vector<MeshRenderer::Vertex> GenCube(std::vector<MeshRenderer::Vertex> vertices);

	std::vector<unsigned int> genCubeIndices();
	

	GUIApplication();
	~GUIApplication();

	// Inherited via Application
	virtual void startup() override;
	virtual void shutdown() override;
	virtual void update(float dt) override;
	virtual void draw() override;
};
