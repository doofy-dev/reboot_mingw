#version 330 core


layout (location = 0) in vec3 position;
layout (location = 1) in vec4 color;

uniform mat4 view;
uniform mat4 model;
uniform mat4 proj;
out vec4 col;

void main() {
    vec3 pos = position;
    col=color;

	gl_Position = proj  * view * model * vec4(position,1);
}
