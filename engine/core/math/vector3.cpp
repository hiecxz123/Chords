#include "vector3.h"
namespace Core
{
	namespace Math
	{
		Vector3 Vector3::operator+(const Vector3 v3) const
		{
			return Vector3(x+v3.x,y+v3.y,z+v3.z);
		}
		Vector3 Vector3::operator-(const Vector3 v3) const
		{
			return Vector3(x - v3.x, y - v3.y, z - v3.z);
		}
		bool Vector3::operator==(const Vector3 v3) const
		{
			return x == v3.x && y == v3.y && z == v3.z;
		}
	}
}

