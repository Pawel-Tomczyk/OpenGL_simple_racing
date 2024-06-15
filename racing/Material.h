#pragma once

#include <glm/glm.hpp>
#include <GL/glew.h>

class Material
{
private:
	GLfloat specularIntensity; // jak du¿o œwiat³a odbija siê od powierzchni
	GLfloat shininess; // jak bardzo powierzchnia jest b³yszcz¹ca (skupienie œwiat³a)
public:
	Material();
	Material(GLfloat specularIntensity, GLfloat shininess);
	~Material();

	void useMaterial(GLuint speculatIntensityLocation, GLuint shininessLocation);
};

