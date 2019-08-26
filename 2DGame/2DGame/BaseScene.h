#pragma once

#include "JoyPad.h"
#include "Keyboard.h"

// クラスの解放
#define REL_CLS(x) if( (x) != nullptr ){ delete (x); (x) = nullptr; }

// シーン情報用enum
enum class SceneName 
{
	mLoad,		// ロード画面
	mStart,		// スタート画面&タイトル画面
	mGame,		// ゲーム画面
	mEnd		// 終了画面
};

// 基底シーンクラス
class BaseScene
{
public:
	BaseScene() {};				// コンストラクタ
	virtual ~BaseScene() {};	// デストラクタ
	virtual void Update() = 0;	// シーン処理
	virtual void Draw() = 0;	// 描画処理

	SceneName GetNowScene();	// シーン情報取得

protected:
	static SceneName nowScene;	// シーン情報
};