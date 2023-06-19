#pragma once

#include <string>
#include "Animation.h"
#include "Graphics.h"

class Text
{
public:
	Text(const std::string& file_name, const int sprite_width, const int sprite_height, const Color& chroma = Colors::White);
	void Draw(Graphics& gfx, const std::string text, const int pos_x, const int pos_y, const Color& text_color = Colors::White) const;
	void Draw(Graphics& gfx, const std::string text, const Vec2& position, const Color& text_color = Colors::White) const;

private:
	RectI GetLetter(const char letter) const;

private:
	Animation fontsheet;
};