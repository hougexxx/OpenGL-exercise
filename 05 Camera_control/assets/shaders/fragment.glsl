#version 330 core
out vec4 FragColor;

in vec2 uv;

//声明纹理的采样器
uniform sampler2D makima_sampler;
uniform float width;
uniform float height;

void main()
{
	FragColor=texture(makima_sampler,uv);
}