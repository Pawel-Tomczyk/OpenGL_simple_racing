#pragma once
#include "PointLight.h"
class SpotLight : public PointLight
{
protected:
	glm::vec3 direction;
	GLfloat edge, procEdge;
public:
	SpotLight();
	SpotLight(glm::vec3 color, GLfloat ambientIntensity, GLfloat diffuseIntensity, // basic Light
				glm::vec3 position, GLfloat constant, GLfloat linear, GLfloat exponent, // PointLight
				glm::vec3 direction, GLfloat edge); // SpotLight
	~SpotLight();
	void useLight(GLuint colorLocation, GLuint ambientIntensityLocation, GLuint diffuseIntensityLocation, 
					GLuint positionLocation, GLuint constantLocation, GLuint linearLocation, GLuint exponentLocation,
					GLuint directionLocation, GLuint edgeLocation);
	void calculateSpotLightFromMatrix(glm::mat4 M);
};

