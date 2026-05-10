#version 330 core
out vec4 FragColor;

in vec2 uv;

//声明纹理的采样器
uniform sampler2D hello_sampler;

void main()
{
	FragColor=texture(hello_sampler,uv);
}