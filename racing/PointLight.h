#pragma once
#include "Light.h"
class PointLight : public Light
{
public:
	glm::vec3 position;
	GLfloat constant, linear, exponent;
public:
	PointLight();
	PointLight(glm::vec3 color, GLfloat ambientIntensity, GLfloat diffuseIntensity,	// basic Light
		glm::vec3 position, GLfloat constant, GLfloat linear, GLfloat exponent); // PointLight
	~PointLight();

	void useLight(GLuint colorLocation, GLuint ambientIntensityLocation, GLuint diffuseIntensityLocation, GLuint positionLocation, GLuint constantLocation, GLuint linearLocation, GLuint exponentLocation);
};

