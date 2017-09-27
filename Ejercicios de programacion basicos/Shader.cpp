/*Brandon Alain Cruz Ruiz A01375640*/

#include "Shader.h"
#include "InputFile.h"


Shader::Shader()
{
	_shaderHandle = 0;
}

Shader::~Shader()
{
	glDeleteShader(_shaderHandle);
}

void Shader::CreateShader(std::string path, GLenum type)
{
	InputFile ifile2;
	ifile2.Read(path);
	std::string fragmentSource = ifile2.GetContents();
	_shaderHandle = glCreateShader(type);
	const GLchar *fragmentSource_c = (const GLchar*)fragmentSource.c_str();
	glShaderSource(_shaderHandle, 1, &fragmentSource_c, nullptr);
	glCompileShader(_shaderHandle);
}

GLuint Shader::GetHandle()
{
	return _shaderHandle;
}
