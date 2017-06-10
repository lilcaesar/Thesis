#version 400

in vec3 VertexPosition;
in vec3 VertexNormal;

out vec3 VNormal;
out vec3 VPosition;

out vec4 frag_color;
out vec3 Position_worldSpace;
out vec3 Normal_cameraspace;
out vec3 EyeDirection_cameraspace;
out vec3 LightDirection_cameraspace;

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

    //Position of vertices in worldspace (m * vertices)
    Position_worldSpace = (model * vec4(VertexPosition, 1.0)).xyz;

    //Vector from vertex to camera in camera space
    vec3 vertexPosition_cameraspace = (view * model * vec4(VertexPosition, 1.0)).xyz;
    EyeDirection_cameraspace = vec3(0,0,0) - vertexPosition_cameraspace;

    //Vector from vertex to the light in camera space
    vec3 LightPosition_cameraspace = (view * vec4(0.0,0.0,1.0,1.0)).xyz;
    LightDirection_cameraspace = LightPosition_cameraspace + EyeDirection_cameraspace;

    //Normal of vertices in camera space (if model is scaled use its inverse transpose)
    Normal_cameraspace = (view * (transpose(inverse(model))) * vec4(VertexNormal,0.0)).xyz;

    frag_color = vec4(0.5, 0.5, 0.5, 1.0);

    gl_Position = MVP * vec4(VertexPosition,1.0);
}
