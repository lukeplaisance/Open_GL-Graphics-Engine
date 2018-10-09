#pragma once
#include <string>
class Texture
{
public:
	enum FORMAT : unsigned int
	{
		RED = 1,
		RG,
		RGB,
		RGBA
	};
	Texture();
	Texture(const char* fileName);
	~Texture();
	bool load(const char* fileName);
	void bind(unsigned int slot) const;
	void create(unsigned int width, unsigned int height, FORMAT format, unsigned char* pixels = nullptr);
	unsigned int getHandle() const;
	unsigned int getWidth() const;
	unsigned int getHeight() const;
	unsigned int getFormat() const;
	const unsigned char* getPixels() const;

protected:
	std::string m_fileName;
	unsigned int m_width;
	unsigned int m_height;
	unsigned int m_handle;
	unsigned int m_format;
	unsigned char* m_loadedpixels;
};

