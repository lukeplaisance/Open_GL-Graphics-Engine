#pragma once
#include <Application.h>
#include <vector>
#include <Transform.h>
#include "MeshRenderer.h"
#include "Shader.h"


class RenderingGeometryApp :public Application
{
public:

	MeshRenderer* mesh;
	Shader* shader;
	unsigned int m_program;

	glm::mat4 m_model;
	glm::mat4 m_view;
	glm::mat4 m_projection;

	RenderingGeometryApp();
	~RenderingGeometryApp();

	// Inherited via Application
	virtual void startup() override;
	virtual void shutdown() override;
	virtual void update(float dt) override;
	virtual void draw() override;
};

