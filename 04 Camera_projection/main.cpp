#include <iostream>
#include "glframework/core.h"
#include "glframework/shader.h"
#include "glframework/texture.h"
#include <string>
#include "Wrapper/check.h"
#include "Application/application.h"

using namespace std;

Shader* shader = nullptr;
GLuint VAO = 0;
Texture* makima_texture = nullptr;
glm::mat4 transform = glm::mat4(1.0f);
glm::mat4 viewMatrix = glm::mat4(1.0f);
glm::mat4 projectionMatrix = glm::mat4(1.0f);
  
float Time;
float  x = 0.0f;
float inc = 0.01f;
float lastTime;

float ValueToTime(float minValue, float maxValue) {
	if (x > maxValue)inc=-0.001f;
	if (x < minValue)inc=0.001f;
	x += inc;
	return x;
}

void OnResize(int width, int height) {
	GL_CALL(glViewport(0, 0, width, height));
	std::cout << "OnResize" << std::endl;
}

void OnkeyCallback(int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_W) {
		std::cout << "GLFW_KEY_W" << std::endl;
	}
}

void doRotateTransform() {
	//使用的是弧度  radians  
  //模板函数  C++
	transform = glm::rotate(glm::mat4(1.0f), glm::radians(0.0f), glm::vec3(0.0, 0.0, 1.0f));
}

void doTranslationTransform() {
	transform = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
}

void doScaleTransform() {
	transform = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f, 0.5f,1.0f));
}

void doMultiTransform() {
	glm::mat4 rotateMat = glm::rotate(glm::mat4(1.0f), glm::radians(Time*90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
	//glm::mat4 scaleMat = glm::scale(glm::mat4(1.0f), glm::vec3(1.0f*glm::sin(Time), 1.0f*glm::sin(Time), 1.0f));
	std::cout << (glm::sin(Time) + 1.0) / 4.0 + 0.2 << std::endl;
	//为什么不能用sin ，因为会有负数  例如-1.0f怎么判断缩放
	glm::mat4 scaleMat = glm::scale(glm::mat4(1.0f), glm::vec3((glm::sin(Time)+1.0)/4.0+0.2, (glm::sin(Time) + 1.0) / 4.0+0.2, 1.0f));
	transform = rotateMat*scaleMat;
}

void doRoateTransform_self() {
	//roate的第一个变量是自身，也就是后续所有操作是基于自己的坐标系，而设置为单位矩阵则自身的coordinate和世界的coordinate重合
	float angle = 0.3f;
	transform = glm::rotate(transform, glm::radians(angle), glm::vec3(0.0f, 0.0f, 1.0f));
}

void prepareShader() {
	shader = new Shader("assets/shaders/vertex.glsl", "assets/shaders/fragment.glsl");
}

void prepareTexture() {
	makima_texture = new Texture("assets/textures/makima.jpg", 1);
}

void prepareCamera() {
	//lookAt function  -->> viewMatrix
	//eye:   point < camera pos
	//center:  point < lookat pos
	//up:  vector
	viewMatrix = glm::lookAt(glm::vec3(0.0f, 0.7f, 0.5f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.5f, 0.0f));
}

void prepareProjection() {
	projectionMatrix = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, 1.0f, -1.0f);//压缩成NDC坐标  给ortho一个方盒子就行
	projectionMatrix = glm::perspective(glm::radians(90.0f), (float)app->getWidth() / (float)app->getHeight(), 0.1f, 1000.0f);
}

void prepareVAO() {
	//顶点位置数据   NDC坐标   -1.0f  1.0f
	float positions[] = {
  -0.5f,-0.5f,0.0f,
  0.5f,-0.5f,0.0f,
  -0.5f,0.5f,0.0f,
  0.5f,0.5f,0.0f,
	-0.5f,-0.5f,-0.5f,
	0.5f,-0.5f,-0.5f,
	-0.5f,0.5f,-0.5f,
	0.5f,0.5f,-0.5f,
	};

	//这个uv是采样纹理时候的坐标，每一个顶点是对应纹理中的位置，范围[0,1]  原点在左下角
	float uvs[] = {
	0.0f,0.0f,
	1.0f,0.0f,
	0.0f,1.0f,
	1.0f,1.0f,
	0.0f,0.0f,
	1.0f,0.0f,
	0.0f,1.0f,
	1.0f,1.0f
	};
	 
	//顶点位置索引数据
	unsigned int indices[] = {
	  4,5,6,
		6,5,7,
		0,1,2,
		2,1,3

	};

	//创建位置VBO
	GLuint vbo = 0;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

	//创建纹理的uv坐标的VBO
	GLuint uvVBO = 0;
	glGenBuffers(1, &uvVBO);
	glBindBuffer(GL_ARRAY_BUFFER, uvVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(uvs), uvs, GL_STATIC_DRAW);

	//创建ebo
	GLuint ebo = 0;
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	//创建vao
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	//posVBO   vertex buffer
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)0);
	//uvVBO        vertex buffer
	glBindBuffer(GL_ARRAY_BUFFER, uvVBO);
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBindVertexArray(0);
}

void render() {
	GL_CALL(glClear(GL_COLOR_BUFFER_BIT));
	//使用当前的program
	shader->begin();
	shader->setMatrix4x4("transform", transform);
	shader->setMatrix4x4("viewMatrix", viewMatrix);
	shader->setMatrix4x4("projectionMatrix", projectionMatrix);
	makima_texture->bind();	                //active  &  bind  -> texture unit  
	shader->setInt("makima_sampler", 1);  	//set sampler      -> texture unit

	//VAO(array)->>   posVBO(position)  colorVBO(color)  EBO(index)   uv(texture)    
	GL_CALL(glBindVertexArray(VAO));
	glClear(GL_DEPTH_BUFFER_BIT);
	glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);
	shader->end();
}

int main() {
	
	app->test();
	app->init(1920, 1080);//窗口
	app->setResizeCallback(OnResize);
	app->setKeyCallback(OnkeyCallback);
	//set viewport and color
	glViewport(0, 0, 1920, 1080);//视口
	glClearColor(0.1f, 0.3f, 0.3f, 1.0f);

	//三角形绘制
	prepareTexture();
	prepareShader();
	prepareVAO();

	Time = float(glfwGetTime());
	doRotateTransform();
	prepareCamera();
	prepareProjection();
	//窗体循环
	while (app->uppdate()) {

		render();
	}

	app->destory();
	return 0;
}

