#include "LoadScene.h"

LoadScene::LoadScene()
{
	loadFlag = false;
	point = 0;
	timer = 0;
}

LoadScene::~LoadScene()
{
	loadFlag = false;
	point = 0;
	timer = 0;
}

void LoadScene::Update()
{
	//if (loadFlag == false)
	//{
	//	// メイン画像
	//	if (Graphics::loadFlag[0])
	//	{
	//		point = x_point[0];
	//	}
	//	else
	//	{
	//		std::thread th1([] { Graphics::LoadMainGraphics(); });
	//		th1.join();
	//		Graphics::loadFlag[0] = true;
	//	}

	//	// プレイヤー画像
	//	if (Graphics::loadFlag[1])
	//	{
	//		point = x_point[1];
	//	}
	//	else
	//	{
	//		std::thread th2([] { Graphics::LoadPlayerGraphics(); });
	//		th2.join();
	//		Graphics::loadFlag[1] = true;
	//	}

	//	// 敵画像
	//	if (Graphics::loadFlag[2])
	//	{
	//		point = x_point[2];
	//	}
	//	else
	//	{
	//		std::thread th3([] { Graphics::LoadEnemyGraphics(); });
	//		th3.join();
	//		Graphics::loadFlag[2] = true;
	//	}

	//	// 文字画像
	//	if (Graphics::loadFlag[3])
	//	{
	//		point = x_point[0];
	//	}
	//	else
	//	{
	//		std::thread th4([] { Graphics::LoadWordGraphics(); });
	//		th4.join();
	//		Graphics::loadFlag[3] = true;
	//	}
	//}

	//// すべての処理が完了していたら
	//if (Graphics::loadFlag[0] && Graphics::loadFlag[1] &&
	//	Graphics::loadFlag[2] && Graphics::loadFlag[3])
	//{
	//	timer++;
	//	if (timer == 30)
	//	{
	//		timer = 0;
	//		loadFlag = true;
	//		nowScene = SceneName::mStart;
	//	}
	//}

	if (Keyboard::GetKey(KEY_INPUT_RETURN) == 1)
	{
		loadFlag = true;
		nowScene = SceneName::mStart;
	}
}

void LoadScene::Draw()
{
	if (!loadFlag)
	{
		/*DrawGraph(0, 0, Graphics::GetMainGraph(MainGraphName::LoadPage), true);
		SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 100);
		DrawBox(point, 0, 1920, 1080, 0x000000, true);
		SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);*/

		DrawFormatString(0,0,0xFFFFFF,"Now Loading...");
	}
	else
	{
		//DrawGraph(0, 0, Graphics::GetMainGraph(MainGraphName::TitlePage), true);
		DrawFormatString(0, 0, 0xFFFFFF, "Load Finished.");
	}
}