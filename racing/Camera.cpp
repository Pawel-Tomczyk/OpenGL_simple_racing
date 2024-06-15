#include "Camera.h"

float PI = 3.14159265359f;

Camera::Camera() {}

Camera::Camera(glm::vec3 startPosition, glm::vec3 startUp, GLfloat startYaw, GLfloat startPitch, GLfloat startMoveSpeed, GLfloat startTurnSpeed)
{
	position = startPosition;
	worldUp = startUp;
	yaw = startYaw;
	pitch = startPitch;
	front = glm::vec3(0.0f, 0.0f, PI / 2);

	moveSpeed = startMoveSpeed;
	turnSpeed = startTurnSpeed;


	calculateViewMatrix();
	update();
}

void Camera::keyControl(bool* keys, GLfloat deltaTime)
{
	GLfloat velocity = moveSpeed * deltaTime;

	if (keys[GLFW_KEY_W])
	{

		position += front * velocity;
	}

	if (keys[GLFW_KEY_S])
	{
		position -= front * velocity;
	}

	if (keys[GLFW_KEY_A])
	{
		position -= right * velocity;
	}

	if (keys[GLFW_KEY_D])
	{
		position += right * velocity;
	}

	if (keys[GLFW_KEY_RIGHT])
	{
		yaw += turnSpeed;
	}

	if (keys[GLFW_KEY_LEFT])
	{
		yaw -= turnSpeed;
	}

	if (keys[GLFW_KEY_UP])
	{
		pitch += turnSpeed;
	}

	if (keys[GLFW_KEY_DOWN])
	{
		pitch -= turnSpeed;
	}


	// !!! ograniczenie ruchu kamery !!!
	//position.y = 1.0f;

	// r1 = 100 r2 = 200

	// (x^2 + z^2)^-2 >100 < 200
	float ogr = sqrt(position.x * position.x + position.z + position.z);
	if (ogr > 100 && ogr < 200);

	if (pitch > 89.0f)
	{
		pitch = 89.0f;
	}

	if (pitch < -89.0f)
	{
		pitch = -89.0f;
	}

	update();
}

void Camera::mouseControl(GLfloat xChange, GLfloat yChange)
{
	xChange *= turnSpeed;
	yChange *= turnSpeed;

	yaw += xChange;
	pitch += yChange;

	if (pitch > 89.0f)
	{
		pitch = 89.0f;
	}

	if (pitch < -89.0f)
	{
		pitch = -89.0f;
	}

	update();
}

glm::mat4 Camera::calculateViewMatrix()
{
	return glm::lookAt(position, position + front, up);
}

glm::mat4 Camera::calculateViewMatrixFromObject(glm::mat4 M)
{
	// Extract the position of the object from the model matrix
	glm::vec3 position = glm::vec3(M[3][0], M[3][1] + 2, M[3][2]);

	// Extract the forward (z-axis) direction from the model matrix
	glm::vec3 forward = glm::normalize(glm::vec3(M[2]));

	// Extract the up (y-axis) direction from the model matrix
	glm::vec3 upDirection = glm::normalize(glm::vec3(M[1]));

	// Calculate the right (x-axis) direction
	glm::vec3 right = glm::normalize(glm::cross(upDirection, forward));

	// Recompute the front and up vectors based on the object's orientation
	glm::vec3 cameraFront = -forward; // Camera looks in the opposite direction of the object's forward
	glm::vec3 cameraUp = upDirection;

	// Calculate the camera position 5 units behind the object
	glm::vec3 cameraPosition = position - forward * 4.0f;

	// Use glm::lookAt to create the view matrix
	//return glm::lookAt(cameraPosition, position, cameraUp);
	return glm::lookAt(cameraPosition, position, cameraUp);
}

glm::vec3 Camera::getCameraPosition()
{
	return this->position;
}

void Camera::update()
{
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	front = glm::normalize(front);

	right = glm::normalize(glm::cross(front, worldUp));
	up = glm::normalize(glm::cross(right, front));
}


Camera::~Camera()
{
}
