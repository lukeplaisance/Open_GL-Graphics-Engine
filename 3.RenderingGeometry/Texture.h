#pragma once
#include <string>
class Texture
{
public:
	Texture();
	~Texture();
	bool load(const char* fileName);
	void bind(unsigned int slot) const;
	unsigned int getHandle() const { return m_handle; };
	unsigned int getWidth() const { return m_width; };
	unsigned int getHeight() const { return m_height; };
	const unsigned char* getPixels() const { return m_loadedpixels; };

protected:
	std::string m_fileName;
	unsigned int m_width;
	unsigned int m_height;
	unsigned int m_handle;
	unsigned char* m_loadedpixels;
};

