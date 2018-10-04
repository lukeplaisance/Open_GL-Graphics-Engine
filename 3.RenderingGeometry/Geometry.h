#pragma once
#include <vector>
#include <Transform.h>
#include "MeshRenderer.h"
#include "Shader.h"
class Geometry
{
public:
	Geometry();
	~Geometry();

	MeshRenderer * mesh;
	Shader* shader;
	Transform * m_transform;

	float pos[3] = { 0,0,0 };

	std::vector<glm::vec4> GenHalfCircle(int np, int radius);

	void GenSphere(int radius, int np, int nm);

	std::vector<unsigned int> GenIndices(unsigned int np, unsigned int nm);

	std::vector<glm::vec4> RotatePoints(std::vector<glm::vec4> points,
		unsigned int numMeridians);

	std::vector<MeshRenderer::Vertex> GenCube(std::vector<MeshRenderer::Vertex> vertices);

	std::vector<unsigned int> genCubeIndices();
	
};

