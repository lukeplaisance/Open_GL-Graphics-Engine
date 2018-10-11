#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb-master/stb_image.h>
#include <gl_core_4_4.h>


Texture::Texture()
{
	m_fileName = ("none");
	m_width = 0;
	m_height = 0;
	m_handle = 0;
	m_loadedpixels = nullptr;
}

Texture::~Texture(){}

bool Texture::load(const char * fileName)
{
	if (m_handle != 0)
	{
		m_handle = 0;
		m_width = 0;
		m_height = 0;
		m_fileName = "none";
	}

	int comp = 0;
	int x = 0;
	int y = 0;
	m_loadedpixels = stbi_load(fileName, &x, &y, &comp, STBI_default);

	if (m_loadedpixels != nullptr)
	{
		glGenTextures(1, &m_handle);
		glBindTexture(GL_TEXTURE_2D, m_handle);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, x, y, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_loadedpixels);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glBindTexture(GL_TEXTURE_2D, 0);

		m_width = (unsigned int)x;
		m_height = (unsigned int)y;
		m_fileName = fileName;

		return true;
	}

	return true;
}

void Texture::bind(unsigned int slot) const
{
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, m_handle);
}
