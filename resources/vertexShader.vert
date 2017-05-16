#version 330

in vec3 vertices;
//in vec3 normals;
//in vec3 color;

out vec4 frag_color;

uniform mat4 modelViewProj;
//uniform mat4 projection;

void main() {
    frag_color = vec4(1.0, 1.0, 1.0, 1.0);
    gl_Position = /*projection **/ modelViewProj * vec4(vertices, 1.0);
}
