namespace Core
{
	namespace Math
	{
		class Vector3
		{
		public:
			Vector3() = default;
			Vector3(float _x, float _y, float _z) { x = _x; y = _y; z = _z; };
			~Vector3() = default;

		public:
			float x;
			float y;
			float z;

			Vector3 operator+(const Vector3 v3) const;
			Vector3 operator-(const Vector3 v3) const;
			bool operator==(const Vector3 v3) const;
		};
	}
}