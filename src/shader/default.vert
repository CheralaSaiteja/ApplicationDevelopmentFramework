#version 460 core
layout (location = 0) in vec2 aPos;

uniform mat4 scale;
uniform mat4 trans;
uniform float zIndex;

mat4 ltrans = mat4(
    1, 0, 0, -1,
    0, 1, 0, 1,
    0, 0, 1, 0,
    0, 0, 0, 1
);

void main(){
    gl_Position = vec4(aPos, zIndex, 1.0f) * scale * trans;
}