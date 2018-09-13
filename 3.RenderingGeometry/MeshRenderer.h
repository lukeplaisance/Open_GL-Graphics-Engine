#pragma once
#include <glm/glm.hpp>
#include <vector>
#include <Transform.h>

class MeshRenderer
{
public:
	MeshRenderer();
	~MeshRenderer();

	struct Vertex
	{
		glm::vec4 m_position;
		glm::vec4 m_color;
	};
	
	int initialize(std::vector<unsigned int>& indices, std::vector<Vertex>& vertices);
	int render();

private:
	std::vector<unsigned int> m_indices;
	std::vector<Vertex> m_vertices;

	unsigned int m_vao;
	unsigned int m_vbo;
	unsigned int m_ibo;

	int create_buffers();
};

