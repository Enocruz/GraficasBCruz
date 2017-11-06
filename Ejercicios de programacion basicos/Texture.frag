#version 330

in vec3 InterpolatedColor;
in vec3 InterpolatedNormal;
in vec3 PixelPosition;
in vec2 InterpolatedTexCoord;


out vec4 FragColor;

uniform vec3 LightColor;
uniform vec3 LightPosition;
uniform mat4 modelMatrix;
uniform vec3 CameraPosition;
uniform sampler2D DiffuseTexture;


void main(){
	
	vec3 L = normalize(LightPosition - PixelPosition);

	vec3 R = normalize(reflect(-L, InterpolatedNormal));

	vec3 V = normalize(CameraPosition - PixelPosition);

	vec3 specular = 0.5f * pow(dot(V,R),32) * LightColor;

	vec3 ambient = 0.1f * LightColor;

	vec3 diffuse = dot(normalize(InterpolatedNormal),L) * normalize(LightColor);
	
	//vec3 phong = (specular+ambient+diffuse) * InterpolatedColor;
	vec3 phong = (specular+ambient+diffuse);
	FragColor = texture2D(DiffuseTexture,InterpolatedTexCoord);// * phong, 1.0f);
	//FragColor = vec4(phong, 1.0f);
}