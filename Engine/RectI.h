#pragma once

#include "Vei2.h"
#include "Vec2.h"

class RectI
{
public:
	RectI() = default;
	RectI( int left_in,int right_in,int top_in,int bottom_in );
	RectI( const Vei2& topLeft,const Vei2& bottomRight );
	RectI( const Vei2& topLeft,float width,float height );
	RectI( const Vec2& topLeft, const Vec2& bottomRight );
	RectI( const Vec2& topLeft, int width, int height );
	bool IsOverlappingWith( const RectI& other ) const;
	bool IsContainedBy( const RectI& other ) const;
	bool Contains( const Vei2& point ) const;
	RectI FromCenter( const Vei2& center,float halfWidth,float halfHeight );
	RectI FromCenter( const Vec2& center, int halfWidth, int halfHeight );
	RectI GetExpanded( int offset ) const;
	Vec2 GetCenter() const;
	int GetWidth() const;
	int GetHeight() const;
public:
	int left;
	int right;
	int top;
	int bottom;
};