#version 330

in vec3 VertexPosition;
in vec3 VertexColor;
in vec3 VertexNormal;
in vec2 VertexTexCoord;

out vec3 InterpolatedColor;
out vec3 InterpolatedVertexNormal;
out vec3 PixelPosition;
out vec2 InterpolatedTexCoord;

uniform mat4 mvpMatrix;
uniform mat4 modelMatrix;

void main()
{
	InterpolatedColor = VertexColor;
	PixelPosition = vec3(modelMatrix*vec4(VertexPosition, 1.0f));
	InterpolatedVertexNormal = VertexNormal;
	InterpolatedTexCoord = VertexTexCoord;
	gl_Position = mvpMatrix * vec4(VertexPosition, 1.0f);
}