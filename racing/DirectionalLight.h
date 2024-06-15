#pragma once
#include "Light.h"
class DirectionalLight : public Light
{
protected:
	glm::vec3 direction;
public:
	DirectionalLight();
	DirectionalLight(glm::vec3 color, GLfloat ambientIntensity, GLfloat diffuseIntensity, // basic Light
		glm::vec3 direction); // DirectionalLight

	~DirectionalLight();

	void useLight(GLuint colorLocation, GLuint ambientIntensityLocation, GLuint diffuseIntensityLocation, GLuint directionLocation);
};

