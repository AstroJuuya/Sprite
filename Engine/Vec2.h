#pragma once

#include <cmath>

template <typename T> class Vec2_
{
public:
	Vec2_() = default;
	Vec2_(T x_in, T y_in)
		:
		x(x_in),
		y(y_in)
	{
	}

	template <typename S> Vec2_(const Vec2_<S>& src)
		:
		x((T)src.x),
		y((T)src.y)
	{
	}

	Vec2_& operator=(const Vec2_<T>& rhs)
	{
		x = rhs.x;
		y = rhs.y;
		return *this;
	}

	Vec2_ operator+(const Vec2_<T>& rhs) const
	{
		return Vec2_<T>(x + rhs.x, y + rhs.y);
	}

	Vec2_& operator+=(const Vec2_<T>& rhs)
	{
		return *this = *this + rhs;
	}

	Vec2_ operator*(T rhs) const
	{
		return Vec2_<T>(x * rhs, y * rhs);
	}

	Vec2_& operator*=(T rhs)
	{
		return *this = *this * rhs;
	}

	Vec2_ operator/(T rhs) const
	{
		return Vec2_<T>(T(x) / T(rhs), T(y) / T(rhs));
	}

	Vec2_ operator/=(T rhs) const
	{
		return *this = T(x) / rhs, T(y) / rhs;
	}

	Vec2_ operator-(const Vec2_<T>& rhs) const
	{
		return Vec2_<T>(x - rhs.x, y - rhs.y);
	}

	Vec2_& operator-=(const Vec2_<T>& rhs)
	{
		return *this = *this - rhs;
	}

	T GetLength() const
	{
		return (T)std::sqrt(GetLengthSq());
	}

	T GetLengthSq() const
	{
		return T(x * x + y * y);
	}

	Vec2_& Vec2_::Normalize()
	{
		return *this = GetNormalized();
	}

	Vec2_ GetNormalized() const
	{
		const T len = (T)GetLength();
		if (len != (T)0)
		{
			return Vec2_<T>(x * ((T)1 / len), y * ((T)1 / len));
		}
		return *this;
	}

public:
	T x;
	T y;
};

using Vec2 = Vec2_<int>;
using Vei2 = Vec2_<float>;