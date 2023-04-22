#pragma once
#include <iostream>
//#include <spdlog/spdlog.h>
namespace Core
{
	namespace Math
	{
		class Mat4x4
		{
		public:
			float m4x4[4][4];
		public:
			Mat4x4() {}
			Mat4x4(const float floatarr[16]);
			Mat4x4(
				float v11, float v12, float v13, float v14,
				float v21, float v22, float v23, float v24,
				float v31, float v32, float v33, float v34,
				float v41, float v42, float v43, float v44
			);

			Mat4x4 operator+(const Mat4x4 mat4x4) const;
			Mat4x4 operator-(const Mat4x4 mat4x4) const;
			Mat4x4 operator*(const Mat4x4 mat4x4) const;

			void PrintMat4x4();
		};
	}
}
