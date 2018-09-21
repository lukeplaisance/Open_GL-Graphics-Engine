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
	Transform* m_transform;
	
	unsigned int m_program;

	glm::mat4 m_model;
	glm::mat4 m_view;
	glm::mat4 m_projection;

	RenderingGeometryApp();
	~RenderingGeometryApp();

	std::vector<glm::vec4> GenHalfCircle(int np, int radius);

	void GenSphere(float np, float nm, float radius);

	std::vector<glm::vec4> RotatePoints(std::vector<glm::vec4> points, 
									unsigned int numMeridians);

	// Inherited via Application
	virtual void startup() override;
	virtual void shutdown() override;
	virtual void update(float dt) override;
	virtual void draw() override;
};

