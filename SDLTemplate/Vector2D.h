#include <math.h>


#ifndef __Vector2D__
#define __Vector2D__

class Vector2D
{
public:
	
	Vector2D()
	{

	}
	
	Vector2D(float x, float y) : m_x(x), m_y(y) {}

	float getX() { return m_x; }
	float getY() { return m_y; }

	void setX(float x) { m_x = x; }
	void setY(float y) { m_y = y; }


	float length() { return sqrt(m_x * m_x + m_y * m_y); }

	//adding of two vectors
	Vector2D operator+ (const Vector2D& v2) const
	{
		return Vector2D(m_x + v2.m_x, m_y + v2.m_y);
	}

	friend Vector2D& operator+=(Vector2D& v1, const Vector2D& v2)
	{
		v1.m_x += v2.m_x;
		v1.m_y += v2.m_y;

		return v1;
	}

	//multiply by a scalar number
	Vector2D operator* (float scalar)
	{
		return Vector2D(m_x * scalar, m_y * scalar);
	}

	Vector2D& operator*= (float scalar)
	{
		m_x *= scalar;
		m_y *= scalar;

		return *this;
	}

	//subtraction of two vectors
	Vector2D operator- (const Vector2D& v2) const
	{
		return Vector2D(m_x - v2.m_x, m_y - v2.m_y);
	}

	friend Vector2D& operator-= (Vector2D& v1, const Vector2D& v2)
	{
		v1.m_x -= v2.m_x;
		v1.m_y -= v2.m_y;

		return v1;
	}

	//divide by a scalar number
	Vector2D operator/ (float scalar)
	{
		return Vector2D(m_x / scalar, m_y / scalar);
	}

	Vector2D& operator/= (float scalar)
	{
		m_x /= scalar;
		m_y /= scalar;

		return *this;
	}

	//normalizing a vector  //normalizing a vector makes its lenght equal to 1  //multiply by the inverse of its length
	void normalize()
	{
		float l = length();
		if (l > 0)  // we never want to attempt to divide by 0
		{
			(*this) *= 1 / l;
		}

	}


private:

	float m_x;
	float m_y;

};


#endif