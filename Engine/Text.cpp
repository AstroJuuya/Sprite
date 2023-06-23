#include "Text.h"

Text::Text(const std::string& file_name, const int sprite_width, const int sprite_height, const Color& chroma)
	:
	fontsheet(file_name, sprite_width, sprite_height, chroma)
{
}

void Text::Draw(Graphics& gfx, const std::string text, const int pos_x, const int pos_y, const Color& text_color) const
{
	Vec2 text_coord{ 0, 0 };
	for (int i = 0; i < text.length(); i++, text_coord.x++) {
		if (text[i] == '\n') {
			text_coord.y += 1;
			text_coord.x = -1;
			continue;
		}
		gfx.DrawSprite(
			pos_x + fontsheet.spritesize.x * text_coord.x,
			pos_y + fontsheet.spritesize.y * text_coord.y,
			GetLetter(text[i]),
			fontsheet.spritesheet,
			SpriteEffect::Substitute { text_color, fontsheet.chroma });
	}
}

void Text::Draw(Graphics& gfx, const std::string text, const Vec2& position, const Color& text_color) const
{
	Draw(gfx, text, position.x, position.y, text_color);
}

RectI Text::GetLetter(const char letter) const
{
	const int index = letter - 32;
	const int y = int(index / (fontsheet.spritesheet.GetWidth() / fontsheet.spritesize.x));
	const int x = index % (fontsheet.spritesheet.GetWidth() / fontsheet.spritesize.x);
	return fontsheet.GetSpriteRect({ x,y });
}
