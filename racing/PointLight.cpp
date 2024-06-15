#include "PointLight.h"

PointLight::PointLight() : Light()
{
	position = glm::vec3(0.0f, 1.0f, 0.0f);
	constant = 1.0f;
	linear = 0.0f;
	exponent = 0.0f;
}

PointLight::PointLight(glm::vec3 color, GLfloat ambientIntensity, GLfloat diffuseIntensity, glm::vec3 position, GLfloat constant, GLfloat linear, GLfloat exponent)
: Light(color, ambientIntensity, diffuseIntensity), position(position), constant(constant), linear(linear), exponent(exponent)
{
}

PointLight::~PointLight()
{
	printf("Destruktor klasy PointLight\n");
}

void PointLight::useLight(GLuint colorLocation, GLuint ambientIntensityLocation, GLuint diffuseIntensityLocation, GLuint positionLocation, GLuint constantLocation, GLuint linearLocation, GLuint exponentLocation)
{
	Light::useLight(colorLocation, ambientIntensityLocation, diffuseIntensityLocation);
	glUniform3f(positionLocation, position.x, position.y, position.z);
	glUniform1f(constantLocation, constant);
	glUniform1f(linearLocation, linear);
	glUniform1f(exponentLocation, exponent);

	if (colorLocation == -1 || ambientIntensityLocation == -1 || diffuseIntensityLocation == -1 || positionLocation == -1 || constantLocation == -1 || linearLocation == -1 || exponentLocation == -1)
	{
		printf("B³¹d przy u¿yciu Œwiat³a(PointLight)\n");
	}
}
