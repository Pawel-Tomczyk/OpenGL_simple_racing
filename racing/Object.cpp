#include "Object.h"

void Object::calcPoints()
{
	points[0] = position + diagonal * glm::vec2(glm::cos(angle + rotation), glm::sin(angle + rotation));
	points[1] = position + diagonal * glm::vec2(glm::cos(PI - angle + rotation), glm::sin(PI - angle + rotation));
	points[2] = position + diagonal * glm::vec2(glm::cos(PI + angle + rotation), glm::sin(PI + angle + rotation));
	points[3] = position + diagonal * glm::vec2(glm::cos(2 * PI - angle + rotation), glm::sin(2 * PI - angle + rotation));
}

void Object::calcPosition2D()
{
	position = glm::vec2(M[3][0], M[3][2]);
}

Object::Object()
{
	printf("Obiekt bezu¿yteczny jak ty, sadeg.\n");
}

Object::Object(glm::mat4 M, float* vertices, int countVertices, float* normals, float* texCoords, glm::vec2 sizeOf2Dmodel)
{
	this->M = M;

	this->vertices = vertices;
	vertexCount = countVertices;
	this->normals = normals;
	this->texCoords = texCoords;

	velcoity = glm::vec2(0.0f, 0.0f); //wektor prêdkoœci

	calcPosition2D();
	rotation = 0.0f;

	size = sizeOf2Dmodel;
	diagonal = glm::length(size); // d³ugoœæ przek¹tnej
	angle = acos(glm::normalize(size).x);

	calcPoints();	
}

Object::~Object()
{
	delete vertices;
	delete normals;
	delete texCoords;
}

void Object::rotate(GLfloat curentRotation)
{
	rotation += curentRotation;
	if(rotation >= 2*PI) rotation -= 2*PI;
	if(rotation <= -2*PI) rotation += 2*PI;
	M = glm::rotate(M, curentRotation, glm::vec3(0, 1, 0));

	this->calcPosition2D();
	this->calcPoints();
}

void Object::move(glm::vec3 moveVector)
{
	this->M = glm::translate(M, moveVector);
	this->calcPosition2D();
	this->calcPoints();
}

void Object::draw(ShaderProgram* sp, GLuint texture)
{
	glVertexAttribPointer(sp->a("vertex"), 4, GL_FLOAT, false, 0, vertices); //Wska¿ tablicê z danymi dla atrybutu vertex
	glVertexAttribPointer(sp->a("normal"), 4, GL_FLOAT, false, 0, normals); //Wska¿ tablicê z danymi dla atrybutu normal
	glVertexAttribPointer(sp->a("texCoord"), 2, GL_FLOAT, false, 0, texCoords); //Wska¿ tablicê z danymi dla atrybutu texCoord

	glUniform1i(sp->u("theTexture"), 0);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);

	glUniformMatrix4fv(sp->u("M"), 1, false, glm::value_ptr(M));

	glDrawArrays(GL_TRIANGLES, 0, vertexCount);
}

void Object::drawScale(ShaderProgram* sp, GLuint texture, glm::vec3 scale)
{
	glVertexAttribPointer(sp->a("vertex"), 4, GL_FLOAT, false, 0, vertices); //Wska¿ tablicê z danymi dla atrybutu vertex
	glVertexAttribPointer(sp->a("normal"), 4, GL_FLOAT, false, 0, normals); //Wska¿ tablicê z danymi dla atrybutu normal
	glVertexAttribPointer(sp->a("texCoord"), 2, GL_FLOAT, false, 0, texCoords); //Wska¿ tablicê z danymi dla atrybutu texCoord

	glUniform1i(sp->u("theTexture"), 0);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);

	glUniformMatrix4fv(sp->u("M"), 1, false, glm::value_ptr(glm::scale(M, scale)));

	glDrawArrays(GL_TRIANGLES, 0, vertexCount);
}

void Object::handleCollision(glm::vec2 normal)
{
	// sigma -> ma w dupie ¿e ktoœ na niego naje¿dza, ¿yje w³asnym ¿yciem, nie jakieœ tam kolizje
}
