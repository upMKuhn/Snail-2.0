#version 120

attribute vec2 textureCoords;
attribute vec3 position;

varying vec2 textCoord0; 

uniform mat4 transform;

void main() {
    gl_Position = transform * vec4(position, 1.0);
    textCoord0 = textureCoords;
}