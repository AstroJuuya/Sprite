#pragma once

#include "Colors.h"
#include "ChiliWin.h"
#include "Rect.h"
#include <string>

class Surface {
public:
	Surface() = delete;
	Surface(std::string filename);
	Surface(const Surface& in_surf);
	Surface(const int in_width, const int in_height);
	Surface(const int in_width, const int in_height, Color& col);
	Surface& operator=(const Surface& rhs);
	~Surface();

	void PutPixel(const int x, const int y, const Color& c);
	Color GetPixel(const int x, const int y) const;
	int GetWidth() const;
	int GetHeight() const;
	int GetSize() const;
	RectI GetRect() const;

private:
	int width = 0;
	int height = 0;
	Color* pPixels = nullptr;
};