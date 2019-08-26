#pragma once

#include "JoyPad.h"
#include "Keyboard.h"

// �N���X�̉��
#define REL_CLS(x) if( (x) != nullptr ){ delete (x); (x) = nullptr; }

// �V�[�����penum
enum class SceneName 
{
	mLoad,		// ���[�h���
	mStart,		// �X�^�[�g���&�^�C�g�����
	mGame,		// �Q�[�����
	mEnd		// �I�����
};

// ���V�[���N���X
class BaseScene
{
public:
	BaseScene() {};				// �R���X�g���N�^
	virtual ~BaseScene() {};	// �f�X�g���N�^
	virtual void Update() = 0;	// �V�[������
	virtual void Draw() = 0;	// �`�揈��

	SceneName GetNowScene();	// �V�[�����擾

protected:
	static SceneName nowScene;	// �V�[�����
};