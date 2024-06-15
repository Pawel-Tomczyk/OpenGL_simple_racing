#pragma once

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <glm\glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


class MovableKostka
{
private:
	glm::mat4 M;
	GLfloat turn;
	GLfloat speed;

public:
	MovableKostka();
	~MovableKostka();

	void keyControl(bool* keys, GLfloat deltaTime);
	glm::mat4 getM();
};

