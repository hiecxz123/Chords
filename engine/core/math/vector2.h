#pragma once
namespace EngineMath
{
	class Vector2
	{
	public:
		float x{ 0.0f };
		float y{ 0.0f };
	public:
		Vector2() = default;
		Vector2(float _x, float _y) :x(_x), y(_y) {}
		bool operator==(const Vector2& o) const { return (x == o.x && y == o.y); }

		Vector2 operator+(const Vector2& o) const { return Vector2(x + o.x, y + o.y); }
	};
}