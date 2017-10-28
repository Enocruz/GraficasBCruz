#version 330

in vec3 VertexPosition;
in vec3 VertexColor;
in vec3 VertexNormal;

out vec3 InterpolatedColor;
out vec3 InterpolatedNormal;
out vec3 PixelPosition;

uniform mat4 mvpMatrix;
uniform vec3 LightPosition;
uniform mat4 modelMatrix;

void main(){

	mat3 NormalMatrix = transpose(inverse(mat3(modelMatrix)));
	
	PixelPosition = vec3(modelMatrix * vec4(VertexPosition, 1.0f));
	
	InterpolatedNormal = NormalMatrix * VertexNormal;

	InterpolatedColor = VertexColor;

	gl_Position = mvpMatrix * vec4(VertexPosition, 1.0f);
}