#include "RenderingGeometryApp.h"
#include <gl_core_4_4.h>
#include <glm/glm/glm.hpp>
#include "Geometry.h"
#include <GLFW/glfw3.h>



RenderingGeometryApp::RenderingGeometryApp()
{
	m_transform = new Transform();
	mesh = new MeshRenderer();
}


RenderingGeometryApp::~RenderingGeometryApp()
{
}

std::vector<glm::vec4> RenderingGeometryApp::GenHalfCircle(int np, int radius)
{
	std::vector<glm::vec4> points;

	for (float i = 0; i < np; i++)
	{
		float angle = glm::pi<float>() / ((float)np - 1);
		float theta = i * angle;

		points.push_back(glm::vec4(glm::cos(theta) * radius, glm::sin(theta) * radius, 0, 1));
	}
	return points;
}

void RenderingGeometryApp::GenSphere(int radius, int np, int nm)
{
	std::vector<unsigned int> indices;
	std::vector<MeshRenderer::Vertex> vertices;
	MeshRenderer::Vertex vertex;
	std::vector<glm::vec4> points;

	points = GenHalfCircle(np, radius);

	points = RotatePoints(points, nm);

	indices = GenIndices(nm, np);

	for (glm::vec4 point : points)
	{
		vertex = { point, glm::vec4(.5, .5, .5, 1) };
		vertices.push_back(vertex);
	}
	mesh->initialize(indices, vertices);
}

std::vector<unsigned int> RenderingGeometryApp::GenIndices(unsigned int np, unsigned int nm)
{
	std::vector<unsigned int> indices;

	unsigned int start;
	unsigned int bot_left;
	unsigned int bot_right;
	
	for (int y = 0; y < nm; y++)
	{
		start = y * np;

		for (int j = 0; j < np; j++)
		{
			bot_left = start + j;
			bot_right = bot_left + np;

			indices.push_back(bot_left);
			indices.push_back(bot_right);
		}
		indices.push_back(0xFFFF);
	}
	return indices;
}

std::vector<glm::vec4> RenderingGeometryApp::RotatePoints(std::vector<glm::vec4> points, unsigned int nm)
{
	std::vector<glm::vec4> allPoints;
	for (int i = 0; i < nm + 1; i++)
	{
		float angle = (glm::pi<float>() * 2.0f) / (float)nm;
		float theta = i * angle;

		for (int j = 0; j < points.size(); j++)
		{
			float newX = points[j].x;
			float newY = points[j].y * cos(theta) + points[j].z * -sin(theta);
			float newZ = points[j].z * cos(theta) + points[j].y * sin(theta);

			allPoints.push_back(glm::vec4(newX, newY, newZ, 1));
		}
	}
	return allPoints;
}

std::vector<MeshRenderer::Vertex> RenderingGeometryApp::GenCube(std::vector<MeshRenderer::Vertex> vertices)
{
	std::vector<MeshRenderer::Vertex> c_verts
	{
	//front
	{ glm::vec4(0.0, 1.0, 1.0, 1.0), glm::vec4(1, 0, 0, 1) },
	{ glm::vec4(1.0, 1.0, 1.0, 1.0), glm::vec4(0, 1, 0, 1) },
	{ glm::vec4(1.0, 0.0, 1.0, 1.0), glm::vec4(0, 0, 1, 1) },
	{ glm::vec4(0.0, 0.0, 1.0, 1.0), glm::vec4(1, 1, 0, 1) },

	//bot
	{ glm::vec4(0.0, 0.0, 0.0, 1.0), glm::vec4(1, 0, 0, 1) },
	{ glm::vec4(1.0, 0.0, 0.0, 1.0), glm::vec4(0, 1, 1, 1) },

	//back
	{ glm::vec4(1.0, 1.0, 0.0, 1.0), glm::vec4(1, 1, 1, 1) },
	{ glm::vec4(0.0, 1.0, 0.0, 1.0), glm::vec4(1, 0, 0, 1) },

	//top
	{ glm::vec4(0.0, 1.0, 1.0, 1.0), glm::vec4(1, 1, 1, 1) },
	{ glm::vec4(1.0, 1.0, 1.0, 1.0), glm::vec4(1, 0, 1, 1) },

	//right
	{ glm::vec4(1.0, 1.0, 0.0, 1.0), glm::vec4(1, 0, 1, 1) },
	{ glm::vec4(1.0, 0.0, 0.0, 1.0), glm::vec4(1, 0, 1, 1) },

	//left
	{ glm::vec4(1.0, 1.0, 0.0, 1.0), glm::vec4(1, 0, 1, 1) },
	{ glm::vec4(0.0, 0.0, 0.0, 1.0), glm::vec4(1, 0, 0, 1) }
	};
	return c_verts;
}

