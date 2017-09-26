#pragma once

#include <GL/glew.h>
#include <GL/freeglut.h>

class Shader {
private:
	GLuint _shaderHandle;
public:
	Shader();
	~Shader();
	void CreateShader(std::string path, GLenum type);
	GLuint GetHandle();
};
