#include "DirectionalLight.h"

DirectionalLight::DirectionalLight() : Light(), direction(glm::vec3(0.0f, 1.0f, 0.0f))
{
}

DirectionalLight::DirectionalLight(glm::vec3 color, GLfloat ambientIntensity, GLfloat diffuseIntensity, glm::vec3 direction) : Light(color, ambientIntensity, diffuseIntensity), direction(direction)
{
}

DirectionalLight::~DirectionalLight()
{
	printf("Brak b³êdów przy usuwaniu obietku z klasy DirectionalLight\n");
}

void DirectionalLight::useLight(GLuint colorLocation, GLuint ambientIntensityLocation, GLuint diffuseIntensityLocation, GLuint directionLocation)
{
	glUniform3f(colorLocation, color.x, color.y, color.z);
	glUniform1f(ambientIntensityLocation, ambientIntensity);
	glUniform1f(diffuseIntensityLocation, diffuseIntensity);
	glUniform3f(directionLocation, direction.x, direction.y, direction.z);

	if (colorLocation == -1 || ambientIntensityLocation == -1 || diffuseIntensityLocation == -1 || directionLocation == -1)
	{
		printf("B³¹d przy u¿yciu Œwiat³a(DirectionalLight)\n");
	}
}
