#version 330

in vec3 vertices;
in vec3 normals;

out vec4 frag_color;

uniform mat4 proj;
uniform mat4 model;
uniform mat4 view;
uniform vec3 lightPosition_worldspace;

void main() {
    mat4 mvp = proj * view * model;

    gl_Position = mvp * vec4(vertices, 1.0);

    vec3 lightVector = lightPosition_worldspace - vertices;
    float dist = length(lightVector);

    float attenuation = 1.0 / (1.0+0.1*dist+0.01*dist*dist);

    lightVector = normalize(lightVector);

    float nxDir = max(0.0, dot(normals, lightVector));
    frag_color = vec4(0.5, 0.5, 0.5, 1.0) * nxDir * attenuation;
}
