#version 400

in vec3 VertexPosition;
in vec3 VertexNormal;

out vec3 VNormal;
out vec3 lightDir;
out vec3 viewDir;

uniform mat4 proj;
uniform mat4 model;
uniform mat4 view;
uniform vec3 lightPosition_worldspace;

void main()
{
    vec4 MV_vertices = view * model * vec4(VertexPosition, 1.0);
    mat4 MVP = proj * view * model;
    VNormal = mat3(transpose(inverse(view*model))) * VertexNormal;
    lightDir = lightPosition_worldspace - MV_vertices.xyz;
    viewDir = -MV_vertices.xyz;
    gl_Position = MVP * vec4(VertexPosition,1.0);
}
