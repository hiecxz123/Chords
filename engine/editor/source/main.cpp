#include<iostream>
#include<math/math.h>
#include<math/matrix4.h>
#include <stdlib.h>
#include<log/Log.h>
using namespace std;
int main()
{
	Core::Math::Mat4x4 mat4x41(
		1, 1, 1, 1,
		2, 3, 3, 3,
		1, 1, 1, 1,
		2, 2, 2, 2
	);
	Core::Math::Mat4x4 mat4x42(
		1, 1, 1, 1,
		2, 2, 2, 2,
		3, 3, 3, 3,
		4, 4, 4, 4
	);
	Core::Math::Mat4x4 temp;
	temp = mat4x41 * mat4x42;


	temp.PrintMat4x4();

	system("pause");

}