#pragma once

#include <glm/glm.hpp>
#include <GL/glew.h>

class Light
{
protected:
	glm::vec3 color;
	GLfloat ambientIntensity;
	GLfloat diffuseIntensity;
public:
	Light();
	Light(glm::vec3 color, GLfloat ambientIntensity, GLfloat diffuseIntensity);

	~Light();

	void useLight(GLuint colorLocation, GLuint ambientIntensityLocation, GLuint diffuseIntensityLocation);
};

