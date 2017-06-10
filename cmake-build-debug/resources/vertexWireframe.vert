#version 400

in vec3 VertexPosition;
in vec3 VertexNormal;

out vec3 VNormal;
out vec3 VPosition;

uniform mat4 ModelViewMatrix;
uniform mat3 NormalMatrix;

uniform mat4 proj;
uniform mat4 model;
uniform mat4 view;

void main()
{
    mat4 MVP = proj * view * model;
    VNormal = normalize( NormalMatrix * VertexNormal);
    VPosition = vec3(ModelViewMatrix * vec4(VertexPosition,1.0));
    gl_Position = MVP * vec4(VertexPosition,1.0);
}
