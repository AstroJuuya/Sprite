#include "Animation.h"
#include <cassert>

Animation::Animation(const Surface& spritesheet_file, const Vec2& sections, const Color& chroma_color)
	:
	spritesheet(spritesheet_file),
	spritesize(
		spritesheet_file.GetWidth() / sections.x,
		spritesheet_file.GetHeight() / sections.y),
	chroma(chroma_color)
{
	assert(spritesheet_file.GetWidth() % spritesize.x == 0);
	assert(spritesheet_file.GetHeight() % spritesize.y == 0);
}

Animation::Animation(const Surface& spritesheet_file, const int sprite_width, const int sprite_height, const Color& chroma_color)
	:
	spritesheet(spritesheet_file),
	chroma(chroma_color),
	spritesize(
		sprite_width,
		sprite_height)
{
	assert(spritesheet_file.GetWidth() % sprite_width == 0);
	assert(spritesheet_file.GetHeight() % sprite_height == 0);
}

Vec2 Animation::GetSpriteCenter() const
{
	return Vec2(spritesize.x / 2, spritesize.y / 2);
}

RectI Animation::GetSpriteRect(const Vec2& at) const
{
	assert(at.x * spritesize.x <= spritesheet.GetWidth());
	assert(at.y * spritesize.y <= spritesheet.GetHeight());
	return RectI(
		spritesize.x * at.x,
		spritesize.x * at.x + spritesize.x,
		spritesize.y * at.y + 1,
		spritesize.y * at.y + spritesize.y);
}
