#include <math/matrix4.h>

Core::Math::Mat4x4::Mat4x4(const float floatArr[16])
{
	m4x4[0][0] = floatArr[0];
	m4x4[0][1] = floatArr[1];
	m4x4[0][2] = floatArr[2];
	m4x4[0][3] = floatArr[3];
	m4x4[1][0] = floatArr[4];
	m4x4[1][1] = floatArr[5];
	m4x4[1][2] = floatArr[6];
	m4x4[1][3] = floatArr[7];
	m4x4[2][0] = floatArr[8];
	m4x4[2][1] = floatArr[9];
	m4x4[2][2] = floatArr[10];
	m4x4[2][3] = floatArr[11];
	m4x4[3][0] = floatArr[12];
	m4x4[3][1] = floatArr[13];
	m4x4[3][2] = floatArr[14];
	m4x4[3][3] = floatArr[15];
}

Core::Math::Mat4x4::Mat4x4(float v11, float v12, float v13, float v14, float v21, float v22, float v23, float v24, float v31, float v32, float v33, float v34, float v41, float v42, float v43, float v44)
{
	m4x4[0][0] = v11;
	m4x4[0][1] = v11;
	m4x4[0][2] = v11;
	m4x4[0][3] = v11;
	m4x4[1][0] = v11;
	m4x4[1][1] = v11;
	m4x4[1][2] = v11;
	m4x4[1][3] = v11;
	m4x4[2][0] = v11;
	m4x4[2][1] = v11;
	m4x4[2][2] = v11;
	m4x4[2][3] = v11;
	m4x4[3][0] = v11;
	m4x4[3][1] = v11;
	m4x4[3][2] = v11;
	m4x4[3][3] = v11;
}

Core::Math::Mat4x4 Core::Math::Mat4x4::operator+(const Mat4x4 mat4x4) const
{
	Mat4x4 temp;
	temp.m4x4[0][0] = m4x4[0][0] + mat4x4.m4x4[0][0];
	temp.m4x4[0][1] = m4x4[0][1] + mat4x4.m4x4[0][1];
	temp.m4x4[0][2] = m4x4[0][2] + mat4x4.m4x4[0][2];
	temp.m4x4[0][3] = m4x4[0][3] + mat4x4.m4x4[0][3];
	temp.m4x4[1][0] = m4x4[1][0] + mat4x4.m4x4[1][0];
	temp.m4x4[1][1] = m4x4[1][1] + mat4x4.m4x4[1][1];
	temp.m4x4[1][2] = m4x4[1][2] + mat4x4.m4x4[1][2];
	temp.m4x4[1][3] = m4x4[1][3] + mat4x4.m4x4[1][3];
	temp.m4x4[2][0] = m4x4[2][0] + mat4x4.m4x4[2][0];
	temp.m4x4[2][1] = m4x4[2][1] + mat4x4.m4x4[2][1];
	temp.m4x4[2][2] = m4x4[2][2] + mat4x4.m4x4[2][2];
	temp.m4x4[2][3] = m4x4[2][3] + mat4x4.m4x4[2][3];
	temp.m4x4[3][0] = m4x4[3][0] + mat4x4.m4x4[3][0];
	temp.m4x4[3][1] = m4x4[3][1] + mat4x4.m4x4[3][1];
	temp.m4x4[3][2] = m4x4[3][2] + mat4x4.m4x4[3][2];
	temp.m4x4[3][3] = m4x4[3][3] + mat4x4.m4x4[3][3];
	return temp;
}

Core::Math::Mat4x4 Core::Math::Mat4x4::operator-(const Mat4x4 mat4x4) const
{
	Core::Math::Mat4x4 temp;
	temp.m4x4[0][0] = m4x4[0][0] - mat4x4.m4x4[0][0];
	temp.m4x4[0][1] = m4x4[0][1] - mat4x4.m4x4[0][1];
	temp.m4x4[0][2] = m4x4[0][2] - mat4x4.m4x4[0][2];
	temp.m4x4[0][3] = m4x4[0][3] - mat4x4.m4x4[0][3];
	temp.m4x4[1][0] = m4x4[1][0] - mat4x4.m4x4[1][0];
	temp.m4x4[1][1] = m4x4[1][1] - mat4x4.m4x4[1][1];
	temp.m4x4[1][2] = m4x4[1][2] - mat4x4.m4x4[1][2];
	temp.m4x4[1][3] = m4x4[1][3] - mat4x4.m4x4[1][3];
	temp.m4x4[2][0] = m4x4[2][0] - mat4x4.m4x4[2][0];
	temp.m4x4[2][1] = m4x4[2][1] - mat4x4.m4x4[2][1];
	temp.m4x4[2][2] = m4x4[2][2] - mat4x4.m4x4[2][2];
	temp.m4x4[2][3] = m4x4[2][3] - mat4x4.m4x4[2][3];
	temp.m4x4[3][0] = m4x4[3][0] - mat4x4.m4x4[3][0];
	temp.m4x4[3][1] = m4x4[3][1] - mat4x4.m4x4[3][1];
	temp.m4x4[3][2] = m4x4[3][2] - mat4x4.m4x4[3][2];
	temp.m4x4[3][3] = m4x4[3][3] - mat4x4.m4x4[3][3];
	return temp;
}

