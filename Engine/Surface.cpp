#include "Surface.h"
#include <string>
#include <wingdi.h>
#include <fstream>
#include <iostream>
#include <assert.h>

Surface::Surface(std::string filename)
{
	try
	{
		std::ifstream file;
		file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		file.open(filename, std::iostream::binary);

		BITMAPFILEHEADER bmFileHeader;
		file.read(reinterpret_cast<char*>(&bmFileHeader), sizeof(bmFileHeader));

		BITMAPINFOHEADER bmInfoHeader;
		file.read(reinterpret_cast<char*>(&bmInfoHeader), sizeof(bmInfoHeader));

		width = bmInfoHeader.biWidth;
		height = abs(bmInfoHeader.biHeight);
		pPixels = std::make_unique<Color[]>(width * height);

		if (!(bmInfoHeader.biBitCount == 32) && !(bmInfoHeader.biBitCount == 24))
		{
			throw std::runtime_error("Bitmap file: '" + filename + "' is required to be in 24 or 32 bit color depth.");
		}

		if (bmInfoHeader.biCompression != BI_RGB)
		{
			throw std::runtime_error("Bitmap file: '" + filename + "' cannot be compressed.");
		}

		int heightStart = height - 1;
		int heightEnd = -1;
		int fdir = -1;
		if (bmInfoHeader.biHeight < 0) {
			heightStart = 0;
			heightEnd = height - 1;
			fdir = 1;
		}

		file.seekg(bmFileHeader.bfOffBits);
		int padding = bmInfoHeader.biBitCount == 24 ? (4 - (width * 3) % 4) % 4 : 0;
		for (int y = heightStart; y != heightEnd; y += fdir) {
			for (int x = 0; x < width; x++) {
				PutPixel(x, y, Color(file.get(), file.get(), file.get()));
			}
			file.seekg(padding, std::ios::cur);
		}
	}
	catch(const std::exception& e)
	{
		throw e;
	}
}

Surface::Surface(const Surface& in_surf)
	:
	width(in_surf.width),
	height(in_surf.height)
{
	pPixels = std::make_unique<Color[]>(width * height);
	for (int i = 0; i < width * height; i++) {
		pPixels[i] = in_surf.pPixels[i];
	}
}

Surface::Surface(const int in_width, const int in_height)
	:
	width(in_width),
	height(in_height)
{
	pPixels = std::make_unique<Color[]>(width * height);
}

Surface::Surface(const int in_width, const int in_height, Color& col)
	:
	Surface(in_width, in_height)
{
	for (int i = 0; i < width * height; ++i)
	{
		pPixels[i] = col;
	}
}

Surface& Surface::operator=(const Surface& rhs)
{
	pPixels.reset();
	width = rhs.width;
	height = rhs.height;

	pPixels = std::make_unique<Color[]>(width * height);
	for (int i = 0; i < width * height; ++i)
	{
		pPixels[i] = rhs.pPixels[i];
	}
	return *this;
}

void Surface::PutPixel(const int x, const int y, const Color& c)
{
	pPixels[y * width + x] = c;
}

Color Surface::GetPixel(const int x, const int y) const
{
	return pPixels[y * width + x];
}

int Surface::GetWidth() const
{
	return width;
}

int Surface::GetHeight() const
{
	return height;
}

int Surface::GetSize() const
{
	return width * height;
}

RectI Surface::GetRect() const
{
	return RectI(0, width, 0, height);
}
