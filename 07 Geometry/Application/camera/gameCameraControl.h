#pragma once

#include "../../glframework/core.h"
#include "cameraControl.h"

class GameCameraControl : public CameraControl {
public:
	GameCameraControl();

	~GameCameraControl();

  void onCursor(double xpos, double ypos)override;
	void  update()override;
	void setSpeed(double s) { mSpeed = s; }

	
private:
	void pitch(double angle);
	void yaw(double angle);

private:
	double mSpeed = 0.1f;
};