#include "application.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"


//init mInstance
Application* Application::mInstance = nullptr;


Application* Application::getInstance() {
	if (mInstance == nullptr) {
		mInstance = new Application();
	}
	return mInstance;
}

Application::~Application() {

}

Application::Application() {

}




bool Application::init(const uint32_t& width, const uint32_t& height) {
	mWidth = width;
	mHeight = height;
	//glfw 初始化   OpenGL型号   渲染模式  ？？？
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//创建窗体   链接窗体和OpenGL
	mWindow = glfwCreateWindow(mWidth, mHeight, "Hello OpenGL", NULL, NULL);
	if (mWindow == NULL) {
		return false;
	}
	glfwMakeContextCurrent(mWindow);

	//载入opengl函数
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to load GLAD." << std::endl;
		return false;
	}

	//GLFW窗体回调函数
	glfwSetFramebufferSizeCallback(mWindow, frameBufferSizeCallback);
	//GLFW键盘回调函数
	glfwSetKeyCallback(mWindow, KeyCallback);
	//GLFW鼠标点击回调函数
	glfwSetMouseButtonCallback(mWindow, mouseCallback);
	//GLFW光标位置移动回调函数
	glfwSetCursorPosCallback(mWindow, cursorCallback);
	//GLFW鼠标滚轮回调函数
	glfwSetScrollCallback(mWindow, mouseScrollCallback);
	//GLFW中user pointer
	glfwSetWindowUserPointer(mWindow, this);
	

	return true;
}

bool Application::update() {

	if (glfwWindowShouldClose(mWindow)) {
		return false;
	}
	glfwPollEvents();
	//swap buffers
	glfwSwapBuffers(mWindow);

	return true;
}

void Application::destory() {

	glfwTerminate();
}


//窗体回调函数应用
void Application::frameBufferSizeCallback(GLFWwindow* window, int width, int height) {
	std::cout << "frameSizeCallback test." << std::endl;
	Application* self = (Application*)glfwGetWindowUserPointer(window);
	self->mResizeCallback(width,height);

	//只是 GLFW 规定：回调函数必须通过它传给你的 window 参数去取用户指针，
	// 不能直接用 mWindow（因为静态回调函数里根本看不到类的成员 mWindow）。
	//if (app->mResizeCallback != nullptr) {
	//	app->mResizeCallback(width, height);
	//}
}

void Application::KeyCallback(GLFWwindow* window, int key, int scancode,int action, int mods) {
	Application* self = (Application*)glfwGetWindowUserPointer(window);
	self->mKeycallback(key, action, mods);
}

void Application::mouseCallback(GLFWwindow* window, int button, int action, int mods) {
	Application* self = (Application*)glfwGetWindowUserPointer(window);
	self->mMousecallback(button, action, mods);
}


void Application::cursorCallback(GLFWwindow* window, double xpos,double ypos) {
	Application* self = (Application*)glfwGetWindowUserPointer(window);
	self->mCursorcallback(xpos,ypos);
}


void Application::mouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset) {
	Application* self = (Application*)glfwGetWindowUserPointer(window);
	self->mMouseScrollCallback(yoffset);
}


void Application::getCursorPostion(double* xpos,double* ypos) {
	glfwGetCursorPos(mWindow, xpos, ypos);
}