Core::Math::Mat4x4 Core::Math::Mat4x4::operator*(const Mat4x4 mat4x4) const
{
	Mat4x4 temp;
	temp.m4x4[0][0] = m4x4[0][0] * mat4x4.m4x4[0][0] + m4x4[0][1] * mat4x4.m4x4[1][0] + m4x4[0][2] * mat4x4.m4x4[2][0] + m4x4[0][3] * mat4x4.m4x4[3][0];
	temp.m4x4[0][1] = m4x4[0][0] * mat4x4.m4x4[0][1] + m4x4[0][1] * mat4x4.m4x4[1][1] + m4x4[0][2] * mat4x4.m4x4[2][1] + m4x4[0][3] * mat4x4.m4x4[3][1];
	temp.m4x4[0][2] = m4x4[0][0] * mat4x4.m4x4[0][2] + m4x4[0][1] * mat4x4.m4x4[1][2] + m4x4[0][2] * mat4x4.m4x4[2][2] + m4x4[0][3] * mat4x4.m4x4[3][2];
	temp.m4x4[0][3] = m4x4[0][0] * mat4x4.m4x4[0][3] + m4x4[0][1] * mat4x4.m4x4[1][3] + m4x4[0][2] * mat4x4.m4x4[2][3] + m4x4[0][3] * mat4x4.m4x4[3][3];

	temp.m4x4[1][0] = m4x4[1][0] * mat4x4.m4x4[0][0] + m4x4[1][1] * mat4x4.m4x4[1][0] + m4x4[1][2] * mat4x4.m4x4[2][0] + m4x4[1][3] * mat4x4.m4x4[3][0];
	temp.m4x4[1][1] = m4x4[1][0] * mat4x4.m4x4[0][1] + m4x4[1][1] * mat4x4.m4x4[1][1] + m4x4[1][2] * mat4x4.m4x4[2][1] + m4x4[1][3] * mat4x4.m4x4[3][1];
	temp.m4x4[1][2] = m4x4[1][0] * mat4x4.m4x4[0][2] + m4x4[1][1] * mat4x4.m4x4[1][2] + m4x4[1][2] * mat4x4.m4x4[2][2] + m4x4[1][3] * mat4x4.m4x4[3][2];
	temp.m4x4[1][3] = m4x4[1][0] * mat4x4.m4x4[0][3] + m4x4[1][1] * mat4x4.m4x4[1][3] + m4x4[1][2] * mat4x4.m4x4[2][3] + m4x4[1][3] * mat4x4.m4x4[3][3];

	temp.m4x4[2][0] = m4x4[2][0] * mat4x4.m4x4[0][0] + m4x4[2][1] * mat4x4.m4x4[1][0] + m4x4[2][2] * mat4x4.m4x4[2][0] + m4x4[2][3] * mat4x4.m4x4[3][0];
	temp.m4x4[2][1] = m4x4[2][0] * mat4x4.m4x4[0][1] + m4x4[2][1] * mat4x4.m4x4[1][1] + m4x4[2][2] * mat4x4.m4x4[2][1] + m4x4[2][3] * mat4x4.m4x4[3][1];
	temp.m4x4[2][2] = m4x4[2][0] * mat4x4.m4x4[0][2] + m4x4[2][1] * mat4x4.m4x4[1][2] + m4x4[2][2] * mat4x4.m4x4[2][2] + m4x4[2][3] * mat4x4.m4x4[3][2];
	temp.m4x4[2][3] = m4x4[2][0] * mat4x4.m4x4[0][3] + m4x4[2][1] * mat4x4.m4x4[1][3] + m4x4[2][2] * mat4x4.m4x4[2][3] + m4x4[2][3] * mat4x4.m4x4[3][3];

	temp.m4x4[3][0] = m4x4[3][0] * mat4x4.m4x4[0][0] + m4x4[3][1] * mat4x4.m4x4[1][0] + m4x4[3][2] * mat4x4.m4x4[2][0] + m4x4[3][3] * mat4x4.m4x4[3][0];
	temp.m4x4[3][1] = m4x4[3][0] * mat4x4.m4x4[0][1] + m4x4[3][1] * mat4x4.m4x4[1][1] + m4x4[3][2] * mat4x4.m4x4[2][1] + m4x4[3][3] * mat4x4.m4x4[3][1];
	temp.m4x4[3][2] = m4x4[3][0] * mat4x4.m4x4[0][2] + m4x4[3][1] * mat4x4.m4x4[1][2] + m4x4[3][2] * mat4x4.m4x4[2][2] + m4x4[3][3] * mat4x4.m4x4[3][2];
	temp.m4x4[3][3] = m4x4[3][0] * mat4x4.m4x4[0][3] + m4x4[3][1] * mat4x4.m4x4[1][3] + m4x4[3][2] * mat4x4.m4x4[2][3] + m4x4[3][3] * mat4x4.m4x4[3][3];
	return temp;
}

void Core::Math::Mat4x4::PrintMat4x4()
{
	spdlog::info("Mat4x4");
	//std::cout << "Mat4x4" << std::endl;
}



