#pragma once
#include "../../glframework/core.h"

class Camera {
public:
	Camera();
	~Camera();
	glm::mat4 getViewMatrix();
	virtual glm::mat4 getProjectionMatrix();
	virtual void scale(double deltaScale);

public:
	glm::vec3 mPositon{ 0.0f, 0.0f, 2.0f };
	glm::vec3 mUp{ 0.0f, 0.5f, 0.0f };
	glm::vec3 mRight{0.5f, 0.0f, 0.0f};

};