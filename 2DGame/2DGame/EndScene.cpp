#include "EndScene.h"

EndScene::EndScene()
	: BaseScene()
{

}

EndScene::~EndScene()
{

}

void EndScene::Update()
{
	if (Keyboard::GetKey(KEY_INPUT_RETURN) == 1)
	{
		BaseScene::nowScene = SceneName::mStart;
	}
}

void EndScene::Draw()
{
#ifdef _DEBUG
	DrawFormatString(0, 0, 0xFFFFFF, "Now Scene is End & Result Scene\nPress the Enter key for the next scene.");
#endif
}