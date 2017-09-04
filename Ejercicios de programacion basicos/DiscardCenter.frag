#version 330

in vec3 InterpolatedColor;

out vec4 FragColor;

void main(){
	vec2 centro = vec2(200,200);
	vec2 pixelPositionInWindow = gl_FragCoord.xy - centro;
	if(sqrt(pixelPositionInWindow.x*pixelPositionInWindow.x+pixelPositionInWindow.y*pixelPositionInWindow.y) < 100){
		discard;
	}
	
	FragColor = vec4(InterpolatedColor, 1.0f);
}