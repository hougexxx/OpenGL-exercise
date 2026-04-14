#version 460 core


//layout (location=1) in vec3 aColor;
layout(location=0)in vec3 aPos;
layout (location=2) in vec2 aUV;

//out vec3 color;
out vec2 uv;

uniform float time;

void main()
{
	gl_Position=vec4(aPos,1.0);
	uv = vec2(aUV.x+time,aUV.y);
//	color = aColor;
	
//	gl_Position = vec4(aPos.x+sin(time)/2.0,aPos.y,aPos.z, 1.0); 
//	color = aColor*((sin(time)+1.0)/2.0); 
}