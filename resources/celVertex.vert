#version 330

in vec3 vertices;
in vec3 normals;

uniform mat4 proj;
uniform mat4 model;
uniform mat4 view;
uniform vec3 lightPosition_worldspace;

out vec3 normal;
out vec3 lightDir;

void main()
{
    mat4 MVP = proj * view * model;
    vec4 MV_vertices = view * model * vec4(vertices, 1.0);
    mat3 normalMatrix = mat3(transpose(inverse(view*model)));
	normal = normalMatrix * normals;
	lightDir = lightPosition_worldspace - MV_vertices.xyz;
	gl_Position = MVP * vec4(vertices, 1.0);
}
