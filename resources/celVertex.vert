#version 330

in vec3 vertices;
in vec3 normals;

uniform mat4 proj;
uniform mat4 model;
uniform mat4 view;

out vec3 normal;

void main()
{
    mat4 MVP = proj * view * model;
    mat3 normalMatrix = mat3(transpose(inverse(view*model)));
	normal = normalMatrix * normals;
	gl_Position = MVP * vec4(vertices, 1.0);
}
