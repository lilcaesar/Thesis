#version 330

uniform vec3 lightPosition_worldspace;
uniform vec4 color;

in vec3 normal;

out vec4 gl_FragColor;

void main()
{
	float intensity;
	vec4 colorF;
	vec3 n = normalize(normal);
	intensity = dot(vec3(lightPosition_worldspace),n);

	if (intensity > 3)
		colorF = color;
	else if (intensity > 0.5)
		colorF = vec4(color.rgb*0.6,1.0);
	else if (intensity > -3)
		colorF = vec4(color.rgb*0.4,1.0);
	else
		colorF = vec4(color.rgb*0.2,1.0);
	gl_FragColor = colorF;

}