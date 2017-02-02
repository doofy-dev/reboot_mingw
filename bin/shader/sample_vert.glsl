#version 330 core


layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;
layout (location = 2) in vec3 norm;

uniform mat4 view;
uniform mat4 model;
uniform mat4 proj;
out vec3 normal;
out vec3 toCameraVector;
out vec3 toLightVector;
out vec4 col;

void main() {
    col=vec4(color,1);
    vec4 worldPosition = model * vec4(position, 1.0);
	toLightVector = vec3(0,100,0) - worldPosition.xyz;
	toCameraVector = (inverse(view) * vec4(0.0,0.0,0.0,1.0)).xyz - worldPosition.xyz;

	normal =(model * vec4(norm,1.0)).xyz;
	gl_Position = proj  * view * worldPosition;
}
