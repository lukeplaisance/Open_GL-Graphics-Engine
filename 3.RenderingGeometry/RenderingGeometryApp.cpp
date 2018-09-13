#include "RenderingGeometryApp.h"
#include <gl_core_4_4.h>



RenderingGeometryApp::RenderingGeometryApp()
{
}


RenderingGeometryApp::~RenderingGeometryApp()
{
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

	m_vertices =
	{//this was copied wrong -luke
		{ glm::vec4(-10, 10, 0, 1), glm::vec4(1, 0, 0, 1) },
		{ glm::vec4(10, 10, 0, 1), glm::vec4(0, 1, 0, 1) },
		{ glm::vec4(10, -10, 0, 1), glm::vec4(0, 0, 1, 1) },
		{ glm::vec4(-10, -10, 0, 1), glm::vec4(0, 0, 0, 1) },
	};

	glGenBuffers(1, &m_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(m_vertices) * m_vertices.size(), &m_vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)sizeof(glm::vec4));

	glBindBuffer(GL_ARRAY_BUFFER, 0);


	m_indices = std::vector<int>{ 0,1,2,2,3,0 };
	glGenBuffers(1, &m_ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(m_indices) * m_indices.size(), &m_indices, GL_STATIC_DRAW);

}

void RenderingGeometryApp::shutdown()
{
}

void RenderingGeometryApp::update(float dt)
{
}

void RenderingGeometryApp::draw()
{
	glUseProgram(m_program);
	glBindVertexArray(m_vao);


	glBindVertexArray(0);
	glUseProgram(0);

	glDrawElements(GL_TRIANGLE_STRIP, m_indices.size(), GL_UNSIGNED_INT, 0);
}
