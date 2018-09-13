#include "Shader.h"
#include <assert.h>



Shader::Shader()
{
	m_program = glCreateProgram();
}


Shader::~Shader()
{
}

void Shader::Bind()
{
	glUseProgram(m_program);
}

void Shader::UnBind()
{
	glUseProgram(0);
}

bool Shader::load(const char * filename, unsigned int type, bool isFile)
{
	//Load shader with file name
	//Vertex Shader data
	vsSource = "Vertex";
	//Fragment shader data
	fsSource = "fragment";

	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	//specify the code we are going to compile
	glShaderSource(vertexShader, 1, (const char**)&vsSource, 0);
	glCompileShader(vertexShader);

	glShaderSource(fragmentShader, 1, (const char**)&fsSource, 0);
	glCompileShader(fragmentShader);
}

bool Shader::attach()
{
	return false;
}

void Shader::defaultLoad()
{
	//Default Shaders
	vsSource = "#version 410\n \
                            layout(location = 0) in vec4 Position; \
                            layout(location = 1) in vec4 Color; \
                            out vec4 vColor; \
                            uniform mat4 ProjectionViewWorld; \
                            void main() { vColor = Color; \
                            gl_Position = ProjectionViewWorld * Position; }";

	fsSource = "#version 410\n \
                            in vec4 vColor; \
                            out vec4 FragColor; \
                            void main() { FragColor = vColor; }";

	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	//specify the code we are going to compile
	glShaderSource(vertexShader, 1, (const char**)&vsSource, 0);
	glCompileShader(vertexShader);

	glShaderSource(fragmentShader, 1, (const char**)&fsSource, 0);
	glCompileShader(fragmentShader);
}

unsigned int Shader::getUniform(const char * name)
{
	return glGetUniformLocation(m_program, name);
}
