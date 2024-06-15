#include "SpotLight.h"

SpotLight::SpotLight() : PointLight()
{
	direction = glm::vec3(0.0f, -1.0f, 0.0f);
	edge = 0.0f;
	procEdge = cosf(glm::radians(edge));
}

SpotLight::SpotLight(glm::vec3 color, GLfloat ambientIntensity, GLfloat diffuseIntensity, 
	glm::vec3 position, GLfloat constant, GLfloat linear, GLfloat exponent, 
	glm::vec3 direction, GLfloat edge) : 

	PointLight(color, ambientIntensity, diffuseIntensity, position, constant, linear, exponent),
	direction(direction), edge(edge), procEdge(cosf(glm::radians(edge)))
{

}

SpotLight::~SpotLight()
{
	printf("Brak b³êdów przy usuwaniu obiektu klasy SpotLight");
}

void SpotLight::useLight(GLuint colorLocation, GLuint ambientIntensityLocation, GLuint diffuseIntensityLocation, GLuint positionLocation, GLuint constantLocation, GLuint linearLocation, GLuint exponentLocation, GLuint directionLocation, GLuint edgeLocation)
{
	glUniform3f(colorLocation, color.x, color.y, color.z);
	glUniform1f(ambientIntensityLocation, ambientIntensity);
	glUniform1f(diffuseIntensityLocation, diffuseIntensity);
	glUniform3f(positionLocation, position.x, position.y, position.z);
	glUniform1f(constantLocation, constant);
	glUniform1f(linearLocation, linear);
	glUniform1f(exponentLocation, exponent);
	glUniform3f(directionLocation, direction.x, direction.y, direction.z);
	glUniform1f(edgeLocation, procEdge);

	if(colorLocation == -1 || ambientIntensityLocation == -1 || diffuseIntensityLocation == -1 || positionLocation == -1 || constantLocation == -1 || linearLocation == -1 || exponentLocation == -1 || directionLocation == -1 || edgeLocation == -1)
	{
		printf("B³¹d przy przypisywaniu wartoœci do zmiennych w klasie SpotLight");
	}
}

void SpotLight::calculateSpotLightFromMatrix(glm::mat4 M)
{
	// Extract the position of the light from the model matrix
	position = glm::vec3(M[3]);

	// Extract the forward direction from the model matrix
	direction = glm::normalize(glm::vec3(M[2]));

	// Set the light's direction to the forward direction
	
}