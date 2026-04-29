#include "camera.h"




Camera::Camera() {

}

Camera::~Camera() {

}

glm::mat4 Camera::getViewMatrix() {
	//lookat function
	glm::vec3 front = glm::cross(mUp, mRight);
	glm::vec3 center = mPositon + front;
	return glm::lookAt(mPositon, center, mUp);
}

glm::mat4 Camera::getProjectionMatrix() {
	return glm::identity<glm::mat4>();
}


void Camera::scale(double deltaScale) {
	
}
