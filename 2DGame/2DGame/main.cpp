#include <DxLib.h>
#include "JoyPad.h"
#include "Keyboard.h"
#include "SceneMgr.h"

int _stdcall WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	SetMainWindowText("Game_Name");				// アプリケーション名

#ifdef _DEBUG
	SetOutApplicationLogValidFlag(false);		// logファイルの生成
	ChangeWindowMode(true);						// スクリーン設定
#endif

#ifndef _DEBUG
	SetOutApplicationLogValidFlag(false);		// logファイルの生成
	ChangeWindowMode(false);					// スクリーン設定
#endif

	SetGraphMode(1920, 1080, 32);				// 描画範囲
	SetFontSize(16);							// 文字サイズ設定
	if (DxLib_Init() == -1)						// Dxライブラリの初期化
	{
		return -1;
	}
	if (SetDrawScreen(DX_SCREEN_BACK) == -1)	// 背景描画設定
	{
		return -1;
	}
	
	SetMouseDispFlag(false);					// ウィンドウモードでもマウスカーソルを非表示にする

	//Graphics* grs	 = new Graphics("graph/main/0.png");
	JoyPad* pad		 = new JoyPad();
	Keyboard* key	 = new Keyboard();
	SceneMgr* smgr	 = new SceneMgr();

	// メッセージループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen();
		pad->Pad_Update();		// Joypad処理
		key->KeyUpdate();		// キーボード処理
		smgr->SceneUpdate();	// シーン処理
		smgr->SceneDraw();		// シーン描画
		ScreenFlip();
	}
	
	REL_CLS(smgr);
	REL_CLS(key);
	REL_CLS(pad);
	//REL_CLS(grs);

	InitGraph();
	DxLib_End();

	return 0;
}