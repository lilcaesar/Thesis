#version 330;
uniform mat4 modelViewProj;
uniform mat4 projection;
out vec4 frag_color;
in vec3 vertices;
in vec3 color;
void main() {
    frag_color = 3.0 * modelViewProj * vec4(color, 1.0);
    gl_Position = projection * modelViewProj * vec4(vertices, 1.0);
}