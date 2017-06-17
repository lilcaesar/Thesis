#version 400

layout( triangles ) in;
layout( triangle_strip, max_vertices = 3 ) out;

out vec3 GNormal;
out vec3 GlightDir;
out vec3 GviewDir;
noperspective out vec3 GEdgeDistance;

in vec3 VNormal[];
in vec3 lightDir[];
in vec3 viewDir[];

uniform mat4 ViewportMatrix;  // Viewport matrix

void main()
{
    // Transform each vertex into viewport space
    vec2 p0 = vec2(ViewportMatrix * (gl_in[0].gl_Position / gl_in[0].gl_Position.w));
    vec2 p1 = vec2(ViewportMatrix * (gl_in[1].gl_Position / gl_in[1].gl_Position.w));
    vec2 p2 = vec2(ViewportMatrix * (gl_in[2].gl_Position / gl_in[2].gl_Position.w));

    float a = length(p1 - p2);
    float b = length(p2 - p0);
    float c = length(p1 - p0);
    float alpha = acos( (b*b + c*c - a*a) / (2.0*b*c) );
    float beta = acos( (a*a + c*c - b*b) / (2.0*a*c) );
    float ha = abs( c * sin( beta ) );
    float hb = abs( c * sin( alpha ) );
    float hc = abs( b * sin( alpha ) );

    GEdgeDistance = vec3( ha, 0, 0 );
    GNormal = VNormal[0];
    GlightDir = lightDir[0];
    GviewDir = viewDir[0];
    gl_Position = gl_in[0].gl_Position;
    EmitVertex();

    GEdgeDistance = vec3( 0, hb, 0 );
    GNormal = VNormal[1];
    GlightDir = lightDir[1];
    GviewDir = viewDir[1];
    gl_Position = gl_in[1].gl_Position;
    EmitVertex();

    GEdgeDistance = vec3( 0, 0, hc );
    GNormal = VNormal[2];
    GlightDir = lightDir[2];
    GviewDir = viewDir[2];
    gl_Position = gl_in[2].gl_Position;
    EmitVertex();

    EndPrimitive();
}
