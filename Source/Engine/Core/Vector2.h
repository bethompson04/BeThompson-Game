#pragma once

namespace MEN 
{

	class Vector2
	{
	public:
		float x, y;

	public:
		Vector2() : x{ 0 }, y{ 0 } {} //Initializes x and y to 0
		Vector2(float value) : x{ value }, y{ value } {}
		Vector2(float valueX, float valueY) : x{ valueX }, y{ valueY } {}
		Vector2(int valueX, int valueY) : x{ (float)valueX }, y{ (float)valueY } {}

		//Vector2 Add(const Vector2& vector) const { return Vector2(x + vector.x, y + vector.y); }
		Vector2 operator + (const Vector2& vector) const { return Vector2(x + vector.x, y + vector.y); }
		Vector2 operator - (const Vector2& vector) const { return Vector2(x - vector.x, y - vector.y); }
		Vector2 operator / (const Vector2& vector) const { return Vector2(x / vector.x, y / vector.y); }
		Vector2 operator * (const Vector2& vector) const { return Vector2(x * vector.x, y * vector.y); }

		Vector2 operator + (float s) const { return Vector2(x + s, y + s); }
		Vector2 operator - (float s) const { return Vector2(x - s, y - s); }
		Vector2 operator / (float s) const { return Vector2(x / s, y / s); }
		Vector2 operator * (float s) const { return Vector2(x * s, y * s); }

		Vector2& operator += (const Vector2& vector) { x += vector.x; y += vector.y; return *this; }
		Vector2& operator -= (const Vector2& vector) { x -= vector.x; y -= vector.y; return *this; }
		Vector2& operator /= (const Vector2& vector) { x /= vector.x; y /= vector.y; return *this; }
		Vector2& operator *= (const Vector2& vector) { x *= vector.x; y *= vector.y; return *this; }
	private:
			
	};

}