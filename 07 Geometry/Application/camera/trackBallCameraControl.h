#pragma once
#include "cameraControl.h"


class TrackBallCameraControl:public CameraControl {
public:
	TrackBallCameraControl();
	~TrackBallCameraControl();
	void onCursor(double xpos, double ypos)override;
	void onScroll(double offset)override;//+ -

private:
	void pitch(float angle);
	void yaw(float angle);
	void moveX(float pos);
	void moveY(float pos);
	
};