#include <render/camera/camera.h>
#include <cmath>
#include <math/trigonometric.h>

namespace Core
{

	Camera::Camera(Math::Vector3 _position, Math::Vector3 _up, float _yaw, float _pitch) :front(Math::Vector3(0, 0, -1)), movementSpeed(CAMERA_SPEED)
	{
		position = _position;
		worldUp = _up;
		yaw = _yaw;
		pitch = _pitch;
	}
	void Camera::UpdateCameraVectors()
	{
		Math::Vector3 front;

		front.x = cos(Math::radians(yaw)) * cos(Math::radians(pitch));
		front.y = sin(Math::radians(pitch));
		front.z = sin(Math::radians(yaw)) * cos(Math::radians(pitch));
		//Front = glm::normalize(front);
		//// also re-calculate the Right and Up vector
		//Right = glm::normalize(glm::cross(Front, WorldUp));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
		//Up = glm::normalize(glm::cross(Right, Front));
	}
}

