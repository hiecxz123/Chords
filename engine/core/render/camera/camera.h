#include<math/vector3.h>
namespace Core
{
	enum CameraMovement
	{
		FORWORD,
		BACKWARD,
		LEFT,
		RIGHT
	};
	const float CAMERA_YAW = -90.0f;
	const float CAMERA_PITCH = 0.0f;
	const float CAMERA_SPEED = 2.5f;
	const float CAMERA_SENSITIVITY = 0.1f;
	const float CAMERA_ZOOM = 45.0f;
	class Camera
	{
	
	public:
		Math::Vector3 position;
		Math::Vector3 front;
		Math::Vector3 up;
		Math::Vector3 right;
		Math::Vector3 worldUp;
	public:
		float yaw;
		float pitch;
		float movementSpeed;
		float mouseSensitivity;
		float zoom;

		Camera(Math::Vector3 _position = Math::Vector3(0, 0, 0), Math::Vector3 _up = Math::Vector3(0, 1, 0), float _yaw = CAMERA_YAW, float _pitch = CAMERA_PITCH);
	private:
		void UpdateCameraVectors();
	};
}
