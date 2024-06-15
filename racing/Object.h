#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "constants.h"
#include "ShaderProgram.h"

class Object {
public:
	// Matryca transformacji -> pozycja w �wiecie 3D
	glm::mat4 M;

	float* vertices; // 4 * x
	int vertexCount;
	float* normals; // 4 * x
	float* texCoords; // 2 * x

	glm::vec2 velcoity; //wektor pr�dko�ci

	// pozycja w �wiecie 2D
	glm::vec2 position; //automatycznie obliczane z M[3][0], M[3][2] -> punkt 0,0 obiektu
	GLfloat rotation;

	glm::vec2 size; // x,y -> po�owa szeroko�ci i po�owa wysoko�ci -> odleg�o�� od �rodka do kraw�dzi przy braku obrotu podstawy
	glm::vec2 points[4]; // punkty w 2D �wiecie, kt�re definiuj� obiekt
	GLfloat diagonal; // d�ugo�� przek�tnej
	GLfloat angle; // k�t mi�dzy przek�tn� a osi� x

	void calcPoints(); // oblicza punkty na podstawie pozycji i rozmiaru
	void calcPosition2D(); // oblicza pozycj� w 2D na podstawie M
public:
	Object();
	Object(glm::mat4 M, float* vertices, int countVertices, float* normals, float* texCoords, glm::vec2 sizeOf2Dmodel); // sizeOf2Dmodel -> x,y -> po�owa szeroko�ci i po�owa wysoko�ci
	// DO NOT SCALE OR ROTATE THE MODEL IN THE CONSTRUCTOR, if u have to, there are functions for that, thanks :)
	~Object();

	void rotate(GLfloat curentRotation); // Mo�na obraca� tylko w osi Y
	void move(glm::vec3 moveVector); // przesuwa obiekt o wektor moveVector

	void draw(ShaderProgram* sp, GLuint texture);
	void drawScale(ShaderProgram* sp, GLuint texture, glm::vec3 scale);

	glm::mat4 getM() { return M; }
	glm::vec2 getPosition() { return position; }
	glm::vec2 getPoint(int i) { return points[i]; }
	GLfloat getDiagonal() { return diagonal; }

	virtual void handleCollision(glm::vec2 normal);
};
