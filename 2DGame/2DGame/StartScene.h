#pragma once

#include "BaseScene.h"

// �h���V�[���N���X�i������ʁj
class StartScene :
	public BaseScene
{
public:
	StartScene();		// �R���X�g���N�^
	~StartScene();		// �f�X�g���N�^
	void Update();		// �V�[������
	void Draw();		// �V�[���`��
};