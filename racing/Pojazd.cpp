#include "Pojazd.h"

Pojazd::Pojazd() : Object()
{
}

Pojazd::Pojazd(glm::mat4 M, float* vertices, int countVertices, float* normals, float* texCoords, glm::vec2 sizeOf2Dmodel) : Object(M, vertices, countVertices, normals, texCoords, sizeOf2Dmodel)
{
	direction = glm::vec2(0.0f, 1.0f);
	y = 1;
	x = 0;
}

Pojazd::~Pojazd()
{
	vertices = nullptr;
	normals = nullptr;
	texCoords = nullptr;
}

void Pojazd::keyControl(bool* keys, GLfloat deltaTime)
{
	GLfloat velocity = 1 * deltaTime;

	if (keys[GLFW_KEY_W])
	{

		speed += velocity;
	}

	if (keys[GLFW_KEY_S])
	{
		speed -= velocity;
	}

	if (keys[GLFW_KEY_A])
	{
		if (turn < 0.2) turn += velocity * 0.95;
		if (turn > 0.6) turn = 0.6;
		else turn += velocity * 0.3;
	}
	else if (keys[GLFW_KEY_D])
	{
		if (turn > -0.2) turn -= velocity;
		if (turn < -0.6) turn = -0.6;
		else turn -= velocity * 0.3;
	}
	else {
		turn *= 0.92;
	}
	if (keys[GLFW_KEY_SPACE])
	{
		speed *= 0.5;
		//turn *= 0.5;
	}
	if (speed > 0) y = 1;
	else if (speed < 0) y = -1;
	if (turn > 0) x = 1;
	else if (turn < 0) x = -1;
	else x = 0;

	this->rotate((turn) / 8);
	direction = glm::vec2(glm::cos(rotation), glm::sin(rotation));

	this->move(glm::vec3(0, 0, speed));


	speed *= 0.98;

	if (abs(turn) < 0.001) {
		turn = 0;
	}
	if (abs(speed) < 0.001) {
		speed = 0;
	}
}

void Pojazd::handleCollision(glm::vec2 normal) {
	move(glm::vec3(0.0f, 0.0f, -y));
}