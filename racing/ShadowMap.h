#pragma once
#include <GL\glew.h>

class ShadowMap
{
public:
	ShadowMap();
	~ShadowMap();
	virtual bool init(GLsizei width, GLsizei height);
	void bind();
	void unbind();
	void bindTexture(GLuint textureUnit);
protected:
	GLuint FBO;
	GLuint shadowMap;
	GLsizei width, height;
};

