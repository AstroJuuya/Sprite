#pragma once

#include "Vei2.h"

class Vec2
{
public:
	Vec2() = default;
	Vec2(int x_in, int y_in );
	Vec2& operator=(const Vec2& rhs);
	Vec2 operator+( const Vec2& rhs ) const;
	Vec2& operator+=( const Vec2& rhs );
	Vec2 operator*( int rhs ) const;
	Vec2 operator*=( int rhs );
	Vei2 operator*( float rhs ) const;
	Vei2 operator/( int rhs ) const;
	Vei2 operator/( float rhs ) const;
	Vec2 operator-( const Vec2& rhs ) const;
	Vec2& operator-=( const Vec2& rhs );
	operator Vei2() const;
	float GetLength() const;
	float GetLengthSq() const;
	Vei2 GetNormalized() const;
public:
	int x;
	int y;
};