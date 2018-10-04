#include "Geometry.h"


Geometry::Geometry()
{
	mesh = new MeshRenderer();
}


Geometry::~Geometry()
{
}

std::vector<glm::vec4> Geometry::GenHalfCircle(int np, int radius)
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

void Geometry::GenSphere(int radius, int np, int nm)
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

std::vector<unsigned int> Geometry::GenIndices(unsigned int np, unsigned int nm)
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

std::vector<glm::vec4> Geometry::RotatePoints(std::vector<glm::vec4> points, unsigned int nm)
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

std::vector<MeshRenderer::Vertex> Geometry::GenCube(std::vector<MeshRenderer::Vertex> vertices)
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

std::vector<unsigned int> Geometry::genCubeIndices()
{
	std::vector<unsigned int> indices =
	{ 0,1,2,2,3,0,//front
		3,2,4,4,5,2,//Bot
		4,5,6,6,7,4,//Back
		6,7,8,8,9,6,//Top
		2,1,10,10,11,2,//Right
		0,3,12,12,13,0//Left
	};
	return indices;
}