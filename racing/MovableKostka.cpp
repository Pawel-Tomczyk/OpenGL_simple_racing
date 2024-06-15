#include "MovableKostka.h"

MovableKostka::MovableKostka()
{
	M = glm::mat4(1.0);
	turn = 0;
	speed = 0;
}

MovableKostka::~MovableKostka()
{
}

void MovableKostka::keyControl(bool* keys, GLfloat deltaTime)
{
	GLfloat velocity = 2 * deltaTime;

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
		if (turn < 0.2) turn += velocity*0.95;
		if (turn > 0.6) turn = 0.6;
		else turn += velocity * 0.3;
	}
	else if (keys[GLFW_KEY_D])
	{
		if(turn > -0.2) turn -= velocity;
		if (turn < -0.6) turn = -0.6;
		else turn -= velocity * 0.3;

	}
	else {
		turn *= 0.92;
	}
	if(keys[GLFW_KEY_SPACE])
	{
		speed *= 0.5;
		//turn *= 0.5;
	}
	

	M = glm::translate(M, glm::vec3(0, 0, speed));
	M = glm::rotate(M, (turn * speed)/4, glm::vec3(0, 1, 0));

	speed *= 0.98;

	if(abs(turn) < 0.01) 	{
		turn = 0;
	}
	if(abs(speed) < 0.01) {
		speed = 0;
	}
}

glm::mat4 MovableKostka::getM()
{
	return M;
}
