#version 330

in vec3 vertices;
in vec3 normals;
uniform vec4 color;

out vec4 frag_color;
out vec3 faceNormal;
out vec3 lightDir;
out vec3 viewDir;

uniform mat4 proj;
uniform mat4 model;
uniform mat4 view;
uniform vec3 lightPosition_worldspace;

void main() {
    vec4 MV_vertices = view * model * vec4(vertices, 1.0);
    gl_Position = proj * MV_vertices;
    frag_color = color;
    faceNormal = mat3(transpose(inverse(view*model))) * normals;
    lightDir = lightPosition_worldspace - MV_vertices.xyz;
    viewDir = -MV_vertices.xyz;
}
