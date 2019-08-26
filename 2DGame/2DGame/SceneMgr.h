#pragma once

#include "EndScene.h"
#include "GameScene.h"
#include "StartScene.h"
#include "LoadScene.h"

// �V�[���Ǘ��N���X
class SceneMgr
{
public:
	SceneMgr();				// �R���X�g���N�^
	~SceneMgr();			// �f�X�g���N�^

	void ChangeScene();		// �V�[���ؑ�
	void SceneUpdate();		// �V�[������
	void SceneDraw();		// �V�[���`��

	BaseScene* mpScene;		// �V�[���|�C���^�[
	SceneName preScene;		// �V�[�����L���ϐ�
};