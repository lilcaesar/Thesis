#version 330
#extension GL_EXT_gpu_shader4 : enable

in vec3 vertices;

uniform mat4 proj;
uniform mat4 model;
uniform mat4 view;

void main(void) {
    mat4 mvp = proj * view * model;

    gl_Position = mvp * vec4(vertices, 1.0);
}