std::vector<unsigned int> RenderingGeometryApp::genCubeIndices()
{
	std::vector<unsigned int> indices =
	{	0,1,2,2,3,0,//front
		3,2,4,4,5,2,//Bot
		4,5,6,6,7,4,//Back
		6,7,8,8,9,6,//Top
		2,1,10,10,11,2,//Right
		0,3,12,12,13,0//Left
	};
	return indices;
}

void RenderingGeometryApp::startup()
{
	shader = new Shader();
	Geometry * geo = new Geometry();
	
	// A----B
	// |\	|
	// | \	|
	// |  \ |
	//D|---\|C
	//
	//
	//shader->defaultLoad();
	shader->load("ShaderSources/VERTEX.vert", Shader::SHADER_TYPE::VERTEX);
	shader->load("ShaderSources/BLINN_SHADER_FRAG.frag", Shader::SHADER_TYPE::FRAGMENT);
	shader->attach();
	

	GenSphere(5, 100, 100);
	/*std::vector<MeshRenderer::Vertex> vertices = GenCube(vertices);
	std::vector<unsigned int> indices = genCubeIndices();
	mesh->initialize(indices, vertices);*/
};

void RenderingGeometryApp::shutdown()
{
}

float rt = 0;
void RenderingGeometryApp::update(float dt)
{
	rt += dt;
	glm::mat4 rot;
	glm::mat4 trans;
	float angle = glm::cos(rt*0.001f) * dt;
	rot = glm::rotate(glm::mat4(1), angle, glm::vec3(0, 1, 0));
	trans = glm::translate(glm::mat4(1), glm::vec3(0, 0, 0));
	m_view = glm::lookAt(glm::vec3(10, -10, -10), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	m_projection = glm::perspective(glm::quarter_pi<float>(), 800 / (float)600, 0.1f, 1000.f);
	m_model = glm::mat4(1) * trans * rot;
	m_model = glm::mat4(1);
}

void RenderingGeometryApp::draw()
{
	shader->Bind();
	int handle = shader->getUniform("ProjectionViewWorld");
	int lightPosHandle = shader->getUniform("lightPos");
	int lightColorHandle = shader->getUniform("lightColor");
	int lightDirHandle = shader->getUniform("lightDir");
	int cameraPosHandle = shader->getUniform("cameraPos");

	glm::mat4 mvp = m_projection * m_view * m_model;
	glUniformMatrix4fv(handle, 1, GL_FALSE, &mvp[0][0]);
	auto pos = glm::vec3(0, 0, 0);
	auto col = glm::vec3(1, .5, 0);
	auto dir = glm::vec3(0, 1, 0);
	auto cameraPos = glm::vec3(10, -10, -10);

	glUniform3fv(lightPosHandle, 1, &pos[0]);
	glUniform3fv(lightColorHandle, 1, &col[0]);
	glUniform3fv(lightDirHandle, 1, &dir[0]);
	glUniform3fv(cameraPosHandle, 1, &cameraPos[0]);
	mesh->render();
	shader->UnBind();
}
