#version 330

in vec3 InterpolatedColor;
in vec3 InterpolatedVertexNormal;
in vec3 PixelPosition;
in vec2 InterpolatedTexCoord;

out vec4 FragColor;

uniform vec3 LightColor;
uniform vec3 LightPosition;
uniform mat4 modelMatrix;
uniform vec3 CameraPosition;
uniform sampler2D DiffuseTexture0;
uniform sampler2D DiffuseTexturePuerco;

void main()
{
	vec3 ambient = 0.1f * normalize(LightColor);

	vec3 L = normalize(LightPosition - PixelPosition);

	mat3 NormalMatrix = transpose(inverse(mat3(modelMatrix)));

	vec3 InterpolatedNormal = normalize(NormalMatrix * InterpolatedVertexNormal);
	vec3 diffuse = dot(normalize(InterpolatedNormal), L) * normalize(LightColor);
	vec3 R = normalize(reflect(-L, InterpolatedNormal));
	vec3 V = normalize(CameraPosition - PixelPosition);
	vec3 specular = 0.5f * pow(dot(V, R), 32) * normalize(LightColor);
	
	//FragColor = texture2D(DiffuseTexture, InterpolatedTexCoord);
	vec3 phong = (ambient + specular + diffuse);
	//FragColor = vec4(phong,1.0f);

	FragColor = mix(texture2D(DiffuseTexturePuerco, InterpolatedTexCoord), texture2D(DiffuseTexture0, InterpolatedTexCoord),0.6f) * vec4(phong,1.0f);
}