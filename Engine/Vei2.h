#pragma once

class Vei2
{
public:
	Vei2() = default;
	Vei2(float x_in, float y_in);
	Vei2 operator+(const Vei2& rhs) const;
	Vei2& operator+=(const Vei2& rhs);
	Vei2 operator-(const Vei2& rhs) const;
	Vei2& operator-=(const Vei2& rhs);
	Vei2 operator*(const float rhs) const;
	Vei2& operator*=(const float rhs);
	Vei2 operator/(const float rhs) const;
	Vei2& operator/=(const float rhs);
	float GetLength() const;
	float GetLengthSq() const;
	Vei2& Normalize();
	Vei2 GetNormalized() const;
public:
	float x;
	float y;
};