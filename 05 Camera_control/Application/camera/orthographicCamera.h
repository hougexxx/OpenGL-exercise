#pragma once 
#include "camera.h"
#include "../../glframework/core.h"
class OrthographicCamera :public Camera {
public:
	OrthographicCamera(float t, float b, float l, float r,float n,float f);
	~OrthographicCamera();
  glm::mat4 getProjectionMatrix() override;
	void scale(double deltaScale)override;
	
private:
	float mNear = 0.0f;
	float mFar = 0.0f;
	float mTop = 0.0f;
	float mBottom = 0.0f;
	float mLeft = 0.0f;
	float mRight = 0.0f;
	float mScale = 0.0f;
};