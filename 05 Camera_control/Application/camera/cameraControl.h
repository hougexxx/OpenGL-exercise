#pragma once
#include "camera.h"
#include "../../glframework/core.h"	
#include <map>

class CameraControl {
public:
	CameraControl();
	~CameraControl();

	//事件回调函数
	virtual void onMouse(int button, int action, double xpos, double ypos);
	virtual void onCursor(double xpos, double ypos);
	virtual void onKey(int button, int action, int mods);
	virtual void onScroll(double offset);//+ -

	//每一帧渲染之前都要进行调用
	virtual void  update();

	void setCamera(Camera* camera) { mCamera = camera; }
	void setSensitivity(double s) { mSensitivity = s; }
	void setScaleSpeed(double s) {mScaleSpeed = s; }

protected:
	//1 鼠标的按键状态
	bool mLeftMouseDown = false;
	bool mRightMouseDown = false;
	bool mMiddleMouseDown = false;

	//2 当前鼠标的位置
	double mCurrentX = 0.0f, mCurrentY = 0.0f;

	//3 敏感度  用来控制移动的速度
	double mSensitivity = 0.2f;

	double mSensitivityMiddleMouse = 0.01f;

	//4 键盘的按键
	std::map<int, bool> mKeyMap;

	//5 存储当前的控制的那个相机
	Camera* mCamera = nullptr;

	//6 存储相机scale的速度
	double mScaleSpeed = 0.2f;
};