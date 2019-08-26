#include <DxLib.h>
#include "JoyPad.h"
#include "Keyboard.h"
#include "SceneMgr.h"

int _stdcall WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	SetMainWindowText("Game_Name");				// �A�v���P�[�V������

#ifdef _DEBUG
	SetOutApplicationLogValidFlag(false);		// log�t�@�C���̐���
	ChangeWindowMode(true);						// �X�N���[���ݒ�
#endif

#ifndef _DEBUG
	SetOutApplicationLogValidFlag(false);		// log�t�@�C���̐���
	ChangeWindowMode(false);					// �X�N���[���ݒ�
#endif

	SetGraphMode(1920, 1080, 32);				// �`��͈�
	SetFontSize(16);							// �����T�C�Y�ݒ�
	if (DxLib_Init() == -1)						// Dx���C�u�����̏�����
	{
		return -1;
	}
	if (SetDrawScreen(DX_SCREEN_BACK) == -1)	// �w�i�`��ݒ�
	{
		return -1;
	}
	
	SetMouseDispFlag(false);					// �E�B���h�E���[�h�ł��}�E�X�J�[�\�����\���ɂ���

	//Graphics* grs	 = new Graphics("graph/main/0.png");
	JoyPad* pad		 = new JoyPad();
	Keyboard* key	 = new Keyboard();
	SceneMgr* smgr	 = new SceneMgr();

	// ���b�Z�[�W���[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen();
		pad->Pad_Update();		// Joypad����
		key->KeyUpdate();		// �L�[�{�[�h����
		smgr->SceneUpdate();	// �V�[������
		smgr->SceneDraw();		// �V�[���`��
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