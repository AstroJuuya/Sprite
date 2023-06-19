#pragma once

#include "Surface.h"

class Animation
{
public:
	Animation(const Surface& spritesheet_file, const Vec2& sections, const Color& chroma_color = Colors::Magenta);
	Animation(const Surface& spritesheet_file, const int sprite_width, const int sprite_height, const Color& chroma_color = Colors::Magenta);
	Vec2 GetSpriteCenter() const;
	RectI GetSpriteRect(const Vec2& at) const;

public:
	const Vec2 spritesize;
	const Surface spritesheet;
	const Color chroma;
};