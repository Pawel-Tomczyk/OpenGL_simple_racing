#include "Light.h"

Light::Light()
{
	color = glm::vec3(1.0f, 1.0f, 1.0f);
	ambientIntensity = 1.0f;
	diffuseIntensity = 0.0f;
}

Light::Light(glm::vec3 color, GLfloat ambientIntensity, GLfloat diffuseIntensity) : color(color), ambientIntensity(ambientIntensity), diffuseIntensity(diffuseIntensity)
{
}

Light::~Light()
{
	printf("Brak b³êdów przy usuwaniu obietku z klasy Light\n");
}

void Light::useLight(GLuint colorLocation, GLuint ambientIntensityLocation, GLuint diffuseIntensityLocation)
{
	glUniform3f(colorLocation, color.x, color.y, color.z);
	glUniform1f(ambientIntensityLocation, ambientIntensity);
	glUniform1f(diffuseIntensityLocation, diffuseIntensity);

	if(colorLocation == -1 || ambientIntensityLocation == -1 || diffuseIntensityLocation == -1)
	{
		printf("B³¹d przy u¿yciu Œwiat³a(Light)\n");
	}
}
