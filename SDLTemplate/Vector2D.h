#include <math.h>

#ifndef __Vector2D__
#define __Vector2D__
class Vector2D
{
public:
	Vector2D(){}
	Vector2D(float x, float y)
	{
		m_x = x;
		m_y = y;
	}
	float getX() { return m_x; }
	float getY() { return m_y; }

	void setX(float x) { cout << "?";  m_x = x; }
	void setY(float y) { m_y = y; }

	float length() { return sqrt(m_x * m_x * m_y * m_y); }

	Vector2D operator+(const Vector2D& v2) const
	{
		return Vector2D(m_x + v2.m_x, m_y + v2.m_y);
	}
	friend Vector2D& operator+=(Vector2D& v1, const Vector2D& v2)
	{
		v1.m_x += v2.m_x;
		v1.m_y += v2.m_y;
		return v1;
	}

	Vector2D operator-(const Vector2D& v2) const
	{
		return Vector2D(m_x - v2.m_x, m_y - v2.m_y);
	}
	friend Vector2D& operator-=(Vector2D& v1, const Vector2D& v2)
	{
		v1.m_x -= v2.m_x;
		v1.m_y -= v2.m_y;
		return v1;
	}

	Vector2D operator*(float scalar)
	{
		return Vector2D(m_x * scalar, m_y * scalar);
	}
	Vector2D& operator*=(float scalar)
	{
		m_x *= scalar;
		m_y *= scalar;
		return *this;
	}

	Vector2D operator/(float scalar)
	{
		return Vector2D(m_x / scalar, m_y / scalar);
	}
	Vector2D& operator/=(float scalar)
	{
		m_x /= scalar;
		m_y /= scalar;
		return *this;
	}

	void normalize()
	{
		float L = length();
		if (L > 0) // we never want to attempt to divide by 0
		{
			(*this) *= 1 / L;
		}
	}

private:
	float m_y;
	float m_x;
};
#endif