#include "gameCameraControl.h"
#include "cameraControl.h"

GameCameraControl::GameCameraControl() {

}

GameCameraControl::~GameCameraControl() {

}

void GameCameraControl::onCursor(double xpos, double ypos) {
	
	double deltaX = (xpos - mCurrentX) * mSensitivity;
	double deltaY = (ypos - mCurrentY) * mSensitivity;

	if (mRightMouseDown) {

		pitch(deltaY);
		yaw(deltaX);
	}

	mCurrentX = xpos;
	mCurrentY = ypos;
}

void GameCameraControl::pitch(double angle) {
	mLimitAngle += angle;
	if (mLimitAngle > 89.0f || mLimitAngle < -89.0f) {
		mLimitAngle -= angle;
		return;
	}

	auto mat = glm::rotate(glm::mat4(1.0f), (float)glm::radians(angle), mCamera->mRight);
	mCamera->mUp = mat * glm::vec4(mCamera->mUp, 0.0f);
}


void GameCameraControl::yaw(double angle) {
	auto mat = glm::rotate(glm::mat4(1.0f), (float)glm::radians(angle), glm::vec3(0.0f,1.0f,0.0f));
	mCamera->mRight = mat * glm::vec4(mCamera->mRight, 0.0f);
	mCamera->mUp = mat * glm::vec4(mCamera->mUp, 0.0f);
}


void  GameCameraControl::update() {
	auto front = glm::cross(mCamera->mUp, mCamera->mRight);
	auto right = mCamera->mRight;
	glm::vec3 direction(0.0f);

	if (mKeyMap[GLFW_KEY_W]) {
		direction += front;
	}

	if (mKeyMap[GLFW_KEY_A]) {
		direction -= right;
	}

	if (mKeyMap[GLFW_KEY_S]) {
		direction -= front;
	}

	if (mKeyMap[GLFW_KEY_D]) {
		direction += right;
	}

	if (glm::length(direction)!=0) {
		direction = glm::normalize(direction);
		mCamera->mPositon += direction * (float)mSpeed;
	}

	
}
