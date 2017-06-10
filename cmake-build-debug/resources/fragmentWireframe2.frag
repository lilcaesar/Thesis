#version 400

uniform struct LineInfo {
  float Width;
  vec4 Color;
} Line;

uniform float filled;

in vec3 GPosition;
in vec3 GNormal;
in vec3 Position_worldSpace;
in vec3 Normal_cameraspace;
in vec3 EyeDirection_cameraspace;
in vec3 LightDirection_cameraspace;
noperspective in vec3 GEdgeDistance;

layout( location = 0 ) out vec4 FragColor;

void main() {
    vec3 LightColor = vec3(1,1,1);
    float LightPower = 0.1f;

    // Material properties
    vec3 MaterialDiffuseColor = vec3(0.5,0.5,0.5);
    vec3 MaterialAmbientColor = vec3(0.5,0.5,0.5) * MaterialDiffuseColor;
    vec3 MaterialSpecularColor = vec3(0.3,0.3,0.3);

    // Distance to the light
    float distance = length( vec3(0.0,0.0,1.0) - Position_worldSpace);

    // Normal of the computed fragment, in camera space
    vec3 n = normalize( Normal_cameraspace );
    // Direction of the light (from the fragment to the light)
    vec3 l = normalize( LightDirection_cameraspace );
    // Cosine of the angle between the normal and the light direction,
    // clamped above 0
    //  - light is at the vertical of the triangle -> 1
    //  - light is perpendicular to the triangle -> 0
    //  - light is behind the triangle -> 0
    float cosTheta = clamp( dot( n,l ), 0,1 );

    // Eye vector (towards the camera)
    vec3 E = normalize(EyeDirection_cameraspace);
    // Direction in which the triangle reflects the light
    vec3 R = reflect(-l,n);
    // Cosine of the angle between the Eye vector and the Reflect vector,
    // clamped to 0
    //  - Looking into the reflection -> 1
    //  - Looking elsewhere -> < 1
    float cosAlpha = clamp( dot( E,R ), 0,1 );

    vec4 color = vec4(
    		// Ambient : simulates indirect lighting
    		MaterialAmbientColor +
    		// Diffuse : "color" of the object
    		MaterialDiffuseColor * LightColor * LightPower * cosTheta / (distance*distance) +
    		// Specular : reflective highlight, like a mirror
    		MaterialSpecularColor * LightColor * LightPower * pow(cosAlpha,5) / (distance*distance)
    		,1.0);

    // Find the smallest distance
    float d = min( GEdgeDistance.x, GEdgeDistance.y );
    d = min( d, GEdgeDistance.z );
    float mixVal;
    if(filled>0.0){
        if( d < Line.Width - 1 ) {
            mixVal = 1.0;
        } else if( d > Line.Width + 1 ) {
            mixVal = 0.0;
        } else {
            float x = d - (Line.Width - 1);
            mixVal = exp2(-2.0 * (x*x));
        }
        FragColor = mix( color, Line.Color, mixVal );
    }else{
        if( d > Line.Width + 1 ) {
            FragColor = vec4(0.0,0.0,0.0,0.0);
        }else{
            FragColor = Line.Color;
        }
    }
}