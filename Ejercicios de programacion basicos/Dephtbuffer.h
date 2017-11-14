#pragma once

#include <GL/glew.h>
#include <GL/freeglut.h>

class Dephtbuffer {
private:
	GLuint _framebuffer;
	GLuint _depthmap;
	GLsizei _resolution;
public:
	Dephtbuffer();
	~Dephtbuffer();
	void Create(int resolution);
	void Bind();
	void Unbind();
	void BindDepthMap();
	void UnbindDepthMap();
};
