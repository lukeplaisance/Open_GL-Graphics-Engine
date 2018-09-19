#include <glm/glm\glm.hpp>
#include "gl_core_4_4.h"
#pragma once
class Shader
{
public:
	enum SHADER_TYPE
	{
		VERTEX = 0,
		FRAGMENT = 1,
	};

	Shader();
	~Shader();
	void Bind();
	void UnBind();
	bool load(const char* filename, SHADER_TYPE shadertype);
	bool attach();
	void defaultLoad();

	unsigned int getUniform(const char*);
	unsigned int m_vertexShader;
	unsigned int m_fragmentShader;

	const char* vsSource;
	const char* fsSource;

	unsigned int m_program;
};

struct ShaderData
{
	Shader* shader;
	char* source;
	unsigned type;
};

