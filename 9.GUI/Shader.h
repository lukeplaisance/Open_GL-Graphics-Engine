#include <glm/glm\glm.hpp>
#include "gl_core_4_4.h"
#pragma once
class Shader
{
public:
	Shader();
	~Shader();
	void Bind();
	void UnBind();
	bool load(const char* filename, unsigned int type, bool isFile = true);
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
	bool isFile;
};

