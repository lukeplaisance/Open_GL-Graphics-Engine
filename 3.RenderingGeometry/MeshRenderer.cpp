#include "MeshRenderer.h"
#include "gl_core_4_4.h"


MeshRenderer::MeshRenderer()
{
}


MeshRenderer::~MeshRenderer()
{
}

int MeshRenderer::initialize(std::vector<unsigned>& indices, std::vector<Vertex>& vertices)
{
	m_vbo = 0;
	m_vao = 0;
	m_ibo = 0;
	m_indices = indices;
	m_vertices = vertices;
	create_buffers();

	return 1;
}

int MeshRenderer::render()
{
	

	glBindVertexArray(m_vao);

	//set the draw mode to render the front and back of our geometry
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glPrimitiveRestartIndex(0xFFFF);
	glEnable(GL_PRIMITIVE_RESTART);

	glDrawElements(GL_TRIANGLE_STRIP, m_indices.size(), GL_UNSIGNED_INT, 0);
	glDisable(GL_PRIMITIVE_RESTART);


	//glUseProgram(0);
	glBindVertexArray(0);

	return 1;
}

int MeshRenderer::create_buffers()
{
	//gen vertex array
	glGenVertexArrays(1, &m_vao);

	//gen buffers
	glGenBuffers(1, &m_vbo);
	glGenBuffers(1, &m_ibo);

	glBindVertexArray(m_vao);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(Vertex), m_vertices.data(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size() * sizeof(unsigned int), m_indices.data(), GL_STATIC_DRAW);

	//positions
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

	//colors
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(glm::vec4)));

	//textures
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)32);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	return 1;
}
