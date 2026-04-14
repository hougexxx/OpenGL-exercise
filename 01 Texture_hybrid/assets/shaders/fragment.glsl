#version 330 core
out vec4 FragColor;
//in vec3 color;
in vec2 uv;

//uniform vec3 uColor;
uniform sampler2D hello_sampler;
uniform sampler2D sunset_sampler;
uniform sampler2D noise_sampler;

void main()
{
	float weight;
	vec4 hello = texture(hello_sampler,uv);
	vec4 sunset = texture(sunset_sampler,uv);
	vec4 noise = texture(sunset_sampler,uv);
	weight = noise.r;
//	weight = 0.1;
	vec4 finalcolor  = weight*hello+(1.0-weight)*sunset;
	FragColor = vec4(finalcolor.rgb,1.0);
//	FragColor = texture(hello_sampler,uv);

//	FragColor = vec4(color, 1.0f); 
}