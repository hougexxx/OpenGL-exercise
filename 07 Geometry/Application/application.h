#pragma once
#include <iostream>
#define app Application::getInstance() 

using ResizeCallback = void(*)(int width, int height);
using keyCallbackType = void(*)(int key, int action, int mods);
using mouseCallbackType = void(*)(int button, int action, int mods);
using cursorCallbackType = void(*)(double xpos,double ypos);
using mouseScrollCallbackType = void(*)(double offset);

class GLFWwindow;
//#include <GLFW/glfw3.h>

class Application {
public:
	~Application();

	bool init(const uint32_t& width, const uint32_t& height);
	bool update();
	void destory();
	
	static Application* getInstance();  //获取静态变量的函数???

	void test() {
		std::cout << "test application." << std::endl;
	}

	uint32_t getWidth() const { return mWidth; }
	uint32_t getHeight() const { return mHeight; }

	void setResizeCallback(ResizeCallback callback) {	mResizeCallback = callback;	}
	void setKeyCallback(keyCallbackType keycallback) { mKeycallback = keycallback; }
	void setMouseCallback(mouseCallbackType mousecallback) { mMousecallback = mousecallback;}
	void setCursorCallback(cursorCallbackType cursorcallback) { mCursorcallback = cursorcallback; }
	void setMouseScrollCallback(mouseScrollCallbackType mousescrollcallback) { mMouseScrollCallback = mousescrollcallback; }

	void getCursorPostion(double * xpos,double * ypos);


private:
	//C++类内函数指针
	static void frameBufferSizeCallback(GLFWwindow* window, int width, int height);
	static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void mouseCallback(GLFWwindow* window, int button,int action, int mods);
	static void cursorCallback(GLFWwindow* window, double xpos,double ypos);
	static void mouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset);

private:
	ResizeCallback mResizeCallback{nullptr};
	keyCallbackType mKeycallback{ nullptr };
	mouseCallbackType mMousecallback{ nullptr };
	cursorCallbackType mCursorcallback{ nullptr };
	mouseScrollCallbackType mMouseScrollCallback{ nullptr };

	static Application* mInstance;  	//全局唯一静态变量  

	uint32_t mWidth{ 0 };
	uint32_t mHeight{ 0 };
	GLFWwindow* mWindow{ nullptr };

	Application();
};