#pragma once

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>

class Dephtbuffer {
public:
	Dephtbuffer();
	~Dephtbuffer();
	void Create(int resolution);
	void Bind();
	void Unbind();
	void BindDepthMap();
	void UnbindDepthMap();
private:
	GLuint _framebuffer;
	GLuint _dephtmap;
	GLsizei _resolution;
};