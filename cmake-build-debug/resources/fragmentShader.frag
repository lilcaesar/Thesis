#version 330

out vec4 color;

in vec4 frag_color;

in vec3 faceNormal;
in vec3 lightDir;
in vec3 viewDir;

void main() {
    vec3 col = vec3(0.0);
    col += vec3(1.0)*vec3(0.1, 0.1, 0.1);
    vec3 normalizedNormals= normalize(faceNormal);
    vec3 normalizedView= normalize(viewDir);
    vec3 normalizedLight= normalize(lightDir);
    float lambert = dot(normalizedNormals,normalizedLight);
    if(lambert>0.0){
        col += vec3(lambert);
        vec3 normalizedView= normalize(viewDir);
        vec3 reflection = reflect(-normalizedLight,normalizedNormals);
        col += vec3(pow(max(dot(reflection, normalizedView),0.0), 90.0));
    }
    col *= frag_color.xyz;
    color = vec4(col, frag_color.a);
}
