#include "RenderingGeometryApp.h"
#include <gl_core_4_4.h>
#include <glm/glm/glm.hpp>



RenderingGeometryApp::RenderingGeometryApp()
{
	m_transform = new Transform();
}


RenderingGeometryApp::~RenderingGeometryApp()
{
}

std::vector<glm::vec4> RenderingGeometryApp::GenHalfCircle(int np, int radius)
{
	std::vector<glm::vec4> points;
	float angle = 3.14 / np;
	for (float theta = 0; theta < 3.14; theta += angle)
	{
		points.push_back(glm::vec4(glm::cos(theta) * radius, glm::sin(theta) * radius, 0, 1));
	}

	return points;
}

void RenderingGeometryApp::GenSphere(float np, float nm, float radius)
{
	std::vector<glm::vec4> meshPoints;
	std::vector<MeshRenderer::Vertex> vertices;
	std::vector<unsigned int> indicies;

	std::vector<glm::vec4> halfCircle = GenHalfCircle(np, radius);
	halfCircle = RotatePoints(halfCircle, nm);

	for (auto index : meshPoints)
	{
		MeshRenderer::Vertex verts = { glm::vec4(1), glm::normalize(index) };
		vertices.push_back(verts);
	}
	mesh->initialize(indicies, vertices);

}

std::vector<glm::vec4> RenderingGeometryApp::RotatePoints(std::vector<glm::vec4> points, unsigned int nm)
{
	std::vector<glm::vec4> allPoints;
	for (int i = 0; i < nm + 1; i++)
	{
		float sphereSlice = (3.14 / 2.0f);
		float theta = i / sphereSlice;

		for (int j = 0; j < points.size(); j++)
		{
			float newX = points[j].x;
			float newY = points[j].y * cos(theta) + points[j].y * sin(theta);
			float newZ = points[j].z * -sin(theta) + points[j].z * cos(theta);

			allPoints.push_back(glm::vec4(newX, newY, newZ, 1));
		}
	}
	return allPoints;
}

void RenderingGeometryApp::startup()
{
	shader = new Shader();
	mesh = new MeshRenderer();
	// A----B
	// |\	|
	// | \	|
	// |  \ |
	//D|---\|C
	//
	//
	shader->defaultLoad();
	shader->attach();
	std::vector<glm::vec4> points = GenHalfCircle(10, 5);
	points = RotatePoints(points, 10);
	std::vector<unsigned int> indices;
	for (int i = 0; i < points.size(); i++)
	{
		indices.push_back(i);
	}

	std::vector<MeshRenderer::Vertex> vertices;
	MeshRenderer::Vertex vertex;

	for (glm::vec4 point : points)
	{
		vertex = {point, glm::vec4(1, 1, 1, 1) };
		vertices.push_back(vertex);
	}
	mesh->initialize(indices, vertices);
	
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
