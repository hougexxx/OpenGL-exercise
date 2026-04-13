#version 330 core
out vec4 FragColor;
//in vec3 color;
in vec2 uv;
//uniform vec3 uColor;


//声明纹理的采样器
uniform sampler2D makima_sampler;
uniform float width;
uniform float height;


void main()
{
	FragColor=texture(makima_sampler,uv);
//	int zero=0;
//	//获取纹理上的位置
//	vec2 location = uv*vec2(width,height);
//	vec2 dx = dFdx(location);
//	vec2 dy = dFdy(location);
//
//	float maxdelta = sqrt(max(dot(dx,dx),dot(dy,dy)));
//	float L=log2(maxdelta);
//
//	int level = max(int(L+0.5),0);
//	FragColor = textureLod(makima_sampler,uv,level);
}