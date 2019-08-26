#pragma once

#include "EndScene.h"
#include "GameScene.h"
#include "StartScene.h"
#include "LoadScene.h"

// シーン管理クラス
class SceneMgr
{
public:
	SceneMgr();				// コンストラクタ
	~SceneMgr();			// デストラクタ

	void ChangeScene();		// シーン切替
	void SceneUpdate();		// シーン処理
	void SceneDraw();		// シーン描画

	BaseScene* mpScene;		// シーンポインター
	SceneName preScene;		// シーン情報記憶変数
};