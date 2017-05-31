#version 330

in vec3 vertices;
in vec3 barycentric;

uniform mat4 proj;
uniform mat4 model;
uniform mat4 view;

out vec4 frag_color;
varying vec3 vBC;
void main(void) {
    mat4 mvp = proj * view * model;

    frag_color = vec4(0.0, 1.0, 0.0, 1.0);
    vBC = barycentric;
    gl_Position = mvp * vec4(vertices, 1.0);
}