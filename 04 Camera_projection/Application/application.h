#pragma once
#include <iostream>
#define app Application::getInstance() 

using ResizeCallback = void(*)(int width, int height);
using keyCallbackType = void(*)(int key, int scancode, int action, int mods);

class GLFWwindow;
//#include <GLFW/glfw3.h>

class Application {
public:
	~Application();

	bool init(const uint32_t& width, const uint32_t& height);
	bool uppdate();
	void destory();
	
	static Application* getInstance();  //获取静态变量的函数???

	void test() {
		std::cout << "test application." << std::endl;
	}

	uint32_t getWidth() const { return mWidth; }
	uint32_t getHeight() const { return mHeight; }

	void setResizeCallback(ResizeCallback callback) {	mResizeCallback = callback;	}
	void setKeyCallback(keyCallbackType keycallback) { mKeycallback = keycallback; }

private:
	//C++类内函数指针
	static void frameBufferSizeCallback(GLFWwindow* window, int width, int height);
	static void KeyBufferCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

private:
	ResizeCallback mResizeCallback{nullptr};
	keyCallbackType mKeycallback{ nullptr };

	static Application* mInstance;  	//全局唯一静态变量  

	uint32_t mWidth{ 0 };
	uint32_t mHeight{ 0 };
	GLFWwindow* mWindow{ nullptr };

	Application();
};