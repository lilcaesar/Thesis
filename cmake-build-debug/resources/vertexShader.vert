#version 330

in vec3 vertices;
//in vec3 normals;
//in vec3 color;

out vec4 frag_color;

uniform mat4 proj;
uniform mat4 model;
uniform mat4 view;

void main() {
    mat4 mvp = proj * view * model;
    frag_color = vec4(1.0, 1.0, 1.0, 1.0);
    gl_Position = mvp * vec4(vertices, 1.0);
}
