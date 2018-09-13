#pragma once
#define GLM_FORCE_SWIZZLE
#include <glm/glm/glm.hpp>
#include <glm/glm/ext.hpp>
#include <glm/glm/fwd.hpp>
#include <glm/glm/common.hpp>


class Transform
{
public:
	Transform();
	~Transform();	
	//TRS
	glm::mat4 Translate(glm::vec3 move);
	glm::mat4 Rotate(float radians, glm::vec3 axis);
	glm::mat4 Scale(float size);
	glm::vec3 getLocalPosition();
	glm::mat4 getModel();

private:	
	/*
	glm::mat4(1)
	m_model[0] = 1 0 0 0
	m_model[1] = 0 1 0 0
	m_model[2] = 0 0 1 0
	m_model[3] = 0 0 0 1
	x y z w
	1 0 0 0
	0 1 0 0
	0 0 1 0
	0 0 0 1
	*/
	glm::mat4 m_model; //identity 
	glm::vec3 m_worldPosition;//m_model[3]
	glm::vec3 m_localPosition;//m_model[3]

	glm::mat3 m_worldRotation;//inner 3 x 3 of the model
	glm::mat3 m_localRotation;

	glm::vec3 m_localScale; // this is the diagonal
	glm::vec3 m_worldScale; // what we deal with is affine 
	//or uniform scale
};