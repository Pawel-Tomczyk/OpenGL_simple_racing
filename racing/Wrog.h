#pragma once
#include "Pojazd.h"
class Wrog :
    public Pojazd
{
public:
	int point;

	Wrog(glm::mat4 M, float* vertices, int countVertices, float* normals, float* texCoords, glm::vec2 sizeOf2Dmodel);
	void keyControl(bool* keys, GLfloat deltaTime) override { /*nie dla maruchy*/ }
	void control(glm::vec2* points, int pointsSize);
};

