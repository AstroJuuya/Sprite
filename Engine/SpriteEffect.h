#pragma once

#include "Colors.h"
#include "Graphics.h"
#include <cassert>

namespace SpriteEffect
{
	class Chroma
	{
	public:
		Chroma(Color chroma_color)
			:
			chroma(chroma_color)
		{
		}
		void operator()(Color source, int x, int y, Graphics& gfx) const
		{
			if (source != chroma)
			{
				gfx.PutPixel(x, y, source);
			}
		}

	private:
		Color chroma = Colors::Magenta;
	};

	class Copy
	{
	public:
		void operator()(Color source, int x, int y, Graphics& gfx) const
		{
			gfx.PutPixel(x, y, source);
		}
	};

	class Substitute
	{
	public:
		Substitute(Color substitute_color, Color chroma_color)
			:
			chroma(chroma_color),
			substitute(substitute_color)
		{
		}
		void operator()(Color source, int x, int y, Graphics& gfx) const
		{
			if (source != chroma)
			{
				gfx.PutPixel(x, y, substitute);
			}
		}

	private:
		Color chroma = Colors::Magenta;
		Color substitute = Colors::Magenta;
	};

	class Transparent
	{
	public:
		Transparent(int alpha_value, Color chroma_color)
			:
			alpha(alpha_value),
			chroma(chroma_color)
		{
			assert(alpha <= 100);
		}
		void operator()(Color source, int x, int y, Graphics& gfx) const
		{
			Color pixel_to_draw = source;
			if (pixel_to_draw != chroma) {
				pixel_to_draw *= (float)alpha / 100.0f;

				Color drawn_pixel = gfx.GetPixel(x, y);
				drawn_pixel *= 1.0f - (float)alpha / 100.0f;
				pixel_to_draw += drawn_pixel;
				gfx.PutPixel(x, y, pixel_to_draw);
			}
		}

	private:
		int alpha;
		Color chroma;
	};
}
