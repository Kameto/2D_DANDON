#include "GameScene.h"

GameScene::GameScene()
	: BaseScene()
{

}

GameScene::~GameScene()
{

}

void GameScene::Update() 
{
	if (Keyboard::GetKey(KEY_INPUT_RETURN) == 1)
	{
		BaseScene::nowScene = SceneName::mEnd;
	}
}

void GameScene::Draw()
{
#ifdef _DEBUG
	DrawFormatString(0, 0, 0xFFFFFF, "Now Scene is Game Scene\nPress the Enter key for the next scene.");
#endif
}