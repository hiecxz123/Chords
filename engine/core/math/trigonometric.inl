#include<limits>

#define RAD_TO_DEG 57.295779513082320876798154814105   // 弧度转角度的转换率
#define DEG_TO_RAD 0.01745329251994329576923690768489 // 角度转弧度的转换率

namespace Core
{
	namespace Math 
	{
		template<typename genType>
		inline constexpr genType radians(genType degrees)
		{
			static_assert(std::numeric_limits<genType>::is_iec559, "'radians' only accept floating-point input");
			return degrees * static_cast<genType>(DEG_TO_RAD);
		}
	}
}