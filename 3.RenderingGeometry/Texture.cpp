#include "Texture.h"


Texture::Texture()
{
	m_fileName = ("none");
	m_width = 0;
	m_height = 0;
	m_handle = 0;
	m_format = 0;
	m_loadedpixels = nullptr;
}

Texture::Texture(const char * fileName)
{
	m_fileName = ("none");
	m_width = 0;
	m_height = 0;
	m_handle = 0;
	m_format = 0;
	m_loadedpixels = nullptr;

	load(fileName);
}

Texture::~Texture()
{
}

bool Texture::load(const char * fileName)
{
	return false;
}

void Texture::bind(unsigned int slot) const
{
}

void Texture::create(unsigned int width, unsigned int height, FORMAT format, unsigned char * pixels)
{
}

unsigned int Texture::getHandle() const
{
	return m_handle;
}

unsigned int Texture::getWidth() const
{
	return m_width;
}

unsigned int Texture::getHeight() const
{
	return m_height;
}

unsigned int Texture::getFormat() const
{
	return m_format;
}

const unsigned char * Texture::getPixels() const
{
	return m_loadedpixels;
}
