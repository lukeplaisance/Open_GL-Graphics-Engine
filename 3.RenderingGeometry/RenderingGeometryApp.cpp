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

	for (float i = 0; i < np; i++)
	{
		float angle = 3.14 / (np - 1);
		float theta = i * angle;

		points.push_back(glm::vec4(glm::cos(theta) * radius, glm::sin(theta) * radius, 0, 1));
		points[i] = glm::round(points[i]);
	}
	return points;
}

std::vector<unsigned int> RenderingGeometryApp::GenIndices(int np, int nm)
{
	std::vector<unsigned int> indices;
	std::vector<unsigned int> bot_left;
	std::vector<unsigned int> bot_right;
	int i = 0;
	for (int y = 0; y < nm - 1; y++)
	{
		for (int j = 0; j < np; j++)
		{
			bot_left.push_back(i);
			bot_right.push_back(i + np);
			i++;
		}
	}

	for (int x = 1; x <= bot_left.size(); x++)
	{
		indices.push_back(bot_left[x-1]);
		indices.push_back(bot_right[x-1]);

		if (x % 3 == 0)
		{
			indices.push_back(0xFFFF);
		}
	}

	return indices;
}

std::vector<glm::vec4> RenderingGeometryApp::RotatePoints(std::vector<glm::vec4> points, unsigned int nm)
{
	std::vector<glm::vec4> allPoints;
	for (int i = 0; i < nm + 1; i++)
	{
		float angle = (3.14 / nm);
		float theta = i * angle;

		for (int j = 0; j < points.size(); j++)
		{
			float newX = points[j].x * cos(theta) + points[j].x * -sin(theta);
			float newY = points[j].y;
			float newZ = points[j].z * sin(theta) + points[j].z * cos(theta);

			allPoints.push_back(glm::vec4(newX, newY, newZ, 1));
			allPoints[i] = glm::round(allPoints[i]);
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
	//shader->defaultLoad();
	shader->load("ShaderSources/VERTEX.txt", Shader::SHADER_TYPE::VERTEX);
	shader->load("ShaderSources/FRAGMENT.txt", Shader::SHADER_TYPE::FRAGMENT);
	shader->attach();

	std::vector<glm::vec4> points = GenHalfCircle(3, 1);
	points = RotatePoints(points, 4);

	std::vector<unsigned int> indices = GenIndices(3, 4);
	std::vector<MeshRenderer::Vertex> vertices;
	MeshRenderer::Vertex vertex;

	for (glm::vec4 point : points)
	{
		vertex = {point, glm::vec4(1) };
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
	glm::vec3 eye = glm::vec3(0, -10, -50);
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
