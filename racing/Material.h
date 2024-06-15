#pragma once

#include <glm/glm.hpp>
#include <GL/glew.h>

class Material
{
private:
	GLfloat specularIntensity; // jak du�o �wiat�a odbija si� od powierzchni
	GLfloat shininess; // jak bardzo powierzchnia jest b�yszcz�ca (skupienie �wiat�a)
public:
	Material();
	Material(GLfloat specularIntensity, GLfloat shininess);
	~Material();

	void useMaterial(GLuint speculatIntensityLocation, GLuint shininessLocation);
};

