#version 330

uniform vec4 color;

in vec3 normal;
in vec3 lightDir;

out vec4 gl_FragColor;

void main()
{
	float intensity;
	vec4 colorF;
	vec3 n = normalize(normal);
	vec3 l = normalize(lightDir);
	intensity = dot(l,n);

	if (intensity > 0.95)
		colorF = color;
	else if (intensity > 0.5)
		colorF = vec4(color.rgb*0.6,1.0);
	else if (intensity > 0.25)
		colorF = vec4(color.rgb*0.4,1.0);
	else
		colorF = vec4(color.rgb*0.2,1.0);
	gl_FragColor = colorF;

}