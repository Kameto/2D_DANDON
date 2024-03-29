#pragma once
#include "BaseScene.h"
#include "Graphics.h"
#include <thread>

class LoadScene
	: public BaseScene
{
public:
	LoadScene();
	~LoadScene();
	void Update();
	void Draw();

private:
	const int x_point[4] = { 480,960,1440,1920 };
	int point;
	int timer;
	bool loadFlag;
};