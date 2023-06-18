#include "Vei2.h"
#include <cmath>

Vei2::Vei2(float x_in, float y_in)
	:
	x( x_in ),
	y( y_in )
{
}

Vei2 Vei2::operator+(const Vei2& rhs) const
{
	return Vei2( x + rhs.x, y + rhs.y );
}

Vei2& Vei2::operator+=(const Vei2& rhs)
{
	return *this = *this + rhs;
}

Vei2 Vei2::operator-(const Vei2& rhs) const
{
	return Vei2( x - rhs.x, y - rhs.y );
}

Vei2& Vei2::operator-=(const Vei2& rhs)
{
	return *this = *this - rhs;
}

Vei2 Vei2::operator*(const float rhs) const
{
	return Vei2( x * rhs, y * rhs );
}

Vei2& Vei2::operator*=(const float rhs)
{
	return *this = *this * rhs;
}

Vei2 Vei2::operator/(const float rhs) const
{
	return Vei2( x / rhs, y / rhs );
}

Vei2& Vei2::operator/=(const float rhs)
{
	return *this = *this / rhs;
}

float Vei2::GetLength() const
{
	return std::sqrt( GetLengthSq() );
}

float Vei2::GetLengthSq() const
{
	return x * x + y * y;
}

Vei2& Vei2::Normalize()
{
	return *this = GetNormalized();
}

Vei2 Vei2::GetNormalized() const
{
	const float len = GetLength();
	if (len != 0.0f)
	{
		return *this * (1.0f / len);
	}
	return *this;
}
