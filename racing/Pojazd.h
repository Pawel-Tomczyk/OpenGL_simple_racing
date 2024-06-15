#pragma once
#include "Object.h"
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <glm\glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Pojazd :
    public Object
{
public:
	GLfloat turn;
	GLfloat speed;
	int y;
	int x;
	glm::vec2 direction;
public:
	Pojazd();
	Pojazd(glm::mat4 M, float* vertices, int countVertices, float* normals, float* texCoords, glm::vec2 sizeOf2Dmodel); // sizeOf2Dmodel -> x,y -> po³owa szerokoœci i po³owa wysokoœci
	// DO NOT SCALE OR ROTATE THE MODEL IN THE CONSTRUCTOR, if u have to, there are functions for that, thanks :)
	~Pojazd();
	virtual void keyControl(bool* keys, GLfloat deltaTime);
	void handleCollision(glm::vec2 normal) override;
};

