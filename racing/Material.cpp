#include "Material.h"

Material::Material() : specularIntensity(1.0f), shininess(1.0f)
{
}

Material::Material(GLfloat specularIntensity, GLfloat shininess) : specularIntensity(specularIntensity), shininess(shininess)
{
}

Material::~Material()
{
	printf("Brak b³êdów przy usuwaniu obietku z klasy Material\n");
}

void Material::useMaterial(GLuint speculatIntensityLocation, GLuint shininessLocation)
{
	glUniform1f(speculatIntensityLocation, specularIntensity);
	glUniform1f(shininessLocation, shininess);

	if (speculatIntensityLocation == -1 || shininessLocation == -1)	printf("B³¹d przy u¿yciu materia³u\n");
}
