#include "StartScene.h"

StartScene::StartScene()
{

}

StartScene::~StartScene()
{

}

void StartScene::Update() 
{
	if (Keyboard::GetKey(KEY_INPUT_RETURN) == 1)
	{
		BaseScene::nowScene = SceneName::mGame;
	}
}

void StartScene::Draw() 
{
#ifdef _DEBUG
	DrawFormatString(0,0,0xFFFFFF,"Now Scene is Start & Title Scene\nPress the Enter key for the next scene.");
#endif
} 