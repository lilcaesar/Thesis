#version 330

in vec3 vertices;
in vec3 normals;
//in vec3 color;

out vec4 frag_color;
out vec3 Position_worldSpace;
out vec3 Normal_cameraspace;
out vec3 EyeDirection_cameraspace;
out vec3 LightDirection_cameraspace;

uniform mat4 proj;
uniform mat4 model;
uniform mat4 view;
uniform vec3 lightPosition_worldspace;

void main() {
    mat4 mvp = proj * view * model;

    //Position of vertices in worldspace (m * vertices)
    Position_worldSpace = (model * vec4(vertices, 1.0)).xyz;

    //Vector from vertex to camera in camera space
    vec3 vertexPosition_cameraspace = (view * model * vec4(vertices, 1.0)).xyz;
    EyeDirection_cameraspace = vec3(0,0,0) - vertexPosition_cameraspace;

    //Vector from vertex to the light in camera space
    vec3 LightPosition_cameraspace = (view * vec4(lightPosition_worldspace,1.0)).xyz;
    LightDirection_cameraspace = LightPosition_cameraspace + EyeDirection_cameraspace;

    //Normal of vertices in camera space (if model is scaled use its inverse transpose)
    Normal_cameraspace = (view * (transpose(inverse(model))) * vec4(normals,0.0)).xyz;

    //Position of vertices in clip space (mvp * vertices)
    gl_Position = mvp * vec4(vertices, 1.0);

    frag_color = vec4(1.0, 0.0, 0.0, 1.0);
}
