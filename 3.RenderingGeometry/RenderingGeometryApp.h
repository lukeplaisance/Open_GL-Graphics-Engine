#pragma once
#include "Application.h"
#include <vector>
#include <Transform.h>


class RenderingGeometryApp :public Application
{
public:
	struct Vertex
	{
		glm::vec4 position;
		glm::vec4 color;
	};

	RenderingGeometryApp();
	std::vector<int> m_indices;
	std::vector<Vertex> m_vertices;
	unsigned int m_vbo;
	unsigned int m_ibo;
	unsigned int m_vao;
	unsigned int m_program;

	~RenderingGeometryApp();

	// Inherited via Application
	virtual void startup() override;
	virtual void shutdown() override;
	virtual void update(float dt) override;
	virtual void draw() override;
};

