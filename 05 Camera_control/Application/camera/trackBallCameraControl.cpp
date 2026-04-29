#include "trackBallCameraControl.h"
#include <iostream>


TrackBallCameraControl::TrackBallCameraControl() {

}

TrackBallCameraControl::~TrackBallCameraControl() {

}


void TrackBallCameraControl::pitch(float angle) {
	//绕着camera的Right向量进行旋转
	auto mat = glm::rotate(glm::mat4(1.0f), glm::radians(angle), mCamera->mRight);

	mCamera->mUp = mat * glm::vec4(mCamera->mUp,0.0f);
	mCamera->mPositon = mat * glm::vec4(mCamera->mPositon, 1.0f);
}

void TrackBallCameraControl::yaw(float angle) {
	//绕着camera的Right向量进行旋转
	auto mat = glm::rotate(glm::mat4(1.0f), glm::radians(angle), mCamera->mUp);

	mCamera->mRight = mat * glm::vec4(mCamera->mRight, 0.0f);
	mCamera->mPositon = mat * glm::vec4(mCamera->mPositon, 1.0f);
}

void TrackBallCameraControl::moveX(float pos) {
	auto mat = glm::translate(glm::mat4(1.0f), mCamera->mRight*pos);

	mCamera->mPositon = mat * glm::vec4(mCamera->mPositon,1.0f);

}

void TrackBallCameraControl::moveY(float pos) {
	auto mat = glm::translate(glm::mat4(1.0f), mCamera->mUp * pos);
	mCamera->mPositon = mat * glm::vec4(mCamera->mPositon, 1.0f);
}

void TrackBallCameraControl::onCursor(double xpos, double ypos) {
	std::cout<<"hello "<<std::endl;
	if (mLeftMouseDown) {
		//调整相机的各个参数
		//1 计算光标的 x   y  增量  
		float deltaX = (xpos - mCurrentX) * mSensitivity;
		float deltaY = (ypos - mCurrentY) * mSensitivity;
	
		//2 计算pitch   yaw的角度
		pitch(-deltaY);
		yaw(-deltaX);

	}

	if (mMiddleMouseDown) {
		float deltaX = (xpos - mCurrentX) * mSensitivityMiddleMouse;
		float deltaY = (ypos - mCurrentY) * mSensitivityMiddleMouse;

		moveX(-deltaX);
		moveY(deltaY);
		
	}

	mCurrentX = xpos;
	mCurrentY = ypos;
}


void TrackBallCameraControl::onScroll(double offset) {
	mCamera->scale(mScaleSpeed * offset);
}

