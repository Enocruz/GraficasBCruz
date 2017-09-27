/*Brandon Alain Cruz Ruiz A01375640*/

#include "ShaderProgram.h"

void ShaderProgram::DeleteAndDetachShaders()
{
	_attachedShaders.clear();
}

void ShaderProgram::DeleteProgram()
{
	DeleteAndDetachShaders();
	glUseProgram(0);
}

ShaderProgram::ShaderProgram()
{
	_programHandle = 0;
}

ShaderProgram::~ShaderProgram()
{
	DeleteProgram();
}

void ShaderProgram::CreateProgram()
{
	_programHandle = glCreateProgram();
}

void ShaderProgram::AttachShader(std::string name, GLenum type)
{
	// Create and add the shaders to a list
	std::unique_ptr<Shader> shader(new Shader);
	shader->CreateShader(name, type);
	_attachedShaders.push_back(std::move(shader));
}

void ShaderProgram::LinkProgram()
{
	for (int i = 0; i < _attachedShaders.size() ; i++)
		glAttachShader(_programHandle, _attachedShaders.at(i).get()->GetHandle());
	glLinkProgram(_programHandle);
	DeleteAndDetachShaders();
}

void ShaderProgram::Activate()
{
	glUseProgram(_programHandle);
	
}

void ShaderProgram::Deactivate()
{
	glUseProgram(0);
}

void ShaderProgram::SetAttribute(GLuint locationIndex, std::string name)
{
	glBindAttribLocation(_programHandle, locationIndex, name.c_str());

}

void ShaderProgram::SetUniformf(std::string name, float value)
{
	GLint uniformLocation = glGetUniformLocation(_programHandle, name.c_str());
	glUniform1f(uniformLocation, value);
}

void ShaderProgram::SetUniformf(std::string name, float x, float y)
{
	GLint uniformLocation = glGetUniformLocation(_programHandle, name.c_str());
	glUniform2f(uniformLocation, x,y);
}

void ShaderProgram::SetUniformf(std::string name, float x, float y, float z)
{
	GLint uniformLocation = glGetUniformLocation(_programHandle, name.c_str());
	glUniform3f(uniformLocation,x,y,z);
}

void ShaderProgram::SetUniformf(std::string name, float x, float y, float z, float w)
{
	GLint uniformLocation = glGetUniformLocation(_programHandle, name.c_str());
	glUniform4f(uniformLocation, x,y,z,w);
}
