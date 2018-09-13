
#include "Transform.h"

//ToDo:: implement the rotation function
//document all of the steps necessary 
//you must include y rotation and z rotation 
//Use case: 
//	Input: Transform *myTransform = new Transform()
//		   Transform rotate90 = myTransform.Rotate(3.14/2.0, glm::vec3(1,0,0))
//	Expected Result:
//  rotate90.localRotation will be assigned the value 
//  0 -1   0
//  1  0   0
//  0  0   1
Transform::Transform()
{

	m_model = glm::mat4(1);
	m_worldPosition = m_model[3];
	m_localPosition = m_model[3];

	for (int col = 0; col < 3; col++)
	{
		m_worldRotation[col] = m_model[col].xyz;
		m_localRotation[col] = m_model[col].xyz;
	}
	//we have to initialize with just some base values
	//then we can track actual info. this is inconsistent
	//with what we are doing above but we can't initialize
	//scale with inverse rotation * scale because
	//scale has not been initialized yet
	m_localScale = glm::vec3(1, 1, 1);
	m_worldScale = glm::vec3(1, 1, 1);
}

Transform::~Transform()
{
	//we are not allocating memory with new 
	//so we have nothing in the destructor
}

glm::mat4 Transform::Translate(glm::vec3 move)
{
	glm::mat4 translation = glm::mat4(1);
	translation[3].xyz = move;
	m_model = m_model * translation;
	m_localPosition = m_model[3].xyz;
 
	return m_model;
}

glm::mat4 Transform::Rotate(float radians, glm::vec3 axis)
{
	auto cos = glm::cos(radians);
	auto sin = glm::sin(radians);
	auto rotation = glm::mat4(1);	
	if (glm::length(axis) > 1)
	{
		return glm::mat4(0);
	}
	
	
		//z rotation 
		//x   y    z
		//cos -sin  0
		//sin  cos  0
		//0    0	1
	return m_model;

}

glm::mat4 Transform::Scale(float size)
{
	glm::mat4 scale = glm::mat4(1);
	scale[0].x = size;
	scale[1].y = size;
	scale[2].z = size;
	m_model = m_model * scale;
	return m_model;
}

glm::vec3 Transform::getLocalPosition()
{
	return m_localPosition;
}

glm::mat4 Transform::getModel()
{
	return m_model;
}
