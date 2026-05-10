#include "cameraControl.h"
#include <iostream>

CameraControl::CameraControl() {

}

CameraControl::~CameraControl() {

}

void CameraControl::onMouse(int button, int action, double xpos, double ypos) {
	//判断是否按下
	bool pressed = action == GLFW_PRESS ? true : false;

	//按下时候记录位置
	if (pressed) {
		mCurrentX = xpos;
		mCurrentY = ypos;
	}

	//检测是哪一个按键按下
	switch (button) {
	case GLFW_MOUSE_BUTTON_LEFT:
		mLeftMouseDown = pressed;
		break;
	case GLFW_MOUSE_BUTTON_RIGHT:
		mRightMouseDown = pressed;
		break;
	case GLFW_MOUSE_BUTTON_MIDDLE:
		mMiddleMouseDown = pressed;
		break;
	}
}

void CameraControl::onCursor(double xpos, double ypos) {
	std::cout << "onCursor" << std::endl;
}

void CameraControl::onKey(int key, int action, int mods) {
	std::cout << "onKey" << std::endl;
	if (action == GLFW_REPEAT)	return;

	bool pressed = action == GLFW_PRESS ? true : false;

	mKeyMap[key] = pressed;
}

//每一帧渲染之前都要进行调用
void CameraControl::update() {
	;
}

void CameraControl::onScroll(double offset) {

}