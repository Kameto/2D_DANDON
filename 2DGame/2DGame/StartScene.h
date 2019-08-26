#pragma once

#include "BaseScene.h"

// 派生シーンクラス（初期画面）
class StartScene :
	public BaseScene
{
public:
	StartScene();		// コンストラクタ
	~StartScene();		// デストラクタ
	void Update();		// シーン処理
	void Draw();		// シーン描画
};