#include "Vec2.h"
#include <cmath>

Vec2::Vec2( int x_in,int y_in )
	:
	x( x_in ),
	y( y_in )
{
}

Vec2& Vec2::operator=(const Vec2& rhs)
{
	return Vec2(rhs.x, rhs.y);
}

Vec2 Vec2::operator+( const Vec2& rhs ) const
{
	return Vec2( x + rhs.x,y + rhs.y );
}

Vec2& Vec2::operator+=( const Vec2& rhs )
{
	return *this = *this + rhs;
}

Vec2 Vec2::operator*(int rhs) const
{
	return Vec2(x * rhs, y * rhs);
}

Vec2 Vec2::operator*=(int rhs)
{
	return *this = *this * rhs;
}

Vei2 Vec2::operator*(float rhs) const
{
	return Vei2( float(x) * rhs, float(y) * rhs );
}

Vei2 Vec2::operator/(int rhs) const
{
	return Vei2(float(x) / float(rhs),float(y) / float(rhs));
}

Vei2 Vec2::operator/(float rhs) const
{
	return Vei2(float(x) / rhs, float(y) / rhs);
}

Vec2 Vec2::operator-( const Vec2& rhs ) const
{
	return Vec2( x - rhs.x,y - rhs.y );
}

Vec2& Vec2::operator-=( const Vec2& rhs )
{
	return *this = *this - rhs;
}

Vec2::operator Vei2() const
{
	return { float(x), float(y) };
}

float Vec2::GetLength() const
{
	return std::sqrt( GetLengthSq() );
}

float Vec2::GetLengthSq() const
{
	return float(x * x + y * y);
}

Vei2 Vec2::GetNormalized() const
{
	const float len = GetLength();
	if( len != 0.0f )
	{
		return Vei2(x * (1.0f / len), y * (1.0f / len));
	}
	return *this;
}
