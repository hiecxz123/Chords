#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>
namespace Core
{
	enum class CameraMovementEnum
	{
		FORWARD,
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
		glm::vec3 m_position;
		glm::vec3 m_front;
		glm::vec3 m_up;
		glm::vec3 m_right;
		glm::vec3 m_worldUp;
	public:
		float m_yaw;
		float m_pitch;
		float m_movementSpeed;
		float m_mouseSensitivity;
		float m_zoom;

		Camera(glm::vec3 _position = glm::vec3(0, 0, 0), glm::vec3 _up = glm::vec3(0, 1, 0), float _yaw = CAMERA_YAW, float _pitch = CAMERA_PITCH);
		Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch);

	public:
		void UpdateCameraVectors();
		glm::mat4 GetViewMatrix();
		void CameraMovement(float xoffset, float yoffset, GLboolean constrainPitch = true);
		void CameraScroll(float yoffset);
		void ProcessKeyboard(CameraMovementEnum direction, float deltaTime);
	};
}
