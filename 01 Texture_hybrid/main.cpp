#include <iostream>
#include "glframework/core.h"
#include "glframework/shader.h"
#include "glframework/texture.h"
#include <string>
#include "Wrapper/check.h"
#include "Application/application.h"


using namespace std;

shader* Shader = nullptr;
GLuint VAO = 0;
Texture* sunset_texture = nullptr;
Texture* hello_texture = nullptr;
Texture* noise_texture = nullptr;

void OnResize(int width, int height) {
	GL_CALL(glViewport(0, 0, width, height));
	std::cout << "OnResize" << std::endl;
}

void OnkeyCallback(int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_W) {
		std::cout << "GLFW_KEY_W" << std::endl;
	}
}

void prepareShader() {
	Shader = new shader("assets/shaders/vertex.glsl", "assets/shaders/fragment.glsl");
}

void prepareTexture() {
	hello_texture = new Texture("assets/textures/hello.jpg", 0);
	sunset_texture = new Texture("assets/textures/sunset.jpg", 1);
	noise_texture = new Texture("assets/textures/noise.jpg", 2);
}

void prepareVAO() {
	//顶点位置数据
	//float positions[] = {
	//-0.5f,-0.5f,0.0f,
	//0.5f,-0.5f,0.0f,
	//-0.5f,0.5f,0.0f,
	//0.5f,0.5f,0.0f,
	//};
	float positions[] = {
  -1.0f,-1.0f,0.0f,
  1.0f,-1.0f,0.0f,
  -1.0f,1.0f,0.0f,
  1.0f,1.0f,0.0f,
	};

	float uvs[] = {
	0.0f,0.0f,
	1.0f,0.0f,
	0.0f,1.0f,
	1.0f,1.0f
	};
	//顶点位置索引数据
	unsigned int indices[] = {
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
	Shader->begin();

	Shader->setFloat("time", glfwGetTime()/5);
	hello_texture->bind();
	Shader->setInt("hello_sampler", 0);
	sunset_texture->bind();
	Shader->setInt("sunset_sampler", 1);
	noise_texture->bind();
	Shader->setInt("noise_sampler", 2);


	GL_CALL(glBindVertexArray(VAO));
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	Shader->end();
}

int main() {

	app->test();
	app->init(1920, 1080);
	app->setResizeCallback(OnResize);
	app->setKeyCallback(OnkeyCallback);
	//set viewport and color
	glViewport(0, 0, 1920, 1080);
	glClearColor(0.1f, 0.3f, 0.3f, 1.0f);

	//三角形绘制
	prepareTexture();
	prepareShader();
	prepareVAO();


	//窗体循环
	while (app->uppdate()) {

		render();
		
	}

	app->destory();
	//delete sunset_texture;
	return 0;
}

