#include "orthographicCamera.h"

OrthographicCamera::OrthographicCamera(float t, float b, float l, float r, float n, float f) {
	mTop, mBottom, mLeft, mRight, mNear, mFar = t, b, l, r, n, f;
}

OrthographicCamera::~OrthographicCamera(){}

glm::mat4 OrthographicCamera::getProjectionMatrix() {
	float scale = std::pow(2.0f,mScale);
	return glm::ortho(mLeft * scale, mRight * scale, mBottom * scale, mTop * scale, mNear, mFar);
}


void OrthographicCamera::scale(double deltaScale) {
	mScale += deltaScale;
}
