#include "perspectiveCamera.h"

PerspectiveCamera::PerspectiveCamera(float fovy, float aspect, float near, float far) {
	mFovy = fovy;
	mAspect = aspect;
	mNear = near;
	mFar = far;

	//mFovy,mAspect,mNear,mFar=fovy,aspect,near,far; //错误，不能够同时赋值，只会将mFar=far
}

PerspectiveCamera::~PerspectiveCamera() {

}

//对父类中的camera的投影矩阵进行覆写
glm::mat4 PerspectiveCamera::getProjectionMatrix() {
	return glm::perspective(glm::radians(mFovy), mAspect, mNear, mFar);
}

void PerspectiveCamera::scale(double deltaScale) {
	auto front = glm::cross(mUp, mRight);
	mPositon += front * (float)deltaScale;//mPositon = front * (float)deltaScale?
}
