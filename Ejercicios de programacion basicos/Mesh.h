/*Brandon Alain Cruz Ruiz A01375640*/

#pragma once

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <vector>


class Mesh{
private:
	GLuint _vertexArrayObject;
	GLuint _positionsVertexBufferObject;
	GLuint _colorsVertexBufferObject;
	GLuint _vertexCount;
	GLuint _indicesBufferObject;
	GLuint _indicesCount;
	GLuint _normalsVertexBufferObject;
	GLuint _texturesVertexBufferObject;

	void SetAttributeData(GLuint buffer, const GLsizeiptr size, const void* data, GLenum usage, GLuint locationIndex, const GLint components);

public:
	Mesh();
	~Mesh();
	void CreateMesh(GLint vertexCount);
	void Draw(GLenum primitive);
	void SetPositionAttribute(std::vector<glm::vec2> positions, GLenum usage, GLuint locationIndex);
	void SetPositionAttribute(std::vector<glm::vec3> positions, GLenum usage, GLuint locationIndex);
	void SetColorAttribute(std::vector<glm::vec3> colors, GLenum usage, GLuint locationIndex);
	void SetColorAttribute(std::vector<glm::vec4> colors, GLenum usage, GLuint locationIndex);
	void SetNormalAttibute(std::vector<glm::vec3> normals, GLenum usage, GLuint locationIndex);
	void SetTextureAttribute(std::vector<glm::vec2> textureCoords, GLenum usage, GLuint locationIndex);
	void SetIndices(std::vector<unsigned int> indices, GLenum usage);
};