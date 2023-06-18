#include <render/camera/camera.h>
#include <cmath>
#include <glm/geometric.hpp>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
namespace Core
{
	Camera::Camera(glm::vec3 _position, glm::vec3 _up, float _yaw, float _pitch) :
		m_front(glm::vec3(0.0f, 0.0f, -1.0f)), m_movementSpeed(CAMERA_SPEED), m_mouseSensitivity(CAMERA_SENSITIVITY), m_zoom(CAMERA_ZOOM)
	{
		m_position = _position;
		m_worldUp = _up;
		m_yaw = _yaw;
		m_pitch = _pitch;
		UpdateCameraVectors();
	}

	Camera::Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch) :
		m_front(glm::vec3(0.0f, 0.0f, -1.0f)), m_movementSpeed(CAMERA_SPEED), m_mouseSensitivity(CAMERA_SENSITIVITY), m_zoom(CAMERA_ZOOM)
	{
		m_position = glm::vec3(posX, posY, posZ);
		m_worldUp = glm::vec3(upX, upY, upZ);
		m_yaw = yaw;
		m_pitch = pitch;
		UpdateCameraVectors();
	}

	void Camera::UpdateCameraVectors()
	{
		glm::vec3 front;

		front.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
		front.y = sin(glm::radians(m_pitch));
		front.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
		m_front = glm::normalize(front);

		m_right = glm::normalize(glm::cross(m_front, m_worldUp));
		m_up = glm::normalize(glm::cross(m_right, m_front));
	}

	glm::mat4 Camera::GetViewMatrix()
	{
		return glm::lookAt(m_position, m_position + m_front, m_up);
	}

	void Camera::CameraMovement(float xoffset, float yoffset, GLboolean constrainPitch)
	{
		xoffset *= m_mouseSensitivity;
		yoffset *= m_mouseSensitivity;

		m_yaw += xoffset;
		m_pitch += yoffset;

		// make sure that when pitch is out of bounds, screen doesn't get flipped
		if (constrainPitch)
		{
			if (m_pitch > 89.0f)
				m_pitch = 89.0f;
			if (m_pitch < -89.0f)
				m_pitch = -89.0f;
		}
		UpdateCameraVectors();
	}

	void Camera::CameraScroll(float yoffset)
	{
		m_zoom -= (float)yoffset;
		if (m_zoom < 1.0f)
			m_zoom = 1.0f;
		if (m_zoom > 45.0f)
			m_zoom = 45.0f;
	}
	void Camera::ProcessKeyboard(CameraMovementEnum direction, float deltaTime)
	{
		float velocity = m_movementSpeed * deltaTime;
		if (direction == CameraMovementEnum::FORWARD)
			m_position += m_front * velocity;
		if (direction == CameraMovementEnum::BACKWARD)
			m_position -= m_front * velocity;
		if (direction == CameraMovementEnum::LEFT)
			m_position -= m_right * velocity;
		if (direction == CameraMovementEnum::RIGHT)
			m_position += m_right * velocity;
	}
}

