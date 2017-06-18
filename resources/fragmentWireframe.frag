#version 400

struct MaterialInfo {
  vec4 Kd;            // Diffuse reflectivity
};
uniform MaterialInfo Material;

uniform struct LineInfo {
  float Width;
  vec4 Color;
} Line;

uniform float filled;
uniform float flatColor;

in vec3 GNormal;
in vec3 GlightDir;
in vec3 GviewDir;
noperspective in vec3 GEdgeDistance;

layout( location = 0 ) out vec4 FragColor;

void main() {

    vec3 col = vec3(0.0);
    col += vec3(1.0)*vec3(0.1, 0.1, 0.1);
    vec3 normalizedNormals= normalize(GNormal);
    vec3 normalizedView= normalize(GviewDir);
    vec3 normalizedLight= normalize(GlightDir);
    float lambert = dot(normalizedNormals,normalizedLight);
    if(lambert>0.0){
        col += vec3(lambert);
        vec3 normalizedView= normalize(GviewDir);
        vec3 reflection = reflect(-normalizedLight,normalizedNormals);
        col += vec3(pow(max(dot(reflection, normalizedView),0.0), 90.0));
    }
    col *= Material.Kd.xyz;
    vec4 color = vec4( col, Material.Kd.a );

    // Find the smallest distance
    float d = min( GEdgeDistance.x, GEdgeDistance.y );
    d = min( d, GEdgeDistance.z );
    float mixVal;
    if(filled>0.0){
        if(flatColor>0.0){
            if( d < Line.Width - 1 ) {
                mixVal = 1.0;
            } else if( d > Line.Width + 1 ) {
                mixVal = 0.0;
            } else {
                float x = d - (Line.Width - 1);
                mixVal = exp2(-2.0 * (x*x));
            }
            FragColor = mix( Material.Kd, Line.Color, mixVal );
        }else{
            if( d < Line.Width - 1 ) {
                mixVal = 1.0;
            } else if( d > Line.Width + 1 ) {
                mixVal = 0.0;
            } else {
                float x = d - (Line.Width - 1);
                mixVal = exp2(-2.0 * (x*x));
            }
            FragColor = mix( color, Line.Color, mixVal );
        }
    }else{
        if( d < Line.Width - 1 ) {
            mixVal = 1.0;
        } else if( d > Line.Width + 1 ) {
            mixVal = 0.0;
        } else {
            float x = d - (Line.Width - 1);
            mixVal = exp2(-2.0 * (x*x));
        }
        FragColor = mix( vec4(0.0,0.0,0.0,0.0), Line.Color, mixVal );
    }
}